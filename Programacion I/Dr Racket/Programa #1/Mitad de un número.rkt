;Enunciado/Objetivo
;Construir un programa que lea un número y muestre la mitad de este
;
;Análisis Semántico
;Mitad = n/2
;
;Análisis EPS
;E: n
;P: 1. Lea n - 2. Calcule n/2
;S: Mitad
;
;Código
(define (mitad n)
  (/ n 2 )
)
(define (interfaz n)
  (display "Ingrese el #: ")
  (set! n(read))
  (newline)
  (display "La mitad del número es: ")
  (display (mitad n))
)