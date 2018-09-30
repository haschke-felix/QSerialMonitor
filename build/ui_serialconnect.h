/********************************************************************************
** Form generated from reading UI file 'serialconnect.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALCONNECT_H
#define UI_SERIALCONNECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SerialConnect
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonUpdate;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonConnect;

    void setupUi(QDialog *SerialConnect)
    {
        if (SerialConnect->objectName().isEmpty())
            SerialConnect->setObjectName(QStringLiteral("SerialConnect"));
        SerialConnect->resize(304, 298);
        verticalLayout = new QVBoxLayout(SerialConnect);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeWidget = new QTreeWidget(SerialConnect);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        verticalLayout->addWidget(treeWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonUpdate = new QPushButton(SerialConnect);
        pushButtonUpdate->setObjectName(QStringLiteral("pushButtonUpdate"));

        horizontalLayout->addWidget(pushButtonUpdate);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonCancel = new QPushButton(SerialConnect);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout->addWidget(pushButtonCancel);

        pushButtonConnect = new QPushButton(SerialConnect);
        pushButtonConnect->setObjectName(QStringLiteral("pushButtonConnect"));

        horizontalLayout->addWidget(pushButtonConnect);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SerialConnect);

        QMetaObject::connectSlotsByName(SerialConnect);
    } // setupUi

    void retranslateUi(QDialog *SerialConnect)
    {
        SerialConnect->setWindowTitle(QApplication::translate("SerialConnect", "Dialog", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("SerialConnect", "Manufacture", Q_NULLPTR));
        ___qtreewidgetitem->setText(1, QApplication::translate("SerialConnect", "Description", Q_NULLPTR));
        ___qtreewidgetitem->setText(0, QApplication::translate("SerialConnect", "Name", Q_NULLPTR));
        pushButtonUpdate->setText(QApplication::translate("SerialConnect", "Update", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        pushButtonUpdate->setShortcut(QApplication::translate("SerialConnect", "F5", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        pushButtonCancel->setText(QApplication::translate("SerialConnect", "Cancel", Q_NULLPTR));
        pushButtonConnect->setText(QApplication::translate("SerialConnect", "Connect", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SerialConnect: public Ui_SerialConnect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALCONNECT_H
