;Enunciado/Objetivo
;Construir un programa que lea dos números y muestre el producto de estos
;
;Análisis Semántico
;Producto = a * b
;
;Análisis EPS
;E: a b
;P: 1. Lea a - 2. Lea b - 2. Calcule a * b
;S: Producto
;
;Código
(define (producto a b)
  (* a b )
)
(define (interfaz a b)
  (display "Ingrese el primer #: ")
  (set! a(read))
  (newline)
  (display "Ingrese el segundo #: ")
  (set! b(read))
  (newline)
  (display "El producto de estos dos números es: ")
  (display (producto a b))
)