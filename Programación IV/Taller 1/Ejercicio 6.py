""" Realice un programa en el que el usuario ingrese un valor entero, luego debe mostrar en pantalla las cadenas cuya longitud sea igual al número ingresado. """
# Hecho por Steven Grisales López. 1034289634

Cadenas = []

cantidad_Cadenas = int(input("Ingrese la cantidad de cadenas que quiere: "))
print(" ")

for i in range(cantidad_Cadenas):
    Cadenas.append(str(input("Ingrese la cadena: ")))
    
print("\nLista: ", Cadenas)

numero = int(input("Ingrese un número entero: "))
print(" ")

for i in range(cantidad_Cadenas):
    if(len(Cadenas[i]) == numero): # Si el número es igual a la longitud de lo que haya en la posición de la cadena
        print("Cadena con longitud similar: ", Cadenas[i])