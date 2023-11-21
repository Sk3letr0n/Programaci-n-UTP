;Enunciado/Objetivo
;Construir un programa que calcule la suma de los números comprendidos entre 1 y 10
;
;Analisis semántico
;Suma= resultado 2+3+4+5+6+7+8+9
;
;Analisis EPS
;E: n
;P: 1. Lea n - 2. Calcule 2+3+4+5+6+7+8+9
;S: Suma
;
;Código
(define (suma n)
  (+ 2 3 4 5 6 7 8 9)
)
(define (interfaz n)
  (display "Inserte el valor nulo ")
  (set! n(read))
  (newline)
  (display "La suma de los números comprendidos entre 1 y 10 es: ")
  (display (suma n))
)