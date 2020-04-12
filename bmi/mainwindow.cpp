#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), // call parent constructor
    ui(new Ui::MainWindow),
    m_weight(0.0f),
    m_height(0.0f),
    m_bmi(0.0f)
{
    ui->setupUi(this);

    // connect signals to slots
    connect(ui->calculateButton, SIGNAL(clicked(bool)), this, SLOT(onButtonClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonClicked() {
    // get weight & height from inputs
    QString weight = ui->weightLineEdit->text();
    QString height = ui->heightLineEdit->text();

    // calculate bmi
    m_weight = weight.toFloat();
    m_height = height.toFloat();
    m_bmi = m_weight / (m_height * m_height);

    // show bmi
    ui->bmiLabel->setText("BMI: " + QString::number(m_bmi));
}
