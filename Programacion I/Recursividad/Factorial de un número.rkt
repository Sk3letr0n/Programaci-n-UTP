#| Enunciado/Objetivo
Leer un número y calcularle su factorial.

Análisis Semántico
Multiplicacion sucesiva, Ej:  5!--> 5*4*3*2*1 = 120

EPS
E: n
P: 1. Lea n - 2. Calcular factorial de n
S: Mostrar n!
|#

(define (dis n)
  (display n)
  (display " ")
  (display "*")
  (display " "))

(define (Mmul n)
   (* n (- n 1)))

(define (mult n)
  (cond
    ( (= n 0)1)
    ( (= n 1)1)
    (else
     (* n (mult (- n 1))))))


(define (cont n)
  (if (= n 1)
      (begin
        (display "1 ") (display "= ") )
     
      (begin
        (dis n)
        (cont (- n 1)))))

(define (int n)
  (display "Ingrese un número")(newline)
  (set! n (read))
  (display "Su factorial es")(newline)
  (cont n) (mult n))
 
(int 1)