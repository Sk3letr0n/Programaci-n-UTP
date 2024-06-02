'''
2. Haga uso del punto 2 del taller 5 para realizar lo siguiente:
a. Encapsular todos los atributos y métodos
b. Diseñar los métodos set y get correspondientes.
c. Implementando modularidad debe tener en un archivo las clases, en
otro archivo los objetos y en otro archivo el llamado a los métodos o
atributos de dichos objetos, si dicha ruta no se puede implementar
proponga una posible solución.
'''
# Hecho por: Steven Grisales López - 1034289634

from Animales import Mamifero, Ave

# Crear instancias de diferentes animales
perro = Mamifero("Max", 3, "Canino", "Terrestre", "carnívoro", "Pelo corto", "Vivíparo")
aguila = Ave("Aguila", 5, "Ave rapaz", "Aéreo", "carnívoro", "Café y blanco", "Ovíparo")

# Mostrar información de los animales
print(f"Nombre: {perro.get_nombre()}")
perro.comer()
perro.dormir()
perro.reproducirse()
perro.amamantar()

print(f"\nNombre: {aguila.get_nombre()}")
aguila.comer()
aguila.dormir()
aguila.reproducirse()
aguila.volar()
