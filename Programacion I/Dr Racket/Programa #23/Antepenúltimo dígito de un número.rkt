;Enunciado/Objetivo
;Construir un programa que lea un número entero y muestre su antepenúltimo dígito
;
;Análisis Semántico
;3845 = 8
;
;Análisis EPS
;E: n
;P: 1. Lea n - 2. Saquele el penúltimo dígito a n
;S: Penúltimo dígito de n
;
;Código
(define (apud n)
  (remainder (quotient (quotient n 10) 10) 10)
)
(define (interfaz n)
  (display "Dígite el #: ")
  (set! n(read))
  (newline)
  (display "El antepenúltimo dígito de su # es: ")
  (display (apud (abs n)))
)