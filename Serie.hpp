/*
Ana Fernanda Chacón Lomelí
A00830052
17 de mayo 2021

Clase Serie derivada de la clase Video donde un atributo adicional a los heredados de la clase base es la cantidad de 
episodios que tiene la serie. Además, se hace una composición con la clase Episodio al incluir un arreglo de tipo Episodio 
donde se almacenan todos los episodios de la serie como otro atributo. Se utilizan métodos constructores (default y con parámetros)
donde se manda a llamar a los constructores de la clase base. Asímismo, se incluye un destructor, métodos modificadores y de acceso.
Hay un método para calcular la calificación promedio de la serie en base a sus episodios. Finalmente, se implementa la sobrecarga 
del operador de salida "<<" a través de una función amiga y se incluye un método str() para retornar un string con todos los 
atributos de la serie (incluyendo una lista de sus episodios).
*/

#ifndef Serie_hpp
#define Serie_hpp

#include <iostream>
#include <stdio.h>

#include "Video.hpp"
#include "Episodio.hpp"

class Serie : public Video
{
    public:
        //constructores
        Serie();
        Serie(std::string _iD, std::string _titulo, int _duracion, std::string _genero, double _calificacionPromedio, int _cantidad);

        //destructor
        ~Serie();

        //setters
        void setEpisodio(int iE, Episodio _episodio);
        void setCantidad(int _cantidad);

        //getters
        Episodio getEpisodio(int iE);
        int getCantidad();

        //para calcular la calificación promedio de la serie en base a las calificaciones de sus episodios
        double calculaCalPromedio();

        //para retornar un string con todos los atributos del objeto (incluyendo sus episodios)
        std::string str();

        //sobrecarga operador <<
        friend std::ostream& operator<<(std::ostream &out, const Serie &serie);


    private:
        Episodio episodios[5];
        int cantidad;
};


// IMPLEMENTACIÓN
//constructores
Serie::Serie() : Video()
{
    cantidad = 0;
}

Serie::Serie(std::string _iD, std::string _titulo, int _duracion, std::string _genero, double _calificacionPromedio, int _cantidad) 
: Video(_iD, _titulo, _duracion, _genero, _calificacionPromedio)
{
    cantidad = _cantidad;
}


//destructor
Serie::~Serie()
{

}


//setters
void Serie::setEpisodio(int iE, Episodio _episodio)
{
    if(iE >= 0 && iE < 5)
        episodios[iE] = _episodio;
}

void Serie::setCantidad(int _cantidad)
{
    if(_cantidad >= 0 && _cantidad <= 5)
        cantidad = _cantidad;
}


//getters
Episodio Serie::getEpisodio(int iE)
{
    Episodio EpisodioDefault{};
    if(iE >= 0 && iE < 5)
        return episodios[iE];
    else
        return EpisodioDefault;
}

int Serie::getCantidad()
{
    return cantidad;
}


//para calcular la calificación promedio de la serie en base a las calificaciones de sus episodios
double Serie::calculaCalPromedio()
{
    double suma{0};
    if(cantidad > 0)
    {
        for(int iE = 0; iE < cantidad; iE++)
            suma = suma + episodios[iE].getCalificacion();
        calificacionPromedio = suma / cantidad;
    }
    else
        calificacionPromedio = -1;
    return calificacionPromedio;
}

//para retornar un string con todos los atributos del objeto (incluyendo sus episodios)
std::string Serie::str()
{
    std::string print;
    print = 'S' + Video::str() + ',' + std::to_string(cantidad) + '\n';
    for(int iE = 0; iE < cantidad; iE++)
        print = print + std::to_string(iE) + ':' + episodios[iE].str() + '\n';
    return print;
}

//sobrecarga operador <<
std::ostream& operator<<(std::ostream &out, const Serie &serie)
{
    out << 'S' + serie.iD + ',' + serie.titulo + ',' + std::to_string(serie.duracion) + ',' + serie.genero + ',' + 
    std::to_string(serie.calificacionPromedio) + ',' + std::to_string(serie.cantidad) + '\n';

    for(int iE = 0; iE < serie.cantidad; iE++)
        out << std::to_string(iE) + ':' << serie.episodios[iE] << '\n';
    return out;
}

#endif /* Serie_hpp */