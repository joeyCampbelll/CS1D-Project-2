#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QWidget>

namespace Ui {
class tableview;
}

class tableview : public QWidget
{
    Q_OBJECT

public:
    explicit tableview(QWidget *parent = nullptr);
    ~tableview();

private:
    Ui::tableview *ui;
};

#endif // TABLEVIEW_H
