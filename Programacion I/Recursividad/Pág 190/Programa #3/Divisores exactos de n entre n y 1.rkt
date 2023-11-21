#| Enunciado/Objetivo:
Leer un número entero y mostrar todos los divisores exactos del número comprendidos entre 1 y el número leído

Análisis semántico:
Leer los divisores exactos de n entre n y 1,  4 = 4, 2

Análisis EPS:
Entrada: n
Proceso: 1. Leer n - 2. Buscar los números comprendidos entre 1 y n - 3. Sacar los divisores exactos
Salida: Divisores exactos
|#

(define (calcula n con)
  (if (= con 0)
      1
      (begin
        (if (= (remainder n con) 0)
            0
            1
        )
      )
   )
)
(define (fx1 n con)
  (if (> con n)
      (display " ")
      (begin
        (if (= (remainder n con) 0)
            (begin
              (display con)
              (display " ")
            )
        )
        (fx1 n( + con 1))
      )
  )
)
(define (fx2 n con)
  (if (> con (* (- 1)n))
      (display " ")
      (begin
        (if (= (calcula n con) 0)
            (begin (display con)
                   (display " ")
                   (fx2 n (+ con 1))
            )
            (fx2 n (+ con 1))
        )
      )
  )
)
(define (interfaz n)
  (display "Ingrese un número: ")
  (set! n(read))
  (if (> n 0)
  (fx1 n 1)
  (fx2 n n)
  )
)
(interfaz 1)