;Enunciado/Objetivo
;Construir un programa que calcule la tabla de multiplicar del 3
;
;Analisis semántico
;Tabla de multiplicar = resultado 3*1, 3*2... 3*10
;
;Analisis EPS
;E: 3
;P: 1. Lea  - 2. Calcule 3*1, 3*2... 3*10
;S: Tabla
;
;Código
(define (tabla1)
  (* 3 1)
)
(define (tabla2)
  (* 3 2)
)
(define (tabla3)
  (* 3 3)
)
(define (tabla4)
  (* 3 4)
)
(define (tabla5)
  (* 3 5)
)
(define (tabla6)
  (* 3 6)
)
(define (tabla7)
  (* 3 7)
)
(define (tabla8)
  (* 3 8)
)
(define (tabla9)
  (* 3 9)
)
(define (tabla10)
  (* 3 10)
)
(define (interfaz)
  (newline)
  (display "La tabla de multiplicación del 3 es: ")
  (newline)
  (display 3) (display " * 1 = ") (display (tabla1)) (newline)
  (display 3) (display " * 2 = ") (display (tabla2)) (newline)
  (display 3) (display " * 3 = ") (display (tabla3)) (newline)
  (display 3) (display " * 4 = ") (display (tabla4)) (newline)
  (display 3) (display " * 5 = ") (display (tabla5)) (newline)
  (display 3) (display " * 6 = ") (display (tabla6)) (newline)
  (display 3) (display " * 7 = ") (display (tabla7)) (newline)
  (display 3) (display " * 8 = ") (display (tabla8)) (newline)
  (display 3) (display " * 9 = ") (display (tabla9)) (newline)
  (display 3) (display " * 10 = ") (display (tabla10)) (newline)
)