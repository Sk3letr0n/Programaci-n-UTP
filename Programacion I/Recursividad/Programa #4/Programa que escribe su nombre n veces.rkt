#|
Enunciado/Objetivo:
Construir un prog que escriba n veces su nombre, para un valor de n leído

Análisis semántico:
4 = Steven Grisales López Steven Grisales López Steven Grisales López Steven Grisales López

Análisis EPS:
E: name, n
P: 1. Leer n  -  2. Leer name  -  3. Escribir name n veces
S: Su nombre n veces.
|#
;Código

(define (mos n)
(display n)
(display " "))

(define (ciclo1 n m)
  (if (> m 0)
      (begin (mos n)
             (ciclo1 n (- m 1) )
      )
      (display "")
  )
)

(define (nombre n  m)
(display "Ingrese su nombre: ")
  (set! n  (read))
  (display "¿Cuántas veces desea repetir el nombre? ")
  (set! m (read))
  (newline)
  (ciclo1 n m))
 (nombre 1  2)