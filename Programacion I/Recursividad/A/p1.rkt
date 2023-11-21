#|ENUNCIADO OBJETIVO
Consruir un programa que calcule la suma de los números pares comprendidos entre 1 y un valor n leído

ANÁLISIS SEMÁNTICO
n --> 7 --> 2+4+6 ==> 12
m --> 14 --> 2+4+6+8+10+12+14 ==> 56
n --> -7 --> -6 + -4 + -2 + 0 --> -12

ANÁLISIS EPS
E: n
P: 1. Seleccionar números pares comprendidos entre n y 1 - 2. Sumar esos valores

S: la suma de los valores positivos
|#

(define (espar x)
  (if(= (remainder x 2) 0)
     x
     0
  )
)

(define (sumaparespos n)
  (if(= n 1)
     0
     (+ (espar n)
        (sumaparespos (- n 1))
     )
  )
)

(define (sumaparesneg n)
  (if(= n 1)
     0
     (+ (espar n)
        (sumaparesneg (+ n 1))
     )
   )
)     

(define (interfaz n)
  (display "Num: ")
  (set! n (read))
  (if (> n 0)
      (display (sumaparespos n))
      (display (sumaparesneg n))
      )
  )
(interfaz 1)

