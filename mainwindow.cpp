#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setRootIsDecorated(false);
    ui->treeWidget->setColumnWidth(0,50);
    ui->treeWidget->setColumnWidth(1,150);
    QObject::connect(&genFile, SIGNAL(sendLog(QStringList)),this, SLOT(receiveLog(QStringList)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveLog( QStringList logList)
{
//需要判断按钮情况选择执行相应的操作
    if(!filterNameOn && !filterLogOn)
    {
       QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget,logList);
       ui->treeWidget->addTopLevelItem(item);
    }
    if(!filterLogOn && filterNameOn && logList.at(0) == ui->minput_line->text())
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget,logList);
        ui->treeWidget->addTopLevelItem(item);

    }
    if (!filterNameOn && filterLogOn && logList.at(2).contains(ui->ninput_line->text()))
    {
       QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget,logList);
       ui->treeWidget->addTopLevelItem(item);
    }
   if(filterLogOn && filterNameOn && logList.at(0) == ui->minput_line->text() && logList.at(2).contains(ui->ninput_line->text()))
   {
      QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget,logList);
      ui->treeWidget->addTopLevelItem(item);
   }
}

void MainWindow::on_startButton_clicked()
{
    genFile.start();
 //   timeConvert(genFile.getFileMaker().getFileData()[0].dTimeStamp)<<genFile.getFileMaker().getFileData()[0].strLog;
}

void MainWindow::on_stopButton_clicked()
{
//    QObject::disconnect(&genFile, SIGNAL(sendLog(QStringList)),this, SLOT(receiveLog(QStringList)));
    if (genFile.isRunning())    genFile.stop();

}

void MainWindow::on_clearButton_clicked()
{
// 按钮复位
//    QObject::disconnect(&genFile, SIGNAL(sendLog(QStringList)),this, SLOT(receiveLog(QStringList)));
    if (genFile.isRunning())    genFile.stop();
    filterNameOn = false;
    filterLogOn  = false;
    ui->treeWidget->clear();
}

void MainWindow::on_mokButton_clicked()
{
    for(int i = 0 ; i < ui->treeWidget->topLevelItemCount(); ++i)
    {
        if(!(ui->treeWidget->topLevelItem(i)->text(0) == ui->minput_line->text()))
        {
            ui->treeWidget->takeTopLevelItem(i);
            --i;
        }
    }
    filterNameOn = true;
}

void MainWindow::on_nokButton_clicked()
{
    for(int i = 0 ; i < ui->treeWidget->topLevelItemCount(); ++i)
    {
        if(!filterNameOn && !(ui->treeWidget->topLevelItem(i)->text(2).contains(ui->ninput_line->text())))
        {
            ui->treeWidget->takeTopLevelItem(i);
            --i;
        }
        if(filterNameOn && !(ui->treeWidget->topLevelItem(i)->text(2).contains(ui->ninput_line->text()) && ui->treeWidget->topLevelItem(i)->text(0) == ui->minput_line->text()) )
        {
            ui->treeWidget->takeTopLevelItem(i);
            --i;
        }
    }
    filterLogOn = true;
}

QString MainWindow::timeConvert(double dTime)
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

QStringList MainWindow::typeChange(fileData* fData)
{
   QStringList sList;
   sList << fData->strModName << timeConvert(fData->dTimeStamp) << fData->strLog;
   return sList;
}

