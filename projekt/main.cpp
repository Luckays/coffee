#include "mainwindow.h"
#include <QApplication>
#include "product_extract.h"
#include "form.h"
#include "variety_extract.h"
#include "place_extract.h"
int main(int argc, char *argv[])
{// open main window
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
