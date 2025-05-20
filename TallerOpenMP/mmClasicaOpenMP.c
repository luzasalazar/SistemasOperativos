/***************************************
-Pontificia Universidad Javeriana
-Nombres: Luz Adriana Salazar
-Clase: Sistemas Operativos
-Fecha: 2025-04-30
-Tema: Evaluación de Rendimiento
**************************************/

#include "mmInterfazOpenMP.h"

/*
 * Descripción:
 * Programa para realizar la multiplicación de matrices haciendo uso de programación
 * en paralelo con la biblioteca de OpenMp, dividiendo las filas a multiplicar entre los
 * hilos establecidos.
 */


/*
 * Conclusión:
 * Es posible implementar OpenMP para este problema debido a que la multiplicación de matrices permite ejecutar las mismas instrucciónes
 * en cada hilo y unicamente varían los parámetros que recibe cada uno (la fila a multiplicar).
 * Cuando se declara la directiva de OpenMp, se declaran las variables privadas para cada hilo, de manera que cada uno guarda
 * los valores de su multiplicación de forma individual y evitando que se den condiciones de carrera al intentar acceder a las mismas variables.
 * En la ejecución del programa se recomienda no establecer un número de hilos mayor al número de hilos totales de la maquina que se esté
 * utilizando ya que esto puede empeorar el rendimiento del programa.
 */


/*
 * Función principal que:
 * 1. Valida argumentos de entrada (tamaño de matriz y número de hilos)
 * 2. Reserva memoria e inicializa matrices
 * 3. Realiza la multiplicación de matrices en paralelo con OpenMP 
 * 4. Mide el tiempo de ejecución
 * 5. Imprime las matrices si son pequeñas
 */
int main(int argc, char *argv[]){
	if(argc < 3){
		printf("\n Use: $./clasicaOpenMP SIZE Hilos \n\n");
		exit(0);
	}

	int N = atoi(argv[1]);  // Dimensión de la matriz
	int TH = atoi(argv[2]); // Número de hilos a utilizar

	// Reservar memoria para matrices A, B y C 
	size_t *matrixA  = (size_t *)calloc(N*N, sizeof(size_t));
	size_t *matrixB  = (size_t *)calloc(N*N, sizeof(size_t));
	size_t *matrixC  = (size_t *)calloc(N*N, sizeof(size_t));

	srand(time(NULL));      // Inicializa semilla para números aleatorios 

	omp_set_num_threads(TH); // Establece número de hilos a usar con OpenMP

	iniMatrix(matrixA, matrixB, N); // Inicializa las matrices A y B

	impMatrix(matrixA, N);  // Imprime matriz A si es pequeña
	impMatrix(matrixB, N);  // Imprime matriz B si es pequeña

	InicioMuestra();              // Inicia cronómetro
	multiMatrix(matrixA, matrixB, matrixC, N); // Multiplica matrices
	FinMuestra();                 // Finaliza cronómetro e imprime el tiempo

	impMatrix(matrixC, N);        // Imprime matriz resultado si es pequeña

	free(matrixA);                // Libera memoria asignada a matriz A
	free(matrixB);                // Libera memoria asignada a matriz B
	free(matrixC);                // Libera memoria asignada a matriz C
	
	return 0;
}