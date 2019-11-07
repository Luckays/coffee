#include "place_extract.h"
#include "ui_place_extract.h"

place_extract::place_extract(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::place_extract)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: ;");
    setWindowTitle("Výpis Odrůdy");
    setWindowIcon(QIcon(":/img/mainIcon"));

}

place_extract::~place_extract()
{
    delete ui;
}
void place_extract::on_close_clicked()
    {
        this->close();
    }
