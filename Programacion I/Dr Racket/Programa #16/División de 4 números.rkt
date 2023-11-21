;Enunciado/Objetivo
;Construir un programa que calcule la división de cuatro números
;
;Analisis semántico
;División = resultado de q/w/p/u
;
;Analisis EPS
;E: q w p u
;P: 1. Lea q - 2. Lea w - 3. Lea p - 4. Lea u - 5. Calcule q/w/p/u
;S: División
;
;Código
(define (división q w p u)
  ( / (/ (/ q w) p) u)
)
(define (interfaz q w p u)
  (display "Ingrese el primer número ")
  (set! q (read))
  (newline)
  (display "Ingrese el segundo número ")
  (set! w (read))
  (newline)
  (display "Ingrese el tercer número ")
  (set! p (read))
  (newline)
  (display "Ingrese el cuarto número ")
  (set! u (read))
  (newline)
  (display "La división de los cuatro números es: ")
  (display (división q w p u))
)   