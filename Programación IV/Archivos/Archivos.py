from io import *

nombre = "Luis"
edad = "6"

archivo = open(r"desktop\ejemplo.txt", "w")

archivo.write(f"\n nombre: {nombre}  edad: {edad}")

lectura = archivo.read() # Primero toca cerrar el archivo antes de pedir que lea o escriba, se hace una acción por apertura.

archivo.close

class ejemplo:
    
    #atributos
    asignatura = "programacion"
    num_horas = 4
    
    def conteo_horas(self):
        pass
    def cantidad_horas(self):
        pass