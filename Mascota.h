#ifndef MASCOTA_H
#define MASCOTA_H

#include <iostream>
#include <list>
#include <fstream>
using namespace std;

class Mascota
{
public:
    int edad;
    string nombre;
    Mascota(int edad,string nombre);
};

#endif // MASCOTA_H