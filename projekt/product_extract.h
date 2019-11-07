#ifndef PRODUCT_EXTRACT_H
#define PRODUCT_EXTRACT_H
#include <QIcon>
#include <QDialog>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlTableModel>

namespace Ui {
class product_extract;
}


class product_extract : public QDialog
{
    Q_OBJECT

public:
    explicit product_extract(int h,QWidget *parent = nullptr);
    ~product_extract();

private:
    Ui::product_extract *ui;
    int hh;

private slots:
    void on_close_clicked();
};

#endif // PRODUCT_EXTRACT_H
