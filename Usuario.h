#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
#pragma once

class Usuario{
  private:
    string cuenta,nombre;
    int contadorVideos;
    vector<int> misVideos;
    //vector<Objeto*> xd;
    //¿vector?xdxddd

  public: 
    Usuario();

    int getContadorVideos();
    int getUnIdMisVideos(int);


    void  setNombre(string);
    void  setCuenta(string);
    string getNombre();
    string getCuenta();

    void operator+=(int);
};

Usuario::Usuario(){
cuenta=" ";
nombre=" ";
contadorVideos=0;
misVideos={};
}

int Usuario::getContadorVideos(){return contadorVideos;}
int Usuario::getUnIdMisVideos(int _pos){
  if(misVideos.size()>=_pos){
    return misVideos[_pos];
  }
  else{cout<<"Indice incorrecto"<<endl;return -1;}
}

string Usuario::getNombre(){return nombre;}
string Usuario::getCuenta(){return cuenta;}

void Usuario::setNombre(string nombre){this->nombre=nombre;}
void Usuario::setCuenta(string cuenta){this->cuenta=cuenta;}

void Usuario::operator+=(int aid){
  bool confirmar=true;
  for (int z=0;z<misVideos.size();z++){if(misVideos[z]==aid){confirmar=false;break;}}

ifstream archivo;
char tipo;
int indice,duracion,calificacion,numepis,temporada;
string titulo,serie, genero;

archivo.open("Videos.txt");
bool siexiste=false;


if (confirmar==true ){
  ///
  while(archivo>>tipo){
    if(tipo =='p'){
      archivo>>indice>>titulo>>genero>>duracion>>calificacion;
      if(indice == aid){
        misVideos.push_back(aid); contadorVideos+=1;
        siexiste = true;
        break;
      }
    }
    else{
      archivo>>indice>>titulo>>genero>>duracion>>calificacion>>serie>>numepis>>temporada;
      if(indice ==aid){
      misVideos.push_back(aid); contadorVideos+=1;
      siexiste = true;
      break;
      }
    }
    
    }
    ///
    archivo.close();
    if(siexiste){
      if(tipo=='p'){
        cout<<"Se agregó correctamente la película: "<<titulo<<endl;
      }
      else{
        cout<<"Se agregó correctamente el episodio: "<<numepis<<", "<<titulo<<" de la serie: "<< serie<<endl;
      } 
    }
    else{
      cout<<"ERROR: No hay ningún episodio de una serie ni película con ese ID"<<endl;
    }
}
else{
  cout<<"Ya tiene ese ID en su lista"<<endl;
}


}