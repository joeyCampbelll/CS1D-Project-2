#ifndef TABLEFILTERS_H
#define TABLEFILTERS_H

#include <QWidget>
#include <QTableView>
#include "database.h"


namespace Ui {
class tablefilter;
}

class tablefilter : public QWidget
{
    Q_OBJECT

public:
    explicit tablefilter(QWidget *parent = nullptr);
    ~tablefilter();

    void setTableView(QTableView *newTableView);

private slots:
    void on_pushButton_clicked();

private:
    QTableView* tableView;
    Ui::tablefilter *ui;
};

#endif // TABLEFILTERS_H
