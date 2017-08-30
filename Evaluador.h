
#ifndef EVALUADOR_H
#define EVALUADOR_H

#include "Mascota.h"
#include <iostream>       // std::cin, std::cout
#include <queue>          // std::queue
using namespace std;

void evaluar();
void escribir(string nombre_archivo, Mascota*mascota, int posicion);
Mascota* leer(string nombre_archivo, int posicion);
vector<Mascota*> leerTodos(string nombre_archivo);

#endif // EVALUADOR_H