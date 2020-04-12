#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    static const QSize SIZE;
    QImage m_image;

private slots:
    void onOpenImage();
    void onCloseImage();
    void onRotateImage();
};

#endif // MAINWINDOW_H
