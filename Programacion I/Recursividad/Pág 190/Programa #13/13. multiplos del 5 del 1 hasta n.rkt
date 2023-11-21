;enunciado: 13. Leer un entero y mostrar todos los múltiplos
;de 5 comprendidos entre 1 y el número leído.
;analisis semantico:
; 25--->  5 10 15 20 25
; -25--> -5 -10 -15 -20 -25
; analisis eps
;       e--->  n
;       p---> 1. leer n   
;             2. mostrar los multiplos del 5 comprendidos del 1 hasta n
;       s---> los multiplos del 5 comprendidos del 1 hasta n



(define(contarnega n m)
  (if (= m (- n 1))
      (display " ")
      (begin
        (if (= (remainder m 5) 0)
            (begin
              (display m)
              (display " ")
              (contarnega n (- m 1)))
            (contarnega n (- m 1))))))

(define(contar n m)
  (if (= m (+ n 1))
      (display " ")
      (begin
        (if (= (remainder m 5) 0)
            (begin
              (display m)
              (display " ")
              (contar n (+ m 1)))
            (contar n (+ m 1))))))


(define(interfaz n)
  (display "digite un numero")
  (newline)
  (set! n (read))
  (display "los multiplos del 5 comprendidos entre 1 hasta")
  (display n)
  (display "son:")
  (newline)
  (if (> n 0)
      (contar n 1)
      (contarnega n 1)))
(interfaz 1)