lista = [1, 100, 55, 0, "programacion", "lista", "POO", "Algebra", 89]

numeros = []
cadenas = []

for i in lista:
    if isinstance(i, int):
        numeros.append(i)
    else:
        cadenas.append(i)

numeros.sort()
cadenas.sort()

listafinal = numeros + cadenas

print(listafinal)
