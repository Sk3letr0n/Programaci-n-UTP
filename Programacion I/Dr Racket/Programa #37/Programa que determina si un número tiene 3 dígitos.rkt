#|Enunciado Objetivo
Construir un programa que lea un número entero y determine si tiene 3 dígitos

Análisis Semántico
546 = #t  -  69 = #f

Análisis EPS
E: n
P: 1. Leer n - 2. Determinar si tiene 3 dígitos
S: Resultado
|#
(define (dig n)
  (if (and (>= n 100) (< n 1000))
  (display "Su número tiene 3 dígitos")
  (display "Su número no tiene 3 dígitos")
  )
)
(display "Ingrese un número")
(newline)
(define (interfaz n)
  (dig n)
)
(interfaz (read))