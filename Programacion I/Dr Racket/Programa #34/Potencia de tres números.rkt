;Enunciado/Objetivo
;Construir un programa que lea 3 números enteros y asuma que el primero es el a, el segundo b y el tercero c para poder calcular la potencia de (a^b)^c
;
;Análisis Semántico
;3 = a    4 = b   2 = c
;(3^4)^2 = 6561
;
;Análisis EPS
;E: a b c
;P: 1. Lea a - 2. Lea b - 3. Lea c - Calcule (a^b)^c
;S: Potencia
;
;Código
(define (potencia a b c)
  (expt (expt a b) c)
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
  (display "La potencia de estos tres # es: ")
  (display (potencia (abs a) (abs b) (abs c)))
)