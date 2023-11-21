;Enunciado/Objetivo
;Construir un programa que lea 4 números enteros y muestre la suma de los penúltimos dígitos de cada número
;
;Análisis Semántico
;741 = 4    1206 = 0  539 = 3   4395 = 9 
;4 + 0 + 3 + 9 = 16
;
;Análisis EPS
;E: n m p o
;P: 1. Lea n - 2. Saquele el penúltimo dígito - 3. Lea m - 4. Saquele el penúltimo dígito - 5. Lea p - 6. Saquele el penúltimo dígito - 7. Lea o - 8. Saquele el penúltimo dígito - 9. Calcule pud1 + pud2 + pud3 + pud4
;S: Suma
;
;Código
(define (suma n m p o)
  (+ (remainder (quotient n 10) 10) (remainder (quotient m 10) 10) (remainder (quotient p 10) 10) (remainder (quotient o 10) 10) )
)
(define (interfaz n m p o)
  (display "Dígite el primer #: ")
  (set! m(read))
  (newline)
  (display "Dígite el segundo #: ")
  (set! n(read))
  (newline)
  (display "Dígite el tercer #: ")
  (set! p(read))
  (newline)
  (display "Dígite el cuarto #: ")
  (set! o(read))
  (newline)
  (display "La suma de los penúltimos dígitos de estos cuatro # es: ")
  (display (suma (abs n) (abs m) (abs p) (abs o)))
)