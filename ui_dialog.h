/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QLabel *StatusText;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *HostLineEdit;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *connectButton;
    QPushButton *DisconnectButton;
    QSpacerItem *verticalSpacer;
    QPushButton *changeDirectoryButton;
    QPushButton *UpButton;
    QPushButton *getFileButton;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(465, 377);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        StatusText = new QLabel(Dialog);
        StatusText->setObjectName(QStringLiteral("StatusText"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StatusText->sizePolicy().hasHeightForWidth());
        StatusText->setSizePolicy(sizePolicy);

        gridLayout->addWidget(StatusText, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        HostLineEdit = new QLineEdit(Dialog);
        HostLineEdit->setObjectName(QStringLiteral("HostLineEdit"));

        horizontalLayout->addWidget(HostLineEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        listWidget = new QListWidget(groupBox);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        horizontalLayout_2->addWidget(listWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        connectButton = new QPushButton(groupBox);
        connectButton->setObjectName(QStringLiteral("connectButton"));

        verticalLayout->addWidget(connectButton);

        DisconnectButton = new QPushButton(groupBox);
        DisconnectButton->setObjectName(QStringLiteral("DisconnectButton"));

        verticalLayout->addWidget(DisconnectButton);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        changeDirectoryButton = new QPushButton(groupBox);
        changeDirectoryButton->setObjectName(QStringLiteral("changeDirectoryButton"));

        verticalLayout->addWidget(changeDirectoryButton);

        UpButton = new QPushButton(groupBox);
        UpButton->setObjectName(QStringLiteral("UpButton"));

        verticalLayout->addWidget(UpButton);

        getFileButton = new QPushButton(groupBox);
        getFileButton->setObjectName(QStringLiteral("getFileButton"));

        verticalLayout->addWidget(getFileButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout);


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Ftp Mini Client", 0));
        StatusText->setText(QApplication::translate("Dialog", "Ready", 0));
        label->setText(QApplication::translate("Dialog", "Host:", 0));
        HostLineEdit->setText(QApplication::translate("Dialog", "ftp://ftp.trolltech.com", 0));
        groupBox->setTitle(QApplication::translate("Dialog", "Host", 0));
        connectButton->setText(QApplication::translate("Dialog", "Connect", 0));
        DisconnectButton->setText(QApplication::translate("Dialog", "Disconnect", 0));
        changeDirectoryButton->setText(QApplication::translate("Dialog", "Change Directory", 0));
        UpButton->setText(QApplication::translate("Dialog", "Up", 0));
        getFileButton->setText(QApplication::translate("Dialog", "Get File", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
