#include "configuration.h"

CongigWindow::CongigWindow(QWidget *parent) : QWidget(parent) {

    outLayout = new QVBoxLayout(this);
    outLayout->setContentsMargins(0, 0, 0, 0);

    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setFrameShape(QFrame::NoFrame);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scrollContent = new QWidget();
    configLayout = new QVBoxLayout(scrollContent);
    configLayout->setContentsMargins(0, 0, 10, 0);
    configLayout->setSpacing(20);

    row1Layout = new QHBoxLayout();
    row2Layout = new QHBoxLayout();
    row3Layout = new QHBoxLayout();
    row1Layout->setSpacing(15);
    row2Layout->setSpacing(15);
    row3Layout->setSpacing(15);

    //РЯД 1.сетевой интерфейс
    QWidget *card1 = createCardWidget();
    crd1= new QVBoxLayout(card1);
    lbl1 = new QLabel("Сетевой интерфейс");
    lbl1->setStyleSheet("font-size: 34px; font-weight: bold; border-bottom: 4px solid black; padding-bottom: 6px; margin-bottom: 8px;");
    crd1->addWidget(lbl1);

    interface = new QLabel("Включённые интерфейсы:");
    crd1->addWidget(interface);

    g3 = new QRadioButton("3G модем");
    crd1->addWidget(g3);

    lan = new QRadioButton("LAN");
    crd1->addWidget(lan);

    group = new QButtonGroup();
    group->addButton(g3);
    group->addButton(lan);

    LAN = new QLabel("LAN можно оставить включённым для терминала, а интернет направить через выбранный uplink.");
    LAN->setWordWrap(true);
    LAN->setStyleSheet("font-style: italic; font-size: 24px;color: black");
    crd1->addWidget(LAN);

    internet = new QLabel("Интернет по умолчанию");
    crd1->addWidget(internet);

    internetBox = new QComboBox();
    internetBox->addItems({"3G модем", "LAN", "Wi-Fi"});
    crd1->addWidget(internetBox);

    wifiSSID = new QLabel("WI-FI SSID");
    crd1->addWidget(wifiSSID);

    EDTwifiSSID = new QLineEdit();
    EDTwifiSSID->setText("MOD_3_MALANKA");
    crd1->addWidget(EDTwifiSSID);

    wifiPASS = new QLabel("WI-FI PASS");
    crd1->addWidget(wifiPASS);

    EDTwifiPASS = new QLineEdit();
    EDTwifiPASS->setEchoMode(QLineEdit::Password);
    EDTwifiPASS->setPlaceholderText("Введите пароль");
    crd1->addWidget(EDTwifiPASS);
    crd1->addStretch();

    //РЯД 1.станция
    QWidget *card2 = createCardWidget();
    crd2= new QVBoxLayout(card2);
    lbl2 = new QLabel("Станция");
    lbl2->setStyleSheet("font-size: 34px; font-weight: bold; border-bottom: 4px solid black; padding-bottom: 6px; margin-bottom: 8px;");
    crd2->addWidget(lbl2);

    id= new QLabel("ID станции");
    crd2->addWidget(id);

    edtID = new QLineEdit();
    edtID->setText("700577312711");
    crd2->addWidget(edtID);

    serialNum= new QLabel("Серийный номер");
    crd2->addWidget(serialNum);

    edtSerialNum = new QLineEdit();
    edtSerialNum->setText("250410006");
    crd2->addWidget(edtSerialNum);

    rowNum= new QLabel("Номер столбика");
    crd2->addWidget(rowNum);

    edtRowNum = new QLineEdit();
    edtRowNum->setText("1");
    crd2->addWidget(edtRowNum);

    place= new QLabel("Место установки");
    crd2->addWidget(place);

    edtPlace = new QLineEdit();
    edtPlace->setText("Минск, Берсона, 14");
    crd2->addWidget(edtPlace);
    crd2->addStretch();

    //РЯД 1.соединение
    QWidget *card3 = createCardWidget();
    crd3= new QVBoxLayout(card3);
    lbl3 = new QLabel("Соединение");
    lbl3->setStyleSheet("font-size: 34px; font-weight: bold; border-bottom: 4px solid black; padding-bottom: 6px; margin-bottom: 8px;");
    crd3->addWidget(lbl3);

    server= new QLabel("Адресс OCPP сервера");
    crd3->addWidget(server);

    edtServer = new QLineEdit();
    edtServer->setText("ws://192.168.253.201:81/");
    crd3->addWidget(edtServer);

    apn= new QLabel("APN");
    crd3->addWidget(apn);

    edtApn = new QLineEdit();
    edtApn->setText("vpn");
    crd3->addWidget(edtApn);

    pin = new QLabel("PIN-код");
    crd3->addWidget(pin);

    edtPin = new QLineEdit();
    edtPin->setEchoMode(QLineEdit::Password);
    edtPin->setPlaceholderText("Введите PIN-код");
    crd3->addWidget(edtPin);
    crd3->addStretch();

    row1Layout->addWidget(card1);
    row1Layout->addWidget(card2);
    row1Layout->addWidget(card3);

    configLayout->addLayout(row1Layout);

    //РЯД 2. лимиты и коннекторы
    QWidget *card4 = createCardWidget();
    crd4= new QVBoxLayout(card4);
    lbl4 = new QLabel("Лимиты и коннекторы");
    lbl4->setStyleSheet("font-size: 34px; font-weight: bold; border-bottom: 4px solid black; padding-bottom: 6px; margin-bottom: 8px;");
    crd4->addWidget(lbl4);

    lim = new QLabel("Лимит станции (А)");
    crd4->addWidget(lim);

    edtLim = new QSpinBox();
    edtLim->setValue(32);
    crd4->addWidget(edtLim);

    connector = new QLabel("Количество коннекторов");
    crd4->addWidget(connector);

    edtConnector = new QSpinBox();
    edtConnector->setValue(1);
    crd4->addWidget(edtConnector);

    crd4->addWidget(new QCheckBox("Динамическое распределение мощности"));

    regime = new QLabel("Режим работы станции");
    crd4->addWidget(regime);

    regimeBox = new QComboBox();
    regimeBox->addItems({"Продакшн","Тест"});
    crd4->addWidget(regimeBox);

    crd4->addWidget(new QCheckBox("Режим отладки (эмулятор тока счётчика)"));
    crd4->addWidget(new QCheckBox("Кабельная сборка (кабель постоянно в станции)"));
    crd4->addStretch();

    //РЯД 2. Настройки коннекторов
    QWidget *card5 = createCardWidget();
    crd5= new QVBoxLayout(card5);
    lbl5 = new QLabel("Настройки коннекторов");
    lbl5->setStyleSheet("font-size: 34px; font-weight: bold; border-bottom: 4px solid black; padding-bottom: 6px; margin-bottom: 8px; ");
    crd5->addWidget(lbl5);

    // Внутренний контейнер
    connectorWidget = new QWidget();
    connectorWidget->setStyleSheet("QWidget { border: 1px solid #e0e0e0; border-radius: 4px; background: #fafafa;margin-left: 10px; }  "
                                   "QLabel { border: none; color: #333333; background: transparent; font-size: 28px; }"
                                   "QCheckBox { border: none; padding: 4px; color: #333333; font-size: 26px; }"
                                   "QSpinBox { border:1px solid #cccccc; border-radius: 4px; padding: 6px; background-color: #ffffff; color: #333333; font-size: 28px; }");

    Vconnector = new QVBoxLayout(connectorWidget);

    lblConnector = new QLabel("Коннектор 1");
    lblConnector->setStyleSheet("font-weight: bold; font-size: 30px; border-bottom: 2px solid black; padding-bottom: 4px; margin-bottom: 8px;");
    Vconnector->addWidget(lblConnector);

    Vconnector->addWidget(new QCheckBox("Включен"));

    modbus = new QLabel("Modbus адрес счётчика");
    Vconnector->addWidget(modbus);

    edtModbus = new QSpinBox();
    edtModbus->setValue(0);
    Vconnector->addWidget(edtModbus);

    Vconnector->addWidget(new QCheckBox("Счётчик включен"));

    interval = new QLabel("Интервал опроса (мс)");
    Vconnector->addWidget(interval);

    edtInterval = new QSpinBox();
    edtInterval->setRange(0, 100000);
    edtInterval->setValue(1000);
    Vconnector->addWidget(edtInterval);

    crd5->addWidget(connectorWidget);
    crd5->addStretch();

    row2Layout->addWidget(card4, 1);
    row2Layout->addWidget(card5, 1);
    configLayout->addLayout(row2Layout);

    //РЯД 3. RGB
    QWidget *card6 = createCardWidget();
    crd6= new QVBoxLayout(card6);
    lbl6 = new QLabel("RGB");
    lbl6->setStyleSheet("font-size: 34px; font-weight: bold; border-bottom: 4px solid black; padding-bottom: 6px; margin-bottom: 8px;");
    crd6->addWidget(lbl6);

    kol = new QLabel("Текущее количество светодиодов");
    crd6->addWidget(kol);

    edtKol = new QSpinBox();
    edtKol->setRange(0, 120);
    edtKol->setValue(93);
    crd6->addWidget(edtKol);

    maxKol = new QLabel("Максимально допустимое количество светодиодов");
    crd6->addWidget(maxKol);

    edtMaxKol = new QSpinBox();
    edtMaxKol->setRange(0, 120);
    edtMaxKol->setValue(93);
    crd6->addWidget(edtMaxKol);
    crd6->addStretch();

    //РЯД 3. вкл/выкл
    QWidget *card7 = createCardWidget();
    crd7= new QVBoxLayout(card7);
    lbl7 = new QLabel("Включение/отключение функций");
    lbl7->setStyleSheet("font-size: 34px; font-weight: bold; border-bottom: 4px solid black; padding-bottom: 6px; margin-bottom: 8px;");
    crd7->addWidget(lbl7);

    counter = new QLabel("Тип счётчика");
    crd7->addWidget(counter);

    edtCount = new QComboBox();
    edtCount->addItems({"Гран Электро", "CE318BY (SMP)", "CE301BY (ГОСТ 61107)"});
    crd7->addWidget(edtCount);
    crd7->addWidget(new QCheckBox("Состояние двери"));
    crd7->addWidget(new QCheckBox("Аварийный СТОП"));
    crd7->addWidget(new QCheckBox("Датчик утечки тока (R01)"));
    crd7->addStretch();

    row3Layout->addWidget(card6, 1);
    row3Layout->addWidget(card7, 1);
    configLayout->addLayout(row3Layout);

    //кнопки
    btnLayout = new QHBoxLayout();
    btnLayout->setSpacing(30);
    btnLayout->setAlignment(Qt::AlignCenter);

    save = new QPushButton("Сохранить");
    load = new QPushButton("Загрузить конфигурацию");

    QString buttonStyle =
        "QPushButton { border: 2px solid #000000; background-color: grey; color: white; border-radius: 4px; padding: 10px 36px; font-size: 34px}"
        "QPushButton:hover {background-color: #5c6373 }"
        "QPushButton:pressed {background-color: black }";

    save->setStyleSheet(buttonStyle);
    load->setStyleSheet(buttonStyle);

    btnLayout->addWidget(save);
    btnLayout->addWidget(load);

    configLayout->addLayout(btnLayout);

    scrollArea->setWidget(scrollContent);
    outLayout->addWidget(scrollArea);
}

CongigWindow::~CongigWindow(){}

QWidget* CongigWindow::createCardWidget()
{
    card = new QWidget();
    card->setStyleSheet(
        "QWidget { border: 1px solid #000000; background-color: #fcf9f9; border-radius: 10px; }"
        "QLabel { border: none; color: #333333; font-size: 32px; margin-left: 30px; }"
        "QLineEdit, QComboBox, QSpinBox { border: 1px solid #cccccc; border-radius: 4px; padding: 6px; background-color: #ffffff; color: #333333; font-size: 28px; margin-left: 45px;}"
        "QLineEdit:focus, QComboBox:focus, QSpinBox:focus { border: 1px solid #0056b3; }"
        "QCheckBox { border: none; padding: 4px; color: #333333; font-size: 26px; margin-left: 45px; }"
        "QRadioButton { border: none; padding: 4px; color: #333333; font-size: 26px; margin-left: 40px; }"
        "QSpinBox::up-button, QSpinBox::down-button { border: none; background: transparent; }"
        "QComboBox QAbstractItemView {background-color: #ffffff; border: 1px solid #cccccc; }");
    return card;
}


