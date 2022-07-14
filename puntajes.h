#ifndef PUNTAJES_H_INCLUDED
#define PUNTAJES_H_INCLUDED

#include "funciones.h"
#include "puntosMenu.h"


int generala (int dado[]) {
    int j, primerIndice;
    int contador = 0;

    primerIndice = dado[0];
    for(j = 0; j < 5; j++) {
        if(dado[j]==primerIndice) {
            contador++;
        }
    }

    if(contador == 5) {
        cout<<"Es una generala"<<endl;
        return 50;
    } else {
    return 0;
    }
};

int poker(int dado[]) {
    int i, contador = 0;
    int recorrerValores;

    if (dado[0] != dado[1]) {
        recorrerValores = dado[1];
    } if(dado[0] == dado[2]) {
        recorrerValores = dado[0];
    } if (dado[0] == dado[1]){
        recorrerValores = dado[0];
    };

    for(i = 0; i < 5; i++) {
        if(dado[i] == recorrerValores) {
            contador++;
            recorrerValores = dado[i];
        }
    };

    if(contador == 4) {
        return 40;
    } else {
        return 0;
    };
}

int full(int dado[]) {
    int i;
    int fullA = 0, fullB = 0;
    int contadorA = 0, contadorB = 0;

    for(i = 0; i < 5; i++) {
        if(fullA == 0) {
            fullA = dado[i];
        }
        if(fullB == 0 && fullA != dado[i]) {
            fullB = dado[i];
        }
        if(fullA == dado[i]) {
            contadorA++;
        }
        if(fullB == dado[i]) {
            contadorB++;
        }
    };
    if(contadorA == 2 && contadorB == 3) {
        return 30;
    } else if (contadorA == 3 && contadorB == 2) {
        return 30;
    } else {
        return 0;
    };
}

int escalera (int dado[]) {
    int i, j, k;
    int primerValorEscalera = 0;
    int contador = 0;
    int copiaDado[5];

    for(j = 0; j<5; j++){
        copiaDado[j] = dado[j];
    };

    ordenarVector(dado, 5);

    primerValorEscalera = dado[0];

    for(i = 0; i < 5; i++) {
        if(dado[i] == primerValorEscalera) {
            contador++;
            primerValorEscalera += 1;
        }
    }
    if(contador == 5) {
        for(k=0; k<5; k++){
            dado[k] = copiaDado[k];
        };
        return 25;
    } else {
        for(k=0; k<5; k++){
            dado[k] = copiaDado[k];
        };
        return 0;
    }
}

int juegoDe1 (int dado[]) {
    int i, acumulador = 0;
    for(i = 0; i < 5; i++) {
        if(dado[i] == 1) {
            acumulador++;
        };
    }
        if(acumulador == 0) {
            return 0;
        } else {
            return acumulador;
        };
}

int juegoDe2 (int dado[]) {
    int i, acumulador = 0;
    for(i = 0; i < 5; i++) {
        if(dado[i] == 2) {
            acumulador += dado[i];
        };
    }
        if(acumulador == 0) {
            return 0;
        } else {
            return acumulador;
        };
}

int juegoDe3 (int dado[]) {
    int i, acumulador = 0;
    for(i = 0; i < 5; i++) {
        if(dado[i] == 3) {
            acumulador += dado[i];
        };
    }
        if(acumulador == 0) {
            return 0;
        } else {
            return acumulador;
        };
}

int juegoDe4 (int dado[]) {
    int i, acumulador = 0;
    for(i = 0; i < 5; i++) {
        if(dado[i] == 4) {
            acumulador += dado[i];
        };
    }
        if(acumulador == 0) {
            return 0;
        } else {
            return acumulador;
        };
}

int juegoDe5 (int dado[]) {
    int i, acumulador = 0;
    for(i = 0; i < 5; i++) {
        if(dado[i] == 5) {
            acumulador += dado[i];
        };
    }
        if(acumulador == 0) {
            return 0;
        } else {
            return acumulador;
        };
}

int juegoDe6 (int dado[]) {
    int i, acumulador = 0;
    for(i = 0; i < 5; i++) {
        if(dado[i] == 6) {
            acumulador += dado[i];
        };
    }
        if(acumulador == 0) {
            return 0;
        } else {
            return acumulador;
        };
}

void puntuacionesNombres (string puntajesNombre[], int V[], int dado[], int puntajes[]) {
    int j, i;
    string noPuntajes[10];

    puntajesNombre[0] = "Juego de 1";
    puntajesNombre[1] = "Juego de 2";
    puntajesNombre[2] = "Juego de 3";
    puntajesNombre[3] = "Juego de 4";
    puntajesNombre[4] = "Juego de 5";
    puntajesNombre[5] = "Juego de 6";
    puntajesNombre[6] = "Escalera";
    puntajesNombre[7] = "Full";
    puntajesNombre[8] = "Poker";
    puntajesNombre[9] = "Generala";

    //aca en este array se guardan todos los valores posibles de cada combinacion de cada ronda
    V[9] = generala(dado);
    V[8] = poker(dado);
    V[7] = full(dado);
    V[6] = escalera(dado);
    V[5] = juegoDe6(dado);
    V[4] = juegoDe5(dado);
    V[3] = juegoDe4(dado);
    V[2] = juegoDe3(dado);
    V[1] = juegoDe2(dado);
    V[0] = juegoDe1(dado);

    for(i=0; i < 10; i++) {
        if(puntajes[i] == -1) {
            noPuntajes[i] = "Combinacion Disponible";
        } else {
            noPuntajes[i] = "Combinacion no Disponible";
        }
    }

    //TODO: ACA SE TIENE QUE BUSCAR LA MANERA DE NOMBRAR CADA INDICE COMO UNA COMBINACION GANADORA
    for(j = 0; j < 10; j++) {

        cout<<"\n"<<j + 1<<" "<<puntajesNombre[j]<<" Puntaje: "<<V[j]<<"   -------    "<<noPuntajes[j]<<endl;
    }
}

//funcion para llamar a los puntajes de cada combinacion de dados
//y poder guardar el valor de cada combinacion en un array
int puntajesGanadores(int dado[], int puntajes[], int result = -1) {
    int eleccion, nIndice;
    int V[10];
    bool flag = false;
    string puntajesNombre[10];

    puntuacionesNombres(puntajesNombre, V, dado, puntajes);

    if(result == -1) {
        return -1;
    }
    //este while sirve como verificacion para que no se pueda sobreescribir
    //un valor ya escogido.
    while(flag == false) {
    cout<<"Elige el puntaje que deseas para esta ronda"<<endl; cin>>eleccion;
    nIndice = eleccion - 1;
        if(puntajes[nIndice] != -1) {
            cout<<"No se puede sobreescribir un puntaje ya guardado, por favor, ingrese otro puntaje"<<endl;
        } else {
            return puntajes[nIndice] = V[nIndice];
            flag = true;
        }
    }
}

int sumarPuntajes(int puntajes[]) {
    int acumuladorPuntajes = 0, i, j;
    int copiaPuntajes[10];

    for(j=0;j<10;j++) {
        if(puntajes[j] == -1) {
            copiaPuntajes[j] = puntajes[j] + 1;
        } else {
            copiaPuntajes[j] = puntajes[j];
        }
    }

    for(i=0;i<10;i++) {
        acumuladorPuntajes += copiaPuntajes[i];
    }

    return acumuladorPuntajes;
}


#endif // PUNTAJES_H_INCLUDED
