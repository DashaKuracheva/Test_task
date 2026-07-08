#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    //формрование ЦЕНТРАЛЬНОГО ВИДЖЕТА
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    //формирование горизонтального слоя
    mainLayout = new QHBoxLayout(centralWidget);
    mainLayout->setContentsMargins(50, 50, 50, 50);
    mainLayout->setSpacing(30);

    //левая часть
    idInfo = new QLabel("ID станции:", this);
    idInfo->setWordWrap(true);
    idInfo->setStyleSheet("QLabel {font-size: 36px}");

    InfoLayout = new QVBoxLayout();
    InfoLayout->setSpacing(10);
    InfoLayout->addWidget(idInfo);

    listWidget = new QListWidget(this);
    QFont font = listWidget->font();
    font.setPointSize(14);
    listWidget->setFont(font);
    listWidget->setStyleSheet(
            "QListWidget { border: 1px solid #000000; background-color: #e6f8df; border-radius: 6px; outline: 0;  }"
            "QListWidget::item { border: 1px solid transparent; padding-top: 12px; padding-bottom: 12px; padding-left: 35px; color: black; font-size: 16px; }"
            "QListWidget::item:selected { border: 1px solid #000000; border-radius: 8px; background-color: grey; color: white; padding-top: 12px; padding-bottom: 12px; padding-left: 35px; font-size: 20px;}" );

    listWidget->setSpacing(5);

    item1 = new QListWidgetItem(QIcon(":/new/prefix1/home.png"), "Главная");
    listWidget->addItem(item1);
    item2 = new QListWidgetItem(QIcon(":/new/prefix1/setting.png"), "Конфигурация");
    listWidget->addItem(item2);
    item3 = new QListWidgetItem(QIcon(":/new/prefix1/diagnostis.png"), "Диагностика");
    listWidget->addItem(item3);
    item4 = new QListWidgetItem(QIcon(":/new/prefix1/update.png"), "Обновление ПО");
    listWidget->addItem(item4);
    item5 = new QListWidgetItem(QIcon(":/new/prefix1/analytics.png"), "Аналитика");
    listWidget->addItem(item5);

    InfoLayout->addWidget(listWidget);

    //правая чассть
    stackedWidget = new QStackedWidget(this);
    homePage = new homeWindow(this);
    CongigPage = new CongigWindow(this);
    diagnosticsPage = new DiagnosticsWindow (this);
    updatePage= new updateWindow(this);
    analyticsPage = new analyticsWindow(this);

    stackedWidget->addWidget(homePage);
    stackedWidget->addWidget(CongigPage);
    stackedWidget->addWidget(diagnosticsPage);
    stackedWidget->addWidget(updatePage);
    stackedWidget->addWidget(analyticsPage);

    mainLayout->addLayout(InfoLayout);
    mainLayout->addWidget(stackedWidget);
    listWidget->setFixedWidth(450);

    connect(listWidget, SIGNAL(currentRowChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));
    listWidget->setCurrentRow(0);

    connect(CongigPage->idLineEdit(), SIGNAL(textChanged(QString)), this, SLOT(updateInfo()));
    connect(CongigPage->locationLineEdit(), SIGNAL(textChanged(QString)), this, SLOT(updateInfo()));
    updateInfo();
}

MainWindow::~MainWindow(){};

void MainWindow::updateInfo()
{
    QString id = CongigPage->stationId();
    QString displayId = id.isEmpty() ? "—" : id;

    idInfo->setText(QString("<span style='color:#000000;'>ID станции: </span>"
                            "<span style='color:#a80d22;font-weight: bold '>%1</span>").arg(displayId));
    QString locationStr = CongigPage->location();
        QString displayLoc = locationStr.isEmpty() ? "Не указана" : locationStr;

        if (homePage) {
            homePage->setNewLocation(displayLoc);
        }
}

QFrame* MainWindow::createCardWidget()
{
    QFrame *card = new QFrame();
    card->setFrameShape(QFrame::NoFrame);

    card->setStyleSheet(
        "QFrame { background-color: #fcf9f9; border-radius: 10px; }"
        "QLabel { border: none; color: #333333; font-size: 32px;  }"
        "QLineEdit,QTextEdit, QComboBox, QSpinBox { border: 1px solid #cccccc; border-radius: 4px; padding: 6px; background-color: #ffffff; color: #333333; font-size: 28px; margin-left: 45px;}"
        "QLineEdit:focus, QComboBox:focus, QSpinBox:focus { border: 1px solid #0056b3; }"
        "QCheckBox { border: none; padding: 4px; color: #333333; font-size: 26px; margin-left: 45px; }"
        "QRadioButton { border: none; padding: 4px; color: #333333; font-size: 26px; margin-left: 40px; }"
        "QSpinBox::up-button, QSpinBox::down-button { border: none; background: transparent; }"
        "QComboBox QAbstractItemView {background-color: #ffffff; border: 1px solid #cccccc; }");

    // ИСПРАВЛЕНИЕ: Создаем эффект тени БЕЗ указания (card) в скобках
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(15);
    shadow->setOffset(3, 3);
    shadow->setColor(QColor(0, 0, 0, 100));

    // Метод сам назначит родителя для shadow внутри Qt
    card->setGraphicsEffect(shadow);

    return card;
}
