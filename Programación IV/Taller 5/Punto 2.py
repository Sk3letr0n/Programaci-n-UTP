'''
Diseñe y modele un problema de cotidianidad con herencia múltiple,
implementando las siguientes características:
a. Debe tener al menos dos clases principales.
b. Debe tener al menos 5 subclases.
c. Las clases principales deben tener cada una al menos 5 atributos.
d. Entre todas las clases principales y subclases deben diseñar al menos 7
métodos.
e. Se debe crear una lista para almacenar los objetos creados para probar
las clases y subclases.

f. Guarde la información que crea necesaria en un archivo para este
programa.
'''
# Hecho por: Steven Grisales López - 1034289634
import os

script_path = os.path.dirname(os.path.abspath(__file__))

# Clase principal 1: Animal
class Animal:
        def __init__(self, nombre, edad, especie, habitat, alimentacion):
            self.nombre = nombre
            self.edad = edad
            self.especie = especie
            self.habitat = habitat
            self.alimentacion = alimentacion

        def comer(self):
            print(f"{self.nombre} está comiendo {self.alimentacion}.")

        def dormir(self):
            print(f"{self.nombre} está durmiendo.")

# Clase principal 2: SerVivo
class SerVivo:
        def __init__(self, nombre, edad, reproduccion, crecimiento):
            self.nombre = nombre
            self.edad = edad
            self.reproduccion = reproduccion
            self.crecimiento = crecimiento

        def reproducirse(self):
            print(f"{self.nombre} se está reproduciendo de manera {self.reproduccion}.")

# Subclase 1: Mamífero
class Mamifero(Animal, SerVivo):
        def __init__(self, nombre, edad, especie, habitat, alimentacion, pelaje, reproduccion):
            Animal.__init__(self, nombre, edad, especie, habitat, alimentacion)
            SerVivo.__init__(self, nombre, edad, reproduccion, "Vivíparo")
            self.pelaje = pelaje

        def amamantar(self):
            print(f"{self.nombre} está amamantando a sus crías.")

# Subclase 2: Ave
class Ave(Animal, SerVivo):
        def __init__(self, nombre, edad, especie, habitat, alimentacion, color_plumaje, reproduccion):
            Animal.__init__(self, nombre, edad, especie, habitat, alimentacion)
            SerVivo.__init__(self, nombre, edad, reproduccion, "Ovíparo")
            self.color_plumaje = color_plumaje

        def volar(self):
            print(f"{self.nombre} está volando.")

# Subclase 3: Pez
class Pez(Animal, SerVivo):
        def __init__(self, nombre, edad, especie, habitat, alimentacion, tipo_agua, reproduccion):
            Animal.__init__(self, nombre, edad, especie, habitat, alimentacion)
            SerVivo.__init__(self, nombre, edad, reproduccion, "Ovíparo")
            self.tipo_agua = tipo_agua

        def nadar(self):
            print(f"{self.nombre} está nadando en agua {self.tipo_agua}.")

# Subclase 4: Reptil
class Reptil(Animal, SerVivo):
        def __init__(self, nombre, edad, especie, habitat, alimentacion, temperatura_cuerpo, reproduccion):
            Animal.__init__(self, nombre, edad, especie, habitat, alimentacion)
            SerVivo.__init__(self, nombre, edad, reproduccion, "Ovíparo")
            self.temperatura_cuerpo = temperatura_cuerpo

        def tomar_sol(self):
            print(f"{self.nombre} está tomando el sol para regular su temperatura.")

# Subclase 5: Anfibio
class Anfibio(Animal, SerVivo):
        def __init__(self, nombre, edad, especie, habitat, alimentacion, tipo_piel, reproduccion):
            Animal.__init__(self, nombre, edad, especie, habitat, alimentacion)
            SerVivo.__init__(self, nombre, edad, reproduccion, "Ovovivíparo")
            self.tipo_piel = tipo_piel

        def saltar(self):
            print(f"{self.nombre} está saltando.")

# Crear una lista para almacenar objetos de animales
animales = []

# Crear instancias de diferentes animales
perro = Mamifero("Max", 3, "Canino", "Terrestre", "carnívoro", "Pelo corto", "Vivíparo")
aguila = Ave("Aquila", 5, "Ave rapaz", "Aéreo", "carnívoro", "Café y blanco", "Ovíparo")
pez = Pez("Nemo", 1, "Pez payaso", "Acuático", "omnívoro", "Agua salada", "Ovíparo")
tortuga = Reptil("Toby", 10, "Tortuga de tierra", "Terrestre", "herbívoro", "Fría", "Ovíparo")
rana = Anfibio("Frodo", 2, "Rana verde", "Acuático", "insectívoro", "Húmeda", "Ovovivíparo")

    # Agregar los objetos a la lista
animales.append(perro)
animales.append(aguila)
animales.append(pez)
animales.append(tortuga)
animales.append(rana)
    
# Guardar la información en un archivo
file_path = os.path.join(script_path, "animales.txt")
with open(file_path, "w") as archivo:
        for animal in animales:
            archivo.write(f"Nombre: {animal.nombre}, Edad: {animal.edad}, Especie: {animal.especie}\n")

# Mostrar información de los animales
for animal in animales:
    print(f"Nombre: {animal.nombre}")
    print(f"Edad: {animal.edad} años")
    print(f"Especie: {animal.especie}")
    print(f"Hábitat: {animal.habitat}")
    print(f"Alimentación: {animal.alimentacion}")
    animal.comer()
    animal.dormir()
    animal.reproducirse()

# Verificar el tipo de objeto antes de llamar a métodos específicos
if isinstance(animal, Mamifero):
    animal.amamantar()
elif isinstance(animal, Ave):
    animal.volar()
elif isinstance(animal, Reptil):
    animal.tomar_sol()
elif isinstance(animal, Anfibio):
    animal.saltar()

    print()