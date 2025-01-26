#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    std::string connectedIP;

public slots:
    void putData();
    void tcpConnect();
    void tcpDisconnect();
    void updateMinValue(int value);
    void updateMaxValue(int value);
    void updateTimingValue(int value);
    void startTimer();
    void stopTimer();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    int minValue;
    int maxValue;
    int timing;
    QTimer *timer;
};

#endif // MAINWINDOW_H
