#include "CFileMaker.h"

fileData* CFileMaker::getFileData()
{
    return LogStr;
}

//make file
void CFileMaker::runFileMaker(int tempNum)
{
   strcpy(CFileMaker::LogStr[tempNum%100].strModName,CFileMaker::modName[rand()%6]);
     // qDebug()<<CFileMaker::LogStr[tempNum%100].strModName;
   CFileMaker::LogStr[tempNum%100].dTimeStamp = getdTime();
      //qDebug()<<CFileMaker::timeConvert(CFileMaker::LogStr[tempNum%100].dTimeStamp);
   CFileMaker::LogStr[tempNum%100].nStrLen = rand()%10 + 2;
   for (unsigned int i = 0; i < CFileMaker::LogStr[tempNum%100].nStrLen - 1; i++)
   CFileMaker::LogStr[tempNum%100].strLog[i] = rand() % 74 + 0x30;
   CFileMaker::LogStr[tempNum%100].strLog[CFileMaker::LogStr[tempNum%100].nStrLen - 1] = '\0';
     // qDebug()<<CFileMaker::LogStr[tempNum%100].strLog;
}



edouble CFileMaker::getdTime()
{
    edouble dTime;
    QDateTime current_date_time = QDateTime::currentDateTime();
    dTime = (double)current_date_time.currentMSecsSinceEpoch()/(24*60*60*1000);
    return dTime;
}


 QString CFileMaker::timeConvert(double dTime)
{
    QDateTime *dt=new QDateTime;
    QString str;
    int day =dTime/1;
    int secs =(dTime-day)*24*60*60/1;
    int msecs =((dTime-day)*24*60*60-secs)*1000;
    dt->setDate(QDate(1970,1,1));
    dt->setTime(QTime(0,0,0,0));
    *dt = dt->addDays(day);
    *dt = dt-> addSecs(secs);
    *dt = dt->addMSecs(msecs);
    str = dt->toString("yyyy-MM-dd hh:mm:ss.zzz");
    return str;
}

