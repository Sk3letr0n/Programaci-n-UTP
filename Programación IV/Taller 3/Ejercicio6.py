'''
Realice un ejemplo de cada método de archivos visto en clase.
'''
from io import *

class Metodos_Archivos:
    def __init__(self, nombre, edad, genero):
        self.nombre = nombre
        self.edad = edad
        self.genero = genero
        
    # Método With para abrir un archivo
    def metodo_with(self):
        with open(r"Archivos\punto6.txt", "w") as archivo:
            archivo.write(f"Nombre: {self.nombre}\nEdad: {self.edad}\nGenero: {self.genero}\n")
        
        print("Método With: ")
        
        with open(r"Archivos\punto6.txt", "r") as archivo:
            print(archivo.read())
            
    # Método Seek para mover el puntero de lectura/escritura
    def metodo_seek(self):
        print("Método Seek: ")
        
        with open(r"Archivos\punto6.txt", "r") as archivo:
            archivo.seek(7)  # Mover el puntero a la posición 7
            print(archivo.read())
    
    # Método Tell para obtener la posición actual del puntero
    def metodo_tell(self):
        print("Método Tell:")
        
        with open(r"Archivos\punto6.txt", "r") as archivo:
            archivo.read()  # Leer los primeros 4 caracteres
            print(f"La cantidad de caracteres en el archivo es: {archivo.tell()}\n")  # Mostrar la nueva posición del puntero
    
    # Método Readline para leer una línea a la vez
    def metodo_readline(self):
        print("Método Readline: ")
        
        with open(r"Archivos\punto6.txt", "r") as archivo:
            print(archivo.readline())  # Leer la primera línea

    # Método Readlines para leer todas las líneas en una lista
    def metodo_readlines(self):
        print("Método Readlines: ")
        
        with open(r"Archivos\punto6.txt", "r") as archivo:
            for linea in archivo.readlines():
                print(linea)

    # Método Writelines para escribir una lista de líneas en un archivo
    def metodo_writelines(self):
        Lista = ["Cancion \n", "sobre \n", "piratas"]
        
        print("Método Writelines: ")
        with open (r"Archivos\punto6.txt", "r+") as archivo: 
            archivo.read()  
                              
            final_del_archivo = archivo.tell()   
            archivo.writelines(Lista)   
            archivo.seek(final_del_archivo)   
            contenido_editado = archivo.read()
            print (contenido_editado)           

Metodos = Metodos_Archivos("Juan", 25, "Masculinos")
Metodos.metodo_with()
Metodos.metodo_seek()
Metodos.metodo_tell()
Metodos.metodo_readline()
Metodos.metodo_readlines()
Metodos.metodo_writelines()