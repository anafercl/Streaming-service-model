/*Ana Fernanda Chacón Lomelí
A00830052
22 de mayo 2021

Clase Peliculas, donde se hace una composición con la clase Pelicula. En esta clase se leen los datos 
de las películas para almacenarlas en un arreglo de apuntadores de tipo Pelicula a través de la función
leerArchivo. Además, hay funciones en esta clase con el propósito de generar diferentes reportes donde
se desplieguen todos los atributos de las películas. Entre ellos están: un reporte de todas las películas
disponibles, un reporte de las películas con la calificación pedida por el usuario y finalmente un reporte 
de todas las películas del género igualmente solicitado por el usuario. 
*/

#ifndef Peliculas_hpp
#define Peliculas_hpp

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>

using namespace std;

#include "Pelicula.hpp"

const int MAX_PEL = 50;

class Peliculas
{
    public:
        //constructor default
        Peliculas();

        //para leer el archivo csv con la información de las películas y almacenarlas en arrPtrPeliculas
        void leerArchivo();
    
        //setters
        void setPtrPelicula(Pelicula *_ptr);
        void setCantidadPeliculas(int _cantidad);

        //getters
        Pelicula* getPtrPelicula(string _iD);
        int getCantidadPeliculas();
    
        //para desplegar información de todas las películas en el arreglo y calcula el promedio de las calificaciones
        void reporteTodasLasPeliculas();

        //para desplegar las películas con una calificación específica que se recibe como parámetro de entrada
        void reporteConCalificacion(double _calificacion);

        //para desplegar las películas de cierto genero específico que se recibe como parámetro de entrada
        void reporteGenero(string _genero);


    private:
        Pelicula *arrPtrPeliculas[MAX_PEL];
        int cantidad;
};


// IMPLEMENTACIÓN
//constructor default
Peliculas::Peliculas()
{
    for(int iP = 0; iP < MAX_PEL; iP++)
        arrPtrPeliculas[iP] = nullptr;
    cantidad = 0;
}

//para leer el archivo csv con la información de las películas y almacenarlas en arrPtrPeliculas
void Peliculas::leerArchivo()
{
    fstream fin; //fin - file input
    string row[6]; //para almacenar los datos leídos 
    string line, word;

    //abrimos archivo de entrada
    fin.open("Pelicula.csv");

    //inicializamos atributo cantidad con 0
    cantidad = 0;

    while(getline(fin, line))
    {
        stringstream s(line); //para separar las palabras split()

        int iR = 0; //inicializamos índice del renglón en 0

        //extrae caracteres de s y los almacena en word hasta que encuentra el delimitador ','
        while(getline(s, word, ','))
            row[iR++] = word;
        
        //operador new crea un objeto del tipo Pelicula y retorna un pointer (dirección de la memoria HEAP) al objeto Pelicula 
        //stoi - función que convierte un string a int
        //stod - función que convierte un string a double
        //[0] iD, [1]titulo, [2]duracion, [3]genero, [4]calificacion, [5]oscares
        arrPtrPeliculas[cantidad] = new Pelicula(row[0], row[1], stoi(row[2]), row[3], stod(row[4]), stoi(row[5]));

        cantidad++;
    }
    //sale del ciclo cuando ya no existen más líneas en el archivo
    fin.close();
}


//setters
void Peliculas::setPtrPelicula(Pelicula *_ptr)
{
    arrPtrPeliculas[cantidad] = _ptr;
    cantidad++;
}

void Peliculas::setCantidadPeliculas(int _cantidad)
{
    cantidad = _cantidad;
}


//getters
Pelicula* Peliculas::getPtrPelicula(string _iD)
{
    for(int iP = 0; iP < cantidad; iP++)
    {
        if(arrPtrPeliculas[iP]->getId() == _iD)
            return arrPtrPeliculas[iP];
    }
    return nullptr;
}

int Peliculas::getCantidadPeliculas()
{
    return cantidad;
}


//para desplegar información de todas las películas en el arreglo y calcula el promedio de calificación
void Peliculas::reporteTodasLasPeliculas()
{
    double suma{0};
    for(int iP = 0; iP < cantidad; iP++)
    {
        cout << *arrPtrPeliculas[iP] << endl;
        suma = suma + arrPtrPeliculas[iP]->getCalificacion();
    }
    if(cantidad > 0)
        cout << "Promedio:" << suma/cantidad << endl;
        
}

//para desplegar las películas con una calificación específica que se recibe como parámetro de entrada
void Peliculas::reporteConCalificacion(double _calificacion)
{
    for(int iP = 0; iP < cantidad; iP++)
    {
        if(arrPtrPeliculas[iP]->getCalificacion() == _calificacion)
            cout << *arrPtrPeliculas[iP] << endl;
    }
}

//para desplegar las películas de cierto genero específico que se recibe como parámetro de entrada
void Peliculas::reporteGenero(string _genero)
{
    for(int iP = 0; iP < cantidad; iP++)
    {
        if(arrPtrPeliculas[iP]->getGenero() == _genero)
            cout << *arrPtrPeliculas[iP] << endl;
    }
}

#endif /* Peliculas_hpp */