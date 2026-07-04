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
     QListWidget *listWidget;
     QLabel *id, *page1,*page2,*page3,*page4,*page5;
     QListWidgetItem *item1, *item2, *item3, *item4, *item5;
     QStackedWidget *stackedWidget;

     CongigWindow *CongigPage;
};
#endif // MAINWINDOW_H
