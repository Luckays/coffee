#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{//open favorite, set colour, title and icon
    ui->setupUi(this);
    this->setStyleSheet("background-color: ;");
    setWindowTitle("Oblíbené");
    setWindowIcon(QIcon(":/img/Favorite"));


//set tableview and fill it with sql select
    model_fav = new QSqlTableModel(this);
    model_fav ->setQuery("SELECT produkt_oblibene AS Oblíbené FROM oblibene");

     ui->tableView->setModel(model_fav);
     ui->tableView->show();
     ui->tableView->resizeColumnsToContents();
// react to changes in tableView
     connect(ui->tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
             this, SLOT(rowChanged(QModelIndex, QModelIndex)));

}
// funkcion, when you choose row in tableView - set in lineEdit selected row, prepare to delete row.
void Form::rowChanged(QModelIndex index, QModelIndex)
{

        ui->tableView->setModel(model_fav);
        QString naze = ui->tableView->model()->index(index.row(),0).data().toString();
        ui->lineEdit->setText(naze);
}
//funkcion, delete from TABLE selected row.
void Form::on_delete_2_clicked()
{
QString smazat;
    smazat = ui->lineEdit->text();
    QSqlQuery *query = new QSqlQuery();
    QString smaz = "DELETE FROM oblibene WHERE produkt_oblibene = '" +smazat+ "'";
    query->clear();
    query->prepare(smaz);
    if(!query->exec())
        qDebug() << "ERROR" << query->lastError();
    else
        qDebug() << "Success";
    QMessageBox::information(0,"Odebráno","Produkt byl odebrán.");

    model_fav = new QSqlTableModel(this);
    model_fav ->setQuery("SELECT produkt_oblibene AS Oblíbené FROM oblibene");


     ui->tableView->setModel(model_fav);
     ui->tableView->show();
     ui->tableView->resizeColumnsToContents();
     connect(ui->tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
             this, SLOT(rowChanged(QModelIndex, QModelIndex)));
}



Form::~Form()
{
    delete ui;
}
//button close
void Form::on_close_clicked()
    {
        this->close();
    }
