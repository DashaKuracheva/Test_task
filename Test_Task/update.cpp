#include "update.h"
#include "mainwindow.h"

updateWindow::updateWindow(QWidget *parent) : QWidget{parent}
{
    mainLayout = new QVBoxLayout(this);

    QFrame *card = MainWindow::createCardWidget();
    cardLayout = new QVBoxLayout(card);
    cardLayout->setContentsMargins(40, 20, 40, 20);

    titleLabel = new QLabel("Обновление прошивки");
    titleLabel->setStyleSheet("font-size: 34px; font-weight: bold; border-bottom: 4px solid black; padding-bottom: 6px; margin-bottom: 8px;");
    cardLayout->addWidget(titleLabel);
    cardLayout->addSpacing(20);

    bodyLayout = new QHBoxLayout();
    bodyLayout->setSpacing(40);

    leftLayout = new QVBoxLayout();
    version = new QLabel("Текущая версия прошивки:");
    version->setStyleSheet("color: #888888; font-size: 30px; border: none;");

    versionValue = new QLabel("2.1.6");
    versionValue->setStyleSheet("font-size: 30px; font-weight: bold; border: none;");

    leftLayout->addWidget(version);
    leftLayout->addWidget(versionValue);
    leftLayout->addStretch();

    bodyLayout->addLayout(leftLayout, 1);

    rightLayout = new QVBoxLayout();
    history = new QLabel("История обновлений");
    history->setStyleSheet("color: #888888; font-size: 28px; border: none;");
    rightLayout->addWidget(history);

    historyListLayout = new QVBoxLayout();
    historyListLayout->setSpacing(4);
    rightLayout->addLayout(historyListLayout);
    rightLayout->addStretch();

    bodyLayout->addLayout(rightLayout, 3);

    cardLayout->addLayout(bodyLayout);
    cardLayout->addSpacing(30);

    btnLayout = new QVBoxLayout();
    btnLayout->setSpacing(10);

    chooseBtn = new QPushButton("Выбрать файл прошивки");
    chooseBtn->setStyleSheet(
                "QPushButton { border: 2px solid #000000; background-color: grey; color: white; border-radius: 20px; padding: 10px 40px; font-size: 28px}"
                "QPushButton:hover {background-color: #5c6373 }"
                "QPushButton:pressed {background-color: black }");

    connect(chooseBtn, SIGNAL(clicked()), this, SLOT(chooseFile()));

    selectedFile = new QLabel("Файл не выбран");
    selectedFile->setStyleSheet("color: #888888; font-size: 24px; border: none;");
    selectedFile->setAlignment(Qt::AlignCenter);


    btnLayout->addWidget(chooseBtn, 0, Qt::AlignHCenter);
    btnLayout->addSpacing(30);
    btnLayout->addWidget(selectedFile, 0, Qt::AlignHCenter);

    cardLayout->addLayout(btnLayout);
    cardLayout->addSpacing(30);
    cardLayout->addStretch();

    mainLayout->addWidget(card);
    mainLayout->addStretch(1);

    QVector<historyItem> demo = {
        {"09.05.2026 09:24:23", "OTA", "Mod3_2.1.6_n.bin", "ok"},
        {"05.05.2026 11:23:41", "OTA", "Mod3-2MB_2.1.4_c.bin", "ok"},
        {"05.05.2026 07:41:40", "WEB", "web_update_1.6.4.tar", "ok"},
        {"05.05.2026 07:39:12", "OTA", "Mod3_2.1.6_g.bin", "ok"},
        {"05.05.2026 05:16:10", "WEB", "web_update_1.6.4.tar", "ok"},
    };
    setHistory(demo);

}

updateWindow::~updateWindow() {}

void updateWindow::setVersion(const QString &version)
{
    versionValue->setText(version);
}

QLabel *updateWindow::typeFunc(const QString &type)
{
    lblType = new QLabel(type);
    lblType->setAlignment(Qt::AlignCenter);
    lblType->setFixedWidth(70);

    if (type == "WEB") {
        lblType->setStyleSheet(
            "background-color: #e8f0fe; color: #4285f4; font-size: 26px; "
            "font-weight: bold; border-radius: 6px; padding: 4px 0;");
    } else {
        lblType->setStyleSheet(
            "background-color: #eeeeee; color: #777777; font-size: 26px; "
            "font-weight: bold; border-radius: 6px; padding: 4px 0;");
    }
    return lblType;
}

QLabel *updateWindow::statusIcon(const QString &status)
{
    icon = new QLabel();
    icon->setFixedSize(50, 50);
    icon->setAlignment(Qt::AlignCenter);

    QString iconPath = ":/new/prefix1/ok.png";
    QString bg = "#e8f7ee";
    if (status == "error") {
        iconPath = ":/new/prefix1/error.png";
        bg = "#fdeaea";
    }
    icon->setStyleSheet(QString("background-color: %1; border-radius: 15px;").arg(bg));

    QPixmap pix(iconPath);
    icon->setPixmap(pix.scaled(45, 45, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    return icon;
}

QWidget *updateWindow::buildHistory(const historyItem &item)
{
    row = new QWidget();
    rowLayout = new QHBoxLayout(row);
    rowLayout->setContentsMargins(0, 20, 0, 20);
    rowLayout->setSpacing(15);

    dateLbl = new QLabel(item.date);
    dateLbl->setFixedWidth(220);
    dateLbl->setStyleSheet("font-size: 26px; font-weight: bold; color: #333333; border: none;");
    rowLayout->addWidget(dateLbl);

    rowLayout->addWidget(typeFunc(item.type));

    fileLbl = new QLabel(item.fileName);
    fileLbl->setStyleSheet("font-size: 26px; color: #888888; border: none;");
    rowLayout->addWidget(fileLbl, 1);

    rowLayout->addWidget(statusIcon(item.status));

    return row;
}

void updateWindow::clearHistoryList()
{
    QLayoutItem *child;
    while ((child = historyListLayout->takeAt(0)) != nullptr) {
        if (child->widget())
            child->widget()->deleteLater();
        delete child;
    }
}

void updateWindow::setHistory(const QVector<historyItem> &items)
{
    historyItems = items;
    clearHistoryList();
    for (int i = 0; i < items.size(); i++) {
            const historyItem &item = items.at(i);
            historyListLayout->addWidget(buildHistory(item));
        }
}

void updateWindow::chooseFile(){

    QString fileName = QFileDialog::getOpenFileName(
        this, "Выбрать файл прошивки", QString(), "Прошивка (*.bin *.tar)");

    if (fileName.isEmpty())
        return;

    QFileInfo info(fileName);
    selectedFile->setText(info.fileName());

    QString type = (info.suffix().compare("tar", Qt::CaseInsensitive) == 0) ? "WEB" : "OTA";

    QRegularExpression versionRe("(\\d+\\.\\d+\\.\\d+)");
    QRegularExpressionMatch match = versionRe.match(info.fileName());

    historyItem newItem;
    newItem.date = QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss");
    newItem.type = type;
    newItem.fileName = info.fileName();
    newItem.status = "ok";

    historyItems.prepend(newItem);
    setHistory(historyItems);

    if (match.hasMatch()) {
        setVersion(match.captured(1));
    }
}

