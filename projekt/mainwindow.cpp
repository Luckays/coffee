#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QColorDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
, ui(new Ui::MainWindow)
{


    ui->setupUi(this);
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
        pr = new product_extract();
            QPalette p(palette());
            p.setColor(QPalette::Background, Qt::gray);
            pr->setAutoFillBackground(true);
            pr->setPalette(p);
            pr->show();
}else if(ui->set_normal->isChecked()){


        pr = new product_extract();
        pr->show();}
else if(ui->set_red->isChecked()){
        pr = new product_extract();
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
            va = new variety_extract();
                QPalette p(palette());
                p.setColor(QPalette::Background, Qt::gray);
                va->setAutoFillBackground(true);
                va->setPalette(p);
                va->show();
    }else if(ui->set_normal->isChecked()){


            va = new variety_extract();
            pr->show();}
    else if(ui->set_red->isChecked()){
            va = new variety_extract();
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
            pl = new place_extract();
                QPalette p(palette());
                p.setColor(QPalette::Background, Qt::gray);
                pl->setAutoFillBackground(true);
                pl->setPalette(p);
                pl->show();
    }else if(ui->set_normal->isChecked()){


            pl = new place_extract();
            pl->show();}
    else if(ui->set_red->isChecked()){
            pl = new place_extract();
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
            pr = new product_extract();
                QPalette p(palette());
                p.setColor(QPalette::Background, Qt::gray);
                pr->setAutoFillBackground(true);
                pr->setPalette(p);
                pr->show();
    }else if(ui->set_normal->isChecked()){


            pr = new product_extract();
            pr->show();}
    else if(ui->set_red->isChecked()){
            pr = new product_extract();
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
            va = new variety_extract();
                QPalette p(palette());
                p.setColor(QPalette::Background, Qt::gray);
                va->setAutoFillBackground(true);
                va->setPalette(p);
                va->show();
    }else if(ui->set_normal->isChecked()){


            va = new variety_extract();
            pr->show();}
    else if(ui->set_red->isChecked()){
            va = new variety_extract();
            QPalette p(palette());
            p.setColor(QPalette::Background, Qt::red);
            va->setAutoFillBackground(true);
            va->setPalette(p);
            va->show();}
}

void MainWindow::on_show_place_2_clicked()
{
    if(ui->set_gray->isChecked())
        {
            pl = new place_extract();
                QPalette p(palette());
                p.setColor(QPalette::Background, Qt::gray);
                pl->setAutoFillBackground(true);
                pl->setPalette(p);
                pl->show();
    }else if(ui->set_normal->isChecked()){


            pl = new place_extract();
            pl->show();}
    else if(ui->set_red->isChecked()){
            pl = new place_extract();
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
            pr = new product_extract();
                QPalette p(palette());
                p.setColor(QPalette::Background, Qt::gray);
                pr->setAutoFillBackground(true);
                pr->setPalette(p);
                pr->show();
    }else if(ui->set_normal->isChecked()){


            pr = new product_extract();
            pr->show();}
    else if(ui->set_red->isChecked()){
            pr = new product_extract();
            QPalette p(palette());
            p.setColor(QPalette::Background, Qt::red);
            pr->setAutoFillBackground(true);
            pr->setPalette(p);
            pr->show();}
}

void MainWindow::on_show_variety_3_clicked()
{
    if(ui->set_gray->isChecked())
        {
            va = new variety_extract();
                QPalette p(palette());
                p.setColor(QPalette::Background, Qt::gray);
                va->setAutoFillBackground(true);
                va->setPalette(p);
                va->show();
    }else if(ui->set_normal->isChecked()){


            va = new variety_extract();
            pr->show();}
    else if(ui->set_red->isChecked()){
            va = new variety_extract();
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
            pl = new place_extract();
                QPalette p(palette());
                p.setColor(QPalette::Background, Qt::gray);
                pl->setAutoFillBackground(true);
                pl->setPalette(p);
                pl->show();
    }else if(ui->set_normal->isChecked()){


            pl = new place_extract();
            pl->show();}
    else if(ui->set_red->isChecked()){
            pl = new place_extract();
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

