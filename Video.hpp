/*
Ana Fernanda Chacón Lomelí
A00830052
17 de mayo 2021

Clase Video para la oferta de un servicio de streaming de videos bajo demanda, donde habrá una variedad de series y 
peliculas. Cada video cuenta con los atributos ID,  título, duración, género, y calificación promedio. En la clase se 
utilizan métodos constructores (default y con parámetros), modificadores y de acceso. Además, se utiliza una función 
amiga para hacer una sobrecarga del operador de salida "<<" y una función virtual para el método str(), ya que se 
realiza un overriding de esta en las clases derivadas.
*/

#ifndef Video_hpp
#define Video_hpp

#include <iostream>
#include <stdio.h>

class Video
{
    public:
        //constructores
        Video();
        Video(std::string _iD, std::string _titulo, int _duracion, std::string _genero, double _calificacionPromedio);

        //setters
        void setId(std::string _iD);
        void setTitulo(std::string _titulo);
        void setDuracion(int _duracion);
        void setGenero(std::string _genero);
        void setCalificacion(double _calificacionPromedio);

        //getters
        std::string getId();
        std::string getTitulo();
        int getDuracion();
        std::string getGenero();
        double getCalificacion();

        //para retornar un string con todos los atributos del objeto (función virtual)
        virtual std::string str();

        //sobrecarga operador <<
        friend std::ostream& operator<<(std::ostream &out, const Video &video);


    protected:
        std::string iD, titulo, genero;
        int duracion;
        double calificacionPromedio;

};


// IMPLEMENTACIÓN
//constructores
Video::Video()
{
    iD = "000";
    titulo = "___";
    duracion = 0;
    genero = "XXX";
    calificacionPromedio = 0;
}

Video::Video(std::string _iD, std::string _titulo, int _duracion, std::string _genero, double _calificacionPromedio)
{
    iD = _iD;
    titulo = _titulo;
    duracion = _duracion;
    genero = _genero;
    calificacionPromedio = _calificacionPromedio;
}


//setters
void Video::setId(std::string _iD)
{
    iD = _iD;
}

void Video::setTitulo(std::string _titulo)
{
    titulo = _titulo;
}

void Video::setDuracion(int _duracion)
{
    duracion = _duracion;
}

void Video::setGenero(std::string _genero)
{
    genero = _genero;
}

void Video::setCalificacion(double _calificacionPromedio)
{
    calificacionPromedio = _calificacionPromedio;
}


//getters
std::string Video::getId()
{
    return iD;
}

std::string Video::getTitulo()
{
    return titulo;
}

int Video::getDuracion()
{
    return duracion;
}

std::string Video::getGenero()
{
    return genero;
}

double Video::getCalificacion()
{
    return calificacionPromedio;
}


//para retornar un string con todos los atributos del objeto (función virtual)
std::string Video::str()
{
    return iD + ',' + titulo + ',' + std::to_string(duracion) + ',' + genero + ',' + std::to_string(calificacionPromedio);
}

//sobrecarga operador <<
std::ostream& operator<<(std::ostream &out, const Video &video)
{
    out << video.iD + ',' + video.titulo + ',' + std::to_string(video.duracion) + ',' + video.genero + ',' + 
    std::to_string(video.calificacionPromedio);
    
    return out;
}

#endif /* Video_hpp */


/* REFLEXIÓN SOBRE FUNCIONES VIRTUALES

El polimorfismo ayuda a que los objetos en la dirección de los apuntadores tomen muchas formas. Es decir, se puede declarar 
un apuntador del tipo de la clase base y en él se puede almacenar una dirección a un objeto tanto de esa clase como de 
cualquiera de sus derivadas. Sin embargo, al utilizar esa variable, el objeto se comportaría como si perteneciera a la clase 
base, independientemente de cuál sea su tipo original. Esto se puede ver al realizar un overriding de funciones, donde si se 
quiere llamar a una función del objeto, la computadora llamará a la función en la clase base sin importar a qué clase pertenezca 
este objeto. 

El uso de funciones virtuales ayuda a que se pueda implementar el polimorfismo en un grado mucho mayor. Esto es porque,
en el overriding, al volver la función en la clase base una función virtual se logra que se pueda llamar a las funciones
correspondientes al objeto a pesar de que se utilizen apuntadores del tipo de la clase base. De esta manera, se podría hacer
un solo arreglo de apuntadores del tipo de la clase base, en lugar de arreglos separados por cada una. En otras palabras, la
implementación de funciones virtuales ayuda a que se pueda aplicar el polimorfismo con apuntadores y que sigan funcionando
como sus objetos correspondientes, con el beneficio de que se está ocupando menos memoria. 

*/
