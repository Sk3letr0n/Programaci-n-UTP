from io import *

menu = True

while menu:
    opcion = int(input(''' Bienvenido al menú
          1. Añadir datos.
          2. Listar datos.
          3. Salida.
          Opción: '''))
    match opcion:
        
        case 1:
            archivo = open(r"C:\Users\utp\Desktop\prueba.txt", "a")
            print("")
            nombre = str(input("Ingrese el nombre de usuario: "))
            edad = int(input("Ingrese la edad del usuario: "))
            archivo.write(f"nombre: {nombre} edad: {edad}\n")
            archivo.close()
            
        case 2:
            archivo = open(r"C:\Users\utp\Desktop\prueba.txt", "a")
            lectura = archivo.read()
            print(lectura)
            archivo.close
            
        case 3:
            menu = False
            pass
        
        case _:
            print("Opción inválida.")
