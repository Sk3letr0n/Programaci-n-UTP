#lang Racket

(require racket/gui)

(define vent (new frame% [min-width 600][min-height 800] [label "Hola mundo"]))

(define mensaje (new message% (parent vent)
                     [label "Puta malparida penta hijueputa gonorreica vida sapa perra sifilitica"]))
(send vent show #t)