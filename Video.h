#pragma once
#include <string>
using namespace std;

class Video{
  public:
    Video();
    Video(int,int,int,string,string);
    

  int getIdVideo();
  int getDuracion();
  int getCalificacion();
  string getTitulo();
  string getGenero();

  void setIdVideo(int);
  void setDuracion(int);
  void setCalificacion(int);
  void setTitulo(string);
  void setGenero(string);

  virtual void muestra();

  private:
    int  idVideo,duracion,calificacion;
    string titulo,genero;

};

Video::Video(){
  idVideo=0;
  duracion=0;
  calificacion=0;
  titulo="";
  genero="";
}

Video::Video(int id,int dur, int calif, string titu, string gen){
  idVideo=id;
  duracion=dur;
  calificacion=calif;
  titulo=titu;
  genero=gen;
}

int Video::getIdVideo(){ return idVideo;}
int Video::getDuracion(){ return duracion;}
int Video::getCalificacion(){return calificacion;}
string Video::getTitulo(){return titulo;}
string Video::getGenero(){return genero;}

void Video::setIdVideo(int _id){idVideo=_id;}
void Video::setDuracion(int _dur){duracion=_dur;}
void Video::setCalificacion(int _cal){calificacion=_cal;}
void Video::setTitulo(string _title){titulo=_title;}
void Video::setGenero(string _gen){genero=_gen;}

void Video::muestra(){
  cout<<"Titulo: "<<titulo<<"\n"<<"ID del video: "<<idVideo<<"\n"<<"Género: "<<genero<<"\n"<<"Duración: "<<duracion<<"\n"<<"Calificación: "<<calificacion<<endl;
}