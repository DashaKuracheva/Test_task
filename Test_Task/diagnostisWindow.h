#ifndef DIAGNOSTISWINDOW_H
#define DIAGNOSTISWINDOW_H

#include <QWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QFrame>
#include <QPushButton>
#include <QProgressBar>
#include <QComboBox>
#include <QCheckBox>

class DiagnosticsWindow : public QWidget
{
    Q_OBJECT

public:
    DiagnosticsWindow(QWidget *parent = nullptr);
    ~DiagnosticsWindow();

private:
    QTabWidget *tabW;
    QWidget *createDiagnosticsTab(), *createNetworkTab();
    QVBoxLayout *mainLayout;
    QTabWidget *tabs;
//диагностика
    QHBoxLayout *btnLt;
    QPushButton *btnDumps, *btnClear, *btnRefresh;
    QFrame *diagFrame1, *connectorFrame, *dumpsFrame2;
    QVBoxLayout *diagFrameLayout, *connectorLayout, *dumpsFrameLayout;
    QLabel *diagTitle, *connectorLabel;
    QHBoxLayout *connectorLine, *statusLine, *dumpsLine;
    QLabel *connectorCheck;
    QLabel *statusLabel, *ocppStatus, *pokazania, *powerNameLbl,*powerValueLbl, *voltageNameLbl,
           *voltageValueLbl, *currentNameLbl, *currentValueLbl, *energyNameLbl, *energyValueLbl;
    QGridLayout *grid;
    QLabel *dumpsTitleLabel, *dumpsInfoLabel, *dumpsLabel;
    QPushButton *dumpBtn;
    bool dumpsEnabled;
//параметры сети
    QGridLayout *paramGrid, *sigGrid;
    QFrame *modem, *signal,* connection, *network;
    QVBoxLayout *modemLayout, *signalLayout, *connectionLayout, *networkLayout;
    QLabel *modemTitle, *signalTitle, *connectionTitle, *networkTitle, *subLabel;
    QProgressBar *pb;
    QLabel *regime, *load, *available, *load2;
    QComboBox *modeComboBox;
    QPushButton *applyBtn;

private slots:
    void refresh();
    void clear();
    void dumps();
    void refreshDumps();
    void applyNetwork();
};

#endif // DIAGNOSTISWINDOW_H
