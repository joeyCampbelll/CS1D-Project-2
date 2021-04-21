#include "tableview.h"
#include "ui_tableview.h"

tableview::tableview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tableview)
{
    ui->setupUi(this);
}

tableview::~tableview()
{
    delete ui;
}
