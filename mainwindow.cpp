#include <QDebug>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("L:/Projects/Qt_test/Qt_db.db");
    db.setUserName("root");

    if (!db.open()) {
        qDebug() << db.lastError().text();
        return;
    } else {
        qDebug() << "Success";
    }
    connect(ui->pushButton, SIGNAL(clicked()),
            this, SLOT(getDataFromLinedit()));
    ui->pushButton->setEnabled(false);
}
MainWindow::~MainWindow() {
    delete ui;
}
void MainWindow::on_pushButton_3_clicked() {
    model = new QSqlTableModel(this, db);
    model->setTable("First_table");
    model->select();
    ui->tableView->setModel(model);
}


void MainWindow::on_pushButton_2_clicked() {
    model = new QSqlTableModel(this, db);
    model->setTable("Second_table");
    model->select();
    ui->tableView->setModel(model);
}

void MainWindow::on_pushButton_4_clicked() {
    model = new QSqlTableModel(this, db);
    model -> setTable("");
    model->select();
    ui->tableView->setModel(model);
}

void MainWindow::on_pushButton_clicked() {
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1) {
    if (!arg1.isEmpty() && (arg1.at(0) == '1' || arg1.at(0) == '2')) {
        ui->pushButton->setEnabled(true);
    } else {
        ui->pushButton->setEnabled(false);
    }
}

void MainWindow::getDataFromLinedit() {
    QSqlQuery query;
    if (ui->lineEdit->text().at(0) == '1') {
    query.prepare("Insert into First_table(data) values (?) ");
    } else if (ui->lineEdit->text().at(0) == '2') {
    query.prepare("Insert into Second_table(data) values (?) ");
    }
    query.addBindValue(ui->lineEdit->text());
    query.exec();
    if (ui->lineEdit->text().at(0) == '1') {
        MainWindow::on_pushButton_3_clicked();
    } else if (ui->lineEdit->text().at(0) == '2') {
        MainWindow::on_pushButton_2_clicked();
    }
}




