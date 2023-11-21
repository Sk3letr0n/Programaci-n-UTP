
(define (unidades n)
  (cond
    ((= n 1)(display "Uno"))
    ((= n 2)(display "Dos"))
    ((= n 3)(display "Tres"))
    ((= n 4)(display "Cuatro"))
    ((= n 5)(display "Cinco"))
    ((= n 6)(display "Seis"))
    ((= n 7)(display "Siete"))
    ((= n 8)(display "Ocho"))
    ((= n 9)(display "Nueve"))
    ))

(define (decenas n)
  (cond
    ((= n 1)(display "Dieci"))
    ((= n 2)(display "Veinti"))
    ((= n 3)(display "Treinta y "))
    ((= n 4)(display "Cuarenta y "))
    ((= n 5)(display "Cincuenta y "))
    ((= n 6)(display "Sesenta y "))
    ((= n 7)(display "Setenta y "))
    ((= n 8)(display "Ochenta y "))
    ((= n 9)(display "Noventa y "))
    ))
  
;Enunciado Objetivo
; Leer un número de 2 dígitos y mostrar su monto escrito
; OJO. Si el num es positivo 36 --> Treinta y Seis
; -36 --> Menos Treinta y Seis

; AS. Monto escrito -->numero escrito en texto

; EPS--> E--> n
; P--> 1. Leer n,2. Validar 2dig, 3. Separar dig, 4. Monto escrito

; Código

(define (ud n)
  (remainder n 10))

(define (pud n)
  (remainder (quotient n 10) 10))

(define (interfaz n)
  (display "Num de 2 dig: ")
  (set! n (read))
  (if(and (>= (abs n) 10)(<= (abs n) 99))
     (begin
       (decenas (pud (abs n)))
       (unidades (ud (abs n)))
       )
     (display "El num no es de 2 dig")
     )
  )

(interfaz 1)










