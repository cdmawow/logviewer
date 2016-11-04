#ifndef CFILETHREAD_H
#define CFILETHREAD_H
#include <QThread>
#include <CFileMaker.h>
#include  <QObject>

class CThread:public QThread
{
    Q_OBJECT;
public:
    CThread();
    ~CThread();
    void stop();
    CFileMaker getFileMaker();
    void setMessage(QString message);

protected:
    void run();
private:
    CFileMaker f;
    volatile bool stopped;
signals:
    void sendLog( QStringList logList);
};

#endif // THREAD_H
