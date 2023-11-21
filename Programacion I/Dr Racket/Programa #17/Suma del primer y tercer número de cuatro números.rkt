;Enunciado/Objetivo
;Construir un programa que calcule la suma del primer y tercer número de cuatro números
;
;Analisis semántico
;Suma = resultado de n1+n3
;
;Analisis EPS
;E: n1 n2 n3 n4
;P: 1. Lea n1 - 2. Lea n2 - 3. Lea n3 - 4. Lea n4 - 5. Calcule n1+n3
;S: Suma
;
;Código
(define (suma n1 n2 n3 n4)
  (+ n1 n3)
)
(define (interfaz n1 n2 n3 n4)
  (display "Ingrese el primer número ")
  (set! n1 (read))
  (newline)
  (display "Ingrese el segundo número ")
  (set! n2 (read))
  (newline)
  (display "Ingrese el tercer número ")
  (set! n3 (read))
  (newline)
  (display "Ingrese el cuarto número ")
  (set! n4 (read))
  (newline)
  (display "La suma del primer y tercer número de los cuatro números es: ")
  (display (suma n1 n2 n3 n4))
)   