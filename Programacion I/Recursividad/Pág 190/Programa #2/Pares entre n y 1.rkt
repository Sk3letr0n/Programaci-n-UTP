#| Enunciado/Objetivo:
Construir un programa que lea un número entero y muestre todos los pares comprendidos entre 1 y el número leído

Análisis semántico:
Leer los números pares entre n y 1, ej: 7--> 2, 4, 6

Análisis EPS:
Entrada: n
Proceso: 1. Leer n - 2. Buscar los números comprendidos entre 1 y n - 3. Sacar los números pares
Salida: Números comprendidos
|#
(define (fx1 n con)
  (if (> con n)
      (display " ")
      (begin
        (if (= (remainder con 2) 0)
            (display con)
            (display " ")
        )
        (fx1 n ( + con 1))
      )
  )
)
(define (fx2 n con)
  (if (< con n)
      (display " ")
      (begin
        (if (= (remainder con 2) 0)
            (display con)
            (display " ")
        )
        (fx2 n ( - con 1))
      )
  )
)
(define (interfaz n)
  (display "Ingrese un número: ")
  (set! n(read))
  (if (> n 0)
  (fx1 n 1)
  (fx2 n 1)
  )
)
(interfaz 1)
  
     
