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
    QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget,logList);
    item->setTextAlignment(0,1);
    item->setTextAlignment(1,1);
    item->setTextAlignment(2,1);
    qDebug()<<filterOn;
    ui->treeWidget->addTopLevelItem(item);
}

void MainWindow::on_startButton_clicked()
{
    genFile.start();
 //   timeConvert(genFile.getFileMaker().getFileData()[0].dTimeStamp)<<genFile.getFileMaker().getFileData()[0].strLog;
}

void MainWindow::on_stopButton_clicked()
{
//    QObject::disconnect(&genFile, SIGNAL(sendLog(QStringList)),this, SLOT(receiveLog(QStringList)));
    if (genFile.isRunning())
    genFile.stop();

}

void MainWindow::on_clearButton_clicked()
{
//    QObject::disconnect(&genFile, SIGNAL(sendLog(QStringList)),this, SLOT(receiveLog(QStringList)));
    if (genFile.isRunning())
    genFile.stop();
    filterOn = false;
    ui->treeWidget->clear();
}

void MainWindow::on_mokButton_clicked()
{
    filterOn = true;
    ui->treeWidget->findItems(ui->minput_line->text())
}

void MainWindow::on_nokButton_clicked()
{
    filterOn = true;
}
