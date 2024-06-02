""" Elabore un programa para ingresar la siguiente lista.
Lista= [“casa”, “programación”, “ciaf”, “universidad”, “ciaf, “casa”, “casa”, “thj”, “vbh”, “456”, “987”]
a. Borre los elementos repetidos que tengamos en la lista
b. Borre las cadenas que NO contengan vocales.
c. Ordene la lista en orden alfabético respecto al primer elemento de la cadena. """
# Hecho por Steven Grisales López. 1034289634

Lista = ["casa", "programación", "ciaf", "universidad", "ciaf", "casa", "casa", "thj", "vbh", "456", "987"]
vocales = "aeiouAEIOU"

print("La lista es la siguiente: ", Lista)

# Punto a.
for i in range(len(Lista)-1, 0, -1): # Recorro de manera inversa la lista.
    if Lista[i] in Lista[:i]: # Creo una sublista para ir comparando con la lista que tengo.
        Lista.remove(Lista[i]) # Elimino el elemento de la lista.
        
print("\nLa lista con las cadenas repetidas eliminadas es: ", Lista)

# Punto b.
for j in range(len(Lista)-1, 0, -1): # Recorro de manera inversa la lista.
    if not any(caracter in vocales for caracter in Lista[j]): # Si el caracter no coincide con lo que hay en la variable vocales en la Lista en su posición actual.
        Lista.pop(j) # Elimino el elemento de la lista.
        
print("\nAhora la lista con las cadenas sin vocales eliminadas es:", Lista)

# Punto c.
for _ in range(len(Lista)): # No uso iterador.
    Lista.sort() # Ordeno la lista.
    
print("\nNuevamente la lista ordenada de manera alfabética es: ", Lista)