#include "CFileThread.h"

CThread::CThread()
{
    stopped = false;
}

CThread::~CThread()
{

}

CFileMaker CThread::getFileMaker()
{
    return f;
}

void CThread::run()
{
    unsigned int tempNum = 0;
    srand((unsigned)time(NULL));
    while(!stopped)
    {
        f.runFileMaker(tempNum);
        QStringList itemList;
        itemList << f.getFileData()[tempNum].strModName << f.timeConvert(f.getFileData()[tempNum].dTimeStamp)<< f.getFileData()[tempNum].strLog;
        emit sendLog(itemList);
        tempNum ++ ;
        tempNum = tempNum%100;
        QThread::sleep(1);
    }

    stopped = false;
}

void CThread::stop()
{
    stopped = true;
}
