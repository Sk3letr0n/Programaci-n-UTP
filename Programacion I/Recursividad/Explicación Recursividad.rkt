
; RECURSIVIDAD NIVEL 0
; EO: Construir un prog que permita mostrar la tabla de multiplicar de un dig

; AS: 3x5=15 (1..10)

; Análisis EPS:
; E--> n (1 dig)
; P--> Mostrar la tabla de multiplicar en formato estandar
; 3x1=3  3x2=6 ... 3x10=30
; S--> Tabla de multiplicar

; Code

; VERSIÓN SIMPLE
(define (formato n m)
  (newline)
  (display n)
  (display "x")
  (display m)
  (display "=")
  (display (* n m))
  )

; VERSION RECURSIVA NIVEL 0
; Llamado mutuo entre funciones
(define (tabdemultv2 n clave)  ;<<<<<<<<<<<< Definición de la función
  (formato n clave) ;<<<<<<<<<<<<<<< cuerpo de la función
  (if(< clave 10); <<<<<<<<<<<<<< condición de parada
     (tabdemultv2 n (+ clave 1))))

; versión correcta recursivamente hablando
(define (tabdemultv3 n clave)
  (if(= clave 11)
     (display "")
     (begin
       (formato n clave)
       (tabdemultv3 n (+ clave 1)))
     ))

(define (interfaz n)
  (display "Valor: ")
  (set! n (read))
  (if(and (>= n 1)(<= n 9))
     (tabdemultv3 n 1)
     (display "Error"))
  )

(interfaz 1)

; estructura de una función recursiva
; 1 Definición de la función
; 2 Condición de parada
; 3 Llamado recursivo
  










