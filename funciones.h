#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "puntosMenu.h"
#include "funciones.h"
#include "graficos.h"


//#include "puntajes.h"

//Mostrar Nombre Jugador
void cargarNombreJugador (string nombre[3], int tam)
{
    int i;
    cin>>nombre[tam];

};

void mostrarSoloJugador(string nombre[3], int pos)
{
    cout<<nombre[pos-1];
}

//Cargar un Vector aleatorio
void cargarAleatorio(int v[], int tam, int limite)
{
    int i;
    srand(time(NULL));
    for( i=0; i<tam; i++ )
    {
        v[i]=(rand()%limite)+1;
    }
};

void cargarManualmenteVector (int v[])
{
    int i;
    int valor;

    cout<<"Ingrese los valores del dado"<<endl;
    for(i = 0; i < 5; i++)
    {
        cin>>valor;
        v[i] = valor;
    }
}

//Mostrar Vector
void mostrarVector(int v[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {

        {



            switch(v[0])
            {

            case 1 :
                dadoUno(5,5);
                break;
            case 2 :
                dadoDos(5,5);
                break;
            case 3 :
                dadoTres(5,5);
                break;
            case 4 :
                dadoCuatro(5,5);
                break;
            case 5 :
                dadoCinco(5,5);
                break;
            case 6 :
                dadoSeis(5,5);
                break;

            }

            switch(v[1])
            {

            case 1 :
                dadoUno(20,5);
                break;
            case 2 :
                dadoDos(20,5);
                break;
            case 3 :
                dadoTres(20,5);
                break;
            case 4 :
                dadoCuatro(20,5);
                break;
            case 5 :
                dadoCinco(20,5);
                break;
            case 6 :
                dadoSeis(20,5);
                break;

            }

            switch(v[2])
            {

            case 1 :
                dadoUno(35,5);
                break;
            case 2 :
                dadoDos(35,5);
                break;
            case 3 :
                dadoTres(35,5);
                break;
            case 4 :
                dadoCuatro(35,5);
                break;
            case 5 :
                dadoCinco(35,5);
                break;
            case 6 :
                dadoSeis(35,5);
                break;

            }

            switch(v[3])
            {

            case 1 :
                dadoUno(50,5);
                break;
            case 2 :
                dadoDos(50,5);
                break;
            case 3 :
                dadoTres(50,5);
                break;
            case 4 :
                dadoCuatro(50,5);
                break;
            case 5 :
                dadoCinco(50,5);
                break;
            case 6 :
                dadoSeis(50,5);
                break;

            }

            switch(v[4])
            {

            case 1 :
                dadoUno(65,5);
                break;
            case 2 :
                dadoDos(65,5);
                break;
            case 3 :
                dadoTres(65,5);
                break;
            case 4 :
                dadoCuatro(65,5);
                break;
            case 5 :
                dadoCinco(65,5);
                break;
            case 6 :
                dadoSeis(65,5);
                break;

            }

            switch(v[5])
            {

            case 1 :
                dadoUno(80,5);
                break;
            case 2 :
                dadoDos(80,5);
                break;
            case 3 :
                dadoTres(80,5);
                break;
            case 4 :
                dadoCuatro(80,5);
                break;
            case 5 :
                dadoCinco(80,5);
                break;
            case 6 :
                dadoSeis(80,5);
                break;

            }
        }
    }
    cout<<endl;
    cout<<endl;
};

//ordenar Vector
void ordenarVector(int v[], int tam)
{
    int i,j, posmin, aux;

    for(i=0; i<tam-1; i++)
    {
        posmin=i;
        for(j=i+1; j<tam; j++)
        {
            if(v[j]<v[posmin]) posmin=j;
        }
        aux=v[i];
        v[i]=v[posmin];
        v[posmin]=aux;
    }
}




bool puntajesEnCero(int Puntaje[], bool flag)
{
    int i;

    if(flag == false)
    {
        for(i = 0; i < 10; i++)
        {
            Puntaje[i] = -1;
        };
        return true;
    };
    return false;
}

void iniciarRegistroEn0 (string guardarPuntajes[1][3])
{
    int k, l;
    for(k=0; k<1; k++)
    {
        for(l=0; l<3; l++)
        {
            guardarPuntajes[k][l] = "0";
        }
    }
}


int ganadorGenerala(int v[], int tam, int jugador)
{
    int i;
    int acumulador = 0;
    int esGenerala = v[0];

    for(i=0; i<tam; i++)
    {
        if(esGenerala == v[i])
        {
            acumulador++;
        };
    }



    if(acumulador == 5)
    {
        system("cls");
        cout<<"Has ganado la partida"<<endl;
        mostrarVector(v, 5);
        cout<<"GENERALA SERVIDA 500ptos"<<endl;
        return 500;
        system("pause");
    }
    else
    {
        return 0;
    }

}

//funcion para mostrar el puntaje de cada participante
void mostrarPuntajes(int puntajes[])
{
    string puntajesNombre[10];

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

    int j;
    for(j = 0; j < 10; j++)
    {
        if(puntajes[j] == -1)
        {
            puntajes[j] = 0;
            cout<<"\n"<<j + 1<<" "<<puntajes[j]<<endl;
            puntajes[j] = -1;
        }
        else
        {
            cout<<"\n"<<j + 1<<" "<<puntajesNombre[j]<<" Puntaje: "<<puntajes[j]<<endl;
        };
    };
}


//modificar dados
void modificarDados(int opciones, int dado[])
{
    int i, eleccion, modificarIndex;

    //Si deseas modificar los 5 dados se crea un nuevo vector
    if(opciones == 5)
    {
        cargarAleatorio(dado, 5, 6);
        mostrarVector(dado, 5);
    }
    else
    {
        cout<<"Cuales dados deseas cambiar?"<<endl;
        for(i = 0; i < opciones; i++)
        {
            cin>>eleccion;
            modificarIndex = eleccion - 1;
            dado[modificarIndex] = (rand()%6)+1;
        };
        mostrarVector(dado, 5);

    }
};

void showItem(const char* text, int posx, int posy, bool selected)

{
    if(selected)

    {
        rlutil::setBackgroundColor(rlutil::color::RED);
        rlutil::locate(posx - 3, posy);
        std::cout<< " " << (char)175 << " " << text << " " << (char)174 << " " <<std:: endl;
    }
    else
    {
        rlutil::setBackgroundColor(rlutil::color::BLACK);
        rlutil::locate(posx-3, posy);
        std::cout<< "   " << text << "   " << std::endl;
    }

};




#endif // FUNCIONES_H_INCLUDED
