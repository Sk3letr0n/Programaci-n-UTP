;Enunciado/Objetivo
;Construir un programa que calcule la tercera parte de un número
;
;Analisis semántico
;Tercera= resultado de n/3
;
;Analisis EPS
;E: n
;P: 1. Lea n - 2. Calcule n/3
;S: Tercera
;
;Código
(define (tercera n)
  (/ n 3)
)
(define (interfaz n)
  (display "Ingrese un número ")
  (set! n (read))
  (newline)
  (display "La tercera parte de ese número es: ")
  (display (tercera n))
)   