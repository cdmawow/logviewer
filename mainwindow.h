#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include <CFileMaker.h>
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

private slots:

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_clearButton_clicked();

    void on_mokButton_clicked();

    void on_nokButton_clicked();

    void receiveLog (QStringList logList);

private:
    Ui::MainWindow *ui;
    CFileMaker f;
    CThread genFile;
    bool filterOn = false;

};

#endif // MAINWINDOW_H
