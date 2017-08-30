#include "Evaluador.h"

string getPrimerElemento(queue<string> mi_cola);


void evaluar()
{
    int nota = 0;

    escribir("archivo_evaluador",new Mascota(3,"lili"),2);
    escribir("archivo_evaluador",new Mascota(1,"lola"),0);
    escribir("archivo_evaluador",new Mascota(2,"lele"),1);

    cout<<"Ejercicio escribir() y leer():\t\t";
    bool correcto = true;
    if(  (leer("archivo_evaluador",0)->edad == 1
       && leer("archivo_evaluador",1)->edad == 2
       && leer("archivo_evaluador",2)->edad == 3
       && leer("archivo_evaluador",0)->nombre == "lola"
       && leer("archivo_evaluador",1)->nombre == "lele"
       && leer("archivo_evaluador",2)->nombre == "lili")==false)
    {
        correcto=false;
    }

    escribir("archivo_evaluador",new Mascota(10,"juan"),1);
    escribir("archivo_evaluador",new Mascota(20,"pedro"),2);

    if(  (leer("archivo_evaluador",1)->edad == 10
       && leer("archivo_evaluador",2)->edad == 20
       && leer("archivo_evaluador",1)->nombre == "juan"
       && leer("archivo_evaluador",2)->nombre == "pedro")==false)
    {
        correcto=false;
    }

    if(correcto)
    {
        nota+=3;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Ejercicio leerTodos():\t\t\t";
    vector<Mascota*>temp=leerTodos("archivo_evaluador");

    if(temp.size()<3)
    {
        cout<<"Incorrecto"<<endl;
    }
    else if(   temp[0]->edad==1
       && temp[1]->edad==10
       && temp[2]->edad==20
       && temp[0]->nombre=="lola"
       && temp[1]->nombre=="juan"
       && temp[2]->nombre=="pedro")
    {
        nota+=3;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }


    cout<<endl<<"Nota: "<<nota<<"/6"<<endl;
}