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
    QString dotazA = "SELECT produkt, zpracovani,chut,prazeni,odrudy.odruda,oblasti.oblast,produkty.intenzita,produkty.kyselost FROM produkty JOIN oblasti ON oblasti.oblast_id = produkty.oblast_id JOIN odrudy ON odrudy.odruda_id = produkty.odruda_id WHERE produkt_id = %1";

     QSqlQuery dotaz (dotazA.arg(H));

     QString produkt;
     QString proc;
     QString roast;
     QString var;
     QString plac;
     QString chut;
     QString intenzite;
      QString kyselost;
     while (dotaz.next())
     {
    produkt = dotaz.value("produkt").toString();
    proc = dotaz.value("zpracovani").toString();
    roast = dotaz.value("prazeni").toString();
    var = dotaz.value("odrudy.odruda").toString();
    plac = dotaz.value("oblasti.oblast").toString();
    chut = dotaz.value("chut").toString();
    intenzite = dotaz.value("intenzita").toString();
    kyselost = dotaz.value("kyselost").toString();

}
    ui->lineEdit_product->setText(produkt);
    ui->lineEdit_proc->setText(proc);
    ui->lineEdit_roast->setText(roast);
    ui->lineEdit_var->setText(var);
    ui->lineEdit_place->setText(plac);
    ui->label_kyselost->setText(kyselost);
    ui->textEdit->setText(chut);
    if(intenzite == '1'){

    QPixmap image(":/img/inten1");
    ui->label_int->setPixmap(image);

       }
    else if(intenzite == '2'){

    QPixmap image(":/img/inten2");
    ui->label_int->setPixmap(image);

    }
    else if(intenzite == '3'){

    QPixmap image(":/img/inten3");
    ui->label_int->setPixmap(image);

    }
    else if(intenzite == '4'){

    QPixmap image(":/img/inten4");
    ui->label_int->setPixmap(image);

    }
    else if(intenzite == '5'){

    QPixmap image(":/img/inten5");
    ui->label_int->setPixmap(image);

    }
    else if(intenzite == '-' or intenzite == NULL){

    QPixmap image(":/img/inten0");
    ui->label_int->setPixmap(image);


}
    if(kyselost == '1'){

    QPixmap image(":/img/inten1");
    ui->label_kyselost->setPixmap(image);

       }
    else if(kyselost == '2'){

    QPixmap image(":/img/inten2");
    ui->label_kyselost->setPixmap(image);

    }
    else if(kyselost == '3'){

    QPixmap image(":/img/inten3");
    ui->label_kyselost->setPixmap(image);

    }
    else if(kyselost == '4'){

    QPixmap image(":/img/inten4");
    ui->label_kyselost->setPixmap(image);

    }
    else if(kyselost == '5'){

    QPixmap image(":/img/inten5");
    ui->label_kyselost->setPixmap(image);

    }
    else if(kyselost == '-' or kyselost == NULL){

    QPixmap image(":/img/inten0");
    ui->label_kyselost->setPixmap(image);


}
}
product_extract::~product_extract()
{
    delete ui;
}

void product_extract::on_close_clicked()
    {
        this->close();
    }
