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

    int linesSize = linesFile.size(); //кол-во строк в файле
    int linesSizeEnd = 0;
    int countLine = 0;
    int countLeftUp = 0;
    int columnError = 0;
    int flagError = 0;
    int flagError2 = 0;
    int flagError3 = 0;
    int countStepDown = 0;
    int lengthNormal = 0;
    int countControl = 0;

    //qDebug()<<"linesSize="<<linesSize;
    //qDebug()<<"errorLength="<<errorLength;
    if ((linesSize < 10)||(errorLength > 0))
    {
        //cout << "Ошибка! Не найдено поле требуемого размера 10х10"<< endl;
        cout << "Error! Required field size (10x10) not found!" << endl;
    }
    else
    {
        while (linesSize-1 > linesSizeEnd)
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

                        //qDebug()<<"countLine="<<countLine;
                    }

                    //                    qDebug()<<"linesSizeEnd="<<linesSizeEnd;
                    //                    qDebug()<<"linesSize-1="<<linesSize-1;
                    countControl=linesSize-linesSizeEnd;

                    //(countLine == 10)
                    if ((countLine == 10)&&(countControl>=9))
                    {
                        int x=0;
                        int y=0;
                        int pRight=0;
                        int pRightCount=0;
                        qDebug()<<"i="<<i;
                        //qDebug()<<"linesFile[linesSizeEnd].length()-1="<<linesFile[linesSizeEnd].length()-1;


                        //qDebug()<<"123456789";
                        //qDebug()<<"flagError="<<flagError;
                        int countCheck=linesFile[linesSizeEnd].length()-1;

                        //                                if (i<countCheck)
                        //                                {
                        //                                    while (pRight<10)
                        //                                    {
                        //                                        for (int k = linesSizeEnd; k < linesSizeEnd+10; k++)
                        //                                        {

                        //                                            if (i<countCheck)
                        //                                            {

                        //                                            if (linesFile[k][i+1]!=' ')
                        //                                            {
                        //                                                flagError = 1;
                        //                                                flagError3 = 1;
                        //                                            }

                        //                                            countCheck=linesFile[linesSizeEnd+1].length()-1;
                        //                                            }
                        //                                        }
                        //                                        pRight++;
                        //                                    }
                        //                                }
                        //                        else
                        //                            if (linesSize-1 > linesSizeEnd)
                        //                            {
                        //                                if (linesFile[linesSizeEnd+10][countLeftUp]!=' ')
                        //                                {
                        //                                    flagError = 1;
                        //                                    flagError3 = 1;
                        //                                }
                        //                            }
                        //                            else
                        //                           {


                        //qDebug()<<"linesFile[linesSizeEnd].length()="<<linesFile[linesSizeEnd].length();
                        //qDebug()<<"flagError="<<flagError;

                        //qDebug()<<"linesSize="<<linesSize;

                        //qDebug()<<"countControl="<<countControl;



                        //qDebug()<<"lengthNormal="<<lengthNormal;
                        //qDebug()<<"i="<<i;

                        int strNowLength;
                        int z = linesSizeEnd;
                        strNowLength = linesFile[z].length();
                        //                        qDebug()<<"strNowLength="<<strNowLength;
                        //qDebug()<<"i="<<i;

                        //qDebug()<<"linesSizeEnd="<<linesSizeEnd;

                        //lengthNormal = countLeftUp+9;

                        columnError = linesSize - linesSizeEnd;
                        //qDebug()<<"columnError="<<columnError;

                        if (columnError<10)
                        {
                            linesSizeEnd = linesSize-1;
                        }
                        else
                        {

                            int k=0;
                            while (z<linesSizeEnd+10)
                            {
                                if(linesFile[z].length()-1<i)
                                {
                                    flagError = 1;
                                    flagError3 = 1;
                                    //linesSizeEnd = linesSize-1;
                                    z = linesSizeEnd+10;
                                }
                                z++;
                            }

                            //qDebug()<<"k="<<k;
                            //qDebug()<<"flagError="<<flagError;
                            //qDebug()<<"linesSizeEnd="<<linesSizeEnd;
                            //qDebug()<<"countLeftUp="<<countLeftUp;

                            //int u=0;
                            //int w=0;

                            if (flagError == 0)
                            {
                                for (int n = linesSizeEnd; n < linesSizeEnd+10; n++)
                                {
                                    for (int m = countLeftUp; m < countLeftUp+10; m++)
                                    {
                                        if ((linesFile[n][m]!='0')&&(linesFile[n][m]!='*'))
                                        {
                                            //shipsZone[u][w]=linesFile[n][m];
                                            //w++;
                                            flagError3 = 1;
                                        }
                                    }
                                    //w=0;
                                    //u++;
                                }
                                //linesSizeEnd = linesSize-1;
                            }

                            k = linesSizeEnd;
                            int strSize = linesFile[k].length()-1;
                            qDebug()<<"strSize="<<strSize;

                            //for (int i = 0; i < linesFile[linesSizeEnd].length(); i++)
                            //if (linesFile[k][i+1]!=' ')
                            //int a=0;

                            qDebug()<<"countLeftUp="<<countLeftUp;
                            if (flagError == 0)
                            {
                                for (int a = linesSizeEnd; a < linesSizeEnd+10; a++)
                                {
//                                    for (int b = countLeftUp; b < countLeftUp+10; b++)
//                                    {
                                        int strSize = linesFile[a].length()-1;
                                        //qDebug()<<"strSize="<<strSize;

                                        if (strSize-countLeftUp!=9)
                                        {
                                            if (linesFile[a][countLeftUp+10]!=' ')
                                            {

                                            qDebug()<<"NOTOKEY";
                                            flagError = 1;
                                            flagError3 = 1;
                                            }
                                        }

                                        if (countLeftUp!=0)
                                        {
                                            if (linesFile[a][countLeftUp-1]!=' ')
                                            {

                                            qDebug()<<"NOTOKEY";
                                            flagError = 1;
                                            flagError3 = 1;
                                            }
                                        }
                                }

                                for (int a = linesSizeEnd; a < linesSizeEnd+10; a++)
                                {

                                   //Доделать клетка отступ сверху и снизу
//                                    for (int b = countLeftUp; b < countLeftUp+10; b++)
//                                    {
                                        int strSize = linesFile[a].length()-1;
                                        //qDebug()<<"strSize="<<strSize;

                                        if (strSize-countLeftUp!=9)
                                        {
                                            if (linesFile[a][countLeftUp+10]!=' ')
                                            {

                                            qDebug()<<"NOTOKEY";
                                            //flagError = 1;
                                            //flagError3 = 1;
                                            }
                                        }

//                                        if (countLeftUp!=0)
//                                        {
//                                            if (linesFile[a][countLeftUp-1]!=' ')
//                                            {

//                                            qDebug()<<"NOTOKEY";
//                                            flagError = 1;
//                                            flagError3 = 1;
//                                            }
//                                        }
                                }

                            }

                            //qDebug()<<"flagError3="<<flagError3;

                            int line = 0;
                            if (flagError3 == 0)
                            {
                                //qDebug()<<"OK";
                                //qDebug()<<"countLeftUp="<<countLeftUp;

                                //for (int j = countLeftUp; j < countLeftUp+10; j++)
                                //{
                                int j = countLeftUp;
                                while (j < countLeftUp+10)
                                {

                                    //for (int line = linesSizeEnd; line < linesSizeEnd+10; line++)
                                    //{
                                    line = linesSizeEnd;
                                    while (line < linesSizeEnd+10)
                                    {
                                        //if ((linesFile[line][j]=='0')||(linesFile[line][j]=='*'))
                                        //{
                                        //qDebug()<<"1111111111111111111";

                                        shipsZone[x][y]=linesFile[line][j];

                                        //}
                                        //else
                                        //{

                                        //                                        flagError2=1;
                                        //                                        j = countLeftUp+10;
                                        //                                        line = linesSizeEnd+10;
                                        //                                        columnError++;
                                        //}
                                        line++;
                                        x++;
                                    }
                                    //}
                                    x=0;
                                    y++;
                                    j++;
                                }
                                //}

                                //if (i==strNowLength)

                                //qDebug()<<"flagError2="<<flagError2;

                                //                            if (flagError2==0)
                                //                            {
                                linesSizeEnd = linesSize-1;
                                //                            }

                            }
                            else
                            {
                                flagError=0;
                                //flagError2=0;
                                flagError3=0;
                            }

                            //                        }

                        }
                    }
                }
                else
                {
                    countLine=0;
                    countLeftUp=0;
                }
            }
            countLeftUp=0;
            countLine=0;

            flagError=0;
            //flagError2=0;
            flagError3=0;
            countControl=0;
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

