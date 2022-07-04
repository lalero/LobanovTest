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
QStringList fakeLineShips;
QStringList fakeColumnShips;
QStringList allShips;
QStringList greenShips;
QStringList redShips;
}

using namespace global;
using namespace std;

void readFile()
{
    //setlocale(LC_ALL,"Russian");

    QFile file("C:/Programms/LobanovTest/Ships.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //cout << "Указан неправильный путь к файлу, укажите правильный путь к файлу 'Ships.txt'" << endl;
        //cout << "Мой указанный путь - C:/Programms/LobanovTest/Ships.txt" << endl;
        cout << "Invalid file path, please specify a valid file path 'Ships.txt'" << endl;
        cout << "My specified path - C:/Programms/LobanovTest/Ships.txt" << endl;
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        //if (line.length() < 10)
        //{
        //errorLength++;
        //}
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
    int messageError1 = 1;
    int messageError2 = 0;
    //int messageError = 0;
    //int flagError2 = 0;
    int flagError3 = 0;
    //int countStepDown = 0;
    //int lengthNormal = 0;
    int countControl = 0;

    //qDebug()<<"linesSize="<<linesSize;
    //qDebug()<<"errorLength="<<errorLength;
    if (linesSize < 10)
    {
        //cout << "Ошибка! Не найдено поле требуемого размера 10х10"<< endl;
        //cout << "Error! Required field size (10x10) not found!" << endl;
        messageError1=1;
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

                    //qDebug()<<"linesSizeEnd="<<linesSizeEnd;
                    //qDebug()<<"linesSize-1="<<linesSize-1;
                    countControl=linesSize-linesSizeEnd;

                    //(countLine == 10)
                    if ((countLine == 10)&&(countControl>=9))
                    {
                        int x=0;
                        int y=0;
                        //int pRight=0;
                        //int pRightCount=0;

                        //qDebug()<<"i="<<i;
                        //qDebug()<<"linesFile[linesSizeEnd].length()-1="<<linesFile[linesSizeEnd].length()-1;
                        //qDebug()<<"123456789";
                        //qDebug()<<"flagError="<<flagError;

                        //int countCheck=linesFile[linesSizeEnd].length()-1;

                        //qDebug()<<"linesFile[linesSizeEnd].length()="<<linesFile[linesSizeEnd].length();
                        //qDebug()<<"flagError="<<flagError;
                        //qDebug()<<"linesSize="<<linesSize;
                        //qDebug()<<"countControl="<<countControl;
                        //qDebug()<<"lengthNormal="<<lengthNormal;
                        //qDebug()<<"i="<<i;

                        //int strNowLength;
                        int z = linesSizeEnd;
                        //strNowLength = linesFile[z].length();
                        //qDebug()<<"strNowLength="<<strNowLength;
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

                            //int k=0;
                            while (z<linesSizeEnd+10)
                            {
                                if(linesFile[z].length()-1<i)
                                {
                                    flagError = 1;
                                    flagError3 = 1;

                                    //messageError1=1;

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
                                            //messageError1=1;
                                        }
                                    }
                                    //w=0;
                                    //u++;
                                }
                                //linesSizeEnd = linesSize-1;
                            }

                            //k = linesSizeEnd;
                            //int strSize = linesFile[k].length()-1;
                            //qDebug()<<"strSize="<<strSize;

                            //for (int i = 0; i < linesFile[linesSizeEnd].length(); i++)
                            //if (linesFile[k][i+1]!=' ')
                            //int a=0;

                            //qDebug()<<"countLeftUp="<<countLeftUp;
                            if (flagError == 0)
                            {
                                for (int a = linesSizeEnd; a < linesSizeEnd+10; a++)
                                {
                                    //for (int b = countLeftUp; b < countLeftUp+10; b++)
                                    //{
                                    int strSize = linesFile[a].length()-1;
                                    //qDebug()<<"strSize="<<strSize;

                                    if (strSize-countLeftUp!=9)
                                    {
                                        if (linesFile[a][countLeftUp+10]!=' ')
                                        {

                                            //qDebug()<<"NOTOKEY";
                                            flagError = 1;
                                            flagError3 = 1;
                                            messageError2=1;
                                        }
                                    }

                                    if (countLeftUp!=0)
                                    {
                                        if (linesFile[a][countLeftUp-1]!=' ')
                                        {

                                            //qDebug()<<"NOTOKEY";
                                            flagError = 1;
                                            flagError3 = 1;
                                            messageError2=1;
                                        }
                                    }
                                }

                                //qDebug()<<"countLeftUp="<<countLeftUp;
                                //qDebug()<<"linesSizeEnd="<<linesSizeEnd;
                                //qDebug()<<"linesSize-1="<<linesSize-1;

                                int ColumnSize = linesSize-1-linesSizeEnd;
                                //int cSize = linesSizeEnd;
                                //qDebug()<<"ColumnSize="<<ColumnSize;

                                //int strLengthCheck = linesFile[linesSizeEnd+10].length()-1;
                                //qDebug()<<"strLengthCheck="<<strLengthCheck;

                                if ((ColumnSize>9))
                                {
                                    int a = countLeftUp;
                                    while (a < countLeftUp+10)

                                        //qDebug()<<"Test";
                                        //for (int a = countLeftUp; a < countLeftUp+10; a++)
                                    {
                                        //int intlinesFile10 = linesFile[linesSizeEnd+10].length();
                                        //qDebug()<<"linesSizeEnd="<<linesSizeEnd;
                                        //if (strSize-countLeftUp!=9)
                                        //{

                                        int strLengthCheck = linesFile[linesSizeEnd+10].length()-1;
                                        //qDebug()<<"strLengthCheck="<<strLengthCheck;

                                        //if (strLengthCheck>=countLeftUp+9)
                                        if (a<=strLengthCheck)
                                        {

                                            if (linesFile[linesSizeEnd+10][a]!=' ')
                                            {

                                                //qDebug()<<"NOTOKEY";
                                                flagError = 1;
                                                flagError3 = 1;
                                                messageError2 = 1;
                                            }
                                        }

                                        a++;
                                    }
                                }

                                if (ColumnSize<linesSize-1)
                                {
                                    int b = countLeftUp;
                                    while (b < countLeftUp+10)
                                    {
                                        int strLengthCheckUp = linesFile[linesSizeEnd-1].length()-1;

                                        if (b<=strLengthCheckUp)
                                        {
                                            if (linesFile[linesSizeEnd-1][b]!=' ')
                                            {

                                                //qDebug()<<"NOTOKEY2";
                                                flagError = 1;
                                                flagError3 = 1;
                                                messageError2=1;
                                            }
                                        }

                                        b++;
                                    }
                                }
                            }

                            //qDebug()<<"flagError3="<<flagError3;

                            int line = 0;
                            if (flagError3 == 0)
                            {
                                messageError1=0;
                                messageError2=0;

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
                                messageError1=1;
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

    if (messageError2==1)
    {
        //Ошибка! Обнаружены символы, соприкасающиеся с полем. Уберите их для корректной работы программы. Поле должно быть размером 10х10;
        cout << "Error! Characters in contact with the field are detected. Remove them for the correct operation of the program. The field must be 10x10" << endl;
    }
    else
    if (messageError1==1)
    {
        //cout << "Ошибка! Не найдено поле требуемого размера 10х10"<< endl;
        cout << "Error! No valid field with a size 10x10 was found! Please specify an isolated 10x10 field" << endl;
    }
}

void checkingShips()
{
    //QStringList shipsZone;
    //QStringList allShips;

    QString usedPointsShips="";

    QString allPointsShips="";
    QString selectPointsShips="";

    int countChecksPoints=0;
    int line = 0;
    int column = 0;

    //for (int line = 0; line < 10; line++)
    int countPoint=0;

    while (line < 10)
    {
        column = 0;
        while (column < 10)
        {
            if (shipsZone[line][column]=='*')
            {
                QString str1 = QString::number(line);
                QString str2 = QString::number(column);
                allPointsShips = allPointsShips+str1+str2;
                countChecksPoints++;

                countPoint++;
                selectPointsShips = selectPointsShips+str1+str2;

                //Доделать, не работает при крайней 9ой *

                if (column==9)
                {
                    if (countPoint !=0)
                    {
                        fakeLineShips.append(selectPointsShips);
                        selectPointsShips="";
                        countPoint=0;
                    }
                }

            }
            else
                if (countPoint !=0)
                {
                    fakeLineShips.append(selectPointsShips);
                    selectPointsShips="";
                    countPoint=0;
                }

            column++;
        }
        selectPointsShips="";

        line++;
    }

    line = 0;
    column = 0;
    selectPointsShips="";
    while (column < 10)
    {
        line = 0;
        while (line < 10)
        {
            if (shipsZone[line][column]=='*')
            {
                QString str1 = QString::number(line);
                QString str2 = QString::number(column);
                //allPointsShips = allPointsShips+str1+str2;
                //countChecksPoints++;

                countPoint++;
                selectPointsShips = selectPointsShips+str1+str2;


                if (line==9)
                {
                    if (countPoint !=0)
                    {
                        fakeLineShips.append(selectPointsShips);
                        selectPointsShips="";
                        countPoint=0;
                    }
                }

            }
            else
                if (countPoint !=0)
                {
                    fakeColumnShips.append(selectPointsShips);
                    selectPointsShips="";
                    countPoint=0;
                }

            line++;
        }
        selectPointsShips="";

        column++;
    }


    qDebug()<<fakeLineShips;
    qDebug()<<fakeColumnShips;

//    int countPoint=0;
//    for (int i = 0; i < 10; i++)
//    {

//        for (int j = 0; j < 10; j++)
//        {
//            if (shipsZone[i][j]=='*')
//            {

//                countPoint++;

//                //fakeShips.append(line);

//            }
//            else
//            {
//                if (countPoint !=0)
//                {
//                    fakeShips.append(line);
//                    countPoint=0;
//                }
//            }


//        }

//    }


    //while (line < 10)

    qDebug()<<"allPointsShips="<<allPointsShips;
    //qDebug()<<"allPointsShips.size()="<<allPointsShips.size();
    qDebug()<<"countChecksPoints="<<countChecksPoints;

    QString Ship="";

    int countChecksShips=0;
    int i = 0;
    //int j = 0;
    QString lineStr;
    QString columnStr;
    int errorRadiusCheck=0;
    int intLineRadiusStep=0;
    int intColumnRadiusStep=0;
    int countError = 0;
    QString ship="";


    qDebug()<<"line="<<line;



    /*

    while (allPointsShips.size()!=0)
    {
        lineStr = allPointsShips[i];
        columnStr = allPointsShips[i+1];

        ship=ship+lineStr+columnStr;

        allPointsShips[i]=' ';
        allPointsShips[i+1] = ' ';

        allPointsShips = allPointsShips.simplified();

        //allPointsShips.remove(0,2);

        //allPointsShips.remove(columnStr);


        int lineInt = lineStr.toInt();
        int columnInt = columnStr.toInt();

        shipsZone[lineInt][columnInt]='-';

//        for (int i = 0; i < allPointsShips.size(); i++)
//        {

//        }

        qDebug()<<"lineInt="<<lineInt;
        qDebug()<<"columnInt="<<columnInt;

        //qDebug()<<shipsZone[0][3];



        while (errorRadiusCheck==0)
        {
//        if ((shipsZone[lineInt-1][columnInt-1] == '*') ||
//                (shipsZone[lineInt-1][columnInt] == '*') ||
//                (shipsZone[lineInt-1][columnInt+1] == '*') ||
//                (shipsZone[lineInt][columnInt-1] == '*') ||
//                (shipsZone[lineInt][columnInt+1] == '*') ||
//                (shipsZone[lineInt+1][columnInt-1] == '*') ||
//                (shipsZone[lineInt+1][columnInt] == '*') ||
//                (shipsZone[lineInt+1][columnInt+1] == '*'))

            if (shipsZone[lineInt-1][columnInt] == '*')
                // проверять и на '-' в радиусе
            {
                intLineRadiusStep = lineInt-1;
                intColumnRadiusStep = columnInt;
                shipsZone[intLineRadiusStep][intColumnRadiusStep] = '-';
                countError=1;
            }
            else
                if (shipsZone[lineInt][columnInt-1] == '*')
                {
                    intLineRadiusStep = lineInt;
                    intColumnRadiusStep = columnInt-1;
                    shipsZone[intLineRadiusStep][intColumnRadiusStep] = '-';
                    countError=1;
                }
                else
                    if (shipsZone[lineInt][columnInt+1] == '*')
                    {
                        intLineRadiusStep = lineInt;
                        intColumnRadiusStep = columnInt+1;
                        shipsZone[intLineRadiusStep][intColumnRadiusStep] = '-';
                        countError=1;
                    }
                    else
                        if (shipsZone[lineInt+1][columnInt] == '*')
                        {
                            intLineRadiusStep = lineInt+1;
                            intColumnRadiusStep = columnInt;
                            shipsZone[intLineRadiusStep][intColumnRadiusStep] = '-';
                            countError=1;
                        }
                        else
                        {
                            errorRadiusCheck = 1;
                        }

            if (countError==0)
            {

            qDebug()<<"intLineRadiusStep="<<intLineRadiusStep;
            qDebug()<<"intColumnRadiusStep="<<intColumnRadiusStep;

            QString str1 = QString::number(intLineRadiusStep);
            QString str2 = QString::number(intColumnRadiusStep);

            ship=ship+str1+str2;


            for (int i = 0; i < allPointsShips.size()-1; i++)
            {
                if ((i%2!=0)&&(allPointsShips[i]==str1)&&(allPointsShips[i+1]==str2))
                {
                    allPointsShips[i]=' ';
                    allPointsShips[i+1]=' ';
                }

            }

            //allPointsShips.erase(intLineRadiusStep,intColumnRadiusStep);
//            allPointsShips = allPointsShips.simplified();
//            allPointsShips = allPointsShips.simplified();

            //qDebug()<<"shipsZone[intLineRadiusStep][intColumnRadiusStep]="<<shipsZone[intLineRadiusStep][intColumnRadiusStep];

            QString str;
            for (int i = 0; i < allPointsShips.size(); i++)
            {
                if (allPointsShips[i]!=' ')
                {
                  str = str + allPointsShips[i];
                }
            }
            allPointsShips.clear();
            allPointsShips.append(str);

            }
            countError=0;

        }



        //errorRadiusCheck=0;
        qDebug()<<"ship="<<ship;
        qDebug()<<"allPointsShips="<<allPointsShips;

        //allPointsShips="";
    }

    */


//        for (int i = 0; i < allPointsShips.size()-2; i++)
//        {
//            QString selectedPoint = allPointsShips[i];

//            QString str1 = allPointsShips[i];
//            QString str2 = allPointsShips[i+1];

//            Ship = Ship+str1+str2;

//            if (i<allPointsShips.size()-2)
//            {

//                int j = i + 2;
//                while (j < allPointsShips.size()-1)
//                {
//                    if (allPointsShips[i]==allPointsShips[j])
//                    {
//                        if (allPointsShips[i+1]==allPointsShips[j+1])
//                        {
//                            QString str1 = allPointsShips[i+1];
//                            QString str2 = QString::number(column);

//                        }
//                    }

//                    j=j+2;
//                }
//            }


//        countChecksShips++;
//    }



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
        //qDebug() << x;
        //qDebug() << "1";
    }


    readFile();
    checkAndWriteStringList();
    checkingShips();

    int y = 0;
    while (y<10)
    {
        //qDebug() << shipsZone[y];
        y++;
    }



    return a.exec();
}

