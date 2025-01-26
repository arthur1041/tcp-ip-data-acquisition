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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_15;
    QFrame *frame;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonConnect;
    QPushButton *pushButtonDisconnect;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_20;
    QLineEdit *lineEditIPServidor;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_9;
    QSlider *horizontalSliderMin;
    QLCDNumber *lcdNumberMin;
    QLabel *label;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_10;
    QSlider *horizontalSliderMax;
    QLCDNumber *lcdNumberMax;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_3;
    QSlider *horizontalSliderTiming;
    QLabel *labelTiming;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonStop;
    QLabel *labelConnected;
    QVBoxLayout *verticalLayout_16;
    QFrame *frame_2;
    QTextBrowser *textBrowserLog;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(543, 400);
        MainWindow->setMinimumSize(QSize(543, 400));
        MainWindow->setMaximumSize(QSize(543, 400));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(-18, 0, 571, 351));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName("verticalLayout_15");
        verticalLayout_15->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(horizontalLayoutWidget);
        frame->setObjectName("frame");
        frame->setEnabled(true);
        frame->setMaximumSize(QSize(16777215, 16777215));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QString::fromUtf8("background: transparent;"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayoutWidget_2 = new QWidget(frame);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(24, 29, 250, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButtonConnect = new QPushButton(horizontalLayoutWidget_2);
        pushButtonConnect->setObjectName("pushButtonConnect");

        horizontalLayout_5->addWidget(pushButtonConnect);

        pushButtonDisconnect = new QPushButton(horizontalLayoutWidget_2);
        pushButtonDisconnect->setObjectName("pushButtonDisconnect");

        horizontalLayout_5->addWidget(pushButtonDisconnect);

        verticalLayoutWidget_3 = new QWidget(frame);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(23, -4, 251, 41));
        verticalLayout_20 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_20->setSpacing(6);
        verticalLayout_20->setContentsMargins(11, 11, 11, 11);
        verticalLayout_20->setObjectName("verticalLayout_20");
        verticalLayout_20->setContentsMargins(0, 0, 0, 0);
        lineEditIPServidor = new QLineEdit(verticalLayoutWidget_3);
        lineEditIPServidor->setObjectName("lineEditIPServidor");
        lineEditIPServidor->setMaximumSize(QSize(16777215, 25));
        lineEditIPServidor->setClearButtonEnabled(false);

        verticalLayout_20->addWidget(lineEditIPServidor);

        horizontalLayoutWidget_3 = new QWidget(frame);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(30, 120, 241, 31));
        horizontalLayout_9 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalSliderMin = new QSlider(horizontalLayoutWidget_3);
        horizontalSliderMin->setObjectName("horizontalSliderMin");
        horizontalSliderMin->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_9->addWidget(horizontalSliderMin);

        lcdNumberMin = new QLCDNumber(horizontalLayoutWidget_3);
        lcdNumberMin->setObjectName("lcdNumberMin");

        horizontalLayout_9->addWidget(lcdNumberMin);

        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 104, 37, 12));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(210, 174, 37, 12));
        label_2->setFont(font);
        horizontalLayoutWidget_4 = new QWidget(frame);
        horizontalLayoutWidget_4->setObjectName("horizontalLayoutWidget_4");
        horizontalLayoutWidget_4->setGeometry(QRect(30, 190, 241, 31));
        horizontalLayout_10 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        horizontalSliderMax = new QSlider(horizontalLayoutWidget_4);
        horizontalSliderMax->setObjectName("horizontalSliderMax");
        horizontalSliderMax->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_10->addWidget(horizontalSliderMax);

        lcdNumberMax = new QLCDNumber(horizontalLayoutWidget_4);
        lcdNumberMax->setObjectName("lcdNumberMax");

        horizontalLayout_10->addWidget(lcdNumberMax);

        horizontalLayoutWidget_5 = new QWidget(frame);
        horizontalLayoutWidget_5->setObjectName("horizontalLayoutWidget_5");
        horizontalLayoutWidget_5->setGeometry(QRect(30, 250, 241, 31));
        horizontalLayout_12 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_5);
        label_3->setObjectName("label_3");
        QFont font1;
        font1.setBold(true);
        label_3->setFont(font1);

        horizontalLayout_12->addWidget(label_3);

        horizontalSliderTiming = new QSlider(horizontalLayoutWidget_5);
        horizontalSliderTiming->setObjectName("horizontalSliderTiming");
        horizontalSliderTiming->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_12->addWidget(horizontalSliderTiming);

        labelTiming = new QLabel(horizontalLayoutWidget_5);
        labelTiming->setObjectName("labelTiming");
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        labelTiming->setFont(font2);

        horizontalLayout_12->addWidget(labelTiming);

        horizontalLayoutWidget_6 = new QWidget(frame);
        horizontalLayoutWidget_6->setObjectName("horizontalLayoutWidget_6");
        horizontalLayoutWidget_6->setGeometry(QRect(24, 319, 250, 31));
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

        labelConnected = new QLabel(frame);
        labelConnected->setObjectName("labelConnected");
        labelConnected->setGeometry(QRect(28, 60, 241, 20));
        labelConnected->setFont(font1);
        labelConnected->setStyleSheet(QString::fromUtf8("color: red;"));

        verticalLayout_15->addWidget(frame);


        horizontalLayout_4->addLayout(verticalLayout_15);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setObjectName("verticalLayout_16");
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(horizontalLayoutWidget);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        textBrowserLog = new QTextBrowser(frame_2);
        textBrowserLog->setObjectName("textBrowserLog");
        textBrowserLog->setGeometry(QRect(0, 0, 271, 351));

        verticalLayout_16->addWidget(frame_2);


        horizontalLayout_4->addLayout(verticalLayout_16);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 543, 18));
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
        pushButtonConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        pushButtonDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        lineEditIPServidor->setPlaceholderText(QCoreApplication::translate("MainWindow", "Digite o IP do Servidor", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Max", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Timing(s)", nullptr));
        labelTiming->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
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
