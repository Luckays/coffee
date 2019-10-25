#ifndef PRODUCT_EXTRACT_H
#define PRODUCT_EXTRACT_H
#include <QIcon>
#include <QWidget>

namespace Ui {
class product_extract;
}


class product_extract : public QWidget
{
    Q_OBJECT

public:
    explicit product_extract(QWidget *parent = nullptr);
    ~product_extract();

private:
    Ui::product_extract *ui;
};

#endif // PRODUCT_EXTRACT_H
