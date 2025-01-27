#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    socket(new QTcpSocket(this)),
    timer(new QTimer(this)),
    captureInterval(1),
    numSamples(30), // Número inicial de amostras no gráfico
    chart(new QChart()),
    series(new QLineSeries()),
    axisX(new QValueAxis()),
    axisY(new QValueAxis()) {

    ui->setupUi(this);

    ui->horizontalSliderInterval->setValue(captureInterval);
    ui->labelTiming->setText(QString::number(captureInterval));

    setupChart();

    // Conectar sinais e slots
    connect(ui->pushButtonConnect, &QPushButton::clicked, this, &MainWindow::tcpConnect);
    connect(ui->pushButtonDisconnect, &QPushButton::clicked, this, &MainWindow::tcpDisconnect);
    connect(ui->pushButtonUpdate, &QPushButton::clicked, this, &MainWindow::updateMachineList);
    connect(ui->pushButtonStart, &QPushButton::clicked, this, &MainWindow::startReceiving);
    connect(ui->pushButtonStop, &QPushButton::clicked, this, &MainWindow::stopReceiving);
    connect(ui->horizontalSliderInterval, &QSlider::valueChanged, this, &MainWindow::updateCaptureInterval);
    connect(ui->listWidgetMachines, &QListWidget::itemClicked, this, &MainWindow::selectMachine);
}

void MainWindow::setupChart() {
    // Adicionar série ao gráfico
    chart->addSeries(series);

    // Configurar fundo amarelo
    chart->setBackgroundBrush(QBrush(Qt::yellow));

    // Configurar linha azul
    QPen pen(Qt::blue);
    pen.setWidth(2);
    series->setPen(pen);

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    series->attachAxis(axisX);
    series->attachAxis(axisY);

    // Remover título e margens extras
    chart->setMargins(QMargins(0, 0, 0, 0));
    chart->legend()->hide(); // Esconder legenda

    // Configurar QChartView
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setContentsMargins(0, 0, 0, 0);

    // Adicionar ao layout
    ui->verticalLayoutChart->addWidget(chartView);
}

void MainWindow::tcpConnect() {
    QString ipAddress = ui->lineEditServerIP->text().trimmed();
    socket->connectToHost(ipAddress, 1234);

    if (socket->waitForConnected(3000)) {
        qDebug() << "Connected to server at" << ipAddress;
        ui->labelConnected->setText("Connected to " + ipAddress);
        ui->labelConnected->setStyleSheet("color: green;");
        updateMachineList();
    } else {
        qDebug() << "Failed to connect to server.";
    }
}

void MainWindow::tcpDisconnect() {
    if (socket->state() == QAbstractSocket::ConnectedState) {
        socket->disconnectFromHost();
        if (socket->state() == QAbstractSocket::UnconnectedState || socket->waitForDisconnected(3000)) {
            ui->labelConnected->setText("Disconnected");
            ui->labelConnected->setStyleSheet("color: red;");
            qDebug() << "Disconnected";
        } else {
            qDebug() << "Error: Unable to disconnect";
        }
    } else {
        qDebug() << "Socket is not connected";
    }
}

void MainWindow::updateMachineList() {
    if (socket->state() == QAbstractSocket::ConnectedState) {
        socket->write("list\r\n");
        socket->waitForBytesWritten();
        socket->waitForReadyRead();

        ui->listWidgetMachines->clear();

        while (socket->bytesAvailable()) {
            QString machine = socket->readLine().trimmed();
            ui->listWidgetMachines->addItem(machine);
        }

        qDebug() << "Machine list updated.";
    } else {
        qDebug() << "Not connected to server.";
    }
}

void MainWindow::selectMachine(QListWidgetItem *item) {
    if (!item) {
        qDebug() << "Error: No item selected.";
        return;
    }
    selectedMachine = item->text();
    qDebug() << "Selected machine:" << selectedMachine;
}

void MainWindow::updateCaptureInterval(int value) {
    if(value < 1) {
        ui->horizontalSliderInterval->setValue(1);
        return;
    }
    captureInterval = value;
    ui->labelTiming->setText(QString::number(captureInterval) + " ms");

    // Atualize o intervalo do QTimer
    if (timer->isActive()) {
        timer->setInterval(captureInterval * 1000); // Atualiza o intervalo para o novo valor
        qDebug() << "Timer interval updated to:" << captureInterval * 1000 << "ms";
    }
}

void MainWindow::startReceiving() {
    if (socket->state() == QAbstractSocket::ConnectedState && !selectedMachine.isEmpty()) {
        // Configura o intervalo do timer baseado no slider
        timer->setInterval(captureInterval * 1000);

        // Garante que o timer tenha apenas uma conexão com getData
        disconnect(timer, &QTimer::timeout, this, &MainWindow::getData);
        connect(timer, &QTimer::timeout, this, &MainWindow::getData, Qt::UniqueConnection);

        // Inicia o timer
        timer->start();
        qDebug() << "Started receiving data for machine:" << selectedMachine
                 << "with interval:" << captureInterval * 1000 << "ms";
    } else {
        qDebug() << "Cannot start receiving: Ensure connection and machine selection.";
    }
}

void MainWindow::stopReceiving() {
    if (timer->isActive()) {
        timer->stop();
        qDebug() << "Timer stopped.";
    }
}

void MainWindow::getData() {
    if (socket->state() != QAbstractSocket::ConnectedState) {
        qDebug() << "Error: Socket is not connected.";
        stopReceiving();
        return;
    }

    // Criar o comando a ser enviado
    QString command = QString("get %1 %2\r\n").arg(selectedMachine).arg(numSamples);
    socket->write(command.toUtf8());

    // Log do comando enviado
    qDebug() << "Command sent to server:" << command.trimmed();

    if (!socket->waitForBytesWritten(3000)) {
        qDebug() << "Error: Could not write to socket.";
        return;
    }

    if (!socket->waitForReadyRead(3000)) {
        qDebug() << "Error: No data received from server.";
        return;
    }

    while (socket->bytesAvailable()) {
        QString response = socket->readLine().trimmed();
        QStringList data = response.split(" ");
        if (data.size() != 2) {
            continue;
        }

        bool ok;
        qint64 timestamp = data[0].toLongLong(&ok);
        double value = data[1].toDouble(&ok);

        if (ok) {
            // Atualiza o gráfico
            updateChart(timestamp, value);
        }
    }
}


void MainWindow::updateChart(qint64 timestamp, double value) {
    double timeInSeconds = timestamp / 1000.0;

    // Adicionar ponto ao gráfico
    series->append(timeInSeconds, value);

    // Limitar o número de pontos no gráfico
    if (series->count() > numSamples) {
        series->remove(0);
    }

    // Atualizar os eixos para refletir os novos dados
    axisX->setRange(timeInSeconds - 30, timeInSeconds); // Últimos 30 segundos
    axisY->setRange(0, value * 1.2); // Ajusta o eixo Y para o valor máximo
}

MainWindow::~MainWindow()
{
    delete socket;
    delete timer;
    delete ui;
}
