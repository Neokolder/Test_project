#include "mainwindow.h"
#include <list>
#include <iterator>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QListView>

#include <QApplication>

class  ContactListProvider
{
public:
    std::string contactName;
    std::string contactPhoneNumber;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
    std::list<ContactListProvider> contactList;
    contactList.push_back({"Misha", "123456789"});
    contactList.push_back({"Misha2", "123456789"});
    contactList.push_back({"Misha3", "123456789"});
}


