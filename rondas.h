#ifndef RONDAS_H_INCLUDED
#define RONDAS_H_INCLUDED

#include <string>
#include <iostream>
#include "puntajes.h"
#include "funciones.h"

int mayorPuntuacion = 0;
int mayorTiradas = 0;

void empatePartida(int ptosJugador1, string nombre[3], string puntajes[1][3], int totalTiradas, int nroJugador,
                   int ptosJugador2 = 0, int totalTiradas2 = 0, int nroJugador2 = 0);

int turnoCadaJugador(int rondas, string nombreJugador[3], int dado[], int Puntaje[], int nroJugador, int tiradaGeneral, bool isTest = false, int puntero = 0)
{
    int resultado, opciones, result, tirada = 0;
    int contador = 0;
    int acumuladorPuntajes;
    int generalaServida = 0;

    system("cls");

    acumuladorPuntajes = sumarPuntajes(Puntaje);

    cout<<"Turno de ";
    mostrarSoloJugador(nombreJugador, nroJugador);
    cout<<"  |  Ronda N"<<(char) 167<<" "<<rondas+1;
    cout<<"  |  Puntaje Total: "<<acumuladorPuntajes<<endl;
    //TODO: DESCOMENTAR CARGAR ALEATORIO Y COMENTAR CARGAR MANUAL
    if(isTest) {
        cargarManualmenteVector(dado);
    } else {
        cargarAleatorio(dado, 5, 6);
    }

    mostrarVector(dado, 5);

    while(contador != 2)
    {
        rlutil::locate(1,14);
        tirada++;
        tiradaGeneral++;
        cout<<"Tirada N"<<(char) 167<<" : "<<tirada<<" -- Tiradas Totales: "<<tiradaGeneral<<endl;

        resultado = puntajesGanadores(dado, Puntaje);

        if(tirada == 1)
        {
            generalaServida = ganadorGenerala(dado, 5, nroJugador);
            if(generalaServida == 500)
            {
                return generalaServida;
            }
            else if(puntero == 1)
            {
                return -1;
            }
        }

        result = eleccionOpc();

        if(result == 2)
        {
            mostrarVector(dado, 5);
            cout<<"\t"<<(char) 168<<"Cuantos deseas modificar?"<<endl; //cin>>opciones;
            opciones = lanzarDadosDeNuevo();
            modificarDados(opciones, dado, isTest);
            system("cls");
            cout<<"Turno de ";
            mostrarSoloJugador(nombreJugador, nroJugador);
            cout<<"  |  Ronda N"<<(char) 167<<" "<<rondas+1;
            cout<<"  |  Puntaje Total: "<<acumuladorPuntajes<<endl;
            cout<<endl;
            mostrarVector(dado, 5);
            cout<<endl;
            contador++;
            if(contador == 2)
            {
                tirada++,
                       tiradaGeneral++;
            }
        }
        else
        {
            contador = 2;
        }
    }

    system("cls");
    cout<<"\n Jugador: ";
    mostrarSoloJugador(nombreJugador, nroJugador);
    cout<<"  |  Ronda N"<<(char) 167<<" "<<rondas+1;
    cout<<"  |  Puntaje Total: "<<acumuladorPuntajes<<endl;
    mostrarVector(dado, 5);
    //aca en resultado guarda la cantidad de puntos que el participante
    //obtuvo y eligio de la ronda
    resultado = puntajesGanadores(dado, Puntaje, 1, true);
    Puntaje[resultado];

    system("cls");

    contador = 0;
    return tiradaGeneral;
}

void guardarDatosGanadores(int puntos, string nombre[3], int tiradas, int nroJugador, string guardarPuntajes[][3])
{

    string nuevosPuntos, nuevasTiradas;
    string nombreJugador;
    bool flag = false;

    if(guardarPuntajes[0][0] == "")
    {
        iniciarRegistroEn0(guardarPuntajes);
    }

    if(puntos == mayorPuntuacion)
    {
        if(tiradas < mayorTiradas)
        {
            flag = true;
            mayorTiradas = tiradas;
            mayorPuntuacion = puntos;
        }
    }
    else if (puntos > mayorPuntuacion)
    {
        mayorPuntuacion = puntos;
        mayorTiradas = tiradas;
        flag = true;
    }

//    nombreJugador = guardarNombreJugador(nombre, nroJugador);
    nuevosPuntos = to_string(puntos);
    nuevasTiradas = to_string(tiradas);


    if(guardarPuntajes[0][0]== "0" || flag == true)
    {
        guardarPuntajes[0][0] = nombre[nroJugador-1];
        guardarPuntajes[0][1] = nuevosPuntos;
        guardarPuntajes[0][2] = nuevasTiradas;
    }

}

void ganadorPartida(int ptosJugador1, string nombre[3], string puntajes[][3], int totalTiradas, int nroJugador,
                    int ptosJugador2 = 0, int totalTiradas2 = 0, int nroJugador2 = 0)
{
//    system("pause");
    system("cls");
    if(ptosJugador1 == ptosJugador2)
    {
        empatePartida(ptosJugador1, nombre, puntajes, totalTiradas, nroJugador,
                      ptosJugador2, totalTiradas2, nroJugador2);
        return;
    }
    centrarTexto("HORA DE SABER EL GANADOR");
    system("pause");
    system("cls");

    cout<<"El jugador ";
    mostrarSoloJugador(nombre, nroJugador);
    guardarDatosGanadores(ptosJugador1, nombre, totalTiradas, nroJugador, puntajes);
    cout<<" obtuvo "<<ptosJugador1<<" puntos en "<<totalTiradas<<" tiradas en toda la partida"<<endl;

    if(ptosJugador2 != 0)
    {
        cout<<endl;
        guardarDatosGanadores(ptosJugador2, nombre, totalTiradas2, nroJugador2, puntajes);
        cout<<"El jugador ";
        mostrarSoloJugador(nombre, nroJugador2);
        cout<<" obtuvo "<<ptosJugador2<<" puntos en "<<totalTiradas2<<" tiradas en toda la partida"<<endl;
    }

    if(ptosJugador1 > ptosJugador2)
    {
        cout<<endl;
        centrarTexto("El ganador es el jugador ", 10);
        mostrarSoloJugador(nombre, nroJugador, true, 11);
        centrarTexto("Con un puntaje de: ", 12);
        centrarTexto(to_string(ptosJugador1),13);
        centrarTexto("Con un total de tiradas de: ",14);
        centrarTexto(to_string(totalTiradas), 15);
    }
    else
    {
        cout<<endl;
        centrarTexto("El ganador es el jugador ", 10);
        mostrarSoloJugador(nombre, nroJugador2, true, 11);
        centrarTexto("Con un puntaje de: ", 12);
        centrarTexto(to_string(ptosJugador2), 13);
        centrarTexto("Con un total de tiradas de: ",14);
        centrarTexto(to_string(totalTiradas2), 15);
    }
}

void empatePartida(int ptosJugador1, string nombre[3], string puntajes[1][3], int totalTiradas, int nroJugador,
                   int ptosJugador2, int totalTiradas2, int nroJugador2)
{

    cout<<"HORA DE SABER EL GANADOR"<<endl;
    system("pause");
    system("cls");

    cout<<"El jugador ";
    mostrarSoloJugador(nombre, nroJugador);
    cout<<" obtuvo "<<ptosJugador1<<" puntos en "<<totalTiradas<<" tiradas en toda la partida"<<endl;
    guardarDatosGanadores(ptosJugador1, nombre, totalTiradas, nroJugador, puntajes);

    guardarDatosGanadores(ptosJugador2, nombre, totalTiradas2, nroJugador2, puntajes);
    cout<<"El jugador ";
    mostrarSoloJugador(nombre, nroJugador2);
    cout<<" obtuvo "<<ptosJugador2<<" puntos en "<<totalTiradas2<<" tiradas en toda la partida"<<endl;

    if(totalTiradas2 == totalTiradas)
    {
        cout<<endl;
        cout<<endl;
        cout<<"EL JUEGO HA SIDO UN EMPATE"<<endl;
    }
    else if(totalTiradas < totalTiradas2)
    {
        cout<<endl;
        cout<<endl;
        cout<<"EL GANADOR ES EL JUGADOR ";
        mostrarSoloJugador(nombre, nroJugador);
        cout<<" CON UN PUNTAJE DE "<<ptosJugador1<<" CON UN TOTAL DE TIRADAS DE "<<totalTiradas<<endl;
    }
    else
    {
        cout<<endl;
        cout<<endl;
        cout<<"EL GANADOR ES EL JUGADOR ";
        mostrarSoloJugador(nombre, nroJugador2);
        cout<<" CON UN PUNTAJE DE "<<ptosJugador2<<" CON UN TOTAL DE TIRADAS DE "<<totalTiradas2<<endl;
    }
}



#endif // RONDAS_H_INCLUDED
