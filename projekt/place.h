#ifndef PLACEH
#define PLACE_H
#include <QIcon>
#include <QWidget>

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
