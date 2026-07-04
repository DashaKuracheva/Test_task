#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "configuration.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
     QWidget *centralWidget;
     QHBoxLayout *mainLayout;
     QVBoxLayout *InfoLayout;
     QListWidget *listWidget;
     QLabel *idInfo, *page1,*page2,*page3,*page4,*page5;
     QListWidgetItem *item1, *item2, *item3, *item4, *item5;
     QStackedWidget *stackedWidget;

     CongigWindow *CongigPage;

private slots:
    void updateInfo();
};
#endif // MAINWINDOW_H
