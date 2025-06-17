#include <iostream>
#include <cstdlib>
#include "rlutil.h"
#include "interfaz.h"


using namespace std;


void opcionMenu(){
    int y = 0, opcion = 1;

    rlutil::hidecursor();
    rlutil::saveDefaultColor();

    do{
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
        rlutil::hidecursor();

        seleccionar("OPCION 1", 50, 16, y == 0);
        seleccionar("OPCION 2", 50, 17, y == 1);
        seleccionar("OPCION 3", 50, 18, y == 2);
        seleccionar("SALIR DEL PROGRAMA", 50, 19, y == 3);

        switch(rlutil::getkey()){
            case rlutil::KEY_UP:
                y--;
                if(y<0) y=0;
                break;

            case rlutil::KEY_DOWN:
                y++;
                if(y>3) y=3;
                break;

            case rlutil::KEY_ENTER:

                switch(y){
                    case 0:
                        rlutil::cls();
                        break;
                    case 1:
                        rlutil::cls();

                        break;
                    case 2:
                        rlutil::cls();
                        break;
                    case 3:
                        opcion = 0;
                        rlutil::cls();
                        cout<<"GRACIAS POR USAR EL PROGRAMA :-)"<<endl;
                        break;
            }
        }
    }while(opcion!=0);
}

