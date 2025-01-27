#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QTcpSocket>
#include <QTimer>
#include <QListWidgetItem>
#include <QVector>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void tcpConnect();
    void tcpDisconnect();
    void updateMachineList();
    void selectMachine(QListWidgetItem *item);
    void startReceiving();
    void stopReceiving();
    void updateCaptureInterval(int value);
    void getData();
    void updateChart(qint64 timestamp, double value);
private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QTimer *timer;
    QString selectedMachine;
    int captureInterval;
    int numSamples;

    // Gráfico
    QChart *chart;
    QLineSeries *series;
    QValueAxis *axisX;
    QValueAxis *axisY;

    void setupChart();
};

#endif // MAINWINDOW_H
