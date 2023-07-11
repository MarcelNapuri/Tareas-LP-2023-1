%grafo
vecino(a,b).
vecino(a,c).
vecino(a,e).

vecino(b,c).

vecino(c,d).
vecino(c,e).

vecino(e,b).

vecino(f,b).
vecino(f,e).
vecino(f,g).

vecino(g,e).

vecino(h,g).
vecino(h,i).
vecino(h,j).

vecino(i,g).

vecino(j,g).
vecino(j,i).

%-------------------puedellegar--------------------------------
% la funcion puedellegar toma dos nodos X e Y , devuelve true si existe
% un camino desde X hasta Y, retorna false en caso contrario

puedellegar(X, Y) :-
    setof(Ruta,camino(X, Y, [], Ruta),ListaCaminos),
    member(Ruta,ListaCaminos).

% camino es una funcion auxiliar para la busqueda de camino
% La primera cláusula se ejecuta cuando los nodos X e Y son vecinos directos
% [X|Visitados] representa el camino desde X hasta Y, donde Y es el nodo objetivo.

camino(X, Y,Visitados,[X|Visitados]) :-
    vecino(X, Y).

%La segunda clausula se busca un vecino M de X que no haya sido visitado
% anteriormente, es decir, que no esté en la lista Visitados,luego, se
% realiza una llamada recursiva a camino con M como nuevo X y se agrega
% M a la lista Visitados.

camino(X, Y, Visitados,Camino) :-
   vecino(X, M),
   \+ member(M, Visitados),
   camino(M, Y, [M | Visitados],Camino).


%------------------vecinos----------------------------------
% la funcion vecinos(X, L) toma un nodo X del grafo y L, siendo una
% lista con todos los vecinos del nodo X, devolvera true si la lista es
% correcta y false en caso contrario
vecinos(X, L) :- setof(Y, vecino(X, Y), Vecinos),
    permutation(L,Vecinos).

%------------------caminovalido-----------------------------
% caminovalido verificar si una lista dada representa un camino válido
% en un grafo
%
% caminovalido([]), establece que una lista vacía es considerada un camino válido.
caminovalido([]).

% caminovalido([_]), establece que una lista con un solo elemento es considerada un camino válido.
caminovalido([_]).

% caminovalido([X,Y|Resto]) Verifica si el primer nodo X y el segundo
% nodo Y son vecinos. Si lo son vecinos, se llama recursivamente a la
% funcion con el resto de la lista [Y|Resto]
caminovalido([X,Y|Resto]) :- vecino(X, Y), caminovalido([Y|Resto]).



%------------------caminomascorto-------------------------------
%caminomascorto(X, Y, L) es una funcion tal que X e Y sean nodos en el
% grafo y L sea la lista de nodos que forma el camino mas corto desde X hasta Y.
% llama a una funcion auxiliar bfs para la ejecucion,toma una lista de
% caminos [[Nodo|Camino]|Cola], donde Nodo es el nodo actual y Camino es
% la lista de nodos visitados hasta ese momento. Cola es una cola de
% caminos pendientes de exploración.
caminomascorto(X, Y, L) :-
    bfs([[X]], Y, CaminoReverso),
    reverse(CaminoReverso, L).

% la primera clausula se ejecuta cuando se encuentra un camino que llega
% al nodo destino
bfs([[Nodo|Camino]|_], Nodo, [Nodo|Camino]).

% genera la lista NuevosCaminos de todas las extensiones posibles del
% camino,Cada extensión es una lista [Vecino, Nodo|Camino] donde Vecino
% es un vecino no visitado de Nodo y se agrega a Camino.Luego, se agrega
% NuevosCaminos a la Cola utilizando append/3 para continuar la exploración.
bfs([[Nodo|Camino]|Cola], Destino, Resultado) :-
    findall([Vecino, Nodo|Camino],
            (vecino(Nodo, Vecino),
             \+ member(Vecino, [Nodo|Camino])),
            NuevosCaminos),
    append(Cola, NuevosCaminos, NuevaCola),
    bfs(NuevaCola, Destino, Resultado).

% ejecuta cuando el primer camino en la cola no llega al destino, lo cual indica
% que no se ha encontrado un camino válido
bfs([_|Cola], Destino, Resultado) :-
    bfs(Cola, Destino, Resultado).

