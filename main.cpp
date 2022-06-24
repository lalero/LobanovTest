#include <QtCore/QCoreApplication>
#include "iostream"
#include <QFile>
#include <QDebug>
#include <QByteArray>
#include <QString>
#include <QTextStream>
#include <QStringList>

namespace global
{
    QStringList linesFile;
    QStringList playZone;
    int errorLength = 0;
}

using namespace global;
using namespace std;


void readFile()
{
    //    setlocale(LC_ALL,"Russian");

    QFile file("C:/Programms/LobanovTest/Ships.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
//        cout << "Указан неправильный путь к файлу, укажите правильный путь к файлу 'Ships.txt'" << endl;
//        cout << "Мой указанный путь - C:/Programms/LobanovTest/Ships.txt" << endl;
        cout << "Invalid file path, please specify a valid file path 'Ships.txt'" << endl;
        cout << "My specified path - C:/Programms/LobanovTest/Ships.txt" << endl;
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        if (line.length() < 10)
        {
            errorLength++;
        }
        linesFile.append(line);
    }
//    qDebug()<<linesFile;
}

void checkAndWriteStringList()
{
    //setlocale(LC_ALL,"Russian");

    int linesSize = linesFile.size();
    int linesSizeEnd = 0;
    int countLine = 0;
    int countStep = 0;

    qDebug()<<"linesSize="<<linesSize;
    qDebug()<<"errorLength="<<errorLength;
    if ((linesSize < 10)||(errorLength > 0))
    {
//        cout << "Ошибка! Не найдено поле требуемого размера 10х10"<< endl;
        cout << "Error! Required field size (10x10) not found!" << endl;
    }
    else
    {
    while (linesSize != linesSizeEnd)
    {
        //qDebug()<<"linesFile[linesSizeEnd].length()="<<linesFile[linesSizeEnd].length();
        for (int i = 0; i < linesFile[linesSizeEnd].length(); i++)
        {
            if ((linesFile[linesSizeEnd][i]=='0')||(linesFile[linesSizeEnd][i]=='*'))
            {

                countLine++;

                if (countLine == 10)
                {

                    for (int column = 0; column < 10; column++)
                    {
                        if ((linesFile[column][i]=='0')||(linesFile[column][i]=='*'))
                        {

                        }
                    }
                }
            }
            else
            {
                countStep++;
            }
        }

        linesSizeEnd++;
    }
    //qDebug()<<"countLine="<<countLine;

    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    readFile();
    checkAndWriteStringList();

    return a.exec();
}

