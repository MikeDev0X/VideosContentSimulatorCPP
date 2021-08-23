#include "Video.h"
#include <string>
using namespace std;
#pragma once

class Episodio:public Video{
  public:
    Episodio();
    Episodio(int,int,int,string,string,string,int,int);

    string getSerie();
    int getNumeroEp();
    int getNumeroTemp();

    void setSerie(string);
    void setNumeroEp(int);
    void setNumeroTemp(int);

    void muestra();
  
  private:
    string serie;
    int numeroEpisodio,numeroTemporada;
};

Episodio::Episodio():Video(){
  serie=" ";
  numeroEpisodio=0;
  numeroTemporada=0;
}

Episodio::Episodio(int _idV,int _dura, int _calif, string _title, string _gender, string _serie, int _numEp, int _numTemp):Video(_idV,_dura,_calif,_title,_gender){
  serie=_serie;
  numeroEpisodio=_numEp;
  numeroTemporada=_numTemp;
}

string Episodio::getSerie(){return serie;}
int Episodio::getNumeroEp(){return numeroEpisodio;}
int Episodio::getNumeroTemp(){return numeroTemporada;}

void Episodio::setSerie(string serie_){serie=serie_;}
void Episodio::setNumeroEp(int numeroEpisodio_){numeroEpisodio=numeroEpisodio_;}
void Episodio::setNumeroTemp(int numeroTemporada_){numeroTemporada=numeroTemporada_;}

void Episodio::muestra(){
  cout<<"\nTitulo: "<<getTitulo()<<"\n"<<"ID del video: "<<getIdVideo()<<"\n"<<"Género: "<<getGenero()<<"\n"<<"Duración: "<<getDuracion()<<"\n"<<"Calificación: "<<getCalificacion()<<"\n"<<"Serie: "<<serie<<"\n"<<"Número de episodios: "<<numeroEpisodio<<"\n"<<"Número de temporadas: "<<numeroTemporada<<endl;
}
