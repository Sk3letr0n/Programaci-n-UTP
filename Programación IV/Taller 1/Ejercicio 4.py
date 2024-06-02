""" Escriba un programa que pida al usuario la cantidad que desea de la lista, luego el usuario debe ingresar valores numéricos
enteros hasta llenar la lista, luego de ingresarlos se debe imprimir en pantalla cada numero ingresado por el usuario 
y al lado debe aparecer ese mismo número al cuadrado y al lado ese mismo número al cubo. """
# Hecho por Steven Grisales López. 1034289634

Numeros = []

cantidad_num = int(input("Ingrese la cantidad de numeros enteros que desea: "))

print(" ")

for i in range(cantidad_num):
    Numeros.append(int(input("Ingrese los numeros: "))) # Agrega los número a la lista
    
print(" ")

for j in range(cantidad_num):
    print(Numeros[j], " - ", pow(Numeros[j], 2), " - ", pow(Numeros[j], 3)) # Imprime el número, su cuadrado y su cubo