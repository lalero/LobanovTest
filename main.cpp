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
    QStringList shipsZone;
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
//        if (line.length() < 10)
//        {
//            errorLength++;
//        }
        linesFile.append(line);
    }
//    qDebug()<<linesFile;
}

void checkAndWriteStringList()
{

    int linesSize = linesFile.size();
    int linesSizeEnd = 0;
    int countLine = 0;
    int countLeftUp = 0;
    int columnError = 0;
    int flagError = 0;

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

                if (countLine == 1)
                {
                    countLeftUp = i;
                    qDebug()<<"countLeftUp="<<countLeftUp;
                }



                if (countLine == 10)
                {
                    int x=0;
                    int y=0;
                    flagError = linesSize - linesSizeEnd;
                    qDebug()<<"linesSize="<<linesSize;
                    qDebug()<<"linesSizeEnd="<<linesSizeEnd;
                    qDebug()<<"flagError="<<flagError;



//                    qDebug()<<"countLine="<<countLine;
//                    qDebug()<<"countLeftUp="<<countLeftUp;
                    for (int j = countLeftUp; j < countLeftUp+10; j++)
                    {
                        for (int line = linesSizeEnd; line < linesSizeEnd+10; line++)
                        {
                            if ((linesFile[line][j]=='0')||(linesFile[line][j]=='*'))
                            {
                                shipsZone[x][y]=linesFile[line][j];
                            }
                            else
                            {
                                columnError++;
                            }
                            x++;
                        }
                        x=0;
                        y++;
                    }
                    linesSizeEnd = linesSize-1;
                }
            }
            else
            {
                countLine=0;
                countLeftUp=0;
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

    int o = 0;
    while (o<10)
    {
        QString x="##########";
        shipsZone.append(x);
        o++;
//        qDebug() << x;
//        qDebug() << "1";
    }


    readFile();
    checkAndWriteStringList();

    int y = 0;
    while (y<10)
    {
        qDebug() << shipsZone[y];
        y++;
    }

    return a.exec();
}

