""" Escribir un programa que almacene las asignaturas de un curso (matemáticas, física, química, entre otras) en una lista y muestre
en pantalla el mensaje: "yo estudio <asignatura>", donde asignatura es cada una de las asignaturas de la lista. """
# Hecho por Steven Grisales López. 1034289634

Asignaturas = []

num_asignaturas = int(input("Ingrese la cantidad de asignaturas que esta cursando: "))

print(" ")

for i in range(num_asignaturas):
    Asignaturas.append(str(input("Ingrese la asignatura: "))) # Agregar las asignaturas a la lista
    
print(" ")

for j in range(num_asignaturas):
    print(f"Yo estudio {Asignaturas[j]}")