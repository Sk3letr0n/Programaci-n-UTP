""" Escribir un programa que almacene las asignaturas de un curso en una lista, pida al usuario las 4 notas de cada materia y en 
pantalla mostrar el promedio que ha sacado en cada materia y si alguna materia queda por debajo de la nota 3 debe salir en 
pantalla “asignatura perdida”, luego se deben calcular el promedio general de todas las materias si el promedio está por
debajo de 3 debe imprimir “semestre perdido”, si esta entre 3 y 4 debe imprimir “buen trabajo”, si el promedio esta entre 4 y 5
debe imprimir “felicidades serás becado”. """
# Hecho por Steven Grisales López. 1034289634

Lista_Asignaturas = []
Lista_Notas = []
Lista_Promedio = []

num_asignaturas = int(input("Ingrese la cantidad de asignaturas que esta cursando: "))

print(" ")


for i in range(num_asignaturas):
    Lista_Asignaturas.append(str(input("Ingrese la asignatura: ")))
    
print(" ")


for i in range(num_asignaturas):
    print("Ingrese las notas de la asignatura: ", Lista_Asignaturas[i])
    
    notas = [] # Lista para almacenar las notas de la materia actual.
    
    for j in range(0,4): # Utiliza range(0, 4) para iterar sobre las notas del 1 al 4
        notas.append(float(input("Ingrese la nota %d: "% (j + 1))))  # % (j + 1) es el valor que se va a insertar en el marcador de posición.
        
    Lista_Notas.append(notas) # Agrega la lista de notas de la materia actual a la lista principal de listas

    print(" ")
    
    
for i in range(len(Lista_Notas)): 
    notas_materia = Lista_Notas[i] # Accedo a la Sublista en la posición i
    Lista_Promedio.append(sum(notas_materia) / 4) # Agrego el promedio de la materia actual a la lista de promedios
    

for i in range(num_asignaturas):
    print(f"{Lista_Asignaturas[i]} : ")
    
    for j in range(1,5): # Utiliza range(1, 5) para iterar sobre las notas del 1 al 4
        print(f"Nota {j} = {Lista_Notas[i][j-1]} ") # Accedo a las notas ingresando a la Sublista en la posición i y luego accediendo a sus elementos en la posición j-1
        
    if(Lista_Promedio[i] >= 3): # Si el promedio de la materia actual es mayor o igual a 3
        print(f"El promedio {Lista_Asignaturas[i]} : {Lista_Promedio[i]} - Asignatura Ganada")
        print(" ")
    else:
        print(f"El promedio {Lista_Asignaturas[i]} : {Lista_Promedio[i]} - Asignatura Perdida")
        print(" ")
        
        
if sum(Lista_Promedio) / num_asignaturas < 3: # Si el promedio general es menor a 3
    print(f"Promedio general: {sum(Lista_Promedio) / num_asignaturas} - Semestre perdido")
    
elif  3 <= sum(Lista_Promedio) / num_asignaturas < 4:
    print(f"\nPromedio general: {sum(Lista_Promedio) / num_asignaturas} -  Buen trabajo")
    
elif  4 <= sum(Lista_Promedio) / num_asignaturas < 5:
    print(f"\nPromedio general: {sum(Lista_Promedio) / num_asignaturas} - Felicidades serás Becado")