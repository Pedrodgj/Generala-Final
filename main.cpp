#include <iostream>
#include<ctime>
#include <cstring>
#include <cstdlib>
#include<cstdio>
#include <ctype.h>
#include <wchar.h>
#include <locale.h>

#include "rlutil.h"
using namespace std;

#include "puntosMenu.h"
#include "puntajes.h"
#include "rondas.h"

int main()
{ //Menu general para jugar o ver puntajes
    rlutil::setBackgroundColor(2);
    string guardarPuntajes[5][3];

    int y=0 ;
    while(true)
    {
        rlutil::hidecursor();

        showItem("------MENU GENERALA------", 50, 10, y==0);
        showItem("JUEGO DE 1 JUGADOR       ", 50, 12, y==1);
        showItem("JUEGO DE 2 JUGADORES     ", 50, 14, y==2);
        showItem("RECORD DE PUNTAJES       ", 50, 16, y==3);
        showItem("COMBINACIONES DE PUNTAJES", 50, 18, y==4);
        showItem("MODO TEST                ", 50, 20, y==5);
        showItem("SALIR DEL JUEGO          ", 50, 22, y==6);

        int key = rlutil::getkey();
        switch(key)
        {
        case 14:
            rlutil::locate(48, 10 + y);
            std::cout<< " " <<std::endl;
            y--;
            if(y<0)
            {
                y=0;
            }
            break;
        case 15:
            rlutil::locate(48, 10 + y);
            std::cout<< " " <<std::endl;
            y++;
            if(y>6)
            {
                y=7;
            }
            break;
        case 1:
            switch(y)
            {
            case 1:
                jugarUnJugador(guardarPuntajes);
                break;
            case 2:
                jugarDosJugador(guardarPuntajes);
                break;
            case 3:
                mostrarRecord(guardarPuntajes);
                break;
            case 4:
                combinacionPuntaje();
                break;
            case 5:
                modoTest(guardarPuntajes);
                break;
            case 6:
                return 0;
                break;
            case 0:
                return 0;
                break;
            default:
                break;
            }
        default:
            break;
        }
    }
    return 0;
}

