#include "mainwindow.h"
#include "ui_mainwindow.h"

const QSize MainWindow::SIZE(QSize(500, 500));

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_image(0, 0, QImage::Format_RGB32)
{
    ui->setupUi(this);

    // attach signals to slots
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::onOpenImage);
    connect(ui->actionClose, &QAction::triggered, this, &MainWindow::onCloseImage);
    connect(ui->actionQuit, &QAction::triggered, this, &QApplication::quit);
    connect(ui->actionRotate, &QAction::triggered, this, &MainWindow::onRotateImage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onOpenImage() {
    // open image dialog
    QString path = QFileDialog::getOpenFileName(this, "Open image", ".", "*.jpg");

    // open & display image in label
    if (!path.isEmpty()) {
        qDebug() << "Opening file: " << qPrintable(path);
        m_image.load(path);
        m_image  = m_image.scaled(MainWindow::SIZE, Qt::KeepAspectRatio);
        ui->labelImage->setPixmap(QPixmap::fromImage(m_image));
    }
}

void MainWindow::onCloseImage() {
    // clear image
    m_image = QImage(0, 0, QImage::Format_RGB32);
    ui->labelImage->setPixmap(QPixmap::fromImage(m_image));
}

void MainWindow::onRotateImage() {
    if (!m_image.isNull()) {
        // rotate image using transformation matrix
        QTransform transform;
        transform.rotate(90);
        m_image = m_image.transformed(transform);
        ui->labelImage->setPixmap(QPixmap::fromImage(m_image));
    } else {
        qDebug() << "Image is empty!";
    }
}
