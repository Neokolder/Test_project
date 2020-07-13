#include "bonuswindow.h"
#include "ui_bonuswindow.h"
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

bonuswindow::bonuswindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bonuswindow)
{
    ui->setupUi(this);
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
    setFixedSize(490,125+55*contactList.size()/4);
    QString pictString = "C:/Users/neoko/Documents/wand.png";
    QPixmap picture(pictString);
    ui->setupUi(this);
    for (int i = 0; i < contactList.size(); i++)
    {
        QPushButton *btn = new QPushButton(contactList[i].contactName, this);
        int a = i % 4;
        int b = i / 4;
        btn->setGeometry(5+120*a, 60+65*b, 110, 55);
        btn->setFont(QFont("Times New Roman", 15));
        btn->setStyleSheet("background-color: darkCyan; border-radius: 10px;");
        btn->setText(" ");
        connect(btn, SIGNAL (released()), this, SLOT (call()));
        QString pictString = "C:/Users/neoko/Documents/%1.png";
        QPixmap picture(pictString.arg(i));
        QLabel *pictLabel = new QLabel(this);
        pictLabel->setPixmap(picture);
        pictLabel->setScaledContents(true);
        pictLabel->setGeometry(5+120*a, 60+65*b, 55, 55);
        connect(ui->pushButton1, SIGNAL (released()), this, SLOT(on_pushButton1_clicked()));
    }
    ui->pushButton1->setGeometry(45, 5, 50, 50);
    ui->pushButton1->setText("Style");
}

void bonuswindow::on_pushButton1_clicked()
{
    this->close();
    emit firstWindow();
}

void bonuswindow::call(){
    QMessageBox msgBox;
    msgBox.setText("Calling someone");
    msgBox.exec();
}

bonuswindow::~bonuswindow()
{
    delete ui;
}


