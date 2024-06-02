""" Realizar un programa que inicialice una lista con 15 valores aleatorios y posteriormente muestre en pantalla cada elemento de la lista junto con su cuadrado y su cubo. """
# Hecho por Steven Grisales López. 1034289634

import random # La busque en google.

Numeros = []

for _ in range(15): # Cómo no uso iterador por eso el _
    Numeros.append(random.randint(1, 100)) # Le meto valores random del 1 al 100.

print("\nLista: ", Numeros)

for i in range(len(Numeros)):
    print(Numeros[i], " - ", pow(Numeros[i], 2), " - ", pow(Numeros[i], 3)) # Número, cuadrado y cubo.