#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(int h,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    hh = h;
    QString H = QString::number(hh);
    QString Hk = "SELECT produkt from produkty";

    ui->label->setText(H);

    QString dotazA = "SELECT produkt from produkty WHERE produkt_id = %1";
    QSqlQuery dotaz (dotazA.arg(H));

     QString U;
     while (dotaz.next())
     {
    U = dotaz.value("produkt").toString();
}
    ui->lineEdit->setText(U);

}

Dialog::~Dialog()
{
    delete ui;
}
