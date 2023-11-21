#| Todos los programas estan hechos con la misma lista |#
(define numlista (list 81 92 103 28 94 2 73))
(define illista (list 81 92 103 28 81 2 73))

#| 1. Número menor de la lista |#
(define (menorlista lista con)
  (if (null? lista)
      (display con)
      (begin
        (if (< (car lista) con)
            (set! con (car lista))
            )
        (menorlista (cdr lista) con)
        )
      )
  )
(define (int con)
  (set! con (car numlista))
  (display "El menor número de la lista es: ")
  (menorlista numlista con)
  (newline)
  )
(int 1)

#| 2. Primer número de la lista repetido en la lista |#
(define (iguallista lista con)
  (if (null? lista)
      (display "La lista no tiene números repetidos")
      (begin
        (if (= (car lista) con)
            (begin
              (display "El número que se repite es: ")
              (display con)
            )
        (iguallista (cdr lista) con)
        )
      )
  )
)
(define (inta con)
  (set! con (car illista))
  (iguallista illista con)
  (newline)
)
(inta 1)

#| 3. Promedio de los datos en la lista |#
