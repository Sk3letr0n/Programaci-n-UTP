;Enunciado/Objetivo
;Construir un programa que lea 3 números enteros y calcule el promedio de los últimos dígitos de cada número
;
;Análisis Semántico
;523 = 3    25 = 5   1027 = 7
;3 + 5 + 7 / 3 = 5
;
;Análisis EPS
;E: a b c
;P: 1. Lea a - 2. Saquele el ultimo dígito - 3. Lea b - 4. Saquele el ultimo dígito - 5. Lea c - 6. Saquele el ultimo dígito - 7. Calcule ud1 + ud2 + ud3 / 3
;S: Promedio
;
;Código
(define (promedio a b c)
  (/ (+ (remainder a 10) (remainder b 10) (remainder c 10) ) 3)
)
(define (interfaz a b c)
  (display "Dígite el primer #: ")
  (set! a(read))
  (newline)
  (display "Dígite el segundo #: ")
  (set! b(read))
  (newline)
  (display "Dígite el tercer #: ")
  (set! c(read))
  (newline)
  (display "El promedio de los 3 ultimos digitos de cada número es: ")
  (display (promedio (abs a) (abs b) (abs c)))
)