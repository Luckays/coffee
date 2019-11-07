#ifndef VARIETY_EXTRACT_H
#define VARIETY_EXTRACT_H
#include <QIcon>
#include <QDialog>

namespace Ui {
class variety_extract;
}

class variety_extract : public QWidget
{
    Q_OBJECT

public:
    explicit variety_extract(QWidget *parent = nullptr);
    ~variety_extract();

private:
    Ui::variety_extract *ui;
private slots:
    void on_close_clicked();
};

#endif // VARIETY_EXTRACT_H
