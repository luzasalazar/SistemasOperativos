/***************************************
-Pontificia Universidad Javeriana
-Nombre: Luz Adriana Salazar
-Clase: Sistemas Operativos
-Fecha: 2025-05-08
-Tema: OpenMP
---------------------------------
- Resumen
  Programa crea hilos de ejecución para cada core 
  imprime cadena de caracteres por cada llamada.

**************************************/


/*
* Descripción: Programa que invoca la API  OpenMP para utilizar el máximo de
* hilos disponibles y que cada uno de ellos imprima un mensaje
*/


#include <omp.h>	//<--------Header necesario para invocar API OpenMP
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	printf("OPenMP ejecutando con %d hilos\n", omp_get_max_threads()); //Imprime el máximo de hilos a usar
#pragma omp parallel //Intrucción directa al compilador para dividir las instrucciones entre los hilos

{ //Code here will be executed by all threads
	printf("Hello world desde el thread %d\n", omp_get_thread_num());
}
	return 0;

}
