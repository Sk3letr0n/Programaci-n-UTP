;Enunciado/Objetivo
;Construir un programa que lea un número entero y muestre su penúltimo dígito
;
;Análisis Semántico
;2051 = 5
;
;Análisis EPS
;E: n
;P: 1. Lea n - 2. Saquele el penúltimo dígito a n
;S: Penúltimo dígito de n
;
;Código
(define (pud n)
  (remainder (quotient n 10) 10)
)
(define (interfaz n)
  (display "Dígite el #: ")
  (set! n(read))
  (newline)
  (display "El penúltimo dígito de su # es: ")
  (display (pud (abs n)))
)