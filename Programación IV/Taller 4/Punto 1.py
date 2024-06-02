'''
1. Realice un programa en el que podamos observar los atributos de las clases
inspiradas en el siguiente gráfico, se debe implementar herencia simple y se
deben guardar la información de cada vehículo en uno o varios archivos para
poder listarlos cuando se necesiten, el programa también debe contar con los
siguientes métodos:

    - Métodos Vehículo:
        a. Debe mostrar información dependiendo del vehículo (camión, moto,
        automóvil) de cuantos años aproximadamente le pueden durar las llantas esto
        también sujeto a tres tipos de marcas.
        b. tipo de combustible que se recomienda usar para el vehículo que se elija
        (ACPM, Extra, Corriente).
        
    - Métodos Coche:
        a. Mostrar que tiempo se tomaría cada vehículo en llegar desde Pereira a
        diferentes lugares en Colombia (mínimo 5 lugares).
        b. debe mostrar cuanto gastaría al mes en combustible cada automóvil
        suponiendo que cada uno hace viajes de 1000 km mensuales, ustedes pueden
        consultar precios actuales para parametrizar el combustible.
'''
# Hecho por Steven Grisales López - 1034289634
import os
import random
        
class Vehiculo:
    def __init__(self, tipo_vehiculo, marca, tipo_combustible):
        self.tipo_vehiculo = tipo_vehiculo
        self.marca = marca
        self.tipo_combustible = tipo_combustible
        
        
    def duracion_llantas(self):
        self.tipo_vehiculo = input("Ingrese el tipo de vehículo.  "
                           "\nAuto, Camion, Moto: ")
        
        if self.tipo_vehiculo == "Auto":
            self.marca = input("\nIngrese la marca de su vehículo. "
                            "\nToyota, Chevrolet, Mazda: ")
            
            if self.marca == "Toyota":
                print("\nDuración promedio de las llantas:")
                print("Entre 45,000 Km y 60,000 Km.")
                
            elif self.marca == "Chevrolet":
                print("\nDuración promedio de las llantas:")
                print("Entre 40,000 Km y 55,000 Km.")
                
            elif self.marca == "Mazda":
                print("\nDuración promedio de las llantas:")
                print("Entre 50,000 Km y 65,000 Km.")
                
            else :
                print("\nMarca no válida.")
                
        
        elif self.tipo_vehiculo == "Camion":
            self.marca = input("\nIngrese la marca de su vehículo. "
                                "\nToyota, Chevrolet, Mazda: ")
            
            if self.marca == "Toyota":
                print("\nDuración promedio de las llantas:")
                print("Dependerá del tipo de camión y su uso, pero en general, pueden durar más de 100,000 Km.")
                
            elif self.marca == "Chevrolet":
                print("\nDuración promedio de las llantas:")
                print("Dependerá del tipo de camión y su uso, pero en general, pueden durar más de 200,000 Km.")
                
            elif self.marca == "Mazda":
                print("\nDuración promedio de las llantas:")
                print("Dependerá del tipo de camión y su uso, pero en general, pueden durar más de 150,000 Km.")
                
            else :
                print("\nMarca no válida.")
                    
                    
        elif self.tipo_vehiculo == "Moto":
            self.marca = input("\nIngrese la marca de su moto. "
                                "\nToyota, Chevrolet, Mazda: ")
            
            if self.marca == "Toyota":
                print("\nDuración promedio de las llantas:")
                print("La duración de las llantas de moto puede variar, pero suele estar entre 8,000 y 16,000 Km.")
                
            elif self.marca == "Chevrolet":
                print("\nDuración promedio de las llantas:")
                print("La duración de las llantas de moto puede variar, pero suele estar entre 10,000 y 18,000 Km.")
                
            elif self.marca == "Mazda":
                print("\nDuración promedio de las llantas:")
                print("La duración de las llantas de moto puede variar, pero suele estar entre 12,000 y 20,000 Km.") 
                
            else :
                print("\nMarca no válida.")

        else :
            print("\nTipo de vehículo no válido.")

    def recomendar_combustible(self):
        if self.tipo_vehiculo == "Auto":
            self.tipo_combustible = "Extra"
            print("\nRecomendamos usar gasolina Extra.")
        
        elif self.tipo_vehiculo == "Camion":
            self.tipo_combustible = "ACPM"
            print("\nRecomendamos usar ACPM.")
        
        elif self.tipo_vehiculo == "Moto":
            self.tipo_combustible = "Corriente"
            print("\nRecomendamos usar gasolina Corriente.")
        
        else:
            print("\nTipo de vehículo no válido.")
        

class Coche(Vehiculo):
    def __init__(self, tipo_vehiculo, marca, tipo_combustible, lugares):
        super().__init__(tipo_vehiculo, marca, tipo_combustible) # Se llama al constructor de la clase padre (Vehiculo).
        self.lugares = lugares


    def tiempo_viaje(self):
             
        velocidad_kmph = random.randint(80, 120) 

        distancia_a_bogota = 280
        distancia_a_medellin = 200
        distancia_a_cali = 350
        distancia_a_cartagena = 800
        distancia_a_bucaramanga = 450

        # Se calcula el tiempo de viaje a cada ciudad
        tiempo_a_bogota = distancia_a_bogota / velocidad_kmph
        tiempo_a_medellin = distancia_a_medellin / velocidad_kmph
        tiempo_a_cali = distancia_a_cali / velocidad_kmph
        tiempo_a_cartagena = distancia_a_cartagena / velocidad_kmph
        tiempo_a_bucaramanga = distancia_a_bucaramanga / velocidad_kmph

        print(f"\nTiempo de viaje a Bogotá: {tiempo_a_bogota} horas")
        print(f"Tiempo de viaje a Medellín: {tiempo_a_medellin} horas")
        print(f"Tiempo de viaje a Cali: {tiempo_a_cali} horas")
        print(f"Tiempo de viaje a Cartagena: {tiempo_a_cartagena} horas")
        print(f"Tiempo de viaje a Bucaramanga: {tiempo_a_bucaramanga} horas")
        
        with open("datos_vehiculo.txt", "a") as archivo:     
            archivo.write(f'''El vehiculo Hizo los siguientes viajes en el siguiente orden y tiempo:
                          Bogota: {tiempo_a_bogota} horas.
                          Medellin: {tiempo_a_medellin} horas.
                          Cali: {tiempo_a_cali} horas.
                          Cartagena: {tiempo_a_cartagena} horas.
                          Bucaramanga: {tiempo_a_bucaramanga} horas. ''')


    def costo_combustible_mensual(self):

        precio_gasolina_actual = 15164

        distancia_mensual_km = 1000 

        costo_mensual = (distancia_mensual_km / random.randint(4, 12)) * precio_gasolina_actual # Se asume que el vehículo hace entre 4 y 12 km por litro

        print(f"\nEl costo mensual es de {int(costo_mensual)} pesos.")
        
        with open("datos_vehiculo.txt", "a") as archivo:
            archivo.write(f"\nEl costo mensual es de {int(costo_mensual)} pesos.")
            
    def guardar_datos(self):
        print(f"\nLos datos de su vehiculo son: {self.tipo_vehiculo}, {self.marca}, {self.tipo_combustible}.")
        
        with open("datos_vehiculo.txt", "a") as archivo:
            archivo.write(f"\n\nTipo de vehiculo: {self.tipo_vehiculo}, Marca: {self.marca}, Tipo de combustible: {self.tipo_combustible}.\n")


os.system("cls")
coche1 = Coche("", "", "", 5)
coche1.duracion_llantas()
coche1.recomendar_combustible()
coche1.guardar_datos()
coche1.tiempo_viaje()
coche1.costo_combustible_mensual()