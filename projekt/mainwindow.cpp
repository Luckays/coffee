#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QColorDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
, ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
void MainWindow::on_open_favorite_triggered(){
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



   }





void MainWindow::on_close_all_triggered()
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



}

void MainWindow::on_make_favorite_clicked()//tab variety
{

}
 /*void MainWindow::on_place_variety_table_activated(const QModelIndex &index)
 {
     QString vybrane = ui->place_variety_table->model()->data(index).toString();
QString podminka = "odruda = '"+vybrane+"'";
     QString productvyber = "SELECT DISTINCT produkty.produkt AS Produkt FROM produkty";

     QSqlQuery *queryy = new QSqlQuery();
    // queryy -> clear();
     queryy -> prepare(productvyber);
     queryy -> exec();
     model_variety -> setQuery(*queryy);
     ui->place_variety_table->setModel(model_variety);
     ui->variety_product_table->show();
     ui->variety_product_table->resizeColumnsToContents();

 }*/


//end of windows
//end of project

