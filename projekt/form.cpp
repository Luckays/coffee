#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: ;");
    setWindowTitle("Oblíbené");
    setWindowIcon(QIcon(":/img/Favorite"));



    model_fav = new QSqlTableModel(this);
    model_fav ->setQuery("SELECT produkt_oblibene FROM oblibene");


     ui->tableView->setModel(model_fav);
     ui->tableView->show();
     ui->tableView->resizeColumnsToContents();
}




Form::~Form()
{
    delete ui;
}
void Form::on_close_clicked()
    {
        this->close();
    }
