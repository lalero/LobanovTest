#include <QtCore/QCoreApplication>
#include "iostream"
#include <QFile>
#include <QDebug>
#include <QByteArray>
#include <QString>
#include <QTextStream>
#include <QStringList>

using namespace std;

void readFile()
{
    QFile file("C:/Programms/LobanovTest/Ships.txt");
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
         cout << "Invalid file path, please specify a valid file path 'Ships.txt'" << endl;
         cout << "My specified path - C:/Programms/LobanovTest/Ships.txt";
         return;
     }

     QStringList lines;

     QTextStream in(&file);
     while (!in.atEnd()) {
         QString line = in.readLine();
         lines.append(line);
     }
     qDebug()<<lines;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    readFile();

    return a.exec();
}

