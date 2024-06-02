"""
Implementar el algoritmo de cifrado cesar haciendo uso de POO, archivos y
listas.
Para este algoritmo se deja documentación en la sección de “Parcial I”.
"""
# Hecho por: Steven Grisales López (1034289634) y Luis Felipe Garzón Bonilla (1089931169)
from io import *

def menu():
    opcion = int(input(""" 
                    Ingrese que desea hacer
                    1. Cifrar 
                    2. Descifrar
                    0. Salir 
                    """))
    match opcion:

        case 1:
            mensaje=str(input("Ingrese el mensaje a cifrar: "))
            llave=int(input("Ingrese la llave de cifrado: "))
            cifrador=CifradoCesar(mensaje,llave)
            cifrador.cifrar()
            
        case 2:
            mensaje=str(input("Ingrese el mensaje a descifrar: "))
            llave=int(input("Ingrese la llave de cifrado: "))
            cifrador=CifradoCesar(mensaje,llave)
            cifrador.descifrar()
            
        case 0:
            print(f"Saliendo...")
            
        case _:
            print("Opción inválida, intente de nuevo.")
       
class CifradoCesar():

    def __init__(self, mensaje, llave):
        self.mensaje = mensaje
        self.llave = llave

    def cifrar(self):
        # Se definen los alfabetos en mayúsculas y minúsculas.
        alfabetoMin = "abcdefghijklmnopqrstuvwxyz"
        alfabetoMay = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        MensajeCif = ""

        # Se recorre el mensaje.
        for i in self.mensaje:
            # Si el caracter está en el alfabeto minúsculas.
            if i in alfabetoMin:
                posicion = alfabetoMin.index(i) # Se obtiene la posición del caracter en el alfabeto.
                posicion = (posicion + self.llave) % 26 # Se aplica la fórmula de cifrado.
                MensajeCif = MensajeCif + alfabetoMin[posicion] # Se añade el caracter cifrado al mensaje cifrado.

            # Si el caracter está en el alfabeto mayúsculas.
            else:
                if i in alfabetoMay:
                 posicion = alfabetoMay.index(i) 
                 posicion = (posicion + self.llave) % 26 
                 MensajeCif = MensajeCif + alfabetoMay[posicion] 
                 
                # Si el caracter no está en el alfabeto, se añade tal cual al mensaje cifrado.
                else:
                    MensajeCif = MensajeCif + i 

        print(f"El mensaje cifrado es {MensajeCif}")  
        with open(r"Archivos\Punto5.txt" , "a") as archivo:  
           archivo.write(f"El {self.mensaje} cifrado con llave {self.llave} es {MensajeCif} ")

    # Mismo que cifrar pero operación contraria (resta en vez de suma).
    def descifrar (self):
        # Se definen los alfabetos en mayúsculas y minúsculas.
        alfabetoMin = "abcdefghijklmnopqrstuvwxyz"
        alfabetoMay = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        MensajeDesci = ""

        for i in self.mensaje:
            
            if i in alfabetoMin:
                posicion = alfabetoMin.index(i)
                posicion = (posicion - self.llave) % 26
                MensajeDesci = MensajeDesci + alfabetoMin[posicion]

            else:
                if i in alfabetoMay:
                 posicion = alfabetoMay.index(i)
                 posicion = (posicion - self.llave) % 26
                 MensajeDesci = MensajeDesci + alfabetoMay[posicion]

                else:
                    MensajeDesci = MensajeDesci + i

        print(f"El mensaje descifrado es {MensajeDesci}")
        with open(r"Archivos\Punto5.txt" , "a") as archivo:  
           archivo.write(f"El {self.mensaje} descifrado con llave {self.llave} es {MensajeDesci} ")
            
menu()