;Enunciado/Objetivo
;Construir un programa que calcule la multiplicación de cuatro números
;
;Analisis semántico
;Resta = resultado de l*m*n*o
;
;Analisis EPS
;E: l m n o
;P: 1. Lea l - 2. Lea m - 3. Lea n - 4. Lea o - 5. Calcule l*m*n*o
;S: Multiplicación
;
;Código
(define (multiplicación l m n o)
  (* l m n o)
)
(define (interfaz l m n o)
  (display "Ingrese el primer número ")
  (set! l (read))
  (newline)
  (display "Ingrese el segundo número ")
  (set! m (read))
  (newline)
  (display "Ingrese el tercer número ")
  (set! n (read))
  (newline)
  (display "Ingrese el cuarto número ")
  (set! o (read))
  (newline)
  (display "La multiplicación de los cuatro números es: ")
  (display (multiplicación l m n o))
)   