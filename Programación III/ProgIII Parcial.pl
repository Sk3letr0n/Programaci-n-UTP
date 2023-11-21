% Hecho por: Steven Grisales López, Luis Felipe Garzón Bonilla y Santiago Aristizabal Sepúlveda.

% Definición de un segmento
segmento(punto(X1,Y1),punto(X2,Y2)). 

% Regla para determinar si un segmento es horizontal
horizontal(segmento(punto(X1, Y), punto(X2, Y))) :-
    X1 \= X2, !.

% Regla para determinar si un segmento es vertical
vertical(segmento(punto(X, Y1), punto(X, Y2))) :-
    Y1 \= Y2, !.

% Regla para determinar si un conjunto de segmentos forman un polígono cerrado
poligono_cerrado(Segmentos) :-
    last(Segmentos, segmento(punto(_,Y), punto(X1,Y))),
    nth0(0, Segmentos, segmento(punto(X2,Y), _)),
    X1 =:= X2.

% Regla para determinar si un conjunto de segmentos es un triángulo
triangulo(Segmentos) :-
    length(Segmentos, 3),
    poligono_cerrado(Segmentos).

% Regla para determinar si un conjunto de segmentos es un cuadrado
cuadrado(Segmentos) :-
    length(Segmentos, 4),
    poligono_cerrado(Segmentos),
    member(segmento(punto(X,Y), punto(X1,Y)), Segmentos),
    member(segmento(punto(X1,Y), punto(X1,Y1)), Segmentos),
    member(segmento(punto(X1,Y1), punto(X,Y1)), Segmentos),
    member(segmento(punto(X,Y1), punto(X,Y)), Segmentos), !.

% Regla para determinar si un conjunto de segmentos es un rectángulo
rectangulo(Segmentos) :-
    length(Segmentos, 4),
    poligono_cerrado(Segmentos),
    member(segmento(punto(X,Y), punto(X1,Y)), Segmentos),
    member(segmento(punto(X1,Y), punto(X1,Y1)), Segmentos),
    member(segmento(punto(X1,Y1), punto(X,Y1)), Segmentos),
    member(segmento(punto(X,Y1), punto(X,Y)), Segmentos),
    ((horizontal(segmento(punto(X,Y), punto(X1,Y))),
    vertical(segmento(punto(X1,Y), punto(X1,Y1))));
    (horizontal(segmento(punto(X1,Y), punto(X,Y1))),
    vertical(segmento(punto(X,Y1), punto(X,Y))))), !.



/* Consultas:
triangulo([segmento(punto(1,1), punto(2,2)), segmento(punto(2,2), punto(3,1)), segmento(punto(3,1), punto(1,1))]).

cuadrado([segmento(punto(1,1), punto(1,2)), segmento(punto(1,2), punto(2,2)), segmento(punto(2,2), punto(2,1)), segmento(punto(2,1), punto(1,1))]).

rectangulo([segmento(punto(1,1), punto(1,3)), segmento(punto(1,3), punto(3,3)), segmento(punto(3,3), punto(3,1)), segmento(punto(3,1), punto(1,1))]).
*/