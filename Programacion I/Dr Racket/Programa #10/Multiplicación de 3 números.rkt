;Enunciado/Objetivo
;Construir un programa que calcule la multiplicación de tres números
;
;Analisis semántico
;Resta = resultado de r*s*t
;
;Analisis EPS
;E: r s t
;P: 1. Lea r - 2. Lea s - 3. Lea t - 4. Calcule r*s*t
;S: Multiplicación
;
;Código
(define (multiplicación r s t)
  (* r s t)
)
(define (interfaz r s t)
  (display "Ingrese el primer número ")
  (set! r (read))
  (newline)
  (display "Ingrese el segundo número ")
  (set! s (read))
  (newline)
  (display "Ingrese el tercer número ")
  (set! t (read))
  (newline)
  (display "La multiplicación de los tres números es: ")
  (display (multiplicación r s t))
)   