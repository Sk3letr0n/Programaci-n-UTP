;Enunciado/Objetivo
;Construir un programa que calcule la potencia de un número elevado a si mismo
;
;Analisis semántico
;Potencia = resultado n^n
;
;Analisis EPS
;E: n
;P: 1. Lea n - 2. Calcule n^n
;S: Potencia
;
;Código
(define (potencia n)
  (expt n n)
)
(define (interfaz n)
  (display "Inserte su número ")
  (set! n(read))
  (newline)
  (display "La potencia de ese número elevado a si mismo es: ")
  (display (potencia n))
)