#|Enunciado/Objetivo
Mostrar en pantalla todos los enteros comprendidos entre 1 y 100.

Análisis Semántico
1 2 3 4 5 6 7 8...... 34 35 36 37......96 97 98 100

Análisis EPS
E: 
P:1. Calcula los números enteros comprendidos del 1 al 100 - 2. Mostrar los números enteros comprendidos del 1 al 100
S: Los números enteros comprendidos del 1 al 100
|#

(define (mostrar n)
  (if (= n 100)
      (display n)
      (begin
        (display n)
        (display " ")
        (mostrar (+ n 1))
      )
   )
)

(define (interfaz)
  (display "Los numeros enteros comprendidos del 1 hasta el 100 son: ")
  (newline)
  (mostrar 1)
)
(interfaz)

