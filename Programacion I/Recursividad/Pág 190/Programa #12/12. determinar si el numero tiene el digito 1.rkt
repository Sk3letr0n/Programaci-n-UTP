;enunciado: 12. Leer un número entero de 3 dígitos y determinar
;si tiene el dígito 1.
;analisis semantico:
; 952---> no tiene el digito 1
; -951--> si tiene el digito 1
; analisis eps
;       e--->  n
;       p---> 1. leer n   
;             2. mostrar si tiene el digito 1 o si no lo tiene
;       s---> si tiene el digito 1 o si no lo tiene


(define (contar2 n)
  (if (= n 1)
      1
      0))


(define(contar n m)
  (if (= n 0)
      0
      (begin
        (set! m (contar2 (remainder n 10)))
        (if (= m 1)
            1
            (contar (quotient n 10) m)))))


(define(mostrar n)
  (if (= (contar n 0) 1)
      (display "el numero tiene el digito 1")
      (display "el numero no tiene el digito 1")))




(define(interfaz n)
  (display "digite un numero de tres digitos")
  (newline)
  (set! n (read))
  (if (and (> (abs n) 99)(< (abs n) 1000))
      (mostrar (abs n))
      (begin
        (display "el numero debe ser de tres digitos")
        (interaz n))))
(interfaz 1)