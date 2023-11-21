;enunciado: 14. Mostrar en pantalla los primeros 20 múltiplos de 3.
;analisis semantico:
; 3 6 9 12 15 18 21 24 27 30 33 36 39 42 45 48 51 54 57 60
; analisis eps
;       e--->  
;       p---> 1.    
;             2. mostrar los primeros 20 multiplos del 3
;       s---> los primeros 20 multiplos del 3



(define (mostrar n)
  (display 3)
  (display "*")
  (display n)
  (display "= "))


(define(contar n)
  (if(= n 21)
     (display " ")
     (begin
       (mostrar n)
       (display (* 3 n))
       (newline)
       (contar (+ n 1)))))



(define (interfaz)
  (display "los primeros 20 multiplos del 3 son: ")
  (newline)
  (contar 1))
(interfaz)

