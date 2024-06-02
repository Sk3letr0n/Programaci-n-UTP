""" Realice un programa que almacene una cantidad de cadenas dictaminadas por el usuario, en pantalla se debe mostrar la
cadena que mas caracteres contenga y la cadena que menos caracteres contenga. """
# Hecho por Steven Grisales López. 1034289634

Cadenas = []
Cadena_Mayor = 0
Cadena_Menor = 0

cantidad_Cadenas = int(input("Ingrese la cantidad de cadenas que quiere: "))

print(" ")

for i in range(cantidad_Cadenas):
    Cadenas.append(str(input("Ingrese la cadena: ")))
    
print("\nLista: ", Cadenas)

for i in range(1, cantidad_Cadenas): # Inicio desde la posición 1 de la cadena.
    if(len(Cadenas[i]) > len(Cadenas[Cadena_Mayor])): # Comparo posición por posición iniciando en 1 > 0.
        Cadena_Mayor = i # Le asigno la mayor actualmente.
    elif(len(Cadenas[i]) < len(Cadenas[Cadena_Menor])): # Comparo posición por posición iniciando en 1 > 0.
        Cadena_Menor = i # Le asigno la menor actualmente.
    
print("\nCadena Mayor: ", Cadenas[Cadena_Mayor])
print("Cadena Menor: ", Cadenas[Cadena_Menor])