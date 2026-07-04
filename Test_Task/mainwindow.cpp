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
    page1 = new QLabel("<h1>Контент 1</h1>", this); page1->setAlignment(Qt::AlignCenter);
    CongigPage = new CongigWindow(this);
    page3 = new QLabel("<h1>Контент 3</h1>", this); page3->setAlignment(Qt::AlignCenter);
    page4 = new QLabel("<h1>Контент 4</h1>", this); page4->setAlignment(Qt::AlignCenter);
    page5 = new QLabel("<h1>Контент 5</h1>", this); page5->setAlignment(Qt::AlignCenter);

    stackedWidget->addWidget(page1);
    //stackedWidget->addWidget(homePage);
    stackedWidget->addWidget(CongigPage);
    stackedWidget->addWidget(page3);
    stackedWidget->addWidget(page4);
    stackedWidget->addWidget(page5);

    mainLayout->addLayout(InfoLayout);
    mainLayout->addWidget(stackedWidget);
    listWidget->setFixedWidth(450);

    connect(listWidget, SIGNAL(currentRowChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));
    listWidget->setCurrentRow(0);

    connect(CongigPage->idLineEdit(), SIGNAL(textChanged(QString)), this, SLOT(updateInfo()));
    updateInfo();
}

MainWindow::~MainWindow(){};

void MainWindow::updateInfo()
{
    QString id = CongigPage->stationId();
    QString displayId = id.isEmpty() ? "—" : id;

    idInfo->setText(QString("<span style='color:#000000;'>ID станции: </span>"
                            "<span style='color:#a80d22;font-weight: bold '>%1</span>").arg(displayId));
}

