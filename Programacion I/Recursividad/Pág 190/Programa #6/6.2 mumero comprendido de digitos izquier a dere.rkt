;enunciado: 6. Leer un número entero de tres dígitos y
;mostrar todos los enteros comprendidos entre 1 y cada uno de los dígitos.
;analisis semantico:
; 624----> 1 2 3 4 5 6 --- 1 2 --- 1 2 3 4  
; 598----> 1 2 3 4 5---- 1 2 3 4 5 6 7 8 9--- 1 2 3 4 5 6 7 8  
; -946----> 1 0 -1 -2 -3 -4 -5 -6 -7 -8 -9----- 1 0 -1 -2 -3 -4 ---- 1 0 -1....-6
; analisis eps
;       e---> n 
;       p---> 1. lea n 
;             2. calcule si n es de tres digitos
;             3. si es verdadero, calcule los numeros comprendidos del 1 hasta
;                cada digito de n
;             4. si es falso, mostrar los digitos deben ser de tres digitos
;       s---> si es verdadero, los numeros comprendidos del 1 hast cada digito de n
;             si es falso, los digitos deben ser de tres digitos


(define (muestra n)
  (newline)
  (display "los numeros comprendidos del 1 hasta el digito ")
  (display n) (display " del numero ingresado son:"))


(define (calculanega m cont)
  (if (= cont m)
      (display cont)
      (begin
        (display cont)
        (display " ")
        (calculanega m (- cont 1)))))

(define (calcula m cont)
  (if (= cont m)
      (display cont)
      (begin
        (display cont)
        (display " ")
        (calcula m (+ cont 1)))))

(define (poone n)
(if (and (> (abs n) 99)(< (abs n) 1000))
    (if (> n 0)
      (begin
        (muestra (quotient n 100))
        (newline)
        (calcula (quotient n 100) 1)
        (newline)
        (muestra (remainder(quotient n 10)10))
        (newline)
        (calcula (remainder(quotient n 10)10) 1)
        (newline)
        (muestra (remainder n 10))
        (newline)
        (calcula (remainder n 10) 1))
      (begin
        (muestra (quotient n 100))
        (newline)
        (calculanega (quotient n 100) 1)
        (newline)
        (muestra (remainder(quotient n 10)10))
        (newline)
        (calculanega (remainder(quotient n 10)10) 1)
        (newline)
        (muestra (remainder n 10))
        (newline)
        (calculanega (remainder n 10) 1)))
    (begin(display "el numero debe ser de 3 digitos")(interfaz 1))
      ))


(define (interfaz n)
  (newline)
  (display "digite un numero")
  (newline)
  (set! n (read))
  (poone n))


 (interfaz 1)