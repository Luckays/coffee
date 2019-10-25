#include "product_extract.h"
#include "form.h"
#include "variety_extract.h"
#include "place_extract.h"
#include <QIcon>
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

private slots:
    void on_show_product_clicked();
    void on_show_variety_clicked();
    void on_show_place_clicked();
    void on_show_product_2_clicked();
    void on_show_variety_2_clicked();
    void on_show_place_2_clicked();
    void on_show_product_3_clicked();
    void on_show_variety_3_clicked();
    void on_show_place_3_clicked();
    void on_open_favorite_triggered();
    void on_close_all_triggered();

};

#endif // MAINWINDOW_H
