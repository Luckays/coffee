#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "product_extract.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
, ui(new Ui::MainWindow)
{


    ui->setupUi(this);


    setWindowTitle("Káva");
    setWindowIcon(QIcon(":/img/mainIcon"));

}

MainWindow::~MainWindow()
{
    delete ui;
}
//open windows
void MainWindow::on_show_product_clicked()//tab product
{
   pr = new product_extract();
   pr->show();
}

void MainWindow::on_show_variety_clicked()
{
   va = new variety_extract();
   va->show();
}

void MainWindow::on_show_place_clicked()
{
   pl = new place_extract();
   pl->show();
}

void MainWindow::on_show_product_2_clicked()//tab place
{
   pr = new product_extract();
   pr->show();
}

void MainWindow::on_show_variety_2_clicked()
{
   va = new variety_extract();
   va->show();
}

void MainWindow::on_show_place_2_clicked()
{
   pl = new place_extract();
   pl->show();
}
void MainWindow::on_show_product_3_clicked()//tab variety
{
   pr = new product_extract();
   pr->show();
}

void MainWindow::on_show_variety_3_clicked()
{
   va = new variety_extract();
   va->show();
}

void MainWindow::on_show_place_3_clicked()
{
   pl = new place_extract();
   QPalette p(palette());
   p.setColor(QPalette::Background, Qt::red);
   pl->setAutoFillBackground(true);
   pl->setPalette(p);
   pl->show();
}
void MainWindow::on_open_favorite_triggered(){
    fav = new Form();
    fav->show();
}
void MainWindow::on_active_depression_triggered(){
    pl = new place_extract();
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::red);
    pl->setAutoFillBackground(true);
    pl->setPalette(p);
    pl->show();
}
void MainWindow::on_close_all_triggered()
    {
        this->close();
        pl->close();
        pr->close();
        va->close();
        fav->close();
    }


//end of windows
//end of project
