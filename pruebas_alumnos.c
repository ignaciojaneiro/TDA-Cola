#include "cola.h"
#include "testing.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>


bool pruebas_memoria_dinamica(){

	cola_t* cola = cola_crear();

	int* memoria_dinamica = malloc(sizeof(int) * 1000);
	
	for(int i = 0; i < 1000; i++){
		memoria_dinamica[i] = i;
	}
	cola_encolar(cola, memoria_dinamica);
	cola_destruir(cola,*(free));
	return true;
}

bool pruebas_volumen(){

	cola_t* cola = cola_crear();

	int* vector[1000];

	for(int i = 0; i < 1000; i++){
		vector[i] = &i;
		cola_encolar(cola,vector[i]);
	}

	for(int i = 0; i < 1000; i++){
		if(cola_desencolar(cola)!=vector[i]){
			return false;
		}
	}

	cola_destruir(cola,NULL);
	return true;
}


void pruebas_cola_alumno(){
	/*Prueba cola vacia*/
	printf("Prueba cola vacia: \n");
	cola_t* cola = cola_crear();
	print_test("Cola creada: ", cola != NULL);
	print_test("Colda desencolar = NULL: ", cola_desencolar(cola) == NULL);
	cola_destruir(cola,NULL);
	print_test("Cola destruida: ", true);

	/*Prueba de encolar y desencolar*/
	printf("Prueba de encolar y desencolar\n");

	cola = cola_crear();

	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;

	int* pa = &a;
	int* pb = &b;
	int* pc = &c;
	int* pd = &d;

	print_test("Encolo pa: ", cola_encolar(cola,pa));
	print_test("Encolo pb: ", cola_encolar(cola,pb));
	print_test("Encolo pc: ", cola_encolar(cola,pc));
	print_test("Encolo pd: ", cola_encolar(cola,pd));

	print_test("Veo primero: ", cola_ver_primero(cola)==pa);
	print_test("Veo si no esta vacia: ", cola_esta_vacia(cola)==false);

	print_test("Desencolo pa: ",cola_desencolar(cola)==pa);
	print_test("Nuevo primero: ",cola_ver_primero(cola)==pb);
	print_test("Desencolo pb: ",cola_desencolar(cola)==pb);
	print_test("Nuevo primero: ",cola_ver_primero(cola)==pc);
	print_test("Desencolo pc: ",cola_desencolar(cola)==pc);
	print_test("Nuevo primero: ",cola_ver_primero(cola)==pd);
	print_test("Desencolo pd: ",cola_desencolar(cola)==pd);

	print_test("Veo si esta vacia: ", cola_esta_vacia(cola)==true);
	cola_destruir(cola,NULL);
	print_test("Cola destruida: ", true);

	/*Prueba con NULLS*/
	
	cola = cola_crear();

	print_test("Encolo primer NULL: ",cola_encolar(cola,NULL));
	print_test("Encolo segundo NULL: ",cola_encolar(cola,NULL));
	print_test("Encolo tercer NULL: ",cola_encolar(cola,NULL));
	print_test("Encolo cuarto NULL: ",cola_encolar(cola,NULL));

	print_test("Veo si no esta vacia: ", cola_esta_vacia(cola)==false);

	print_test("Desencolo primer NULL: ",cola_desencolar(cola)==NULL);
	print_test("Desencolo segundo NULL: ",cola_desencolar(cola)==NULL);
	print_test("Desencolo tercer NULL: ",cola_desencolar(cola)==NULL);
	print_test("Desencolo cuarto NULL: ",cola_desencolar(cola)==NULL);

	print_test("Veo si esta vacia: ", cola_esta_vacia(cola));
	cola_destruir(cola,NULL);
	print_test("Cola destruida: ", true);

	print_test("Prueba destruccion de datos, memoria dinamica: ", pruebas_memoria_dinamica());
	print_test("Prueba Volumne: ", pruebas_volumen());
}