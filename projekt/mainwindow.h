#include "product_extract.h"
#include "form.h"
#include "variety_extract.h"
#include "place_extract.h"
#include "dialog.h"
#include <QIcon>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlTableModel>

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    product_extract *pr;
    variety_extract *va;
    place_extract *pl;
    Form *fav;
   QSqlQueryModel * model_variety;
    QSqlQueryModel * model_product;
      QSqlQueryModel * model_product2;
    QSqlQueryModel *model_place ;
QString favorite,produkt,process,chut,intenz,acid,roast,variet,plac_e,pr_id,pl_id,va_id;

QString pla_ce, vyskaod,vyskado,klimpas,zeme,oblastid,zemeid;

QString odruda,popis,odolnost,chuto,vznik,region,odrudaid;

private slots:
    void on_show_product_clicked();
    void on_show_variety_clicked();
    void on_show_place_clicked();
    void on_make_favorite_clicked();
    void on_show_product_2_clicked();
    void on_show_variety_2_clicked();
    void on_show_place_2_clicked();
    void on_show_product_3_clicked();
    void on_show_variety_3_clicked();
    void on_show_place_3_clicked();
    void on_open_favorite_3_triggered();
    void on_close_all_3_triggered();
    void on_actionGray_triggered();
    void on_actionNormal_triggered();
    void on_actionRed_triggered();
    void on_comboBox_place_currentTextChanged(const QString &place);
    void on_comboBox_variety_currentTextChanged(const QString &variety);
    void on_comboBox_product_currentTextChanged(const QString &place);
    void rowChanged_var_pl(QModelIndex index, QModelIndex);
    void rowChanged_pl_var(QModelIndex index, QModelIndex);
    void rowChanged_pl_pr(QModelIndex index, QModelIndex);
    void rowChanged_var_pr(QModelIndex index, QModelIndex);
    void on_pridatpr_clicked();
    void on_add_place_clicked();
    void on_add_variety_clicked();
};

#endif // MAINWINDOW_H
