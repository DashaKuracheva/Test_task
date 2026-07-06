#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QtWidgets>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QStandardPaths>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>

class CongigWindow : public QWidget
{
    Q_OBJECT

public:
    CongigWindow(QWidget *parent = nullptr);
    ~CongigWindow();
    QString stationId() const { return edtID->text(); }
    QLineEdit* idLineEdit() const { return edtID; }
    QString location() const { return edtPlace->text(); }
    QLineEdit* locationLineEdit() const { return edtPlace; }

private:

     QFrame *connectorWidget;
     QScrollArea *scrollArea;
     QWidget *configlWidget, *scrollContent;
     QHBoxLayout *row1Layout, *row2Layout, *row3Layout, *btnLayout;
     QVBoxLayout *configLayout,*outLayout, *crd1, *crd2, * crd3, *crd4, *crd5, *crd6, *crd7, *Vconnector;
     // заголовкии
     QLabel *lbl1, *lbl2, * lbl3, *lbl4, *lbl5, *lbl6, *lbl7, *lblConnector;
     //сетевой инт
     QLabel *interface, *wifiPASS, * wifiSSID, *internet, *LAN;
     QLineEdit *EDTwifiSSID, *EDTwifiPASS;
     //станция
     QLabel *id, *serialNum, * rowNum, *place;
     QLineEdit *edtID, *edtSerialNum, *edtRowNum, *edtPlace;
     //соединение
     QLabel *server, *apn, * pin;
     QLineEdit *edtServer, *edtApn, *edtPin;
     //лимиты
     QLabel *lim, *connector, * regime;
     QSpinBox *edtLim, *edtConnector;
     //настройки коннекторов
     QLabel *modbus, *interval;
     QSpinBox *edtModbus, *edtInterval;
     //RGB
     QLabel *kol, *maxKol;
     QSpinBox *edtKol, *edtMaxKol;
     //on off
     QLabel *counter;
     QComboBox *edtCount;

     QRadioButton *g3, *lan;
     QButtonGroup *group;
     QComboBox *internetBox, *regimeBox;
     QPushButton *save,*load;
     QCheckBox *power, *cable,*debug, *on, *counterOn, *door, *stop, *current;


private slots:
     void onSave();
     void onLoad();
};

#endif // CONFIGURATION_H
