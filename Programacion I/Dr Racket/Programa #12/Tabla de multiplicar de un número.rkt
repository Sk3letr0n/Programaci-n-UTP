;Enunciado/Objetivo
;Construir un programa que calcule la tabla de multiplicar de un número
;
;Analisis semántico
;Tabla de multiplicar = resultado n*1, n*2... n*10
;
;Analisis EPS
;E: n
;P: 1. Lea n - 2. Calcule n*1, n*2... n*10
;S: Tabla
;
;Código
(define (tabla1 n)
  (* n 1)
)
(define (tabla2 n)
  (* n 2)
)
(define (tabla3 n)
  (* n 3)
)
(define (tabla4 n)
  (* n 4)
)
(define (tabla5 n)
  (* n 5)
)
(define (tabla6 n)
  (* n 6)
)
(define (tabla7 n)
  (* n 7)
)
(define (tabla8 n)
  (* n 8)
)
(define (tabla9 n)
  (* n 9)
)
(define (tabla10 n)
  (* n 10)
)
(define (interfaz n)
  (display "Inserte su número ")
  (set! n(read))
  (newline)
  (display "La tabla de multiplicación de su número es: ")
  (newline)
  (display n) (display " * 1 = ") (display (tabla1 n)) (newline)
  (display n) (display " * 2 = ") (display (tabla2 n)) (newline)
  (display n) (display " * 3 = ") (display (tabla3 n)) (newline)
  (display n) (display " * 4 = ") (display (tabla4 n)) (newline)
  (display n) (display " * 5 = ") (display (tabla5 n)) (newline)
  (display n) (display " * 6 = ") (display (tabla6 n)) (newline)
  (display n) (display " * 7 = ") (display (tabla7 n)) (newline)
  (display n) (display " * 8 = ") (display (tabla8 n)) (newline)
  (display n) (display " * 9 = ") (display (tabla9 n)) (newline)
  (display n) (display " * 10 = ") (display (tabla10 n)) (newline)
)