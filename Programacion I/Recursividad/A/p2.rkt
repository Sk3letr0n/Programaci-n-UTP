; RECURSIVIDAD NIVEL 1
; objetivo: construir un prog que permita sumar todos los enteros comprendidos
; entre 1 y un valor entero positivo leido

; Análisis semántico:
; 4 --> 1+2+3+4 = 10
; 9 --> 1+2+3+4+5+6+7+8+9=45

; Análisis EPS
; E--> n+ entero
; P--> 1+2+3+4+5...+(n-1)+n
; S-->Suma 1->n

(define (funcionx n)
     (display n)
     (display "+")
)

(define (sumade1an n)
  (if(= n 0)
     0
     (begin
       (funcionx n)
     (+ n (sumade1an (- n 1)))
     
     )
     )
     )

(sumade1an 5)







