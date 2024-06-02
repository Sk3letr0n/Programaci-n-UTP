'''
2. Realice un programa para gestionar la información de usuarios como son:
a. Crear usuario
b. Consultar usuarios inscritos
c. Editar al menos dos atributos del usuario
d. Borrar usuario

'''
from io import *
# Hecho por: Steven Grisales López (1034289634) y Luis Felipe Garzón Bonilla (1089931169).

class Usuario():
    def __init__(self, nombre, documento, edad, correo, telefono):
        self.nombre = nombre
        self.documento = documento
        self.edad = edad
        self.correo = correo
        self.telefono = telefono

    def crearUsuario(self):
        self.nombre = input("Ingrese el nombre del usuario: ")
        self.documento = int(input("Ingrese el documento del usuario: "))
        self.edad = int(input("Ingrese la edad del usuario: "))
        self.correo = input("Ingrese el correo del usuario: ")
        self.telefono = int(input("Ingrese el telefono del usuario: "))
        
        with open(r"Archivos\Punto2.txt", "a") as archivo:
            archivo.write(f"Nombre: {self.nombre}, Documento: {self.documento}, Edad: {self.edad}, Correo: {self.correo}, Telefono: {self.telefono}" + "\n")

    def consultarUsuarios(self):
        print("\nUsuarios inscritos: ")
        print("")
        with open(r"Archivos\Punto2.txt", "r") as archivo:
            print(archivo.read())

                
    def editarUsuario(self):
        Usuario.consultarUsuarios(self) # Llamamos al método consultarUsuarios para mostrar los usuarios inscritos.
        
        usuario = input("\nIngrese el usuario que desea editar: ")
        
        with open("Archivos\Punto2.txt", "r") as archivo:
            lineas = archivo.readlines() # Guardamos las líneas del archivo en una lista.
        count = 0 # Variable para saber si el usuario se encuentra en la lista.

        with open("Archivos\Punto2.txt", "w") as archivo:
            for linea in lineas: # Recorremos cada línea del archivo.
                if usuario not in linea: # Si el usuario no se encuentra en la línea, se escribe en el archivo.
                    archivo.write(linea)
                else:
                    self.nombre = input("Ingrese el nuevo nombre: ")
                    self.documento = input("Ingrese el nuevo documento: ")
                    self.edad = int(input("Ingrese la nueva edad: "))
                    self.correo = input("Ingrese el nuevo correo: ")
                    self.telefono = int(input("Ingrese el nuevo telefono: "))
                    
                    archivo.write(f"Nombre: {self.nombre}, Documento: {self.documento}, Edad: {self.edad}, Correo: {self.correo}, Telefono: {self.telefono}" + "\n")
                    count += 1 # Aumentamos el contador si el usuario se encuentra en la lista.
                    
        # Si el contador es 0, el usuario no se encuentra en la lista.
        if count == 0:
            print(f"El usuario {usuario} no se encuentra en la lista.")  
                            
    def borrarUsuario(self):
        with open(r"Archivos\Punto2.txt", "r") as archivo:
            print(archivo.read())
    
        usuario = input("Ingrese el documento del usuario que desea borrar: ")
        with open(r"Archivos\Punto2.txt", "r") as archivo:
            lineas = archivo.readlines() # Guardamos las líneas del archivo en una lista.
            
            # Recorremos cada línea del archivo.
            for i in range(len(lineas)):
                # Si el usuario se encuentra en la línea, se borra del archivo (linea exactamente).
                if usuario in lineas[i]:
                    print(f"El usuario {self.nombre} tiene los siguientes datos: {lineas[i]}")
                    lineas.remove(lineas[i])
                    with open(r"Archivos\Punto2.txt", "w") as archivo:
                        archivo.writelines(lineas) # Escribimos las líneas con el usuario borrado en el archivo.

def menu():

    while True:
        opcion = input("""
        --- Menú ---
        1. Crear usuario.
        2. Consultar usuarios inscritos.
        3. Editar usuario.
        4. Borrar usuario.
        0. Salir.
        Seleccione una opción: """)

        match opcion:
            case "1":
                usuario.crearUsuario()
                
            case "2":
                usuario.consultarUsuarios()
                
            case "3":
                usuario.editarUsuario()
                
            case "4":
                usuario.borrarUsuario()
                
            case "0":
                print("\nSaliendo del programa...")
                exit()
                
            case _:
                print("\nOpción no válida. Intente de nuevo.")

usuario = Usuario("", "", 0, "", 0)
menu()