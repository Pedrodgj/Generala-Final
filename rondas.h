#ifndef RONDAS_H_INCLUDED
#define RONDAS_H_INCLUDED

#include <string>
#include <iostream>
#include "puntajes.h"
#include "funciones.h"

int mayorPuntuacion = 0;
int mayorTiradas = 0;

int turnoCadaJugador(int rondas, string nombreJugador[3], int dado[], int Puntaje[], int nroJugador, int tiradaGeneral, int puntero = 0) {
    int resultado, opciones, result, tirada = 0;
    int contador = 0;
    int acumuladorPuntajes;
    int generalaServida = 0;

        system("cls");
        cout<<"Listo para lanzar los dados "<<endl;
        mostrarSoloJugador(nombreJugador, nroJugador); cout<<endl;
        system("pause");
        system("cls");

        acumuladorPuntajes = sumarPuntajes(Puntaje);

        cout<<"Turno de "; mostrarSoloJugador(nombreJugador, nroJugador);
        cout<<"  |  Ronda N"<<(char) 167<<" "<<rondas+1;
        cout<<"  |  Puntaje Total: "<<acumuladorPuntajes<<endl;
        //TODO: DESCOMENTAR CARGAR ALEATORIO Y COMENTAR CARGAR MANUAL
        //cargarManualmenteVector(dado);
        cargarAleatorio(dado, 5, 6);
        mostrarVector(dado, 5);
        cout<<endl;

        while(contador != 2) {
            rlutil::locate(1,14);
            tirada++;
            tiradaGeneral++;
            cout<<"Tirada N"<<(char) 167<<" : "<<tirada<<" -- Tiradas Totales: "<<tiradaGeneral<<endl;

            resultado = puntajesGanadores(dado, Puntaje);

            if(tirada == 1) {
                generalaServida = ganadorGenerala(dado, 5, nroJugador);
                if(generalaServida == 500) {
                    return generalaServida;
                } else if(puntero == 1){
                    return -1;
                }
            };

            cout<<"\n"<<(char) 168<<"Desea obtener el puntaje de esta combinacion o desea lanzar los dados de nuevo?"<<endl;
            cout<<"Presione 1 para obtener puntaje. Presione 2 para lanzar los dados de nuevo"<<endl;
            cin>>result;

                if(result == 2) {
                    cout<<(char) 168<<"Cuantos deseas modificar?"<<endl; cin>>opciones;
                    modificarDados(opciones, dado);
                    //system("pause");
                    system("cls");
                    cout<<"Turno de "; mostrarSoloJugador(nombreJugador, nroJugador);
                    cout<<"  |  Ronda N"<<(char) 167<<" "<<rondas+1;
                    cout<<"  |  Puntaje Total: "<<acumuladorPuntajes<<endl;
                    cout<<endl;
                    mostrarVector(dado, 5);
                    cout<<endl;
                    contador++;
                    if(contador == 2) {
                        tirada++,
                        tiradaGeneral++;
                    }
                } else {
                    contador = 2;
                };
            }

        system("cls");
        cout<<"Jugador: "; mostrarSoloJugador(nombreJugador, nroJugador);
        cout<<"  |  Ronda N"<<(char) 167<<" "<<rondas+1;
        cout<<"  |  Puntaje Total: "<<acumuladorPuntajes<<endl;
        mostrarVector(dado, 5);
        //aca en resultado guarda la cantidad de puntos que el participante
        //obtuvo y eligio de la ronda
        resultado = puntajesGanadores(dado, Puntaje, 1);
        Puntaje[resultado];

        system("pause");
        system("cls");

        contador = 0;
        return tiradaGeneral;

}

void guardarDatosGanadores(int puntos, string nombre[3], int tiradas, int nroJugador, string guardarPuntajes[1][3]) {

    string nuevosPuntos, nuevasTiradas;
    string nombreJugador;
    bool flag = false;

    if(guardarPuntajes[0][0] == "") {
        iniciarRegistroEn0(guardarPuntajes);
    }

    if(puntos == mayorPuntuacion) {
       if(tiradas < mayorTiradas) {
        flag = true;
        mayorTiradas = tiradas;
        mayorPuntuacion = puntos;
       }
    } else if (puntos > mayorPuntuacion) {
            mayorPuntuacion = puntos;
            mayorTiradas = tiradas;
            flag = true;
        }

//    nombreJugador = guardarNombreJugador(nombre, nroJugador);
    nuevosPuntos = to_string(puntos);
    nuevasTiradas = to_string(tiradas);


        if(guardarPuntajes[0][0]== "0" || flag == true) {
            guardarPuntajes[0][0] = nombre[nroJugador-1];
            guardarPuntajes[0][1] = nuevosPuntos;
            guardarPuntajes[0][2] = nuevasTiradas;
        }

}

void ganadorPartida(int ptosJugador1, string nombre[3], string puntajes[1][3], int totalTiradas, int nroJugador,
                    int ptosJugador2 = 0, int totalTiradas2 = 0, int nroJugador2 = 0) {

    cout<<"HORA DE SABER EL GANADOR"<<endl;
    system("pause");
    system("cls");

    cout<<"El jugador "; mostrarSoloJugador(nombre, nroJugador);
    guardarDatosGanadores(ptosJugador1, nombre, totalTiradas, nroJugador, puntajes);
    cout<<" obtuvo "<<ptosJugador1<<" puntos en "<<totalTiradas<<" tiradas en toda la partida"<<endl;

    if(ptosJugador2 != 0){
        guardarDatosGanadores(ptosJugador2, nombre, totalTiradas2, nroJugador2, puntajes);
        cout<<"El jugador "; mostrarSoloJugador(nombre, nroJugador2);
        cout<<" obtuvo "<<ptosJugador2<<" puntos en "<<totalTiradas2<<" tiradas en toda la partida"<<endl;
    }

    if(ptosJugador1 > ptosJugador2) {
        cout<<"El ganador es el jugador "; mostrarSoloJugador(nombre, nroJugador);
        cout<<" con un puntaje de "<<ptosJugador1<<" con un total de tiradas de "<<totalTiradas<<endl;
    } else {
        cout<<"El ganador es el jugador "; mostrarSoloJugador(nombre, nroJugador2);
        cout<<" con un puntaje de "<<ptosJugador2<<" con un total de tiradas de "<<totalTiradas2<<endl;
    }
}

void emptatePartida(int ptosJugador1, string nombre[3], string puntajes[1][3], int totalTiradas, int nroJugador,
                    int ptosJugador2 = 0, int totalTiradas2 = 0, int nroJugador2 = 0) {

    cout<<"HORA DE SABER EL GANADOR"<<endl;
    system("pause");
    system("cls");

    cout<<"El jugador "; mostrarSoloJugador(nombre, nroJugador);
    cout<<" obtuvo "<<ptosJugador1<<" puntos en "<<totalTiradas<<" tiradas en toda la partida"<<endl;
    guardarDatosGanadores(ptosJugador1, nombre, totalTiradas, nroJugador, puntajes);

    guardarDatosGanadores(ptosJugador2, nombre, totalTiradas2, nroJugador2, puntajes);
    cout<<"El jugador "; mostrarSoloJugador(nombre, nroJugador2);
    cout<<" obtuvo "<<ptosJugador2<<" puntos en "<<totalTiradas2<<" tiradas en toda la partida"<<endl;

    if(totalTiradas2 == totalTiradas) {
        cout<<"EL JUEGO HA SIDO UN EMPATE"<<endl;
    } else if(totalTiradas < totalTiradas2) {
        cout<<"EL GANADOR ES EL JUGADOR "; mostrarSoloJugador(nombre, nroJugador);
        cout<<" CON UN PUNTAJE DE "<<ptosJugador1<<" CON UN TOTAL DE TIRADAS DE "<<totalTiradas<<endl;
    } else {
        cout<<"EL GANADOR ES EL JUGADOR "; mostrarSoloJugador(nombre, nroJugador2);
        cout<<" CON UN PUNTAJE DE "<<ptosJugador2<<" CON UN TOTAL DE TIRADAS DE "<<totalTiradas2<<endl;
    }
}


#endif // RONDAS_H_INCLUDED
