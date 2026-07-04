#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    //формрование ЦЕНТРАЛЬНОГО ВИДЖЕТА
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    //формирование горизонтального слоя
    mainLayout = new QHBoxLayout(centralWidget);
    mainLayout->setContentsMargins(50, 50, 50, 50);
    mainLayout->setSpacing(100);


    //левая часть
    listWidget = new QListWidget(this);
    QFont font = listWidget->font();
    font.setPointSize(14);
    listWidget->setFont(font);

    listWidget->setStyleSheet(
            "QListWidget::item:selected {"
            "background-color: grey;"
            "color: white;"
            "}"
        );

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

    //правая чассть
    stackedWidget = new QStackedWidget(this);
    page1 = new QLabel("<h1>Контент 1</h1>", this); page1->setAlignment(Qt::AlignCenter);
    page2 = new QLabel("<h1>Контент 2</h1>", this); page2->setAlignment(Qt::AlignCenter);
    page3 = new QLabel("<h1>Контент 3</h1>", this); page3->setAlignment(Qt::AlignCenter);
    page4 = new QLabel("<h1>Контент 4</h1>", this); page4->setAlignment(Qt::AlignCenter);
    page5 = new QLabel("<h1>Контент 5</h1>", this); page5->setAlignment(Qt::AlignCenter);
    stackedWidget->addWidget(page1);
    stackedWidget->addWidget(page2);
    stackedWidget->addWidget(page3);
    stackedWidget->addWidget(page4);
    stackedWidget->addWidget(page5);

    mainLayout->addWidget(listWidget, 1);
    mainLayout->addWidget(stackedWidget, 4);

    connect(listWidget, SIGNAL(currentRowChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));
    listWidget->setCurrentRow(0);
}

MainWindow::~MainWindow(){};
