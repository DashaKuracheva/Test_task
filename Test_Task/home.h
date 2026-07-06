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
    QVBoxLayout *homeLayout, *crd1Layout, *avgTimeLayout, *avgPowerLayout, *btnLayout, *crd2Layout,*crd6Layout, *crd5Layout, *crd4Layout, *powerLayout, *voltageLayout,*statusTextLayout, *currentLayout, *receivedLayout, *crd3Layout;
    QHBoxLayout *row1, *row2, *row3, *namecard1, *statsLayout, *statusLayout, *namecard2,*statusLayout1, *namecard3,*namecard6, *namecard5;
    QLabel * label1, *label2, * label3, * label4, *label5, *label6, *finish, *pixLbl, *finish2, *pixLbl2, *pixLbl3;
    QTextEdit *edtLocation;
    QFrame *avgTime,*avgPower, *power, *voltage, *current, *received, *status;
    QLabel * avgTimeName, *avgTimeValue, * avgPowerTitle, * avgPowerValue, *labelError, *statusIcon, *statusText, *powerName, *powerValue, *voltageName,
    *currentName,*receivedName,*statusName, *statusValue, *receivedValue, *currentValue,*voltageValue, *icon;
    QPushButton *softBtn,*hardBtn, *unlockBtn, *btnSinhr;
    QGridLayout * param1;
    QHBoxLayout *memoryLayout, *flashLbl, *dramLbl, *iramLbl, *psramLbl;
    QVBoxLayout *flashLayout, *dramLayout, *iramLayout, *psramLayout;
    QFrame *flash, *dram, *iram, *psram;
    QLabel *flashName, *flashFree,*flashUsed, *dramName, *dramFree, *dramUsed, *iramName, *iramFree, *iramUsed, *psramName, *psramFree, *psramUsed;
    QProgressBar *flashBar, *dramBar, *iramBar, *psramBar;
    QFrame *time, *restart, *version;
    QVBoxLayout *timeLayout, *restartLayout, *versionLayout;
    QLabel *timeName,*timeValue, *restartValue, *restartName, *versionValue, *versionName;
    QHBoxLayout *sessionLayout,*Layout;
    QVBoxLayout *idCol, *statusCol, *timeCol, *durationCol, *consumedCol;
    QLabel *idName, *idValue, *statName, *statValue, *timeTitle, *timeVal, *durationName, *durationValue, *consumedName, *consumedValue ;
    QFrame *total,*success, *failed, *err;
    QVBoxLayout *vTotal, *vSuccess, *vFailed, *vError;
    QHBoxLayout *iconTotal, *iconSuccess, *iconFailed, *iconError;
    QLabel *icTotal, *valueTotal, *lblTotal, *icSuccess, *valueSuccess, *lblSuccess, *icFailed, *valueFailed, *lblFailed, *icError, *valueError, *lblError ;

private slots:
    void unlock();
};

#endif // HOME_H
