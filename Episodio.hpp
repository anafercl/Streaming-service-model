/*
Ana Fernanda Chacón Lomelí
A00830052
17 de mayo 2021

Clase Episodio con el propósito de que cada episodio se pueda considerar como un objeto y tenga sus propios 
atributos, los cuales son: título, temporada y duración. En la clase se utilizan métodos constructores (default 
y con parámetros), de acceso y de modificación. Además, hay una función str para retornar un string con todos 
los atributos del episodio. Finalmente, se incluye la sobrecarga del operador de salida "<<".
*/

#ifndef Episodio_hpp
#define Episodio_hpp

#include <iostream>
#include <stdio.h>

class Episodio
{
    public:
        //constructores
        Episodio();
        Episodio(std::string _titulo, int _temporada, double _calificacion);

        //setters
        void setTitulo(std::string _titulo);
        void setTemporada(int _temporada);
        void setCalificacion(double _calificacion);

        //getters
        std::string getTitulo();
        int getTemporada();
        double getCalificacion();

        //para retornar un string con todos los atributos del objeto
        std::string str();

        //sobrecarga operador <<
        friend std::ostream& operator<<(std::ostream &out, const Episodio &episodio);


    private:
        std::string titulo;
        int temporada;
        double calificacion;
};


// IMPLEMENTACIÓN
//constructores
Episodio::Episodio()
{
    titulo = " ";
    temporada = 0;
    calificacion = 0;
}

Episodio::Episodio(std::string _titulo, int _temporada, double _calificacion)
{
    titulo = _titulo;
    temporada = _temporada;
    calificacion = _calificacion;
}


//setters
void Episodio::setTitulo(std::string _titulo)
{
    titulo = _titulo;
}

void Episodio::setTemporada(int _temporada)
{
    temporada = _temporada;
}

void Episodio::setCalificacion(double _calificacion)
{
    calificacion = _calificacion;
}


//getters
std::string Episodio::getTitulo()
{
    return titulo;
}

int Episodio::getTemporada()
{
    return temporada;
}

double Episodio::getCalificacion()
{
    return calificacion;
}


//para retornar un string con todos los atributos del objeto
std::string Episodio::str()
{
    return 'E' + titulo + ',' + std::to_string(temporada) + ',' + std::to_string(calificacion);
}

//sobrecarga operador <<
std::ostream& operator<<(std::ostream &out, const Episodio &episodio)
{
    out << 'E' + episodio.titulo + ',' + std::to_string(episodio.temporada) + ',' + std::to_string(episodio.calificacion);
    return out;
}

#endif /* Episodio_hpp */