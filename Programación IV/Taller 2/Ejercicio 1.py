'''
Realice un programa que reciba en una lista solo números enteros de dos
cifras, luego de llenar la lista, recorra cada elemento sumando el digito uno
con el digito dos. La lista puede ser de la longitud que el usuario ingrese.
Input: [22,44,36,12]
Output: [4,8,9,3]
'''
# Hecho por: Steven Grisales López - 1034289634
from io import *

lista = []

longitud_lista = int(input("Ingrese la cantidad de elementos que desea en la lista: "))

for i in range(longitud_lista):
    
    while True:
        numero = int(input("Ingrese un número de dos cifras: "))
    
        if(numero >= 10 and numero <= 99): # Verificar que el número sea de dos cifras
            lista.append(numero)
            break
        else:
            print("El número no es de dos cifras, ingrese otro.\n")
            
print(f"Su lista es: {lista}" + "\n")
            
archivo = open(r"punto1.txt", "a") # Esta con relative path (Cambiar si no funciona).

for i in range(len(lista)):
    # Convertir el número en una cadena para poder acceder a los digitos que lo componen y sumarlos
    lista[i] = int(str(lista[i])[0]) + int(str(lista[i])[1]) 

archivo.write(f"{lista}" + "\n")
archivo.close()