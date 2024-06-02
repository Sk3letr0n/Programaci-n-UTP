'''
Realice un método que ordene una lista de mínimo 15 cadenas empezando
por todas las cadenas pares y luego las impares.
Recuerden que definimos si una cadena es par o impar por la cantidad de
caracteres que tenga, por ejemplo:
“hola” es una cadena par por que se compone de 4 caracteres y “oso” sería
una cadena impar porque tiene tres caracteres.
Si las cadenas tienen la misma cantidad de caracteres no importa cuál va
de primera.
'''
# Hecho por: Steven Grisales López - 1034289634
from io import *

class Cadenas:
    
    lista = []
    
    def llenarLista(self):
        
        for i in range(15): # Se llena la lista con 15 cadenas
            self.lista.append(input(f"Ingrese la cadena {i + 1}: ")) 
            
    print(f"Su lista es: {lista}" + "\n")
    
    def ordenarLista(self):
        pares = []
        impares = []
        ordenada = []
        
        archivo = open(r"punto3.txt", "a") # Esta con relative path (Cambiar si no funciona).
        
        for i in range(len(self.lista)):
            if(len(self.lista[i]) % 2 == 0): # Si la cadena es par
                pares.append(self.lista[i])
            else:
                impares.append(self.lista[i])
        
        pares.sort()
        impares.sort()
        ordenada = pares + impares
        
        archivo.write(f"{ordenada}" + "\n")
        archivo.close()

paroimpar = Cadenas()
paroimpar.llenarLista()
paroimpar.ordenarLista()