/*
Ana Fernanda Chacón Lomelí
A00830052
29 de mayo 2021

Clase Series donde se hace una composición con la clase Serie. En esta clase se lee toda la información de las series 
y cada uno de sus episodios a través de la función leerArchivo. Los episodios son almacenados como atributos en el arreglo 
de episodios de cada serie, mientras que las series son almacenadas en el arreglo de apuntadores tipo Serie. Asímismo, en esta 
clase se encuentran funciones para generar diferentes reportes donde se desplieguen todos los atributos de las series y sus episodios. 
Estos son: un reporte de todas las series y sus respectivos episodios disponibles, un reporte de todas las series con la calificación 
especificada por el usuario y un reporte de todas las series que pertenezcan a cierto género igualmente solicitado por el usuario. 
Finalmente, hay una función para mandar a calcular la calificación de todas las series de acuerdo a las de sus episodios.
*/

#ifndef Series_hpp
#define Series_hpp

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>

using namespace std;

#include "Serie.hpp"

const int MAX_SERIES = 50;

class Series
{
    public:
        //constructor default
        Series();

        //para leer el archivo csv con la información de las series y almacenarlas en arrPtrSeries
        void leerArchivo();

        //setters
        void setPtrSerie(Serie *_serie);
        void setCantidadSeries(int _cantidad);

        //getters
        Serie* getPtrSerie(string _iD);
        int getCantidadSeries();

        //para desplegar la información de todas las series que están en el arreglo arrPtrSeries y calcula el promedio 
        //de las calificaciones
        void reporteTodasLasSeries();

        //para desplegar las series con una calificación específica que se recibe como parámetro de entrada
        void reporteConCalificacion(double _calificacion);

        //para desplegar las series de cierto genero específico que se recibe como parámetro de entrada
        void reporteGenero(string _genero);

        // calcula la calificación de cada serie en base a sus episodios mandando a llamar la función calculaCalPromedio
        void calcularCalificacionSeries();


    private:
        Serie *arrPtrSeries[MAX_SERIES];
        int cantidad;
};


//IMPLEMENTACIÓN
//constructor default
Series::Series()
{
    for(int iS = 0; iS < MAX_SERIES; iS++)
        arrPtrSeries[iS] = nullptr;
    cantidad = 0;
}

//para leer el archivo csv con la información de las series y almacenarlas en arrPtrSeries
void Series::leerArchivo()
{
    //Declaración de variables que serán usadas al leer cada línea del archivo
    string linea, dato, row[6];

    //Variable para llevar el contador de cantidad de series leídas del archivo
    int iRow{}, iS{}, cantEpisodios{};

    //Declaración de variable para el archivo
    fstream lectura;

    Episodio *episodio;

    //LECTURA DE LAS SERIES
    lectura.open("Serie2021.csv");
    //inicializamos atributo de cantidad en 0
    cantidad = 0;
    //ciclo para leer todo el archivo
    while(getline(lectura, linea))
    {
        stringstream registro(linea);
        iRow = 0;

        //ciclo para separar los elementos de la serie
        while(getline(registro, dato, ','))
            row[iRow++] = dato;

        //crear un objeto de la clase Serie, new retorna un pointer
        arrPtrSeries[cantidad] = new Serie(row[0], row[1], stoi(row[2]), row[3], stod(row[4]), 0);

        cantidad++;
    }
    lectura.close();

    //LECTURA DE LOS EPISODIOS
    lectura.open("Episodio2021.csv");
    //ciclo para leer todo el archivo
    while(getline(lectura,linea))
    {
        stringstream registro(linea);
        iRow = 0;

        //ciclo para separar los datos del episodio desde la línea
        while(getline(registro, dato, ','))
            row[iRow++] = dato;
        
        //sacamos la posicion del arreglo donde esta el ptr de la serie a la que pertenece el episodio: 
        //ID 500 -> posicion 0, 501 -> 1, etc.
        iS = stoi(row[0]) - 500; 

        //creamos el episodio
        episodio = new Episodio(row[1], stoi(row[2]), stod(row[3]));

        //trae la cantidad de episodios de la serie iS (la primera vez retorna 0)
        cantEpisodios = arrPtrSeries[iS]->getCantidad();

        //verificamos si todavía se pueden añadir más episodios al arreglo
        if(cantEpisodios < 5)
        {
            arrPtrSeries[iS]->setEpisodio(cantEpisodios, *(episodio));
            arrPtrSeries[iS]->setCantidad(++cantEpisodios);
        }
    }
    lectura.close();
}


//setters
void Series::setPtrSerie(Serie *_serie)
{
    arrPtrSeries[cantidad] = _serie;
    cantidad++;
}

void Series::setCantidadSeries(int _cantidad)
{
    cantidad = _cantidad;
}


//getters
Serie* Series::getPtrSerie(string _iD)
{
    for(int iS = 0; iS < cantidad; iS++)
    {
        if(arrPtrSeries[iS]->getId() == _iD)
            return arrPtrSeries[iS];
    }
    return nullptr;
}

int Series::getCantidadSeries()
{
    return cantidad;
}


//para desplegar la información de todas las series que están en el arreglo arrPtrSeries y calcula el promedio
//de las calificaciones
void Series::reporteTodasLasSeries()
{
    double suma{0};
    for(int iS = 0; iS < cantidad; iS++)
    {
        cout << *arrPtrSeries[iS] << endl;
        suma = suma + arrPtrSeries[iS]->getCalificacion();
    }
    if(cantidad > 0)
        cout << "Promedio Series:" << suma / cantidad << endl;
}
    
//para desplegar las series con una calificación específica que se recibe como parámetro de entrada
void Series::reporteConCalificacion(double _calificacion)
{
    for(int iS = 0; iS < cantidad; iS++)
    {
        if(arrPtrSeries[iS]->getCalificacion() == _calificacion)
            cout << *arrPtrSeries[iS] << endl;
    }
}
    
//para desplegar las series de cierto genero específico que se recibe como parámetro de entrada
void Series::reporteGenero(string _genero)
{
    for(int iS = 0; iS < cantidad; iS++)
    {
        if(arrPtrSeries[iS]->getGenero() == _genero)
            cout << *arrPtrSeries[iS] << endl;
    }
}
    
//calcula la calificación de cada serie en base a sus episodios mandando a llamar la función calculaCalPromedio
void Series::calcularCalificacionSeries()
{
    for(int iS = 0; iS < cantidad; iS++)
        arrPtrSeries[iS]->calculaCalPromedio();
}

#endif /*Series_hpp*/