lista = []

num_elem = int(input("Ingrese la cantidad de elementos que desea: "))

for i in range(num_elem):
    elemento = int(input("Ingrese el elemento: "))

    lista += [elemento]
    # Alternativa 1 = lista.append(elemento)
    # Alternativa 2 = mi_lista.insert(posicion, elemento)
    # Alternativa 3 = lista[i:i] = elemento

print(lista, end=" ") # Especifica el carácter o cadena de caracteres que se debe imprimir al final de la salida (usualmente suele ser un /n).