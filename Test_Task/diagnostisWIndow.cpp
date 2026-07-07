#include "diagnostisWindow.h"
#include "mainwindow.h"

DiagnosticsWindow::DiagnosticsWindow(QWidget *parent) : QWidget{parent}
{
    dumpsEnabled = false;

    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(100, 0, 100, 0);

    tabW = new QTabWidget(this);
    tabW->setStyleSheet(
        "QTabWidget::pane { border: none; }"
        "QTabBar::tab { background: transparent; color: #888888; font-size: 34px; padding: 10px 20px;  min-width: 400px; }"
        "QTabBar::tab:selected { color: #000000; font-weight: bold; border-bottom: 4px solid #2b2b33; }");

    tabW->addTab(createDiagnosticsTab(), "Диагностика счетчика");
    tabW->addTab(createNetworkTab(), "Параметры сети");

    mainLayout->addWidget(tabW);

}

DiagnosticsWindow::~DiagnosticsWindow() {}

QWidget *DiagnosticsWindow::createDiagnosticsTab()
{
    QWidget *list = new QWidget();
    QVBoxLayout *tabLayout= new QVBoxLayout(list);
    tabLayout->addSpacing(30);

    btnLt = new QHBoxLayout();

    QString btn =
        "QPushButton { background-color: #2b2b33; color: white; border-radius: 10px; padding: 15px 20px; font-size: 32px; }"
        "QPushButton:hover { background-color: #40404a; }"
        "QPushButton:pressed { background-color: #1a1a1f; }";

    btnDumps = new QPushButton("Включить дампы");
    btnDumps->setStyleSheet(btn);
    btnLt->addWidget(btnDumps);
    connect(btnDumps, SIGNAL(clicked()), this, SLOT(dumps()));

    btnClear = new QPushButton("Очистить");
    btnClear->setStyleSheet(btn);
    btnLt->addWidget(btnClear);
    connect(btnClear, SIGNAL(clicked()), this, SLOT(clear()));

    btnRefresh = new QPushButton("Обновить");
    btnRefresh->setStyleSheet(btn);
    btnLt->addWidget(btnRefresh);
    connect(btnRefresh, SIGNAL(clicked()), this, SLOT(refresh()));

    tabLayout->addLayout(btnLt);
    tabLayout->addSpacing(30);

//диагностика счетчиков
    diagFrame1 = MainWindow::createCardWidget();
    diagFrameLayout = new QVBoxLayout(diagFrame1);
    diagFrameLayout->setSpacing(15);

    diagTitle = new QLabel("Диагностика счётчиков по коннекторам");
    diagTitle->setAlignment(Qt::AlignCenter);
    diagTitle->setStyleSheet("font-size: 32px; font-weight: bold; border: none;");
    diagFrameLayout->addWidget(diagTitle);
    diagFrameLayout->addSpacing(30);

    connectorFrame = new QFrame();
    connectorFrame->setStyleSheet(".QFrame { border: 3px solid #2ecc71; border-radius: 8px;  background: transparent }");

    connectorLayout = new QVBoxLayout(connectorFrame);
    connectorLayout->setSpacing(15);

    connectorLine = new QHBoxLayout();
    connectorCheck = new QLabel();
    QPixmap pixmapCon2(":/new/prefix1/ok.png");
    QPixmap scaledPixmap2 = pixmapCon2.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    connectorCheck->setPixmap(scaledPixmap2);

    connectorLabel = new QLabel("Коннектор 1");
    connectorLabel->setStyleSheet("font-size: 30px; font-weight: bold; color: #307e0e;");

    connectorLine->addWidget(connectorCheck);
    connectorLine->addWidget(connectorLabel);
    connectorLine->addStretch();

    connectorLayout->addLayout(connectorLine);

    QFrame *divider1 = new QFrame();
    divider1->setFrameShape(QFrame::HLine);
    divider1->setStyleSheet("QFrame { border: none; border-top: 4px solid #999999; }");
    connectorLayout->addWidget(divider1);

    statusLine = new QHBoxLayout();
    statusLabel = new QLabel("Статус счётчика: \u2705 <span style='color: #968e8e;'><i>Подключен</i></span>");
    statusLabel->setStyleSheet("font-size: 28px; font-weight: bold; color: #444444; border: none;");

    ocppStatus = new QLabel("Статус OCPP: <span style='color: #968e8e;'><i>Finishing</i></span>");
    ocppStatus->setStyleSheet("font-size: 28px; font-weight: bold; color: #444444; border: none;");

    statusLine->addWidget(statusLabel);
    statusLine->addStretch();
    statusLine->addWidget(ocppStatus);

    connectorLayout->addLayout(statusLine);

    QFrame *divider2 = new QFrame();
    divider2->setFrameShape(QFrame::HLine);
    divider2->setStyleSheet("QFrame { border: none; border-top: 4px solid #999999; }");

    connectorLayout->addWidget(divider2);

    pokazania = new QLabel("Текущие показания:");
    pokazania->setStyleSheet("font-size: 28px; font-weight: bold; border: none;");

    connectorLayout->addWidget(pokazania);

    grid = new QGridLayout();
    grid->setHorizontalSpacing(60);
    grid->setVerticalSpacing(8);

    powerNameLbl = new QLabel("Мощность:");
    powerNameLbl->setStyleSheet("font-size: 26px; border: none;");

    powerValueLbl = new QLabel("0,006 кВт");
    powerValueLbl->setStyleSheet("font-size: 26px; font-weight: bold; border: none;");

    grid->addWidget(powerNameLbl, 0, 0);
    grid->addWidget(powerValueLbl, 0, 1);

    voltageNameLbl = new QLabel("Напряжение:");
    voltageNameLbl->setStyleSheet("font-size: 26px; border: none;");

    voltageValueLbl = new QLabel("226,8 В");
    voltageValueLbl->setStyleSheet("font-size: 26px; font-weight: bold; color: #2ecc71; border: none;");

    grid->addWidget(voltageNameLbl, 0, 2);
    grid->addWidget(voltageValueLbl, 0, 3);

    currentNameLbl = new QLabel("Ток:");
    currentNameLbl->setStyleSheet("font-size: 26px; border: none;");

    currentValueLbl = new QLabel("0,041 А");
    currentValueLbl->setStyleSheet("font-size: 26px; font-weight: bold; border: none;");

    grid->addWidget(currentNameLbl, 1, 0);
    grid->addWidget(currentValueLbl, 1, 1);

    energyNameLbl = new QLabel("Энергия:");
    energyNameLbl->setStyleSheet("font-size: 26px; border: none;");

    energyValueLbl = new QLabel("8 231,336 кВт*ч");
    energyValueLbl->setStyleSheet("font-size: 26px; font-weight: bold; border: none;");
    grid->addWidget(energyNameLbl, 1, 2);
    grid->addWidget(energyValueLbl, 1, 3);

    connectorLayout->addLayout(grid);
    diagFrameLayout->addWidget(connectorFrame);

    tabLayout->addWidget(diagFrame1);
    tabLayout->addSpacing(40);

//rs485
    dumpsFrame2 = MainWindow::createCardWidget();
    dumpsFrameLayout = new QVBoxLayout(dumpsFrame2);
    dumpsFrameLayout->addSpacing(15);

    dumpsLine = new QHBoxLayout();
    dumpsTitleLabel = new QLabel("Дампы RS485 обмена");
    dumpsTitleLabel->setStyleSheet("font-size: 32px; font-weight: bold; border: none;");

    dumpsLine->addWidget(dumpsTitleLabel);
    dumpsLine->addStretch();

    dumpsInfoLabel = new QLabel("Записей: 0/50   Всего: 0   Статус: \u274C Выключен");
    dumpsInfoLabel->setStyleSheet("font-size: 28px; color: #999999; border: none;");

    dumpsLine->addWidget(dumpsInfoLabel);
    dumpsLine->addSpacing(20);

    dumpBtn = new QPushButton("Обновить");
    dumpBtn->setStyleSheet(btn);
    connect(dumpBtn, SIGNAL(clicked()), this, SLOT(refreshDumps()));
    dumpsLine->addWidget(dumpBtn);

    dumpsFrameLayout->addLayout(dumpsLine);

    QFrame *divider3 = new QFrame();
    divider3->setFrameShape(QFrame::HLine);
    divider3->setStyleSheet("QFrame { border: none; border-top: 4px solid #999999; }");
    dumpsFrameLayout->addWidget(divider3);
    dumpsFrameLayout->addSpacing(50);

    dumpsLabel = new QLabel("Нет записей дампов");
    dumpsLabel->setAlignment(Qt::AlignCenter);
    dumpsLabel->setStyleSheet("font-size: 28px; font-style: italic; color: #888888; border: none;");
    dumpsFrameLayout->addWidget(dumpsLabel);
    dumpsFrameLayout->addSpacing(80);

    tabLayout->addWidget(dumpsFrame2);
    tabLayout->addStretch();

    return list;
}

QWidget *DiagnosticsWindow::createNetworkTab()
{
    QWidget *list = new QWidget();
    QVBoxLayout *tabLayout = new QVBoxLayout(list);
    tabLayout->addSpacing(30);

    paramGrid = new QGridLayout();

//Информация о модеме
    modem = MainWindow::createCardWidget();
    modemLayout = new QVBoxLayout(modem);
    modemLayout->setContentsMargins(20, 18, 20, 18);
    modemLayout->setSpacing(14);

    modemTitle = new QLabel("<font color='#f7b721'>\u2139</font> Информация о модеме");
    modemTitle->setStyleSheet("font-size: 32px; font-weight: bold; border: none;");

    modemLayout->addWidget(modemTitle);
    modemLayout->addSpacing(20);

    modemLayout->addWidget(new QLabel("<span style='color:gray;'>Производитель:</span> SIMCOM INCORPORATED"));
    modemLayout->addWidget(new QLabel("<span style='color:gray;'>Модель:</span> SIMCOM_SIM7600E-H"));
    modemLayout->addWidget(new QLabel("<span style='color:gray;'>Прошивка:</span> LE11B14SIM7600M22"));
    modemLayout->addWidget(new QLabel("<span style='color:gray;'>IMEI:</span> 868140079033697"));
    modemLayout->addStretch();

    modemLayout->addStretch();
    paramGrid->addWidget(modem, 0,0);

//Сигнал
    signal = MainWindow::createCardWidget();
    signalLayout = new QVBoxLayout(signal);
    signalLayout->setContentsMargins(20, 18, 20, 18);
    signalLayout->setSpacing(14);

    signalTitle = new QLabel("📶 Сигнал");
    signalTitle->setStyleSheet("font-size: 32px; font-weight: bold; border: none;");

    signalLayout->addWidget(signalTitle);
    signalLayout->addSpacing(20);

    sigGrid = new QGridLayout();

    QString pbStyle = "QProgressBar { border: none; background: #e0e0e0; height: 8px; border-radius: 4px; text-align: center; } "
                      "QProgressBar::chunk { background: #8bc34a; border-radius: 4px; }";

    const char* titles[] = {"RSSI:", "SINR:", "RSRP:", "RSRQ:"};
    const char* values[] = {"-57.5 dBm", "20 dB", "-73 dBm", "-29.6 dB"};
    const char* subs[] = {"Уровень принимаемого сигнала", "Отношение сигнал/помеха+шум", "Мощность опорного сигнала", "Качество опорного сигнала"};
    int progress[] = {80, 95, 75, 10};

    for(int i=0; i<4; i++)
    {
    QLabel *titleLbl = new QLabel(titles[i]);
    titleLbl->setStyleSheet("font-size: 30px; font-weight: bold; border: none;");
    sigGrid->addWidget(titleLbl, i*2, 0);

    QLabel *valLbl = new QLabel(values[i]);
    valLbl->setStyleSheet("font-size: 28px; border: none;");
    sigGrid->addWidget(valLbl, i*2, 1);

    pb = new QProgressBar();
    pb->setStyleSheet(pbStyle);
    pb->setValue(progress[i]);
    pb->setTextVisible(false);
    pb->setFixedSize(140, 20);
    sigGrid->addWidget(pb, i*2, 2, Qt::AlignLeft);

    subLabel = new QLabel(subs[i]);
    subLabel->setStyleSheet("color: gray; font-size: 26px; border: none;");
    sigGrid->addWidget(subLabel, i*2 + 1, 0, 1, 3);
    }
    signalLayout->addLayout(sigGrid);
    paramGrid->addWidget(signal, 0,1);

//подключение
    connection = MainWindow::createCardWidget();
    connectionLayout = new QVBoxLayout(connection);
    connectionLayout->setContentsMargins(20, 18, 20, 18);

    connectionTitle = new QLabel("🛜 Подключение");
    connectionTitle->setStyleSheet("font-size: 32px; font-weight: bold; border: none;");

    connectionLayout->addWidget(connectionTitle);
    connectionLayout->addSpacing(20);

    connectionLayout->addWidget(new QLabel("<span style='color:gray;'>Оператор:</span> MTS"));
    connectionLayout->addWidget(new QLabel("<span style='color:gray;'>Тип сети:</span> LTE"));
    connectionLayout->addWidget(new QLabel("<span style='color:gray;'>IP:</span> 10.142.3.208"));
    connectionLayout->addWidget(new QLabel("<span style='color:gray;'>DNS1:</span> 192.168.253.60"));
    connectionLayout->addWidget(new QLabel("<span style='color:gray;'>DNS2:</span> 192.168.253.70"));
    connectionLayout->addStretch();

    paramGrid->addWidget(connection, 0,2);
    paramGrid->setVerticalSpacing(40);

//режим сети
    network = MainWindow::createCardWidget();
    networkLayout= new QVBoxLayout(network);
    networkLayout->setContentsMargins(25, 20, 25, 20);

    networkTitle = new QLabel("Режим сети");
    networkTitle->setStyleSheet("font-size: 32px; font-weight: bold; border: none;");
    networkLayout->addWidget(networkTitle);

    QFrame *divider5 = new QFrame();
    divider5->setFrameShape(QFrame::HLine);
    divider5->setStyleSheet("QFrame { border: none; border-top: 4px solid #999999; }");
    networkLayout->addWidget(divider5);

    networkLayout->addSpacing(30);

    regime = new QLabel("Текущий режим:");
    regime->setAlignment(Qt::AlignCenter);
    regime->setStyleSheet("color: #888888; font-size: 28px; border: none;");

    load = new QLabel("Загрузка...");
    load->setAlignment(Qt::AlignCenter);
    load->setStyleSheet("font-size: 26px; font-weight: bold; border: none;");

    networkLayout->addWidget(regime);
    networkLayout->addWidget(load);
    networkLayout->addSpacing(30);

    QFrame *divider6 = new QFrame();
    divider6->setFrameShape(QFrame::HLine);
    divider6->setStyleSheet("QFrame { border: none; border-top: 4px solid #eeeeee; }");
    networkLayout->addWidget(divider6);
    networkLayout->addSpacing(30);

    available = new QLabel("Доступные сети:");
    available->setAlignment(Qt::AlignCenter);
    available->setStyleSheet("color: #888888; font-size: 28px; border: none;");

    load2 = new QLabel("Загрузка...");
    load2->setAlignment(Qt::AlignCenter);
    load2->setStyleSheet("font-size: 26px; font-weight: bold; border: none;");

    networkLayout->addWidget(available);
    networkLayout->addWidget(load2);
    networkLayout->addSpacing(30);

    modeComboBox = new QComboBox();
    modeComboBox->addItem("Загрузка режимов...");
    modeComboBox->setStyleSheet(
        "QComboBox { border: 1px solid #dddddd; border-radius: 8px; padding: 10px 15px; font-size: 30px;margin-left: -5px; }");
    networkLayout->addWidget(modeComboBox);

    applyBtn = new QPushButton("Применить режим");
    connect(applyBtn, SIGNAL(clicked()), this, SLOT(applyNetwork()));
    applyBtn->setStyleSheet(
        "QPushButton { background-color: #2f80ed; color: white; border-radius: 10px; padding: 15px 20px; font-size: 28px; }"
        "QPushButton:hover { background-color: #2569c4; }"
        "QPushButton:pressed { background-color: #1c559e; }");

    networkLayout->addWidget(applyBtn);
    paramGrid->addWidget(network, 1,0,1,3);

    tabLayout->addLayout(paramGrid);
    tabLayout->addStretch();

    return list;
}

void DiagnosticsWindow::refresh(){}

void DiagnosticsWindow::clear(){}

void DiagnosticsWindow::dumps()
{
    dumpsEnabled = !dumpsEnabled;
    if (dumpsEnabled) {
        btnDumps->setText("Выключить дампы");
        dumpsInfoLabel->setText("Записей: 0/50   Всего: 0   Статус: <span style='color: #2ecc71;'>\u2705 Включен</span>");
    } else {
        btnDumps->setText("Включить дампы");
        dumpsInfoLabel->setText("Записей: 0/50   Всего: 0   Статус: <span style='color: #e74c3c;'>\u274C Выключен</span>");
    }
}

void DiagnosticsWindow::refreshDumps(){}

void DiagnosticsWindow::applyNetwork(){}

