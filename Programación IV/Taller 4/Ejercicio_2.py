class Vehiculo():
    def __init__(self, color, ruedas):
        self.color = color
        self.ruedas = ruedas

class Coche(Vehiculo):
    def __init__(self, color, ruedas, velocidad, cilindrada):
        super().__init__(color, ruedas)
        self.velocidad = velocidad
        self.cilindrada = cilindrada

    def crearcoche():
        color = input("Ingrese el color del coche: ")
        ruedas = int(input("Ingrese el numero de ruedas del coche: "))
        velocidad = int(input("Ingrese la velocidad maxima del coche: "))
        cilindrada = int(input("Ingrese el cilindraje del coche: "))
        return Coche(color, ruedas, velocidad, cilindrada)

class Camioneta(Coche):
    def __init__(self, color, ruedas, velocidad, cilindrada, carga):
        super().__init__(color, ruedas, velocidad, cilindrada)
        self.carga = carga
        
    def crearcamioneta():
        color = input("Ingrese el color de la camioneta: ")
        ruedas = int(input("Ingrese el numero de ruedas de la camioneta: "))
        velocidad = int(input("Ingrese la velocidad maxima de la camioneta: "))
        cilindrada = int(input("Ingrese el cilindraje de la camioneta: "))
        carga = int(input("Ingrese la carga de la camioneta: "))
        return Camioneta(color, ruedas, velocidad, cilindrada, carga)

class Bicicleta(Vehiculo):
    def __init__(self, color, ruedas, tipo):
        super().__init__(color, ruedas)
        self.tipo = tipo
        
    def crearbicicleta():
        color = input("Ingrese el color de la bicicleta: ")
        ruedas = int(input("Ingrese el numero de ruedas de la bicicleta: "))
        tipo = input("Ingrese el tipo de bicicleta: ")
        return Bicicleta(color, ruedas, tipo)

class Motocicleta(Bicicleta):
    def __init__(self, color, ruedas, tipo, velocidad, cilindrada):
        super().__init__(color, ruedas, tipo)
        self.velocidad = velocidad
        self.cilindrada = cilindrada

    def crearmoto():
        color = input("Ingrese el color de la moto: ")
        ruedas = int(input("Ingrese el numero de ruedas de la moto: "))
        tipo = input("Ingrese el tipo de moto: ")
        velocidad = int(input("Ingrese la velocidad maxima de la moto: "))
        cilindrada = int(input("Ingrese el cilindraje de la moto: "))
        return Motocicleta(color, ruedas, tipo, velocidad, cilindrada)

coche = Coche.crearcoche()
camioneta = Camioneta.crearcamioneta()
bicicleta = Bicicleta.crearbicicleta()
moto = Motocicleta.crearmoto()

ListaVehiculos = [coche, camioneta, bicicleta, moto]
           
def catalogar(vehiculos, ruedas = None):
    if ruedas is not None:
        print(f"Se han encontrado {len([v for v in vehiculos if v.ruedas == ruedas])} vehículos con {ruedas} ruedas:")
        for vehiculo in vehiculos:
            if vehiculo.ruedas == ruedas:
                print(f"Tipo de Vehiculo: {type(vehiculo).__name__}, Caracteristicas: {vars(vehiculo)}")
    else:
        for vehiculo in vehiculos:
            print(f"Tipo de Vehiculo: {type(vehiculo).__name__}, Caracteristicas: {vars(vehiculo)}")

print("\nTodos los vehículos:")
catalogar(ListaVehiculos)
print("\nVehículos con 4 ruedas:")
catalogar(ListaVehiculos, 4)
print("\nVehículos con 2 ruedas:")
catalogar(ListaVehiculos, 2)
print("\nVehículos con 0 ruedas:")
catalogar(ListaVehiculos, 0)

