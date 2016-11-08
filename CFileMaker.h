//20161014 cm
//数据发生器，主要实现功能是，制作随机的log数据

#ifndef CFileMaker_H
#define CFileMaker_H
#include <time.h>
#include <stdlib.h>
#include <QString>
#include <QDateTime>
#include<QtDebug>

typedef char echar;
typedef double edouble;
typedef unsigned int euint32;

struct fileData{
    echar strModName[6];
    edouble dTimeStamp;
    euint32 nStrLen;
    echar strLog[1280];
};


class CFileMaker
{
public:
    CFileMaker() {}

    void runFileMaker(int tempNum);
    edouble getdTime();
    QString timeConvert(double dTime);
    fileData* getFileData ();

private:
    echar modName[6][6] = {"xtx","yty","ztz","ixi","xxx","adewg"};
    fileData LogStr[100];
  //time convert
};





#endif // CFileMaker_H
