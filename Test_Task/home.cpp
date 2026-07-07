#include "home.h"
#include "mainwindow.h"

homeWindow::homeWindow(QWidget *parent): QWidget{parent}
{
    homeLayout = new QVBoxLayout(this);
    homeLayout->setContentsMargins(0, 0, 0, 0);
    homeLayout->setSpacing(20);

    row1 = new QHBoxLayout();
    row2 = new QHBoxLayout();
    row3 = new QHBoxLayout();
    row1->setSpacing(15);
    row2->setSpacing(15);
    row3->setSpacing(15);

//  РЯД 1. Станция 1
    QFrame *cardHome1 = MainWindow::createCardWidget();
    crd1Layout = new QVBoxLayout(cardHome1);

    namecard1 = new QHBoxLayout();
    label1 = new QLabel("Станция: #1");
    label1->setStyleSheet("font-size: 34px; font-weight: bold; border-bottom: 4px solid black; padding-bottom: 6px; margin-bottom: 8px;");
    namecard1->addWidget(label1);
    namecard1->addStretch();

    finish = new QLabel( "finishing");
    finish->setStyleSheet("color: #000000; font-size: 30px; font-style: italic; ");
    namecard1->addWidget(finish);

    pixLbl = new QLabel();
    pixLbl->setStyleSheet("background-color: #defcd3");
    QPixmap pixmap(":/new/prefix1/finishing.png");
    QPixmap scaledPixmap = pixmap.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    pixLbl->setPixmap(scaledPixmap);
    namecard1->addWidget(pixLbl);

    crd1Layout->addLayout(namecard1);
    crd1Layout->addSpacing(20);

    edtLocation = new QTextEdit();
    edtLocation->setReadOnly(true);
    edtLocation->setMaximumHeight(70);
    crd1Layout->addWidget(edtLocation);

    //Строка состояния
    statsLayout = new QHBoxLayout();
    statsLayout->setSpacing(15);

    avgTime = new QFrame();
    avgTime->setStyleSheet("QFrame { background-color: #f5f5f5; border-radius: 10px; }");
    avgTimeLayout = new QVBoxLayout(avgTime);

    avgTimeName = new QLabel("Среднее время зарядки");
    avgTimeName->setStyleSheet("color: #888888; font-size: 28px; border: none;");
    avgTimeLayout->addWidget(avgTimeName);

    avgTimeValue = new QLabel("2ч 2м");
    avgTimeValue->setStyleSheet("font-size: 30px; font-weight: bold; border: none;");
    avgTimeLayout->addWidget(avgTimeValue);

    statsLayout->addWidget(avgTime, 1);

    avgPower = new QFrame();
    avgPower->setStyleSheet("QFrame { background-color: #f5f5f5; border-radius: 10px; }");
    avgPowerLayout = new QVBoxLayout(avgPower);

    avgPowerName = new QLabel("Средняя мощность");
    avgPowerName->setStyleSheet("color: #888888; font-size: 28px; border: none;");
    avgPowerLayout->addWidget(avgPowerName);

    avgPowerValue = new QLabel("5.77 кВт");
    avgPowerValue->setStyleSheet("font-size: 30px; font-weight: bold; border: none;");
    avgPowerLayout->addWidget(avgPowerValue);

    statsLayout->addWidget(avgPower, 1);

    btnLayout = new QVBoxLayout();
    btnLayout->setSpacing(10);

    QString button =
        "QPushButton { background-color: #2b2b33; color: white; border-radius: 6px; padding: 10px 20px; font-size: 22px; }"
        "QPushButton:hover { background-color: #40404a; }"
        "QPushButton:pressed { background-color: #1a1a1f; }";

    softBtn = new QPushButton("SOFT RESET");
    softBtn->setStyleSheet(button);
    btnLayout->addWidget(softBtn);

    hardBtn = new QPushButton("HARD RESET");
    hardBtn->setStyleSheet(button);
    btnLayout->addWidget(hardBtn);

    statsLayout->addLayout(btnLayout, 1);

    crd1Layout->addLayout(statsLayout);

    crd1Layout->addSpacing(20);
    labelError = new QLabel("Панель ошибок станции");
    labelError->setStyleSheet("font-size: 28px; font-weight: bold; border-bottom: 4px solid black; padding-bottom: 6px; margin-bottom: 8px;");
    crd1Layout->addWidget(labelError);

    // Статус станции
    statusLayout = new QHBoxLayout();
    statusLayout->setSpacing(8);

    statusIcon = new QLabel();
    QPixmap okPixmap(":/new/prefix1/ok.png");
    QPixmap scaledOkPixmap = okPixmap.scaled(30, 30, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    statusIcon->setPixmap(scaledOkPixmap);
    statusLayout->addWidget(statusIcon);

    statusText = new QLabel("Станция технически исправна");
    statusText->setStyleSheet("font-style: italic; font-size: 26px; border: none;");
    statusLayout->addWidget(statusText);
    statusLayout->addStretch();

    crd1Layout->addLayout(statusLayout);
    row1->addWidget(cardHome1);
    homeLayout->addLayout(row1);
    homeLayout->addSpacing(20);
    crd1Layout->addStretch();

//РЯД 1. коннектор
    QFrame *cardHome2 = MainWindow::createCardWidget();
    crd2Layout = new QVBoxLayout(cardHome2);

    namecard2 = new QHBoxLayout();
    label2 = new QLabel("Коннектор: 1");
    label2->setStyleSheet("font-size: 34px; font-weight: bold; border-bottom: 4px solid black; padding-bottom: 6px; margin-bottom: 8px;");
    namecard2->addWidget(label2);
    namecard2->addStretch();

    finish2 = new QLabel( "finishing");
    finish2->setStyleSheet("color: #000000; font-size: 30px; font-style: italic; ");
    namecard2->addWidget(finish2);

    pixLbl2 = new QLabel();
    pixLbl2->setStyleSheet("background-color: #defcd3");
    QPixmap pixmap2(":/new/prefix1/finishing.png");
    QPixmap scaledPixmap2 = pixmap2.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    pixLbl2->setPixmap(scaledPixmap2);
    namecard2->addWidget(pixLbl2);

    crd2Layout->addLayout(namecard2);
    crd2Layout->addSpacing(20);
    row1->addWidget(cardHome2);

    param1 = new QGridLayout();
    param1->setSpacing(15);

    power = new QFrame();
    power->setStyleSheet("QFrame { background-color: #f5f5f5; border-radius: 10px; }");
    powerLayout = new QVBoxLayout(power);

    powerName = new QLabel("Мощность");
    powerName->setStyleSheet("color: #888888; font-size: 28px; border: none;");
    powerLayout->addWidget(powerName);

    powerValue = new QLabel("0,01 кВт");
    powerValue->setStyleSheet("font-size: 30px; font-weight: bold; border: none;");
    powerLayout->addWidget(powerValue);

    param1->addWidget(power, 0,0);

    voltage = new QFrame();
    voltage->setStyleSheet("QFrame { background-color: #f5f5f5; border-radius: 10px; }");
    voltageLayout = new QVBoxLayout(voltage);

    voltageName = new QLabel("Напряжение");
    voltageName->setStyleSheet("color: #888888; font-size: 28px; border: none;");
    voltageLayout->addWidget(voltageName);

    voltageValue = new QLabel("228,7 В");
    voltageValue->setStyleSheet("font-size: 30px; font-weight: bold; border: none;");
    voltageLayout->addWidget(voltageValue);

    param1->addWidget(voltage, 0,1);

    current = new QFrame();
    current->setStyleSheet("QFrame { background-color: #f5f5f5; border-radius: 10px; }");
    currentLayout = new QVBoxLayout(current);

    currentName = new QLabel("Ток");
    currentName->setStyleSheet("color: #888888; font-size: 28px; border: none;");
    currentLayout->addWidget(currentName);

    currentValue = new QLabel("0,0 А");
    currentValue->setStyleSheet("font-size: 30px; font-weight: bold; border: none;");
    currentLayout->addWidget(currentValue);

    param1->addWidget(current, 1,0);

    received = new QFrame();
    received->setStyleSheet("QFrame { background-color: #f5f5f5; border-radius: 10px; }");
    receivedLayout = new QVBoxLayout(received);

    receivedName = new QLabel("Получено");
    receivedName->setStyleSheet("color: #888888; font-size: 28px; border: none;");
    receivedLayout->addWidget(receivedName);

    receivedValue = new QLabel("8231,33 кВт*ч");
    receivedValue->setStyleSheet("font-size: 30px; font-weight: bold; border: none;");
    receivedLayout->addWidget(receivedValue);

    param1->addWidget(received, 1,1);

    status = new QFrame();
    status->setStyleSheet("QFrame { background-color: #f5f5f5; border-radius: 10px; }");
    statusLayout1 = new QHBoxLayout(status);

    statusTextLayout = new QVBoxLayout();

    statusName = new QLabel("Состояние коннектора");
    statusName->setStyleSheet("color: #888888; font-size: 28px; border: none;");
    statusTextLayout->addWidget(statusName);

    statusValue = new QLabel("Lock");
    statusValue->setStyleSheet("font-size: 30px; font-weight: bold; border: none;");
    statusTextLayout->addWidget(statusValue);
    statusTextLayout->addStretch();

    statusLayout1->addLayout(statusTextLayout);
    statusLayout1->addStretch();

    icon = new QLabel();
    icon->setStyleSheet("background-color: #fef3d6; border-radius: 30px; qproperty-alignment: 'AlignCenter';");
    icon->setAlignment(Qt::AlignCenter);
    QPixmap lockPixmap(":/new/prefix1/lock.png");
    QPixmap scaledLockPixmap = lockPixmap.scaled(90, 90, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    icon->setPixmap(scaledLockPixmap);
    statusLayout1->addWidget(icon);

    param1->addWidget(status, 2,0);

    unlockBtn = new QPushButton("Разблокировать\nконнектор");
    unlockBtn->setFixedWidth(400);
    unlockBtn->setStyleSheet(
                "QPushButton { border: 2px solid #000000; background-color: grey; color: white; border-radius: 20px; padding: 20px 50px; font-size: 30px}"
                "QPushButton:hover {background-color: #5c6373 }"
                "QPushButton:pressed {background-color: black }");

    param1->addWidget(unlockBtn, 2, 1, Qt::AlignRight | Qt::AlignVCenter);
    connect(unlockBtn, SIGNAL(clicked()), this,SLOT(unlock()));

    param1->setRowStretch(3, 1);
    crd2Layout->addLayout(param1);
    crd2Layout->addStretch();

//РЯД 2. память
    QFrame *cardHome3 = MainWindow::createCardWidget();
    crd3Layout = new QVBoxLayout(cardHome3);

    namecard3 = new QHBoxLayout();
    label3 = new QLabel("Информация о памяти");
    label3->setStyleSheet("font-size: 34px; font-weight: bold; border-bottom: 4px solid black; padding-bottom: 6px; margin-bottom: 8px;");
    namecard3->addWidget(label3);
    namecard3->addStretch();

    btnSinhr = new QPushButton();
    QIcon sinhrIcon(":/new/prefix1/sinhr.png");
    btnSinhr->setIcon(sinhrIcon);
    namecard3->addWidget(btnSinhr);

    crd3Layout->addLayout(namecard3);
    crd3Layout->addSpacing(20);

    row2->addWidget(cardHome3);
    homeLayout->addLayout(row2);
    homeLayout->addSpacing(20);

    memoryLayout = new QHBoxLayout();
    memoryLayout->setSpacing(15);

    QString barStyle =
                "QProgressBar { border: none; background-color: #e8e8e8; height: 14px; border-radius: 8px; }"
                "QProgressBar::chunk { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #2ecc71 , stop:1 #9ddf07); border-radius: 6px; }";

    flash = new QFrame();
    flash->setStyleSheet("QFrame { background-color: #f5f5f5; border-radius: 10px; }");
    flash->setFixedSize(435, 200);
    flashLayout = new QVBoxLayout(flash);

    flashName = new QLabel("FLASH");
    flashName->setStyleSheet("font-size: 24px; font-weight: bold; color: #2b2b33; border: none;");

    flashBar = new QProgressBar();
    flashBar->setTextVisible(false);
    flashBar->setStyleSheet(barStyle);
    flashBar->setMaximum(1600);
    flashBar->setValue(575);

    flashLbl = new QHBoxLayout();
    flashFree = new QLabel("Свободно: 10.25 МБ");
    flashFree->setStyleSheet("color: #888888; font-size: 20px; border: none;");
    flashUsed = new QLabel("5.75 МБ / 16 МБ");
    flashUsed->setStyleSheet("color: #888888; font-size: 20px; border: none;");
    flashLbl->addWidget(flashFree);
    flashLbl->addStretch();
    flashLbl->addWidget(flashUsed);

    flashLayout->addWidget(flashName);
    flashLayout->addWidget(flashBar);
    flashLayout->addLayout(flashLbl);
    memoryLayout->addWidget(flash, 1);

    dram = new QFrame();
    dram->setStyleSheet("QFrame { background-color: #f5f5f5; border-radius: 10px; }");
    dram->setFixedSize(435, 200);
    dramLayout = new QVBoxLayout(dram);

    dramName = new QLabel("DRAM");
    dramName->setStyleSheet("font-size: 24px; font-weight: bold; color: #2b2b33; border: none;");

    dramBar = new QProgressBar();
    dramBar->setTextVisible(false);
    dramBar->setStyleSheet(barStyle);
    dramBar->setMaximum(4266);
    dramBar->setValue(3106);

    dramLbl = new QHBoxLayout();
    dramFree = new QLabel("Свободно: 116 КБ");
    dramFree->setStyleSheet("color: #888888; font-size: 20px; border: none;");
    dramUsed = new QLabel("310.6 КБ / 426.6 КБ");
    dramUsed->setStyleSheet("color: #888888; font-size: 20px; border: none;");
    dramLbl->addWidget(dramFree);
    dramLbl->addStretch();
    dramLbl->addWidget(dramUsed);

    dramLayout->addWidget(dramName);
    dramLayout->addWidget(dramBar);
    dramLayout->addLayout(dramLbl);
    memoryLayout->addWidget(dram, 1);

    iram = new QFrame();
    iram->setStyleSheet("QFrame { background-color: #f5f5f5; border-radius: 10px; }");
    iram->setFixedSize(435, 200);
    iramLayout = new QVBoxLayout(iram);

    iramName = new QLabel("IRAM");
    iramName->setStyleSheet("font-size: 24px; font-weight: bold; color: #2b2b33; border: none;");

    iramBar = new QProgressBar();
    iramBar->setTextVisible(false);
    iramBar->setStyleSheet(barStyle);
    iramBar->setMaximum(244);
    iramBar->setValue(113);

    iramLbl = new QHBoxLayout();
    iramFree = new QLabel("Свободно: 1.3 МБ");
    iramFree->setStyleSheet("color: #888888; font-size: 20px; border: none;");
    iramUsed = new QLabel("1.13 МБ / 2.44 МБ");
    iramUsed->setStyleSheet("color: #888888; font-size: 20px; border: none;");
    iramLbl->addWidget(iramFree);
    iramLbl->addStretch();
    iramLbl->addWidget(iramUsed);

    iramLayout->addWidget(iramName);
    iramLayout->addWidget(iramBar);
    iramLayout->addLayout(iramLbl);
    memoryLayout->addWidget(iram, 1);

    psram = new QFrame();
    psram->setStyleSheet("QFrame { background-color: #f5f5f5; border-radius: 10px; }");
    psram->setFixedSize(435, 200);
    psramLayout = new QVBoxLayout(psram);

    psramName = new QLabel("PSRAM");
    psramName->setStyleSheet("font-size: 24px; font-weight: bold; color: #2b2b33; border: none;");

    psramBar = new QProgressBar();
    psramBar->setTextVisible(false);
    psramBar->setStyleSheet(barStyle);
    psramBar->setMaximum(200);
    psramBar->setValue(82);

    psramLbl = new QHBoxLayout();
    psramFree = new QLabel("Свободно: 1.19 МБ");
    psramFree->setStyleSheet("color: #888888; font-size: 20px; border: none;");
    psramUsed = new QLabel("824.36 КБ / 2 МБ");
    psramUsed->setStyleSheet("color: #888888; font-size: 20px; border: none;");
    psramLbl->addWidget(psramFree);
    psramLbl->addStretch();
    psramLbl->addWidget(psramUsed);

    psramLayout->addWidget(psramName);
    psramLayout->addWidget(psramBar);
    psramLayout->addLayout(psramLbl);
    memoryLayout->addWidget(psram, 1);

    crd3Layout->addLayout(memoryLayout);
    crd3Layout->addStretch();

//РЯД 2. время/версия
    QFrame *cardHome4 = MainWindow::createCardWidget();
    crd4Layout = new QVBoxLayout(cardHome4);
    crd4Layout->setSpacing(15);

    time = new QFrame();
    time->setStyleSheet( "background-color: #f5f5f5; border-radius: 10px; ");
    timeLayout = new QVBoxLayout(time);

    timeName = new QLabel("Время:");
    timeName->setStyleSheet("color: #888888; font-size: 22px; border: none;");
    timeName->setAlignment(Qt::AlignCenter);

    timeValue = new QLabel("02.07.2026, 15:24:31");
    timeValue->setStyleSheet("font-size: 26px; font-weight: bold; color: #000000; border: none;");
    timeValue->setAlignment(Qt::AlignCenter);

    timeLayout->addWidget(timeName);
    timeLayout->addWidget(timeValue);
    crd4Layout->addWidget(time);

    restart = new QFrame();
    restart->setStyleSheet( "background-color: #f5f5f5; border-radius: 10px; ");
    restartLayout = new QVBoxLayout(restart);

    restartName = new QLabel("Рестарты:");
    restartName->setStyleSheet("color: #888888; font-size: 22px; border: none;");
    restartName->setAlignment(Qt::AlignCenter);

    restartValue = new QLabel("47");
    restartValue->setStyleSheet("font-size: 26px; font-weight: bold; color: #000000; border: none;");
    restartValue->setAlignment(Qt::AlignCenter);

    restartLayout->addWidget(restartName);
    restartLayout->addWidget(restartValue);
    crd4Layout->addWidget(restart);

    version = new QFrame();
    version->setStyleSheet( "background-color: #f5f5f5; border-radius: 10px; ");
    versionLayout = new QVBoxLayout(version);

    versionName = new QLabel("Версия:");
    versionName->setStyleSheet("color: #888888; font-size: 22px; border: none;");
    versionName->setAlignment(Qt::AlignCenter);

    versionValue = new QLabel("2.1.6");
    versionValue->setStyleSheet("font-size: 26px; font-weight: bold; color: #000000; border: none;");
    versionValue->setAlignment(Qt::AlignCenter);

    versionLayout->addWidget(versionName);
    versionLayout->addWidget(versionValue);
    crd4Layout->addWidget(version);

    row2->addWidget(cardHome4);
    crd4Layout->addStretch();

//РЯД 3. Последняя сессия

    QFrame *cardHome5 = MainWindow::createCardWidget();
    crd5Layout = new QVBoxLayout(cardHome5);

    namecard5 = new QHBoxLayout();
    label5 = new QLabel("Последняя сессия");
    label5->setStyleSheet("font-size: 34px; font-weight: bold; border-bottom: 4px solid black; padding-bottom: 6px; margin-bottom: 8px;");
    namecard5->addWidget(label5);
    namecard5->addStretch();

    crd5Layout->addLayout(namecard5);
    crd5Layout->addSpacing(15);

    sessionLayout = new QHBoxLayout();
    sessionLayout->setSpacing(35);

    idCol = new QVBoxLayout();
    idName = new QLabel("ID");
    idName->setStyleSheet("color: #888888; font-size: 22px;");
    idValue = new QLabel("827191");
    idValue->setStyleSheet("font-size: 26px; font-weight: bold; color: #2b2b33;");
    idCol->addWidget(idName);
    idCol->addSpacing(5);
    idCol->addWidget(idValue);

    sessionLayout->addLayout(idCol);

    statusCol = new QVBoxLayout();
    statName = new QLabel("Статус");
    statName->setStyleSheet("color: #888888; font-size: 22px;");
    statValue = new QLabel("Completed");
    statValue->setStyleSheet("QLabel {background-color: #e8f7ee; color: #2ecc71; font-size: 24px; font-weight: bold; border-radius: 8px;}");
    statValue->setAlignment(Qt::AlignCenter);
    statusCol->addWidget(statName);
    statusCol->addSpacing(5);
    statusCol->addWidget(statValue);

    sessionLayout->addLayout(statusCol);

    timeCol = new QVBoxLayout();
    timeTitle = new QLabel("Время зарядки");
    timeTitle->setStyleSheet("color: #888888; font-size: 22px;");
    timeVal = new QLabel("02.07.2026 08:07 - 13:50");
    timeVal->setStyleSheet("font-size: 26px; font-weight: bold; color: #2b2b33;");
    timeCol->addWidget(timeTitle);
    timeCol->addSpacing(5);
    timeCol->addWidget(timeVal);

    sessionLayout->addLayout(timeCol);

    durationCol = new QVBoxLayout();
    durationName = new QLabel("Длительность");
    durationName->setStyleSheet("color: #888888; font-size: 22px;");
    durationValue = new QLabel("5ч 43м");
    durationValue->setStyleSheet("font-size: 26px; font-weight: bold; color: #2b2b33;");
    durationCol->addWidget(durationName);
    durationCol->addSpacing(5);
    durationCol->addWidget(durationValue);

    sessionLayout->addLayout(durationCol);

    consumedCol = new QVBoxLayout();
    consumedName = new QLabel("Потреблено");
    consumedName->setStyleSheet("color: #888888; font-size: 22px;");
    consumedValue = new QLabel("30.07 кВт");
    consumedValue->setStyleSheet("font-size: 26px; font-weight: bold; color: #2b2b33;");
    consumedCol->addWidget(consumedName);
    consumedCol->addSpacing(5);
    consumedCol->addWidget(consumedValue);

    sessionLayout->addLayout(consumedCol);
    sessionLayout->addStretch();
    crd5Layout->addLayout(sessionLayout);
    crd5Layout->addStretch();

    row3->addWidget(cardHome5, 3);

//РЯД 3. Статистика

    QFrame *cardHome6 = MainWindow::createCardWidget();
    crd6Layout = new QVBoxLayout(cardHome6);

    namecard6 = new QHBoxLayout();
    label6 = new QLabel("Статистика сессий");
    label6->setStyleSheet("font-size: 34px; font-weight: bold; border-bottom: 4px solid black; padding-bottom: 6px; margin-bottom: 8px;");
    namecard6->addWidget(label6);
    namecard6->addStretch();

    crd6Layout->addLayout(namecard6);
    crd6Layout->addSpacing(15);

    Layout = new QHBoxLayout();
    Layout->setSpacing(15);

    total = new QFrame();
    total->setStyleSheet(".QFrame { background-color: #ffffff; border: 1px solid #e0e0e0; border-radius: 12px; }");
    vTotal = new QVBoxLayout(total);

    iconTotal = new QHBoxLayout();
    icTotal = new QLabel();
    icTotal->setPixmap(QPixmap(":/new/prefix1/total.png").scaled(35, 35, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    valueTotal = new QLabel("191");
    valueTotal->setStyleSheet("font-size: 32px; font-weight: bold; border: none;");

    iconTotal->addWidget(icTotal);
    iconTotal->addSpacing(10);
    iconTotal->addWidget(valueTotal);
    iconTotal->addStretch();

    lblTotal = new QLabel("Всего сессий");
    lblTotal->setStyleSheet("color: #888888; font-size: 20px; border: none;");
    lblTotal->setAlignment(Qt::AlignCenter);

    vTotal->addLayout(iconTotal);
    vTotal->addSpacing(10);
    vTotal->addWidget(lblTotal);
    Layout->addWidget(total, 1);

    success = new QFrame();
    success->setStyleSheet(".QFrame { background-color: #ffffff; border: 1px solid #e0e0e0; border-radius: 12px; }");
    vSuccess = new QVBoxLayout(success);

    iconSuccess = new QHBoxLayout();
    icSuccess = new QLabel();
    icSuccess->setPixmap(QPixmap(":/new/prefix1/ok.png").scaled(35, 35, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    valueSuccess = new QLabel("189");
    valueSuccess->setStyleSheet("font-size: 32px; font-weight: bold; border: none;");

    iconSuccess->addWidget(icSuccess);
    iconSuccess->addSpacing(10);
    iconSuccess->addWidget(valueSuccess);
    iconSuccess->addStretch();

    lblSuccess = new QLabel("Успешных");
    lblSuccess->setStyleSheet("color: #888888; font-size: 20px; border: none;");
    lblSuccess->setAlignment(Qt::AlignCenter);

    vSuccess->addLayout(iconSuccess);
    vSuccess->addSpacing(10);
    vSuccess->addWidget(lblSuccess);
    Layout->addWidget(success, 1);

    failed = new QFrame();
    failed->setStyleSheet(".QFrame { background-color: #ffffff; border: 1px solid #e0e0e0; border-radius: 12px; }");
    vFailed = new QVBoxLayout(failed);

    iconFailed = new QHBoxLayout();
    icFailed = new QLabel();
    icFailed->setPixmap(QPixmap(":/new/prefix1/failed.png").scaled(35, 35, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    valueFailed = new QLabel("2");
    valueFailed->setStyleSheet("font-size: 32px; font-weight: bold; border: none;");

    iconFailed->addWidget(icFailed);
    iconFailed->addSpacing(10);
    iconFailed->addWidget(valueFailed);
    iconFailed->addStretch();

    lblFailed = new QLabel("Неудачных");
    lblFailed->setStyleSheet("color: #888888; font-size: 20px; border: none;");
    lblFailed->setAlignment(Qt::AlignCenter);

    vFailed->addLayout(iconFailed);
    vFailed->addSpacing(10);
    vFailed->addWidget(lblFailed);
    Layout->addWidget(failed, 1);

    err = new QFrame();
    err->setStyleSheet(".QFrame { background-color: #ffffff; border: 1px solid #e0e0e0; border-radius: 12px; }");
    vError = new QVBoxLayout(err);

    iconError = new QHBoxLayout();
    icError = new QLabel();
    icError->setPixmap(QPixmap(":/new/prefix1/error.png").scaled(35, 35, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    valueError = new QLabel("0");
    valueError->setStyleSheet("font-size: 32px; font-weight: bold; border: none;");

    iconError->addWidget(icError);
    iconError->addSpacing(10);
    iconError->addWidget(valueError);
    iconError->addStretch();

    lblError = new QLabel("С ошибкой");
    lblError->setStyleSheet("color: #888888; font-size: 20px; border: none;");
    lblError->setAlignment(Qt::AlignCenter);

    vError->addLayout(iconError);
    vError->addSpacing(10);
    vError->addWidget(lblError);
    Layout->addWidget(err, 1);

    crd6Layout->addLayout(Layout);
    crd6Layout->addStretch();
    row3->addWidget(cardHome6, 4);

    homeLayout->addLayout(row3);
    homeLayout->addStretch(1);
}

void homeWindow::unlock()
{
    if (statusValue->text() == "Lock") {
        statusValue->setText("Unlock");
        QPixmap unlockPixmap(":/new/prefix1/unlock.png");
        icon->setPixmap(unlockPixmap.scaled(90, 90, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        icon->setStyleSheet("background-color: #defcd3; border-radius: 30px; qproperty-alignment: 'AlignCenter';");
        unlockBtn->setText("Заблокировать\nконнектор");
    }
    else {
        statusValue->setText("Lock");
        QPixmap lockPixmap(":/new/prefix1/lock.png");
        icon->setPixmap(lockPixmap.scaled(90, 90, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        icon->setStyleSheet("background-color: #fef3d6; border-radius: 30px; qproperty-alignment: 'AlignCenter';");
        unlockBtn->setText("Разблокировать\nконнектор");
    }
}

homeWindow::~homeWindow(){}

void homeWindow::setNewLocation(const QString &newPlace)
{
    edtLocation->setText("Локация: " + newPlace);
}
