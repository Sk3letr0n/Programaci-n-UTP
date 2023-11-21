#|Enunciado Objetivo
Construir un programa que lea un número entero de dos dígitos y calcule la suma de sus dos dígitos

Análisis Semántico
65 = 6 + 5 = 11

Análisis EPS
E: n
P: 1. Leer n - 2. Sacar el ud - 3. Sacar el pud - 4. Calcular pud + ud
S: Suma
|#
(define (fx n)
  (+ (remainder n 10) (remainder (quotient n 10) 10))
)
(define (suma n)
  (if (and (>= n 10)(< n 100))
      (begin
        (display "Su número es de dos dígitos, por lo tanto se puede calcular la suma: ")
        (fx n)
      )
      (display "Su número no es de dos dígitos, por lo tanto no se puede calcular la suma ")
   )
)
(display "Ingrese un número: ")
(define (interfaz n)
  (suma n)
)
(interfaz (read))