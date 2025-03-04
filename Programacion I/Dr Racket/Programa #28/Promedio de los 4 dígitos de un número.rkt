;Enunciado/Objetivo
;Construir un programa que lea un número entero de cuatro dígitos y calcule el promedio de estos 4 dígitos
;
;Análisis Semántico
;9757 = 9 + 7 + 5 + 7 / 4 = 7
;
;Análisis EPS
;E: n
;P: 1. Lea n - 2. Saquele los cuatro dígitos por separado a n - 3. Calcule ud + pud + apud + traspud/ 4
;S: Promedio
;
;Código
(define (promedio n)
  (/(+ (remainder n 10) (remainder (quotient n 10) 10) (remainder (quotient (quotient n 10) 10) 10) (remainder (quotient (quotient (quotient n 10) 10) 10) 10))4)
)
(define (interfaz n)
  (display "Dígite el #: ")
  (set! n(read))
  (newline)
  (display "La suma de los cuatro dígitos de su # es: ")
  (display (promedio (abs n)))
)