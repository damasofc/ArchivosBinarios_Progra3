// queue::push/pop
#include "Mascota.h"
#include "Evaluador.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

int TAMANO_REGISTRO = 14;

//Escribe los datos del objeto mascota dado en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo
void escribir(string nombre_archivo, Mascota*mascota, int posicion)
{
    ofstream out(nombre_archivo.c_str(),ios::in | ios::out);
    //este if comprueba que si el archivo no se abrio(porque no existe), entonces se va a crear.
    if(!out.is_open())
    {
      out.open(nombre_archivo.c_str());
    }
    out.seekp(posicion * TAMANO_REGISTRO);
    out.write((char*)&mascota->edad,4);
    out.write(mascota->nombre.c_str(),10);
    
    out.close();
}

//Devuelve una mascota previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo
Mascota* leer(string nombre_archivo, int posicion)
{
    char nombre[10];
    Mascota *m = new Mascota(-1,"");
    ifstream in(nombre_archivo.c_str());
    in.seekg(posicion*TAMANO_REGISTRO);
    in.read((char*)&m->edad,4);
    in.read(nombre,10);
    m->nombre = nombre;
    
    return m;
}
int getCantidadDeRegistros(string archivo)
{
  ifstream in(archivo.c_str());
  //esto significa, posicioname a 0 bytes del final del archivo, el ios::end significa el final
  //digamos si quieero posicionarme en el ultimo registro entonces en vez de 0 pondria -14
  in.seekg(0,ios::end);
  //aca el tellg, lee cuantos bytes hay en total donde estoy ubicado, y como estoy ubicado en el final
  //entonces me lee el tamano total del archivo.
  int cantidad_bytes = in.tellg();
  in.close();
  return cantidad_bytes / TAMANO_REGISTRO;
}

//Devuelve un vector que contenga todas las mascotas previamente escritas (con la funcion escribir()) en un archivo binario con nombre dado
//Nota: El vector debe contener las mascotas ordenadas de acuerdo a la posicion en la que se escribieron
vector<Mascota*> leerTodos(string nombre_archivo)
{   
    int cant = getCantidadDeRegistros(nombre_archivo);
    vector<Mascota*>respuesta;
    ifstream in(nombre_archivo.c_str());
    in.seekg(0);
    for(int i = 0; i < cant; i++)
    {
        respuesta.push_back(leer(nombre_archivo,i));
    }
    
    return respuesta;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}