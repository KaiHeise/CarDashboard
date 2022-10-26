import QtQuick
import heise.de
//import QtQml.StateMachine
import QtQuick.Controls



Window {
    id: haupt
    width: 1200
    height: 700
    visible: true
    //color: "black"
    title: qsTr("Multifunktionsanzeige")

    Image {
        id: rueck
        visible: false
        source: "RueckBild_02.jpg"
        //sourceSize.width: 1200
        //sourceSize.height: 700
    }

/*
    Image {
        id: bkgr
        source: "bkgr_001_ab_728.png"
    }       // ende Image background

*/

    Item {
        id: anzeigen

        Text {
            id: l_dreh
            x: 100
            y: 136
            width: 154
            height: 113
            text: qsTr("Drehzahl")
            font.pixelSize: 37
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.italic: true
        }
        TextEdit {
            id: drehzahl
            x: 300
            y: 144
            width: 80
            height: 20
            text: key_tra.gas_prop_akt
            font.pixelSize: 72
            overwriteMode: true
        }

        Text {
            id: l_gang
            x: 500
            y: 375
            width: 154
            height: 113
            text: qsTr("Gang")
            font.pixelSize: 27
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.italic: true
        }
        TextEdit {
            id: gang
            x: 570
            y: 340
            width: 80
            height: 20
            text: key_tra.gang_prop_akt
            font.bold: true
            font.pixelSize: 37
            overwriteMode: true
        }



        Text {
            id: l_temp
            x: 780
            y: 136
            width: 154
            height: 113
            text: qsTr("Tempo")
            font.pixelSize: 37
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.italic: true
        }
        TextEdit {
            id: temp
            x: 1000
            y: 144
            width: 80
            height: 20
            text: key_tra.tempo_p_akt
            font.pixelSize: 72
            overwriteMode: true
        }

        Text {
            id: l_km
            x: 830
            y: 410
            width: 154
            height: 113
            text: qsTr("ges km")
            font.pixelSize: 27
            //  horizontalAlignment: Text.AlignHCenter
          //  verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.italic: true
        }
        TextEdit {
            id: km
            x: 940
            y: 406
            width: 80
            height: 42
            font.pixelSize: 33
            text:key_tra.geskm_p

            overwriteMode: true
        }





        Text {
            id: l_meld
            x: 350
            y: 620
            width: 154
            height: 213
            font.pixelSize: 23
            text: qsTr("Meldung:")
        }



        TextEdit {
            id: mel
            x: 500
            y: 610
            width: 180
            height: 20
            font.pixelSize: 33
            font.bold: true
           // text:                               key_tra.Mel_p
            overwriteMode: true
        }





        RoundButton {
            id: button
            x: 100
            y: 620
            width: 100
            height: 47
            //color: "red"
            text: qsTr("Start /Stop")
        }
    }   // Ende von Item anzeigen


    Transf {
        id: key_tra

        onMeld_change:
            mel.text=key_tra.meld_p

        onKm_change:
            km.text = key_tra.geskm_p     // ist getter READ

            // key_tra.geskm_p = km.text
// wie richtig? oder nur OHNE, dann wie schreiben?


  //        DZ_p_ch: {   }
  //        onDZ_ch: drehzahl.text = key_tra.DZ_ch

    }

    Item {
        id: it
        property bool gestartet: false
        property bool losgelassen: false
        focus: true                                     // damit es aktiviert ist
        Keys.onPressed: {

    // km.text=key_tra.geskm_p

            if(event.key === Qt.Key_S) {if( gestartet === false) {gestartet=true; key_tra.start_p = true; drehzahl.text = key_tra.gas_prop_akt;  temp.text=key_tra.tempo_p_akt; mel.text="gestartet ..."; key_tra.geskm_p = km.text}
                                        else {gestartet=false; console.log("gestoppt... \n"); key_tra.start_p = false; key_tra.gang_prop = 0; gang.text = key_tra.gang_prop_akt; drehzahl.text = key_tra.gas_prop_akt; temp.text=key_tra.tempo_p_akt; mel.text="Motor aus"}}

            else if(event.key === Qt.Key_Up) {key_tra.gas_prop_up = 1; drehzahl.text = key_tra.gas_prop_akt; temp.text=key_tra.tempo_p_akt; km.text=key_tra.geskm_p}  // ; key_tra.gekm_p=km.text
            else if(event.key === Qt.Key_Down) {key_tra.brems_prop = -1;drehzahl.text = key_tra.gas_prop_akt; temp.text=key_tra.tempo_p_akt; km.text=key_tra.geskm_p }

            else if(event.key === Qt.Key_Control) key_tra.kuppl_p = true

            else if(event.key === Qt.Key_R) {key_tra.gang_prop = -1; gang.text = key_tra.gang_prop_akt; drehzahl.text = key_tra.gas_prop_akt; temp.text=key_tra.tempo_p_akt; mel.text=key_tra.meld_p}
            else if(event.key === Qt.Key_0) {key_tra.gang_prop = 0; gang.text = key_tra.gang_prop_akt; drehzahl.text = key_tra.gas_prop_akt; temp.text=key_tra.tempo_p_akt; mel.text=key_tra.meld_p}
            else if(event.key === Qt.Key_1) {key_tra.gang_prop = 1; gang.text = key_tra.gang_prop_akt; drehzahl.text = key_tra.gas_prop_akt; temp.text=key_tra.tempo_p_akt; km.text=key_tra.geskm_p; mel.text=key_tra.meld_p}
            else if(event.key === Qt.Key_2) {key_tra.gang_prop = 2; gang.text = key_tra.gang_prop_akt; drehzahl.text = key_tra.gas_prop_akt; temp.text=key_tra.tempo_p_akt; km.text=key_tra.geskm_p; mel.text=key_tra.meld_p}
            else if(event.key === Qt.Key_3) {key_tra.gang_prop = 3; gang.text = key_tra.gang_prop_akt; drehzahl.text = key_tra.gas_prop_akt; temp.text=key_tra.tempo_p_akt; km.text=key_tra.geskm_p; mel.text=key_tra.meld_p}
            else if(event.key === Qt.Key_4) {key_tra.gang_prop = 4; gang.text = key_tra.gang_prop_akt; drehzahl.text = key_tra.gas_prop_akt; temp.text=key_tra.tempo_p_akt; km.text=key_tra.geskm_p; mel.text=key_tra.meld_p}
            else if(event.key === Qt.Key_5) {key_tra.gang_prop = 5; gang.text = key_tra.gang_prop_akt; drehzahl.text = key_tra.gas_prop_akt; temp.text=key_tra.tempo_p_akt; km.text=key_tra.geskm_p; mel.text=key_tra.meld_p}

            if(gang.text === "-1") {rueck.visible=true; anzeigen.visible=false }
            else {rueck.visible=false; anzeigen.visible=true}

            //console.log("up gedrückt... \n")

//            gang.text = key_tra.gang_prop_akt
//            drehzahl.text = key_tra.gas_prop_akt
//            temp.text=key_tra.tempo_p_akt


        }   // ende Keys.onPressed

    }

    // ende Item it

}           // ende Window haupt
