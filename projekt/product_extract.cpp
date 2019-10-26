#include "product_extract.h"
#include "ui_product_extract.h"

product_extract::product_extract(QWidget *parent)
    : QWidget(parent),
   ui(new Ui::product_extract)
{
    ui->setupUi(this);
    setWindowTitle("Výpis produktu");
    setWindowIcon(QIcon(":/img/mainIcon"));
}

product_extract::~product_extract()
{
    delete ui;
}

void product_extract::on_close_clicked()
    {
        this->close();
    }
