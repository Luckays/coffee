#ifndef VARIETY_EXTRACT_H
#define VARIETY_EXTRACT_H
#include <QIcon>
#include <QDialog>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlTableModel>

namespace Ui {
class variety_extract;
}

class variety_extract : public QDialog
{
    Q_OBJECT

public:
    explicit variety_extract(int h,QWidget *parent = nullptr);
    ~variety_extract();

private:
    Ui::variety_extract *ui;
        int hh;
private slots:
    void on_close_clicked();
};

#endif // VARIETY_EXTRACT_H
