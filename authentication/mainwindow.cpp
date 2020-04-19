#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // connect to sqlite database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/hakim/repos/qt-projects/authentication/database.db");

    if (!db.open())
        qDebug() << "Unable to connect to database";
    else
        qDebug() << "Connected to database";

    // attach signals to slots
    connect(ui->connectButton, &QPushButton::clicked, this, &MainWindow::onConnect);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onConnect() {
    // get submitted credentials
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();

    // run query with submitted credentials
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query;
    query.prepare("SELECT * FROM members WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.exec();

    // query.size() unsupported by sqlite
    if (!query.last())
        QMessageBox::critical(this, "Wrong credentials", "Wrong credentials");
    else
        QMessageBox::information(this, "You're authenticated", "You're authenticated");
}
