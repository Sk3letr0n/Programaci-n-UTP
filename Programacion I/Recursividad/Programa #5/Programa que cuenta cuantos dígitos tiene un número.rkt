#| Enunciado/Objetivo:
Construir un programa que reciba un número entero y cuente cuántos dígitos tiene

Análisis semántico:
Leer el número y contar cuántos dígitos tiene:   291 = 3 dígitos

Análisis EPS:
Entrada: Leer un número
Proceso: 1. Leer n - 2. Contar cuantos dígitos tiene
Salida: dígitos
|#
;Código
(define (fx n)
  (display n)
  (display " ")
)

(define (ciclo n)
  (if (or (> n 0) (= n 1))
      (begin
        (fx n)
        (ciclo (- n 1))
      )
      (display "")
  )
)
  
(define (ciclo1 m n)
  (if  (n)
       (sumam m)
       (begin (suman n)
              (ciclo1 m (- n 1))
       )     
  )
)

(define (int n m)
  (display "Ingrese un número ")(newline)
  (set! n  (read))
  (if (> n m)
      (ciclo1 m n)
      (ciclo2 m n)
  )
)
(int 1 2)