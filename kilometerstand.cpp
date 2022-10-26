#include "kilometerstand.h"
/*
KilometerStand::KilometerStand()
{
}

KilometerStand::KilometerStand(QString)
{

}

void KilometerStand::schreib_km(QString km)
{
    QFile f("km_Stand.txt");
    if(!f.open(QFile::WriteOnly)) qDebug() << "nicht offen...";
    else
    {
        QTextStream out(&f);
        out << getGeskm();
        f.close();
    }
}


QString KilometerStand::lies_km()
{
    QString km_txt ;
    QFile f("km_Stand.txt");
    if (!f.open(QFile::ReadOnly))  qDebug() << "nicht offen...";
    else
    {
        QTextStream in(&f);
        km_txt = in.readAll();
        f.close();
    }
   return km_txt;
}
*/
