#include "abb.h"
#include <stdio.h>
#include <stdbool.h>

#define FALLO -1



abb_t* arbol_crear(abb_comparador comparador, abb_liberar_elemento destructor){

    if(!comparador){
        return NULL;
    }

    abb_t* abb = malloc(1*sizeof(abb_t));
    abb->comparador = comparador;
    abb->destructor = destructor;
    abb->nodo_raiz = NULL;

    return abb;

}

/**
 * Inserta un nodo nuevo con el elemento requerido a un arbol usando el comparador como
 * criterio para posicionarlo donde corresponde. 
 * Tiene comportamiento recursivo, por lo que puede devolver:
 *  -NULL en caso de falla al reservar el nodo nuevo.
 *  -El nodo del arbol sobre el cual se encuentra actualmente posicionado.
 * Debido a éste último, al finalizar TODOS los retornos recursivos se devuelve la raíz del abb. 
*/
nodo_abb_t* insercion_de_nodo(nodo_abb_t* nodo_actual, abb_comparador comparador, void* elemento){

    if(nodo_actual == NULL){

        nodo_actual = calloc(1, sizeof(nodo_abb_t));
        if(!nodo_actual){
            return NULL;
        }

        nodo_actual->elemento = elemento;
        return nodo_actual;

    }

    int comparacion_de_elementos = comparador(elemento, nodo_actual->elemento);

    //Convención tomada: Si el elemento a insertar es repetido, se inserta a la izquierda del mismo.
    if(comparacion_de_elementos <= 0){ 

        nodo_actual->izquierda = insercion_de_nodo(nodo_actual->izquierda, comparador, elemento);
    
    }
    else if(comparacion_de_elementos > 0){

        nodo_actual->derecha = insercion_de_nodo(nodo_actual->derecha, comparador, elemento);

    }

    return nodo_actual;

}

int arbol_insertar(abb_t* arbol, void* elemento){

    if(!arbol){
        printf("\n\tFallo: No se puede insertar en un arbol inexistente.\n");
        return FALLO;
    }

    nodo_abb_t* nodo_fue_insertado = insercion_de_nodo(arbol->nodo_raiz , arbol->comparador, elemento);

    if(nodo_fue_insertado != NULL){
        arbol->nodo_raiz = nodo_fue_insertado;
        return 0;
    }
    else{
        return FALLO;
    }

}




int arbol_borrar(abb_t* arbol, void* elemento){

    if(arbol_vacio(arbol)){
        printf("\n\tFallo: No se puede borrar de un arbol vacío.\n");
        return FALLO;
    }

    return 0;

}



/**
 * Intenta encontrar 'elemento_buscado' entre los nodos del arbol usando el comparador como
 * criterio para guiar la busqueda. 
 *  -Si logra encontrarlo, se devuelve el puntero al elemento encontrado.
 *  -Si no lo encuentra, se devuelve NULL.
*/
void* busqueda_en_nodos(nodo_abb_t* nodo_actual, abb_comparador comparador, void* elemento_buscado, void* elemento_encontrado){

    if(nodo_actual == NULL){
        return NULL;
    }

    int comparacion = comparador(elemento_buscado, nodo_actual->elemento);

    if(comparacion < 0){

        elemento_encontrado = busqueda_en_nodos(nodo_actual->izquierda, comparador, elemento_buscado, elemento_encontrado);
    
    }
    else if(comparacion > 0){

        elemento_encontrado = busqueda_en_nodos(nodo_actual->derecha, comparador, elemento_buscado, elemento_encontrado);

    }
    else if(comparacion == 0){

        elemento_encontrado = nodo_actual->elemento;

    }
    
    return elemento_encontrado;

}


void* arbol_buscar(abb_t* arbol, void* elemento){

    if(arbol_vacio(arbol)){
        printf("\n\tFallo: No se puede buscar elementos de un arbol vacío.\n");
        return NULL;
    }

    void* elemento_encontrado = NULL; 

    elemento_encontrado = busqueda_en_nodos(arbol->nodo_raiz, arbol->comparador, elemento, elemento_encontrado);

    return elemento_encontrado;

}




void* arbol_raiz(abb_t* arbol){

    if(arbol_vacio(arbol)){
        printf("\n\tFallo: No se puede obtener elemento raíz de arbol vacío.\n");
        return NULL;
    }

    return arbol->nodo_raiz->elemento;

}




bool arbol_vacio(abb_t* arbol){

    if(!arbol){
        return true;
    }
    else if(arbol->nodo_raiz == NULL){
        return true;
    }
    else{
        return false;
    }

}




size_t arbol_recorrido_inorden(abb_t* arbol, void** array, size_t tamanio_array){


    return 0;

}




size_t arbol_recorrido_preorden(abb_t* arbol, void** array, size_t tamanio_array){


    return 0;

}




size_t arbol_recorrido_postorden(abb_t* arbol, void** array, size_t tamanio_array){


    return 0;

}




/**
 * Libera todos los nodos de un arbol. En caso de tener destructor, destruye
 * a su vez a cada elemento.
*/
void destruir_nodos(nodo_abb_t* nodo_actual, abb_liberar_elemento destructor){

    if(!nodo_actual){
        return;
    }
    else if(nodo_actual != NULL){
        destruir_nodos(nodo_actual->izquierda, destructor);
        destruir_nodos(nodo_actual->derecha, destructor);
    }

    if(destructor != NULL){
        destructor(nodo_actual->elemento);
    }
    free(nodo_actual);

}


void arbol_destruir(abb_t* arbol){

    if(!arbol){
        printf("\n\tFallo: No existe el arbol a destruir.\n");
        return;
    }

    destruir_nodos(arbol->nodo_raiz, arbol->destructor);
    free(arbol);

}




size_t abb_con_cada_elemento(abb_t* arbol, int recorrido, bool (*funcion)(void*, void*), void* extra){


    return 0;

}




