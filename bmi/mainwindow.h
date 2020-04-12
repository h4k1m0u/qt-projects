#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    // macro needed in classes that use signals/slots
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // weight, height, and bmi
    float m_weight;
    float m_height;
    float m_bmi;

// custom event listener
private slots:
    void onButtonClicked();
};

#endif // MAINWINDOW_H
