;Enunciado/Objetivo
;Construir un programa que calcule la potencia del primer número elevado al segundo
;
;Analisis semántico
;Potencia = resultado de a^b
;
;Analisis EPS
;E: a b
;P: 1. Lea a - 2. Lea b - 3. Calcule a^ b
;S: potencia
;
;Código
(define (potencia a b)
  (expt a b)
)
(define (interfaz a b)
  (display "Ingrese el primer número ")
  (set! a (read))
  (newline)
  (display "Ingrese el segundo número ")
  (set! b (read))
  (newline)
  (display "La potencia del primer número elevado al segundo es: ")
  (display (potencia a b))
)   