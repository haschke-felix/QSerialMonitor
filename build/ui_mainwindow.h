/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionVisit_Tekkietorium_de;
    QAction *actionSave;
    QAction *actionNew;
    QAction *actionOpen_2;
    QAction *actionSave_2;
    QAction *actionSave_All;
    QAction *actionOpen;
    QAction *actionInfo;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLabel *label;
    QPushButton *pushButton_connect;
    QPushButton *pushButton_disconnect;
    QComboBox *comboBox_baud;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBox_show_tranmitted;
    QPushButton *pushButton_clear;
    QMenuBar *menuBar;
    QMenu *menuHelp;
    QMenu *menuTools;
    QMenu *menuEdit;
    QMenu *menuFile;
    QToolBar *toolBar_1;
    QToolBar *toolBar_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(803, 494);
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionVisit_Tekkietorium_de = new QAction(MainWindow);
        actionVisit_Tekkietorium_de->setObjectName(QStringLiteral("actionVisit_Tekkietorium_de"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen_2 = new QAction(MainWindow);
        actionOpen_2->setObjectName(QStringLiteral("actionOpen_2"));
        actionSave_2 = new QAction(MainWindow);
        actionSave_2->setObjectName(QStringLiteral("actionSave_2"));
        actionSave_All = new QAction(MainWindow);
        actionSave_All->setObjectName(QStringLiteral("actionSave_All"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName(QStringLiteral("actionInfo"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/images/info icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInfo->setIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setFrameShadow(QFrame::Sunken);
        plainTextEdit->setLineWrapMode(QPlainTextEdit::WidgetWidth);
        plainTextEdit->setReadOnly(true);
        plainTextEdit->setCenterOnScroll(true);

        verticalLayout->addWidget(plainTextEdit);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(100, 0));

        horizontalLayout_4->addWidget(label);

        pushButton_connect = new QPushButton(centralWidget);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));

        horizontalLayout_4->addWidget(pushButton_connect);

        pushButton_disconnect = new QPushButton(centralWidget);
        pushButton_disconnect->setObjectName(QStringLiteral("pushButton_disconnect"));

        horizontalLayout_4->addWidget(pushButton_disconnect);

        comboBox_baud = new QComboBox(centralWidget);
        comboBox_baud->setObjectName(QStringLiteral("comboBox_baud"));

        horizontalLayout_4->addWidget(comboBox_baud);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        checkBox_show_tranmitted = new QCheckBox(centralWidget);
        checkBox_show_tranmitted->setObjectName(QStringLiteral("checkBox_show_tranmitted"));

        horizontalLayout_4->addWidget(checkBox_show_tranmitted);

        pushButton_clear = new QPushButton(centralWidget);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));

        horizontalLayout_4->addWidget(pushButton_clear);


        verticalLayout->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 803, 22));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        toolBar_1 = new QToolBar(MainWindow);
        toolBar_1->setObjectName(QStringLiteral("toolBar_1"));
        MainWindow->addToolBar(Qt::BottomToolBarArea, toolBar_1);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionVisit_Tekkietorium_de);
        menuTools->addAction(actionInfo);
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen_2);
        menuFile->addAction(actionSave_All);
        menuFile->addAction(actionSave_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionVisit_Tekkietorium_de->setText(QApplication::translate("MainWindow", "Visit Tekkietorium.de", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        actionNew->setText(QApplication::translate("MainWindow", "New", Q_NULLPTR));
        actionOpen_2->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        actionSave_2->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        actionSave_All->setText(QApplication::translate("MainWindow", "Save All", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        actionInfo->setText(QApplication::translate("MainWindow", "info", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Port:", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "unconnected", Q_NULLPTR));
        pushButton_connect->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        pushButton_disconnect->setText(QApplication::translate("MainWindow", "Disconnect", Q_NULLPTR));
        comboBox_baud->clear();
        comboBox_baud->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "300 baud", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1200 baud", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2400 baud", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4800 baud", Q_NULLPTR)
         << QApplication::translate("MainWindow", "9600 baud", Q_NULLPTR)
         << QApplication::translate("MainWindow", "19200 baud", Q_NULLPTR)
         << QApplication::translate("MainWindow", "38400 baud", Q_NULLPTR)
         << QApplication::translate("MainWindow", "57600 baud", Q_NULLPTR)
         << QApplication::translate("MainWindow", "74880 baud", Q_NULLPTR)
         << QApplication::translate("MainWindow", "115200 baud", Q_NULLPTR)
        );
        checkBox_show_tranmitted->setText(QApplication::translate("MainWindow", "Show Transmitted", Q_NULLPTR));
        pushButton_clear->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        toolBar_1->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
