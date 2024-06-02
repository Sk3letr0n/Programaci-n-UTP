'''
2. Realizar un programa Orientado a Objetos que muestre el siguiente menú
de opciones y realice todas las funcionalidades propuestas en el menú,
ustedes tendrán que diseñar las clases, atributos y métodos que se
requieran:
a. “Bienvenido al gestor de vehículos”
b. Nuevo vehículo
c. Ingreso de vehículo, marca, modelo, año
d. Buscar vehículo
e. Introduzca una cantidad de millas, calcula y muestra su equivalente en
kilómetros.
f. Modificar vehículo
g. Ver todos los vehículos
h. Mostrar los vehículos con sus datos.
'''
# Hecho por: Steven Grisales López y Luis Felipe Garzón Bonilla.
from vehiculos import *


def menu():
    while True:
        

        opcion=int(input (f'''
            Bienvenido al gestor de vehículos
            1. Ingresar nuevo vehiculo
            2. Buscar vehiculo
            3. Convertir millas a kilometros
            4. Modificar vehiculo
            5. Ver todos los vehiculos
            6. Mostrar los vehiculos con sus datos
            0. Salir
            Ingresar una opcion:  '''))
        
        match opcion:

            case 1:
                marca = input("Ingrese la marca del vehiculo: ")
                modelo = input("Ingrese el modelo del vehiculo: ")
                año = input("Ingrese el año del vehiculo: ")
                placa= input("Ingrese la placa del vehiculo: ")

                vehiculo = Vehiculos(marca,modelo,año,placa)
                vehiculo.Guardar()


                
                
            case 2:
                placa = input("Ingrese la placa del vehiculo que desea buscar: ")
                vehiculo = Vehiculos("", "", "", placa)
                vehiculo.BuscarPlaca(placa)
                

            
            case 3:
                millas = int(input("Ingrese la cantidad de millas que desea convertir a kilometros: "))
                vehiculo = Vehiculos("", "", "", "")

                vehiculo.ConvertirMillas(millas)
               
            
            case 4:

                placa = input("Ingrese la placa del vehiculo para modificar sus datos : ")
                vehiculo = Vehiculos("","","","")
                vehiculo.Modificar_Vehiculo(placa)
              

            case 5:
                vehiculo=Vehiculos("", "", "", "")
                vehiculo.Mostrar_Vehiculos()
            
            case 6:
                vehiculo=Vehiculos("", "", "", "")
                vehiculo.Mostrar_datos()
                
            
            case 0:
                exit()

menu()
