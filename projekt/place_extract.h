#ifndef PLACE_EXTRACT_H
#define PLACE_EXTRACT_H
#include <QIcon>
#include <QDialog>

namespace Ui {
class place_extract;
}

class place_extract : public QWidget
{
    Q_OBJECT

public:
    explicit place_extract(QWidget *parent = nullptr);
    ~place_extract();

private:
    Ui::place_extract *ui;
private slots:
    void on_close_clicked();
};

#endif // PLACE_EXTRACT_H
