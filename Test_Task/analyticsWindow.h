#ifndef ANALYTICSWINDOW_H
#define ANALYTICSWINDOW_H

#include <QtWidgets>
#include <QVector>
#include "qcustomplot.h"

class analyticsWindow : public QWidget
{
    Q_OBJECT

public:
    analyticsWindow(QWidget *parent = nullptr);

private:
    QGridLayout *windowLayout;
    QVBoxLayout *crd1, *crd2, *crd3;
    QLabel * lbl1, *lbl2, * lbl3;
    QString buttonStyle;

//Карточка 1
    QHBoxLayout *btnLayout;
    QPushButton *btnD, *btnW, *btnM;
    QButtonGroup *btnGroup;
    QLabel *title1;
    QCustomPlot *plot1;

//Карточка 2
    QLabel *title2, *session, *sessionLbl, *energy, *energyLbl, *time, *timeLbl, *titleConn;
    QCustomPlot *plot2;

//Карточка 2
    QLabel *title3;
    QCustomPlot *plot3;

    QVector<double> dayX, dayY;
    QVector<double> weekX,weekY;
    QVector<double> monthX,monthY;
    const double maxEnergyD = 60;
    const double maxEnergyW = 250;
    const double maxEnergyM = 1000;

    void graphPower(const QVector<double> &x, const QVector<double> &values, double yMax);
    void graphConnector();
    void graphTime();

private slots:
    void showDay();
    void showWeek();
    void showMonth();

};

#endif // ANALYTICSWINDOW_H
