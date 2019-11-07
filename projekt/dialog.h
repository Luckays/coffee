#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlTableModel>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(int h,QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    int hh;
     QSqlQueryModel *model_product3;
};

#endif // DIALOG_H
