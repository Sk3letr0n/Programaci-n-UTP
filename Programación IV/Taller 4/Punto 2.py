'''
Según el diagrama del pdf.
2. Implemente:
    a. Crea al menos un objeto de cada subclase y añádelos a una lista llamada vehículos.
    b. Realiza una función llamada catalogar() que reciba la lista de vehículos y los recorra
    mostrando el nombre de su clase y sus atributos.
    c. Modifica la función catalogar() para que reciba un argumento optativo ruedas,
    haciendo que muestre únicamente los que su número de ruedas concuerde con el
    valor del argumento. También debe mostrar un mensaje &quot;Se han encontrado {}
    vehículos con {} ruedas:&quot; únicamente si se envía el argumento ruedas. Ponla a
    prueba con 0, 2 y 4 ruedas como valor.
'''
# Hecho por Steven Grisales López - 1034289634
import os

class Vehiculo:
    def __init__(self, color, ruedas):
        self.color = color
        self.ruedas = ruedas

class Coche(Vehiculo):
    def __init__(self, color, ruedas, velocidad, cilindrada):
        super().__init__(color, ruedas)
        self.velocidad = velocidad
        self.cilindrada = cilindrada

class Camioneta(Coche):
    def __init__(self, color, ruedas, velocidad, cilindrada, carga):
        super().__init__(color, ruedas, velocidad, cilindrada)
        self.carga = carga

class Bicicleta(Vehiculo):
    def __init__(self, color, ruedas, tipo):
        super().__init__(color, ruedas)
        self.tipo = tipo

class Motocicleta(Bicicleta):
    def __init__(self, color, ruedas, tipo, velocidad, cilindrada):
        super().__init__(color, ruedas, tipo)
        self.velocidad = velocidad
        self.cilindrada = cilindrada


os.system("cls")

vehiculo1 = Vehiculo("Rojo", 4)
coche1 = Coche("Azul", 4, 180, 2000)
camioneta1 = Camioneta("Gris", 4, 160, 2500, "Carga ligera")
bicicleta1 = Bicicleta("Verde", 2, "Urbana")
motocicleta1 = Motocicleta("Negra", 2, "Deportiva", 250, 1000)

vehículos = [vehiculo1, coche1, camioneta1, bicicleta1, motocicleta1]

def catalogar(lista, ruedas = None):
    if ruedas is not None:
        vehiculos_filtrados = [v for v in lista if v.ruedas == ruedas]
        print(f"Se han encontrado {len(vehiculos_filtrados)} vehículos con {ruedas} ruedas:")
        for vehiculo in vehiculos_filtrados:
            print(f"Clase: {vehiculo.__class__.__name__}, Atributos: {vars(vehiculo)}")
    else:
        for vehiculo in lista:
            print(f"Clase: {vehiculo.__class__.__name__}, Atributos: {vars(vehiculo)}")


#catalogar(vehículos) # Muestra todos los vehículos
#catalogar(vehículos, 0)  # Muestra vehículos con 0 ruedas
#catalogar(vehículos, 2)  # Muestra vehículos con 2 ruedas
catalogar(vehículos, 4)  # Muestra vehículos con 4 ruedas