#ifndef BONUSWINDOW_H
#define BONUSWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class bonuswindow;
}

class bonuswindow : public QWidget
{
    Q_OBJECT

public:
    explicit bonuswindow(QWidget *parent = nullptr);
    ~bonuswindow();

signals:
    void firstWindow();

private slots:
    void on_pushButton1_clicked();
    void call();

private:
    Ui::bonuswindow *ui;

private:
    QPushButton *btn;
};

#endif // BONUSWINDOW_H
