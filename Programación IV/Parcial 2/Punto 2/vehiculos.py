"""Realizar un programa Orientado a Objetos que muestre el siguiente menú
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
"""


class Vehiculos:
     
     def __init__(self,marca,modelo,año, placa):
        self.marca = marca
        self.modelo = modelo
        self.año = año
        self.placa = placa
    
     def Guardar(self):
      with open(r"Punto2.txt" , "a") as archivo:
           archivo.write(f"Marca: {self.marca}, Modelo: {self.modelo}, Año: {self.año}, placa: {self.placa}" + "\n")
      print(f"Vehiculos guardados con exito")

   
     def Modificar_Vehiculo(self, placa):
          
          with open(r"Punto2.txt", "r") as archivo:
            lineas = archivo.readlines()
          cont=0

          with open(r"Punto2.txt", "w") as archivo:
             for linea in lineas:
                if placa not in linea:
                   archivo.write(linea)
                else:
                   self.marca = input(f"Ingrese la nueva marca ")
                   self.modelo = input(f"Ingrese el nuevo modelo ")
                   self.año = input(f"Ingrese el nuevo año ")
                   self.placa = input(f"Ingrese la nueva placa ")
                   archivo.write(f"Marca: {self.marca}, Modelo: {self.modelo}, Año: {self.año}, placa: {self.placa}" + "\n")
                   cont+=1
            
          if cont == 0:
             print(f"La placa {placa} no se encuentra en la lista")
          else:
             print(f"Se han hecho los cambios exitosamente ")

        
        

     def ConvertirMillas(self, millas):
        print (f"La cantidad de {millas} a kilometros es ", millas * 1.60934)

     
     def Mostrar_datos(self):
        with open (r"Punto2.txt", "r") as archivo:
            print(archivo.read())

      
     def Mostrar_Vehiculos(self):
        
        with open(r"Punto2.txt", "r") as archivo:
          for linea in archivo:
            datos = linea.strip().split(", ")  # Separar los datos por coma y eliminar espacios adicionales
            marca, modelo = datos[:2]  # Tomar los dos primeros datos
            print(f" {marca}, {modelo}")
            
     
     def BuscarPlaca(self, placa):
      
      contador=0
      with open(r"Punto2.txt", "r") as archivo: 
         for linea in archivo:
            if placa in linea:
               str1 = linea
               contador += 1

         if contador == 1:
            print(f"Se ha encontrado el vehiculo: {str1}")
         else:
            print(f"No se ha encontrado el vehiculo")


               
           
        
     
    
        
     

    
