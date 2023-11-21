;enunciado: 10. Leer un número entero y determinar a cuánto es
;igual la suma de todos los enteros comprendidos entre 1 y el número leído.
;analisis semantico:
; 9---> 1 2 3 4 5 6 7 8 9= 45
; -9---> 1 0 -1 -2 -3 -4 -5 -6 -7 -8 -9 = -44
; analisis eps
;       e--->  n
;       p---> 1. leer n   
;             2. mostrar la suma de los numeros comprendido del 1 hasta n
;       s---> suma de los numeros comprendido del 1 hasta n




(define(calcuposi n m a)
  (if (= m n)
      (display (+ m a))
      (begin
        (calcuposi n (+ m 1) (+ m a) )
      )
  )
)

(define (interfaz n)
  (display "Digite un numero: ")
  (newline)
  (set! n (read))
  (display "La suma de los numeros comprendidos del 1 hasta ") (display n) (display " es: ")
  (if (> n 0)   
      (calcuposi n 1 0)
      (calculnega n 1 0)
  )
)
(interfaz 1)
 