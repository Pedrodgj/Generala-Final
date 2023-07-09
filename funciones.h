#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "puntosMenu.h"
#include "funciones.h"
#include "graficos.h"


//#include "puntajes.h"

//Mostrar Nombre Jugador
int elegirDadosLanzar();

void centrarTexto(const string& texto, int altura = 1) {
    int anchuraConsola = rlutil::tcols();
    int anchuraTexto = texto.length();
    int margenIzquierdo = (anchuraConsola - anchuraTexto) / 2;
    rlutil::locate(margenIzquierdo, altura);
    cout << texto <<endl;
}

void cargarNombreJugador (string nombreJugador[3], int tam, int height = 2)
{
    int consoleWidth = rlutil::tcols();
    int marginLeft = (consoleWidth) / 2;
    rlutil::locate(marginLeft, height);
    getline(cin, nombreJugador[tam]);
}

void mostrarSoloJugador(string nombre[3], int pos, bool flag = false, int altura = 2)
{
    if(!flag) {
        cout<<nombre[pos-1];
    } else {
        string nombreCentral = nombre[pos-1];
        centrarTexto(nombreCentral, altura);
    }
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
}

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
}

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
        }
        return true;
    }
    return false;
}

void iniciarRegistroEn0 (string guardarPuntajes[][3])
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
        }
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
        }
    }
}


//modificar dados
void modificarDados(int opciones, int dado[], bool isTest = false)
{
    int i, eleccion, modificarIndex, manual;
    system("cls");

    //Si deseas modificar los 5 dados se crea un nuevo vector
    if(opciones == 5)
    {
        cargarAleatorio(dado, 5, 6);
        mostrarVector(dado, 5);
    }
    else
    {
        cout<<"Cuales dados deseas cambiar?"<<endl;
        mostrarVector(dado, 5);
        for(i = 0; i < opciones; i++)
        {
            eleccion = elegirDadosLanzar();
            modificarIndex = eleccion - 1;
            if(isTest) {
            centrarTexto("Ingrese valor del dado", 2);
            cin>>manual;
            dado[modificarIndex] = manual;
            } else {
                dado[modificarIndex] = (rand()%6)+1;
            }
            cout<<"\n\n\n\n\n\nSelecciono el dado "<<eleccion<<endl;
        }
        mostrarVector(dado, 5);
    }
}

void showItem(const char* text, int posx, int posy, bool selected)

{
    if(selected)
    {
        rlutil::setBackgroundColor(rlutil::color::RED);
        rlutil::locate(posx - 3, posy);
        std::cout<< " " << (char)175 << " " << text << " " << (char)174 << " " <<std:: endl;
        rlutil::setBackgroundColor(rlutil::color::BLACK);
    }
    else
    {
        rlutil::setBackgroundColor(rlutil::color::BLACK);
        rlutil::locate(posx-3, posy);
        std::cout<< "   " << text << "   " << std::endl;
    }
    rlutil::setBackgroundColor(rlutil::color::BLACK);
}

int eleccionOpc()
{
    const char *text1 = "Decida: ";
    const char *text2 = "-Obtener Puntajes-";
    const char *text3 = "-Lanzar Dados de nuevo-";
    int y =0;
    bool valu = true;
    int key;
    while(valu)
    {

        rlutil::hidecursor();

        if(text3 == "")
        {
            showItem(text1, 40, 16, y==0);
            key = rlutil::getkey();
            switch(key)
            {
            case 14:
                rlutil::locate(48, 10 + y);
                std::cout<< " " <<std::endl;
                y--;
                if(y<0)
                {
                    y=1;
                }
                break;
            case 15:
                rlutil::locate(48, 10 + y);
                std::cout<< " " <<std::endl;
                y++;
                if(y>1)
                {
                    y=2;
                }
                break;
            case 1:
                switch(y)
                {
                case 1:
                    valu = false;
                    system("cls");
                    return 1;
                    break;
                case 2:
                    valu = false;
                    system("cls");
                    return 2;
                    break;
                default:
                    break;
                }
            }
        }


        showItem(text1, 60, 14, y==0);
        showItem(text2, 60, 16, y==1);
        showItem(text3, 60, 18, y==2);
        key = rlutil::getkey();
        switch(key)
        {
        case 14:
            rlutil::locate(48, 10 + y);
            std::cout<< " " <<std::endl;
            y--;
            if(y<0)
            {
                y=1;
            }
            break;
        case 15:
            rlutil::locate(48, 10 + y);
            std::cout<< " " <<std::endl;
            y++;
            if(y>1)
            {
                y=2;
            }
            break;
        case 1:
            switch(y)
            {
            case 1:
                valu = false;
                system("cls");
                return 1;
                break;
            case 2:
                valu = false;
                system("cls");
                return 2;
                break;
            default:
                break;
            }
        }
    }
}

int elegir()
{
    int y=0;
    while(true)
    {
        rlutil::hidecursor();
        showItem("<---", 35, 11, y==0);
        showItem("<---", 35, 13, y==1);
        showItem("<---", 35, 15, y==2);
        showItem("<---", 35, 17, y==3);
        showItem("<---", 35, 19, y==4);
        showItem("<---", 35, 21, y==5);
        showItem("<---", 35, 23, y==6);
        showItem("<---", 35, 25, y==7);
        showItem("<---", 35, 27, y==8);
        showItem("<---", 35, 29, y==9);

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
            if(y>9)
            {
                y=10;
            }
            break;
        case 1:
            switch(y)
            {
            case 0:
                return 1;
                break;
            case 1:
                return 2;
                break;
            case 2:
                return 3;
                break;
            case 3:
                return 4;
                break;
            case 4:
                return 5;
                break;
            case 5:
                return 6;
                break;
            case 6:
                return 7;
                break;
            case 7:
                return 8;
                break;
            case 8:
                return 9;
                break;
            case 9:
                return 10;
                break;
            default:
                break;
            }

        default:
            break;
        }
    }
}

int lanzarDadosDeNuevo()
{
    int y=0;
    while(true)
    {
        rlutil::hidecursor();

        showItem("1", 15, 12, y==0);
        showItem("2", 15, 14, y==1);
        showItem("3", 15, 16, y==2);
        showItem("4", 15, 18, y==3);
        showItem("5", 15, 20, y==4);

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
            if(y>4)
            {
                y=5;
            }
            break;
        case 1:
            switch(y)
            {
            case 0:
                return 1;
                break;
            case 1:
                return 2;
                break;
            case 2:
                return 3;
                break;
            case 3:
                return 4;
                break;
            case 4:
                return 5;
                break;
            default:
                break;
            }

        default:
            break;
        }
    }
}

int elegirDadosLanzar()
{
    int y=0;
    while(true)
    {
        rlutil::hidecursor();

        showItem("1*", 8, 4, y==0);
        showItem("2*", 23, 4, y==1);
        showItem("3*", 38, 4, y==2);
        showItem("4*", 53, 4, y==3);
        showItem("5*", 68, 4, y==4);

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
            if(y>4)
            {
                y=4;
            }
            break;
        case 1:
            switch(y)
            {
            case 0:
                return 1;
                break;
            case 1:
                return 2;
                break;
            case 2:
                return 3;
                break;
            case 3:
                return 4;
                break;
            case 4:
                return 5;
                break;
            default:
                break;
            }

        default:
            break;
        }
    }
}





#endif // FUNCIONES_H_INCLUDED
