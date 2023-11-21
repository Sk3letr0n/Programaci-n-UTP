;Enunciado/Objetivo
;Construir un programa que lea dos números y muestre el valor de restarle el 2do al 1ro
;
;Análisis Semántico
;Resta= n1 - n2
;
;Análisis EPS
;E: n1 n2
;P: 1. Lea n1 - 2. Lea n2 - 2. Calcule n1 - n2
;S: Resta
;
;Código
(define (resta n1 n2)
  (- n1 n2 )
)
(define (interfaz n1 n2)
  (display "Ingrese el primer #: ")
  (set! n1(read))
  (newline)
  (display "Ingrese el segundo #: ")
  (set! n2(read))
  (newline)
  (display "El valor de restarle el segundo número al primero es: ")
  (display (resta n1 n2))
)