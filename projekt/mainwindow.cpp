#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QColorDialog>
#include "QtSql/QtSql"
#include "qmessagebox.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
, ui(new Ui::MainWindow)
{
    ui->setupUi(this);
connect(ui->variety_place_table->model(), SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));
    QString path = "../kava.db";
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    db.open();

//okno produkty
  QSqlQuery *products = new QSqlQuery;
 products->exec("SELECT DISTINCT produkt FROM produkty");
 QStringList product;
 while(products->next()) // nahrani produktu
 {
     QString SKO = products->value(0).toString();
     product.append(SKO);
 }

 ui->comboBox_product->clear();
 ui->comboBox_product->addItem("");
 ui->comboBox_product->addItems(product);


 //okno odrudy
   QSqlQuery *varieties = new QSqlQuery;
  varieties->exec("SELECT DISTINCT odruda FROM odrudy");
  QStringList variety;
  while(varieties->next()) // nahrani produktu
  {
      QString SKO = varieties->value(0).toString();
      variety.append(SKO);
  }
  model_place = new QSqlTableModel(this);
  model_place ->setQuery("SELECT oblast FROM oblasti");



   ui->variety_place_table->setModel(model_place);
   ui->variety_place_table->show();
   ui->variety_place_table->resizeColumnsToContents();


   model_product2 = new QSqlTableModel(this);
   model_product2 -> setQuery("SELECT produkt FROM produkty");



   ui->variety_product_table->setModel(model_product2);
   ui->variety_product_table->show();
   ui->variety_product_table->resizeColumnsToContents();

  ui->comboBox_variety->clear();
  ui->comboBox_variety->addItem("");
  ui->comboBox_variety->addItems(variety);



  //okno oblast
    QSqlQuery *places = new QSqlQuery;
   places->exec("SELECT DISTINCT oblast FROM oblasti");
   QStringList place;
   while(places->next()) // nahrani produktu
   {
       QString SKO = places->value(0).toString();
       place.append(SKO);
   }
   model_variety = new QSqlTableModel(this);
   model_variety ->setQuery("SELECT odruda FROM odrudy");


    ui->place_variety_table->setModel(model_variety);
    ui->place_variety_table->show();
    ui->place_variety_table->resizeColumnsToContents();


    model_product = new QSqlTableModel(this);
    model_product -> setQuery("SELECT produkt FROM produkty");



    ui->place_product_table->setModel(model_product);
    ui->place_product_table->show();
    ui->place_product_table->resizeColumnsToContents();

   ui->comboBox_place->clear();
   ui->comboBox_place->addItem("");
   ui->comboBox_place->addItems(place);

   //okno edit
     QSqlQuery *editproducts = new QSqlQuery;
     editproducts->exec("SELECT DISTINCT zpracovani FROM produkty");

    QStringList editprocess, editroast,editvariet,editplace,editint,editacid,editzeme;
    while(editproducts->next()) // nahrani produktu
    {
        QString SKO = editproducts->value(0).toString();

        editprocess.append(SKO);

    }
       QSqlQuery *editproducts1 = new QSqlQuery;
    editproducts1->exec("SELECT DISTINCT prazeni FROM produkty");
    while(editproducts1->next()) // nahrani produktu
    {  QString SK1 = editproducts1->value(0).toString();
        editroast.append(SK1);}

    QSqlQuery *editproducts2 = new QSqlQuery;
 editproducts2->exec("SELECT DISTINCT odruda FROM odrudy");
 while(editproducts2->next()) // nahrani produktu
 {  QString SK1 = editproducts2->value(0).toString();
     editvariet.append(SK1);}

 QSqlQuery *editproducts3 = new QSqlQuery;
editproducts3->exec("SELECT DISTINCT oblast FROM oblasti");
while(editproducts3->next()) // nahrani produktu
{  QString SK1 = editproducts3->value(0).toString();
  editplace.append(SK1);}

QSqlQuery *editproducts4 = new QSqlQuery;
editproducts4->exec("SELECT DISTINCT zeme FROM zeme");
while(editproducts4->next()) // nahrani produktu
{  QString SK1 = editproducts4->value(0).toString();
 editzeme.append(SK1);}


    ui->comboBox_process->clear();
    ui->comboBox_process->addItem("");
    ui->comboBox_process->addItems(editprocess);

    ui->comboBox_roast->clear();
    ui->comboBox_roast->addItem("");
    ui->comboBox_roast->addItems(editroast);

    ui->comboBox_var->clear();
    ui->comboBox_var->addItem("");
    ui->comboBox_var->addItems(editvariet);

    ui->comboBox_place_2->clear();
    ui->comboBox_place_2->addItem("");
    ui->comboBox_place_2->addItems(editplace);

    ui->comboBox_intenz->clear();
    ui->comboBox_intenz->addItem("");
    ui->comboBox_intenz->addItem("1");
    ui->comboBox_intenz->addItem("2");
    ui->comboBox_intenz->addItem("3");
    ui->comboBox_intenz->addItem("4");
    ui->comboBox_intenz->addItem("5");


    ui->comboBox_acid->clear();
    ui->comboBox_acid->addItem("");
    ui->comboBox_acid->addItem("1");
    ui->comboBox_acid->addItem("2");
    ui->comboBox_acid->addItem("3");
    ui->comboBox_acid->addItem("4");
    ui->comboBox_acid->addItem("5");

    ui->comboBox_clima->clear();
    ui->comboBox_clima->addItem("");
    ui->comboBox_clima->addItem("TROPICKÝ");
    ui->comboBox_clima->addItem("SUBTROPICKÝ");
    ui->comboBox_clima->addItem("MÍRNÝ");
    ui->comboBox_clima->addItem("POLÁRNÍ");

    ui->comboBox_country->clear();
    ui->comboBox_country->addItem("");
    ui->comboBox_country->addItems(editzeme);

    ui->comboBox_odolnost->clear();
    ui->comboBox_odolnost->addItem("");
    ui->comboBox_odolnost->addItem("1");
    ui->comboBox_odolnost->addItem("2");
    ui->comboBox_odolnost->addItem("3");
    ui->comboBox_odolnost->addItem("4");
    ui->comboBox_odolnost->addItem("5");





   //nastaveni

this->setStyleSheet("background-color: ;");
ui->set_normal->setChecked(true);

    setWindowTitle("Káva");
    setWindowIcon(QIcon(":/img/mainIcon"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
//open windows

void MainWindow::on_show_product_clicked()
{if(ui->set_gray->isChecked())
    {
        QString H = ui->lineEdit_pr->text();
        pr = new product_extract(H.toInt());
            QPalette p(palette());
            p.setColor(QPalette::Background, Qt::gray);
            pr->setAutoFillBackground(true);
            pr->setPalette(p);
            pr->show();
}else if(ui->set_normal->isChecked()){


        QString H = ui->lineEdit_pr->text();
        pr = new product_extract(H.toInt());
        pr->show();

    }

else if(ui->set_red->isChecked()){
        QString H = ui->lineEdit_pr->text();
        pr = new product_extract(H.toInt());
        QPalette p(palette());
        p.setColor(QPalette::Background, Qt::red);
        pr->setAutoFillBackground(true);
        pr->setPalette(p);
        pr->show();}
}
void MainWindow::on_show_variety_clicked()
{
    if(ui->set_gray->isChecked())
        {
        QString H = ui->lineEdit_va->text();
                   va = new variety_extract(H.toInt());
                QPalette p(palette());
                p.setColor(QPalette::Background, Qt::gray);
                va->setAutoFillBackground(true);
                va->setPalette(p);
                va->show();
    }else if(ui->set_normal->isChecked()){


        QString H = ui->lineEdit_va->text();
                   va = new variety_extract(H.toInt());
            va->show();}
    else if(ui->set_red->isChecked()){
        QString H = ui->lineEdit_va->text();
                   va = new variety_extract(H.toInt());
            QPalette p(palette());
            p.setColor(QPalette::Background, Qt::red);
            va->setAutoFillBackground(true);
            va->setPalette(p);
            va->show();}
}

void MainWindow::on_show_place_clicked()
{
    if(ui->set_gray->isChecked())
        {
        QString H = ui->lineEdit_pl->text();
               pl = new place_extract(H.toInt());
                QPalette p(palette());
                p.setColor(QPalette::Background, Qt::gray);
                pl->setAutoFillBackground(true);
                pl->setPalette(p);
                pl->show();
    }else if(ui->set_normal->isChecked()){


        QString H = ui->lineEdit_pl->text();
                    pl = new place_extract(H.toInt());
            pl->show();}
    else if(ui->set_red->isChecked()){
        QString H = ui->lineEdit_pl->text();
                    pl = new place_extract(H.toInt());
            QPalette p(palette());
            p.setColor(QPalette::Background, Qt::red);
            pl->setAutoFillBackground(true);
            pl->setPalette(p);
            pl->show();}
}

void MainWindow::on_show_product_2_clicked()//tab place
{
    if(ui->set_gray->isChecked())
        {
        QString H = ui->lineEdit_pr2->text();
        pr = new product_extract(H.toInt());
                QPalette p(palette());
                p.setColor(QPalette::Background, Qt::gray);
                pr->setAutoFillBackground(true);
                pr->setPalette(p);
                pr->show();
    }else if(ui->set_normal->isChecked()){


        QString H = ui->lineEdit_pr2->text();
        pr = new product_extract(H.toInt());
            pr->show();}
    else if(ui->set_red->isChecked()){
        QString H = ui->lineEdit_pr2->text();
        pr = new product_extract(H.toInt());
            QPalette p(palette());
            p.setColor(QPalette::Background, Qt::red);
            pr->setAutoFillBackground(true);
            pr->setPalette(p);
            pr->show();}
}

void MainWindow::on_show_variety_2_clicked()
{
    if(ui->set_gray->isChecked())
        {
        QString H = ui->lineEdit_va2->text();
                   va = new variety_extract(H.toInt());
                QPalette p(palette());
                p.setColor(QPalette::Background, Qt::gray);
                va->setAutoFillBackground(true);
                va->setPalette(p);
                va->show();
    }else if(ui->set_normal->isChecked()){


        QString H = ui->lineEdit_va2->text();
                   va = new variety_extract(H.toInt());

            va->show();}

    else if(ui->set_red->isChecked()){
        QString H = ui->lineEdit_va2->text();
                   va = new variety_extract(H.toInt());

            QPalette p(palette());
            p.setColor(QPalette::Background, Qt::red);
            va->setAutoFillBackground(true);
            va->setPalette(p);
            va->show();}
}

void MainWindow::on_show_place_2_clicked()
{
    if(ui->set_gray->isChecked())
        { QString H = ui->lineEdit_pl2->text();
            pl = new place_extract(H.toInt());
                QPalette p(palette());
                p.setColor(QPalette::Background, Qt::gray);
                pl->setAutoFillBackground(true);
                pl->setPalette(p);
                pl->show();
    }else if(ui->set_normal->isChecked()){

        QString H = ui->lineEdit_pl2->text();
    //    Dialog place_extract(H.toInt()); //(ID.toInt())


           pl = new place_extract(H.toInt());
            pl->show();}
    else if(ui->set_red->isChecked()){
         QString H = ui->lineEdit_pl2->text();
            pl = new place_extract(H.toInt());
            QPalette p(palette());
            p.setColor(QPalette::Background, Qt::red);
            pl->setAutoFillBackground(true);
            pl->setPalette(p);
            pl->show();}
}
void MainWindow::on_show_product_3_clicked()//tab variety
{
    if(ui->set_gray->isChecked())
        {
        QString H = ui->lineEdit_pr3->text();
        pr = new product_extract(H.toInt());
                QPalette p(palette());
                p.setColor(QPalette::Background, Qt::gray);
                pr->setAutoFillBackground(true);
                pr->setPalette(p);
                pr->show();
    }else if(ui->set_normal->isChecked()){


        QString H = ui->lineEdit_pr3->text();
        pr = new product_extract(H.toInt());
            pr->show();}
    else if(ui->set_red->isChecked()){
            QString H = ui->lineEdit_pr3->text();
            pr = new product_extract(H.toInt());
            QPalette p(palette());
            p.setColor(QPalette::Background, Qt::red);
            pr->setAutoFillBackground(true);
            pr->setPalette(p);
            pr->show();}
}

void MainWindow::on_show_variety_3_clicked()
{
    if(ui->set_gray->isChecked())

        {  QString H = ui->lineEdit_va3->text();
            va = new variety_extract(H.toInt());

                QPalette p(palette());
                p.setColor(QPalette::Background, Qt::gray);
                va->setAutoFillBackground(true);
                va->setPalette(p);
                va->show();
    }else if(ui->set_normal->isChecked()){


        QString H = ui->lineEdit_va3->text();
                   va = new variety_extract(H.toInt());

            va->show();}
    else if(ui->set_red->isChecked()){
        QString H = ui->lineEdit_va3->text();
                   va = new variety_extract(H.toInt());

            QPalette p(palette());
            p.setColor(QPalette::Background, Qt::red);
            va->setAutoFillBackground(true);
            va->setPalette(p);
            va->show();}
}

void MainWindow::on_show_place_3_clicked()
{
    if(ui->set_gray->isChecked())
        {
        QString H = ui->lineEdit_pl3->text();
                    pl = new place_extract(H.toInt());
                QPalette p(palette());
                p.setColor(QPalette::Background, Qt::gray);
                pl->setAutoFillBackground(true);
                pl->setPalette(p);
                pl->show();
    }else if(ui->set_normal->isChecked()){


        QString H = ui->lineEdit_pl3->text();
                    pl = new place_extract(H.toInt());
            pl->show();}
    else if(ui->set_red->isChecked()){
        QString H = ui->lineEdit_pl3->text();
                    pl = new place_extract(H.toInt());
            QPalette p(palette());
            p.setColor(QPalette::Background, Qt::red);
            pl->setAutoFillBackground(true);
            pl->setPalette(p);
            pl->show();}
}
void MainWindow::on_open_favorite_3_triggered(){
    if(ui->set_gray->isChecked())
        {
            fav = new Form();
                QPalette p(palette());
                p.setColor(QPalette::Background, Qt::gray);
                fav->setAutoFillBackground(true);
                fav->setPalette(p);
                fav->show();
    }else if(ui->set_normal->isChecked()){


            fav = new Form();
            fav->show();}
    else if(ui->set_red->isChecked()){
            fav = new Form();
            QPalette p(palette());
            p.setColor(QPalette::Background, Qt::red);
            fav->setAutoFillBackground(true);
            fav->setPalette(p);
            fav->show();}
}


   void  MainWindow::on_actionGray_triggered()// nic moc
    {
       this->setStyleSheet("background-color: Gray;");
       ui->set_gray->setChecked(true);
    }

   void  MainWindow::on_actionNormal_triggered()// nic moc
    {
       this->setStyleSheet("background-color: ;");
       ui->set_normal->setChecked(true);
    }

   void  MainWindow::on_actionRed_triggered()// nic moc
    {
       this->setStyleSheet("background-color: Red;");
      ui->set_red->setChecked(true);
    }

   void MainWindow::on_comboBox_place_currentTextChanged(const QString &place)
   {
       QString vyber_od="SELECT DISTINCT odrudy.odruda_id AS ID, odrudy.odruda AS Odrůda FROM produkty JOIN odrudy on odrudy.odruda_id = produkty.odruda_id JOIN oblasti on produkty.oblast_id = oblasti.oblast_id WHERE oblasti.oblast = '"+place+"'";
       QSqlQuery* uni_q = new QSqlQuery;

       uni_q -> prepare(vyber_od);
       uni_q -> exec();


       model_variety->setQuery(*uni_q);

       ui->place_variety_table->setModel(model_variety);
       ui->place_variety_table->show();
       ui->place_variety_table->resizeColumnsToContents();


       QString vyber_pr="SELECT DISTINCT produkty.produkt_id AS ID, produkty.produkt AS Produkt FROM produkty JOIN odrudy on odrudy.odruda_id = produkty.odruda_id JOIN oblasti on produkty.oblast_id = oblasti.oblast_id WHERE oblasti.oblast = '"+place+"'";
       QSqlQuery* uni_p = new QSqlQuery;
       uni_p -> prepare(vyber_pr);
       uni_p-> exec();

       model_product->setQuery(*uni_p);

       ui->place_product_table->setModel(model_product);
       ui->place_product_table->show();
       ui->place_product_table->resizeColumnsToContents();


       QString k = ui->comboBox_place->currentText();

         QString dotaz =   "SELECT produkty.produkt_id, oblasti.oblast_id, odrudy.odruda_id FROM produkty JOIN oblasti ON oblasti.oblast_id = produkty.oblast_id JOIN odrudy ON odrudy.odruda_id = produkty.odruda_id WHERE oblasti.oblast = '"+k+"'";
       QSqlQuery query(dotaz);
       int fieldNo = query.record().indexOf("oblasti.oblast_id");
       while (query.next()) {
           QString prod_id = query.value(fieldNo).toString();

           ui->lineEdit_pl2->setText(prod_id);



   }
   }


   void MainWindow::on_comboBox_product_currentTextChanged(const QString &place){

       QString vyber_pr="SELECT DISTINCT produkty.produkt_id, produkty.produkt as Produkt FROM produkty JOIN odrudy on odrudy.odruda_id = produkty.odruda_id JOIN oblasti on produkty.oblast_id = oblasti.oblast_id WHERE oblasti.oblast = '"+place+"'";
       QSqlQuery* uni_p = new QSqlQuery;
       uni_p -> prepare(vyber_pr);
       uni_p-> exec();

       QString k = ui->comboBox_product->currentText();

         QString dotaz =   "SELECT produkty.produkt_id, oblasti.oblast_id, odrudy.odruda_id FROM produkty JOIN oblasti ON oblasti.oblast_id = produkty.oblast_id JOIN odrudy ON odrudy.odruda_id = produkty.odruda_id WHERE produkt = '"+k+"'";
       QSqlQuery query(dotaz);
       int fieldNo = query.record().indexOf("produkty.produkt_id");
       int fieldNo1 = query.record().indexOf("oblasti.oblast_id");
        int fieldNo2 = query.record().indexOf("odrudy.odruda_id");
       while (query.next()) {
           QString prod_id = query.value(fieldNo).toString();
           QString prod_id1 = query.value(fieldNo1).toString();
           QString prod_id2 = query.value(fieldNo2).toString();
           ui->lineEdit_pr->setText(prod_id);
           ui->lineEdit_pl->setText(prod_id1);
           ui->lineEdit_va->setText(prod_id2);
       }







   }


void MainWindow::on_close_all_3_triggered()
    {
        this->close();
        pl->close();
        pr->close();
        va->close();
        fav->close();
    }

void MainWindow::on_comboBox_variety_currentTextChanged(const QString &variety)
{
    QString vyber_od="SELECT DISTINCT oblasti.oblast_id AS ID, oblasti.oblast as Oblast FROM produkty JOIN odrudy on odrudy.odruda_id = produkty.odruda_id JOIN oblasti on produkty.oblast_id = oblasti.oblast_id WHERE odrudy.odruda = '"+variety+"'";
    QSqlQuery* uni_q = new QSqlQuery;
    uni_q -> prepare(vyber_od);
    uni_q -> exec();

    model_place->setQuery(*uni_q);

    ui->variety_place_table->setModel(model_place);
    ui->variety_place_table->show();
    ui->variety_place_table->resizeColumnsToContents();


    QString vyber_pr="SELECT DISTINCT produkty.produkt_id AS ID, produkty.produkt AS Produkt FROM produkty JOIN odrudy on odrudy.odruda_id = produkty.odruda_id JOIN oblasti on produkty.oblast_id = oblasti.oblast_id WHERE odrudy.odruda = '"+variety+"'";
    QSqlQuery* uni_p = new QSqlQuery;
    uni_p -> prepare(vyber_pr);
    uni_p-> exec();

    model_product2->setQuery(*uni_p);

    ui->variety_product_table->setModel(model_product2);
    ui->variety_product_table->show();
    ui->variety_product_table->resizeColumnsToContents();

    QString k = ui->comboBox_variety->currentText();

      QString dotaz =   "SELECT produkty.produkt_id, oblasti.oblast_id, odrudy.odruda_id FROM produkty JOIN oblasti ON oblasti.oblast_id = produkty.oblast_id JOIN odrudy ON odrudy.odruda_id = produkty.odruda_id WHERE odrudy.odruda = '"+k+"'";
    QSqlQuery query(dotaz);
    int fieldNo = query.record().indexOf("odrudy.odruda_id");
    while (query.next()) {
        QString prod_id = query.value(fieldNo).toString();

        ui->lineEdit_va3->setText(prod_id);
    }


}

void MainWindow::on_make_favorite_clicked()//tab variety
{
favorite = ui->comboBox_product->currentText();
QSqlQuery *query = new QSqlQuery();
QString sel = "SELECT produkt FROM produkty WHERE produkt = '"+favorite+"'";
query->prepare(sel);
query->exec();
query->first();
QString seli = query->value(0).toString();
QString insert = "INSERT INTO oblibene (produkt_oblibene) VALUES ('"+seli+"')";
query->clear();
query->prepare(insert);
if(!query->exec())
    qDebug() << "ERROR" << query->lastError();
else
    qDebug() << "Success";
}



void MainWindow::on_pridatpr_clicked()//tab variety
{
produkt = ui->lineEdit_produkt->text();
pr_id = ui->lineEdit_produkt_id->text();
process = ui->comboBox_process->currentText();
acid = ui->comboBox_acid->currentText();
intenz = ui->comboBox_intenz->currentText();
roast = ui->comboBox_roast->currentText();
variet = ui->comboBox_var->currentText();
plac_e = ui->comboBox_place_2->currentText();
chut = ui->lineEdit_chut_2->text();
QSqlQuery *query = new QSqlQuery();
QSqlQuery *query1 = new QSqlQuery();
QSqlQuery *query2 = new QSqlQuery();

QString obid = "SELECT oblast_id FROM oblasti WHERE oblast = '"+plac_e+"'";
query1->prepare(obid);
query1->exec();
query1->first();
QString obidi = query1->value(0).toString();


QString odid = "SELECT odruda_id FROM odrudy WHERE odruda = '"+variet+"'";
query2->prepare(odid);
query2->exec();
query2->first();
QString odidi = query2->value(0).toString();

QString insert = "INSERT INTO produkty (produkt,produkt_id,zpracovani,kyselost,intenzita,prazeni,odruda,oblast,chut,oblast_id,odruda_id) VALUES ('"+produkt+"','"+pr_id+"','"+process+"','"+acid+"','"+intenz+"','"+roast+"','"+variet+"','"+plac_e+"','"+chut+"','"+obidi+"','"+odidi+"')";
query->clear();
query->prepare(insert);
if(!query->exec())
    qDebug() << "ERROR" << query->lastError();
else
    qDebug() << "Success";

ui->lineEdit_produkt->clear();
ui->lineEdit_produkt_id->clear();
ui->comboBox_process->clear();
ui->comboBox_acid->clear();
ui->comboBox_intenz->clear();
ui->comboBox_roast->clear();
ui->comboBox_var->clear();
ui->comboBox_place_2->clear();
ui->lineEdit_chut_2->clear();


}


void MainWindow::on_add_place_clicked()//tab variety
{
pla_ce = ui->lineEdit_oblast->text();
vyskaod = ui->lineEdit_vyskaod->text();
vyskado = ui->lineEdit_vyskado->text();
klimpas = ui->comboBox_clima->currentText();
zeme = ui->comboBox_country->currentText();
oblastid = ui->lineEdit_oblast_id->text();

QSqlQuery *query = new QSqlQuery();
QSqlQuery *query1 = new QSqlQuery();


QString obid = "SELECT zeme_id FROM oblasti WHERE zeme_oblasti = '"+zeme+"'";
query1->prepare(obid);
query1->exec();
query1->first();
QString obidi = query1->value(0).toString();

QString insert = "INSERT INTO oblasti (oblast,vyska_od,vyska_do,klim_pas,zeme_oblasti,oblast_id,zeme_id) VALUES ('"+pla_ce+"','"+vyskaod+"','"+vyskado+"','"+klimpas+"','"+zeme+"','"+oblastid+"','"+obidi+"')";
query->clear();
query->prepare(insert);
if(!query->exec())
    qDebug() << "ERROR" << query->lastError();
else
    qDebug() << "Success";


ui->lineEdit_oblast->clear();
ui->lineEdit_vyskaod->clear();
ui->lineEdit_vyskado->clear();
ui->comboBox_clima->clear();
ui->comboBox_country->clear();
ui->lineEdit_oblast_id->clear();

}
void MainWindow::on_add_variety_clicked()//tab variety
{
odruda = ui->lineEdit_odruda->text();
chuto = ui->lineEdit_chut->text();
popis = ui->lineEdit_popis->text();
odolnost = ui->comboBox_odolnost->currentText();
vznik = ui->lineEdit_region->text();
region = ui->lineEdit_region->text();
odrudaid = ui->lineEdit_odruda_id->text();

QSqlQuery *query = new QSqlQuery();


QString insert = "INSERT INTO odrudy (odruda,popis,odolnost,chut_odrudy,vznik,region,odruda_id) VALUES ('"+odruda+"','"+popis+"','"+odolnost+"','"+chuto+"','"+vznik+"','"+region+"','"+odrudaid+"')";
query->clear();
query->prepare(insert);
if(!query->exec())
    qDebug() << "ERROR" << query->lastError();
else
    qDebug() << "Success";


ui->lineEdit_odruda->clear();
ui->lineEdit_chut->clear();
ui->lineEdit_popis->clear();
ui->comboBox_odolnost->clear();
ui->lineEdit_region->clear();
ui->lineEdit_region->clear();
ui->lineEdit_odruda_id->clear();
ui->lineEdit_vznik->clear();

}
 void MainWindow::on_variety_place_table_activated(const QModelIndex &index)
 {QString EDIT = "SELECT produkt FROM produkty WHERE produkt = 'SUMATRA LINTONG'";
     QSqlQuery *query = new QSqlQuery();
         query -> prepare(EDIT);
         query -> exec();

         ui->variety_place_table->setModel(model_place);
         QString naze = ui->variety_place_table->model()->index(index.row(),0).data().toString();
         ui->lineEdit_pr3->setText(naze);
 }


//end of windows
//end of project

