#ifndef FRACTIONCALCULATOR_H
#define FRACTIONCALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class FractionCalculator; }
QT_END_NAMESPACE

class FractionCalculator : public QMainWindow
{
    Q_OBJECT

public:
    FractionCalculator(QWidget *parent = nullptr);
    ~FractionCalculator();

private:
    Ui::FractionCalculator *ui;


private slots:
    void exit_app();
    void on_Calculate_clicked();
};
#endif // FRACTIONCALCULATOR_H
