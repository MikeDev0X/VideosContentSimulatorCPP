#include <iostream>
#include <vector>
#include <fstream>
#include "Video.h"
#include "Usuario.h"
#include "Episodio.h"
#include "Pelicula.h"
#include <string>

//VARIABLES Y VECTORES GLOBALES
vector<Video*> Videos;
vector<Usuario> Usuarios;

//FUNCION PARA MENÚ DEL PROGRAMA
char menu(){
  char opcion;
  cout<<"\n\nMenú"<<endl;
  cout<<"Tiene 7 opciones para navegar"<<endl;
  cout<<"Digite una de las siguientes opciones: "<<endl;
  cout<<"'a': consultar la lista de videos disponibles.  "<<endl;
  cout<<"'b': consultar la lista de videos con cierta calificación"<<endl;
  cout<<"'c': consultar la lista de videos por género"<<endl;
  cout<<"'d': ver datos de los usuarios"<<endl;
  cout<<"'e': modificar el perfil de un usuario con base en su cuenta"<<endl;
  cout<<"'f': agregar un video a la lista del usuario con base en su cuenta"<<endl;
  cout<<"'g': salir "<<endl;
  while(true){
   cin>>opcion;
   try{
   if(opcion != 'a' && opcion != 'b' && opcion != 'c' && opcion != 'd' && opcion != 'e' && opcion != 'f' && opcion != 'g' ){throw opcion;}
   else{break;}
   }
   catch(char opcion){
     cout << "Su opcion no es ninguna de las indicadas, porfavor intente otra vez"<<endl;
   }
  }
  return opcion;
}
//FUNCION PARA VER VIDEOS DISPONIBLES
char videosDisponibles(vector<Video*> Videos){///a
  for(int z=0; z<Videos.size();z++){Videos[z]->muestra();}
  return 'h';
}
//FUNCION PARA VER VIDEOS SEGÚN CALIFICACIÓN 
char videosCalificacion(vector<Video*>){///b
  int choose;
      while(true){
        cout<<"Las calificaciones de películas van de 0 a 5"<<endl;
        cout<<"Ingrese la calificación que quiera consultar o digite '6' para regresar al menú: ";
        cin >> choose;
        if(choose>=0 && choose <=5){
        break;
        }
        else if(choose == 6){break;}
        else{
          cout<<"Opción inválida, intente de nuevo, recuerde que es de 0 a 5"<<endl;
        }
      }
      
    if(choose != 6){
    for(int i=0;i<Videos.size();i++){
      if(Videos[i]->getCalificacion() == choose){
        Videos[i]->muestra();
        }
      }
    }
    return 'h'; 
}
//FUNCION PARA VER VIDEOS SEGÚN EL GÉNERO
char videosGenero(vector<Video*>)
  {
      string choose2;
      while(true){
        
        cout<<"Los géneros disponibles son: "<<"\nSuspenso\nCiencia_ficcion\nDrama\nTerror\nComedia\nAccion\nAventura"<<endl;

        cout<<"Ingrese el género que quiera consultar o digite 'salir' para regresar al menú:  ";
        
        cin >> choose2;
        if(choose2 =="Suspenso" || choose2 =="Ciencia_ficcion"|| choose2 =="Drama"|| choose2 =="Terror"|| choose2 =="Comedia"|| choose2 =="Accion"|| choose2 =="Aventura"){
          break;
        }
        else if(choose2 == "salir"){break;}
        else{
          cout<<"Opción inválida, ingrese un género correcto"<<endl;
        }
      }
      if(choose2 != "salir"){
      for(int i=0;i<Videos.size();i++){
        if(Videos[i]->getGenero() == choose2){
        Videos[i]->muestra();
          }
        }
      }
    return 'h';
    }
//FUNCION PARA VER LA LISTA COMPLETA DE USUARIOS
char listaUsuarios(vector<Usuario>,vector<Video*> ){
      for(int x=0;x<Usuarios.size();x++){
      cout << "\nCuenta: "<< Usuarios[x].getCuenta()<<endl;
      cout << "Nombre: "<< Usuarios[x].getNombre()<<endl;
      cout << "El tamaño de tu lista es: "<<Usuarios[x].getContadorVideos()<<endl;
      if(Usuarios[x].getContadorVideos() == 0){
        cout<<"Comience a añadir videos"<<endl;
      }
      else{
        for(int y=0;y<Usuarios[x].getContadorVideos();y++){
          for(int z=0;z<Videos.size();z++){
            if(Usuarios[x].getUnIdMisVideos(y) == Videos[z]->getIdVideo()){
              Videos[z]->muestra();
              }
            }
          }
        }
      }
     return 'h'; 
  
}
//FUNCION PARA MODIFICAR LOS PERFILES
char modificarPerfil(vector<Usuario>){
  
      int indicecuentnom;
      string kitten1,kitten2, nuevonombre,nuevacuenta;
      bool kittencontrol=true,kittencontrol2=false;
      while(kittencontrol && kitten1 != "salir"){
        cout<<"Ingrese su cuenta o digite 'salir' para regresar al menú: ";
        cin>>kitten1;
        if(kitten1 == "salir"){break;}
        cout<<"Ingrese su nombre: ";
        cin>>kitten2;
        for(int i=0;i<Usuarios.size();i++){
          if(Usuarios[i].getCuenta() == kitten1 && Usuarios[i].getNombre()==kitten2){
            kittencontrol = false;
            indicecuentnom = i;
            break;}
        }
        if(kittencontrol && kitten1 != "salir"){
          cout<<"Intente otro nombre o cuenta que ya exista para cambiar o digite 'salir' para regresar al menú "<<endl;
        }
      }
      if(kitten1== "salir"){
          return 'h';
        } else {
        
        while(true){
          cout<<"Ingrese su nueva cuenta: ";
          cin>>nuevacuenta;
          for(int i=0;i<Usuarios.size();i++){
            if(Usuarios[i].getCuenta() == nuevacuenta){
              kittencontrol2 = true;
            }
          }
          if(kittencontrol2){
            cout<<"Ya hay una cuenta igual, inténtalo de nuevo"<<endl;
            kittencontrol2=false;
          }
          else{
            break;
          }
        }
        cout<<"Ingrese su nuevo nombre: ";
        cin>>nuevonombre;
        Usuarios[indicecuentnom].setCuenta(nuevacuenta);
        Usuarios[indicecuentnom].setNombre(nuevonombre);
        cout<<"NOMBRE Y CUENTA CAMBIADOS CORRECTAMENTE"<<endl;
        return 'h';
}
}
//FUNCION PARA AGREGAR VIDEOS EN LA LISTA DE LOS USUARIOS
char agregarVideos(vector<Usuario>){///f
    string gato=" ";
      int warzone,kesto;
      bool confirmo=false;
      while(true){//inicia while
        cout<<"Ingrese su cuenta o introduzca 'salir' para regresar al menú: ";
        cin>>gato;
        for(int i=0;i<Usuarios.size();i++){
          if(gato == Usuarios[i].getCuenta()){
            confirmo = true;
            warzone=i;
            break;
          }
        }
        if(confirmo){
          break;
        }
        else{
          if(gato == "salir"){
            cout<<"Entendido, volviendo al menú"<<endl;
            return 'h';
          }
          else{
          cout<<"No se encontró el usuario, introduzca uno correcto"<<endl;
          }
        }
      }//acaba while
      
      if(gato== "salir"){return 'h';}
      cout<<"Introduzca el id de la película o episodio de serie: ";
      cin>>kesto;
      Usuarios[warzone]+=kesto;
      
      return 'h';
}
//FUNCION PARA SALIR DEL PROGRAMA
void salida(vector<Video*>,vector<Usuario>){
  double contador=0;
      cout<<"Cantidad de videos disponibles: "<<Videos.size()<<endl;
      cout<<"Cantidad de usuarios en la plataforma: "<<Usuarios.size()<<endl;
      cout<<"Promedio de videos en la lista de los usuarios: ";
      for(int i=0;i<Usuarios.size();i++){
        contador += Usuarios[i].getContadorVideos();
      }
      contador = contador / Usuarios.size();
      cout<<contador<<endl;
      contador = 0;
      
      for(int i=0;i<Videos.size();i++){
        contador += Videos[i]->getCalificacion();
      }
      contador = contador / Videos.size();

      cout<<"Promedio de calificaciones de los videos disponibles: "<<contador<<endl;
      int contadors=0,contadorcf=0,contadord=0,contadort=0,contadorc=0,contadorac=0,contadorav=0;

      for(int i=0;i<Videos.size();i++){
      
      if(Videos[i]->getGenero() == "Suspenso"){contadors++;}
        else if(Videos[i]->getGenero()=="Ciencia_ficcion"){
          contadorcf++;
        }
        else if(Videos[i]->getGenero() == "Drama"){
          contadord++;
        }
        else if(Videos[i]->getGenero()=="Terror"){
          contadort++;
        }
        else if(Videos[i]->getGenero() == "Comedia"){
          contadorc++;
        }
        else if(Videos[i]->getGenero() == "Aventura"){
          contadorav++;
        }
        else if(Videos[i]->getGenero() == "Accion"){
          contadorac++;
        }
        
      }

      cout << "Lista de cantidad de videos por géneros"<<endl;
      cout<<"Suspenso Cantidad: "<<contadors <<endl;
      cout<<"Ciencia_ficcion Cantidad: "<<contadorcf <<endl;
      cout<<"Drama Cantidad: "<<contadord <<endl;
      cout<<"Terror Cantidad: "<<contadort <<endl;
      cout<<"Comedia Cantidad: "<<contadorc <<endl;
      cout<<"Aventura Cantidad: "<<contadorav <<endl;
      cout<<"Accion Cantidad: "<<contadorac <<endl;

      cout<<"Saliendo del programa..."<<endl;
      } 

//FUNCION PARA ABRIR ARCHIVOS
void archivos(){
  char tipo;
  int indice,duracion,calificacion,numepis,temporada;
  string titulo,serie, genero,cuenta,nombre;
  ifstream archivo1;
  ifstream archivo2;

archivo1.open("Usuarios.txt");
while(archivo1>>cuenta){
  archivo1>>nombre;
  Usuario usuarioprueba;
  usuarioprueba.setCuenta(cuenta);
  usuarioprueba.setNombre(nombre);
  Usuarios.push_back(usuarioprueba);
}
archivo1.close();
archivo2.open("Videos.txt");

while(archivo2>>tipo){
    if(tipo =='p'){
      archivo2>>indice>>titulo>>genero>>duracion>>calificacion;
      Video  *videosprueba1;
      videosprueba1 = new Pelicula(indice,duracion, calificacion, titulo, genero);
      Videos.push_back(videosprueba1);
    }
    else{
      archivo2>>indice>>titulo>>genero>>duracion>>calificacion>>serie>>numepis>>temporada;
      Video  *videosprueba2;
      videosprueba2 = new Episodio (indice,duracion, calificacion, titulo, genero,serie,numepis,temporada);
      Videos.push_back(videosprueba2);
    }
}
archivo2.close();
}

//---------------------------------------------------------------------

int main(){

archivos();
char control='h';

  while(true){
  if(control =='h'){control = menu();}
  else if(control=='a'){control = videosDisponibles(Videos);}
  else if(control=='b'){control = videosCalificacion(Videos);}
  else if(control=='c'){control = videosGenero(Videos);}
  else if(control=='d'){control = listaUsuarios(Usuarios,Videos);}
  else if(control=='e'){control = modificarPerfil(Usuarios);}
  else if(control=='f'){control = agregarVideos(Usuarios);}
  else if(control=='g'){salida(Videos,Usuarios);break;}
  }
}