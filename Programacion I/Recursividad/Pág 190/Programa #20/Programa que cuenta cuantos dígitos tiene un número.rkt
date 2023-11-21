#| Enunciado/Objetivo:
Construir un programa que reciba un número entero y cuente cuántos dígitos tiene

ANALISIS SEMÁNTICO
n --> 354 ==> tiene 3 dígitos
n --> 243567 ==> tiene 6 dígitos
n --> 847503970947508741057410587 ==> tiene 27 dígitos

ANÁLISIS EPS
E: n

P:
7538 --> 8 --> 1
753 --> 3 --> 1
75 --> 5 --> 1
7 --> 7 --> 1
0 --> 0 --> 0

S: 4
|#

(define (cuentadigitos n)
  (if(= n 0)
     0
     (+ 1 (cuentadigitos (quotient n 10)))
     ))

(define (interfaz n)
  (display "Valor: ")
  (set! n (read))
  (cuentadigitos (abs n))
  )
(interfaz 1)