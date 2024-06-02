'''
3. Realizar un programa con el paradigma orientado a objetos y archivos para
gestionar un inventario sencillo donde tendremos el nombre del producto y
la cantidad del producto, el sistema de realizar las siguientes acciones:
a. Ingresar elementos al inventario
b. Buscar un elemento especifico en el inventario
c. Borrar un elemento en especifico
d. Ordenar los elementos en el inventario
'''
# Hecho por: Steven Grisales López(1034289634) y Luis Felipe Garzón Bonilla (1089931169).

class Inventario():
    def __init__(self, nombre, cantidad):
        self.nombre = nombre
        self.cantidad = cantidad

    def ingresarElementos(self):
        self.nombre = input("\nIngrese el nombre del producto: ")
        self.cantidad = int(input("Ingrese la cantidad de este producto: "))

        with open(r"Archivos\Punto3.txt", "a") as archivo:
            archivo.write(f"Nombre: {self.nombre}, Cantidad: {self.cantidad}" + "\n")
            
    # En este método decidimos no mostrar los productos del inventario ya que el usuario puede buscar lo que quiera y se le indica si existe o no.
    def buscarElementos(self):
        producto = input("\nIngrese el producto que desea buscar: ")
        
        with open(r"Archivos\Punto3.txt", "r") as archivo:
            # Recorremos cada línea del archivo.
            for linea in archivo:
                # Si el producto se encuentra en la línea, se imprime la línea.
                if producto in linea:
                    print(f"\nEl producto {producto} se encuentra en el inventario.")
                    print(linea)
                    break
            else:
                print("\nEl producto no se encuentra en el inventario.")

    def borrarElementos(self):
        print("")
        with open(r"Archivos\Punto3.txt", "r") as archivo:
            print(archivo.read())
            
        producto = input("Ingrese el producto que desea borrar: ")
        with open(r"Archivos\Punto3.txt", "r") as archivo:
            lineas = archivo.readlines()
            
            with open(r"Archivos\Punto3.txt", "w") as archivo:
                # Recorremos cada línea del archivo.
                for linea in lineas: 
                    # Si el producto no se encuentra en la línea, se escribe en el archivo.
                    if producto not in linea:  
                        archivo.write(linea)
                    else: 
                        print(f"Se ha eliminado el producto {producto} del inventario.")
                else:
                    print(f"El producto {producto} no se encuentra en el inventario.")

    def ordenarElementos(self):
        print("")
        with open(r"Archivos\Punto3.txt", "r") as archivo:
            lineas = archivo.readlines() # Guardamos las líneas del archivo en una lista.
            lineas.sort() # Ordenamos la lista.
            
            with open(r"Archivos\Punto3.txt", "w") as archivo:
                archivo.writelines(lineas) # Escribimos las líneas ordenadas en el archivo.
        
        with open(r"Archivos\Punto3.txt", "r") as archivo:
            print(archivo.read())


def menu():

    while True:
        print("\n--- Menú ---")
        print("1. Ingresar elementos al inventario.")
        print("2. Buscar elementos.")
        print("3. Borrar elemento.")
        print("4. Ordenar elementos.")
        print("0. Salir")
        opcion = int(input("Seleccione una opción: "))

        match opcion:

            case 1:
                while True:
                    inventario.ingresarElementos()
                    decision = input("¿Desea registrar otro producto? (1 para SI, 0 para NO): ")
                    if decision != '1':
                        print(" ")
                        break
                
            case 2:
               inventario.buscarElementos()

            case 3:
                inventario.borrarElementos()
                    
            case 4:
                inventario.ordenarElementos()

            case 0:
                print("\nSaliendo del programa...")
                exit()       

            case _:
                print("\nOpción no valida. Intente de nuevo.")
                break

inventario = Inventario("", 0)
menu()