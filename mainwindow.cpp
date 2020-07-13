#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListView>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <list>
#include <QListWidget>
#include <QVector>
#include <QTextStream>
#include <QString>
#include <QTableWidget>
#include <QLabel>
#include <QPalette>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPixmap>
#include <QPicture>
#include <QCheckBox>
#include <QLineEdit>

class  ContactListProvider
{
public:
    QString contactName;
    QString contactPhoneNumber;

    void call(){
        QMessageBox msgBox;
        msgBox.setText("Calling");
        msgBox.exec();
    }
};

int check = 0;
QVector<ContactListProvider> contacts;
QVector<int> checked;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QVector<ContactListProvider> contactList;
    QVector<QPushButton*> buttons;
    contactList.append({"Harry Potter", "123456789"});
    contactList.append({"Hermione Granger", "123456789"});
    contactList.append({"Ron Weasley", "123456789"});
    contactList.append({"Albus Dumbledore", "123456789"});
    contactList.append({"Sirius Black", "123456789"});
    contactList.append({"Rubeus Hagrid", "123456789"});
    contactList.append({"Lord Voldemort", "123456789"});
    contactList.append({"Bellatrix Lestrange", "123456789"});
    contactList.append({"Luna Lovegood", "123456789"});
    setFixedSize(500,60+55*contactList.size());
    QString pictString = "C:/Users/neoko/Documents/wand.png";
    QPixmap picture(pictString);
    ui->setupUi(this);
    for (int i = 0; i < contactList.size(); i++)
    {
        buttons.push_back(new QPushButton(contactList[i].contactName, this));
        buttons[i]->setGeometry(5, 60+55*i, MainWindow::width()-10, 50);
        buttons[i]->setFont(QFont("Times New Roman", 15));
        buttons[i]->setStyleSheet("background-color: darkCyan; border-radius: 10px;");
        buttons[i]->setText(contactList[i].contactName);
        connect(buttons[i], SIGNAL (released()), this, SLOT (call()));
        QString pictString = "C:/Users/neoko/Documents/%1.png";
        QPixmap picture(pictString.arg(i));
        QLabel *pictLabel = new QLabel(this);
        pictLabel->setPixmap(picture);
        pictLabel->setScaledContents(true);
        pictLabel->setGeometry(10, 60+55*i, 50, 50);
        QString checkString = "%1";
        QCheckBox *check = new QCheckBox(checkString.arg(i), this);
        check->setGeometry(MainWindow::width()-30, 75+55*i, 20, 20);
        checked. append(0);
    }
    QPushButton *favorites = new QPushButton("Favor", this);
    favorites->setGeometry(100, 5, 50, 50);
    connect(favorites, SIGNAL (released()), this, SLOT(favor()));
    QPushButton *chunk = new QPushButton("Chunk", this);
    connect(chunk, SIGNAL (released()), this, SLOT(chanking()));
    chunk->setGeometry(155, 5, 50, 50);
    QPushButton *sorte = new QPushButton("Sprt", this);
    sorte->setGeometry(210, 5, 50, 50);
    sorte->setCheckable(true);
    connect(sorte, SIGNAL (released()), this, SLOT(sort()));
    ui->pushButton->setGeometry(45, 5, 50, 50);
    ui->pushButton->setText("Style");
    bonus = new bonuswindow();
    connect(bonus, &bonuswindow::firstWindow, this, &MainWindow::show);
    if (sorte->isChecked()){
        MainWindow::sort();
    }

}

void MainWindow::on_pushButton_clicked()
{
    bonus->show();
    this->close();
}

void MainWindow::sort(){
    QVector<ContactListProvider> contactList;
    QVector<QPushButton*> buttons;
    contactList.append({"Harry Potter", "123456789"});
    contactList.append({"Hermione Granger", "123456789"});
    contactList.append({"Ron Weasley", "123456789"});
    contactList.append({"Albus Dumbledore", "123456789"});
    contactList.append({"Sirius Black", "123456789"});
    contactList.append({"Rubeus Hagrid", "123456789"});
    contactList.append({"Lord Voldemort", "123456789"});
    contactList.append({"Bellatrix Lestrange", "123456789"});
    contactList.append({"Luna Lovegood", "123456789"});
    ContactListProvider temp;
    for (int i = 0; i < contactList.size(); i++){
        for (int j = 0; j < contactList.size(); j++){
            if (QString::compare(contactList[i].contactName, contactList[j].contactName) < 0){
                temp = contactList[i];
                contactList[i] = contactList[j];
                contactList[j] = temp;
            }
        }
    }
    setFixedSize(500,60+55*contactList.size());
    for (int i = 0; i < contactList.size(); i++)
    {
        buttons.push_back(new QPushButton(contactList[i].contactName, this));
        buttons[i]->setGeometry(5, 60+55*i, MainWindow::width()-10, 50);
        buttons[i]->setFont(QFont("Times New Roman", 15));
        buttons[i]->setStyleSheet("background-color: darkCyan; border-radius: 10px;");
        buttons[i]->setText(contactList[i].contactName);
        connect(buttons[i], SIGNAL (released()), this, SLOT (call()));
        QString pictString = "C:/Users/neoko/Documents/%1.png";
        QPixmap picture(pictString.arg(i));
        QLabel *pictLabel = new QLabel(this);
        pictLabel->setPixmap(picture);
        pictLabel->setScaledContents(true);
        pictLabel->setGeometry(10, 60+55*i, 50, 50);
        QString checkString = "%1";
        QCheckBox *check = new QCheckBox(checkString.arg(i), this);
        check->setGeometry(MainWindow::width()-30, 75+55*i, 20, 20);
        checked. append(0);
    }
}

void MainWindow::chanking()
{
    int first = ui->spinBox->text().toInt();
    int second = ui->spinBox_2->text().toInt();
    QVector<ContactListProvider> contactList;
    contactList.append({"Harry Potter", "123456789"});
    contactList.append({"Hermione Granger", "123456789"});
    contactList.append({"Ron Weasley", "123456789"});
    contactList.append({"Albus Dumbledore", "123456789"});
    contactList.append({"Sirius Black", "123456789"});
    contactList.append({"Rubeus Hagrid", "123456789"});
    contactList.append({"Lord Voldemort", "123456789"});
    contactList.append({"Bellatrix Lestrange", "123456789"});
    contactList.append({"Luna Lovegood", "123456789"});
    setFixedSize(500,60+55*(second-first+1));
    int count = 0;
    for (int i = first; i < second+1; i++)
    {
        QPushButton *btn = new QPushButton(this);
        btn->setGeometry(5, 60+55*count, MainWindow::width()-10, 50);
        btn->setFont(QFont("Times New Roman", 15));
        btn->setStyleSheet("background-color: darkCyan; border-radius: 10px;");
        btn->setText(contactList[i].contactName);
        connect(btn, SIGNAL (released()), this, SLOT (call()));
        QString pictString = "C:/Users/neoko/Documents/%1.png";
        QPixmap picture(pictString.arg(i));
        QLabel *pictLabel = new QLabel(this);
        pictLabel->setPixmap(picture);
        pictLabel->setScaledContents(true);
        pictLabel->setGeometry(10, 60+55*i, 50, 50);
        count++;
    }
}

void MainWindow::favor(){
    check++;
    if(check%2 == 1){
        QVector<ContactListProvider> contactList;
        contactList.append({"Hermione Granger", "123456789"});
        contactList.append({"Ron Weasley", "123456789"});
        setFixedSize(500,60+55*contactList.size());
        for (int i = 0; i < contactList.size(); i++)
        {
            if (checked[i] == 1){
                QPushButton *btn = new QPushButton(contactList[i].contactName, this);
                btn->setGeometry(5, 60+55*i, MainWindow::width()-10, 50);
                btn->setFont(QFont("Times New Roman", 15));
                btn->setStyleSheet("background-color: darkCyan; border-radius: 10px;");
                btn->setText(contactList[i].contactName);
                connect(btn, SIGNAL (released()), this, SLOT (call()));
                QString pictString = "C:/Users/neoko/Documents/%1.png";
                QPixmap picture(pictString.arg(i));
                QLabel *pictLabel = new QLabel(this);
                pictLabel->setPixmap(picture);
                pictLabel->setScaledContents(true);
                pictLabel->setGeometry(10, 60+55*i, 50, 50);
            }
        }
    }else{
        QVector<ContactListProvider> contactList;
        contactList.append({"Harry Potter", "123456789"});
        contactList.append({"Hermione Granger", "123456789"});
        contactList.append({"Ron Weasley", "123456789"});
        contactList.append({"Albus Dumbledore", "123456789"});
        contactList.append({"Sirius Black", "123456789"});
        contactList.append({"Rubeus Hagrid", "123456789"});
        contactList.append({"Lord Voldemort", "123456789"});
        contactList.append({"Bellatrix Lestrange", "123456789"});
        contactList.append({"Luna Lovegood", "123456789"});
        setFixedSize(500,60+55*contactList.size());
        for (int i = 0; i < contactList.size(); i++)
        {
            QPushButton *btn = new QPushButton(contactList[i].contactName, this);
            btn->setGeometry(5, 60+55*i, MainWindow::width()-10, 50);
            btn->setFont(QFont("Times New Roman", 15));
            btn->setStyleSheet("background-color: darkCyan; border-radius: 10px;");
            btn->setText(contactList[i].contactName);
            connect(btn, SIGNAL (released()), this, SLOT (call()));
            QString pictString = "C:/Users/neoko/Documents/%1.png";
            QPixmap picture(pictString.arg(i));
            QLabel *pictLabel = new QLabel(this);
            pictLabel->setPixmap(picture);
            pictLabel->setScaledContents(true);
            pictLabel->setGeometry(10, 60+55*i, 50, 50);
        }
    }
}

void MainWindow::call(){
    QMessageBox msgBox;
    msgBox.setText("Calling someone");
    msgBox.exec();
}

void MainWindow::open(){
    bonus = new bonuswindow();
    bonus->show();
    this->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

