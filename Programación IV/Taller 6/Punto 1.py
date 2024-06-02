'''
1. Realice un programa para calcular diferentes áreas al menos 4 áreas de
figuras trigonométricas haciendo uso de clases y herencia se puede realizar
el modelamiento, deben encapsular todos los atributos y métodos, cuando
diseñen el set de cada atributo deben tener en cuenta dentro de este
método set que solo se deben ingresar números positivos.
'''
# Hecho por: Steven Grisales López - 1034289634

import math

class FiguraTrigonometrica:
    def __init__(self):
        pass
    
    def calcular_area(self):
        pass

class Circulo(FiguraTrigonometrica):
    def __init__(self, radio):
        super().__init__()
        self.__radio = 0
        self.set_radio(radio)
    
    def set_radio(self, radio):
        if radio > 0:
            self.__radio = radio
        else:
            print("El radio debe ser un número positivo.")
    
    def calcular_area(self):
        return math.pi * self.__radio ** 2

class Triangulo(FiguraTrigonometrica):
    def __init__(self, base, altura):
        super().__init__()
        self.__base = 0
        self.__altura = 0
        self.set_base(base)
        self.set_altura(altura)
    
    def set_base(self, base):
        if base > 0:
            self.__base = base
        else:
            print("La base debe ser un número positivo.")
    
    def set_altura(self, altura):
        if altura > 0:
            self.__altura = altura
        else:
            print("La altura debe ser un número positivo.")
    
    def calcular_area(self):
        return 0.5 * self.__base * self.__altura

class Cuadrado(FiguraTrigonometrica):
    def __init__(self, lado):
        super().__init__()
        self.__lado = 0
        self.set_lado(lado)
    
    def set_lado(self, lado):
        if lado > 0:
            self.__lado = lado
        else:
            print("El lado debe ser un número positivo.")
    
    def calcular_area(self):
        return self.__lado ** 2

class Rectangulo(FiguraTrigonometrica):
    def __init__(self, base, altura):
        super().__init__()
        self.__base = 0
        self.__altura = 0
        self.set_base(base)
        self.set_altura(altura)
    
    def set_base(self, base):
        if base > 0:
            self.__base = base
        else:
            print("La base debe ser un número positivo.")
    
    def set_altura(self, altura):
        if altura > 0:
            self.__altura = altura
        else:
            print("La altura debe ser un número positivo.")
    
    def calcular_area(self):
        return self.__base * self.__altura

# Ejemplo de uso
circulo = Circulo(5)
print("Área del círculo:", circulo.calcular_area())

triangulo = Triangulo(6, 8)
print("Área del triángulo:", triangulo.calcular_area())

cuadrado = Cuadrado(4)
print("Área del cuadrado:", cuadrado.calcular_area())

rectangulo = Rectangulo(5, 10)
print("Área del rectángulo:", rectangulo.calcular_area())
