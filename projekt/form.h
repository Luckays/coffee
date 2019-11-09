#ifndef FORM_H
#define FORM_H
#include <QIcon>
#include <QWidget>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlTableModel>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private:
    Ui::Form *ui;
    QSqlQueryModel *model_fav;
private slots:
    void on_close_clicked();
};

#endif // FORM_H
