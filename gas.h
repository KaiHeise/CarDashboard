#ifndef GAS_H
#define GAS_H

#include <QObject>
#include "auto.h"


class Gas : public Auto
{


    /*
    Q_PROPERTY(int qml_zahl_2 WRITE setZahl2)

*/


public:

    Gas();        //explicit Gas();



  //  int getGang();  //oder brauchts das nicht, wenn ich Variable Gang von oben hier sehen kann?

};

#endif // GAS_H

