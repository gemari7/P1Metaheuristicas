/*
 * MQKPInstance.cpp
 *
 * Fichero que define los métodos de la clase MQKPInstance. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#include "MQKPInstance.h"
#include "MQKPSolution.h"

//Includes añadidos
#include <fstream>
#include <iostream>
#include<stdio.h>

MQKPInstance::MQKPInstance(){
	_numKnapsacks=0;
	_numObjs=0;
	_profits.resize(0);
	_weights.resize(0);
	_capacities.resize(0);
}

MQKPInstance::~MQKPInstance(){
	//TODO completar
}

double MQKPInstance::getMaxCapacityViolation(MQKPSolution &solution) {

	double *sumWeights = new double[this->_numKnapsacks + 1];

	for (int j = 1; j <= this->_numKnapsacks; j++) {
		sumWeights[j] = 0;
	}

	for (int i = 0; i < this->_numObjs; i++) {

		/*TODO Completar
		 * 1. Obtener la mochila en la que se encuentra el objeto i-ésimo
		 * 2. Si se encuentra en una mochila válida (mayor que 0), incrementar con el peso del objeto el valor correspondiente en sumWeights.
		 */
	}

	double maxCapacityViolation = 0; //Inicializamos la máxima violación de alguna mochila a 0, que significa que no hay ninguna violación

	for (int j = 1; j <= this->_numKnapsacks; j++) {

		/*TODO Completar
		 * 1. Calcular la violación en la mochila j-ésima
		 * 2. Actualizar maxCapacityViolation en su caso
		 */
	}

	delete[] sumWeights;
	return maxCapacityViolation;
}

double MQKPInstance::getSumProfits(MQKPSolution &solution) {

	double sumProfits = 0.;

	/*TODO COMPLETAR
	 * Doble bucle para cada par de objetos
	 * Todo objeto incluido en alguna mochila (> 0) debe sumar su beneficio individual
	 * Todo par de objetos incluidos en la misma mochila (y > 0) debe sumar su beneficio conjunto. IMPORTANTE, sumar los pares (i,j) sólo una vez, es decir, si se suma (i, j), no se debe sumar (j, i)
	 */

	return sumProfits;
}

void MQKPInstance::readInstance(char *filename, int numKnapsacks){
	/*
	 * TODO completar esta función:
	 *   1. leer el número de objetos
	 *   2. reservar la memoria de vectores y matrices
	 *   3. leer beneficios y pesos de los objetos según lo comentado arriba
	 *   4. Calcular las capacidades de las mochilas:
	 *      . Calcular la suma de los pesos de todos los objetos
	 *      . Multiplicar por 0.8
	 *      . Dividir el resultado anterior entre el número de mochilas. Eso será la capacidad de cada mochila
	 */
		std::ifstream f;


		f.open(filename);


		std::string leido;
		double aux;
		f>>leido;//1ºlinea

		f>>aux;//2ºlinea
		std::cout<<"_numObjs: "<<aux<<std::endl;
		_numObjs=aux;

		//Inicializar a 0
		_profits.resize(_numObjs);
		for(int i=0;i<_numObjs;i++)
			_profits[i].resize(_numObjs);

		//Diagonal
		for(int i=0; i<_numObjs;i++){
			f>>aux;

			_profits[i][i]=aux;
		}
		//Mitad superior derecha
		for(int j=0;j<_numObjs;j++){
			for(int i=1; i<_numObjs-j;i++){
				f>>aux;

				_profits[j][i]=aux;
				_profits[i][j]=aux;
			}
		}
		f>>aux;
		f>>aux;
		for(int i=0; i<_numObjs;i++){
			f>>aux;

			_weights[i]=aux;
		}

		f.close();
}
