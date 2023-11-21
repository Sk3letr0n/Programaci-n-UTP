;enunciado: 11. Leer un número entero de dos dígitos y mostrar en pantalla
;todos los enteros comprendidos entre un dígito y otro.
;analisis semantico:
; 95--->> 5 6 7 8 9
; -95---> -5 -6 -7 -8 -9
; analisis eps
;       e--->  n
;       p---> 1. leer n   
;             2. mostrar todos los numeros comprendidos entre un digito y el otro
;       s---> todos los numeros comprendidos entre un digito y el otro


(define(contarnega n m)
  (if (= m n)
      (display m)
      (begin
        (display m)
        (display " ")
        (contarnega n (- m 1)))))

(define(contar1nega n m)
  (if (= m n)
      (display n)
      (begin
        (display n)
        (display " ")
        (contar1nega (- n 1) m))))




(define(contar n m)
  (if (= m n)
      (display m)
      (begin
        (display m)
        (display " ")
        (contar n (+ m 1)))))

(define(contar1 n m)
  (if (= m n)
      (display n)
      (begin
        (display n)
        (display " ")
        (contar1 (+ n 1) m))))

(define(interfaz n)
  (newline)
  (display "digite un numero de dos digitos")
  (newline)
  (set! n (read))
  (if (and (> (abs n) 9)(< (abs n) 100))
      (begin
        (if (< n 0)
            (begin
              (if (> (quotient n 10)(remainder n 10))
                  (contar1nega (quotient n 10)(remainder n 10))
                  (contarnega (quotient n 10)(remainder n 10))))
              (begin
                (if (> (quotient n 10)(remainder n 10))
                (contar (quotient n 10)(remainder n 10))
                (contar1 (quotient n 10)(remainder n 10))))))
        (begin
          (display "el numero debe ser de dos digitos")
          (interfaz n))))

(interfaz 1)