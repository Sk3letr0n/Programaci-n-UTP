;Enunciado/Objetivo
;Construir un programa que lea un número de 3 dígitos y muestre la suma de la multiplicación del pud y apud con la multiplicación del pud y ud
;
;Análisis Semántico
;341 (4 * 3) + (4 * 1) = 16
;
;Análisis EPS
;E: n
;P: 1. Lea n - 2. Saquele los tres dígitos por separado a n - 3. Calcule (pud * apud) + (pud * ud)
;S: Suma
;
;Código
(define (resultado n)
  (+(* (remainder (quotient n 10) 10) (remainder n 10)) (* (remainder (quotient n 10) 10) (remainder (quotient (quotient n 10) 10)10) ))
)
(define (interfaz n)
  (display "Dígite el #: ")
  (set! n(read))
  (newline)
  (display "La semisuma de los dos dígitos de su # es: ")
  (display (resultado (abs n)))
)