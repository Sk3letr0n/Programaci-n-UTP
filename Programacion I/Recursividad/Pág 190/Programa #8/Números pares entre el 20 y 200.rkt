#|Enunciado/Objetivo
Mostrar en pantalla todos los pares comprendidos entre 20 y 200.

Análisis Semántico
20 22 24 26 28 30..... 124 126 128 130.....190 192 194 196 198 200

Análisis EPS
E:
P: 1. Calcule los pares del 20 al 200 - 2. Mostrar los pares del 20 al 200
S: Pares entre 20 y 200
|#

(define(mostrar n)
  (if (= n 200)
      (display n)
      (begin
        (display n)
        (display " ")
        (mostrar (+ n 2))
      )
  )
)
(define (interfaz)
  (display "Los numeros pares comprendidos del 20 al 200 son: ")
  (newline)
  (mostrar 20)
)
(interfaz)