//cm 20161108
//log显示器，带简单过滤功能
//用qtreeWidget实现界面

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <CFileThread.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

//转换数据类型，从struct转换为QStringList，为预留功能
    QStringList typeChange(fileData* fData);

private slots:

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_clearButton_clicked();

    void on_mokButton_clicked();

    void on_nokButton_clicked();
//接受数据的槽函数，接收数据格式为 名称 时间 内容的list
    void receiveLog (QStringList logList);


private:
    Ui::MainWindow *ui;
    CThread genFile;
// 标志位，分别表示两个按钮被按下
    bool filterNameOn = false;
    bool filterLogOn = false;
// 把edouble类型的时间转换为yyyy-MM-dd hh:mm:ss.zzz
    QString timeConvert(edouble dTime);

};

#endif // MAINWINDOW_H
