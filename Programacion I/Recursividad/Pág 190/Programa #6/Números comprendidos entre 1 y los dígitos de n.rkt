#|Enunciado/Objetivo
Leer un número entero de tres dígitos y mostrar todos los enteros comprendidos entre 1 y cada uno de los dígitos.

Análisis Semántico:
624----> 1 2 3 4 5 6 --- 1 2 --- 1 2 3 4  
598----> 1 2 3 4 5---- 1 2 3 4 5 6 7 8 9--- 1 2 3 4 5 6 7 8  
-946----> 1 0 -1 -2 -3 -4 -5 -6 -7 -8 -9----- 1 0 -1 -2 -3 -4 ---- 1 0 -1....-6

Análisis EPS
E: n 
P: 1. Lea n - 2. Calcule si n es de tres dígitos - 3. Si es verdadero, calcular los números del 1 hasta cada dígito si es verdadero
S: Números comprendidos entre cada dígito de n
|#

(define (muestra n)
  (newline)
  (display "Los numeros comprendidos del 1 hasta el dígito ") (display n) (display " del numero ingresado son:")
)
;-----------------------------------------------------------------
;Para cuando el numero es negativo 

(define (calneg1 m con)
  (if (= con m)
      (display con)
      (begin
        (display con)
        (display " ")
        (calneg1 m (- con 1))
      )
  )
)

(define (calneg n)
  (if (= (quotient n 10) 0)
      (begin
        (muestra n)
        (newline)
      (calneg1 (remainder n 10) 1)
      )
      (begin
        (muestra (remainder n 10))
        (newline)
        (calneg1 (remainder n 10) 1)
        (calneg (quotient n 10))
      )
  )
)

;------------------------------------------------------------------------
;Para cuando el numero es positivo

(define (calpos1 m con)
  (if (= con m)
      (display con)
      (begin
        (display con)
        (display " ")
        (calpos1 m (+ con 1))
      )
  )
)

(define (calpos n)
  (if (= (quotient n 10) 0)
      (begin
        (muestra n)
        (newline)
      (calpos1 (remainder n 10) 1))
      (begin
        (muestra (remainder n 10))
        (newline)
        (calpos1 (remainder n 10) 1)
        (calpos (quotient n 10))
      )
  )
)
;----------------------------------------////////////////----------------
(define (dig n)
  (if (and (> (abs n) 99)(< (abs n) 1000))
      (if (> n 0)
          1
          0
      )
      (begin
        (display "El numero debe ser de 3 digitos")
      )
  )
)

(define (interfaz n)
  (newline)
  (display "Digite un numero: ")
  (newline)
  (set! n (read))
  (if (= (dig n) 1)
      (calpos n)
      (calneg n)
      )
  )
(interfaz 1)
 
