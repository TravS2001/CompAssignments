/********************************************************************************
** Form generated from reading UI file 'fractioncalculator.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRACTIONCALCULATOR_H
#define UI_FRACTIONCALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FractionCalculator
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QLineEdit *Num1;
    QLineEdit *Num2;
    QLineEdit *Denom1;
    QLineEdit *Denom2;
    QPushButton *Calculate;
    QPushButton *Exit;
    QComboBox *Operation;
    QLabel *Answer;
    QWidget *page_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FractionCalculator)
    {
        if (FractionCalculator->objectName().isEmpty())
            FractionCalculator->setObjectName(QString::fromUtf8("FractionCalculator"));
        FractionCalculator->resize(423, 246);
        FractionCalculator->setMouseTracking(false);
        centralwidget = new QWidget(FractionCalculator);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout->addWidget(label);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        Num1 = new QLineEdit(page_3);
        Num1->setObjectName(QString::fromUtf8("Num1"));
        Num1->setGeometry(QRect(10, 20, 113, 21));
        Num2 = new QLineEdit(page_3);
        Num2->setObjectName(QString::fromUtf8("Num2"));
        Num2->setGeometry(QRect(270, 20, 113, 21));
        Denom1 = new QLineEdit(page_3);
        Denom1->setObjectName(QString::fromUtf8("Denom1"));
        Denom1->setGeometry(QRect(10, 60, 113, 21));
        Denom2 = new QLineEdit(page_3);
        Denom2->setObjectName(QString::fromUtf8("Denom2"));
        Denom2->setGeometry(QRect(270, 60, 113, 21));
        Calculate = new QPushButton(page_3);
        Calculate->setObjectName(QString::fromUtf8("Calculate"));
        Calculate->setGeometry(QRect(160, 120, 80, 22));
        Exit = new QPushButton(page_3);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        Exit->setGeometry(QRect(160, 140, 80, 22));
        Operation = new QComboBox(page_3);
        Operation->addItem(QString());
        Operation->addItem(QString());
        Operation->addItem(QString());
        Operation->addItem(QString());
        Operation->setObjectName(QString::fromUtf8("Operation"));
        Operation->setGeometry(QRect(170, 40, 65, 22));
        Answer = new QLabel(page_3);
        Answer->setObjectName(QString::fromUtf8("Answer"));
        Answer->setGeometry(QRect(130, 90, 141, 21));
        Answer->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        stackedWidget->addWidget(page_4);

        verticalLayout->addWidget(stackedWidget);

        FractionCalculator->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FractionCalculator);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 423, 21));
        FractionCalculator->setMenuBar(menubar);
        statusbar = new QStatusBar(FractionCalculator);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FractionCalculator->setStatusBar(statusbar);

        retranslateUi(FractionCalculator);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FractionCalculator);
    } // setupUi

    void retranslateUi(QMainWindow *FractionCalculator)
    {
        FractionCalculator->setWindowTitle(QCoreApplication::translate("FractionCalculator", "FractionCalculator", nullptr));
        label->setText(QCoreApplication::translate("FractionCalculator", "Fraction Calculator by Travis Stephney", nullptr));
        Calculate->setText(QCoreApplication::translate("FractionCalculator", "Calculate", nullptr));
        Exit->setText(QCoreApplication::translate("FractionCalculator", "Exit", nullptr));
        Operation->setItemText(0, QCoreApplication::translate("FractionCalculator", "Add", nullptr));
        Operation->setItemText(1, QCoreApplication::translate("FractionCalculator", "Subtract", nullptr));
        Operation->setItemText(2, QCoreApplication::translate("FractionCalculator", "Multiply", nullptr));
        Operation->setItemText(3, QCoreApplication::translate("FractionCalculator", "Divide", nullptr));

        Answer->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FractionCalculator: public Ui_FractionCalculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRACTIONCALCULATOR_H
