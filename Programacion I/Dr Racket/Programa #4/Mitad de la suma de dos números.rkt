;Enunciado/Objetivo
;Construir un programa que lea dos números y muestre la mitad de la suma de ambos
;
;Análisis Semántico
;Resultado = x + r / 2
;
;Análisis EPS
;E: x r
;P: 1. Lea x - 2. Lea r - 2. Calcule x + r / 2
;S: Mitad
;
;Código
(define (mitad x r)
  (/ (+ x r) 2)
)
(define (interfaz x r)
  (display "Ingrese el primer #: ")
  (set! x(read))
  (newline)
  (display "Ingrese el segundo #: ")
  (set! r(read))
  (newline)
  (display "La mitad de la suma de estos dos números es: ")
  (display (mitad x r))
)