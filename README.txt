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

        --- arbol_insertar ---
            Como la reserva de memoria del nodo nuevo puede fallar,
            utilizo una variable auxiliar 'raiz_tras_insercion' que
            me guarde el arbol modificado, o NULL si llegó a
            fallar.
            En 'insercion_de_nodo' me muevo recursivamente en el
            arbol por medio de los nodos y el comparador.
            En el caso en el que se tenía un arbol sin elementos,
            lo que hace es simplemente guardar el elemento en un 
            nodo nuevo y ese va a ser el nodo_raiz.
            Siempre que se sale de las comparaciones se devuelve
            el nodo_actual para que el resto del "camino" del arbol que
            se recorrió hasta llegar a donde se insertó algo se pueda
            "reconstruir" tal y como estaba.

        --- arbol_borrar ---
            Al contrario de la inserción, acá no me basta con verificar
            que lo devuelto por borrador_de_nodo sea distinto de NULL
            para decir que se pudo borrar lo pedido (ya que, si por 
            ejemplo se borra la raíz, el que tenga ahora una raíz 
            NULL no representa un fallo, sino un resultado correcto).
            Entonces se tiene 'se_pudo_borrar' como auxiliar para eso.
            La comparación para seguir el recorrido es igual a la de 
            insertar.
            En 'borrador_de_nodo' puedo asegurar que falló el borrado 
            si en algun llamado recursivo el nodo_actual ya no existe,
            porque eso quiere decir que, siguiendo el camino por donde
            debería estar el elemento a borrar, se llegó al hijo de 
            una hoja (o sea NULL), con lo cual ese elemento no existe
            dentro del arbol.
            Cuando se encuentra al elemento a borrar, se usa 
            'extraccion_de_predecesor', que va del todo a la derecha
            de un nodo,y el último derecho que haya lo saca.
            Por ende se le pasa el nodo izquierdo de la
            raíz, y así encuentra el predecesor inorden.
            Ese predecesor a lo sumo puede tener hijo izquierdo
            (ya que, precisamente, es el más derecho que había en 
            ese sub-arbol), pero si no lo tenía entonces ese
            supuesto hijo izquierdo va a ser NULL.
            Esta es razón por la cual el predecesor se guarda en
            un puntero auxiliar que se tenga por parámetro, porque
            quiero devolver el supuesto posible_hijo_izquierdo y 
            así tener "reconstruido" el camino que tuve que recorrer
            hasta el predecesor, pero efectivamente sacandolo de donde
            estaba dejando todos los punteros en su lugar.
            

        --- arbol_buscar ---
            Se

        --- arbol_recorrido_inorden ---
            Se

        --- arbol_recorrido_preorden ---
            Se
        
        --- arbol_recorrido_postorden ---
            Se

        --- abb_con_cada_elemento (inorden) ---
            Se

        --- abb_con_cada_elemento (preorden) ---
            Se

        --- abb_con_cada_elemento (preorden) ---
            Se


        
            

▒▒▒▒▒▒▒▒▒▒▒▒  Aclaraciones:  ▒▒▒▒▒▒▒▒▒▒▒▒ 

    ▒▒▒▒  Detalles de nomenclatura  ▒▒▒▒

        ARBOL INEXISTENTE hace referencia a un puntero a abb que apunta a NULL:
            (abb_t* abb == NULL)
        Un abb VACÍO puede referirse a:
            -Un abb INEXISTENTE.
            -Un abb EXISTENTE cuya raiz es NULL.
            Denomino a este último un "ABB SIN ELEMENTOS" a lo largo de las pruebas. Es un ABB que fue creado, pero que precisamente
            no tiene ningun elemento guardado.

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
                  (0)       (2)      (5*)              (9)

        (Orden de inserción en el arbol: 5,3,7,6,8,9,4,1,2,0,5).
        El orden tomado sirve para verificar comportamiento de inserción
        a izquierda o derecha según corresponda con lo explicado en la
        introducción teórica. Además se verifica comportamiento de inserción de un elemento repetido (el 5*).

        EN GENERAL para el resto de las pruebas se usará este arbol
        como referencia a menos de que se indique lo contrario.
        Se almacenan punteros a enteros debido a que:
            -Se deben reservar en memoria dinámica ya que, como quiero
            generalizar su uso con una función, necesito que los
            elementos del arbol "sobrevivan" tras salir del ámbito
            de la misma. Esto además colabora a probar el
            destructor_de_prueba (que hace free de los elementos al destruir el arbol).
            -Son sencillos de pensar para hacer las comparaciones.


    ▒▒▒▒  Sobre los elementos pasados por parametro por el usuario.  ▒▒▒▒

        Los datos que el usuario almacene se asumen como su responsabilidad, y en ningún momento se verifica el elemento
        que requiera insertar.
        Esto conlleva a que la destrucción de elementos depende
        exclusivamente de si el usuario brinda un destructor o no.
        En caso de brindarlo, tampoco se hacen verificaciones sobre
        dicha función y simplemente se aplica a cada elemento al
        necesitar borrarlo, o al destruir el arbol.


    ▒▒▒▒  Seguimiento de pruebas de borrado  ▒▒▒▒

        Se ilustra paso a paso los borrados realizados con su
        resultado esperado (empezando con el arbol genérico).
        (NOTA: Este es el resultado esperado, NO es el funcionamiento
        de la implementación realizada. Esto es únicamente para hacer
        un seguimiento "a ciegas", como si no se conociera la implementación).

                                ______(5)______
                               /               \
                           __(3)__           __(7)__
                          /       \         /       \
                     __(1)__      (4)     (6)       (8)
                    /       \        \                 \
                  (0)       (2)      (5*)              (9)

                Se borra el 0
                                ______(5)______
                               /               \
                           __(3)__           __(7)__
                          /       \         /       \
                       (1)__      (4)     (6)       (8)
                            \        \                 \
                            (2)      (5*)              (9)

                Se borra el 8 [Se 'agarra' al hijo del 8 como hijo
                del 7 y se elimina el 8]
                                ______(5)______
                               /               \
                           __(3)__           __(7)__
                          /       \         /       \
                       (1)__      (4)     (6)       (9)
                            \        \                 
                            (2)      (5*)               

                Se borra el 6
                                ______(5)______
                               /               \
                           __(3)__             (7)__
                          /       \                 \
                       (1)__      (4)               (9)
                            \        \                 
                            (2)      (5*)               

                Se borra el 7 [Igual que el 8]
                                ______(5)______
                               /               \
                           __(3)__             (9)
                          /       \                 
                       (1)__      (4)               
                            \        \                 
                            (2)      (5*)               
                
                Se borra el 3 [Se busca el predecesor inorden del 3,
                que es el 2. Se intercambian entre sí y se borra el 3].
                                ______(5)______
                               /               \
                           __(2)__             (9)
                          /       \                 
                       (1)        (4)               
                                     \                 
                                     (5*)             

                Se borra el 5 raíz [Su predecesor es el 5 repetido, se 
                intercambian y se borra el 5 que queda abajo (ex-raíz)].
                                ______(5*)______
                               /                \
                           __(2)__              (9)
                          /       \                 
                       (1)        (4)
                
                Se borra el 4
                                ______(5*)______
                               /                \
                           __(2)                (9)
                          /                       
                       (1)      

                Se borra el 5*:
                Su predecesor es el 2, entonces:
                    a) Se intercambian entre sí.
                
                                ______(2)______
                               /               \
                           __(5*)              (9)
                          /                       
                       (1)        
                                                     
                    b) Se vuelve al caso en el que se quiere borrar
                    un elemento con un hijo. Se 'agarra' al hijo del 5*
                    como hijo del 2 y se borra el 5*.

                                ______(2)______
                               /               \
                             (1)               (9)
                                               

    ▒▒▒▒  Resultado esperado de iterador interno para distintos recorridos  ▒▒▒▒

        SOBRE PRUEBAS DE ITERADOR SIN CORTE:
        
        Como la funcion NO se corta, entonces todos los elementos del
        arbol genérico deberían verse modificados, sin importar qué
        recorrido se tome.
        Teniendo en cuenta esto, en una misma prueba se hace la
        verificación de modificación total para los 3 recorridos.
        Los resultados tras aplicar la verificación sobre los 3 
        recorridos son los siguientes: (en este mismo orden se aplican
        en pruebas.c)

                        ______(5)______
                       /               \
                   __(3)__           __(7)__
                  /       \         /       \
             __(1)__      (4)     (6)       (8)
            /       \        \                 \
          (0)       (2)      (5*)              (9)

                                |
                                | Se aplica Iter. Inorden
                                |

                        ______(4)______
                       /               \
                   __(2)__           __(6)__
                  /       \         /       \
             __(0)__      (3)     (5)       (7)
            /       \        \                 \
          (-1)      (1)      (4*)              (8)

                                |
                                | Se aplica Iter. Preorden
                                |

                        ______(3)______
                       /               \
                   __(1)__           __(5)__
                  /       \         /       \
             __(-1)__     (2)     (4)       (6)
            /        \       \                 \
          (-2)      (0)      (3*)              (7)

                                |
                                | Se aplica Iter. Postorden
                                |

                        ______(2)______
                       /               \
                   __(0)__           __(4)__
                  /       \         /       \
             __(-2)__     (1)     (3)       (5)
            /        \       \                 \
          (-3)      (-1)     (2*)              (6)


        SOBRE PRUEBAS DE ITERADOR CON CORTE:

        NOTA: Para evitar conflicto con el elemento repetido tras
        hacer las modificaciones, se borra el mismo antes de
        realizar pruebas sobre el arbol.
        (Por ejemplo: mi función a aplicar le resta uno a todos los
        elementos hasta toparse con el numero 4. Si dejamos el
        elemento repetido (5*), al restarle uno a la raíz en el recorrido
        PREORDEN se obtiene que ahora la raíz es 4, pero a su izquierda
        ahora hay un 5, por lo cual, tras restar, el arbol dejaría de
        ser un ABB (porque se rompe la convención explicada en 
        la intro teórica)!!!
        Esto se puede evitar, por ejemplo, con alguna estructura aparte 
        que almacenara elementos y claves distinguidas, pero como esto
        es una solución a un problema del usuario, se omitirá y 
        simplemente decido eliminar el elemento repetido (5*)).
        
        Por medio del corte se verifican dos cosas:
            1) Que la cantidad de elementos que se modificaron es la adecuada.
            2) Que los elementos modificados antes del corte son los
            correspondientes al recorrido que corresponde.
        El corte se genera al encontrarse con el numero 4 (recién
        después de aplicarle la función al mismo. Es decir, se aplican
        hasta el 4 inclusive), entonces los resultados esperados para
        los distintos recorridos son:

        Iterador interno INORDEN:
            -  Deberían modificarse solo 5 elementos.
            -  0, 1, 2, 3, 4  pasan a ser ----->  -1, 0, 1, 2, 3

                   ___(5)__                            ___(5)__
                  /       (...)                       /       (...)
               _(3)_                                _(2)_
              /     \             ----->           /     \
           _(1)_    (4)                         _(0)_    (3)
          /     \                              /     \        
        (0)     (2)                         (-1)     (1)       
        
        Iterador interno PREORDEN:
            -  Deberían modificarse solo 6 elementos.
            -  5, 3, 1, 0, 2, 4  pasan a ser ----->  4, 2, 0, -1, 1, 3

                   ___(5)__                            ___(4)__
                  /       (...)                       /       (...)
               _(3)_                                _(2)_
              /     \             ----->           /     \
           _(1)_    (4)                         _(0)_    (4)
          /     \                              /     \        
        (0)     (2)                         (-1)     (1)       
    
        Iterador interno POSTORDEN:
            -  Deberían modificarse solo 4 elementos.
            -  0, 2, 1, 4  pasan a ser ----->  -1, 1, 0, 3

                   ___(5)__                            ___(5)__
                  /       (...)                       /       (...)
               _(3)_                                _(3)_
              /     \             ----->           /     \
          _(1)_     (4)                         _(0)_    (3)
         /     \                               /     \        
       (0)     (2)                          (-1)     (1)


        (Nota extra a la implementación del corte: Al principio
        llegué a pensar mal el corte creyendo que NO había que
        aplicar la función cuando se llegaba al elemento de corte.
        Me dí cuenta de que era hasta el elemento de corte INCLUSIVE
        recién despues de probar con Chanutrón una vez, y tras eso
        fijandome bien en el ejemplo del minidemo).