#|Enunciado/Objetivo
Mostrar en pantalla todos los números terminados en 6 comprendidos entre 25 y 205.

Análisis Semántico
26 36 46 56 66 76 86 96 106...... 196

Análisis EPS
E:
P: 1. Calcule los números que terminan en 6 del 25 al 205 - 2. Mostrar los números que terminan en 6 del 25 al 205
S: los numeros que terminan en 6 del 25 al 205
|#

(define (mostrar n)
  (if (= n 205)
      (display " ")
      (begin
        (if (= (remainder n 10)6)
            (begin
              (display n)
              (display " ")
              (mostrar (+ n 1))
            )
            (mostrar (+ n 1))
        )
      )
  )
)

(define(interfaz)
  (display "Los números comprendidos que terminan en 6 del 25 al 205 son: ")
  (newline)
  (mostrar 25)
)
(interfaz)