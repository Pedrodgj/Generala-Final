#ifndef PUNTOSMENU_H_INCLUDED
#define PUNTOSMENU_H_INCLUDED

#include "funciones.h"
#include "puntajes.h"
#include "rondas.h"

string nombreJugador[2];
string guardarPuntajes[1][3];
//int puntajesFinal[100][2];
int Puntaje1[10];
int Puntaje2[10];
int rondas, tirada1, tirada2;
int acumuladorPuntajes1, acumuladorPuntajes2;
int jugador1, jugador2;

//Jugador 1
void jugarUnJugador() {
    int dado1[5];
    int rondas = 0;
    int tiradaAnterior = 1;
    bool flag = false;

    jugador1 = 0, tirada1 = 0;
    acumuladorPuntajes1 = 0;

    system("cls");

    cout<<"Ingrese nombre del jugador 1 "; cargarNombreJugador(nombreJugador, 0);

    flag = puntajesEnCero(Puntaje1, flag);

    while(rondas != 10) {


        tirada1 = turnoCadaJugador(rondas, nombreJugador, dado1, Puntaje1, 1, tirada1);
        if(tirada1 != 500) {
            tiradaAnterior = tirada1+1;
        };

        if(tirada1 == 500) {
            cout<<"Estas en generala"<<endl;
            rondas = 10;
        } else {

            acumuladorPuntajes1 = sumarPuntajes(Puntaje1);
            cout<<"Los puntos del participante "; mostrarSoloJugador(nombreJugador, 1);
            cout<<" "<<acumuladorPuntajes1;
            mostrarPuntajes(Puntaje1);
            cout<<"Tirada General "<<tirada1<<" -- Ronda: "<<rondas+1<<endl;
            system("pause");
            rondas++;
        }
    }
    if(tirada1 == 500) {
        ganadorPartida(500, nombreJugador, guardarPuntajes, tiradaAnterior, 1);
    } else {
        jugador1 = sumarPuntajes(Puntaje1);
        ganadorPartida(jugador1, nombreJugador, guardarPuntajes, tirada1, 1);
    }
    system("pause");
    system("cls");
};


//Jugador 2
void jugarDosJugador() {
    int dado1[5], dado2[5];
    bool flag1 = false, flag2 = false;
    int rondas  = 0, tirada1 = 0, tirada2 = 0;
    int acumuladorPuntajes1 = 0, acumuladorPuntajes2 = 0;
    int jugador1 = 0, jugador2 = 0;
    int tiradaAnterior1 = 1, tiradaAnterior2 = 1;
    int puntero = 0;

    system("cls");

    cout<<"Ingrese nombre del jugador 1 "; cargarNombreJugador(nombreJugador, 0);
    cout<<"Ingrese nombre del jugador 2 "; cargarNombreJugador(nombreJugador, 1);
    //mostrarNombresJugadores(nombreJugador, 2);
    system("pause");

    system("cls");
    cout<<"Listo para ser dos jugadores"<<endl;
    system("pause");
    system("cls");

    flag1 = puntajesEnCero(Puntaje1, flag1);
    flag2 = puntajesEnCero(Puntaje2, flag2);


    //aca empieza el ciclo de las 10 rondas del juego
    while(rondas != 10) {

        tirada1 = turnoCadaJugador(rondas, nombreJugador, dado1, Puntaje1, 1, tirada1);

        if(tirada1 != 500) {
            tiradaAnterior1 = tirada1+1;
        };

        if(tirada1 == 500) {
            cout<<"Estas en generala"<<endl;
            puntero = 1;
        } else {

            acumuladorPuntajes1 = sumarPuntajes(Puntaje1);
            cout<<"\nLos puntos del partipante "; mostrarSoloJugador(nombreJugador, 1);
            cout<<" "<<acumuladorPuntajes1<<endl;
            mostrarPuntajes(Puntaje1);
            system("pause");
            system("cls");
            cout<<"\nLos puntos del partipante "; mostrarSoloJugador(nombreJugador, 1);
            cout<<" "<<acumuladorPuntajes1<<endl;
        }

        cout<<"\nProximo Turno de: "; mostrarSoloJugador(nombreJugador, 2);
        cout<<"\nLos puntos del partipante "; mostrarSoloJugador(nombreJugador, 2);
        cout<<" "<<acumuladorPuntajes2<<endl;
        cout<<"Tirada General "<<tirada2<<" -- Ronda: "<<rondas+1<<endl;
        system("pause");
        system("cls");

        tirada2 = turnoCadaJugador(rondas, nombreJugador, dado2, Puntaje2, 2, tirada2, puntero);

        if(tirada2 != 500) {
            tiradaAnterior2 = tirada2+1;
        };

        if(tirada2 == 500) {
            cout<<"Estas en generala"<<endl;
            rondas = 10;
        } else if(tirada2 == -1) {
            system("cls");
            cout<<"NO HA SIDO UNA GENERALA SERVIDA."<<endl;
            rondas = 10;
        } else {

            acumuladorPuntajes2 = sumarPuntajes(Puntaje2);
            cout<<"Los puntos del partipante "; mostrarSoloJugador(nombreJugador, 2);
            cout<<" "<<acumuladorPuntajes2<<endl;
            mostrarPuntajes(Puntaje2);
            system("pause");
            system("cls");
            cout<<"Los puntos del partipante "; mostrarSoloJugador(nombreJugador, 2);
            cout<<" "<<acumuladorPuntajes2<<endl;
            cout<<endl;

        }

        if(rondas != 10) {
            cout<<"\nProximo Turno de: "; mostrarSoloJugador(nombreJugador, 1);
            cout<<"\nLos puntos del participante "; mostrarSoloJugador(nombreJugador, 1);
            cout<<" "<<acumuladorPuntajes1<<endl;
            cout<<"Tirada General "<<tirada1<<" -- Ronda: "<<rondas+1<<endl;
            system("pause");
            system("cls");

            rondas++;
        }
    }

    jugador1 = sumarPuntajes(Puntaje1);
    jugador2 = sumarPuntajes(Puntaje2);

    if(tirada1 == 500 && tirada2 == 500) {
        emptatePartida(500, nombreJugador, guardarPuntajes, tiradaAnterior1, 1, 500, tiradaAnterior2, 2);
    } else if(tirada1 == 500) {
        ganadorPartida(500, nombreJugador, guardarPuntajes, tiradaAnterior1, 1, jugador2, tiradaAnterior2, 2);
    } else if(tirada2 == 500) {
        ganadorPartida(jugador1, nombreJugador, guardarPuntajes, tirada1, 1, 500, tiradaAnterior2, 2);
    } else {
        ganadorPartida(jugador1, nombreJugador, guardarPuntajes, tirada1, 1, jugador2, tirada2, 2);
    }

    system("pause");
    system("cls");
};

//Mostrar Record de puntaje
void mostrarRecord () {
    int i, j;

    system("cls");

    for(i=0; i<1; i++) {
        if(guardarPuntajes[i][0] != "0") {
            cout<<"MAYOR PUNTUACION "<<endl;
        }
        for(j=0;j<1;j++) {
            if(guardarPuntajes[i][j] != "0") {
                cout<<"Nombre: "<<guardarPuntajes[i][0]<<endl;
                cout<<"Puntos: "<<guardarPuntajes[i][1]<<endl;
                cout<<"Tiradas: "<<guardarPuntajes[i][2]<<endl;
                cout<<"----------------"<<endl;
            }
        }
    }

    system("pause");
    system("cls");

};

//Reglas generala
void reglasGeneral () {

    system("cls");

    cout<<"Las reglas del juego son: "<<endl;
    cout<<"El objetivo de la Generala es obtener la puntuación más alta en la menor cantidad de"
            "tiradas posibles, siendo una generala servida condición inmediata de victoria sin"
            "importar la ronda que se esté jugando."<<endl;
    cout<<"Una ronda puede estar compuesta por hasta tres tiradas por persona."<<endl;
    cout<<"La tirada inicial de la ronda consiste en lanzar los cinco dados y evaluar sus "
            "valores para determinar el puntaje. En caso de que la persona considere, "
            "puede volver a tirar todos o algunos de los dados en dos oportunidades más. "
            "El programa tiene que preguntar si quiere volver a lanzar, y si la respuesta es "
            "sí, preguntar cuántos y cuáles son los dados que desea volver a tirar."<<endl;
    cout<<"El puntaje de un lanzamiento está determinado por una serie de reglas que "
            "figuran en la sección Combinaciones ganadoras."<<endl;
    cout<<"Tras cada tirada el sistema debe ofrecer la posibilidad de anotar puntuación."<<endl;
    cout<<"Si una persona saca Generala en la primera tirada de una ronda gana la "
            "partida. Si al jugar la modalidad ‘Juego nuevo entre 2’ la primera persona que "
            "realiza una tirada al comenzar una ronda saca generala servida, el programa "
            "deberá darle la oportunidad a la segunda persona de hacer una tirada para "
            "sacar generala servida y poder empatar, para evitar una posible ventaja por "
            "jugar en primer lugar."<<endl;

            system("pause");
            system("cls");

};

//COmbinacion puntajes
void combinacionPuntaje () {

    system("cls");

    cout<<"Las combinaciones ganadores son:"<<endl;
    cout<<"COMBINACION:"<<"\t\t\t\t"<<"NOMBRE JUGADA"<<"\t\t\t"<<"PUNTAJE OTORGADO"<<endl;
    cout<<"1 ó más dados con valor"<<"\t\t\t"<<"Juego de 1"<<"\t\t\t"<<"Suma de la cantidad de dados con el valor 1"<<endl;
    cout<<"1 ó más dados con valor"<<"\t\t\t"<<"Juego de 2"<<"\t\t\t"<<"2*suma cantidad de dados con valor 2"<<endl;
    cout<<"1 ó más dados con valor"<<"\t\t\t"<<"Juego de 3"<<"\t\t\t"<<"3*suma cantidad de dados con valor 3"<<endl;
    cout<<"1 ó más dados con valor"<<"\t\t\t"<<"Juego de 4"<<"\t\t\t"<<"4*suma cantidad de dados con valor 4"<<endl;
    cout<<"1 ó más dados con valor"<<"\t\t\t"<<"Juego de 5"<<"\t\t\t"<<"5*suma cantidad de dados con valor 5"<<endl;
    cout<<"1 ó más dados con valor"<<"\t\t\t"<<"Juego de 6"<<"\t\t\t"<<"6*suma cantidad de dados con valor 6"<<endl;
    cout<<"5 dados en orden creciente"<<"\t\t"<<"Escalera"<<"\t\t\t"<<"25"<<endl;
    cout<<"3 dados iguales, más otros 2 iguales"<<"\t"<<"Full"<<"\t\t\t\t"<<"30"<<endl;
    cout<<"4 dados iguales"<<"\t\t\t\t"<<"Póker"<<"\t\t\t\t"<<"40"<<endl;
    cout<<"5 dados con el mismo valor"<<"\t\t"<<"Generala"<<"\t\t\t"<<"50"<<endl;

    system("pause");
    system("cls");
};


#endif // PUNTOSMENU_H_INCLUDED
