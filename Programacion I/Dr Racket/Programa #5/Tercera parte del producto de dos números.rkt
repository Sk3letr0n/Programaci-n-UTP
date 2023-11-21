;Enunciado/Objetivo
;Construir un programa que lea dos números y muestre la tercera parte de su producto
;
;Análisis Semántico
;Resultado = d * s / 3
;
;Análisis EPS
;E: d s
;P: 1. Lea d - 2. Lea s - 2. Calcule d * s / 3
;S: Tercera
;
;Código
(define (tercera d s)
  (/ (* d s) 3)
)
(define (interfaz d s)
  (display "Ingrese el primer #: ")
  (set! d(read))
  (newline)
  (display "Ingrese el segundo #: ")
  (set! s(read))
  (newline)
  (display "La mitad de la suma de estos dos números es: ")
  (display (tercera d s))
)