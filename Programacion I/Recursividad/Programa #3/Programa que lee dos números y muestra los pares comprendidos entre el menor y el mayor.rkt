#| Enunciado/Objetivo:
Construir un programa que lea dos números enteros y muestre todos los pares comprendidos entre el menor y el mayor

Análisis semántico:
Leer los números pares entre n y m, ej: 15, 8--> 8 10 12 14

Análisis EPS:
Entrada: n m
Proceso: 1. Leer n - 2. Leer m - 3. Determinar el mayor - 4. Determinar el mayor - 5. Determinar los pares comprendidos entre estos 
Salida: Pares entre n y m
|#
;Código
(define (suman n)
  (if (= 0 (remainder n 2))
      (begin (display n) (display " ")
      )
      (display " ")
  )  
)
(define (sumam m)
  (if (= 0 (remainder m 2))
      (begin (display m)(display " ")
      )
      (display " ")
  )
)
  
(define (ciclo1 m n)
  (if  (= m n)
       (sumam m)
       (begin (suman n)
              (ciclo1 m (- n 1))
       )     
  )
)

(define (ciclo2 m n)
  (if  (= n m)
        (suman n)
        (begin (sumam m)  
           (ciclo2 (- m 1) n)        
        )     
  )
)

(define (int n m)
  (display "Ingrese un número ")(newline)
  (set! n  (read))
  (display "Ingrese el segundo número ")(newline)
  (set! m  (read))
  (if (> n m)
      (ciclo1 m n)
      (ciclo2 m n)
  )
)
(int 1 2)