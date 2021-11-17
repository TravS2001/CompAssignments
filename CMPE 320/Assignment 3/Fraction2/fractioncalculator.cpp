#include "fractioncalculator.h"
#include "ui_fractioncalculator.h"
#include "FractionLibrary/Fraction_global.h"
#include "FractionLibrary/fraction.h"

FractionCalculator::FractionCalculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FractionCalculator)
{
    ui->setupUi(this);

    connect(ui->Exit, SIGNAL(clicked()), this, SLOT(exit_app()));
}

FractionCalculator::~FractionCalculator()
{
    delete ui;
}

void FractionCalculator::exit_app(){
    QApplication::exit();
}


void FractionCalculator::on_Calculate_clicked()
{
    //ui->Answer->setText(ui->Num1->text());
    int num1=(ui->Num1->text()).toInt();
    int den1=(ui->Denom1->text()).toInt();
    Fraction frac1=Fraction(num1, den1);


    int num2=(ui->Num2->text()).toInt();
    int den2=(ui->Denom2->text()).toInt();
    Fraction frac2=Fraction(num2, den2);

    Fraction ans=Fraction();

    QString op=ui->Operation->currentText();
    if(op.compare("Add")==0){
        ans=frac1+frac2;
    }else if (op.compare("Subtract")==0) {
        ans=frac1-frac2;
    }else if (op.compare("Multiply")==0) {
        ans=frac1*frac2;
    }else if(op.compare("Divide")==0)  {
        ans=frac1/frac2;
    }


    QString n= QString::number(ans.numerator());
    QString d= QString::number(ans.denominator());
    QString v= n +"/" +d;
    ui->Answer->setText(v);

}

