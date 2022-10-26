#ifndef AUTO_H
#define AUTO_H

#include <QObject>
#include<QTimer>
#include <QFile>
// #include "kilometerstand.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>

class Auto    : public QObject  // bin nicht sicher, ob ich das brauche f. PROPERTY
{
    Q_OBJECT

    Q_PROPERTY(bool start_p WRITE setStart)
    Q_PROPERTY(int gas_prop_up WRITE setGas_up)
    Q_PROPERTY(int brems_prop WRITE setBremse)
    Q_PROPERTY(int gas_prop_akt READ getGas)
    Q_PROPERTY(bool kuppl_p WRITE setKuppl)
    Q_PROPERTY(int gang_prop WRITE setGang)
    Q_PROPERTY(int gang_prop_akt READ getGang)
    Q_PROPERTY(float tempo_p_akt READ getTempo)



    Q_PROPERTY(QString geskm_p READ  getGeskm WRITE setGeskm NOTIFY km_change)

    Q_PROPERTY(QString meld_p READ  getMeld WRITE setMeld NOTIFY meld_change)

//   Q_PROPERTY(int DZ_p_ch READ getGas NOTIFY DZ_ch)
//   Tempo t;     // hier wird instanz erschaffen oder variable dafür

    int GangNr, GangAlt;
    float GasMenge, tem, GM_alt, geskm, meter;
    bool start, offen;
    double diff;
    time_t zeit, zeit_alt;
    QString meldung;


public:
    Auto();
    void setStart(bool);
    void setKuppl(bool);
    void setGang(int);
    int getGang();
    void setGas_up(int);
    void setBremse(int);
    int getGas();
    float getTempo();
    void setKup2(bool);
    int getKup2();

    QString getGeskm();
    void setGeskm(QString);

    void schreib_km(QString);
    QString lies_km();
    QString getMeld();
    void setMeld(QString);

signals:
//    int DZ_ch();
    void meld_change();
    void km_change();

};

#endif // AUTO_H
