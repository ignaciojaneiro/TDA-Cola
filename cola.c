#include "cola.h"
#include <stdlib.h>

typedef struct nodo {
	void* dato;
	struct nodo* siguiente;
}nodo_t;

nodo_t* crear_nodo(void* dato){
	nodo_t* nodo = malloc(sizeof(nodo_t));
	if(nodo == NULL){
		return NULL;
	}
	nodo->dato = dato;
	nodo->siguiente = NULL;
	return nodo;
}

void nodo_destruir(nodo_t* nodo){
	free(nodo);
}

struct cola{
	nodo_t* primero;
	nodo_t* ultimo;
};

// Crea una cola.
// Post: devuelve una nueva cola vacía.
cola_t* cola_crear(){
	cola_t* cola = malloc(sizeof(cola_t));
	if (cola == NULL){
		return NULL;
	}
	cola->primero = NULL;
	cola->ultimo = NULL;
	return cola;
}

// Devuelve verdadero si la cola no tiene elementos encolados, false en caso contrario.
// Pre: la cola fue creada.
bool cola_esta_vacia(const cola_t *cola){
	return !cola->primero;
}

// Agrega un nuevo elemento a la cola. Devuelve falso en caso de error.
// Pre: la cola fue creada.
// Post: se agregó un nuevo elemento a la cola, valor se encuentra al final
// de la cola.
bool cola_encolar(cola_t *cola, void* valor){
	nodo_t* nodo = crear_nodo(valor);
	if (cola_esta_vacia(cola)){
		cola->primero = nodo;
		cola->ultimo = nodo;
		return true;
	}
	cola->ultimo->siguiente = nodo;
	cola->ultimo = nodo;
	return true;
}

// Obtiene el valor del primer elemento de la cola. Si la cola tiene
// elementos, se devuelve el valor del primero, si está vacía devuelve NULL.
// Pre: la cola fue creada.
// Post: se devolvió el primer elemento de la cola, cuando no está vacía.
void* cola_ver_primero(const cola_t *cola){
	if(cola_esta_vacia(cola)){
		return NULL;
	}
	return cola->primero->dato;
}
// Saca el primer elemento de la cola. Si la cola tiene elementos, se quita el
// primero de la cola, y se devuelve su valor, si está vacía, devuelve NULL.
// Pre: la cola fue creada.
// Post: se devolvió el valor del primer elemento anterior, la cola
// contiene un elemento menos, si la cola no estaba vacía.
void* cola_desencolar(cola_t *cola){
	if (cola_esta_vacia(cola)){
		return NULL;
	}

	nodo_t* nodo = cola->primero;

	cola->primero = cola->primero->siguiente;

	if(cola_esta_vacia(cola)){
		cola->ultimo = NULL;
	}

	void* dato = nodo->dato;
	nodo_destruir(nodo);
	return dato;
}

// Destruye la cola. Si se recibe la función destruir_dato por parámetro,
// para cada uno de los elementos de la cola llama a destruir_dato.
// Pre: la cola fue creada. destruir_dato es una función capaz de destruir
// los datos de la cola, o NULL en caso de que no se la utilice.
// Post: se eliminaron todos los elementos de la cola.
void cola_destruir(cola_t *cola, void destruir_dato(void*)){
	void* dato;
	while(cola_esta_vacia(cola) == false){
		dato = cola_desencolar(cola);
		if (destruir_dato!=NULL){
			destruir_dato(dato);
		}
	}
	free(cola);
}