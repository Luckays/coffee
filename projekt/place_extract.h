#ifndef PLACE_EXTRACT_H
#define PLACE_EXTRACT_H
#include <QIcon>
#include <QDialog>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlTableModel>

namespace Ui {
class place_extract;
}

class place_extract : public QDialog
{
    Q_OBJECT

public:
    explicit place_extract(int h,QWidget *parent = nullptr);
    ~place_extract();

private:
    Ui::place_extract *ui;
    int hh;
private slots:
    void on_close_clicked();
};

#endif // PLACE_EXTRACT_H
