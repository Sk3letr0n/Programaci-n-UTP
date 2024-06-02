# -*- coding: utf-8 -*-
"""
Created on Thu Nov  9 15:12:18 2023

@author: Harry Nicolas G
"""

# Tkinter es una biblioteca estándar de Python para crear interfaces gráficas de usuario (GUI).
# msilib es parte de la biblioteca estándar de Python y se usa para trabajar con instaladores de Windows (MSI).
from msilib.schema import SelfReg # SelfReg es una clase que se usa para manejar la información de registro de un archivo.
from tkinter import * # El asterisco significa que vamos a implementar todo de la biblioteca Tinker
from tkinter import messagebox # Diálogos de mensajes (messagebox)
import random # Generación de números aleatorios (random)
import time # Gestión del tiempo (time)
import tkinter as tk # Simplemente cambio de nombre
from typing import Self # typing es un módulo que proporciona soporte para anotaciones de tipo en Python.

# Se crea la ventana principal (root) y se establecen algunas configuraciones iniciales, como el tamaño, título y la imposibilidad de cambiar el tamaño de la ventana.
root = Tk() # Root es la instancia de la ventana que se va a crear a partir del módulo
frame = Frame(root) # Aquí se crea un Frame, que es un contenedor rectangular en la ventana principal
frame.pack() #Esta instrucción coloca el Frame dentro de la ventana principal. El método
root.title("Buscaminas") # Título de la ventana generada

root.resizable(False, False) # Deshabilita la capacidad de redimensionar la ventana principal en el eje x e y.
frame.config(width=400, height=400) # Tamaño de la ventana

# --------------Variables--------------
bombasCerca = 0 # Lleva un conteo de la cantidad de bombas cercanas a un espacio seleccionado en el juego, se actualiza cada que se selecciona un espacio.
win = False # Es un indicador booleano que se establece en True cuando se cumple la condición de victoria en el juego.
listaBotones = [] # Es una lista que almacena los botones que representan los espacios del juego y se utiliza para controlar su estado y apariencia durante el juego.. 
reset = False # Cuando se reinicia el juego se utiliza para restablecer todas las variables y elementos del juego a su estado inicial.
inicio = False # Se utiliza para activar algunas funciones relacionadas con el tiempo y el inicio del juego.
varSlotPulsado = -1 # Almacena el índice del espacio seleccionado por el jugador. Se usa para identificar qué espacio ha sido seleccionado.
banderasDisponibles = 10 # Lleva un conteo de la cantidad de banderas que el jugador puede colocar en el juego.

# Estas variables se utilizan para medir y registrar el tiempo transcurrido durante el juego.
tiempoFin = 0 
tiempoActual = 0 
tiempoInicio = time.time() 

bandera = False # Es un indicador booleano que se establece en True cuando el jugador elige colocar una bandera en un espacio del juego.
tiempoHabilitado = False #  Indica si la función de conteo de tiempo está habilitada o no.
tomarTiempoFin = 0 # Estas variables están relacionadas con el conteo del tiempo transcurrido durante el juego.
y = 0 # lleva un seguimiento de cuántas veces se ha actualizado el contador de tiempo.

contadorTiempo = Label(frame) # Es una etiqueta (Label) en la interfaz gráfica que muestra el tiempo transcurrido durante el juego.
contadorTiempo.grid(column=1, row=0, columnspan=4) # Posiciona el contador dentro del Frame.

# Esta función se encarga de llevar el tiempo transcurrido desde el inicio del juego.
def tiempo(tiempo1=""):
    global tiempoInicio, tiempoActual, inicio, tomarTiempoFin, tiempoHabilitado, y, tiempo2 # Accede a las variables globales.
    tiempo2 = time.time() # Devuelve el tiempo actual en segundos desde el comienzo del tiempo de referencia.
    if tiempo1 != tiempo2 and tiempoHabilitado == True: # Si el tiempo de inicio es es distinto al actual y el tiempo esta corriendo
        tiempo1 = tiempo2 # Tiempo1 ira constantemente tomando el valor del último tiempo tomado.
        tiempoActual = int(tiempo2 - tiempoInicio) # Calcula el tiempo transcurrido desde el inicio del juego restando el actual con el de inicio
        contadorTiempo.config(text="Tiempo transcurrido: " + str(tiempoActual), font=("Arial 15")) # Actualiza el tiempo transcurrido en lo que va de juego.
    else:
        tiempo1 = tiempo2 # Esto garantiza que, independientemente del flujo de control, tiempo1 siempre se mantenga sincronizado con el tiempo actual.
        y += 1 # Se encarga de llevar un conteo de cuántas veces se ha ejecutado la función.
        if y == 1: 
            tomarTiempoFin = int(tiempo2 - tiempoInicio) # Calcula el tiempo transcurrido cuando acaba la partida.
            print("termino en: ", tomarTiempoFin)
        contadorTiempo.config(text="Tiempo transcurrido: " + str(tomarTiempoFin), font=("Arial 15"))
    contadorTiempo.after(200, tiempo) # Esto crea un ciclo continuo donde la función se ejecuta cada 0.2 segundos para actualizar y mostrar el tiempo transcurrido en la interfaz gráfica.

# Genera una cuadrícula de botones que representarán los espacios del Buscaminas.
def generarBotones():
    global listaBotones # Accede a las variables globales.
    for c in range(81): # Genera los 81 botones del juego 9x9
        # Determinan la posición de cada botón en filas y columnas, dividiendo los 81 botones en 9 columnas y 9 filas. 
        # Se utiliza grid() para colocar cada botón en la ubicación correspondiente dentro del Frame.
        listaBotones.append(Button(frame, width=6, height=3, text=" ", font=("Arial 12 bold"), command=lambda c=c: slotPulsado(c), bg="grey")) #slotPulsado es si se presiona el botón.
        if c >= 0 and c < 9:
            listaBotones[c].grid(column=1, row=c + 1)
        if c >= 9 and c < 18:
            listaBotones[c].grid(column=2, row=c - 8)
        if c >= 18 and c < 27:
            listaBotones[c].grid(column=3, row=c - 17)
        if c >= 27 and c < 36:
            listaBotones[c].grid(column=4, row=c - 26)
        if c >= 36 and c < 45:
            listaBotones[c].grid(column=5, row=c - 35)
        if c >= 45 and c < 54:
            listaBotones[c].grid(column=6, row=c - 44)
        if c >= 54 and c < 63:
            listaBotones[c].grid(column=7, row=c - 53)
        if c >= 63 and c < 72:
            listaBotones[c].grid(column=8, row=c - 62)
        if c >= 72 and c < 81:
            listaBotones[c].grid(column=9, row=c - 71)

# Llama a la función para que genere los botones automáticamente. 
generarBotones()

# ---------------Bombas---------------
# -1 es que no se le ha asignado espacio aún a las bombas.
bomba1 = -1
bomba2 = -1
bomba3 = -1
bomba4 = -1
bomba5 = -1
bomba6 = -1
bomba7 = -1
bomba8 = -1
bomba9 = -1
bomba10 = -1

#  Genera posiciones aleatorias para las bombas en el juego.
def bombasRandom():
    global bomba1, bomba2, bomba3, bomba4, bomba5, bomba6, bomba7, bomba8, bomba9, bomba10 # Accede a las variables globales.
    # Aquí ya cambia ese -1 y le da un valor random dentro del rango de los botones para que las bombas tengan posiciones.
    bomba1 = random.randrange(81)
    bomba2 = random.randrange(81)
    bomba3 = random.randrange(81)
    bomba4 = random.randrange(81)
    bomba5 = random.randrange(81)
    bomba6 = random.randrange(81)
    bomba7 = random.randrange(81)
    bomba8 = random.randrange(81)
    bomba9 = random.randrange(81)
    bomba10 = random.randrange(81)


bombasRandom() # La llama para generar esos espacios automaticamente.

print("Las ubicaciones de las bombas son: ", bomba1, bomba2, bomba3, bomba4, bomba5, bomba6, bomba7, bomba8, bomba9, bomba10) # Esto se ve en consola solo para ver donde estan.

numeroPulsaciones = 0 # Se utiliza para realizar un seguimiento del número de pulsaciones o clics que ha realizado el jugador.
imagenBomba = PhotoImage(file="bomba3.png") # Adjunta la imagen.

# Muestra las bombas cuando el jugador pierde.
def mostrarBombas():
    global imagenBomba # Accede a las variables globales.
    # Muestra la imagen de la bomba en todas las ubicaciones en la que estaban las 10 bombas cuando pierde el jugador.
    listaBotones[bomba1].config(image=imagenBomba, width=64, height=65)
    listaBotones[bomba2].config(image=imagenBomba, width=64, height=65)
    listaBotones[bomba3].config(image=imagenBomba, width=64, height=65)
    listaBotones[bomba4].config(image=imagenBomba, width=64, height=65)
    listaBotones[bomba5].config(image=imagenBomba, width=64, height=65)
    listaBotones[bomba6].config(image=imagenBomba, width=64, height=65)
    listaBotones[bomba7].config(image=imagenBomba, width=64, height=65)
    listaBotones[bomba8].config(image=imagenBomba, width=64, height=65)
    listaBotones[bomba9].config(image=imagenBomba, width=64, height=65)
    listaBotones[bomba10].config(image=imagenBomba, width=64, height=65)

# Maneja la lógica cuando un espacio del juego es seleccionado (pulsado).
def slotPulsado(slot):
    # Accede a las variables globales.
    global varSlotPulsado, bomba1, bomba2, bomba3, bomba4, bomba5, bomba6, bomba7, bomba8, bomba9, bomba10, listaBotones, bombasCerca, numeroPulsaciones, imagenBomba, win, reset, varSlotPulsado, inicio, ponerBandera, bandera, tiempoHabilitado, tomarTiempoFin, contadorTiempo, tiempoFin, tiempo2, tiempoInicio

    numeroPulsaciones += 1 # Aumenta el número de pulsaciones cada que el jugador hace click
    bombasCerca = 0 # Lleva el registro de las bombas que hay cerca de donde se pulsó 
    varSlotPulsado = slot # Representa la celda o espacio en el que el jugador ha realizado una acción (como un clic) en el tablero del Buscaminas.
    tiempoHabilitado = True # Permite que se registre y se muestre el tiempo transcurrido durante el juego. Es utilizada para controlar el inicio, la pausa o el reinicio del contador de tiempo en el juego de Buscaminas.

    if varSlotPulsado == -1:
        # Indica que no se realiza ninguna operación o acción
        pass
    else:
        # Inicia el juego y empieza a correr el tiempo
        inicio = True
        tiempo()

    if win != True: # Si no se ha ganado aún.
        # Si en alguno de los slots de las bombas se presiona un click.
        if slot == bomba1 or slot == bomba2 or slot == bomba3 or slot == bomba4 or slot == bomba5 or slot == bomba6 or slot == bomba7 or slot == bomba8 or slot == bomba9 or slot == bomba10:
            # El jugador procede a colocar una bandera.
            if bandera == True:
               # Se pone la bandera.
               ponerBandera(None)  
            else:
                # Si no se muestran las bombas y se pierde el juego.
                mostrarBombas()
                listaBotones[slot].config(image=imagenBomba, width=64, height=65, bg="#f17070")
                tiempoHabilitado = False # Se deshabilita el tiempo indicando que el juego acabo
                reset = messagebox.askyesno("Game Over", "¿Desea volver a jugar?") # Sale una ventanita con ese mensaje esperando respuesta del jugador.
                gameReset() # Se resetea el juego
        else:
            # Si no se presiono encima de un slot con una bomba se empieza a examinar cuantas bombas hay adyacentes (en los slots con número y en consola con la palabra).
            # Tiene como objetivo contar la cantidad de bombas adyacentes a la celda seleccionada por el jugador en el juego de Buscaminas.
            def check():
                global bombasCerca # Accede a las variables globales
                # Si hay una bomba justo arriba (slot - 1) o abajo (slot + 1).
                # Si hay una bomba a la derecha (slot + 9) o izquierda (slot - 9).
                # Si hay una bomba en las diagonales superiores (slot - 8 y slot + 10) y diagonales inferiores (slot + 8 y slot - 10).
                if slot + 1 == bomba1 or slot + 1 == bomba2 or slot + 1 == bomba3 or slot + 1 == bomba4 or slot + 1 == bomba5 or slot + 1 == bomba6 or slot + 1 == bomba7 or slot + 1 == bomba8 or slot + 1 == bomba9 or slot + 1 == bomba10:
                    bombasCerca += 1
                    print("abajo")
                if slot - 1 == bomba1 or slot - 1 == bomba2 or slot - 1 == bomba3 or slot - 1 == bomba4 or slot - 1 == bomba5 or slot - 1 == bomba6 or slot - 1 == bomba7 or slot - 1 == bomba8 or slot - 1 == bomba9 or slot - 1 == bomba10:
                    bombasCerca += 1
                    print("arriba")
                if slot + 9 == bomba1 or slot + 9 == bomba2 or slot + 9 == bomba3 or slot + 9 == bomba4 or slot + 9 == bomba5 or slot + 9 == bomba6 or slot + 9 == bomba7 or slot + 9 == bomba8 or slot + 9 == bomba9 or slot + 9 == bomba10:
                    bombasCerca += 1
                    print("derecha")
                if slot - 9 == bomba1 or slot - 9 == bomba2 or slot - 9 == bomba3 or slot - 9 == bomba4 or slot - 9 == bomba5 or slot - 9 == bomba6 or slot - 9 == bomba7 or slot - 9 == bomba8 or slot - 9 == bomba9 or slot - 9 == bomba10:
                    bombasCerca += 1
                    print("izquierda")
                if slot - 8 == bomba1 or slot - 8 == bomba2 or slot - 8 == bomba3 or slot - 8 == bomba4 or slot - 8 == bomba5 or slot - 8 == bomba6 or slot - 8 == bomba7 or slot - 8 == bomba8 or slot - 8 == bomba9 or slot - 8 == bomba10:
                    bombasCerca += 1
                    print("abajo a la izquierda")
                if slot + 8 == bomba1 or slot + 8 == bomba2 or slot + 8 == bomba3 or slot + 8 == bomba4 or slot + 8 == bomba5 or slot + 8 == bomba6 or slot + 8 == bomba7 or slot + 8 == bomba8 or slot + 8 == bomba9 or slot + 8 == bomba10:
                    bombasCerca += 1
                    print("arriba a la derecha")
                if slot + 10 == bomba1 or slot + 10 == bomba2 or slot + 10 == bomba3 or slot + 10 == bomba4 or slot + 10 == bomba5 or slot + 10 == bomba6 or slot + 10 == bomba7 or slot + 10 == bomba8 or slot + 10 == bomba9 or slot + 10 == bomba10:
                    bombasCerca += 1
                    print("abajo a la derecha")
                if slot - 10 == bomba1 or slot - 10 == bomba2 or slot - 10 == bomba3 or slot - 10 == bomba4 or slot - 10 == bomba5 or slot - 10 == bomba6 or slot - 10 == bomba7 or slot - 10 == bomba8 or slot - 10 == bomba9 or slot - 10 == bomba10:
                    bombasCerca += 1
                    print("arriba a la izquierda")

            check() # Verifica y actualiza el frame chekeando. 

            # Si no hay bandera.
            if bandera == False:
                # Esto ocurre si el jugador no está usando una bandera en la celda seleccionada.
                # Configura el botón correspondiente a la celda seleccionada para mostrar la cantidad de bombas cercanas como texto en el botón. 
                listaBotones[slot].config(text=bombasCerca, fg="black", font=("Arial 12 bold"))
                # Luego, desactiva el botón y cambia su apariencia a un color de fondo específico .
                listaBotones[slot].config(bg="#aeb0b2", state="disabled") 
            else:
                # Gestiona la colocación de una bandera en la celda seleccionada.
                ponerBandera(None)

            # Verifica si gano el jugador.
            def checkWin():
                global imagenBomba, listaBotones, win, contadorBanderas # Accede a las variables globales.
                # Comprueba si el slot no tiene una bomba y si la cantidad de pulsaciones fue 71 (Los slots sin las 10 bombas).
                if slot != bomba1 and slot != bomba2 and slot != bomba3 and slot != bomba4 and slot != bomba5 and slot != bomba6 and slot != bomba7 and slot != bomba8 and slot != bomba9 and slot != bomba10 and numeroPulsaciones == 71:
                    win = True # Actualiza el estado de ganar.
                    # Formato de texto de Victoria.
                    txtWin1 = Label(frame, width=25, height=2, text="¡  G  A  N  A  S  T  E  !", font=("helvetica 27 bold"), bg="#fe4a4a")
                    txtWin1.grid(row=10, column=1, columnspan=9)
                    frame.config(bg="#fe4a4a") # Cambia el color de fondo del marco principal.
                    contadorBanderas.config(bg="#fe4a4a") # Modifica el color de fondo de un elemento gráfico que muestra la cantidad de banderas disponibles en el juego.
                    contadorTiempo.config(bg="#fe4a4a") #Cambia el color de fondo de otro elemento gráfico que muestra el tiempo transcurrido en el juego.
                    mostrarBombas() # Muestra la ubicación de todas las bombas.

            checkWin()



# -------------Banderas----------
# Activa la opción de colocar banderas en los espacios.
def presionarBandera():
    global bandera # Accede a variables globales.
    bandera = True # Establece que hay una bandera.

# Genera unas imagenes de cierto tipo que representan graficamente las banderas que funcionan como botones.
banderaImg = tk.Button(root, text="Color", bg="blue", fg="red")  
banderaImgSlot = tk.Button(root, text="Color", bg="blue", fg="red")  



bandera_image = None # Indica que se espera que esta variable almacene una imagen que se utilizará en los botones en algún momento

# Coloca una bandera en un espacio o ejecuta la lógica de pulsar un espacio si ya hay una bandera.
def ponerBandera(event):
    global varSlotPulsado, bandera, banderasDisponibles, contadorBanderas, listaBotones, bandera_image # Accede a las variables globales.
    
    # Verifica si hay banderas y si hay banderas disponibles.
    if bandera and banderasDisponibles > 0:
        banderasDisponibles -= 1 # Disminuye la cantidad de banderas disponibles cuando se coloca una.
        contadorBanderas.config(text="Banderas disponibles: " + str(banderasDisponibles)) # Actualiza el texto del contador de banderas disponibles para reflejar el cambio en la cantidad de banderas.

        # Si no contiene una imagen de bandera genera una desde el archivo de la carpeta.
        if bandera_image is None:
            bandera_image = PhotoImage(file="banderaSlot.png")

        # Configura un botón especifico donde muestra la imagen de la bandera
        listaBotones[varSlotPulsado].config(image=bandera_image, width=64, height=65)

        print("Bandera puesta en: ", varSlotPulsado)

    elif not bandera: # Verifica si bandera es falsa. Si es así, se ejecuta.
     
        slotPulsado(varSlotPulsado) # Verifica si se presiona el slot.

    bandera = not bandera # Cambia el estado de la bandera, que se utiliza para alternar entre el modo de colocación de banderas y el modo de selección normal.





contadorBanderas = Label(frame, text="Banderas disponibles: " + str(banderasDisponibles), font=("Arial 15")) # Muestra la cantidad de banderas disponibles.
contadorBanderas.grid(column=6, row=0, columnspan=5) # Este widget se coloca en la interfaz gráfica usando grid() en la fila 0 y las columnas 6 a 10 (spanning de 5 columnas).

banderaImg = PhotoImage(file="bandera.png")
botonBandera = Button(frame, text=" ", image=banderaImg, command=lambda: presionarBandera()) # Botón que muestra la imagen de bandera.
botonBandera.grid(column=5, row=0) # El tamaño de ese botón y en donde esta ubicado.






# Esta función restablece todas las variables y elementos del juego a su estado inicial para reiniciar la partida.
def gameReset():
    global reset, bombasCerca, win, listaBotones, tiempoActual, tiempoInicio, tiempo1, tiempo2, tiempoActual, banderasDisponibles, bandera, y, tomarTiempoFin, tiempoHabilitado
    if reset: # Si se resetea el juego: 
        inicio = False # Indica que el juego no ha empezado.
        bombasCerca = 0 # Reinicia el contador de bombas cercanas.
        win = False # Establece la variable de estado de victoria a Falso.
        listaBotones = [] # Borra la lista de botones del juego.
        # Reasigna las posiciones de las bombas a -1 para reiniciar su ubicación.
        bomba1 = -1
        bomba2 = -1
        bomba3 = -1
        bomba4 = -1
        bomba5 = -1
        bomba6 = -1
        bomba7 = -1
        bomba8 = -1
        bomba9 = -1
        bomba10 = -1
        tomarTiempoFin = 0 # Reinicia el tiempo de finalización.
        y = 0 # Restablece la variable y a 0.
        tiempoActual = 0 # Restablece el tiempo transcurrido a 0.
        tiempoHabilitado = False # Desactiva el tiempo.
        bombasRandom() # Genera nuevas ubicaciones aleatorias para las bombas.
        numeroPulsaciones = 0 # Reinicia el contador de pulsaciones.
        bombasCerca = 0 # Reinicia las bombas cercanas.
        generarBotones() # Vuelve a generar los botones del juego.
        tiempoInicio = time.time() # Reinicia el tiempo de inicio.
        tiempo() # Reinicia el conteo del tiempo.
        banderasDisponibles = 10 # Restablece la cantidad de banderas disponibles a 10.
        contadorBanderas.config(text="Banderas disponibles: " + str(banderasDisponibles)) # Actualiza el texto del contador de banderas disponibles en la interfaz gráfica.
        bandera = False # Desactiva la bandera.
        reset = False # Marca el final del reinicio.
    else:
        root.destroy() # Finaliza la ventana principal del juego, cerrando la aplicación de buscaminas.

root.mainloop() # Es responsable de mantener la ventana abierta y receptiva a las interacciones del usuario hasta que se cierra explícitamente la ventana, 
# momento en el que el bucle se detiene y la aplicación finaliza.