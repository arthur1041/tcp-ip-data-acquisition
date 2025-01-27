/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayoutChart;
    QFrame *frame_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_20;
    QLineEdit *lineEditServerIP;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonConnect;
    QPushButton *pushButtonDisconnect;
    QListWidget *listWidgetMachines;
    QPushButton *pushButtonUpdate;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_12;
    QSlider *horizontalSliderInterval;
    QLabel *labelTiming;
    QLabel *label_3;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonStop;
    QLabel *labelConnected;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(575, 400);
        MainWindow->setMinimumSize(QSize(575, 400));
        MainWindow->setMaximumSize(QSize(575, 400));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        frame = new QFrame(centralWidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(220, 0, 351, 351));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayoutWidget_2 = new QWidget(frame);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(-1, -1, 361, 351));
        verticalLayoutChart = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayoutChart->setSpacing(6);
        verticalLayoutChart->setContentsMargins(11, 11, 11, 11);
        verticalLayoutChart->setObjectName("verticalLayoutChart");
        verticalLayoutChart->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(0, 0, 211, 351));
        frame_2->setStyleSheet(QString::fromUtf8("background: transparent;"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayoutWidget = new QWidget(frame_2);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 211, 71));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setSpacing(6);
        verticalLayout_20->setObjectName("verticalLayout_20");
        lineEditServerIP = new QLineEdit(verticalLayoutWidget);
        lineEditServerIP->setObjectName("lineEditServerIP");
        lineEditServerIP->setMaximumSize(QSize(16777215, 25));
        lineEditServerIP->setClearButtonEnabled(false);

        verticalLayout_20->addWidget(lineEditServerIP);


        verticalLayout->addLayout(verticalLayout_20);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        pushButtonConnect = new QPushButton(verticalLayoutWidget);
        pushButtonConnect->setObjectName("pushButtonConnect");

        horizontalLayout_5->addWidget(pushButtonConnect);

        pushButtonDisconnect = new QPushButton(verticalLayoutWidget);
        pushButtonDisconnect->setObjectName("pushButtonDisconnect");

        horizontalLayout_5->addWidget(pushButtonDisconnect);


        verticalLayout->addLayout(horizontalLayout_5);

        listWidgetMachines = new QListWidget(frame_2);
        listWidgetMachines->setObjectName("listWidgetMachines");
        listWidgetMachines->setGeometry(QRect(0, 90, 211, 173));
        listWidgetMachines->setStyleSheet(QString::fromUtf8("background: white;"));
        pushButtonUpdate = new QPushButton(frame_2);
        pushButtonUpdate->setObjectName("pushButtonUpdate");
        pushButtonUpdate->setGeometry(QRect(110, 269, 102, 21));
        horizontalLayoutWidget_5 = new QWidget(frame_2);
        horizontalLayoutWidget_5->setObjectName("horizontalLayoutWidget_5");
        horizontalLayoutWidget_5->setGeometry(QRect(0, 300, 211, 21));
        horizontalLayout_12 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        horizontalSliderInterval = new QSlider(horizontalLayoutWidget_5);
        horizontalSliderInterval->setObjectName("horizontalSliderInterval");
        horizontalSliderInterval->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_12->addWidget(horizontalSliderInterval);

        labelTiming = new QLabel(horizontalLayoutWidget_5);
        labelTiming->setObjectName("labelTiming");
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        labelTiming->setFont(font);

        horizontalLayout_12->addWidget(labelTiming);

        label_3 = new QLabel(frame_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 280, 41, 21));
        QFont font1;
        font1.setBold(true);
        label_3->setFont(font1);
        horizontalLayoutWidget_6 = new QWidget(frame_2);
        horizontalLayoutWidget_6->setObjectName("horizontalLayoutWidget_6");
        horizontalLayoutWidget_6->setGeometry(QRect(0, 320, 211, 31));
        horizontalLayout_13 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        pushButtonStart = new QPushButton(horizontalLayoutWidget_6);
        pushButtonStart->setObjectName("pushButtonStart");

        horizontalLayout_13->addWidget(pushButtonStart);

        pushButtonStop = new QPushButton(horizontalLayoutWidget_6);
        pushButtonStop->setObjectName("pushButtonStop");

        horizontalLayout_13->addWidget(pushButtonStop);

        labelConnected = new QLabel(frame_2);
        labelConnected->setObjectName("labelConnected");
        labelConnected->setGeometry(QRect(3, 60, 207, 20));
        labelConnected->setFont(font1);
        labelConnected->setStyleSheet(QString::fromUtf8("color: red;"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 575, 18));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEditServerIP->setPlaceholderText(QCoreApplication::translate("MainWindow", "Digite o IP do Servidor", nullptr));
        pushButtonConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        pushButtonDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        pushButtonUpdate->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        labelTiming->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Timing(s)", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pushButtonStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        labelConnected->setText(QCoreApplication::translate("MainWindow", "Disconnected", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
