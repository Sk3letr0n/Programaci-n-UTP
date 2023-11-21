;Enunciado/Objetivo
;Construir un programa que lea un número entero de tres dígitos y muestre la suma de estos tres dígitos
;
;Análisis Semántico
;392 = 3 + 9 + 2 = 14
;
;Análisis EPS
;E: n
;P: 1. Lea n - 2. Saquele los tres dígitos por separado a n - 3. Calcule ud + pud + apud
;S: Suma
;
;Código
(define (suma n)
  (+ (remainder n 10) (remainder (quotient n 10) 10) (remainder (quotient (quotient n 10) 10) 10) )
)
(define (interfaz n)
  (display "Dígite el #: ")
  (set! n(read))
  (newline)
  (display "La suma de los tres dígitos de su # es: ")
  (display (suma (abs n)))
)