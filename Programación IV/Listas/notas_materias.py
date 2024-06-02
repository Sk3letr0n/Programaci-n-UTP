Materias = ["Programación", "Matemáticas", "Inglés"]
Notas = []

for i in range(len(Materias)):
    elemento = float(input(f"Ingrese la nota para {Materias[i]}: "))

    Notas += [elemento]

print(" ")

for j in range(len(Materias)):
    print(f"Materia: {Materias[j]} - Nota: {Notas[j]}")

# Intentar que se ingrese los elementos de la lista y luego se haga el otro proceso.