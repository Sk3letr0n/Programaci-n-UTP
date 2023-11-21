;enunciado: 15. Escribir en pantalla el resultado de sumar los
;primeros 20 múltiplos de 3.
; 3 + 6 + 9 + 12 + 15 + 18 + 21 + 24 + 27 + 30 + 33 + 36 + 39 + 42
; + 45 + 48 + 51 + 54 + 57 + 60= 630
; analisis eps
;       e--->  
;       p---> 1.    
;             2. mostrar la suma de los primeros 20 multiplos del 3
;       s---> la suma de los primeros 20 multiplos del 3


(define (mostrar n)
  (display 3)
  (display "*")
  (display n)
  (display "= "))


(define(contar n m a)
  (if(= n 21)
     (begin
       (display "     _____      ")
       (newline)
       (display "      ")
       (display (+ m a)))
     (begin
       (mostrar n)
       (display (* 3 n))(display "+")
       (newline)
       (contar (+ n 1) (* 3 n) (+ m a)))))



(define (interfaz)
  (display "los primeros 20 multiplos del 3 son: ")
  (newline)
  (contar 1 0 0))
(interfaz)
