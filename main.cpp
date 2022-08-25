//
//  main.cpp
//  Avance 3 Objetivos - Lectura de archivos csv: 2 archivos para cargar la info de las Series
//           aplicando Herencia con Video y  Composición con Episodio,
//           almacenando todo en un arreglo de apuntadores.
//           Poliformismo -  overriding, asignación dinámica de memoría con el operador new al 
//           leer las Series y los Episodios de las series, se hace una asignación dinámica de
//           memoria.
//           Diseño de métodos para  la generación de reportes de objetos de la clase Serie - la
//           cual ahora ya incluye Episodios, teniendo casos donde la serie no tiene episodios.
//
//  main.cpp
//  Avance 3
//
//  Created by Ma. Guadalupe Roque on 5/28/21.
//  Copyright © 2021 Invitado. All rights reserved.
//

#include <iostream>
#include "Peliculas.hpp"
#include "Series.hpp"

int menuPeliculas(){
    int iOpcion;
    
  /*  cout <<
    "\n *******  Peliculas *******" <<
    "\n1. Leer Peliculas  desde Archivo" <<
    "\n2. Reporte de todas las peliculas" <<
    "\n3. Reporte de peliculas que tienen cierta Calificacion" <<
    "\n4. Reporte de peliculas de cierto genero" <<
    "\n\n *******  Series *******" <<
    "\n5. Leer Series  desde Archivo" <<
    "\n6. Reporte de todas las Series" <<
    "\n7. Reporte de Series que tienen cierta Calificacion" <<
    "\n8. Reporte de Series de cierto genero" <<
    "\n9. Calcular calificación de todas las Series" <<
    
    "\n\n0. SALIR\nTeclea la opcion:"; */
    cin >> iOpcion;
    return iOpcion;
}
// ******************************
//            AVANCE 3
// *******************************
int main() {
    // se manda llamar al constructor - default
    Peliculas peliculas{};
    // Polimorfismo - {} llama al constructor default Video
   // Videos2 videos{};
    Series series{};
    //   Pelicula arrPeliculas[50], pelicula{};
    
    int iOpcion;
    string sGenero, sId;
    double dCal;
 
    // Leer el archivo de peliculas y cargarlo en el arreglo de apuntadores
    // dentro de la clase Peliculas
    peliculas.leerArchivo();
    series.leerArchivo();
    
    // 1o Inicializar la vcc antes del ciclo
    iOpcion = menuPeliculas();
    // 2a Incluir en la condicion la vcc
    while (iOpcion != 0){
        switch (iOpcion) {
                // ***** Peliculas
            case 1: // 1. Leer Peliculas  desde Archivo" <<
                peliculas.leerArchivo();
                break;
            case 2:// 2. Reporte de todas las peliculas" <<
                peliculas.reporteTodasLasPeliculas();
                break;
            case 3:// 3. Reporte de todas las peliculas con cierta Calificacion" <<
              //  cout << "Ingresa la calificacion:";
                cin >> dCal;
                peliculas.reporteConCalificacion(dCal);
                break;
            case 4: // 4. Reporte de todas las peliculas con cierto genero" <<
              //  cout << "Ingresa el Genero:";
                cin >> sGenero;
                peliculas.reporteGenero(sGenero);
                break;
            case 5: // leer videos
               series.leerArchivo();
                break;
            case 6: // 6. Reporte de todas las Series"
                series.reporteTodasLasSeries();
                 break;
            case 7:  // 7. Reporte de Series que tienen cierta Calificacion
              //  cout << "Ingresa la calificación:";
                cin >> dCal;
                series.reporteConCalificacion(dCal);
                 break;
            case 8:  // 8. Reporte de Series de cierto genero
              //  cout << "Ingresa el Genero:";
                cin >> sGenero;
                series.reporteGenero(sGenero);
              //  videos.reporteVideos();
                 break;
            case 9:  // 9. Calcular calificación de todas las Series
                series.calcularCalificacionSeries();
                 break;
            default:
                cout << "Opcion Incorrecta\n";
                break;
        }
        //3o Actualizar la vcc dentro del ciclo
        iOpcion = menuPeliculas();
    }
    return 0;
}


