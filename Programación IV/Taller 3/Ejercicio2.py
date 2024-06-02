'''
Diseñar una clase para crear un objeto rectángulo con sus
respectivos atributos, un método que dibuje el rectángulo con “*”
y otro método que realice alguna fórmula con los datos del
rectángulo.
'''
# Hecho por Steven Grisales López - 1034289634
from io import *

class Rectangulo:
    # Atributos.
    def __init__(self, base, altura):
        self.base = base
        self.altura = altura

    # Métodos.
    def dibujar(self):
        self.altura = int(input("Ingrese la altura: "))
        self.base = int(input("Ingrese la base: "))

        with open(r"Archivos\punto2.txt","a") as archivo:
            archivo.write(f"\nLa altura es {self.altura}, y la base es: {self.base}" + "\n")

        for _ in range(self.altura):
            print("*" * self.base)

            with open(r"Archivos\punto2.txt","a") as archivo:
                archivo.write("*" * self.base + "\n")

    def calcular_formulas(self):
        print(f"El perímetro del rectángulo es: {2 * (self.base + self.altura)}")
        print(f"El área del rectángulo es: {self.base * self.altura}")

        with open(r"Archivos\punto2.txt","a") as archivo:
            archivo.write(f"El perímetro del rectángulo es {2 * (self.base + self.altura)}." + "\n" + f"El área del rectángulo es {self.base * self.altura}." + "\n")

# Prueba de la clase.
rectangulo = Rectangulo(0, 0)
rectangulo.dibujar()
rectangulo.calcular_formulas()