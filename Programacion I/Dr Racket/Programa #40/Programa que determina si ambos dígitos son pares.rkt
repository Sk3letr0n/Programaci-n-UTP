#|Enunciado Objetivo
Construir un programa que lea un número entero de dos dígitos y determine si ambos dígitos son pares

Análisis Semántico
62 --> 6 #t ,  2 #t

Análisis EPS
E: n
P: 1. Leer n - 2. Sacar el ud - 3. Sacar el pud - 4. Determinar si ambos son pares
S: Resultado
|#
(define (fx n)
  (if (and (= (remainder (remainder n 10) 2) 0)(= (remainder (remainder (quotient n 10) 10) 2) 0))
      (begin
        (display "Ambos dígitos son pares")
      )
      (display "Ambos dígitos no son pares") 
   )
)
(define (res n)
  (if (and (>= n 10)(< n 100))
      (begin
        (display "Su número es de dos dígitos, por lo tanto se determinar si son pares o no: ") 
        (fx n)
      )
      (display "Su número no es de dos dígitos, por lo tanto no se puede determinar si son pares o no ")
   ) 
)
(display "Ingrese un número: ")
(define (interfaz n)
  (res n)
)
(interfaz (read))