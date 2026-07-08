#include "configuration.h"
#include "mainwindow.h"
#include <QGraphicsDropShadowEffect>

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
    QFrame *card1 = MainWindow::createCardWidget();
    crd1= new QVBoxLayout(card1);
    lbl1 = new QLabel("Сетевой интерфейс");
    lbl1->setStyleSheet("font-size: 34px; font-weight: bold; border-bottom: 4px solid black; padding-bottom: 6px; margin-bottom: 8px;");
    crd1->addWidget(lbl1);

    interfaceLBL = new QLabel("Включённые интерфейсы:");
    crd1->addWidget(interfaceLBL);

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

    internetCon = new QLabel("Интернет по умолчанию");
    crd1->addWidget(internetCon);

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
    QFrame *card2 = MainWindow::createCardWidget();
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
    QFrame *card3 = MainWindow::createCardWidget();
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
    configLayout->addSpacing(20);

    //РЯД 2. лимиты и коннекторы
    QFrame *card4 = MainWindow::createCardWidget();
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

    power = new QCheckBox("Динамическое распределение мощности");
    crd4->addWidget(power);

    regime = new QLabel("Режим работы станции");
    crd4->addWidget(regime);

    regimeBox = new QComboBox();
    regimeBox->addItems({"Продакшн","Тест"});
    crd4->addWidget(regimeBox);

    debug = new QCheckBox("Режим отладки (эмулятор тока счётчика)");
    crd4->addWidget(debug);
    cable = new QCheckBox("Кабельная сборка (кабель постоянно в станции)");
    crd4->addWidget(cable);
    crd4->addStretch();

    //РЯД 2. Настройки коннекторов
    QFrame *card5 = MainWindow::createCardWidget();
    crd5= new QVBoxLayout(card5);
    lbl5 = new QLabel("Настройки коннекторов");
    lbl5->setStyleSheet("font-size: 34px; font-weight: bold; border-bottom: 4px solid black; padding-bottom: 6px; margin-bottom: 8px; ");
    crd5->addWidget(lbl5);

    // Внутренний контейнер
    connectorWidget = new QFrame();
    connectorWidget->setFrameShape(QFrame::NoFrame); // всё равно не работает нативно из-за стиля родителя — рисуем через QSS

    connectorWidget->setStyleSheet(
            "QFrame { border: 1px solid #cccccc; background: #f5f5f5; margin-left: 10px; border-radius: 0px; }"
            "QLabel { border: none; color: #333333; background: transparent; font-size: 28px; }"
            "QCheckBox { border: none; padding: 4px; color: #333333; font-size: 26px; }"
            "QSpinBox { border: 1px solid #cccccc; border-radius: 4px; padding: 6px; background-color: #ffffff; color: #333333; font-size: 28px; }");

    Vconnector = new QVBoxLayout(connectorWidget);

    lblConnector = new QLabel("Коннектор 1");
    lblConnector->setStyleSheet("font-weight: bold; font-size: 30px; border-bottom: 2px solid black; padding-bottom: 4px; margin-bottom: 8px;");
    Vconnector->addWidget(lblConnector);

    on = new QCheckBox("Включен");
    Vconnector->addWidget(on);

    modbus = new QLabel("Modbus адрес счётчика");
    Vconnector->addWidget(modbus);

    edtModbus = new QSpinBox();
    edtModbus->setValue(0);
    Vconnector->addWidget(edtModbus);

    counterOn = new QCheckBox("Счётчик включен");
    Vconnector->addWidget(counterOn);

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
    configLayout->addSpacing(20);

    //РЯД 3. RGB
    QFrame *card6 = MainWindow::createCardWidget();
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
    QFrame *card7 = MainWindow::createCardWidget();
    crd7= new QVBoxLayout(card7);
    lbl7 = new QLabel("Включение/отключение функций");
    lbl7->setStyleSheet("font-size: 34px; font-weight: bold; border-bottom: 4px solid black; padding-bottom: 6px; margin-bottom: 8px;");
    crd7->addWidget(lbl7);

    counter = new QLabel("Тип счётчика");
    crd7->addWidget(counter);

    edtCount = new QComboBox();
    edtCount->addItems({"Гран Электро", "CE318BY (SMP)", "CE301BY (ГОСТ 61107)"});
    crd7->addWidget(edtCount);
    door = new QCheckBox("Состояние двери");
    crd7->addWidget(door);
    stop = new QCheckBox("Аварийный СТОП");
    crd7->addWidget(stop);
    current = new QCheckBox("Датчик утечки тока (R01)");
    crd7->addWidget(current);
    crd7->addStretch();

    row3Layout->addWidget(card6, 1);
    row3Layout->addWidget(card7, 1);
    configLayout->addLayout(row3Layout);
    configLayout->addSpacing(20);

    //кнопки
    btnLayout = new QHBoxLayout();
    btnLayout->setSpacing(30);
    btnLayout->setAlignment(Qt::AlignCenter);

    save = new QPushButton("Сохранить");
    load = new QPushButton("Загрузить конфигурацию");

    QString buttonStyle =
        "QPushButton { border: 2px solid #000000; background-color: grey; color: white; border-radius: 20px; padding: 20px 50px; font-size: 38px}"
        "QPushButton:hover {background-color: #5c6373 }"
        "QPushButton:pressed {background-color: black }";

    save->setStyleSheet(buttonStyle);
    load->setStyleSheet(buttonStyle);

    btnLayout->addWidget(save);
    btnLayout->addWidget(load);
    connect(save, SIGNAL(clicked()), this, SLOT(onSave()));
    connect(load, SIGNAL(clicked()), this, SLOT(onLoad()));

    configLayout->addLayout(btnLayout);

    scrollArea->setWidget(scrollContent);
    outLayout->addWidget(scrollArea);
}

CongigWindow::~CongigWindow(){}

void CongigWindow::onSave()
{
    QJsonObject root;

    //Сетевой интерфейс
    QJsonObject network;
    network["interface"] = g3->isChecked() ? "3G модем" : (lan->isChecked() ? "LAN" : "");
    network["defaultInternet"] = internetBox->currentText();
    network["wifiSSID"] = EDTwifiSSID->text();
    network["wifiPASS"] = EDTwifiPASS->text();
    root["network"] = network;

    //Станция
    QJsonObject station;
    station["id"] = edtID->text();
    station["serialNumber"] = edtSerialNum->text();
    station["rowNumber"] = edtRowNum->text();
    station["place"] = edtPlace->text();
    root["station"] = station;

    //Соединение
    QJsonObject connection;
    connection["ocppServer"] = edtServer->text();
    connection["apn"] = edtApn->text();
    connection["pin"] = edtPin->text();
    root["connection"] = connection;

    //Лимиты и коннекторы
    QJsonObject limits;
    limits["currentLimitA"] = edtLim->value();
    limits["connectorCount"] = edtConnector->value();
    limits["dynamicPowerDistribution"] = power->isChecked();
    limits["mode"] = regimeBox->currentText();
    limits["debugMode"] = debug->isChecked();
    limits["cablePermanentlyAttached"] = cable->isChecked();
    root["limits"] = limits;

    //Настройки
    QJsonObject connector1;
    connector1["enabled"] = on->isChecked();
    connector1["modbusAddress"] = edtModbus->value();
    connector1["meterEnabled"] = counterOn->isChecked();
    connector1["pollIntervalMs"] = edtInterval->value();
    root["connector1"] = connector1;

    //RGB
    QJsonObject rgb;
    rgb["currentLedCount"] = edtKol->value();
    rgb["maxLedCount"] = edtMaxKol->value();
    root["rgb"] = rgb;

    //Вкл/выкл функций
    QJsonObject features;
    features["meterType"] = edtCount->currentText();
    features["doorState"] = door->isChecked();
    features["emergencyStop"] = stop->isChecked();
    features["leakSensorR01"] = current->isChecked();
    root["features"] = features;

    //Запись в файл
    QString defaultDir = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString defaultPath = defaultDir + "/config.json";

    QString filePath = QFileDialog::getSaveFileName(this, "Сохранить конфигурацию",defaultPath,"JSON файлы (*.json);;Все файлы (*)" );

        if (filePath.isEmpty()) {
            // Пользователь отменил диалог
            return;
        }

        if (!filePath.endsWith(".json", Qt::CaseInsensitive)) {
            filePath += ".json";
        }

        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для записи:\n" + filePath);
            return;
        }

        QJsonDocument doc(root);
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();

        QMessageBox::information(this, "Сохранено", "Конфигурация сохранена:\n" + filePath);
}

void CongigWindow::onLoad()
{
    QString defaultDir = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);

    QString filePath = QFileDialog::getOpenFileName(this, "Загрузить конфигурацию",defaultDir,"JSON файлы (*.json);;Все файлы (*)");

    if (filePath.isEmpty()) {
        // Пользователь отменил диалог
        return;
    }

    QFile file(filePath);
    if (!file.exists()) {
        QMessageBox::warning(this, "Ошибка", "Файл конфигурации не найден:\n" + filePath);
        return;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для чтения:\n" + filePath);
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        QMessageBox::warning(this, "Ошибка", "Ошибка разбора JSON:\n" + parseError.errorString());
        return;
    }

    if (!doc.isObject()) {
        QMessageBox::warning(this, "Ошибка", "Некорректный формат файла конфигурации");
        return;
    }

    QJsonObject root = doc.object();

    //Сетевой интерфейс
    QJsonObject network = root["network"].toObject();
    QString iface = network["interface"].toString();
    if (iface == "3G модем") {
        g3->setChecked(true);
    } else if (iface == "LAN") {
        lan->setChecked(true);
    }
    internetBox->setCurrentText(network["defaultInternet"].toString());
    EDTwifiSSID->setText(network["wifiSSID"].toString());
    EDTwifiPASS->setText(network["wifiPASS"].toString());

    //Станция
    QJsonObject station = root["station"].toObject();
    edtID->setText(station["id"].toString());
    edtSerialNum->setText(station["serialNumber"].toString());
    edtRowNum->setText(station["rowNumber"].toString());
    edtPlace->setText(station["place"].toString());

    //Соединение
    QJsonObject connection = root["connection"].toObject();
    edtServer->setText(connection["ocppServer"].toString());
    edtApn->setText(connection["apn"].toString());
    edtPin->setText(connection["pin"].toString());

    //Лимиты и коннекторы
    QJsonObject limits = root["limits"].toObject();
    edtLim->setValue(limits["currentLimitA"].toInt());
    edtConnector->setValue(limits["connectorCount"].toInt());
    power->setChecked(limits["dynamicPowerDistribution"].toBool());
    regimeBox->setCurrentText(limits["mode"].toString());
    debug->setChecked(limits["debugMode"].toBool());
    cable->setChecked(limits["cablePermanentlyAttached"].toBool());

    //Настройки
    QJsonObject connector1 = root["connector1"].toObject();
    on->setChecked(connector1["enabled"].toBool());
    edtModbus->setValue(connector1["modbusAddress"].toInt());
    counterOn->setChecked(connector1["meterEnabled"].toBool());
    edtInterval->setValue(connector1["pollIntervalMs"].toInt());

    //RGB
    QJsonObject rgb = root["rgb"].toObject();
    edtKol->setValue(rgb["currentLedCount"].toInt());
    edtMaxKol->setValue(rgb["maxLedCount"].toInt());

    //Вкл/выкл функций
    QJsonObject features = root["features"].toObject();
    edtCount->setCurrentText(features["meterType"].toString());
    door->setChecked(features["doorState"].toBool());
    stop->setChecked(features["emergencyStop"].toBool());
    current->setChecked(features["leakSensorR01"].toBool());

    QMessageBox::information(this, "Загружено", "Конфигурация успешно загружена");
}
