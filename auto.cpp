#include<QTimer>
#include "auto.h"
#include "qdebug.h"

//#include<iostream>
//#include<dos.h>
#include <chrono>
#include <thread>
#include <QThread>

#include <time.h>
#include <stdio.h>



//#include <iostream>
//#include <algorithm>
//using namespace std;

Auto::Auto()
{                             //  Initialisierungen:
    GangNr=0; GangAlt=0;
    GasMenge=0.0; tem=0.0;
    GM_alt=0.0;
    start =false;  offen=false;
    //geskm = 777.0;

    geskm = lies_km().toFloat();

}



    void Auto::setStart(bool s){
        start = s;
        tem = 0;

        if (start) { GasMenge=650.0 ; }
            else{ GasMenge = 0.0; }
    }


    void Auto::setKuppl(bool b)
    {
        if (start) {
            offen = b;
            GM_alt = GasMenge;
            //if (offen) {GasMenge = 650; qDebug()<<" in Kupplung offen!!!!";}
            if (!offen) GasMenge= GM_alt;
        }
    }


//    emit int DZ_ch();

    void Auto::setGang(int g)
    {
        if (start) {
            if (offen)
            {
                if(g-GangNr<=2)
                {
                GangAlt = GangNr;
                GangNr = g;
                offen = false;

                qDebug() << "Gas vorher ist !!!: "<< GasMenge<<"\n";

              //  if (GangNr != (-1 | 0) && GangAlt != (-1 ))
                if((GangNr!=-1)&&(GangNr!=0)&&(GangAlt!=-1))
                {
                    GasMenge += (GasMenge*(float(GangAlt - GangNr)/4.0));
                    qDebug() << "Gang alt, neu, GasM sind: "<<GangAlt <<GangNr << GasMenge<<"\n";
                    qDebug() << "(GangAlt - GangNr)/4 : "<<float(GangAlt - GangNr)/4 <<"\n";
                }

                else {GasMenge = 650.0;  qDebug()<<"Achtung!!"; }
                } // Differenz maximal 2
                else {offen = false;
                 //   meldung ="Falscher Gang!"

                    setMeld("Falscher Gang!");}      // und Meldung, "Falscher Gang!"

                //if (GangNr == 0) GasMenge = 650;

            } // Ende von Kupplung offen

          //  setGas_up(GasMenge);

//            emit DZ_ch();
          //  emit getGas();  interessante Fehlermeldung, ich müsste es Notify machen, damit emit klappt!
        }
        else GangNr =0;
    }

    int Auto::getGang() {   return GangNr;    }


void Auto::setGas_up(int i)
{
    int sw;
    sw = 500;
    if (!start) GasMenge = 0;
    else {
        if (GangNr==0) {

            if (GasMenge > 600) {sw -= 300; qDebug() << "in setGas!! "<<GasMenge <<"\n";}
            if (GasMenge > 2000) sw -= 0;
            if (GasMenge > 3000) sw -= 0;
            if (GasMenge > 4000) sw -= 99;
            if (GasMenge > 5000) {sw -= 50; _sleep(20);qDebug() << "Gasmenge >5T "<<GasMenge <<"\n";}
            if (GasMenge > 7332) {sw = 10; _sleep(20);qDebug() << "Gasmenge >7332 "<<GasMenge <<"\n";}
            if (GasMenge > 7894) {sw = 1; _sleep(500);qDebug() << "Gasmenge >7894 "<<GasMenge <<"\n";}
            if (GasMenge > 7897) sw = 0;
            GasMenge += sw;
        }
        else if ((GangNr==1)|(GangNr==2)|(GangNr==3)|(GangNr==4)|(GangNr==5)&&(GasMenge<7777)) {
            GasMenge +=49;

        }

    }
}



float Auto::getTempo()
{

    if(!(GangNr==0)) tem = int(GasMenge * 0.0125 * pow(1.35,(GangNr-1)));

    if((!start) |(GangNr==-1)) tem = 0;

    return tem;
}

void Auto::setBremse(int i)
{
    if (start) {

        if(tem>80) tem -=10;
        else tem -=1;
        if (tem<0) _sleep(20);

        if(tem<3) tem = 0;

        if (!(GangNr==0)) {GasMenge = 80*tem/pow(1.35,(GangNr-1)); if(GasMenge<100){start=false; GasMenge=0;}} // und Message "Motor abgewürgt!"

        //tem = int(GasMenge * 0.0125 * pow(1.35,(GangNr-1)));
    }
}

int Auto::getGas()
{
    return GasMenge;
}

// ---------------------------------------- KILOMETER  -----------------


void Auto::setGeskm(QString st)
{

    geskm =st.toFloat();
    emit km_change();

    schreib_km(QString::number(geskm));

}


QString Auto::getGeskm()                  // schiebt ges km in GUI, wird von GUI angefordert
{

    double sekudn;
    zeit_alt = zeit;
    time(&zeit);         // setze hier Anfangszeit

                 // akt     start
    diff = difftime(zeit, zeit_alt);
    meter = diff*(tem/3600.0);
    geskm += meter;

    qDebug() << "diff: " << diff << "km: " << meter/1000 << "tempo " << tem << "geskm: " << geskm << "anf: " << (time(&zeit_alt)) <<" fertig: "<< time(&zeit) << "\n";

    return QString::number(geskm);
}

// -----------------------  DATEI -----------------


void Auto::schreib_km(QString km)
{
    QFile f("C:/Users/ich halt/Documents/alfatraining/meine_Qt/Abschluss_001/km_Stand.txt");
    if(!f.open(QFile::WriteOnly)) qDebug() << "nichttttt offen...";
    else
    {
        QTextStream out(&f);
        out << getGeskm();

        f.close();
    }
}


QString Auto::lies_km()
{

    QString km_txt ;

    QFile f("C:/Users/ich halt/Documents/alfatraining/meine_Qt/Abschluss_001/km_Stand.txt");

    if (!f.open(QFile::ReadOnly))  qDebug() << "nicht oooffen in lies...";
    else
    {
        QTextStream in(&f);
        km_txt = in.readAll();
        f.close();
    }
   return km_txt;
}


// ---------------------------------



QString Auto::getMeld()
{

    return meldung;
}

void Auto::setMeld(QString m)
{
    meldung =m;
    emit meld_change();
}
