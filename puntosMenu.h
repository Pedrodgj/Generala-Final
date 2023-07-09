#ifndef PUNTOSMENU_H_INCLUDED
#define PUNTOSMENU_H_INCLUDED

#include<string>
#include "funciones.h"
#include "puntajes.h"
#include "rondas.h"

//
//string nombreJugador[3];
//string guardarPuntajes[1][3];
////int puntajesFinal[100][2];
//int Puntaje1[10];
//int Puntaje2[10];
//int rondas, tirada1, tirada2;
//int acumuladorPuntajes1, acumuladorPuntajes2;
//int jugador1, jugador2;

//Jugador 1
void jugarUnJugador(string guardarPuntajes[][3], bool isTest = false)
{
    string nombreJugador[3];
//    string guardarPuntajes[1][3];
    //int puntajesFinal[100][2];
    int Puntaje1[10];
//    int Puntaje2[10];
    int tirada1;
    int acumuladorPuntajes1;
    int jugador1;
    int dado1[5];
    int rondas = 0;
    int tiradaAnterior = 1;
    bool flag = false;

    jugador1 = 0, tirada1 = 0;
    acumuladorPuntajes1 = 0;

    system("cls");

//     cout<<"Ingrese nombre del jugador 1 "; cargarNombreJugador(nombreJugador, 0);
    const string ingresaNombre = "Ingrese nombre del jugador 1 ";
    centrarTexto(ingresaNombre);
    cargarNombreJugador(nombreJugador, 0);

    flag = puntajesEnCero(Puntaje1, flag);

    while(rondas != 10)
    {

        if(isTest)
        {
            tirada1 = turnoCadaJugador(rondas, nombreJugador, dado1, Puntaje1, 1, tirada1, true);
        }
        else
        {
            tirada1 = turnoCadaJugador(rondas, nombreJugador, dado1, Puntaje1, 1, tirada1);
        }
        if(tirada1 != 500)
        {
            tiradaAnterior = tirada1+1;
        };

        if(tirada1 == 500)
        {
            cout<<"Estas en generala"<<endl;
            rondas = 10;
        }
        else
        {

            acumuladorPuntajes1 = sumarPuntajes(Puntaje1);
            cout<<"Los puntos del participante ";
            mostrarSoloJugador(nombreJugador, 1);
            cout<<" "<<acumuladorPuntajes1;
            mostrarPuntajes(Puntaje1);
            cout<<"Tirada General "<<tirada1<<" -- Ronda: "<<rondas+1<<endl;
            system("pause");
            rondas++;
        }
    }
    if(tirada1 == 500)
    {
        system("pause");
        ganadorPartida(500, nombreJugador, guardarPuntajes, tiradaAnterior, 1);
    }
    else
    {
        jugador1 = sumarPuntajes(Puntaje1);
        ganadorPartida(jugador1, nombreJugador, guardarPuntajes, tirada1, 1);
    }
    system("pause");
    system("cls");
}


//Jugador 2
void jugarDosJugador(string guardarPuntajes[][3])
{
    string nombreJugador[3];
    int Puntaje1[10];
    int Puntaje2[10];
    int dado1[5], dado2[5];
    bool flag1 = false, flag2 = false;
    int rondas  = 0, tirada1 = 0, tirada2 = 0;
    int acumuladorPuntajes1 = 0, acumuladorPuntajes2 = 0;
    int jugador1 = 0, jugador2 = 0;
    int tiradaAnterior1 = 1, tiradaAnterior2 = 1;
    int puntero = 0;

    system("cls");

    centrarTexto("Ingrese nombre del jugador 1 ");
    cargarNombreJugador(nombreJugador, 0);
    centrarTexto("Ingrese nombre del jugador 2 ", 4);
    cargarNombreJugador(nombreJugador, 1, 5);

    system("pause");

    system("cls");

    flag1 = puntajesEnCero(Puntaje1, flag1);
    flag2 = puntajesEnCero(Puntaje2, flag2);


    //aca empieza el ciclo de las 10 rondas del juego
    while(rondas != 10)
    {

        centrarTexto("Proximo Turno de: ", 6);
        mostrarSoloJugador(nombreJugador, 1, true, 7);
        centrarTexto("Los puntos del participante: ", 9);
        centrarTexto(to_string(acumuladorPuntajes1), 10);

        centrarTexto("Tirada General del siguiente participante: ", 12);
        centrarTexto(to_string(tirada1), 13);
        centrarTexto("Ronda: ", 14);
        centrarTexto(to_string(rondas+1), 15);
        centrarTexto("Listo para lanzar los dados ", 17);
//        mostrarSoloJugador(nombreJugador, nroJugador, true,18);
        system("pause");
        system("cls");


        tirada1 = turnoCadaJugador(rondas, nombreJugador, dado1, Puntaje1, 1, tirada1);

        if(tirada1 != 500)
        {
            tiradaAnterior1 = tirada1+1;
        }

        if(tirada1 == 500)
        {
            puntero = 1;
        }
        else
        {

            acumuladorPuntajes1 = sumarPuntajes(Puntaje1);
            cout<<"\nLos puntos del partipante ";
            mostrarSoloJugador(nombreJugador, 1);
            cout<<" "<<acumuladorPuntajes1<<endl;
            mostrarPuntajes(Puntaje1);
            system("pause");
            system("cls");
        }

        centrarTexto("Proximo Turno de: ", 6);
        mostrarSoloJugador(nombreJugador, 2, true, 7);
        centrarTexto("Los puntos del participante: ", 9);
        centrarTexto(to_string(acumuladorPuntajes2), 10);

        centrarTexto("Tirada General del siguiente participante: ", 12);
        centrarTexto(to_string(tirada2), 13);
        centrarTexto("Ronda: ", 14);
        centrarTexto(to_string(rondas+1), 15);
        centrarTexto("Listo para lanzar los dados ", 17);
        system("pause");
        system("cls");

        tirada2 = turnoCadaJugador(rondas, nombreJugador, dado2, Puntaje2, 2, tirada2, false, puntero);
        rondas++;

        if(tirada2 != 500)
        {
            tiradaAnterior2 = tirada2+1;
        }

        if(tirada2 == 500)
        {
            rondas = 10;
        }
        else if(tirada2 == -1)
        {
            system("cls");
            cout<<"NO HA SIDO UNA GENERALA SERVIDA."<<endl;
            rondas = 10;
        }
        else
        {

            acumuladorPuntajes2 = sumarPuntajes(Puntaje2);
            cout<<"Los puntos del partipante ";
            mostrarSoloJugador(nombreJugador, 2);
            cout<<" "<<acumuladorPuntajes2<<endl;
            mostrarPuntajes(Puntaje2);
            system("pause");
            system("cls");
        }

    }

    jugador1 = sumarPuntajes(Puntaje1);
    jugador2 = sumarPuntajes(Puntaje2);

    if(tirada1 == 500 && tirada2 == 500)
    {
        empatePartida(500, nombreJugador, guardarPuntajes, tiradaAnterior1, 1, 500, tiradaAnterior2, 2);
    }
    else if(tirada1 == 500)
    {
        ganadorPartida(500, nombreJugador, guardarPuntajes, tiradaAnterior1, 1, jugador2, tiradaAnterior2, 2);
    }
    else if(tirada2 == 500)
    {
        ganadorPartida(jugador1, nombreJugador, guardarPuntajes, tirada1, 1, 500, tiradaAnterior2, 2);
    }
    else
    {
        ganadorPartida(jugador1, nombreJugador, guardarPuntajes, tirada1, 1, jugador2, tirada2, 2);
    }

    system("pause");
    system("cls");
}

//Mostrar Record de puntaje
void mostrarRecord (string guardarPuntajes[][3])
{
    int i, j;

    system("cls");

    for(i=0; i<1; i++)
    {
        if(guardarPuntajes[i][0] != "0")
        {
            cout<<"MAYOR PUNTUACION "<<endl;
        }
        for(j=0; j<1; j++)
        {
            if(guardarPuntajes[i][j] != "0")
            {
                cout<<"Nombre: "<<guardarPuntajes[i][0]<<endl;
                cout<<"Puntos: "<<guardarPuntajes[i][1]<<endl;
                cout<<"Tiradas: "<<guardarPuntajes[i][2]<<endl;
                cout<<"----------------"<<endl;
            }
        }
    }

    system("pause");
    system("cls");

}

//COmbinacion puntajes
void combinacionPuntaje ()
{

    system("cls");

    cout<<"Las combinaciones ganadores son:"<<endl;
    cout<<"COMBINACION:"<<"\t\t\t\t"<<"NOMBRE JUGADA"<<"\t\t\t"<<"PUNTAJE OTORGADO"<<endl;
    cout<<"1 o mas dados con valor"<<"\t\t\t"<<"Juego de 1"<<"\t\t\t"<<"Suma de la cantidad de dados con el valor 1"<<endl;
    cout<<"1 o mas dados con valor"<<"\t\t\t"<<"Juego de 2"<<"\t\t\t"<<"2*suma cantidad de dados con valor 2"<<endl;
    cout<<"1 o mas dados con valor"<<"\t\t\t"<<"Juego de 3"<<"\t\t\t"<<"3*suma cantidad de dados con valor 3"<<endl;
    cout<<"1 o mas dados con valor"<<"\t\t\t"<<"Juego de 4"<<"\t\t\t"<<"4*suma cantidad de dados con valor 4"<<endl;
    cout<<"1 o mas dados con valor"<<"\t\t\t"<<"Juego de 5"<<"\t\t\t"<<"5*suma cantidad de dados con valor 5"<<endl;
    cout<<"1 o mas dados con valor"<<"\t\t\t"<<"Juego de 6"<<"\t\t\t"<<"6*suma cantidad de dados con valor 6"<<endl;
    cout<<"5 dados en orden creciente"<<"\t\t"<<"Escalera"<<"\t\t\t"<<"25"<<endl;
    cout<<"3 dados iguales, mas otros 2 iguales"<<"\t"<<"Full"<<"\t\t\t\t"<<"30"<<endl;
    cout<<"4 dados iguales"<<"\t\t\t\t"<<"Poker"<<"\t\t\t\t"<<"40"<<endl;
    cout<<"5 dados con el mismo valor"<<"\t\t"<<"Generala"<<"\t\t\t"<<"50"<<endl;

    system("pause");
    system("cls");
}

void modoTest(string guardarPuntajes[][3])
{

    system("cls");
    cout<<"Esta entrando en modo Test. Presione una tecla para continuar"<<endl;
    cin.ignore(1000, '\n');
    cin.clear();
    jugarUnJugador(guardarPuntajes, true);
}


#endif // PUNTOSMENU_H_INCLUDED
