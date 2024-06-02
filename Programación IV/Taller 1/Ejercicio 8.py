""" Realizar un programa que haga conteo de todos los caracteres que no sean vocales en una lista de 10 cadenas. """
# Hecho por Steven Grisales López. 1034289634

Cadenas = []
Num_Cad = 10 # Cantidad permitida de cadenas.
vocales = "aeiouAEIOU"

for i in range(Num_Cad): 
    Cadenas.append(input("Ingrese la cadena: "))
    
print("\nLista: ", Cadenas)

contador_no_vocales = 0

for i in range(len(Cadenas)): # Accedo a la lista en cada posición. (cada cadena)
    for j in range(len(Cadenas[i])): # Accedo a cada cadena en cada posición. (letra por letra)
        if not(Cadenas[i][j] in vocales): # Si la letra no está en la lista de vocales, entonces es una consonante.
            contador_no_vocales += 1

        
print(f"La cantidad de caracteres que no son vocales en la lista son: {contador_no_vocales}")