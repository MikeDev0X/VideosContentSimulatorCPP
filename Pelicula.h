#pragma once
#include "Video.h"
#include <string>
using namespace std;


class Pelicula:public Video{
  public:
    Pelicula();
    Pelicula(int,int,int,string,string);
    void muestra();
};

Pelicula::Pelicula():Video(){}

Pelicula::Pelicula(int idV,int dura, int cal, string title, string gender):Video(idV,dura,cal,title,gender){}

void Pelicula::muestra(){
    cout<<"\nTitulo: "<<getTitulo()<<"\n"<<"ID del video: "<<getIdVideo()<<"\n"<<"Género: "<<getGenero()<<"\n"<<"Duración: "<<getDuracion()<<"\n"<<"Calificación: "<<getCalificacion()<<endl;
}