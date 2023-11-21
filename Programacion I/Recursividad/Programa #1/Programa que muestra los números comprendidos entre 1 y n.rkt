#| Enunciado/Objetivo:
Construir un programa que lea un número entero y muestre todos los enteros comprendidos entre 1 y el número leído

Análisis semántico:
Leer los números entre n y 1, ej: 7--> 1,2,3,4,5,6,7

Análisis EPS:
Entrada: n
Proceso: 1. Leer n - 2. Buscar los números comprendidos entre 1 y n
Salida: Números comprendidos
|#
;Código
(define (fx n)
  (display n)
  (display " ")
)

(define (ciclo n)
  (if (or (> n 0) (= n 1))
      (begin
        (fx n)
        (ciclo (- n 1))
      )
      (display "")
  )
)
(define (interfaz n)
  (display "Ingrese un número: ")
  (set! n(read))
  (ciclo n)
)
(interfaz 1)

  