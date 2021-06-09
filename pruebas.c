#include "abb.h"
#include <stdio.h>
#include <stdbool.h>
#include "pa2mm.h"
#include "string.h"


#define FALLO -1



//Por comodidad de lectura, "encapsulo" las funciones auxiliares de las pruebas usando entre separadores del tipo:  "// ======== // ======== //"

// ========================================================= // ========================================================= //


/**
 * Destructor auxiliar de prueba.
 * Hace free del elemento recibido.
*/
void destructor_de_prueba(void* elemento){

  free(elemento);

}

/**
 * Comparador auxiliar de prueba.
 * Recibe dos enteros. Devuelve:
 * 0 en caso de ser iguales, >0 si el primer elemento es mayor al
 * segundo o <0 si el primer elemento es menor al segundo.
*/
int comparador_de_enteros(void* elemento_1 , void* elemento_2){

  int* entero_1 = elemento_1;
  int* entero_2 = elemento_2;
  
  return ((*entero_1) - (*entero_2));

}


/**
 * Funcion auxiliar.
 * Crea un arbol de enteros, se usará de forma generalizada para las pruebas.
 * Más específicamente, crea el arbol ilustrado y explicado en sección ACLARACIONES del README.txt
*/
abb_t* crear_abb_generico(bool* todos_se_insertaron){

  abb_t* abb = arbol_crear(comparador_de_enteros, destructor_de_prueba);

  //Enteros de prueba:

  // Aunque parezca innecesario hacer esto, la explicación de por qué uso memoria
  // dinámica en las pruebas se encuentra en el mismo apartado (de la ilustración) del README.txt
  int* cero = malloc(1*sizeof(int));
  if(!cero){
    return NULL;
  }
  int* uno = malloc(1*sizeof(int));
  if(!uno){
    free(cero);
    return NULL;
  }
  int* dos = malloc(1*sizeof(int));
  if(!dos){
    free(cero);
    free(uno);
    return NULL;
  }
  int* tres = malloc(1*sizeof(int));
  if(!tres){
    free(cero);
    free(uno);
    free(dos);
    return NULL;
  }
  int* cuatro = malloc(1*sizeof(int));
  if(!cuatro){
    free(cero);
    free(uno);
    free(dos);
    free(tres);
    return NULL;
  } 
  int* cinco = malloc(1*sizeof(int));
  if(!cinco){
    free(cero);
    free(uno);
    free(dos);
    free(tres);
    free(cuatro);
    return NULL;
  }
  int* cinco_repetido = malloc(1*sizeof(int));
  if(!cinco_repetido){
    free(cero);
    free(uno);
    free(dos);
    free(tres);
    free(cuatro);
    free(cinco);
    return NULL;
  }
  int* seis = malloc(1*sizeof(int));
  if(!seis){
    free(cero);
    free(uno);
    free(dos);
    free(tres);
    free(cuatro);
    free(cinco);
    free(cinco_repetido);
    return NULL;
  }
  int* siete = malloc(1*sizeof(int));
  if(!siete){
    free(cero);
    free(uno);
    free(dos);
    free(tres);
    free(cuatro);
    free(cinco);
    free(cinco_repetido);
    free(seis);
    return NULL;
  }
  int* ocho = malloc(1*sizeof(int));
  if(!ocho){
    free(cero);
    free(uno);
    free(dos);
    free(tres);
    free(cuatro);
    free(cinco);
    free(cinco_repetido);
    free(seis);
    free(siete);
    return NULL;
  }
  int* nueve = malloc(1*sizeof(int));
  if(!nueve){
    free(cero);
    free(uno);
    free(dos);
    free(tres);
    free(cuatro);
    free(cinco);
    free(cinco_repetido);
    free(seis);
    free(ocho);
    return NULL;
  }
  
  (*cero) = 0;
  (*uno) = 1;
  (*dos) = 2;
  (*tres) = 3;
  (*cuatro) = 4;
  (*cinco) = 5;
  (*cinco_repetido) = 5;
  (*seis) = 6;
  (*siete) = 7;
  (*ocho) = 8;
  (*nueve) = 9;

  //Orden de inserción en el arbol: 5,3,7,6,8,9,4,1,2,0,5.

  int se_inserto_actual = arbol_insertar(abb, cinco);
  if((se_inserto_actual == FALLO) && (todos_se_insertaron != NULL)){
    (*todos_se_insertaron) = false;
  }

  se_inserto_actual = arbol_insertar(abb, tres);
  if(((se_inserto_actual == FALLO) && (todos_se_insertaron != NULL))){
    (*todos_se_insertaron) = false;
  }

  se_inserto_actual = arbol_insertar(abb, siete);
  if(((se_inserto_actual == FALLO) && (todos_se_insertaron != NULL))){
    (*todos_se_insertaron) = false;
  }

  se_inserto_actual = arbol_insertar(abb, seis);
  if(((se_inserto_actual == FALLO) && (todos_se_insertaron != NULL))){
    (*todos_se_insertaron) = false;
  }

  se_inserto_actual = arbol_insertar(abb, ocho);
  if(((se_inserto_actual == FALLO) && (todos_se_insertaron != NULL))){
    (*todos_se_insertaron) = false;
  }

  se_inserto_actual = arbol_insertar(abb, nueve);
  if(((se_inserto_actual == FALLO) && (todos_se_insertaron != NULL))){
    (*todos_se_insertaron) = false;
  }

  se_inserto_actual = arbol_insertar(abb, cuatro);
  if(((se_inserto_actual == FALLO) && (todos_se_insertaron != NULL))){
    (*todos_se_insertaron) = false;
  }

  se_inserto_actual = arbol_insertar(abb, uno);
  if(((se_inserto_actual == FALLO) && (todos_se_insertaron != NULL))){
    (*todos_se_insertaron) = false;
  }

  se_inserto_actual = arbol_insertar(abb, dos);
  if(((se_inserto_actual == FALLO) && (todos_se_insertaron != NULL))){
    (*todos_se_insertaron) = false;
  }

  se_inserto_actual = arbol_insertar(abb, cero);
  if(((se_inserto_actual == FALLO) && (todos_se_insertaron != NULL))){
    (*todos_se_insertaron) = false;
  }

  se_inserto_actual = arbol_insertar(abb, cinco_repetido);
  if(((se_inserto_actual == FALLO) && (todos_se_insertaron != NULL))){
    (*todos_se_insertaron) = false;
  }

  return abb;

}

// ========================================================= // ========================================================= //





// CREACIÓN


void DadoComparadorNull_SiSePideCrear_NoSeCreaYSeRetornaNull(){

  abb_t* abb = arbol_crear(NULL, destructor_de_prueba);
  pa2m_afirmar( abb == NULL , "No se puede crear un arbol sin comparador");
  
  printf("\n");

}



void DadoComparadorValido_SiSePideCrearConOSinDestructor_SeCreaCorrectamenteAbb(){
  
  abb_t* abb = arbol_crear(comparador_de_enteros, NULL);
  pa2m_afirmar( abb != NULL , "Se crea correctamente un arbol con comparador, pero sin destructor.");
  pa2m_afirmar( abb->nodo_raiz == NULL , "El arbol creado no tiene elementos.")
  arbol_destruir(abb);

  abb = arbol_crear(comparador_de_enteros, destructor_de_prueba);
  pa2m_afirmar( abb != NULL , "Se crea correctamente un arbol con comparador y con destructor.");
  pa2m_afirmar( abb->nodo_raiz == NULL , "El arbol creado no tiene elementos.")
  arbol_destruir(abb);
  
  printf("\n");

}





// INSERCIÓN


void DadoAbbInexistente_SiSeIntentaInsertarElemento_NoSePuedeInsertar(){

  int uno = 1; //Elemento de prueba

  pa2m_afirmar( arbol_insertar(NULL , &uno) == FALLO , "No se puede insertar en un arbol inexistente.");

  printf("\n");

}





void DadoAbbSinElementos_SiSeInsertaUnElemento_SeInsertaCorrectamenteYElementoInsertadoEsRaiz(){

  abb_t* abb = arbol_crear(comparador_de_enteros, NULL);

  int uno = 1; //Elemento de prueba

  pa2m_afirmar( arbol_insertar(abb, &uno) == 0 , "Se insertó un elemento a un abb sin elementos.");
  pa2m_afirmar( *(int*)(abb->nodo_raiz->elemento) == uno , "El elemento insertado es el requerido y es ahora la raíz del arbol.");
  arbol_destruir(abb);

  printf("\n");

}




// ========================================================= // ========================================================= //


/**
 * Función auxiliar de uso limitado a prueba de inserción.
 * Devuelve:
 *  -true si todos los elementos insertados estan en la posición del arbol que
 * les corresponde, y si los hijos de las hojas son NULL.
 *  -false en caso de que no se cumpla alguno de los anteriores.
*/
bool verificacion_sub_arboles(nodo_abb_t* raiz){

  //Nuevamente se cita la visualización del README.txt
  //Se guardan los nodos de los enteros con los nombres de los numeros que les deberían corresponder tras la inserción:
  nodo_abb_t* tres = raiz->izquierda;
  nodo_abb_t* uno = raiz->izquierda->izquierda;
  nodo_abb_t* cero = raiz->izquierda->izquierda->izquierda;
  nodo_abb_t* dos = raiz->izquierda->izquierda->derecha;
  nodo_abb_t* cuatro = raiz->izquierda->derecha;
  nodo_abb_t* cinco_repetido = raiz->izquierda->derecha->derecha; //El elemento de la raíz ya se revisó anteriormente. Este cinco es el que está a la derecha del 4.
  nodo_abb_t* siete = raiz->derecha;
  nodo_abb_t* seis = raiz->derecha->izquierda;
  nodo_abb_t* ocho = raiz->derecha->derecha;
  nodo_abb_t* nueve = raiz->derecha->derecha->derecha;

  bool resultado = (    (*(int*)(tres->elemento) == 3)  &&  (*(int*)(uno->elemento) == 1)  &&  (*(int*)(cero->elemento) == 0)  &&  (cero->izquierda == NULL)  &&  (cero->derecha == NULL)  &&  (*(int*)(dos->elemento) == 2)  &&  (dos->izquierda == NULL)  &&  (dos->derecha == NULL)  &&  (*(int*)(cuatro->elemento) == 4)  &&  (*(int*)(cinco_repetido->elemento) == 5)  &&  (cinco_repetido->izquierda == NULL)  &&  (cinco_repetido->derecha == NULL)  &&  (*(int*)(siete->elemento) == 7)  &&  (*(int*)(seis->elemento) == 6)  &&  (seis->izquierda == NULL)  &&  (seis->derecha == NULL)  &&  (*(int*)(ocho->elemento) == 8)  &&  (*(int*)(nueve->elemento) == 9) && (nueve->izquierda == NULL) && (nueve->derecha == NULL)    );

 return resultado;

}

// ========================================================= // ========================================================= //





void DadoAbbSinElementos_SiSeInsertanVariosElementos_SeInsertanTodosYComoCorresponde(){

  //IMPORTANTE VER ilustración del resultado deseado en README.txt, sección Aclaraciones.
  //Allí se encuentra explicación de lo siguiente.

  bool todos_se_insertaron = true;
  abb_t* abb = crear_abb_generico(&todos_se_insertaron);

  pa2m_afirmar( todos_se_insertaron , "Se insertaron varios elementos en un arbol.");
  
  nodo_abb_t* raiz = abb->nodo_raiz;
  pa2m_afirmar( *(int*)(raiz->elemento) == 5 , "El elemento de la raíz es el requerido.");

  //Para las siguientes se requiere ver la ilustración mencionada a modo de guía.
  bool sub_arboles_tienen_elementos_requeridos = verificacion_sub_arboles(raiz);

  pa2m_afirmar( sub_arboles_tienen_elementos_requeridos , "Todos los elementos de los sub-arboles tienen los elementos requeridos.");
  pa2m_afirmar( sub_arboles_tienen_elementos_requeridos , "Los hijos de las hojas son NULL.");
  
  arbol_destruir(abb);

  printf("\n");

}





// FUNCIONES DE UTILIDAD


void DadoAbbSinElementosOInexistente_SiSePreguntaSiEstaVacio_SeDevuelveTrue(){
  
  pa2m_afirmar( arbol_vacio(NULL) == true , "Un arbol inexistente es vacío.");

  abb_t* abb = arbol_crear(comparador_de_enteros, NULL);
  pa2m_afirmar( arbol_vacio(abb) == true , "Un arbol existente sin elementos es vacío.");
  
  arbol_destruir(abb);
  printf("\n");

}


void DadoAbbConUnElemento_SiSePreguntaSiEstaVacio_SeDevuelveFalse(){

  abb_t* abb = arbol_crear(comparador_de_enteros, NULL);
  //No encuentro necesario usar el arbol genérico para esta prueba.

  int uno = 1 , dos = 2 ; //Elementos de prueba
  arbol_insertar(abb, &uno);
  pa2m_afirmar( arbol_vacio(abb) == false , "Un arbol con un elemento no es vacío.");

  arbol_insertar(abb, &dos);
  pa2m_afirmar( arbol_vacio(abb) == false , "Un arbol con más de un elemento no es vacío.");

  arbol_destruir(abb);

  printf("\n");

}




void DadoAbbVacio_SiSePideElementoRaiz_SeDevuelveNull(){

  void* elemento_raiz = arbol_raiz(NULL);
  pa2m_afirmar( elemento_raiz == NULL , "No se puede obtener elemento raiz de un arbol inexistente.");

  abb_t* abb = arbol_crear(comparador_de_enteros, NULL);
  elemento_raiz = arbol_raiz(abb);
  pa2m_afirmar( elemento_raiz == NULL , "No se puede obtener elemento raíz de un arbol sin elementos.");

  arbol_destruir(abb);
  printf("\n");

}




void DadoAbbConElementos_SiSePideElementoRaiz_SeDevuelveEseElementoCorrectamente(){

  abb_t* abb = arbol_crear(comparador_de_enteros, NULL);
  //No encuentro necesario usar el arbol genérico para esta prueba.

  int uno = 1 , dos = 2 ; //Elementos de prueba
  arbol_insertar(abb, &uno);
  arbol_insertar(abb, &dos);

  pa2m_afirmar( *(int*)arbol_raiz(abb) == 1 , "Al pedir elemento raíz de arbol con varios elementos, se devuelve el adecuado.");

  arbol_destruir(abb);

  printf("\n");

}




// BUSQUEDA

void DadoAbbVacio_SiSePideBuscarUnElemento_SeDevuelveNull(){

  int uno = 1; //Elemento de prueba

  pa2m_afirmar( arbol_buscar(NULL, &uno) == NULL , "Si se pide buscar elemento de arbol inexistente, se devuelve NULL.");

  abb_t* abb = arbol_crear(comparador_de_enteros, NULL);

  pa2m_afirmar( arbol_buscar(abb, &uno) == NULL , "Si se pide buscar elemento de arbol sin elementos, se devuelve NULL");

  arbol_destruir(abb);
  printf("\n");

}




void DadoAbbConElementos_SiSeBuscanElementosQueEstanEnElAbb_SeDevuelvenCorrectamenteLosMismos(){

  abb_t* abb = crear_abb_generico(NULL);
  //Conviene tener a la mano la ilustración del arbol genérico.
  int* cinco_de_raiz = abb->nodo_raiz->elemento;
  int* cero = abb->nodo_raiz->izquierda->izquierda->izquierda->elemento;
  int* cuatro = abb->nodo_raiz->izquierda->derecha->elemento;
  int* seis = abb->nodo_raiz->derecha->izquierda->elemento;
  int* siete = abb->nodo_raiz->derecha->elemento;
  int* ocho = abb->nodo_raiz->derecha->derecha->elemento;
  
  pa2m_afirmar( *(int*)arbol_buscar(abb, cero) == 0 , "Se buscó un elemento hoja de un arbol con elementos, el resultado es el esperado.");
  pa2m_afirmar( *(int*)arbol_buscar(abb, seis) ==  6 , "Se buscó otra hoja distinta, el resultado es el esperado.");
  pa2m_afirmar( *(int*)arbol_buscar(abb, cuatro) ==  4 , "Se buscó un elemento en una altura intermedia, el resultado es el esperado.");
  pa2m_afirmar( *(int*)arbol_buscar(abb, ocho) ==  8 , "Se buscó otro elemento de altura intermedia, el resultado es el esperado.");
  pa2m_afirmar( *(int*)arbol_buscar(abb, siete) ==  7 , "Se buscó el hijo derecho de la raíz, el resultado es el esperado.");
  pa2m_afirmar( *(int*)arbol_buscar(abb, cinco_de_raiz) ==  5 , "Se buscó elemento que está repetido en el arbol, se devuelve el primero de ellos que se encuentra.");

  arbol_destruir(abb);
  printf("\n");

}




void DadoAbbConElementos_SiSeBuscanElementosQueNoEstanEnElAbb_SeDevuelveNull(){

  abb_t* abb = arbol_crear(comparador_de_enteros, NULL);
  //No encuentro necesario usar el arbol genérico para esta prueba.

  int uno = 1 , dos = 2 , elemento_no_perteneciente = 10 ; //Elementos de prueba
  arbol_insertar(abb, &uno);
  arbol_insertar(abb, &dos);

  pa2m_afirmar( arbol_buscar(abb, &elemento_no_perteneciente) == NULL , "Al buscar elemento que no pertenece a un arbol, se devuelve NULL.");

  arbol_destruir(abb);

  printf("\n");

}




// BORRAR

void DadoAbbVacio_SiSePideBorrarUnElemento_SeDevuelveMenosUno(){

  int uno = 1; //Elemento de prueba
  //No encuentro necesario usar el arbol genérico para esta prueba.
  pa2m_afirmar( arbol_borrar(NULL, &uno) == FALLO , "No se puede borrar elemento de un arbol inexistente.");

  abb_t* abb = arbol_crear(comparador_de_enteros, NULL);
  pa2m_afirmar( arbol_borrar(NULL, &uno) == FALLO , "No se puede borrar elemento de un arbol sin elementos.");

  arbol_destruir(abb);
  printf("\n");

}



void DadoAbbConUnUnicoElemento_SiSeBorraEseElemento_ResultaEnUnAbbSinElementos(){

  abb_t* abb = arbol_crear(comparador_de_enteros, NULL);
  int uno = 1; //Elemento de prueba
  //No encuentro necesario usar el arbol genérico para esta prueba.
  arbol_insertar(abb, &uno);

  pa2m_afirmar( arbol_borrar(abb, &uno) == 0 , "Se borra elemento de un arbol con un elemento.");
  pa2m_afirmar( arbol_vacio(abb) == true , "El arbol sestá vacío tras borrar.");

  arbol_destruir(abb);

  printf("\n");

}



void DadoAbbConElementos_SiSePideBorrarElementoQueNoEstaEnElAbb_SeDevuelveMenosUno(){
 
  abb_t* abb = arbol_crear(comparador_de_enteros, NULL);
  int uno = 1 , dos = 2 , tres = 3; //Elementos de prueba
  //No encuentro necesario usar el arbol genérico para esta prueba.
  arbol_insertar(abb, &uno);
  arbol_insertar(abb, &dos);

  pa2m_afirmar( arbol_borrar(abb, &tres) == FALLO , "No se puede borrar un elemento que no pertenece a un arbol.");

  arbol_destruir(abb);

  printf("\n");

}




void DadoAbbConElementos_SiSeBorranElementosQueEstanEnElAbb_SeBorranCorrectamente(){
  // Verificación principal de comportamiento de borrado

  abb_t* abb = crear_abb_generico(NULL);

  nodo_abb_t* cero = abb->nodo_raiz->izquierda->izquierda->izquierda;
  nodo_abb_t* ocho = abb->nodo_raiz->derecha->derecha;
  nodo_abb_t* seis = abb->nodo_raiz->derecha->izquierda;
  nodo_abb_t* siete = abb->nodo_raiz->derecha;
  nodo_abb_t* tres = abb->nodo_raiz->izquierda;
  nodo_abb_t* cinco_de_raiz = abb->nodo_raiz;
  nodo_abb_t* cuatro = abb->nodo_raiz->izquierda->derecha;
  nodo_abb_t* uno = abb->nodo_raiz->izquierda->izquierda;
  nodo_abb_t* cinco_repetido = abb->nodo_raiz->izquierda->derecha->derecha;
  nodo_abb_t* nueve = abb->nodo_raiz->derecha->derecha->derecha;
  //VER: 'Seguimiento de pruebas de borrado' en sección aclaraciones, README.txt
  
  pa2m_afirmar( arbol_borrar(abb, cero->elemento) == 0 , "Se borra un elemento hoja de un arbol con elementos.");
  pa2m_afirmar( uno->izquierda == NULL , "Dicha hoja es reemplazada por un nodo NULL al borrar.");


  pa2m_afirmar( arbol_borrar(abb, ocho->elemento) == 0 , "Se borra un elemento que tenía un hijo.");
  pa2m_afirmar( siete->derecha == nueve , "Se llena el lugar del elemento borrado con el hijo que le quedaba al mismo.");


  pa2m_afirmar( arbol_borrar(abb, seis->elemento) == 0 , "Se borra otra hoja distinta.");
  pa2m_afirmar( siete->izquierda == NULL , "Dicha hoja es reemplazada por un nodo NULL al borrar.");


  pa2m_afirmar( arbol_borrar(abb, siete->elemento) == 0 , "Se borra el hijo derecho de la raíz (tenía un hijo).");
  pa2m_afirmar( cinco_de_raiz->derecha == nueve , "Se llena el lugar del elemento borrado con el hijo que le quedaba al mismo.");
  

  pa2m_afirmar( arbol_borrar(abb, ) == 0 , ".");


  pa2m_afirmar( arbol_borrar(abb, ) == 0 , ".");



  arbol_destruir(abb);
  printf("\n");

  printf("\n");

}


/*

//

void Dado_Si_X(){

  printf("\n");

}




void Dado_Si_X(){

  printf("\n");

}




void Dado_Si_X(){

  printf("\n");
}





void Dado_Si_X(){

  printf("\n");

}




void Dado_Si_X(){

  printf("\n");

}




void Dado_Si_X(){

  printf("\n");

}






void Dado_Si_X(){

  printf("\n");


}





void Dado_Si_X(){

  printf("\n");

}




// 



void Dado_Si_X(){

  printf("\n");

}




void Dado_Si_X(){

  printf("\n");

}





void Dado_Si_X(){

  printf("\n");

}




void Dado_Si_X(){

  printf("\n");

}





void Dado_Si_X(){

  printf("\n");

}




void Dado_Si_X(){

  printf("\n");

}





// 


void Dado_Si_X(){

  printf("\n");

}




void Dado_Si_X(){

  printf("\n");

}




void Dado_Si_X(){

  printf("\n");

}




void Dado_Si_X(){

  printf("\n");

}




void Dado_Si_X(){

  printf("\n");

}




void Dado_Si_X(){

  printf("\n");

}




// ITERADOR INTERNO


bool aumentar_entero(void* entero_a_sumar, void* aumento){



}



void Dado_Si_X(){
 
  printf("\n");

}





void Dado_Si_X(){
  
  printf("\n");

}





void Dado_Si_X(){
  
  printf("\n");

}


*/


int main() {
  
  // Ver detalles de nomenclatura en Aclaraciones, README.txt 

  pa2m_nuevo_grupo("Pruebas de creación de abb");

    DadoComparadorNull_SiSePideCrear_NoSeCreaYSeRetornaNull();
    DadoComparadorValido_SiSePideCrearConOSinDestructor_SeCreaCorrectamenteAbb(); // ConOSin ... == Con o sin ...

  pa2m_nuevo_grupo("Pruebas de inserción");

    DadoAbbInexistente_SiSeIntentaInsertarElemento_NoSePuedeInsertar();
    DadoAbbSinElementos_SiSeInsertaUnElemento_SeInsertaCorrectamenteYElementoInsertadoEsRaiz();
    DadoAbbSinElementos_SiSeInsertanVariosElementos_SeInsertanTodosYComoCorresponde();

  pa2m_nuevo_grupo("Pruebas de funciones de utilidad"); //Funciones de utilidad: 'arbol_raiz' y 'arbol_vacio'.

    DadoAbbSinElementosOInexistente_SiSePreguntaSiEstaVacio_SeDevuelveTrue(); //Remarco este como significado de vacío (detalles de nomenclatura, aclaraciones README).
    DadoAbbConUnElemento_SiSePreguntaSiEstaVacio_SeDevuelveFalse();

    DadoAbbVacio_SiSePideElementoRaiz_SeDevuelveNull();
    DadoAbbConElementos_SiSePideElementoRaiz_SeDevuelveEseElementoCorrectamente();

  pa2m_nuevo_grupo("Pruebas de busqueda");

    DadoAbbVacio_SiSePideBuscarUnElemento_SeDevuelveNull();
    DadoAbbConElementos_SiSeBuscanElementosQueEstanEnElAbb_SeDevuelvenCorrectamenteLosMismos();
    DadoAbbConElementos_SiSeBuscanElementosQueNoEstanEnElAbb_SeDevuelveNull();

  pa2m_nuevo_grupo("Pruebas de borrado");
    //Nota: Se reemplazan los elementos a borrar por su PREDECESOR inorden
    DadoAbbVacio_SiSePideBorrarUnElemento_SeDevuelveMenosUno();
    DadoAbbConUnUnicoElemento_SiSeBorraEseElemento_ResultaEnUnAbbSinElementos();
    DadoAbbConElementos_SiSePideBorrarElementoQueNoEstaEnElAbb_SeDevuelveMenosUno();
    DadoAbbConElementos_SiSeBorranElementosQueEstanEnElAbb_SeBorranCorrectamente();

  /*

  pa2m_nuevo_grupo("Pruebas de recorrido inorden");

    Dado_Si_X();

  pa2m_nuevo_grupo("Pruebas de recorrido preorden");
    
    Dado_Si_X();

  pa2m_nuevo_grupo("Pruebas de recorrido postorden");

    Dado_Si_X();

  pa2m_nuevo_grupo("Pruebas de iterador interno");
    
    Dado_Si_X();

  */

  return pa2m_mostrar_reporte();

}
