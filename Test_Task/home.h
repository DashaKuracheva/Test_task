#ifndef HOME_H
#define HOME_H

#include <QtWidgets>

class homeWindow : public QWidget
{
    Q_OBJECT

public:
    homeWindow(QWidget *parent = nullptr);
    ~homeWindow();
    void setNewLocation(const QString &newPlace);

private:
    QVBoxLayout *homeLayout, *crd1Layout, *crd2Layout, *crd3Layout, *crd4Layout, *crd5Layout, *crd6Layout;
    QHBoxLayout *row1, *row2, *row3;
// Заголовоки
    QHBoxLayout *namecard1, *namecard2, *namecard3,*namecard5, *namecard6;
    QLabel * label1, *label2, * label3, *label5, *label6, *finish, *pixLbl, *finish2, *pixLbl2;
//Карточка1
    QTextEdit *edtLocation;
    QHBoxLayout  *statsLayout, *statusLayout;
    QVBoxLayout  *avgTimeLayout, *avgPowerLayout, *btnLayout;
    QFrame *avgTime,*avgPower;
    QLabel * avgTimeName, *avgTimeValue, * avgPowerName, * avgPowerValue, *labelError, *statusIcon, *statusText;
    QPushButton *softBtn,*hardBtn;
//Карточка2
    QGridLayout * param1;
    QHBoxLayout  *statusLayout1;
    QVBoxLayout   *powerLayout, *voltageLayout, *currentLayout, *receivedLayout, *statusTextLayout;
    QFrame *power, *voltage, *current, *received, *status;
    QPushButton  *unlockBtn;
    QLabel  *powerName, *powerValue, *voltageName,*voltageValue, *currentName,*currentValue, *receivedName,
            *receivedValue, *statusName, *statusValue, *icon;
//Карточка3
    QFrame *flash, *dram, *iram, *psram;
    QPushButton  *btnSinhr;
    QHBoxLayout *memoryLayout, *flashLbl, *dramLbl, *iramLbl, *psramLbl;
    QVBoxLayout *flashLayout, *dramLayout, *iramLayout, *psramLayout;
    QProgressBar *flashBar, *dramBar, *iramBar, *psramBar;
    QLabel *flashName, *flashFree,*flashUsed, *dramName, *dramFree, *dramUsed,
           *iramName, *iramFree, *iramUsed, *psramName, *psramFree, *psramUsed;
//Карточка4
    QFrame *time, *restart, *version;
    QVBoxLayout *timeLayout, *restartLayout, *versionLayout;
    QLabel *timeName,*timeValue, *restartValue, *restartName, *versionValue, *versionName;
//Карточка5
    QHBoxLayout *sessionLayout;
    QVBoxLayout *idCol, *statusCol, *timeCol, *durationCol, *consumedCol;
    QLabel *idName, *idValue, *statName, *statValue, *timeTitle, *timeVal,
           *durationName, *durationValue, *consumedName, *consumedValue ;
//Карточка6
    QHBoxLayout *Layout;
    QFrame *total,*success, *failed, *err;
    QVBoxLayout *vTotal, *vSuccess, *vFailed, *vError;
    QHBoxLayout *iconTotal, *iconSuccess, *iconFailed, *iconError;
    QLabel *icTotal, *valueTotal, *lblTotal, *icSuccess, *valueSuccess, *lblSuccess, *icFailed,
           *valueFailed, *lblFailed, *icError, *valueError, *lblError;

private slots:
    void unlock();
};

#endif // HOME_H
