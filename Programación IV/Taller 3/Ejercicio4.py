'''
Diseñar una clase para un objeto calculadora científica con sus
respectivos atributos y al menos 12 métodos.
'''
# Hecho por Steven Grisales López - 1034289634
from io import *
import math

def menu():
    while True:
        opcion = int(input('''\nBienvenido a la calculadora científica.
             1. Mostrar Datos.
             2. Sumar. 
             3. Restar. 
             4. Multiplicar. 
             5. Dividir. 
             6. Potencia. 
             7. Raíz cuadrada. 
             8. Raíz cúbica. 
             9. Logaritmo. 
             10. Seno.
             11. Coseno. 
             12. Tangente. 
             13. Factorial. 
             0. Salir. 
             Ingrese una opción: '''))
    
        Calculadora = CalculadoraCientifica("Casio", 50000, "Negra", "Programable", "fx-82MS", 4, "LED", "100GB", 25, "2 años", "Se rasgó", 12)

        match opcion:
            case 1:
                Calculadora.mostrarDatos()
                
                
            case 2:
                a = int(input("\nIngrese el primer número: "))
                b = int(input("Ingrese el segundo número: "))
                print(f"El resultado de la suma es: {Calculadora.sumar(a, b)}" + "\n")
                
                with open(r"Archivos\punto4.txt","a") as archivo:
                    archivo.write(f"El resultado de la suma es: {Calculadora.sumar(a, b)}" + "\n")

            case 3:
                a = int(input("\nIngrese el primer número: "))
                b = int(input("Ingrese el segundo número: "))
                print(f"El resultado es: {Calculadora.restar(a, b)}" + "\n")
                
                with open(r"Archivos\punto4.txt","a") as archivo:
                    archivo.write(f"El resultado de la resta es: {Calculadora.restar(a, b)}" + "\n")

            case 4:
                a = int(input("\nIngrese el primer número: "))
                b = int(input("Ingrese el segundo número: "))
                print(f"El resultado es: {Calculadora.multiplicar(a, b)}" + "\n")
                
                with open(r"Archivos\punto4.txt","a") as archivo:
                    archivo.write(f"El resultado de la multiplicación es: {Calculadora.multiplicar(a, b)}" + "\n")

            case 5:
                a = int(input("\nIngrese el primer número: "))
                b = int(input("Ingrese el segundo número: "))
                print(f"El resultado es: {Calculadora.dividir(a, b)}" + "\n")
                
                with open(r"Archivos\punto4.txt","a") as archivo:
                    archivo.write(f"El resultado de la división es: {Calculadora.dividir(a, b)}" + "\n")

            case 6:
                a = int(input("\nIngrese el primer número: "))
                b = int(input("Ingrese el segundo número: "))
                print(f"El resultado es: {Calculadora.potencia(a, b)}" + "\n")
                
                with open(r"Archivos\punto4.txt","a") as archivo:
                    archivo.write(f"El resultado de la potencia es: {Calculadora.potencia(a, b)}" + "\n")

            case 7:
                a = int(input("\nIngrese el número: "))
                print(f"El resultado es: {Calculadora.raiz_cuadrada(a)}" + "\n")
                
                with open(r"Archivos\punto4.txt","a") as archivo:
                    archivo.write(f"El resultado de la raíz cuadrada es: {Calculadora.raiz_cuadrada(a)}" + "\n")

            case 8:
                a = int(input("\nIngrese el número: "))
                print(f"El resultado es: {Calculadora.raiz_cubica(a)}" + "\n")
                
                with open(r"Archivos\punto4.txt","a") as archivo:
                    archivo.write(f"El resultado de la raíz cúbica es: {Calculadora.raiz_cubica(a)}" + "\n")

            case 9:
                a = int(input("\nIngrese el número: "))
                print(f"El resultado es: {Calculadora.logaritmo(a)}" + "\n")
                
                with open(r"Archivos\punto4.txt","a") as archivo:
                    archivo.write(f"El resultado del logaritmo es: {Calculadora.logaritmo(a)}" + "\n")

            case 10:
                a = int(input("\nIngrese el número: "))
                print(f"El resultado es: {Calculadora.seno(a)}" + "\n")
                
                with open(r"Archivos\punto4.txt","a") as archivo:
                    archivo.write(f"El resultado del seno es: {Calculadora.seno(a)}" + "\n")

            case 11:
                a = int(input("\nIngrese el número: "))
                print(f"El resultado es: {Calculadora.coseno(a)}" + "\n")
                
                with open(r"Archivos\punto4.txt","a") as archivo:
                    archivo.write(f"El resultado del coseno es: {Calculadora.coseno(a)}" + "\n")

            case 12:
                a = int(input("\nIngrese el número: "))
                print(f"El resultado es: {Calculadora.tangente(a)}" + "\n")
                
                with open(r"Archivos\punto4.txt","a") as archivo:
                    archivo.write(f"El resultado de la tangente es: {Calculadora.tangente(a)}" + "\n")

            case 13:
                a = int(input("\nIngrese el número: "))
                print(f"El resultado es: {Calculadora.factorial(a)}" + "\n")
                
                with open(r"Archivos\punto4.txt","a") as archivo:
                    archivo.write(f"El resultado del factorial es: {Calculadora.factorial(a)}" + "\n")
            
            case 0:
                print("\n   Saliendo del programa...")
                exit()
                
            case _:
                print("\nOpción inválida. Por favor, seleccione una opción válida.")
   

class CalculadoraCientifica:

    def __init__(self, marca, precio, color, tipo, modelo, baterias, pantalla, memoria, teclas, garantia, manual, funciones):
        self.marca = marca
        self.precio = precio
        self.color = color
        self.tipo = tipo 
        self.modelo = modelo
        self.baterias = baterias
        self.pantalla = pantalla
        self.memoria = memoria
        self.teclas = teclas
        self.garantia = garantia
        self.manual = manual
        self.funciones = funciones

    def mostrarDatos(self):
        print(f"\nMarca: {self.marca}, Precio: {self.precio}, Color: {self.color}, Tipo: {self.tipo}, Modelo: {self.modelo}, Baterias: {self.baterias}, Pantalla: {self.pantalla}, Memoria: {self.memoria}, Teclas: {self.teclas}, Garantia: {self.garantia}, Manual: {self.garantia}, Funciones: {self.funciones}." + "\n")
        
        with open(r"Archivos\punto4.txt","a") as archivo:
            archivo.write(f"Marca: {self.marca}, Precio: {self.precio}, Color: {self.color}, Tipo: {self.tipo}, Modelo: {self.modelo}, Baterias: {self.baterias}, Pantalla: {self.pantalla}, Memoria: {self.memoria}, Teclas: {self.teclas}, Garantia: {self.garantia}, Manual: {self.garantia}, Funciones: {self.funciones}." + "\n")

    def sumar(self, a, b):
        return a + b

    def restar(self, a, b):
        return a - b

    def multiplicar(self, a, b):
        return a * b

    def dividir(self, a, b):
        return a / b

    def potencia(self, a, b):
        return a ** b

    def raiz_cuadrada(self, a):
        return a ** 0.5

    def raiz_cubica(self, a):
        return a ** (1/3)

    def logaritmo(self, a):
        return math.log(a)

    def seno(self, a):
        return math.sin(a)

    def coseno(self, a):
        return math.cos(a)

    def tangente(self, a):
        return math.tan(a)

    def factorial(self, a):
        return math.factorial(a)
        

menu()