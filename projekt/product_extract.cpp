#include "product_extract.h"
#include "ui_product_extract.h"
#include <QSqlTableModel>

product_extract::product_extract(int h,QWidget *parent)
    : QDialog(parent),
   ui(new Ui::product_extract)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: ;");
    setWindowTitle("Výpis produktu");
    setWindowIcon(QIcon(":/img/mainIcon"));

    hh = h;
    QString H = QString::number(hh);
    QString dotazA = "SELECT produkt, zpracovani,chut,prazeni,odrudy.odruda,oblasti.oblast FROM produkty JOIN oblasti ON oblasti.oblast_id = produkty.oblast_id JOIN odrudy ON odrudy.odruda_id = produkty.odruda_id WHERE produkt_id = %1";

     QSqlQuery dotaz (dotazA.arg(H));

     QString produkt;
     QString proc;
     QString roast;
     QString var;
     QString plac;
     QString chut;
     while (dotaz.next())
     {
    produkt = dotaz.value("produkt").toString();
    proc = dotaz.value("zpracovani").toString();
    roast = dotaz.value("prazeni").toString();
    var = dotaz.value("odrudy.odruda").toString();
    plac = dotaz.value("oblasti.oblast").toString();
    chut = dotaz.value("chut").toString();

}
    ui->lineEdit_product->setText(produkt);
    ui->lineEdit_proc->setText(proc);
    ui->lineEdit_roast->setText(roast);
    ui->lineEdit_var->setText(var);
    ui->lineEdit_place->setText(plac);
    ui->textEdit->setText(chut);
}
product_extract::~product_extract()
{
    delete ui;
}

void product_extract::on_close_clicked()
    {
        this->close();
    }
