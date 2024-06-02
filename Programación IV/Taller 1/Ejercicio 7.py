""" Realizar un programa que pida al usuario un carácter, luego se debe mostrar las cadenas que contengan dicho carácter y debe mostrar si dichas cadenas son pares o impares. """
# Hecho por Steven Grisales López. 1034289634

Cadenas = []

cantidad_Cadenas = int(input("Ingrese la cantidad de cadenas que quiere: "))
print(" ")

for i in range(cantidad_Cadenas):
    Cadenas.append(str(input("Ingrese el carácter: "))) # Agrego el carácter a la lista.
    
print("\nLista: ", Cadenas)

caracter = str(input("Ingrese un carácter: ")) # Pido al usuario un carácter.
print(" ")

for i in range(cantidad_Cadenas):
    if caracter in Cadenas[i]: # Si el caracter esta en la Cadena en la posición actual
        print(f"La cadena {Cadenas[i]} contiene el carácter: {caracter}")
        
        if (len(Cadenas[i]) % 2 == 0): 
            print(f"La cadena {Cadenas[i]} es par")
        else:
            print(f"La cadena {Cadenas[i]} es impar")
            
        print(" ")