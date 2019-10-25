#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    setWindowTitle("Oblíbené");
    setWindowIcon(QIcon(":/img/Favorite"));
}

Form::~Form()
{
    delete ui;
}
void Form::on_close_clicked()
    {
        this->close();
    }
