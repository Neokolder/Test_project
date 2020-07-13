#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <bonuswindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bonuswindow *bonus;

private slots:
    void on_pushButton_clicked();
    void call();
    void open();
    void favor();
    void chanking();
    void sort();

private:
 QPushButton *btn;
};
#endif // MAINWINDOW_H
