/*
Ana Fernanda Chacón Lomelí
A00830052
17 de mayo 2021

Clase Pelicula derivada de la clase Video, donde el atributo adicional a los heredados de la clase base es la 
cantidad de oscares que ganó la película. En la clase se utilizan métodos constructores (default y con parámetros)
donde también se manda a llamar a los constructores de la clase base. También, se utiliza un método de acceso y
uno de modificación para el atributo oscares. Igualmente, se implementa la sobrecarga del operador de salida "<<"
a través de una función amiga y se incluye un método str() para retornar un string con todos los atributos de la película.
*/

#ifndef Pelicula_hpp
#define Pelicula_hpp

#include <iostream>
#include <stdio.h>

#include "Video.hpp"

class Pelicula : public Video
{
    public:
        //constructores
        Pelicula();
        Pelicula(std::string _iD, std::string _titulo, int _duracion, std::string _genero, double _calificacionPromedio, int _oscares);

        //set y get del atributo oscares
        void setOscares(int _oscares);
        int getOscares();

        //para retornar un string con todos los atributos del objeto
        std::string str();

        //sobrecarga operador <<
        friend std::ostream& operator<<(std::ostream &out, const Pelicula &pelicula);

    private:
        int oscares;
};


// IMPLEMENTACIÓN
//constructores
Pelicula::Pelicula() : Video()
{
    oscares = 0;
}

Pelicula::Pelicula(std::string _iD, std::string _titulo, int _duracion, std::string _genero, double _calificacionPromedio, int _oscares)
: Video(_iD, _titulo, _duracion, _genero, _calificacionPromedio)
{
    oscares = _oscares;
}


//set y get del atributo oscares
void Pelicula::setOscares(int _oscares)
{
    oscares = _oscares;
}

int Pelicula::getOscares()
{
    return oscares;
}


//para retornar un string con todos los atributos del objeto
std::string Pelicula::str()
{
    return 'P' + Video::str() + ',' + std::to_string(oscares);
}

//sobrecarga operador <<
std::ostream& operator<<(std::ostream &out, const Pelicula &pelicula)
{
    out << 'P' + pelicula.iD + ',' + pelicula.titulo + ',' + std::to_string(pelicula.duracion) + ',' + pelicula.genero + 
    ',' + std::to_string(pelicula.calificacionPromedio) + ',' + std::to_string(pelicula.oscares);
    
    return out;
}

#endif /* Pelicula_hpp */