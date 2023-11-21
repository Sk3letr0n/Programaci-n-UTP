;enunciado: 16. Mostrar en pantalla el promedio entero de los n primeros
;múltiplos de 3 para un número n leído
; 6--> 3 6 9 12 15 18 = 10 
; analisis eps
;       e--->  n
;       p---> 1.leer n    
;             2. mostrar el promedio de los primeros n multiplos de 3
;       s---> el promedio de los primeros n multiplos de 3




(define(mostrar2 n b)
  (display "el promedio de los primeros ")
  (display b)(display " multiplos del 3 es: ")
  (newline)
  (display n)
  (display "/")
  (display b)
  (display "="))

(define (mostrar n)
  (display 3)
  (display "*")
  (display n)
  (display "= "))


(define(contar b n m a)
  (if(= n (+ b 1))
     (begin
       (display "     _____      ")
       (newline)
       (display "      ")
       (display (+ m a))
       (newline)
       (mostrar2 (+ m a) b)
       (display (quotient (+ m a) b)))
     (begin
       (mostrar n)
       (display (* 3 n))(display "+")
       (newline)
       (contar b (+ n 1) (* 3 n) (+ m a)))))


(define(interfaz)
  (display "digite un numero: ")
  (newline)
  (contar (abs (read)) 1 0 0))
(interfaz)