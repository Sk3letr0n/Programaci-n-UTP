; 1. Construir una función que encuentre el número menor de una lista
(define l1(list 20 49 61 8 35))
(define (menor lista contador)
  (if(null? lista)
     0
     (begin
       (if (< contador car)
           (= contador cdr)
           (+ (contador ))
       )
     )
   )
)
(define (muestraLista lista)
  (if(null? lista)
     (display "")
     (begin
       (display (car lista))
       (newline)
       (muestraLista (cdr lista))
     )
  )
)