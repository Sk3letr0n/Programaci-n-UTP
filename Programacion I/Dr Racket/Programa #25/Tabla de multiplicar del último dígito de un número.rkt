;Enunciado/Objetivo
;Construir un programa que lea un número entero y muestre la tabla de multiplicar de su ultimo dígito
;
;Análisis Semántico
;128 = 8
;8 * 1, 8 * 2... 8 * 10
;
;Análisis EPS
;E: n
;P: 1. Lea n - 2. Saquele el último dígito a n - 3. Calcule la tabla de multiplicar de este dígito
;S: Tabla de multiplicar
;
;Código
(define (tabmult r s)
  (display r)
  (display " x ")
  (display s)
  (display " = ")
  (display (* r s))
  (newline)
)
(define (FunAux r)
  (tabmult r 1)
  (tabmult r 2)
  (tabmult r 3)
  (tabmult r 4)
  (tabmult r 5)
  (tabmult r 6)
  (tabmult r 7)
  (tabmult r 8)
  (tabmult r 9)
  (tabmult r 10)
  (newline)
)
(define (interfaz n r s)
  (display "Dígite el #: ")
  (set! n(read))
  (newline)
  (display "El último dígito de su # es: ")
  (set! r(remainder n 10))
  (display r)
  (newline)
  (display "La tabla de multiplicar de su # es: ")
  (newline)
  (FunAux r)
)