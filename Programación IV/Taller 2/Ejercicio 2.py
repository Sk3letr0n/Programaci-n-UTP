'''
2. Realice un programa que recorra una lista llena de los objetos usuario que
quieran, luego van a contar la cantidad que un usuario aparezca en la lista y
luego debe decir si aparece una cantidad par o impar de veces.
Al diseñar las clases usted debe considerar los atributos que crea
necesarios.
Input: [medico, enfermera, auxiliar, medico, auxiliar]
Elemento buscado: medico
Output: como el medico esta dos veces entonces la cantidad es par
'''
# Hecho por: Steven Grisales López - 1034289634
from io import *

class Usuario:

    lista = []

    def LlenarLista(self):
        Num = int(input("Ingrese la cantidad de usuarios que desea agregar: "))
        print("")
        
        for i in range(Num):
            print(f"Ingrese los datos del usuario #{i + 1}. ") # i + 1 para que no empiece en 0
            
            nombre = input("Nombre: ")
            profesion = input("Profesion: ")
            edad = int(input("Edad: "))
            print("")
            self.lista.append([nombre, profesion, edad]) # Agregar los datos a la lista en una sublista

    def mostrarUsuarios(self):
        print(self.lista)
    
    def BuscarProfesion(self):
        archivo = open(r"punto2.txt", "a") # Esta con relative path (Cambiar si no funciona).
        
        archivo.write(f"{self.lista}" + "\n") 
        
        contador = 0
        Buscar = input("Ingrese la profesion que desea buscar: ")
        
        for i in self.lista:
            if i[1] == Buscar: # i[1] es la profesion
                contador += 1 # Contar cuantas veces aparece la profesion
        
        if contador % 2 == 0:   
            print(f"La cantidad de {Buscar} es {contador} entonces {Buscar} es par ")
            archivo.write(f"El elemento buscado fue: {Buscar} y es par" + "\n")
        else:
            print(f"La cantidad de {Buscar} es {contador} entonces {Buscar} es impar ")
            archivo.write(f"El elemento buscado fue: {Buscar} y es impar" + "\n")
            
        archivo.close()

User = Usuario()
User.LlenarLista()
User.BuscarProfesion()