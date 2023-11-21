print("FILHO DA PUTA MANO, MUITO BUENO ESTEI CODIGOU AMIGAO")      
print("")

# Objetos (variables en imperativo "C/C++").
miNombre = "steven grisales lópez"
miRol = "Estudiante"

# Maneras de imprimir unas variables:
print("Mi nombre es", miNombre, "y soy", miRol) # 1ra forma.
print(f"Mi nombre es {miNombre} y soy {miRol}") # 2da forma.
print("Mi nombre es " +miNombre+ " y soy " +miRol) # 3ra forma. -----> +miNombre.title()+  [Vuelve las primeras letras de cada palabra a mayúscula]

# Otra forma más "elegante".
print("")
miPeso = 48.2
print(f"Mi nombre es {miNombre.title()} y soy {miRol} y peso {miPeso} kg.") # Usamos mejor este ya que evita lo de str.
print("Mi nombre es " +miNombre.title()+ " y soy " +miRol+ " y peso " +str(miPeso)+ " kg.") # En el caso de usar +objeto+, usar str convierte lo que haya en un string.

# Definición de funciones:
def hola():
    print("")
    return 3 + 4 * 5 - 9
    
# Imprimir lo que retorna una función.
print(hola())   


# Cómo hacer un for (index inicia en 0 a no ser que lo modifique).
# Imprime los numeros horizontalmente.
print("") 
for index in range(1, 10): # 1 a 9 (inicio, cantidad de números).
    print(f"{index}", end = " ") #el end es para que se trague el salto de línea y me lo imprima de seguido con un espacio (" ").

# Imprime los numeros verticalmente.
print("\n")
for index in range(10): # 0 a 9.
    print(index)
    
# Imprime los numeros verticalmente pero teniendo en cuenta el condicional.
print("")
for index in range(20): # 0 a 19.
    if index > 15:
        print(f"{index}", end = " ")
        
# Ahora con un else.
print("\n")
for index in range(30): # 0 a 30.
        print(f"{index}", end = " ") if index < 25 else print(f"puta", end = " ") 

# Otra forma con else.
print("\n")
for index in range(30): # 0 a 30.
    if index < 25:
        print(f"{index}", end = " ") 
    else: 
        print(f"sapo", end = " ") 
        
# Otra manera de definir funciones.
def suma(a,b):
    return a + b

def resta(a,b):
    return a - b

def multiplicacion(a,b):
    return a * b

def division(a,b):
    return a / b

# Imprimir el llamado a función "suma".
print("\n")
print(suma("Garzón", " Zorra"))

# For de un objeto de string iterable.
print("")
nombre = "amir"
for c in nombre:
    print(f"{c} ", end = " ")
    
# Ordena un objeto de menor a mayor o alfabéticamente.
print("\n")
print(sorted(nombre))

# For que itera una lista y la imprime (con range).
lista = [1,2,3,4,5,6,7,8,9] 
print("\n")
for index in range(len(lista)):
    print(lista[index])

# Otra forma para imprimir la lista (sin range).
print("\n")    
for index in lista:
    print(index)
    
# Imprime la lista la cantidad de elementos que tiene la lista.
print("\n")
for index in lista:
    print(lista)
    
# Tarea: Investigar con ejemplos(chatGPT) los siguientes elementos para la siguiente clase. 1- Listas(arrays). 2- Diccionario. 3- Conjunto(set). 4- Duplas y Tuplas 