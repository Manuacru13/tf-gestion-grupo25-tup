#include <iostream>
#include "interfaz.h"
#include "rlutil.h"

using namespace std;

void seleccionar(const char* texto, int posX, int posY, bool elegido){

    if(elegido){
        rlutil::setBackgroundColor(rlutil::BROWN);
        rlutil::locate(posX - 2, posY);
        cout<< char (175) << " " << " " << endl;
    }else{
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::locate(posX - 2, posY);
        cout<< " " << " " <<endl;
    }

    rlutil::locate(posX, posY);
    cout<< texto <<endl;
    rlutil::setBackgroundColor(rlutil::BLACK);
}
