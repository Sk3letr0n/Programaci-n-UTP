;Enunciado/Objetivo
;Construir un programa que lea un número de 2 dígitos y muestre la semisuma de estos
;
;Análisis Semántico
;82 = 8 + 2 / 2 = 5
;
;Análisis EPS
;E: n
;P: 1. Lea n - 2. Saquele los dos dígitos por separado a n - 3. Calcule ud + pud / 2
;S: Suma
;
;Código
(define (semisuma n)
  (/(+ (remainder n 10) (remainder (quotient n 10) 10)) 2)
)
(define (interfaz n)
  (display "Dígite el #: ")
  (set! n(read))
  (newline)
  (display "La semisuma de los dos dígitos de su # es: ")
  (display (semisuma (abs n)))
)