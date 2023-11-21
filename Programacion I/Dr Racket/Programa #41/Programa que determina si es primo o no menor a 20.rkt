#|Enunciado Objetivo
Construir un programa que lea un número entero de dos dígitos menor que 20 y determine si es primo

Análisis Semántico
11 --> #t ,  12 --> #f

Análisis EPS
E: n
P: 1. Leer n - 2. Determinar si es primo
S: Resultado
|#
(display "Ingrese un número: ")
(define (faux n)
  (if (and (< n 20)(>= n 10))
     (begin
       (display "Su número es de dos dígitos y menor que 20, por lo tanto se puede determinar si es primo o no, ")
       (fx n)
     )
     (display "Su número no es de dos dígitos y menor que 20, por lo tanto no se puede determinar si es primo o no ")
  )
)
(define (fx n)
  (if (or (= n 11) (= n 13) (= n 17) (= n 19))
      (display "Su número es primo")
      (display "Su número no es primo")       
  )
)
(faux (read))
