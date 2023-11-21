#|Enunciado Objetivo
Construir un programa que lea un número entero y determine si este termina en 4

Análisis Semántico
54 = 4 #t  -  69 = 9 #f

Análisis EPS
E: n
P: 1. Leer n - 2. Sacar ultimo digito de n - 3. Determinar si termina en 4
S: Resultado
|#

(define (ud n)
  (if (= (remainder n 10) 4)
  (display "Su número termina en 4")
  (display "Su número no termina en 4")
  )
)
(define (interfaz n)
  (display "Ingrese un un número: ")
  (set! n(read))
  (ud n)
)