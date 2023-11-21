#| Enunciado/Objetivo:
Construir un programa que lea un número entero y muestre todos los enteros comprendidos entre 1 y el número leído

Análisis semántico:
Leer los números entre n y 1, ej: 7--> 1,2,3,4,5,6,7

Análisis EPS:
Entrada: n
Proceso: 1. Leer n - 2. Buscar los números comprendidos entre 1 y n
Salida: Números comprendidos
|#

(define (fx n)
  (display n)
  (display " ")
)

(define (ciclo1 n)
  (if (= n 1)
      (fx n)
      (begin
      (display n)
      (display " ")
      (ciclo1 (- n 1))
      )
  )
)
(define (ciclo2 n)
  (if (= n 1)
      (fx n)
      (begin
      (display n)
      (display " ")
      (ciclo2 (+ n 1))
      )
  )
)
(define (interfaz n)
  (display "Ingrese un número: ")
  (set! n(read))
  (if (> n 0)
  (ciclo1 n)
  (ciclo2 n)
  )
)
(interfaz 1)

  