▒▒▒▒▒▒▒▒▒▒▒▒  Introduccion teórica breve  ▒▒▒▒▒▒▒▒▒▒▒▒ 

    Arboles:
        Un arbol en general, al igual que la lista, es un contenedor
        de datos que tiene ciertas características.
        Entre ellas están:
         - Estan conformados por un conjunto de nodos, que son los
          contenedores de los elementos del arbol.
         - Dicho conjunto puede tener una raiz, que es cierto nodo
          específico del que se pueden generar sub-arboles. Se le toma entonces
          como el "padre principal" de todos los sub-arboles.
         - Se tiene entonces una relación de padres e hijos entre los nodos.
         - Por ende, a su vez, cada sub-arbol tiene una raiz, con lo cuál 
          cada nodo puede tener varios hijos (o ningúno).

    Arboles Binarios:
        Son arboles que cumplen ciertas características adicionales:
         - Cada nodo puede tener máximo dos hijos, uno izquierdo y otro derecho.
         - Más generalizado, esto equivale a decir que un arbol binario se puede bifurcar
          solamente en dos sub-arboles (que se pueden entonces identificar como 
          izquierdo o derecho). Cada sub-arbol cumple con lo anterior igualmente.
        Estos arboles buscan aproximar operaciones de busqueda de datos a una complejidad
        algoritmica similar a la de la busqueda binaria [ O(log(n)) ].
        Sin embargo, solo con las características dadas no alcanza para garantizar que 
        dicha aproximación se logre, ya que no posee un criterio general fijo para 
        comparar sus datos.
        Acá es cuando entra el siguiente tipo de arbol.
    
    Arboles Binarios de Busqueda (ABB):
        Son arboles binarios en los cuales:
         - Cada contenedor del arbol tiene una clave característica única.
         - Se tiene un comparador para dichas claves.
        Todo lo anterior concluye como resultado un criterio de comparación en el que:
        Dada una raíz, su sub-arbol izquierdo debe tener todas sus claves menores que la de ella
        misma, y su sub-arbol derecho debe tener todas sus claves mayores.
        Cada sub-arbol cumple con todo lo anterior.

        (NOTA: A pesar de tener establecido dicho criterio de comparación, no se garantiza tampoco
        que las operaciones de busqueda sean O(log(n)), ya que no tienen una forma de
        autobalancearse en caso en el que se inserten bastantes más elementos de un lado del
        arbol que del otro. Si el arbol degenera en una lista, por ejemplo, el recorrido del
        arbol desde la raíz hasta sus hojas puede llegar a ser O(n). Excluyendo casos de 
        dicho desbalance, los ABB cumplen su objetivo).

    Se deben distinguir los tipos de arboles, en especial los últimos dos explicados, porque si
    bien el ABB tiene todas las características de los Arboles Binarios, no se cumple lo recíproco
    y se tiene como diferencia principal el criterio operacional mencionado. Sin ese criterio
    se dificulta en gran medida la aproximación a la que se quiere llegar con la optimización de 
    operaciones de busqueda. 
        

    
▒▒▒▒▒▒▒▒▒▒▒▒  Explicación de implementación:  ▒▒▒▒▒▒▒▒▒▒▒▒ 

    Se omite:
        - Explicación de ciertas funciones o partes de las mismas que no la requieren.
        - Explicación de verificaciones visibles (de arboles/nodos inexistentes).

    ▒▒▒▒  abb.c  ▒▒▒▒

        ---  ---
            Se

        ---  ---
            Se

        ---  ---
            Se

        ---  ---
            Se

        ---  ---
            Se
        
        ---  ---
            Se

        ---  ---
            Se

        ---  ---
            Se

        
            

▒▒▒▒▒▒▒▒▒▒▒▒  Aclaraciones:  ▒▒▒▒▒▒▒▒▒▒▒▒ 

    ▒▒▒▒  Detalles de nomenclatura  ▒▒▒▒

        ARBOL INEXISTENTE hace referencia a un puntero a abb que apunta a NULL:
            (abb_t* abb == NULL)
        Un abb VACÍO puede referirse a:
            -Un abb INEXISTENTE.
            -Un abb EXISTENTE cuya raiz es NULL.
            Denomino a este último un "ABB SIN ELEMENTOS" a lo largo de las pruebas.


    ▒▒▒▒  Creación de arbol de enteros generalizado (ILUSTRACIÓN DEL RESULTADO DESEADO AL INSERTAR)  ▒▒▒▒

        (Notar que para elementos repetidos se toma como convención:
        elementos menores o iguales al actual van a su izquierda).
        En la prueba principal de inserción se insertan los elementos en el orden descripto para obtener como resultado lo siguiente:

                                ______(5)______
                               /               \
                           __(3)__           __(7)__
                          /       \         /       \
                     __(1)__      (4)     (6)       (8)
                    /       \        \                 \
                  (0)       (2)      (5)               (9)

        El orden tomado sirve para verificar comportamiento de inserción
        a izquierda o derecha según corresponda con lo explicado en la
        introducción teórica. Además se verifica comportamiento de inserción de un elemento repetido (el 5).

        EN GENERAL para el resto de las pruebas se usará este arbol
        como referencia a menos de que se indique lo contrario.
        Se almacenan punteros a enteros debido a que:
            -Se deben reservar en memoria dinámica ya que, como quiero
            generalizar su uso con una función, necesito que los
            elementos del arbol "sobrevivan" tras salir del ámbito
            de la misma. Esto además colabora a probar el
            destructor_de_prueba (que hace free de los elementos al destruir el arbol).
            -Son sencillos de pensar para hacer las comparaciones.


    ▒▒▒▒  Sobre  ▒▒▒▒

        


    ▒▒▒▒  Sobre  ▒▒▒▒

        


    ▒▒▒▒  Sobre  ▒▒▒▒

        


    ▒▒▒▒  Sobre  ▒▒▒▒

        


    ▒▒▒▒  Sobre  ▒▒▒▒
    
        






        