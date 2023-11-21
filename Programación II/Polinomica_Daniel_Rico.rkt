#lang racket
#|
Fecha de publicación:21/04/2022
Hora:12:00 pm
Versión de su código: 14.0
Daniel Rico Palacio
Lenguaje Racket
 Versión del lenguaje utilizado: 8.3
 Presentado a: Doctor Ricardo Moreno Laverde
 Universidad Tecnológica de Pereira
 Programa de Ingeniería de Sistemas y Computación
Haremos un programa que pida al usuario una funcion polinomica,luego que pida un rango inicial y un rango final final,tambien un incremento,realizara una tabla de valores X y Y y graficara la función.
|#
(require graphics/graphics)
(open-graphics)
;--------------------------Salvedades-------------------------------
(printf "Buenas querido usuario por favor lea las siguientes salvedades que tenemos con nuestro programa\npara evitar inconvenientes.\n")
(printf "Salvedades:-El polinomio no debe tener mas de 80 componentes.\n")
(printf "           -Ya que la libreria graphics de Racket cuando dibuja tiene un tamaño de fuente muy grande\n            por comodidad no se le es recomendable usar valores muy grandes de números.\n")
(printf "           -La funcion debe ser ingresada siguiendo el ejemplo: ~a3x4-45x24+34(-4)~a.\n"(integer->char 34)(integer->char 34))
(printf "           -El rango inicial no puede sobre pasar al rango final \n           y el rango final ingresado no puede sobrepasar a 80.\n")
(printf "\nPor favor ingrese su polinomio:\n")
;--------------------------------------------------------------------
(define v1  (vector "Coeficientes" "Potencias"))
(define v2  (make-vector 2 #\0)) (define v3  (make-vector 2 #\0)) (define v4  (make-vector 2 #\0)) (define v5   (make-vector 2 #\0)) (define v6  (make-vector 2 #\0))
(define v7  (make-vector 2 #\0)) (define v8  (make-vector 2 #\0)) (define v9  (make-vector 2 #\0)) (define v10  (make-vector 2 #\0)) (define v11 (make-vector 2 #\0))
(define v12 (make-vector 2 #\0)) (define v13 (make-vector 2 #\0)) (define v14 (make-vector 2 #\0)) (define v15  (make-vector 2 #\0)) (define v16 (make-vector 2 #\0))
(define v17 (make-vector 2 #\0)) (define v18 (make-vector 2 #\0)) (define v19 (make-vector 2 #\0)) (define v20  (make-vector 2 #\0)) (define v21 (make-vector 2 #\0))
(define v22 (make-vector 2 #\0)) (define v23 (make-vector 2 #\0)) (define v24 (make-vector 2 #\0)) (define v25  (make-vector 2 #\0)) (define v26 (make-vector 2 #\0))
(define v27 (make-vector 2 #\0)) (define v28 (make-vector 2 #\0)) (define v29 (make-vector 2 #\0)) (define v30  (make-vector 2 #\0)) (define v31 (make-vector 2 #\0))
(define v32 (make-vector 2 #\0)) (define v33 (make-vector 2 #\0)) (define v34 (make-vector 2 #\0)) (define v35  (make-vector 2 #\0)) (define v36 (make-vector 2 #\0))
(define v37 (make-vector 2 #\0)) (define v38 (make-vector 2 #\0)) (define v39 (make-vector 2 #\0)) (define v40  (make-vector 2 #\0)) (define v41 (make-vector 2 #\0))
(define v42 (make-vector 2 #\0)) (define v43 (make-vector 2 #\0)) (define v44 (make-vector 2 #\0)) (define v45  (make-vector 2 #\0)) (define v46 (make-vector 2 #\0))
(define v47 (make-vector 2 #\0)) (define v48 (make-vector 2 #\0)) (define v49 (make-vector 2 #\0)) (define v50  (make-vector 2 #\0)) (define v51 (make-vector 2 #\0))
(define v52 (make-vector 2 #\0)) (define v53 (make-vector 2 #\0)) (define v54 (make-vector 2 #\0)) (define v55  (make-vector 2 #\0)) (define v56 (make-vector 2 #\0))
(define v57 (make-vector 2 #\0)) (define v58 (make-vector 2 #\0)) (define v59 (make-vector 2 #\0)) (define v60  (make-vector 2 #\0)) (define v61 (make-vector 2 #\0))
(define v62 (make-vector 2 #\0)) (define v63 (make-vector 2 #\0)) (define v64 (make-vector 2 #\0)) (define v65  (make-vector 2 #\0)) (define v66 (make-vector 2 #\0))
(define v67 (make-vector 2 #\0)) (define v68 (make-vector 2 #\0)) (define v69 (make-vector 2 #\0)) (define v70  (make-vector 2 #\0)) (define v71 (make-vector 2 #\0))
(define v72 (make-vector 2 #\0)) (define v73 (make-vector 2 #\0)) (define v74 (make-vector 2 #\0)) (define v75  (make-vector 2 #\0)) (define v76 (make-vector 2 #\0))
(define v77 (make-vector 2 #\0)) (define v78 (make-vector 2 #\0)) (define v79 (make-vector 2 #\0)) (define v80  (make-vector 2 #\0)) (define v81 (make-vector 2 #\0))
(define v82 (make-vector 2 #\0)) (define v83 (make-vector 2 #\0)) (define v84 (make-vector 2 #\0)) (define v85  (make-vector 2 #\0)) (define v86 (make-vector 2 #\0))
(define v87 (make-vector 2 #\0)) (define v88 (make-vector 2 #\0)) (define v89 (make-vector 2 #\0)) (define v90  (make-vector 2 #\0)) (define v91 (make-vector 2 #\0))
(define v92 (make-vector 2 #\0)) (define v93 (make-vector 2 #\0)) (define v94 (make-vector 2 #\0)) (define v95  (make-vector 2 #\0)) (define v96 (make-vector 2 #\0))
(define v97 (make-vector 2 #\0)) (define v98 (make-vector 2 #\0)) (define v99 (make-vector 2 #\0)) (define v100 (make-vector 2 #\0)) (define v101 (make-vector 2 #\0))

(define m (vector v1  v2  v3  v4  v5  v6  v7  v8  v9  v10
                  v11 v12 v13 v14 v15 v16 v17 v18 v19 v20
                  v21 v22 v23 v24 v25 v26 v27 v28 v29 v30
                  v31 v32 v33 v34 v35 v36 v37 v38 v39 v40
                  v41 v42 v43 v44 v45 v46 v47 v48 v49 v50
                  v51 v52 v53 v54 v55 v56 v57 v58 v59 v60
                  v61 v62 v63 v64 v65 v66 v67 v68 v69 v70
                  v71 v72 v73 v74 v75 v76 v77 v78 v79 v80
                  v81 v82 v83 v84 v85 v86 v87 v88 v89 v90
                  v91 v92 v93 v94 v95 v96 v97 v98 v99 v100 v101))

(define v102  (make-vector 2 #\0)) (define v103  (make-vector 2 #\0)) (define v104  (make-vector 2 #\0)) (define v105  (make-vector 2 #\0)) (define v106  (make-vector 2 #\0))
(define v107  (make-vector 2 #\0)) (define v108  (make-vector 2 #\0)) (define v109  (make-vector 2 #\0)) (define v110  (make-vector 2 #\0)) (define v111  (make-vector 2 #\0))
(define v112  (make-vector 2 #\0)) (define v113  (make-vector 2 #\0)) (define v114  (make-vector 2 #\0)) (define v115  (make-vector 2 #\0)) (define v116  (make-vector 2 #\0))
(define v117  (make-vector 2 #\0)) (define v118  (make-vector 2 #\0)) (define v119  (make-vector 2 #\0)) (define v120  (make-vector 2 #\0)) (define v121  (make-vector 2 #\0))
(define v122  (make-vector 2 #\0)) (define v123  (make-vector 2 #\0)) (define v124  (make-vector 2 #\0)) (define v125  (make-vector 2 #\0)) (define v126  (make-vector 2 #\0))
(define v127  (make-vector 2 #\0)) (define v128  (make-vector 2 #\0)) (define v129  (make-vector 2 #\0)) (define v130  (make-vector 2 #\0)) (define v131  (make-vector 2 #\0))
(define v132  (make-vector 2 #\0)) (define v133  (make-vector 2 #\0)) (define v134  (make-vector 2 #\0)) (define v135  (make-vector 2 #\0)) (define v136  (make-vector 2 #\0))
(define v137  (make-vector 2 #\0)) (define v138  (make-vector 2 #\0)) (define v139  (make-vector 2 #\0)) (define v140  (make-vector 2 #\0)) (define v141  (make-vector 2 #\0))
(define v142  (make-vector 2 #\0)) (define v143  (make-vector 2 #\0)) (define v144  (make-vector 2 #\0)) (define v145  (make-vector 2 #\0)) (define v146  (make-vector 2 #\0))
(define v147  (make-vector 2 #\0)) (define v148  (make-vector 2 #\0)) (define v149  (make-vector 2 #\0)) (define v150  (make-vector 2 #\0)) (define v151  (make-vector 2 #\0))
(define v152  (make-vector 2 #\0)) (define v153  (make-vector 2 #\0)) (define v154  (make-vector 2 #\0)) (define v155  (make-vector 2 #\0)) (define v156  (make-vector 2 #\0))
(define v157  (make-vector 2 #\0)) (define v158  (make-vector 2 #\0)) (define v159  (make-vector 2 #\0)) (define v160  (make-vector 2 #\0)) (define v161  (make-vector 2 #\0))
(define v162  (make-vector 2 #\0)) (define v163  (make-vector 2 #\0)) (define v164  (make-vector 2 #\0)) (define v165  (make-vector 2 #\0)) (define v166  (make-vector 2 #\0))
(define v167  (make-vector 2 #\0)) (define v168  (make-vector 2 #\0)) (define v169  (make-vector 2 #\0)) (define v170  (make-vector 2 #\0)) (define v171  (make-vector 2 #\0))
(define v172  (make-vector 2 #\0)) (define v173  (make-vector 2 #\0)) (define v174  (make-vector 2 #\0)) (define v175  (make-vector 2 #\0)) (define v176  (make-vector 2 #\0))
(define v177  (make-vector 2 #\0)) (define v178  (make-vector 2 #\0)) (define v179  (make-vector 2 #\0)) (define v180  (make-vector 2 #\0)) (define v181  (make-vector 2 #\0))
(define v182  (make-vector 2 #\0)) (define v183  (make-vector 2 #\0)) (define v184  (make-vector 2 #\0)) (define v185  (make-vector 2 #\0)) (define v186  (make-vector 2 #\0))
(define v187  (make-vector 2 #\0)) (define v188  (make-vector 2 #\0)) (define v189  (make-vector 2 #\0)) (define v190  (make-vector 2 #\0)) (define v191  (make-vector 2 #\0))
(define v192  (make-vector 2 #\0)) (define v193  (make-vector 2 #\0)) (define v194  (make-vector 2 #\0)) (define v195  (make-vector 2 #\0)) (define v196  (make-vector 2 #\0))
(define v197  (make-vector 2 #\0)) (define v198  (make-vector 2 #\0)) (define v199  (make-vector 2 #\0)) (define v200  (make-vector 2 #\0)) (define v201  (make-vector 2 #\0))

(define m2 (vector v102 v103 v104 v105 v106 v107 v108 v109 v110
                   v111 v112 v113 v114 v115 v116 v117 v118 v119 v120
                   v121 v122 v123 v124 v125 v126 v127 v128 v129 v130
                   v131 v132 v133 v134 v135 v136 v137 v138 v139 v140
                   v141 v142 v143 v144 v145 v146 v147 v148 v149 v150
                   v151 v152 v153 v154 v155 v156 v157 v158 v159 v160
                   v161 v162 v163 v164 v165 v166 v167 v168 v169 v170
                   v171 v172 v173 v174 v175 v176 v177 v178 v179 v180
                   v181 v182 v183 v184 v185 v186 v187 v188 v189 v190
                   v191 v192 v193 v194 v195 v196 v197 v198 v199 v200 v201))

(define v000 (vector "PosnX" "PosnY"))
(define v202 (make-vector 2 #\0)) (define v203 (make-vector 2 #\0)) (define v204 (make-vector 2 #\0)) (define v205  (make-vector 2 #\0)) (define v206 (make-vector 2 #\0))
(define v207 (make-vector 2 #\0)) (define v208 (make-vector 2 #\0)) (define v209 (make-vector 2 #\0)) (define v210  (make-vector 2 #\0)) (define v211 (make-vector 2 #\0))
(define v212 (make-vector 2 #\0)) (define v213 (make-vector 2 #\0)) (define v214 (make-vector 2 #\0)) (define v215  (make-vector 2 #\0)) (define v216 (make-vector 2 #\0))
(define v217 (make-vector 2 #\0)) (define v218 (make-vector 2 #\0)) (define v219 (make-vector 2 #\0)) (define v220  (make-vector 2 #\0)) (define v221 (make-vector 2 #\0))
(define v222 (make-vector 2 #\0)) (define v223 (make-vector 2 #\0)) (define v224 (make-vector 2 #\0)) (define v225  (make-vector 2 #\0)) (define v226 (make-vector 2 #\0))
(define v227 (make-vector 2 #\0)) (define v228 (make-vector 2 #\0)) (define v229 (make-vector 2 #\0)) (define v230  (make-vector 2 #\0)) (define v231 (make-vector 2 #\0))
(define v232 (make-vector 2 #\0)) (define v233 (make-vector 2 #\0)) (define v234 (make-vector 2 #\0)) (define v235  (make-vector 2 #\0)) (define v236 (make-vector 2 #\0))
(define v237 (make-vector 2 #\0)) (define v238 (make-vector 2 #\0)) (define v239 (make-vector 2 #\0)) (define v240  (make-vector 2 #\0)) (define v241 (make-vector 2 #\0))
(define v242 (make-vector 2 #\0)) (define v243 (make-vector 2 #\0)) (define v244 (make-vector 2 #\0)) (define v245  (make-vector 2 #\0)) (define v246 (make-vector 2 #\0))
(define v247 (make-vector 2 #\0)) (define v248 (make-vector 2 #\0)) (define v249 (make-vector 2 #\0)) (define v250  (make-vector 2 #\0)) (define v251 (make-vector 2 #\0))
(define v252 (make-vector 2 #\0)) (define v253 (make-vector 2 #\0)) (define v254 (make-vector 2 #\0)) (define v255  (make-vector 2 #\0)) (define v256 (make-vector 2 #\0))
(define v257 (make-vector 2 #\0)) (define v258 (make-vector 2 #\0)) (define v259 (make-vector 2 #\0)) (define v260  (make-vector 2 #\0)) (define v261 (make-vector 2 #\0))
(define v262 (make-vector 2 #\0)) (define v263 (make-vector 2 #\0)) (define v264 (make-vector 2 #\0)) (define v265  (make-vector 2 #\0)) (define v266 (make-vector 2 #\0))
(define v267 (make-vector 2 #\0)) (define v268 (make-vector 2 #\0)) (define v269 (make-vector 2 #\0)) (define v270  (make-vector 2 #\0)) (define v271 (make-vector 2 #\0))
(define v272 (make-vector 2 #\0)) (define v273 (make-vector 2 #\0)) (define v274 (make-vector 2 #\0)) (define v275  (make-vector 2 #\0)) (define v276 (make-vector 2 #\0))
(define v277 (make-vector 2 #\0)) (define v278 (make-vector 2 #\0)) (define v279 (make-vector 2 #\0)) (define v280  (make-vector 2 #\0)) (define v281 (make-vector 2 #\0))
(define v282 (make-vector 2 #\0)) (define v283 (make-vector 2 #\0)) (define v284 (make-vector 2 #\0)) (define v285  (make-vector 2 #\0)) (define v286 (make-vector 2 #\0))
(define v287 (make-vector 2 #\0)) (define v288 (make-vector 2 #\0)) (define v289 (make-vector 2 #\0)) (define v290  (make-vector 2 #\0)) (define v291 (make-vector 2 #\0))
(define v292 (make-vector 2 #\0)) (define v293 (make-vector 2 #\0)) (define v294 (make-vector 2 #\0)) (define v295  (make-vector 2 #\0)) (define v296 (make-vector 2 #\0))
(define v297 (make-vector 2 #\0)) (define v298 (make-vector 2 #\0)) (define v299 (make-vector 2 #\0)) (define v300  (make-vector 2 #\0)) (define v301 (make-vector 2 #\0))

(define m3 (vector v000 v202 v203 v204 v205 v206 v207 v208 v209 v210
                   v211 v212 v213 v214 v215 v216 v217 v218 v219 v220
                   v221 v222 v223 v224 v225 v226 v227 v228 v229 v230
                   v231 v232 v233 v234 v235 v236 v237 v238 v239 v240
                   v241 v242 v243 v244 v245 v246 v247 v248 v249 v250
                   v251 v252 v253 v254 v255 v256 v257 v258 v259 v260
                   v261 v262 v263 v264 v265 v266 v267 v268 v269 v270
                   v271 v272 v273 v274 v275 v276 v277 v278 v279 v280
                   v281 v282 v283 v284 v285 v286 v287 v288 v289 v290
                   v291 v292 v293 v294 v295 v296 v297 v298 v299 v300 v301))

(define v302 (make-vector 2 #\0)) (define v303 (make-vector 2 #\0)) (define v304 (make-vector 2 #\0)) (define v305  (make-vector 2 #\0)) (define v306 (make-vector 2 #\0))
(define v307 (make-vector 2 #\0)) (define v308 (make-vector 2 #\0)) (define v309 (make-vector 2 #\0)) (define v310  (make-vector 2 #\0)) (define v311 (make-vector 2 #\0))
(define v312 (make-vector 2 #\0)) (define v313 (make-vector 2 #\0)) (define v314 (make-vector 2 #\0)) (define v315  (make-vector 2 #\0)) (define v316 (make-vector 2 #\0))
(define v317 (make-vector 2 #\0)) (define v318 (make-vector 2 #\0)) (define v319 (make-vector 2 #\0)) (define v320  (make-vector 2 #\0)) (define v321 (make-vector 2 #\0))
(define v322 (make-vector 2 #\0)) (define v323 (make-vector 2 #\0)) (define v324 (make-vector 2 #\0)) (define v325  (make-vector 2 #\0)) (define v326 (make-vector 2 #\0))
(define v327 (make-vector 2 #\0)) (define v328 (make-vector 2 #\0)) (define v329 (make-vector 2 #\0)) (define v330  (make-vector 2 #\0)) (define v331 (make-vector 2 #\0))
(define v332 (make-vector 2 #\0)) (define v333 (make-vector 2 #\0)) (define v334 (make-vector 2 #\0)) (define v335  (make-vector 2 #\0)) (define v336 (make-vector 2 #\0))
(define v337 (make-vector 2 #\0)) (define v338 (make-vector 2 #\0)) (define v339 (make-vector 2 #\0)) (define v340  (make-vector 2 #\0)) (define v341 (make-vector 2 #\0))
(define v342 (make-vector 2 #\0)) (define v343 (make-vector 2 #\0)) (define v344 (make-vector 2 #\0)) (define v345  (make-vector 2 #\0)) (define v346 (make-vector 2 #\0))
(define v347 (make-vector 2 #\0)) (define v348 (make-vector 2 #\0)) (define v349 (make-vector 2 #\0)) (define v350  (make-vector 2 #\0)) (define v351 (make-vector 2 #\0))
(define v352 (make-vector 2 #\0)) (define v353 (make-vector 2 #\0)) (define v354 (make-vector 2 #\0)) (define v355  (make-vector 2 #\0)) (define v356 (make-vector 2 #\0))
(define v357 (make-vector 2 #\0)) (define v358 (make-vector 2 #\0)) (define v359 (make-vector 2 #\0)) (define v360  (make-vector 2 #\0)) (define v361 (make-vector 2 #\0))
(define v362 (make-vector 2 #\0)) (define v363 (make-vector 2 #\0)) (define v364 (make-vector 2 #\0)) (define v365  (make-vector 2 #\0)) (define v366 (make-vector 2 #\0))
(define v367 (make-vector 2 #\0)) (define v368 (make-vector 2 #\0)) (define v369 (make-vector 2 #\0)) (define v370  (make-vector 2 #\0)) (define v371 (make-vector 2 #\0))
(define v372 (make-vector 2 #\0)) (define v373 (make-vector 2 #\0)) (define v374 (make-vector 2 #\0)) (define v375  (make-vector 2 #\0)) (define v376 (make-vector 2 #\0))
(define v377 (make-vector 2 #\0)) (define v378 (make-vector 2 #\0)) (define v379 (make-vector 2 #\0)) (define v380  (make-vector 2 #\0)) (define v381 (make-vector 2 #\0))
(define v382 (make-vector 2 #\0)) (define v383 (make-vector 2 #\0)) (define v384 (make-vector 2 #\0)) (define v385  (make-vector 2 #\0)) (define v386 (make-vector 2 #\0))
(define v387 (make-vector 2 #\0)) (define v388 (make-vector 2 #\0)) (define v389 (make-vector 2 #\0)) (define v390  (make-vector 2 #\0)) (define v391 (make-vector 2 #\0))
(define v392 (make-vector 2 #\0)) (define v393 (make-vector 2 #\0)) (define v394 (make-vector 2 #\0)) (define v395  (make-vector 2 #\0)) (define v396 (make-vector 2 #\0))
(define v397 (make-vector 2 #\0)) (define v398 (make-vector 2 #\0)) (define v399 (make-vector 2 #\0)) (define v400  (make-vector 2 #\0)) (define v401 (make-vector 2 #\0))

(define m4 (vector v302 v303 v304 v305 v306 v307 v308 v309 v310
                   v311 v312 v313 v314 v315 v316 v317 v318 v319 v320
                   v321 v322 v323 v324 v325 v326 v327 v328 v329 v330
                   v331 v332 v333 v334 v335 v336 v337 v338 v339 v340
                   v341 v342 v343 v344 v345 v346 v347 v348 v349 v350
                   v351 v352 v353 v354 v355 v356 v357 v358 v359 v360
                   v361 v362 v363 v364 v365 v366 v367 v368 v369 v370
                   v371 v372 v373 v374 v375 v376 v377 v378 v379 v380
                   v381 v382 v383 v384 v385 v386 v387 v388 v389 v390
                   v391 v392 v393 v394 v395 v396 v397 v398 v399 v400 v401))

(define v402 (make-vector 2 #\0)) (define v403 (make-vector 2 #\0)) (define v404 (make-vector 2 #\0)) (define v405  (make-vector 2 #\0)) (define v406 (make-vector 2 #\0))
(define v407 (make-vector 2 #\0)) (define v408 (make-vector 2 #\0)) (define v409 (make-vector 2 #\0)) (define v410  (make-vector 2 #\0)) (define v411 (make-vector 2 #\0))
(define v412 (make-vector 2 #\0)) (define v413 (make-vector 2 #\0)) (define v414 (make-vector 2 #\0)) (define v415  (make-vector 2 #\0)) (define v416 (make-vector 2 #\0))
(define v417 (make-vector 2 #\0)) (define v418 (make-vector 2 #\0)) (define v419 (make-vector 2 #\0)) (define v420  (make-vector 2 #\0)) (define v421 (make-vector 2 #\0))
(define v422 (make-vector 2 #\0)) (define v423 (make-vector 2 #\0)) (define v424 (make-vector 2 #\0)) (define v425  (make-vector 2 #\0)) (define v426 (make-vector 2 #\0))
(define v427 (make-vector 2 #\0)) (define v428 (make-vector 2 #\0)) (define v429 (make-vector 2 #\0)) (define v430  (make-vector 2 #\0)) (define v431 (make-vector 2 #\0))
(define v432 (make-vector 2 #\0)) (define v433 (make-vector 2 #\0)) (define v434 (make-vector 2 #\0)) (define v435  (make-vector 2 #\0)) (define v436 (make-vector 2 #\0))
(define v437 (make-vector 2 #\0)) (define v438 (make-vector 2 #\0)) (define v439 (make-vector 2 #\0)) (define v440  (make-vector 2 #\0)) (define v441 (make-vector 2 #\0))
(define v442 (make-vector 2 #\0)) (define v443 (make-vector 2 #\0)) (define v444 (make-vector 2 #\0)) (define v445  (make-vector 2 #\0)) (define v446 (make-vector 2 #\0))
(define v447 (make-vector 2 #\0)) (define v448 (make-vector 2 #\0)) (define v449 (make-vector 2 #\0)) (define v450  (make-vector 2 #\0)) (define v451 (make-vector 2 #\0))
(define v452 (make-vector 2 #\0)) (define v453 (make-vector 2 #\0)) (define v454 (make-vector 2 #\0)) (define v455  (make-vector 2 #\0)) (define v456 (make-vector 2 #\0))
(define v457 (make-vector 2 #\0)) (define v458 (make-vector 2 #\0)) (define v459 (make-vector 2 #\0)) (define v460  (make-vector 2 #\0)) (define v461 (make-vector 2 #\0))
(define v462 (make-vector 2 #\0)) (define v463 (make-vector 2 #\0)) (define v464 (make-vector 2 #\0)) (define v465  (make-vector 2 #\0)) (define v466 (make-vector 2 #\0))
(define v467 (make-vector 2 #\0)) (define v468 (make-vector 2 #\0)) (define v469 (make-vector 2 #\0)) (define v470  (make-vector 2 #\0)) (define v471 (make-vector 2 #\0))
(define v472 (make-vector 2 #\0)) (define v473 (make-vector 2 #\0)) (define v474 (make-vector 2 #\0)) (define v475  (make-vector 2 #\0)) (define v476 (make-vector 2 #\0))
(define v477 (make-vector 2 #\0)) (define v478 (make-vector 2 #\0)) (define v479 (make-vector 2 #\0)) (define v480  (make-vector 2 #\0)) (define v481 (make-vector 2 #\0))
(define v482 (make-vector 2 #\0)) (define v483 (make-vector 2 #\0)) (define v484 (make-vector 2 #\0)) (define v485  (make-vector 2 #\0)) (define v486 (make-vector 2 #\0))
(define v487 (make-vector 2 #\0)) (define v488 (make-vector 2 #\0)) (define v489 (make-vector 2 #\0)) (define v490  (make-vector 2 #\0)) (define v491 (make-vector 2 #\0))
(define v492 (make-vector 2 #\0)) (define v493 (make-vector 2 #\0)) (define v494 (make-vector 2 #\0)) (define v495  (make-vector 2 #\0)) (define v496 (make-vector 2 #\0))
(define v497 (make-vector 2 #\0)) (define v498 (make-vector 2 #\0)) (define v499 (make-vector 2 #\0)) (define v500  (make-vector 2 #\0)) (define v501 (make-vector 2 #\0))

(define m5 (vector v402 v403 v404 v405 v406 v407 v408 v409 v410
                   v411 v412 v413 v414 v415 v416 v417 v418 v419 v420
                   v421 v422 v423 v424 v425 v426 v427 v428 v429 v430
                   v431 v432 v433 v434 v435 v436 v437 v438 v439 v440
                   v441 v442 v443 v444 v445 v446 v447 v448 v449 v450
                   v451 v452 v453 v454 v455 v456 v457 v458 v459 v460
                   v461 v462 v463 v464 v465 v466 v467 v468 v469 v470
                   v471 v472 v473 v474 v475 v476 v477 v478 v479 v480
                   v481 v482 v483 v484 v485 v486 v487 v488 v489 v490
                   v491 v492 v493 v494 v495 v496 v497 v498 v499 v500 v501))

;----------------------------------------- separacion polinomio ------------------------------------------------------
(define entrada (~a(read)))
(define entrada2 (string-copy entrada))
(define numero1 (string-length entrada2))
(define nueva (make-string (+ numero1 1) #\space))

(define (cambio CONTADOR)
  (if (<= CONTADOR (- numero1 1))
      (begin
        (string-set! nueva CONTADOR (string-ref entrada2 CONTADOR))
        (cambio (+ 1 CONTADOR))
        );fin begin
      ;de lo contrario
      (void)
      );fin if
  );fin definicion cambio

(cambio 0)

(define polinomio (string-copy nueva))
(define numero (string-length polinomio))

(define (exponentep Y CONTADOR INICIADOR)
  (if (<= CONTADOR (- numero 1))
      (if (equal? (string-ref polinomio CONTADOR) #\))
          (begin
            (vector-set! (vector-ref m Y) 1 (substring polinomio INICIADOR CONTADOR))
            (coeficiente (+ 1 Y) (+ 1 CONTADOR) (+ 1 CONTADOR) 2)
            );fin begin
          
          ;de lo contrario
          (begin
            (if (or  [equal? (string-ref polinomio CONTADOR) #\0]
                     [equal? (string-ref polinomio CONTADOR) #\1]
                     [equal? (string-ref polinomio CONTADOR) #\2]
                     [equal? (string-ref polinomio CONTADOR) #\3]
                     [equal? (string-ref polinomio CONTADOR) #\4]
                     [equal? (string-ref polinomio CONTADOR) #\5]
                     [equal? (string-ref polinomio CONTADOR) #\6]
                     [equal? (string-ref polinomio CONTADOR) #\7]
                     [equal? (string-ref polinomio CONTADOR) #\8]
                     [equal? (string-ref polinomio CONTADOR) #\9]
                     [equal? (string-ref polinomio CONTADOR) #\+]
                     [equal? (string-ref polinomio CONTADOR) #\-]
                     [equal? (string-ref polinomio CONTADOR) #\/]
                     [equal? (string-ref polinomio CONTADOR) #\*]
                     )
                (exponentep Y (+ 1 CONTADOR) INICIADOR)
                                
                ;de lo contrario
                (exponentep Y (+ 1 CONTADOR) INICIADOR)
                );fin if
            );fin if
          );fin if

      ;de lo contrario
      (void)
      );fin if
  );fin definicion exponentep

(define (exponente Y CONTADOR INICIADOR)
  (if (<= Y 99)
      (if (and (or (equal? (string-ref polinomio (- CONTADOR 1)) #\X) (equal? (string-ref polinomio (- CONTADOR 1)) #\x))
               (equal? (string-ref polinomio CONTADOR) #\()
               )
          (exponentep Y (+ 1 CONTADOR) (+ 1 INICIADOR))

          ;de lo contrario
          (if (and (or (equal? (string-ref polinomio (- CONTADOR 1)) #\X) (equal? (string-ref polinomio (- CONTADOR 1)) #\x))
                   (equal? (string-ref polinomio CONTADOR) #\-)
                   )
              (begin
                (vector-set! (vector-ref m Y) 1 "1")
                (coeficiente (+ 1 Y) (+ 1 CONTADOR) CONTADOR 2)
                );fin begin

              ;de lo contrario
              (if (and (or (equal? (string-ref polinomio (- CONTADOR 1)) #\X) (equal? (string-ref polinomio (- CONTADOR 1)) #\x))
                       (equal? (string-ref polinomio CONTADOR) #\+)
                       )
                  (begin
                    (vector-set! (vector-ref m Y) 1 "1")
                    (coeficiente (+ 1 Y) (+ 1 CONTADOR) (+ 1 CONTADOR) 2)
                    );fin begin

                  ;de lo contrario
                  (if (and (or (equal? (string-ref polinomio (- CONTADOR 1)) #\X) (equal? (string-ref polinomio (- CONTADOR 1)) #\x))
                           (equal? (string-ref polinomio CONTADOR) #\space)
                           )
                      (begin
                        (vector-set! (vector-ref m Y) 1 "1")
                        (void)
                        );fin begin

                      ;de lo contrario
                      (if (and (equal? (string-ref polinomio CONTADOR) #\-) (or (equal? (string-ref polinomio (+ 1 CONTADOR)) #\x) (equal? (string-ref polinomio (+ 1 CONTADOR)) #\X)))
                          (begin
                            (vector-set! (vector-ref m Y) 1 (substring polinomio INICIADOR CONTADOR))
                            (coeficiente Y CONTADOR CONTADOR 2)
                            );fin begin
                  
                          ;de lo contrario
                          (if (and (equal? (string-ref polinomio CONTADOR) #\+) (or (equal? (string-ref polinomio (+ 1 CONTADOR)) #\x) (equal? (string-ref polinomio (+ 1 CONTADOR)) #\X)))
                              (begin
                                (vector-set! (vector-ref m Y) 1 (substring polinomio INICIADOR CONTADOR))
                                (coeficiente Y CONTADOR CONTADOR 2)
                                );fin begin
                  
                              ;de lo contrario
                              (if (and (equal? (string-ref polinomio (- CONTADOR 1)) #\)) (equal? (string-ref polinomio CONTADOR) #\-))
                                  (coeficiente (+ 1 Y) (+ 1 CONTADOR) CONTADOR 2)

                                  ;de lo contrario
                                  (if (and (equal? (string-ref polinomio (- CONTADOR 1)) #\)) (equal? (string-ref polinomio CONTADOR) #\+))
                                      (coeficiente (+ 1 Y) (+ 1 CONTADOR) (+ 1 CONTADOR) 2)

                                      ;de lo contrario
                                      (if (equal? (string-ref polinomio CONTADOR) #\-)
                                          (begin
                                            (vector-set! (vector-ref m Y) 1 (substring polinomio INICIADOR CONTADOR))
                                            (coeficiente (+ 1 Y) (+ 1 CONTADOR) CONTADOR 2)
                                            );fin begin

                                          ;de lo contrario

                                          (if (equal? (string-ref polinomio CONTADOR) #\+)
                                              (begin
                                                (vector-set! (vector-ref m Y) 1 (substring polinomio INICIADOR CONTADOR))
                                                (coeficiente (+ 1 Y) (+ 1 CONTADOR) (+ 1 CONTADOR) 2)
                                                );fin begin

                                              ;de lo contrario
                                              (if (equal? (string-ref polinomio CONTADOR) #\space)
                                                  (begin
                                                    (vector-set! (vector-ref m Y) 1 (substring polinomio INICIADOR CONTADOR))
                                                    (void)
                                                    );fin begin
                      
                                                  ;de lo contrario
                                                  (if (or  [equal? (string-ref polinomio CONTADOR) #\0]
                                                           [equal? (string-ref polinomio CONTADOR) #\1]
                                                           [equal? (string-ref polinomio CONTADOR) #\2]
                                                           [equal? (string-ref polinomio CONTADOR) #\3]
                                                           [equal? (string-ref polinomio CONTADOR) #\4]
                                                           [equal? (string-ref polinomio CONTADOR) #\5]
                                                           [equal? (string-ref polinomio CONTADOR) #\6]
                                                           [equal? (string-ref polinomio CONTADOR) #\7]
                                                           [equal? (string-ref polinomio CONTADOR) #\8]
                                                           [equal? (string-ref polinomio CONTADOR) #\9]
                                                           )
                                                      (exponente Y (+ 1 CONTADOR) INICIADOR)
                              
                                                      ;de lo contrario
                                                      (exponente Y (+ 1 CONTADOR) INICIADOR)
                                                      );fin if
                                                  );fin if
                                              );fin if
                                          );fin if
                                      );fin if
                                  );fin if
                              );fin if
                          );fin if
                      );fin if
                  );fin if             
              );fin if
          );fin if

      ;de lo contrario
      (void)
      );fin if
  );fin definicion exponente



(define (coeficientep Y CONTADOR INICIADOR)
  (if (<= CONTADOR (- numero 1))
      (if (equal? (string-ref polinomio CONTADOR) #\))
          (begin
            (vector-set! (vector-ref m Y) 0 (substring polinomio INICIADOR CONTADOR))
            (coeficiente Y (+ 1 CONTADOR) (+ 1 CONTADOR) 2)
            );fin begin
          
          ;de lo contrario
          (begin
            (if (or  [equal? (string-ref polinomio CONTADOR) #\0]
                     [equal? (string-ref polinomio CONTADOR) #\1]
                     [equal? (string-ref polinomio CONTADOR) #\2]
                     [equal? (string-ref polinomio CONTADOR) #\3]
                     [equal? (string-ref polinomio CONTADOR) #\4]
                     [equal? (string-ref polinomio CONTADOR) #\5]
                     [equal? (string-ref polinomio CONTADOR) #\6]
                     [equal? (string-ref polinomio CONTADOR) #\7]
                     [equal? (string-ref polinomio CONTADOR) #\8]
                     [equal? (string-ref polinomio CONTADOR) #\9]
                     [equal? (string-ref polinomio CONTADOR) #\+]
                     [equal? (string-ref polinomio CONTADOR) #\-]
                     [equal? (string-ref polinomio CONTADOR) #\/]
                     [equal? (string-ref polinomio CONTADOR) #\*]
                     )
                (coeficientep Y (+ 1 CONTADOR) INICIADOR)
                                
                ;de lo contrario
                (coeficientep Y (+ 1 CONTADOR) INICIADOR)
                );fin if
            );fin if
          );fin if

      ;de lo contrario
      (void)
      );fin if
  );fin definicion coeficientep

(define (coeficiente Y CONTADOR INICIADOR COMIENZO)
  (if (<= Y 99)
      (if (<= CONTADOR (- numero 1))

          (if (= COMIENZO 1)
              (if (equal? (string-ref polinomio CONTADOR) #\( )
                  (coeficientep Y (+ 1 CONTADOR) (+ 1 INICIADOR))

                  ;de lo contrario
                  (if (equal? (string-ref polinomio CONTADOR) #\-)
                      (coeficiente Y (+ 1 CONTADOR) INICIADOR 2)

                      ;de lo contrario
                      (if (equal? (string-ref polinomio CONTADOR) #\x)
                          (begin
                            (vector-set! (vector-ref m Y) 0 "1")
                            (exponente Y (+ 1 CONTADOR) (+ 1 CONTADOR))
                            );fin begin

                          ;de lo contrario
                          (if (equal? (string-ref polinomio CONTADOR) #\X)
                              (begin
                                (vector-set! (vector-ref m Y) 0 "1")
                                (exponente Y (+ 1 CONTADOR) (+ 1 CONTADOR))
                                );fin begin

                              ;de lo contrario
                              
                              (coeficiente Y (+ 1 CONTADOR) CONTADOR 2)
                              );fin if
                          );fin if
                      );fin if
                  );fin if
          
              ;de lo contrario
              (if (equal? (string-ref polinomio CONTADOR) #\( )
                  (coeficientep Y (+ 1 CONTADOR) (+ 1 INICIADOR))

                  ;de lo contrario
                  (if (and (equal? (string-ref polinomio CONTADOR) #\-) (or (equal? (string-ref polinomio (+ 1 CONTADOR)) #\x) (equal? (string-ref polinomio (+ 1 CONTADOR)) #\X)))
                      (begin
                        (vector-set! (vector-ref m (+ 1 Y)) 0 "-1")
                        (exponente (+ 1 Y) (+ 1 CONTADOR) (+ 2 CONTADOR))
                        );fin begin
                  
                      ;de lo contrario

                      (if (and (equal? (string-ref polinomio CONTADOR) #\+) (or (equal? (string-ref polinomio (+ 1 CONTADOR)) #\x) (equal? (string-ref polinomio (+ 1 CONTADOR)) #\X)))
                          (begin
                            (vector-set! (vector-ref m (+ 1 Y)) 0 "1")
                            (exponente (+ 1 Y) (+ 1 CONTADOR) (+ 2 CONTADOR))
                            );fin begin
                  
                          ;de lo contrario
                          (if (and (or  [equal? (string-ref polinomio (- CONTADOR 1)) #\0]
                                        [equal? (string-ref polinomio (- CONTADOR 1)) #\1]
                                        [equal? (string-ref polinomio (- CONTADOR 1)) #\2]
                                        [equal? (string-ref polinomio (- CONTADOR 1)) #\3]
                                        [equal? (string-ref polinomio (- CONTADOR 1)) #\4]
                                        [equal? (string-ref polinomio (- CONTADOR 1)) #\5]
                                        [equal? (string-ref polinomio (- CONTADOR 1)) #\6]
                                        [equal? (string-ref polinomio (- CONTADOR 1)) #\7]
                                        [equal? (string-ref polinomio (- CONTADOR 1)) #\8]
                                        [equal? (string-ref polinomio (- CONTADOR 1)) #\9]
                                        ) (equal? (string-ref polinomio CONTADOR) #\-))
                              (begin
                                (vector-set! (vector-ref m Y) 0 (substring polinomio INICIADOR CONTADOR))
                                (vector-set! (vector-ref m Y) 1 "0")
                                (coeficiente (+ 1 Y) (+ 1 CONTADOR) CONTADOR 2)
                                );fin begin

                              ;de lo contrario
                              (if (and (or  [equal? (string-ref polinomio (- CONTADOR 1)) #\0]
                                            [equal? (string-ref polinomio (- CONTADOR 1)) #\1]
                                            [equal? (string-ref polinomio (- CONTADOR 1)) #\2]
                                            [equal? (string-ref polinomio (- CONTADOR 1)) #\3]
                                            [equal? (string-ref polinomio (- CONTADOR 1)) #\4]
                                            [equal? (string-ref polinomio (- CONTADOR 1)) #\5]
                                            [equal? (string-ref polinomio (- CONTADOR 1)) #\6]
                                            [equal? (string-ref polinomio (- CONTADOR 1)) #\7]
                                            [equal? (string-ref polinomio (- CONTADOR 1)) #\8]
                                            [equal? (string-ref polinomio (- CONTADOR 1)) #\9]
                                            ) (equal? (string-ref polinomio CONTADOR) #\+))
                                  (begin
                                    (vector-set! (vector-ref m Y) 0 (substring polinomio INICIADOR CONTADOR))
                                    (vector-set! (vector-ref m Y) 1 "0")
                                    (coeficiente (+ 1 Y) (+ 1 CONTADOR) (+ 1 CONTADOR) 2)
                                    );fin begin

                                  ;de lo contrario
                                  (if (and (equal? (string-ref polinomio (- CONTADOR 1)) #\)) (equal? (string-ref polinomio CONTADOR) #\space))
                                      (void)

                                      (if (and (equal? (string-ref polinomio (- CONTADOR 1)) #\)) (equal? (string-ref polinomio CONTADOR) #\+))
                                          (coeficiente Y (+ 1 CONTADOR) (+ 1 CONTADOR) 2)
                          
                                          ;de lo contrario
                                          (if (and (equal? (string-ref polinomio (- CONTADOR 1)) #\)) (equal? (string-ref polinomio CONTADOR) #\-))
                                              (coeficiente Y (+ 1 CONTADOR) CONTADOR 2)
                          
                                              ;de lo contrario
                                              (if (equal? (string-ref polinomio CONTADOR) #\space)
                                                  (begin
                                                    (vector-set! (vector-ref m Y) 0 (substring polinomio INICIADOR CONTADOR))
                                                    (vector-set! (vector-ref m Y) 1 "0")
                                                    );fin begin
                      
                                                  ;de lo contrario
                                                  (if (or  [equal? (string-ref polinomio CONTADOR) #\0]
                                                           [equal? (string-ref polinomio CONTADOR) #\1]
                                                           [equal? (string-ref polinomio CONTADOR) #\2]
                                                           [equal? (string-ref polinomio CONTADOR) #\3]
                                                           [equal? (string-ref polinomio CONTADOR) #\4]
                                                           [equal? (string-ref polinomio CONTADOR) #\5]
                                                           [equal? (string-ref polinomio CONTADOR) #\6]
                                                           [equal? (string-ref polinomio CONTADOR) #\7]
                                                           [equal? (string-ref polinomio CONTADOR) #\8]
                                                           [equal? (string-ref polinomio CONTADOR) #\9]
                                                           )
                                                      (coeficiente Y (+ 1 CONTADOR) INICIADOR 2)

                                                      ;de lo contrario
                                                      (if (equal? (string-ref polinomio CONTADOR) #\X)
                                                          (begin
                                                            (vector-set! (vector-ref m Y) 0 (substring polinomio INICIADOR CONTADOR))
                                                            (exponente Y (+ 1 CONTADOR) (+ 1 CONTADOR))
                                                            );fin begin

                                                          ;de lo contrario
                                                          (if (equal? (string-ref polinomio CONTADOR) #\x)
                                                              (begin
                                                                (vector-set! (vector-ref m Y) 0 (substring polinomio INICIADOR CONTADOR))
                                                                (exponente Y (+ 1 CONTADOR) (+ 1 CONTADOR))
                                                                );fin begin

                                                              ;de lo contrario
                                                              (coeficiente Y (+ 1 CONTADOR) INICIADOR 2)
                                                              );fin if
                                                          );fin if
                                                      );fin if
                                                  );fin if
                                              );fin if
                                          );fin if
                                      );fin if
                                  );fin if
                              );fin if
                          );fin if
                      );fin if
                  );fin if
              );fin if
          
          ;de lo contrario
          (void)
          );fin if

      ;de lo contrario
      (void)
      );fin if
  );fin definicion coeficiente
(coeficiente 1 0 0 1)

(printf "\n~a\t~a\n" (vector-ref (vector-ref m 0) 0) (vector-ref (vector-ref m 0) 1))

;------------------------------ crea la tabla de la separacion del polinomio -------------------------------
(define (tab Y)
  (if (equal? (vector-ref (vector-ref m Y) 0) #\0)
      (void)

      ;de lo contrario
      (begin
        (if (equal? [string-ref (vector-ref (vector-ref m Y) 0) 0] #\-)
            (begin
              (printf "~a" (vector-ref (vector-ref m Y) 0))
              (printf "~a" (make-string (- 16 [string-length (vector-ref (vector-ref m Y) 0)]) #\space))
              );fin begin

            ;de lo contrario
            (begin
              (printf " ~a" (vector-ref (vector-ref m Y) 0))
              (printf "~a" (make-string (- 14 [string-length (vector-ref (vector-ref m Y) 0)]) #\space))
              );fin begin
            );fin if      

        (if (equal? [string-ref (vector-ref (vector-ref m Y) 0) 0] #\-)
            (printf "~a\n" (vector-ref (vector-ref m Y) 1))

            ;de lo contrario
            (printf " ~a\n" (vector-ref (vector-ref m Y) 1))
            );fin if
        (tab (+ 1 Y))
        );fin begin
      );fin if
  );fin definicion tab
(tab 1)
;"10-10-10-10-10+6542661x(-4)+564"

(define (conversion X Y CONTADOR NUMERO INCREMENTO)
  (if (equal? (vector-ref (vector-ref m (+ 1 Y)) 0) #\0)
      (if (= X 0) 
          (if (>= CONTADOR 0)
          
              (if (equal? (string-ref (vector-ref (vector-ref m Y) 0) CONTADOR) #\0)
                  (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 0] NUMERO) (* INCREMENTO 10))
              
                  ;de lo contrario
                  (if (equal? (string-ref (vector-ref (vector-ref m Y) 0) CONTADOR) #\1)
                      (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 1] NUMERO) (* INCREMENTO 10))

                      ;de lo contrario
                      (if (equal? (string-ref (vector-ref (vector-ref m Y) 0) CONTADOR) #\2)
                          (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 2] NUMERO) (* INCREMENTO 10))

                          ;de lo contrario
                          (if (equal? (string-ref (vector-ref (vector-ref m Y) 0) CONTADOR) #\3)
                              (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 3] NUMERO) (* INCREMENTO 10))

                              ;de lo contrario
                              (if (equal? (string-ref (vector-ref (vector-ref m Y) 0) CONTADOR) #\4)
                                  (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 4] NUMERO) (* INCREMENTO 10))

                                  ;de lo contrario
                                  (if (equal? (string-ref (vector-ref (vector-ref m Y) 0) CONTADOR) #\5)
                                      (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 5] NUMERO) (* INCREMENTO 10))

                                      ;de lo contrario
                                      (if (equal? (string-ref (vector-ref (vector-ref m Y) 0) CONTADOR) #\6)
                                          (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 6] NUMERO) (* INCREMENTO 10))

                                          ;de lo contrario
                                          (if (equal? (string-ref (vector-ref (vector-ref m Y) 0) CONTADOR) #\7)
                                              (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 7] NUMERO) (* INCREMENTO 10))

                                              ;de lo contrario
                                              (if (equal? (string-ref (vector-ref (vector-ref m Y) 0) CONTADOR) #\8)
                                                  (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 8] NUMERO) (* INCREMENTO 10))

                                                  ;de lo contrario
                                                  (if (equal? (string-ref (vector-ref (vector-ref m Y) 0) CONTADOR) #\9)
                                                      (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 9] NUMERO) (* INCREMENTO 10))

                                                      ;de lo contrario
                                                      (if (equal? (string-ref (vector-ref (vector-ref m Y) 0) CONTADOR) #\-)
                                                          (conversion X Y (- CONTADOR 1) (* NUMERO -1) (* INCREMENTO 10))

                                                          ;de lo contrario
                                                          (void)
                                                          );fin if
                                                      );fin if
                                                  );fin if
                                              );fin if
                                          );fin if
                                      );fin if
                                  );fin if
                              );fin if
                          );fin if
                      );fin if
                  );fin if

              ;de lo contrario
              (begin
                (vector-set! (vector-ref m2 Y) 0 NUMERO)
                (conversion 1 Y (- (string-length (vector-ref (vector-ref m Y) 1)) 1) 0 1)
                );fin begin
              );fin if
       
          ;de lo contrario
          (if (>= CONTADOR 0)
          
              (if (equal? (string-ref (vector-ref (vector-ref m Y) 1) CONTADOR) #\0)
                  (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 0] NUMERO) (* INCREMENTO 10))
              
                  ;de lo contrario
                  (if (equal? (string-ref (vector-ref (vector-ref m Y) 1) CONTADOR) #\1)
                      (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 1] NUMERO) (* INCREMENTO 10))

                      ;de lo contrario
                      (if (equal? (string-ref (vector-ref (vector-ref m Y) 1) CONTADOR) #\2)
                          (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 2] NUMERO) (* INCREMENTO 10))

                          ;de lo contrario
                          (if (equal? (string-ref (vector-ref (vector-ref m Y) 1) CONTADOR) #\3)
                              (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 3] NUMERO) (* INCREMENTO 10))

                              ;de lo contrario
                              (if (equal? (string-ref (vector-ref (vector-ref m Y) 1) CONTADOR) #\4)
                                  (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 4] NUMERO) (* INCREMENTO 10))

                                  ;de lo contrario
                                  (if (equal? (string-ref (vector-ref (vector-ref m Y) 1) CONTADOR) #\5)
                                      (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 5] NUMERO) (* INCREMENTO 10))

                                      ;de lo contrario
                                      (if (equal? (string-ref (vector-ref (vector-ref m Y) 1) CONTADOR) #\6)
                                          (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 6] NUMERO) (* INCREMENTO 10))

                                          ;de lo contrario
                                          (if (equal? (string-ref (vector-ref (vector-ref m Y) 1) CONTADOR) #\7)
                                              (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 7] NUMERO) (* INCREMENTO 10))

                                              ;de lo contrario
                                              (if (equal? (string-ref (vector-ref (vector-ref m Y) 1) CONTADOR) #\8)
                                                  (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 8] NUMERO) (* INCREMENTO 10))

                                                  ;de lo contrario
                                                  (if (equal? (string-ref (vector-ref (vector-ref m Y) 1) CONTADOR) #\9)
                                                      (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 9] NUMERO) (* INCREMENTO 10))

                                                      ;de lo contrario
                                                      (if (equal? (string-ref (vector-ref (vector-ref m Y) 1) CONTADOR) #\-)
                                                          (conversion X Y (- CONTADOR 1) (* NUMERO -1) (* INCREMENTO 10))

                                                          ;de lo contrario
                                                          (void)
                                                          );fin if
                                                      );fin if
                                                  );fin if
                                              );fin if
                                          );fin if
                                      );fin if
                                  );fin if
                              );fin if
                          );fin if
                      );fin if
                  );fin if

              ;de lo contrario
              (vector-set! (vector-ref m2 Y) 1 NUMERO)
              );fin if
          );fin if

      ;de lo contrario
      (if (= X 0) 
          (if (>= CONTADOR 0)
          
              (if (equal? (string-ref (vector-ref (vector-ref m Y) 0) CONTADOR) #\0)
                  (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 0] NUMERO) (* INCREMENTO 10))
              
                  ;de lo contrario
                  (if (equal? (string-ref (vector-ref (vector-ref m Y) 0) CONTADOR) #\1)
                      (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 1] NUMERO) (* INCREMENTO 10))

                      ;de lo contrario
                      (if (equal? (string-ref (vector-ref (vector-ref m Y) 0) CONTADOR) #\2)
                          (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 2] NUMERO) (* INCREMENTO 10))

                          ;de lo contrario
                          (if (equal? (string-ref (vector-ref (vector-ref m Y) 0) CONTADOR) #\3)
                              (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 3] NUMERO) (* INCREMENTO 10))

                              ;de lo contrario
                              (if (equal? (string-ref (vector-ref (vector-ref m Y) 0) CONTADOR) #\4)
                                  (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 4] NUMERO) (* INCREMENTO 10))

                                  ;de lo contrario
                                  (if (equal? (string-ref (vector-ref (vector-ref m Y) 0) CONTADOR) #\5)
                                      (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 5] NUMERO) (* INCREMENTO 10))

                                      ;de lo contrario
                                      (if (equal? (string-ref (vector-ref (vector-ref m Y) 0) CONTADOR) #\6)
                                          (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 6] NUMERO) (* INCREMENTO 10))

                                          ;de lo contrario
                                          (if (equal? (string-ref (vector-ref (vector-ref m Y) 0) CONTADOR) #\7)
                                              (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 7] NUMERO) (* INCREMENTO 10))

                                              ;de lo contrario
                                              (if (equal? (string-ref (vector-ref (vector-ref m Y) 0) CONTADOR) #\8)
                                                  (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 8] NUMERO) (* INCREMENTO 10))

                                                  ;de lo contrario
                                                  (if (equal? (string-ref (vector-ref (vector-ref m Y) 0) CONTADOR) #\9)
                                                      (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 9] NUMERO) (* INCREMENTO 10))

                                                      ;de lo contrario
                                                      (if (equal? (string-ref (vector-ref (vector-ref m Y) 0) CONTADOR) #\-)
                                                          (conversion X Y (- CONTADOR 1) (* NUMERO -1) (* INCREMENTO 10))

                                                          ;de lo contrario
                                                          (void)
                                                          );fin if
                                                      );fin if
                                                  );fin if
                                              );fin if
                                          );fin if
                                      );fin if
                                  );fin if
                              );fin if
                          );fin if
                      );fin if
                  );fin if

              ;de lo contrario
              (begin
                (vector-set! (vector-ref m2 Y) 0 NUMERO)
                (conversion 1 Y (- (string-length (vector-ref (vector-ref m Y) 1)) 1) 0 1)
                );fin begin
              );fin if
       
          ;de lo contrario
          (if (>= CONTADOR 0)
          
              (if (equal? (string-ref (vector-ref (vector-ref m Y) 1) CONTADOR) #\0)
                  (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 0] NUMERO) (* INCREMENTO 10))
              
                  ;de lo contrario
                  (if (equal? (string-ref (vector-ref (vector-ref m Y) 1) CONTADOR) #\1)
                      (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 1] NUMERO) (* INCREMENTO 10))

                      ;de lo contrario
                      (if (equal? (string-ref (vector-ref (vector-ref m Y) 1) CONTADOR) #\2)
                          (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 2] NUMERO) (* INCREMENTO 10))

                          ;de lo contrario
                          (if (equal? (string-ref (vector-ref (vector-ref m Y) 1) CONTADOR) #\3)
                              (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 3] NUMERO) (* INCREMENTO 10))

                              ;de lo contrario
                              (if (equal? (string-ref (vector-ref (vector-ref m Y) 1) CONTADOR) #\4)
                                  (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 4] NUMERO) (* INCREMENTO 10))

                                  ;de lo contrario
                                  (if (equal? (string-ref (vector-ref (vector-ref m Y) 1) CONTADOR) #\5)
                                      (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 5] NUMERO) (* INCREMENTO 10))

                                      ;de lo contrario
                                      (if (equal? (string-ref (vector-ref (vector-ref m Y) 1) CONTADOR) #\6)
                                          (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 6] NUMERO) (* INCREMENTO 10))

                                          ;de lo contrario
                                          (if (equal? (string-ref (vector-ref (vector-ref m Y) 1) CONTADOR) #\7)
                                              (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 7] NUMERO) (* INCREMENTO 10))

                                              ;de lo contrario
                                              (if (equal? (string-ref (vector-ref (vector-ref m Y) 1) CONTADOR) #\8)
                                                  (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 8] NUMERO) (* INCREMENTO 10))

                                                  ;de lo contrario
                                                  (if (equal? (string-ref (vector-ref (vector-ref m Y) 1) CONTADOR) #\9)
                                                      (conversion X Y (- CONTADOR 1) (+ [* INCREMENTO 9] NUMERO) (* INCREMENTO 10))

                                                      ;de lo contrario
                                                      (if (equal? (string-ref (vector-ref (vector-ref m Y) 1) CONTADOR) #\-)
                                                          (conversion X Y (- CONTADOR 1) (* NUMERO -1) (* INCREMENTO 10))

                                                          ;de lo contrario
                                                          (void)
                                                          );fin if
                                                      );fin if
                                                  );fin if
                                              );fin if
                                          );fin if
                                      );fin if
                                  );fin if
                              );fin if
                          );fin if
                      );fin if
                  );fin if

              ;de lo contrario
              (begin
                (vector-set! (vector-ref m2 Y) 1 NUMERO)
                (conversion 0 (+ 1 Y) (- (string-length (vector-ref (vector-ref m (+ 1 Y)) 0)) 1) 0 1)
                );fin begin
              );fin if
          );fin if
      );fin if
  );fin definicion conversion
(conversion 0 1 (- (string-length (vector-ref (vector-ref m 1) 0)) 1) 0 1)

(printf "\nCual desea que sea su rango inicial: ")
(define inicio (read))
(printf "\nCual desea que sea su rango final: ")
(define final (read))
(printf "\nIngrese el incremento: ")
(define incremento (read))

(define (tabla-final YM2 Y INICIO RESULTADO)
  (if (<= INICIO final)
      (if (equal? [vector-ref (vector-ref m2 YM2) 0] #\0)
          (begin
            (vector-set! (vector-ref m3 Y) 0 INICIO)
            (vector-set! (vector-ref m3 Y) 1 RESULTADO)
            (tabla-final 1 (+ 1 Y) (+ INICIO incremento) 0)
            );fin begin
          
          ;de lo contrario
          (if (< [vector-ref {vector-ref m2 YM2} 1] 0)
              (if (= {* 1.0 [expt INICIO (* -1 [vector-ref {vector-ref m2 YM2} 1]) ]} 0)
                  (begin
                    (vector-set! (vector-ref m3 Y) 0 INICIO)
                    (vector-set! (vector-ref m3 Y) 1 0)
                    (tabla-final 1 (+ 1 Y) (+ INICIO incremento) RESULTADO)
                    );fin begin
                  
                  ;De lo contrario
                  (tabla-final (+ 1 YM2) Y INICIO (+ RESULTADO (* [vector-ref {vector-ref m2 YM2} 0] [/ 1 {* 1.0 [expt INICIO (* -1 [vector-ref {vector-ref m2 YM2} 1]) ]}])) )
                  );fin if
              
              ;de lo contrario
              (tabla-final (+ 1 YM2) Y INICIO (+ RESULTADO (* [vector-ref {vector-ref m2 YM2} 0] {* 1.0 [expt INICIO [vector-ref {vector-ref m2 YM2} 1] ]})) )
              );fin if
          );fin if

      ;de lo contrario
      (void)
      );fin if
  );fin definicion tabla-final

(tabla-final 1 1 inicio 0)

(printf "\n")
(printf "\n")
(printf "  ~a~a~a\n" [vector-ref {vector-ref m3 0} 0] (make-string [- 20 (string-length {~a[vector-ref {vector-ref m3 0} 0]}) ] #\space) [vector-ref {vector-ref m3 0} 1])

(define (imprimir-tabla Y)
  (if (equal? [vector-ref {vector-ref m3 Y} 0] #\0)
      (void)
      
      ;de lo contrario
      (if (equal? [vector-ref {vector-ref m3 Y} 1] #\N)
          (begin
            (printf "~a~a" [vector-ref {vector-ref m3 Y} 0] (make-string [- 20 (string-length {~a[vector-ref {vector-ref m3 Y} 0]}) ] #\space))
            (printf "Indeterminado\n")
            (imprimir-tabla (+ 1 Y))
            );fin begin
          
          ;de lo contrario
          (begin
            (printf "~a~a" [vector-ref {vector-ref m3 Y} 0] (make-string [- 20 (string-length {~a[vector-ref {vector-ref m3 Y} 0]}) ] #\space))
            (printf "~a\n" [vector-ref {vector-ref m3 Y} 1])
            (imprimir-tabla (+ 1 Y))
            );fin begin
          );fin if
      );fin if
  );fin definicion imprimir-tabla
(imprimir-tabla 1)

(define plano (open-viewport "Grafica de la función polinomica" 700 700))
((draw-line plano) (make-posn 350 10) (make-posn 350 690))
((draw-line plano) (make-posn 10 350) (make-posn 690 350))
(vector-set! (vector-ref m4 0) 0 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000)
(vector-set! (vector-ref m4 0) 1 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000)
(vector-set! (vector-ref m5 0) 0 -1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000)
(vector-set! (vector-ref m5 0) 1 -1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000)
(define (numeroma Y Y1 NMA)
   
  (if (equal? (vector-ref (vector-ref m3 Y1) 1) #\0)
      (void)
      
      ;de lo contrario
      (if (equal? (vector-ref (vector-ref m3 Y) 1) #\N)
          (numeroma (+ 1 Y) Y1 NMA)
      
          ;de lo contrario
          (if (equal? (vector-ref (vector-ref m3 Y) 1) #\0)
              (if (= NMA 0)
                  (vector-set! (vector-ref m5 Y1) 1 #\0)

                  ;De lo contrario
                  (begin
                    (vector-set! (vector-ref m4 Y1) 0 NMA)
                    (numeroma 1 (+ 1 Y1) 0)
                    );fin begin
                  );fin if
              ;de lo contrario
              (if (and [< (vector-ref (vector-ref m3 Y) 1) (vector-ref (vector-ref m4 (- Y1 1)) 0)] [> (vector-ref (vector-ref m3 Y) 1) NMA] )
                  (numeroma (+ 1 Y) Y1 (vector-ref (vector-ref m3 Y) 1))

                  ;de lo contrario          
                  (numeroma (+ 1 Y) Y1 NMA)
                  );fin if
              );fin if
          );fin if
      );fin if
          
  );fin definicion numeroma

(numeroma 1 1 (vector-ref (vector-ref m3 1) 1))

(define (numeroma2 Y Y1 NMA)
  (if (equal? (vector-ref (vector-ref m3 Y1) 0) #\0)
      (void)
      
      ;de lo contrario
      (if (equal? (vector-ref (vector-ref m3 Y) 0) #\N)
          (numeroma2 (+ 1 Y) Y1 NMA)
      
          ;de lo contrario
          (if (equal? (vector-ref (vector-ref m3 Y) 0) #\0)
              (if (= NMA 0)
                  (vector-set! (vector-ref m4 Y1) 1 #\0)
                     
                  ;De lo contrario
                  (begin
                    (vector-set! (vector-ref m4 Y1) 1 NMA)
                    (numeroma2 1 (+ 1 Y1) 0)
                    );fin begin
                  );fin if
      
              ;de lo contrario
              (if (and [< (vector-ref (vector-ref m3 Y) 0) (vector-ref (vector-ref m4 (- Y1 1)) 1)] [> (vector-ref (vector-ref m3 Y) 0) NMA] )
                  (numeroma2 (+ 1 Y) Y1 (vector-ref (vector-ref m3 Y) 0))

                  ;de lo contrario          
                  (numeroma2 (+ 1 Y) Y1 NMA)
                  );fin if
              );fin if
          );fin if
      );fin if

  );fin definicion numeroma2

(numeroma2 1 1 (vector-ref (vector-ref m3 1) 0))

(define (poner CANTIDAD Y1)
  (if (equal? (vector-ref (vector-ref m4 1) 0) #\0)
      (void)

      ;de lo contrario
      (if (equal? (vector-ref (vector-ref m4 Y1) 0) #\0)
          (if (= CANTIDAD 0)
              (void)

              ;De lo contrario
              (if (= CANTIDAD 1)
                  (begin        
                    ((draw-string plano) (make-posn 350 (- 350 (/ [* 335 (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)))) "-")
                    ((draw-string plano) (make-posn 355 (- 350 (/ [* 335 (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)))) (~a (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)) )
                    );fin begin

                  ;de lo contrario
                  (if (= CANTIDAD 2)
                      (begin        
                        ((draw-string plano) (make-posn 350 (- 350 (/ [* 335 (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)))) "-")
                        ((draw-string plano) (make-posn 355 (- 350 (/ [* 335 (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)))) (~a (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)) )
                        (if (= (vector-ref (vector-ref m4 (- CANTIDAD 1)) 0) 0)
                            (void)
                            ;de lo contrario
                            (begin
                              ((draw-string plano) (make-posn 350 (- 350 [/ [* 335 (vector-ref (vector-ref m4 CANTIDAD) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                              ((draw-string plano) (make-posn 355 (- 350 [/ [* 335 (vector-ref (vector-ref m4 CANTIDAD) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m4 CANTIDAD) 0)))
                              );fin begin
                            );fin if
                        );fin begin

                      ;de lo contrario
                      
                      (if (= CANTIDAD 3)
                          (begin        
                            ((draw-string plano) (make-posn 350 (- 350 (/ [* 335 (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)))) "-")
                            ((draw-string plano) (make-posn 355 (- 350 (/ [* 335 (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)))) (~a (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)) )
                            (if (= (vector-ref (vector-ref m4 (- CANTIDAD 1)) 0) 0)
                                (void)
                                ;de lo contrario
                                (begin
                                  ((draw-string plano) (make-posn 350 (- 350 [/ [* 335 (vector-ref (vector-ref m4 CANTIDAD) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                                  ((draw-string plano) (make-posn 355 (- 350 [/ [* 335 (vector-ref (vector-ref m4 CANTIDAD) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m4 CANTIDAD) 0)))
                                  );fin begin
                                );fin if
                            (if (= (remainder CANTIDAD 2) 0)
                                (begin
                                  ((draw-string plano) (make-posn 350 (- 350 [/ [* 335 (vector-ref (vector-ref m4 (/ CANTIDAD 2)) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                                  ((draw-string plano) (make-posn 355 (- 350 [/ [* 335 (vector-ref (vector-ref m4 (/ CANTIDAD 2)) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m4 (/ CANTIDAD 2)) 0)))
                                  );fin begin
                                ;de lo contrario
                                (begin
                                  ((draw-string plano) (make-posn 350 (- 350 [/ [* 335 (vector-ref (vector-ref m4 (truncate (/ CANTIDAD 2))) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                                  ((draw-string plano) (make-posn 355 (- 350 [/ [* 335 (vector-ref (vector-ref m4 (truncate (/ CANTIDAD 2))) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m4 (truncate (/ CANTIDAD 2))) 0)))
                                  );fin begin
                                );fin if
                            );fin begin
                          
                          ;de lo contrario
                          (begin        
                            ((draw-string plano) (make-posn 350 (- 350 (/ [* 335 (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)))) "-")
                            ((draw-string plano) (make-posn 355 (- 350 (/ [* 335 (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)))) (~a (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)) )

                            (if (= (vector-ref (vector-ref m4 (- CANTIDAD 1)) 0) 0)
                                (void)
                                ;de lo contrario
                                (begin
                                  ((draw-string plano) (make-posn 350 (- 350 [/ [* 335 (vector-ref (vector-ref m4 CANTIDAD) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                                  ((draw-string plano) (make-posn 355 (- 350 [/ [* 335 (vector-ref (vector-ref m4 CANTIDAD) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m4 CANTIDAD) 0)))
                                  );fin begin
                                );fin if
        
                            (if (= (remainder CANTIDAD 2) 0)
                                (begin
                                  ((draw-string plano) (make-posn 350 (- 350 [/ [* 335 (vector-ref (vector-ref m4 (/ CANTIDAD 2)) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                                  ((draw-string plano) (make-posn 355 (- 350 [/ [* 335 (vector-ref (vector-ref m4 (/ CANTIDAD 2)) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m4 (/ CANTIDAD 2)) 0)))
                                  );fin begin
                                ;de lo contrario
                                (begin
                                  ((draw-string plano) (make-posn 350 (- 350 [/ [* 335 (vector-ref (vector-ref m4 (truncate (/ CANTIDAD 2))) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                                  ((draw-string plano) (make-posn 355 (- 350 [/ [* 335 (vector-ref (vector-ref m4 (truncate (/ CANTIDAD 2))) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m4 (truncate (/ CANTIDAD 2))) 0)))
                                  );fin begin
                                );fin if

                            (if (= (remainder [truncate (/ CANTIDAD 2)] 2) 0)
                                (if (= [/ [* 335 (vector-ref (vector-ref m4 (/ (truncate (/ CANTIDAD 2)) 2)) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)] 1)
                                    (begin
                                      ((draw-string plano) (make-posn 350 (- 350 [/ [* 335 (vector-ref (vector-ref m4 (+ 1 (/ (truncate (/ CANTIDAD 2)) 2))) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                                      ((draw-string plano) (make-posn 355 (- 350 [/ [* 335 (vector-ref (vector-ref m4 (+ 1 (/ (truncate (/ CANTIDAD 2)) 2))) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m4 (+ 1 (/ (truncate (/ CANTIDAD 2)) 2))) 0)))
                                      );fin begin
                                    ;de lo contrario
                                    (void)
                                    );fin if
                                ;De lo contrario
            
                                (if (= (truncate (/ (truncate (/ CANTIDAD 2)) 2)) 1)
                                    (begin
                                      ((draw-string plano) (make-posn 350 (- 350 [/ [* 335 (vector-ref (vector-ref m4 (+ 1 (truncate (/ (truncate (/ CANTIDAD 2)) 2)))) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                                      ((draw-string plano) (make-posn 355 (- 350 [/ [* 335 (vector-ref (vector-ref m4 (+ 1 (truncate (/ (truncate (/ CANTIDAD 2)) 2)))) 0)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m4 (+ 1 (truncate (/ (truncate (/ CANTIDAD 2)) 2)))) 0)))
                                      );fin begin
                                    ;de lo contrario
                                    (void)
                                    );fin if
                                );fin if        
                            );fin begin
                          );fin if
                      );fin if
                  );fin if
              );fin if
          ;de lo contrario
          (poner (+ 1 CANTIDAD) (+ 1 Y1))
          );fin if
      );fin if
  );fin definicion poner
(poner 0 1)

(define (poner2 CANTIDAD Y1)
  (if (equal? (vector-ref (vector-ref m4 1) 1) #\0)
      (void)

      ;de lo contrario
      (if (equal? (vector-ref (vector-ref m4 Y1) 1) #\0)
          (if (= CANTIDAD 0)
              (void)

              ;de lo contrario
              (if (= CANTIDAD 1)
                  (begin        
                    ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                    ((draw-string plano) (make-posn (+ 340 [/ [* 335 (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)) )
                    );fin begin
                  
                  ;de lo contrario

                  (if (= CANTIDAD 2)
                      (begin        
                        ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                        ((draw-string plano) (make-posn (+ 340 [/ [* 335 (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)) )

                        (if (= (vector-ref (vector-ref m4 (- CANTIDAD 1)) 1) 0)
                            (void)
                            ;de lo contrario
                            (begin
                              ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m4 CANTIDAD) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                              ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m4 CANTIDAD) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m4 CANTIDAD) 1)))
                              );fin begin
                            );fin if
                        );fin begin

                      ;De lo contrario

                      (if (= CANTIDAD 3)
                          (begin        
                            ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                            ((draw-string plano) (make-posn (+ 340 [/ [* 335 (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)) )

                            (if (= (vector-ref (vector-ref m4 (- CANTIDAD 1)) 1) 0)
                                (void)
                                ;de lo contrario
                                (begin
                                  ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m4 CANTIDAD) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                                  ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m4 CANTIDAD) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m4 CANTIDAD) 1)))
                                  );fin begin
                                );fin if
        
                            (if (= (remainder CANTIDAD 2) 0)
                                (begin
                                  ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m4 (/ CANTIDAD 2)) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                                  ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m4 (/ CANTIDAD 2)) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m4 (/ CANTIDAD 2)) 1)))
                                  );fin begin
                                ;de lo contrario
                                (begin
                                  ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m4 (truncate (/ CANTIDAD 2))) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                                  ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m4 (truncate (/ CANTIDAD 2))) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m4 (truncate (/ CANTIDAD 2))) 1)))
                                  );fin begin
                                );fin if
                            );fin begin
                          
                          ;de lo contrario
                          (begin        
                            ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                            ((draw-string plano) (make-posn (+ 340 [/ [* 335 (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)) )

                            (if (= (vector-ref (vector-ref m4 (- CANTIDAD 1)) 1) 0)
                                (void)
                                ;de lo contrario
                                (begin
                                  ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m4 CANTIDAD) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                                  ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m4 CANTIDAD) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m4 CANTIDAD) 1)))
                                  );fin begin
                                );fin if
        
                            (if (= (remainder CANTIDAD 2) 0)
                                (begin
                                  ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m4 (/ CANTIDAD 2)) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                                  ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m4 (/ CANTIDAD 2)) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m4 (/ CANTIDAD 2)) 1)))
                                  );fin begin
                                ;de lo contrario
                                (begin
                                  ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m4 (truncate (/ CANTIDAD 2))) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                                  ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m4 (truncate (/ CANTIDAD 2))) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m4 (truncate (/ CANTIDAD 2))) 1)))
                                  );fin begin
                                );fin if

                            (if (= (remainder [truncate (/ CANTIDAD 2)] 2) 0)
                                (if (= [/ [* 335 (vector-ref (vector-ref m4 (/ (truncate (/ CANTIDAD 2)) 2)) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)] 1)
                                    (begin
                                      ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m4 (+ 2 (/ (truncate (/ CANTIDAD 2)) 2))) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                                      ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m4 (+ 2 (/ (truncate (/ CANTIDAD 2)) 2))) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m4 (+ 1 (/ (truncate (/ CANTIDAD 2)) 2))) 1)))
                                      );fin begin
                                    ;de lo contrario
                                    (void)
                                    );fin if
                                ;De lo contrario
            
                                (if (= (truncate (/ (truncate (/ CANTIDAD 2)) 2)) 1)
                                    (begin
                                      ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m4 (+ 1 (truncate (/ (truncate (/ CANTIDAD 2)) 2)))) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                                      ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m4 (+ 1 (truncate (/ (truncate (/ CANTIDAD 2)) 2)))) 1)] (vector-ref (vector-ref m4 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m4 (+ 1 (truncate (/ (truncate (/ CANTIDAD 2)) 2)))) 1)))
                                      );fin begin
                                    ;de lo contrario
                                    (void)
                                    );fin if
                                );fin if
        
                            );fin begin
                          );fin if
                      );fin if
                  );fin if
              );fin if
          ;de lo contrario
          (poner2 (+ 1 CANTIDAD) (+ 1 Y1))
          );fin if
      );fin if
  );fin definicion poner
(poner2 0 1)

;--------------------------------------------------- NEGATIVOS -------------------------------------------------------

(define (numeroma3 Y Y1 NMA)
 
  (if (equal? (vector-ref (vector-ref m3 Y1) 1) #\0)
      (void)
      
      ;de lo contrario
      (if (equal? (vector-ref (vector-ref m3 Y) 1) #\N)
          (numeroma3 (+ 1 Y) Y1 NMA)
      
          ;de lo contrario
          (if (equal? (vector-ref (vector-ref m3 Y) 1) #\0)
              (if (= NMA 0)
                  (vector-set! (vector-ref m5 Y1) 1 #\0)

                  ;De lo contrario
                  (begin
                    (vector-set! (vector-ref m5 Y1) 0 NMA)
                    (numeroma3 1 (+ 1 Y1) 0)
                    );fin begin
                  );fin if
              ;de lo contrario
              (if (and [> (vector-ref (vector-ref m3 Y) 1) (vector-ref (vector-ref m5 (- Y1 1)) 0)] [< (vector-ref (vector-ref m3 Y) 1) NMA] )
                  (numeroma3 (+ 1 Y) Y1 (vector-ref (vector-ref m3 Y) 1))

                  ;de lo contrario          
                  (numeroma3 (+ 1 Y) Y1 NMA)
                  );fin if
              );fin if
          );fin if
      );fin if          
  );fin definicion numeroma3

(numeroma3 1 1 (vector-ref (vector-ref m3 1) 1))

(define (numeroma4 Y Y1 NMA)
  (if (equal? (vector-ref (vector-ref m3 Y1) 0) #\0)
      (void)
      
      ;de lo contrario
      (if (equal? (vector-ref (vector-ref m3 Y) 0) #\N)
          (numeroma4 (+ 1 Y) Y1 NMA)
      
          ;de lo contrario
          (if (equal? (vector-ref (vector-ref m3 Y) 0) #\0)
              (if (= NMA 0)
                  (vector-set! (vector-ref m5 Y1) 1 #\0)
                     
                  ;De lo contrario
                  (begin
                    (vector-set! (vector-ref m5 Y1) 1 NMA)
                    (numeroma4 1 (+ 1 Y1) 0)
                    );fin begin
                  );fin if
      
              ;de lo contrario
              (if (and [> (vector-ref (vector-ref m3 Y) 0) (vector-ref (vector-ref m5 (- Y1 1)) 1)] [< (vector-ref (vector-ref m3 Y) 0) NMA] )
                  (numeroma4 (+ 1 Y) Y1 (vector-ref (vector-ref m3 Y) 0))

                  ;de lo contrario          
                  (numeroma4 (+ 1 Y) Y1 NMA)
                  );fin if
              );fin if
          );fin if
      );fin if
  );fin definicion numeroma4

(numeroma4 1 1 (vector-ref (vector-ref m3 1) 0))

(define (poner3 CANTIDAD Y1)
  (if (> (vector-ref (vector-ref m5 1) 0) 0)
      (void)

      ;de lo contrario
      (if (equal? (vector-ref (vector-ref m5 Y1) 0) #\0)
          (if (= CANTIDAD 0)
              (void)

              ;de lo contrario
              
              (if (= CANTIDAD 1)
                  (begin        
                    ((draw-string plano) (make-posn 350 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                    ((draw-string plano) (make-posn 355 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)) )
                    );fin begin

                  ;de lo contrario
                  (if (= CANTIDAD 2)
                      (begin        
                        ((draw-string plano) (make-posn 350 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                        ((draw-string plano) (make-posn 355 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)) )
                        (if (= (remainder CANTIDAD 2) 0)
                            (begin
                              ((draw-string plano) (make-posn 350 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 CANTIDAD) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                              ((draw-string plano) (make-posn 355 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 CANTIDAD) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m5 (/ CANTIDAD 2)) 0)))
                              );fin begin
                            ;de lo contrario
                            (begin
                              ((draw-string plano) (make-posn 350 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                              ((draw-string plano) (make-posn 355 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 0)))
                              );fin begin
                            );fin if
                        );fin begin

                      ;de lo contrario
                      (if (= CANTIDAD 3)
                          (begin        
                            ((draw-string plano) (make-posn 350 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                            ((draw-string plano) (make-posn 355 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)) )
                            (if (= (remainder CANTIDAD 2) 0)
                                (begin
                                  ((draw-string plano) (make-posn 350 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                                  ((draw-string plano) (make-posn 355 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m5 (/ CANTIDAD 2)) 0)))
                                  );fin begin
                                ;de lo contrario
                                (begin
                                  ((draw-string plano) (make-posn 350 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                                  ((draw-string plano) (make-posn 355 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 0)))
                                  );fin begin
                                );fin if
                            (if (= (remainder CANTIDAD 2) 0)
                                (begin
                                  ((draw-string plano) (make-posn 350 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (/ CANTIDAD 2)) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                                  ((draw-string plano) (make-posn 355 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (/ CANTIDAD 2)) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m5 (/ CANTIDAD 2)) 0)))
                                  );fin begin
                                ;de lo contrario
                                (begin
                                  ((draw-string plano) (make-posn 350 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                                  ((draw-string plano) (make-posn 355 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 0)))
                                  );fin begin
                                );fin if
                            );fin begin
                                               
                          ;de lo contrario
                          (begin        
                            ((draw-string plano) (make-posn 350 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                            ((draw-string plano) (make-posn 355 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)) )
        
                            (if (= (remainder CANTIDAD 2) 0)
                                (begin
                                  ((draw-string plano) (make-posn 350 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (/ CANTIDAD 2)) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                                  ((draw-string plano) (make-posn 355 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (/ CANTIDAD 2)) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m5 (/ CANTIDAD 2)) 0)))
                                  );fin begin
                                ;de lo contrario
                                (begin
                                  ((draw-string plano) (make-posn 350 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                                  ((draw-string plano) (make-posn 355 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 0)))
                                  );fin begin
                                );fin if

                            (if (= (remainder CANTIDAD 2) 0)
                                (begin
                                  ((draw-string plano) (make-posn 350 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                                  ((draw-string plano) (make-posn 355 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 0)))
                                  );fin begin
                                ;de lo contrario
                                (begin
                                  ((draw-string plano) (make-posn 350 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                                  ((draw-string plano) (make-posn 355 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 0)))
                                  );fin begin
                                );fin if

                            (if (= (remainder [truncate (/ CANTIDAD 2)] 2) 0)
                                (if (= [/ [* 335 (vector-ref (vector-ref m5 (/ (truncate (/ CANTIDAD 2)) 2)) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)] 1)
                                    (begin
                                      ((draw-string plano) (make-posn 350 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (+ 1 (/ (truncate (/ CANTIDAD 2)) 2))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                                      ((draw-string plano) (make-posn 355 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (+ 1 (/ (truncate (/ CANTIDAD 2)) 2))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m5 (+ 1 (/ (truncate (/ CANTIDAD 2)) 2))) 0)))
                                      );fin begin
                                    ;de lo contrario
                                    (void)
                                    );fin if
                                ;De lo contrario
            
                                (if (= (truncate (/ (truncate (/ CANTIDAD 2)) 2)) 1)
                                    (begin
                                      ((draw-string plano) (make-posn 350 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (+ 1 (truncate (/ (truncate (/ CANTIDAD 2)) 2)))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) "-")
                                      ((draw-string plano) (make-posn 355 (+ 350 [/ [* 335 (vector-ref (vector-ref m5 (+ 1 (truncate (/ (truncate (/ CANTIDAD 2)) 2)))) 0)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 0)])) (~a (vector-ref (vector-ref m5 (+ 1 (truncate (/ (truncate (/ CANTIDAD 2)) 2)))) 0)))
                                      );fin begin
                                    ;de lo contrario
                                    (void)
                                    );fin if
                                );fin if
        
                            );fin begin
                          );fin if
                      );fin if
                  );fin if
              );fin if
          ;de lo contrario
          (poner3 (+ 1 CANTIDAD) (+ 1 Y1))
          );fin if
      );fin if
  );fin definicion poner
(poner3 0 1)

(define (poner4 CANTIDAD Y1)
  (if (equal? (vector-ref (vector-ref m5 1) 1) #\0)
      (void)

      ;de lo contrario
      (if (equal? (vector-ref (vector-ref m5 Y1) 1) #\0)
          (if (= CANTIDAD 0)
              (void)

              ;de lo contrario
              (if (= CANTIDAD 1)
                  (begin        
                    ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                    ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)) )
                    );fin begin

                  ;de lo contrario
                  (if (= CANTIDAD 2)
                      (begin        
                        ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                        ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)) )
                        (if (= (vector-ref (vector-ref m5 (- CANTIDAD 1)) 1) 0)
                            (void)
                            ;de lo contrario
                            (begin
                              ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 CANTIDAD) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                              ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 CANTIDAD) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m5 CANTIDAD) 1)))
                              );fin begin
                            );fin if
                        );fin begin

                      ;de lo contrario
                      (if (= CANTIDAD 3)
                          (begin        
                            ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                            ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)) )
                            (if (= (vector-ref (vector-ref m5 (- CANTIDAD 1)) 1) 0)
                                (void)
                                ;de lo contrario
                                (begin
                                  ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 CANTIDAD) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                                  ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 CANTIDAD) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m5 CANTIDAD) 1)))
                                  );fin begin
                                );fin if
                            (if (= (remainder CANTIDAD 2) 0)
                                (begin
                                  ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 (/ CANTIDAD 2)) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                                  ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 (/ CANTIDAD 2)) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m5 (/ CANTIDAD 2)) 1)))
                                  );fin begin
                                ;de lo contrario
                                (begin
                                  ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                                  ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 1)))
                                  );fin begin
                                );fin if
                            );fin begin
                           
                          ;de lo contrario
                          (begin        
                            ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                            ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)) )

                            (if (= (vector-ref (vector-ref m5 (- CANTIDAD 1)) 1) 0)
                                (void)
                                ;de lo contrario
                                (begin
                                  ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 CANTIDAD) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                                  ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 CANTIDAD) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m5 CANTIDAD) 1)))
                                  );fin begin
                                );fin if
        
                            (if (= (remainder CANTIDAD 2) 0)
                                (begin
                                  ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 (/ CANTIDAD 2)) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                                  ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 (/ CANTIDAD 2)) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m5 (/ CANTIDAD 2)) 1)))
                                  );fin begin
                                ;de lo contrario
                                (begin
                                  ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                                  ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m5 (truncate (/ CANTIDAD 2))) 1)))
                                  );fin begin
                                );fin if

                            (if (= (remainder [truncate (/ CANTIDAD 2)] 2) 0)
                                (if (= [/ [* 335 (vector-ref (vector-ref m5 (/ (truncate (/ CANTIDAD 2)) 2)) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)] 1)
                                    (begin
                                      ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 (+ 1 (/ (truncate (/ CANTIDAD 2)) 2))) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                                      ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 (+ 1 (/ (truncate (/ CANTIDAD 2)) 2))) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m5 (+ 1 (/ (truncate (/ CANTIDAD 2)) 2))) 1)))
                                      );fin begin
                                    ;de lo contrario
                                    (void)
                                    );fin if
                                ;De lo contrario
            
                                (if (= (truncate (/ (truncate (/ CANTIDAD 2)) 2)) 1)
                                    (begin
                                      ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 (+ 1 (truncate (/ (truncate (/ CANTIDAD 2)) 2)))) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 350) "|")
                                      ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m5 (+ 1 (truncate (/ (truncate (/ CANTIDAD 2)) 2)))) 1)] (vector-ref (vector-ref m5 (+ 1 (- CANTIDAD CANTIDAD))) 1)]) 370) (~a (vector-ref (vector-ref m5 (+ 1 (truncate (/ (truncate (/ CANTIDAD 2)) 2)))) 1)))
                                      );fin begin
                                    ;de lo contrario
                                    (void)
                                    );fin if
                                );fin if

                            );fin begin
                          );fin if
                      );fin if
                  );fin if
              );fin if
          ;de lo contrario
          (poner4 (+ 1 CANTIDAD) (+ 1 Y1))
          );fin if
      );fin if
  );fin definicion poner
(poner4 0 1)

(define (grafica CASO Y POSICIONX POSICIONY)
  (if (= CASO 1)
      
      (if (equal? [vector-ref (vector-ref m3 Y) 1] #\N)
          (grafica 1 (+ 1 Y) 0 0)
          (if (equal? [vector-ref (vector-ref m3 Y) 0] #\0)
              (void)
            (if(and(=[vector-ref (vector-ref m3 Y) 0]0)(=[vector-ref (vector-ref m3 Y) 1]0))
         (grafica 2 (+ 2 Y) (- 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 0)] (vector-ref (vector-ref m5 1) 1)]) (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m5 1) 0)]))
              ;de lo contrario
              (if (and (< [vector-ref (vector-ref m3 Y) 0] 0) (< [vector-ref (vector-ref m3 Y) 1] 0))
                  (begin
                    ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 0)] (vector-ref (vector-ref m5 1) 1)]) (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m5 1) 0)])) "x")
                    (grafica 2 (+ 1 Y) (- 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 0)] (vector-ref (vector-ref m5 1) 1)]) (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m5 1) 0)]))
                    );fin begin

                  ;De lo contrario
                  (if (and (< [vector-ref (vector-ref m3 Y) 0] 0) (> [vector-ref (vector-ref m3 Y) 1] 0))
                      (begin
                        ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 0)] (vector-ref (vector-ref m5 1) 1)]) (- 350 (/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m4 1) 0)))) "x")
                        (grafica 2 (+ 1 Y) (- 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 0)] (vector-ref (vector-ref m5 1) 1)]) (- 350 (/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m4 1) 0))))
                        );fin begin
              
                      ;De lo contrario
                      (if (and (> [vector-ref (vector-ref m3 Y) 0] 0) (> [vector-ref (vector-ref m3 Y) 1] 0))
                          (begin
                            ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 0)] (vector-ref (vector-ref m4 1) 1)]) (- 350 (/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m4 1) 0)))) "x")
                            (grafica 2 (+ 1 Y) (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 0)] (vector-ref (vector-ref m4 1) 1)]) (- 350 (/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m4 1) 0))))
                            );fin begin
                  
                          ;De lo contrario
                          (if (and (> [vector-ref (vector-ref m3 Y) 0] 0) (< [vector-ref (vector-ref m3 Y) 1] 0))
                              (begin
                                ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 0)] (vector-ref (vector-ref m4 1) 1)]) (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m5 1) 0)])) "x")
                                (grafica 2 (+ 1 Y) (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 0)] (vector-ref (vector-ref m4 1) 1)]) (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m5 1) 0)]))
                                );fin begin
                      
                              ;de lo contrario
                              (if (and (= [vector-ref (vector-ref m3 Y) 0] 0) (< [vector-ref (vector-ref m3 Y) 1] 0))
                                  (begin
                                    ((draw-string plano) (make-posn 350 (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m5 1) 0)])) "x")
                                    (grafica 2 (+ 1 Y) 350 (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m5 1) 0)]))
                                    );fin begin
                      
                                  ;de lo contrario
                                  (if (and (= [vector-ref (vector-ref m3 Y) 0] 0) (> [vector-ref (vector-ref m3 Y) 1] 0))
                                      (begin
                                        ((draw-string plano) (make-posn 350 (- 350 (/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m4 1) 0)))) "x")
                                        (grafica 2 (+ 1 Y) 350 (- 350 (/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m4 1) 0))))
                                        );fin begin
                      
                                      ;de lo contrario
                                      (if (and (< [vector-ref (vector-ref m3 Y) 0] 0) (= [vector-ref (vector-ref m3 Y) 1] 0))
                                          (begin
                                            ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 350)] (vector-ref (vector-ref m5 1) 1)]) 350) "x")
                                            (grafica 2 (+ 1 Y) (- 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 350)] (vector-ref (vector-ref m5 1) 1)]) 350)
                                            );fin begin
                      
                                          ;de lo contrario
                                          (if (and (> [vector-ref (vector-ref m3 Y) 0] 0) (= [vector-ref (vector-ref m3 Y) 1] 0))
                                              (begin
                                                ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 350)] (vector-ref (vector-ref m4 1) 1)]) 350) "x")
                                                (grafica 2 (+ 1 Y) (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 350)] (vector-ref (vector-ref m4 1) 1)]) 350)
                                                );fin begin
                      
                                              ;de lo contrario
                                              (if (and (= [vector-ref (vector-ref m3 Y) 0] 0) (= [vector-ref (vector-ref m3 Y) 1] 0))
                                              (begin
                                                ((draw-string plano) (make-posn 350 350) "x")
                                                (grafica 2 (+ 1 Y) 350 350)
                                                );fin begin
                      
                                              ;de lo contrario
                                              (void)
                                              );fin if
                                              );fin if
                                          );fin if
                                      );fin if
                                  );fin if
                              );fin if         
                          );fin if         
                      );fin if        
                  );fin if
              )
              );fin if
          );fin if

      ;de lo contrario
      
      (if (equal? [vector-ref (vector-ref m3 Y) 1] #\N)
          (grafica 1 (+ 1 Y) 0 0)
          (if (equal? [vector-ref (vector-ref m3 Y) 0] #\0)
              (void)
      (if(and(=[vector-ref (vector-ref m3 Y) 0]0)(=[vector-ref (vector-ref m3 Y) 1]0))
         (grafica 2 (+ 2 Y) (- 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 0)] (vector-ref (vector-ref m5 1) 1)]) (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m5 1) 0)]))
              
              ;de lo contrario
              (if (and (< [vector-ref (vector-ref m3 Y) 0] 0) (< [vector-ref (vector-ref m3 Y) 1] 0))
                  (begin
                    ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 0)] (vector-ref (vector-ref m5 1) 1)]) (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m5 1) 0)])) "x")
                    ((draw-line plano) (make-posn POSICIONX POSICIONY) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 0)] (vector-ref (vector-ref m5 1) 1)]) (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m5 1) 0)])) "RED")
                    (grafica 2 (+ 1 Y) (- 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 0)] (vector-ref (vector-ref m5 1) 1)]) (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m5 1) 0)]))
                    );fin begin

                  ;De lo contrario
                  (if (and (< [vector-ref (vector-ref m3 Y) 0] 0) (> [vector-ref (vector-ref m3 Y) 1] 0))
                      (begin
                        ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 0)] (vector-ref (vector-ref m5 1) 1)]) (- 350 (/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m4 1) 0)))) "x")
                        ((draw-line plano) (make-posn POSICIONX POSICIONY) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 0)] (vector-ref (vector-ref m5 1) 1)]) (- 350 (/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m4 1) 0)))) "RED")
                        (grafica 2 (+ 1 Y) (- 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 0)] (vector-ref (vector-ref m5 1) 1)]) (- 350 (/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m4 1) 0))))
                        );fin begin
              
                      ;De lo contrario
                      (if (and (> [vector-ref (vector-ref m3 Y) 0] 0) (> [vector-ref (vector-ref m3 Y) 1] 0))
                          (begin
                            ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 0)] (vector-ref (vector-ref m4 1) 1)]) (- 350 (/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m4 1) 0)))) "x")
                            ((draw-line plano) (make-posn POSICIONX POSICIONY) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 0)] (vector-ref (vector-ref m4 1) 1)]) (- 350 (/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m4 1) 0)))) "RED")
                            (grafica 2 (+ 1 Y) (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 0)] (vector-ref (vector-ref m4 1) 1)]) (- 350 (/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m4 1) 0))))
                            );fin begin
                  
                          ;De lo contrario
                          (if (and (> [vector-ref (vector-ref m3 Y) 0] 0) (< [vector-ref (vector-ref m3 Y) 1] 0))
                              (begin
                                ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 0)] (vector-ref (vector-ref m4 1) 1)]) (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m5 1) 0)])) "x")
                                ((draw-line plano) (make-posn POSICIONX POSICIONY) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 0)] (vector-ref (vector-ref m4 1) 1)]) (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m5 1) 0)])) "RED")
                                (grafica 2 (+ 1 Y) (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 0)] (vector-ref (vector-ref m4 1) 1)]) (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m5 1) 0)]))
                                );fin begin
                      
                              ;de lo contrario
                              (if (and (= [vector-ref (vector-ref m3 Y) 0] 0) (< [vector-ref (vector-ref m3 Y) 1] 0))
                                  (begin
                                    ((draw-string plano) (make-posn 350 (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m5 1) 0)])) "x")
                                    ((draw-line plano) (make-posn POSICIONX POSICIONY) (make-posn 350 (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m5 1) 0)])) "RED")
                                    (grafica 2 (+ 1 Y) 350 (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m5 1) 0)]))
                                    );fin begin
                      
                                  ;de lo contrario
                                  (if (and (= [vector-ref (vector-ref m3 Y) 0] 0) (> [vector-ref (vector-ref m3 Y) 1] 0))
                                      (begin
                                        ((draw-string plano) (make-posn 350 (- 350 (/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m4 1) 0)))) "x")
                                        ((draw-line plano) (make-posn POSICIONX POSICIONY) (make-posn 350 (- 350 (/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m4 1) 0)))) "RED")
                                        (grafica 2 (+ 1 Y) 350 (- 350 (/ [* 335 (vector-ref (vector-ref m3 Y) 1)] (vector-ref (vector-ref m4 1) 0))))
                                        );fin begin
                      
                                      ;de lo contrario
                                      (if (and (< [vector-ref (vector-ref m3 Y) 0] 0) (= [vector-ref (vector-ref m3 Y) 1] 0))
                                          (begin
                                            ((draw-string plano) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 350)] (vector-ref (vector-ref m5 1) 1)]) 350) "x")
                                            ((draw-line plano) (make-posn POSICIONX POSICIONY) (make-posn (- 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 350)] (vector-ref (vector-ref m5 1) 1)]) 0) "RED")
                                            (grafica 2 (+ 1 Y) (- 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 350)] (vector-ref (vector-ref m5 1) 1)]) 350)
                                            );fin begin
                      
                                          ;de lo contrario
                                          (if (and (> [vector-ref (vector-ref m3 Y) 0] 0) (= [vector-ref (vector-ref m3 Y) 1] 0))
                                              (begin
                                                ((draw-string plano) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 350)] (vector-ref (vector-ref m4 1) 1)]) 350) "x")
                                                ((draw-line plano) (make-posn POSICIONX POSICIONY) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 350)] (vector-ref (vector-ref m4 1) 1)]) 0) "RED")
                                                (grafica 2 (+ 1 Y) (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 350)] (vector-ref (vector-ref m4 1) 1)]) 350)
                                                );fin begin
                      
                                              ;de lo contrario
                                              (if (and (= [vector-ref (vector-ref m3 Y) 0] 0) (= [vector-ref (vector-ref m3 Y) 1] 0))
                                                  (begin
                                                    ((draw-string plano) (make-posn 350 350) "x")
                                                    ((draw-line plano) (make-posn POSICIONX POSICIONY) (make-posn (+ 350 [/ [* 335 (vector-ref (vector-ref m3 Y) 350)] (vector-ref (vector-ref m4 1) 1)]) 0) "RED")
                                                    (grafica 2 (+ 1 Y) 350 350)
                                                    );fin begin
                      
                                                  ;de lo contrario
                                                  (void)
                                                  );fin if
                                              );fin if
                                          );fin if
                                      );fin if
                                  );fin if
                              );fin if         
                          );fin if         
                      );fin if        
                  );fin if
              );fin if
          )
          );fin if
      );fin if
  );fin definicion grafica
(grafica 1 1 0 0)