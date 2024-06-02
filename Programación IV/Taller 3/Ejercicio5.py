'''
Para la siguiente lista:
Lista=[1,1991, “taller”,200,3,”programación”,700, “utp”, “POO”]
Implemente uno o varios métodos para hacer:
     La lista inicial debe quedar guardada en un archivo
     A partir de la lista inicial se debe guardar en un archivo una
    lista con los números enteros y en otro archivo guardar la
    lista con las cadenas.
     En un ultimo archivo vamos a guardar una lista donde se
    reemplacen los números impares con la palabra:
    “reemplazo”
     Al final debe crear un método donde se imprima solo la
    mitad de la lista.
'''
# Hecho por Steven Grisales López - 1034289634
from io import *

class Lista():
    # Atributos.
    def __init__(self, lista):
        self.lista = lista

    # Métodos.
    def guardar_lista_inicial(self):
        with open(r"Archivos\Inicial_punto5.txt","w") as archivo:
            archivo.write(f"La lista inicial es: {self.lista}." + "\n")
            
        print(f"La lista inicial es: {self.lista}.")

    def guardar_enteros(self):
        lista_enteros = [] 
        
        for i in range(len(self.lista)):
            if (type(self.lista[i]) == int): # Si el elemento es un número entero.
                lista_enteros.append(self.lista[i]) # Se agrega el elemento a la lista de enteros.
    
        with open(r"Archivos\Enteros_punto5.txt","w") as archivo:
            archivo.write(f"La lista de solo enteros es: {lista_enteros}." + "\n")
            
        print(f"La lista de solo enteros es: {lista_enteros}.")

    def guardar_cadenas(self):
        lista_cadenas = []

        for i in range(len(self.lista)):
            if (type(self.lista[i]) == str): # Si el elemento es una cadena.
                lista_cadenas.append(self.lista[i]) # Se agrega el elemento a la lista de cadenas.

        with open(r"Archivos\Cadenas_punto5.txt","w") as archivo:
            archivo.write(f"La lista de solo cadenas es: {lista_cadenas}." + "\n")
            
        print(f"La lista de solo cadenas es: {lista_cadenas}.")

    def impares_reemplazo(self):
        for i in range(len(self.lista)): # Se recorre la lista.
            # Si el elemento es un número impar, se reemplaza por "reemplazo".
            if (type(self.lista[i]) == int and self.lista[i] % 2 != 0): 
                self.lista[i] = "reemplazo"
        
        with open(r"Archivos\Impares_punto5.txt","w") as archivo: 
            archivo.write(f"La lista con impares reemplazados es: {self.lista}." + "\n")
            
        print(f"La lista con impares reemplazados es: {self.lista}.")

    def mitad_lista(self):
        mitad = len(self.lista) // 2 # // Obtiene la división entera redondeando hacia abajo.
        print(f"La mitad de la lista es: {self.lista[:mitad]}") # :mitad imprime desde el inicio hasta la mitad de la lista.

lista = [1, 1991, "taller", 200, 3, "programación", 700, "utp", "POO"]
Punto5 = Lista(lista)
Punto5.guardar_lista_inicial()
Punto5.guardar_enteros()
Punto5.guardar_cadenas()
Punto5.impares_reemplazo()    