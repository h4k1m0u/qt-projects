#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_manager(new QNetworkAccessManager(this)),
    m_temperature(0)
{
    ui->setupUi(this);

    // connect slots to signals
    connect(ui->downloadButton, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(m_manager, &QNetworkAccessManager::finished, this, &MainWindow::onReplyFinished);
}

MainWindow::~MainWindow()
{
    delete m_manager;
    delete ui;
}

void MainWindow::onButtonClicked() {
    // send http request
    m_manager->get(QNetworkRequest(QUrl("http://api.openweathermap.org/data/2.5/weather?q=Caen&units=metric&appid=2019157159897d013b06bd8f304a76af")));
}

void MainWindow::onReplyFinished(QNetworkReply *reply) {
    // fetch http reponse
    qDebug() << "Fetching data from openweathermap.org...";
    QByteArray response = reply->readAll();

    // parse json response
    QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
    QJsonObject jsonObject = jsonResponse.object();
    m_temperature = jsonObject["main"].toObject()["temp"].toDouble();

    // show temperature
    ui->temperatureLabel->setText("Temperature: " + QString::number(m_temperature));
}
