;Enunciado/Objetivo
;Construir un programa que lea un número de dos dígitos y muestre la suma de los dos dígitos
;
;Análisis Semántico
;45 = 4 + 5 = 9
;
;Análisis EPS
;E: n
;P: 1. Lea n - 2. Saquele los dos dígitos por separado a n - 3. Calcule ud + pud
;S: Suma
;
;Código
(define (suma n)
  (+ (remainder n 10) (remainder (quotient n 10) 10))
)
(define (interfaz n)
  (display "Dígite el #: ")
  (set! n(read))
  (newline)
  (display "La suma de los dos dígitos de su # es: ")
  (display (suma (abs n)))
)