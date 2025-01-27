#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QTimer>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    socket = new QTcpSocket(this);
    timer = new QTimer(this); // Inicializa o QTimer
    maxValue = 80;
    minValue = 1;
    timing = 1;

    // Configura sliders e valores iniciais
    ui->horizontalSliderMax->setValue(maxValue);
    ui->horizontalSliderMin->setValue(minValue);
    ui->lcdNumberMax->display(maxValue);
    ui->lcdNumberMin->display(minValue);

    ui->horizontalSliderTiming->setValue(timing);
    ui->labelTiming->setText(QString::number(timing));

    // Conectar sliders para atualização de valores
    connect(ui->horizontalSliderMin, &QSlider::valueChanged, this, &MainWindow::updateMinValue);
    connect(ui->horizontalSliderMax, &QSlider::valueChanged, this, &MainWindow::updateMaxValue);
    connect(ui->horizontalSliderTiming, &QSlider::valueChanged, this, &MainWindow::updateTimingValue);

    // Conectar botões para conexão e controle do timer
    connect(ui->pushButtonConnect, &QPushButton::clicked, this, &MainWindow::tcpConnect);
    connect(ui->pushButtonDisconnect, &QPushButton::clicked, this, &MainWindow::tcpDisconnect);
    connect(ui->pushButtonStart, &QPushButton::clicked, this, &MainWindow::startTimer);
    connect(ui->pushButtonStop, &QPushButton::clicked, this, &MainWindow::stopTimer);
}

void MainWindow::startTimer() {
    if (socket->state() == QAbstractSocket::ConnectedState) {
        timer->setInterval(timing * 1000); // Define o intervalo do timer com o valor atual

        // Remove qualquer conexão anterior ao timeout
        disconnect(timer, &QTimer::timeout, this, &MainWindow::putData);

        // Conecta ao putData (agora com garantia de conexão única)
        connect(timer, &QTimer::timeout, this, &MainWindow::putData, Qt::UniqueConnection);

        // Inicia o timer
        timer->start();
        qDebug() << "Timer started with interval:" << timing * 1000 << "ms";
    } else {
        qDebug() << "Cannot start timer: Socket is not connected.";
    }
}

void MainWindow::stopTimer() {
    if (timer->isActive()) {
        timer->stop(); // Para o timer
        qDebug() << "Timer stopped.";
    } else {
        qDebug() << "Timer is not running.";
    }
}

void MainWindow::putData() {
    if (socket->state() == QAbstractSocket::ConnectedState) {
        int randomValue = QRandomGenerator::global()->bounded(minValue, maxValue + 1);

        QDateTime datetime = QDateTime::currentDateTime();
        QString str = QString("set %1 %2\r\n")
                          .arg(datetime.toMSecsSinceEpoch())
                          .arg(randomValue);

        qDebug() << "Generated data:" << str;

        socket->write(str.toUtf8());
        if (socket->waitForBytesWritten(3000)) {
            qDebug() << "Data written to server.";

            // Adicionar o log ao QTextBrowser
            ui->textBrowserLog->append(str);

            // Limitar o número de linhas no log
            while (ui->textBrowserLog->document()->blockCount() > 100) {
                QTextCursor cursor = ui->textBrowserLog->textCursor();
                cursor.movePosition(QTextCursor::Start);
                cursor.select(QTextCursor::BlockUnderCursor);
                cursor.removeSelectedText();
                cursor.deleteChar(); // Remove o caractere de nova linha
            }
        }
    } else {
        qDebug() << "Socket is not connected. Stopping timer.";
        stopTimer(); // Para o timer se o socket estiver desconectado
        ui->textBrowserLog->append("Error: Socket is not connected.");
    }
}

void MainWindow::updateMinValue(int value) {
    if (value > maxValue) {
        ui->horizontalSliderMin->setValue(maxValue);
        return;
    }

    minValue = value;
    ui->lcdNumberMin->display(minValue);
}

void MainWindow::updateMaxValue(int value) {
    if (value < minValue) {
        ui->horizontalSliderMax->setValue(minValue);
        return;
    }

    maxValue = value;
    ui->lcdNumberMax->display(maxValue);
}

void MainWindow::updateTimingValue(int value) {
    if (value < 1) {
        ui->horizontalSliderTiming->setValue(1);
        return;
    }

    timing = value;
    ui->labelTiming->setText(QString::number(timing));

    // Atualize o intervalo do QTimer
    if (timer->isActive()) {
        timer->setInterval(timing * 1000); // Atualiza o intervalo para o novo valor
        qDebug() << "Timer interval updated to:" << timing * 1000 << "ms";
    }
}

void MainWindow::tcpConnect() {
    QString ipAddress = ui->lineEditIPServidor->text().trimmed();
    qDebug() << "Ip passado: " << ipAddress;
    socket->connectToHost(ipAddress, 1234);
    if (socket->waitForConnected(3000)) {
        ui->labelConnected->setText("Connected to " + ipAddress);
        ui->labelConnected->setStyleSheet("color: green;");
        qDebug() << "Connected";
    } else {
        qDebug() << "Unable to connect";
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

MainWindow::~MainWindow() {
    delete socket;
    delete timer;
    delete ui;
}
