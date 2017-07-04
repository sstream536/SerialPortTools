/********************************************************************************
** Form generated from reading UI file 'SerialPortTools.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORTTOOLS_H
#define UI_SERIALPORTTOOLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialPortToolsClass
{
public:
    QAction *openaction;
    QAction *closeaction;
    QAction *aboutaction;
    QWidget *centralWidget;
    QFormLayout *formLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QLabel *label_4;
    QComboBox *comboBox_4;
    QLabel *label_5;
    QComboBox *comboBox_5;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QGroupBox *groupBox_3;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit_2;
    QPushButton *pushButton;
    QToolBar *toolBar;

    void setupUi(QMainWindow *SerialPortToolsClass)
    {
        if (SerialPortToolsClass->objectName().isEmpty())
            SerialPortToolsClass->setObjectName(QStringLiteral("SerialPortToolsClass"));
        SerialPortToolsClass->resize(709, 414);
        SerialPortToolsClass->setStyleSheet(QStringLiteral(""));
        openaction = new QAction(SerialPortToolsClass);
        openaction->setObjectName(QStringLiteral("openaction"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/SerialPortTools/image/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        openaction->setIcon(icon);
        closeaction = new QAction(SerialPortToolsClass);
        closeaction->setObjectName(QStringLiteral("closeaction"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/SerialPortTools/image/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeaction->setIcon(icon1);
        aboutaction = new QAction(SerialPortToolsClass);
        aboutaction->setObjectName(QStringLiteral("aboutaction"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/SerialPortTools/image/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        aboutaction->setIcon(icon2);
        centralWidget = new QWidget(SerialPortToolsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        formLayout_2 = new QFormLayout(centralWidget);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(11);
        groupBox->setFont(font);
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 201, 161));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBox = new QComboBox(formLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        comboBox_2 = new QComboBox(formLayoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBox_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        comboBox_3 = new QComboBox(formLayoutWidget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        comboBox_4 = new QComboBox(formLayoutWidget);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBox_4);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        comboBox_5 = new QComboBox(formLayoutWidget);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_5->sizePolicy().hasHeightForWidth());
        comboBox_5->setSizePolicy(sizePolicy1);

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBox_5);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(10, 30, 89, 16));
        radioButton->setStyleSheet(QStringLiteral(""));
        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(120, 30, 89, 16));

        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        radioButton_3 = new QRadioButton(groupBox_3);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(10, 30, 89, 16));
        radioButton_4 = new QRadioButton(groupBox_3);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(120, 30, 89, 16));

        verticalLayout->addWidget(groupBox_3);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout_2->setContentsMargins(0, -1, -1, -1);
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout_2->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setTabStopWidth(80);

        horizontalLayout->addWidget(textEdit_2);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(pushButton);

        horizontalLayout->setStretch(0, 5);
        horizontalLayout->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 5);
        verticalLayout_2->setStretch(1, 2);

        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 2);

        formLayout_2->setLayout(0, QFormLayout::SpanningRole, gridLayout);

        SerialPortToolsClass->setCentralWidget(centralWidget);
        toolBar = new QToolBar(SerialPortToolsClass);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setEnabled(true);
        toolBar->setContextMenuPolicy(Qt::NoContextMenu);
        toolBar->setMovable(false);
        toolBar->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        toolBar->setFloatable(false);
        SerialPortToolsClass->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(openaction);
        toolBar->addAction(closeaction);
        toolBar->addAction(aboutaction);

        retranslateUi(SerialPortToolsClass);

        QMetaObject::connectSlotsByName(SerialPortToolsClass);
    } // setupUi

    void retranslateUi(QMainWindow *SerialPortToolsClass)
    {
        SerialPortToolsClass->setWindowTitle(QApplication::translate("SerialPortToolsClass", "SerialPortTools", 0));
        openaction->setText(QApplication::translate("SerialPortToolsClass", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
#ifndef QT_NO_TOOLTIP
        openaction->setToolTip(QApplication::translate("SerialPortToolsClass", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
#endif // QT_NO_TOOLTIP
        closeaction->setText(QApplication::translate("SerialPortToolsClass", "\345\205\263\351\227\255\344\270\262\345\217\243", 0));
        aboutaction->setText(QApplication::translate("SerialPortToolsClass", "\345\205\263\344\272\216", 0));
        groupBox->setTitle(QApplication::translate("SerialPortToolsClass", "\344\270\262\345\217\243\350\256\276\347\275\256", 0));
        label->setText(QApplication::translate("SerialPortToolsClass", "\347\253\257  \345\217\243:", 0));
        comboBox->setCurrentText(QString());
        label_2->setText(QApplication::translate("SerialPortToolsClass", "\346\263\242\347\211\271\347\216\207:", 0));
        label_3->setText(QApplication::translate("SerialPortToolsClass", "\346\225\260\346\215\256\344\275\215:", 0));
        label_4->setText(QApplication::translate("SerialPortToolsClass", "\346\240\241\351\252\214\344\275\215:", 0));
        label_5->setText(QApplication::translate("SerialPortToolsClass", "\345\201\234\346\255\242\344\275\215:", 0));
        groupBox_2->setTitle(QApplication::translate("SerialPortToolsClass", "\346\216\245\346\224\266\350\256\276\347\275\256", 0));
        radioButton->setText(QApplication::translate("SerialPortToolsClass", "ASCII", 0));
        radioButton_2->setText(QApplication::translate("SerialPortToolsClass", "HEX", 0));
        groupBox_3->setTitle(QApplication::translate("SerialPortToolsClass", "\345\217\221\351\200\201\350\256\276\347\275\256", 0));
        radioButton_3->setText(QApplication::translate("SerialPortToolsClass", "ASCII", 0));
        radioButton_4->setText(QApplication::translate("SerialPortToolsClass", "HEX", 0));
        pushButton->setText(QApplication::translate("SerialPortToolsClass", "\345\217\221\351\200\201", 0));
        toolBar->setWindowTitle(QApplication::translate("SerialPortToolsClass", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class SerialPortToolsClass: public Ui_SerialPortToolsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORTTOOLS_H
