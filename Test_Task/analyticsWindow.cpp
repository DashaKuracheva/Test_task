#include "analyticsWindow.h"
#include "mainwindow.h"
#include <cstdlib>

analyticsWindow::analyticsWindow(QWidget *parent) : QWidget(parent) {

    windowLayout = new QGridLayout(this);

    buttonStyle =
        "QPushButton { border: 2px solid #cccccc; background-color: #f0f0f0; color: #333333; border-radius: 10px; padding: 10px 20px; font-size: 26px; }"
        "QPushButton:hover { background-color: #e0e0e0; }"
        "QPushButton:checked { border: 2px solid #1565c0; background-color: #1976d2; color: white; font-weight: bold; }";

//карточка1
    QFrame *card1 = MainWindow::createCardWidget();
    crd1 = new QVBoxLayout(card1);
    lbl1 = new QLabel("Потребление энергии по периодам");
    lbl1->setStyleSheet("font-size: 34px; font-weight: bold; border-bottom: 4px solid black; padding-bottom: 6px; margin-bottom: 10px;");
    crd1->addWidget(lbl1);
    crd1->addSpacing(30);

    btnLayout = new QHBoxLayout();
    btnLayout->setSpacing(30);

    btnD = new QPushButton("Дни");
    btnD->setStyleSheet(buttonStyle);
    btnW = new QPushButton("Недели");
    btnW->setStyleSheet(buttonStyle);
    btnM = new QPushButton("Месяцы");
    btnM->setStyleSheet(buttonStyle);

    btnD->setCheckable(true);
    btnW->setCheckable(true);
    btnM->setCheckable(true);
    btnD->setChecked(true);

    connect(btnD, SIGNAL(clicked()), this, SLOT(showDay()));
    connect(btnW, SIGNAL(clicked()), this, SLOT(showWeek()));
    connect(btnM, SIGNAL(clicked()), this, SLOT(showMonth()));

    btnGroup = new QButtonGroup(this);
    btnGroup->addButton(btnD);
    btnGroup->addButton(btnW);
    btnGroup->addButton(btnM);
    btnGroup->setExclusive(true);

    btnLayout->addWidget(btnD);
    btnLayout->addWidget(btnW);
    btnLayout->addWidget(btnM);

    crd1->addLayout(btnLayout);

    title1 = new QLabel("Потребление энергии, кВт·ч");
    title1->setStyleSheet("font-size: 28px; font-weight: bold; margin-top: 10px;");
    crd1->addWidget(title1);

    plot1 = new QCustomPlot();
    plot1->setMinimumHeight(350);
    plot1->setBackground(Qt::white);
    crd1->addWidget(plot1, 1);

    int totalDays = 31;
    int totalWeeks = 4;
    int totalMonths = 12;

    dayX.resize(totalDays);
    dayY.resize(totalDays);
    for (int i = 0; i < totalDays; i++)
        {
            dayX[i] = i + 1;
            dayY[i] = ((double)rand()/RAND_MAX) * maxEnergyD;
        }

    weekX.resize(totalWeeks);
    weekY.resize(totalWeeks);
    for (int i = 0; i < totalWeeks; i++)
        {
            weekX[i] = i + 1;
            weekY[i] = ((double)rand()/RAND_MAX) * maxEnergyW;
        }

    monthX.resize(totalMonths);
    monthY.resize(totalMonths);
    for (int i = 0; i < totalMonths; i++)
        {
            monthX[i] = i + 1;
            monthY[i] = ((double)rand()/RAND_MAX) * maxEnergyM;
        }

    graphPower(dayX, dayY, maxEnergyD);
    windowLayout->addWidget(card1, 0, 0);

//карточка2
    QFrame *card2 = MainWindow::createCardWidget();
    crd2 = new QVBoxLayout(card2);
    lbl2 = new QLabel("Статистика по коннекторам");
    lbl2->setStyleSheet("font-size: 34px; font-weight: bold; border-bottom: 4px solid black; padding-bottom: 6px; margin-bottom: 8px;");
    crd2->addWidget(lbl2);

    title2 = new QLabel("Коннектор 1");
    title2->setAlignment(Qt::AlignCenter);
    title2->setStyleSheet("font-size: 30px; font-weight: bold; margin-top: 10px;");
    crd2->addWidget(title2);

    session = new QLabel("59");
    session->setAlignment(Qt::AlignCenter);
    session->setStyleSheet("font-size: 40px; font-weight: bold; color: #1565c0; margin-top: 10px;");
    crd2->addWidget(session);

    sessionLbl = new QLabel("сессий");
    sessionLbl->setAlignment(Qt::AlignCenter);
    sessionLbl->setStyleSheet("font-size: 24px; color: #666666;");
    crd2->addWidget(sessionLbl);

    energy = new QLabel("677.89");
    energy->setAlignment(Qt::AlignCenter);
    energy->setStyleSheet("font-size: 40px; font-weight: bold; color: #1565c0; margin-top: 10px;");
    crd2->addWidget(energy);

    energyLbl = new QLabel("кВт·ч");
    energyLbl->setAlignment(Qt::AlignCenter);
    energyLbl->setStyleSheet("font-size: 24px; color: #666666;");
    crd2->addWidget(energyLbl);

    time = new QLabel("2.0");
    time->setAlignment(Qt::AlignCenter);
    time->setStyleSheet("font-size: 40px; font-weight: bold; color: #1565c0; margin-top: 10px;");
    crd2->addWidget(time);

    timeLbl = new QLabel("ч (среднее)");
    timeLbl->setAlignment(Qt::AlignCenter);
    timeLbl->setStyleSheet("font-size: 24px; color: #666666; margin-bottom: 10px;");
    crd2->addWidget(timeLbl);

    titleConn = new QLabel("Использование коннекторов");
    titleConn->setStyleSheet("font-size: 28px; font-weight: bold; margin-top: 10px;");
    crd2->addWidget(titleConn);

    crd2->addSpacing(15);

    plot2 = new QCustomPlot();
    plot2->setFixedSize(800,500);
    plot2->setBackground(Qt::white);

    crd2->addWidget(plot2);
    graphConnector();

    crd2->addStretch();
    windowLayout->addWidget(card2, 0, 1, 2, 1);

//карточка3
    QFrame *card3 = MainWindow::createCardWidget();
    crd3 = new QVBoxLayout(card3);
    lbl3 = new QLabel("Пиковые часы использования");
    lbl3->setStyleSheet("font-size: 34px; font-weight: bold; border-bottom: 4px solid black; padding-bottom: 6px; margin-bottom: 8px;");
    crd3->addWidget(lbl3);

    title3 = new QLabel("Активность по часам");
    title3->setAlignment(Qt::AlignCenter);
    title3->setStyleSheet("font-size: 28px; font-weight: bold; margin-top: 10px;");
    crd3->addWidget(title3);

    plot3 = new QCustomPlot();
    plot3->setMinimumHeight(360);
    plot3->setBackground(Qt::white);
    crd3->addWidget(plot3, 1);
    graphTime();

    windowLayout->addWidget(card3, 1, 0);
    windowLayout->setColumnStretch(0, 3);
    windowLayout->setColumnStretch(1, 2);
}

void analyticsWindow::graphPower(const QVector<double> &x, const QVector<double> &y, double yMax) {
    plot1->clearGraphs();

    plot1->addGraph();
    plot1->graph(0)->setData(x, y);
    plot1->graph(0)->setPen(QPen(QColor("#0089ef"), 2));
    plot1->graph(0)->setBrush(QBrush(QColor(25, 118, 210, 80)));
    plot1->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QColor("#0089ef"), QColor("#0089ef"), 6));

    plot1->xAxis->setRange(x.first(), x.last());
    plot1->yAxis->setRange(0, yMax * 1.15);
    plot1->xAxis->grid()->setPen(QPen(QColor("#e0e0e0")));
    plot1->yAxis->grid()->setPen(QPen(QColor("#e0e0e0")));

    if (plot1->width() > 0 && plot1->height() > 0) {
        plot1->replot();
    }
}

void analyticsWindow::graphConnector() {
    plot2->clearPlottables();
    plot2->clearItems();
    plot2->axisRect()->setMargins(QMargins(50, 50, 20, 15));

    QCPBars *sessionsBar = new QCPBars(plot2->xAxis, plot2->yAxis);
    sessionsBar->setName("Сессии");
    sessionsBar->setWidth(0.3);
    sessionsBar->setPen(Qt::NoPen);
    sessionsBar->setBrush(QColor("#87d963"));
    sessionsBar->setData(QVector<double>{0.8}, QVector<double>{59});

    QCPBars *energyBar = new QCPBars(plot2->xAxis, plot2->yAxis);
    energyBar->setName("Энергия (кВт·ч)");
    energyBar->setWidth(0.3);
    energyBar->setPen(Qt::NoPen);
    energyBar->setBrush(QColor("#1565c0"));
    energyBar->setData(QVector<double>{1.2}, QVector<double>{677.89});

    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTick(1.0, "Connector 1");
    plot2->xAxis->setTicker(textTicker);

    plot2->xAxis->setRange(0.3, 1.7);
    plot2->yAxis->setRange(0, 820);

    QPen axisPen(QColor("#d0d2d6"), 1);
    plot2->xAxis->setBasePen(axisPen);
    plot2->yAxis->setBasePen(axisPen);
    plot2->xAxis->setTickPen(axisPen);
    plot2->yAxis->setTickPen(axisPen);
    plot2->xAxis->setSubTickPen(Qt::NoPen);
    plot2->yAxis->setSubTickPen(Qt::NoPen);

    QFont labelsFont = font();
    labelsFont.setPointSize(10);
    plot2->xAxis->setTickLabelFont(labelsFont);
    plot2->yAxis->setTickLabelFont(labelsFont);

    plot2->xAxis2->setVisible(false);
    plot2->yAxis2->setVisible(false);

    plot2->yAxis->grid()->setVisible(true);
    plot2->yAxis->grid()->setPen(QPen(QColor("#eef0f4"), 1, Qt::DashLine));
    plot2->xAxis->grid()->setVisible(false);

    QCPItemText *sessionsLabel = new QCPItemText(plot2);
    sessionsLabel->position->setCoords(0.8, 59 + 10);
    sessionsLabel->setPositionAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    sessionsLabel->setText("59");
    sessionsLabel->setFont(QFont(font().family(), 11, QFont::Bold));
    sessionsLabel->setColor(QColor("#333333"));
    sessionsLabel->setClipToAxisRect(false);

    QCPItemText *energyLabel = new QCPItemText(plot2);
    energyLabel->position->setCoords(1.2, 677.89 + 10);
    energyLabel->setPositionAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    energyLabel->setText("677.89");
    energyLabel->setFont(QFont(font().family(), 11, QFont::Bold));
    energyLabel->setColor(QColor("#333333"));
    energyLabel->setClipToAxisRect(false);

    plot2->legend->setVisible(true);
    plot2->axisRect()->insetLayout()->take(plot2->legend);
    plot2->plotLayout()->addElement(1, 0, plot2->legend);
    plot2->plotLayout()->setRowStretchFactor(1, 0.001);

    plot2->legend->setFillOrder(QCPLegend::foRowsFirst);
    plot2->legend->setBrush(Qt::NoBrush); // Прозрачный фон легенды
    plot2->legend->setBorderPen(Qt::NoPen); // Без рамки вокруг легенды
    plot2->legend->setFont(QFont(font().family(), 10));

    if (plot2->width() > 0 && plot2->height() > 0) {
        plot2->replot();
    }
}

void analyticsWindow::graphTime() {
    QVector<double> hours (25);
    for(int i=0; i<=24; i++)
    {
        hours[i]=i;
    }

    QVector<double> sessionsHour (25);
    QVector<double> energy (25);
    for (int i = 0; i <= 24; i++)
    {
        sessionsHour[i] = rand() % 11;
        double random = (double)rand()/RAND_MAX;
         energy[i] = random * 150.0;
    }

    plot3->clearGraphs();

    plot3->addGraph();
    plot3->graph(0)->setData(hours, energy);
    plot3->graph(0)->setPen(QPen(QColor("#1976d2"), 2));
    plot3->graph(0)->setBrush(QBrush(QColor(25, 118, 210, 80)));
    plot3->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QColor("#0089ef"), QColor("#0089ef"), 6));
    plot3->graph(0)->setName("Энергия,кВт·ч");

    plot3->addGraph();
    plot3->graph(1)->setData(hours, sessionsHour);
    plot3->graph(1)->setPen(QPen(QColor("#4caf50"), 2));
    plot3->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QColor("#4caf50"), QColor("#4caf50"), 6));
    plot3->graph(1)->setName("Сессии");

    QSharedPointer<QCPAxisTickerText> hourTicker(new QCPAxisTickerText);
    for (int h = 0; h <= 24; h += 2) {
        hourTicker->addTick(h, QString("%1:00").arg(h));
    }
    plot3->xAxis->setTicker(hourTicker);
    plot3->xAxis->setRange(0, 24.5);
    plot3->yAxis->setRange(0, 164);
    plot3->xAxis->grid()->setPen(QPen(QColor("#e0e0e0")));
    plot3->yAxis->grid()->setPen(QPen(QColor("#e0e0e0")));

    plot3->legend->setVisible(true);
    plot3->axisRect()->insetLayout()->take(plot3->legend);
    plot3->plotLayout()->addElement(1, 0, plot3->legend);
    plot3->plotLayout()->setRowStretchFactor(1, 0.001);
    plot3->legend->setFillOrder(QCPLegend::foRowsFirst);
    plot3->legend->setBorderPen(Qt::NoPen);

    if (plot3->width() > 0 && plot3->height() > 0) {
        plot3->replot();
    }
}

void analyticsWindow::showDay() {
    graphPower(dayX, dayY, maxEnergyD);
}

void analyticsWindow::showWeek() {
    graphPower(weekX, weekY, maxEnergyW);
}

void analyticsWindow::showMonth() {
    graphPower(monthX, monthY, maxEnergyM);
}
