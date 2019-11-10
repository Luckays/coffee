#include "variety_extract.h"
#include "ui_variety_extract.h"

variety_extract::variety_extract(int h,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::variety_extract)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: ;");
    setWindowTitle("Výpis Odrůdy");
    setWindowIcon(QIcon(":/img/mainIcon"));
    hh = h;
    QString H = QString::number(hh);
    QString dotazA = "SELECT odruda,popis,chut_odrudy,vznik,region,odolnost FROM odrudy WHERE odruda_id = %1";
    QSqlQuery dotaz (dotazA.arg(H));

    QString odruda;
    QString popis;
    QString chut;
    QString vznik;
    QString region;
    QString odolnost;

    while (dotaz.next())
    {
   odruda = dotaz.value("odruda").toString();
   popis = dotaz.value("popis").toString();
   chut = dotaz.value("chut_odrudy").toString();
   vznik = dotaz.value("vznik").toString();
   region = dotaz.value("region").toString();
   odolnost = dotaz.value("odolnost").toString();

}
      ui->lineEdit_var->setText(odruda);
      ui->textEdit->setText(popis);
      ui->lineEdit_taste->setText(chut);
      ui->lineEdit_origin->setText(vznik);
      ui->lineEdit_region->setText(region);


      if(odolnost == '1'){

      QPixmap image(":/img/inten1");
      ui->label_odolnost->setPixmap(image);

         }
      else if(odolnost == '2'){

      QPixmap image(":/img/inten2");
      ui->label_odolnost->setPixmap(image);

      }
      else if(odolnost == '3'){

      QPixmap image(":/img/inten3");
      ui->label_odolnost->setPixmap(image);

      }
      else if(odolnost == '4'){

      QPixmap image(":/img/inten4");
      ui->label_odolnost->setPixmap(image);

      }
      else if(odolnost == '5'){

      QPixmap image(":/img/inten5");
      ui->label_odolnost->setPixmap(image);

      }
      else if(odolnost == '-' or odolnost == NULL){

      QPixmap image(":/img/inten0");
      ui->label_odolnost->setPixmap(image);


  }
}
variety_extract::~variety_extract()
{
    delete ui;
}
void variety_extract::on_close_clicked()
    {
        this->close();
    }
