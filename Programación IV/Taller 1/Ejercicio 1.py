""" Escribir un programa que almacene asignaturas (matemáticas, física, química, entre otras) y las muestre en pantalla. """
# Hecho por Steven Grisales López. 1034289634

Asignaturas = []

num_asignaturas = int(input("Ingrese la cantidad de asignaturas que desea almacenar: "))

print(" ")

for i in range(num_asignaturas):
    Asignaturas.append(str(input("Ingrese la asignatura: "))) # Agrega las asignaturas a la lista

print(" ")
print(f"Sus asignaturas almacenadas son: {Asignaturas}")