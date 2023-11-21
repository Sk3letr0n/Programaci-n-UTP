#|Enunciado Objetivo
Construir un programa que lea un número entero y determine si es negativo

Análisis Semántico
-43 = #t  -  2 = #f

Análisis EPS
E: n
P: 1. Leer n - 2. Determinar si es negativo
S: Resultado
|#
(define (neg n)
  (if (< n 0)
  (display "Su número es negativo")
  (display "Su número no es negativo")
  )
)
(display "Ingrese un número")
(newline)
(define (interfaz n)
  (neg n)
)
(interfaz (read))