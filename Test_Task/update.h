#ifndef UPDATE_H
#define UPDATE_H

#include <QtWidgets>
#include <QVector>
#include <QFileDialog>
#include <QFileInfo>
#include <QRegularExpression>

struct historyItem {
    QString date;
    QString type;
    QString fileName;
    QString status;
};

class updateWindow : public QWidget
{
    Q_OBJECT
public:
    updateWindow(QWidget *parent = nullptr);
    ~updateWindow();

private:
    QVBoxLayout *mainLayout, *cardLayout, *leftLayout, *rightLayout, *btnLayout, *historyListLayout;
    QHBoxLayout *bodyLayout,  *rowLayout;
    QPushButton *chooseBtn;
    QLabel *titleLabel, *version, *versionValue, *history, *selectedFile;
    QLabel *lblType , *icon, *dateLbl, *fileLbl;
    QWidget *row;

    QWidget *buildHistory(const historyItem &item);
    QLabel *typeFunc(const QString &type);
    QLabel *statusIcon(const QString &status);
    QVector<historyItem> historyItems;

    void clearHistoryList();
    void setVersion(const QString &version);
    void setHistory(const QVector<historyItem> &items);

private slots:
    void chooseFile();

};

#endif // UPDATE_H
