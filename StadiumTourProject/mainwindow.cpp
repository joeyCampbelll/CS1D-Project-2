#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Check if database is open
    if(!myDb.isOpen())
    {
        ui->dbStatus_label->setText("Failed to open database!");
    }
    else
    {
        ui->dbStatus_label->setText("Connected...");
        showMLB();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMLB()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    QSqlQuery* qry=new QSqlQuery();

    qry->prepare("SELECT * FROM MLB_Information");

    if(qry->exec())
    {
        qDebug() << "MLB Info updated and displayed to table";
    }
    else
    {
        qDebug() << "MLB info failed to display";
    }

    model->setQuery(*qry);

    ui->mlb_tableView->setModel(model);
    ui->mlb_tableView->resizeColumnsToContents();
}


void MainWindow::on_actionLogin_2_triggered()
{
    auto* login = new Login(this);
    login->show();
}
