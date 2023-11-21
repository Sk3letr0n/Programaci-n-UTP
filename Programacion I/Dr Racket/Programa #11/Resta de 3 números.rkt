;Enunciado/Objetivo
;Construir un programa que calcule la resta de tres números
;
;Analisis semántico
;Resta = resultado de (c-d)-e
;
;Analisis EPS
;E: c d e
;P: 1. Lea c - 2. Lea d - 3. Lea e - 4. Calcule (c-d)-e
;S: Resta
;
;Código
(define (resta c d e)
  (-(- c d)e)
)
(define (interfaz c d e)
  (display "Ingrese el primer número ")
  (set! c (read))
  (newline)
  (display "Ingrese el segundo número ")
  (set! d (read))
  (newline)
  (display "Ingrese el tercer número ")
  (set! e (read))
  (newline)
  (display "La resta de los tres números es: ")
  (display (resta c d e))
)   