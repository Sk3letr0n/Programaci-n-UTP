''' 
Diseñe las siguientes entidades con al menos 4 atributos y al
menos dos métodos:
a. Avión
b. Celular
c. Asignatura
d. Ejercito
e. Silla
f. Audífonos
'''
# Hecho por: Steven Grisales López - 1034289634.
from io import *

def menu():
    while True:
          
        opcion = int(input('''
            Menú de opciones.
                1. Avión.
                2. Celular.
                3. Asignatura.
                4. Ejercito.
                5. Silla.
                6. Audífonos.
                0. Salir
            Ingrese una opción: '''))
        
        match opcion:
            
            case 1:
                avion = Avion("Airbus", 319, 156, "Blanco con Azul")
                avion.despegar()
                avion.aterrizar()
                avion.mostrarDatos()
            
            case 2:
                celular = Celular("Xiaomi", "Redmi 12", "Blanco", "Android")
                celular.llamar(3052456442)
                celular.enviar_mensaje(3116086466, "Hola que tal soy colosal")
                celular.mostrarDatos()
                
            case 3:
                asignatura = Asignatura("Programación", "IS553", 3, 4)
                asignatura.estudiar()
                asignatura.presentar_examen()
                asignatura.mostrarDatos()
                
            case 4:
                ejercito = Ejercito("ELN", "Infanteria", 20, "AK47")
                ejercito.atacar()
                ejercito.defender()
                ejercito.mostrarDatos()
                
            case 5:
                silla = Silla("Tailus", "GamerPRO", "Plástico", "Negra")
                silla.sentarse()
                silla.recostarse()
                silla.mostrarDatos()
                
            case 6:
                audifonos = Audifonos("Apple", "X-Max", "Blancos", "Bluetooth")
                audifonos.escuchar_musica()
                audifonos.contestar_llamada()
                audifonos.mostrarDatos()

                
            case 0:
                print("\n   Saliendo del programa...")
                exit()
                
            case _:
                print("\nOpción inválida. Por favor, seleccione una opción válida.")

# Entidad Avión.
class Avion:
    # Atributos.
    def __init__(self, marca, modelo, capacidad, color):
        self.marca = marca
        self.modelo = modelo
        self.capacidad = capacidad
        self.color = color

    # Métodos.
    def despegar(self):
        print(f"\nEl avión {self.marca} {self.modelo} ha despegado.")
        
        with open(r"Archivos\punto1.txt","w") as archivo:
            archivo.write(f"El avión {self.marca} {self.modelo} ha despegado." + "\n")

    def aterrizar(self):
        print(f"El avión {self.marca} {self.modelo} ha aterrizado.")
        
        with open(r"Archivos\punto1.txt","a") as archivo:
            archivo.write(f"El avión {self.marca} {self.modelo} ha aterrizado." + "\n")

    def mostrarDatos(self):
        print(f"Marca del avión: {self.marca}, Modelo del avión: {self.modelo}, Capacidad de pasajeros: {self.capacidad}, Color del avión: {self.color}.")
        
        with open(r"Archivos\punto1.txt","a") as archivo:
            archivo.write(f"Marca del avión: {self.marca}, Modelo del avión: {self.modelo}, Capacidad de pasajeros: {self.capacidad}, Color del avión: {self.color}." + "\n\n")

# Entidad Celular.
class Celular:
    # Atributos.
    def __init__(self, marca, modelo, color, sistema_operativo):
        self.marca = marca
        self.modelo = modelo
        self.color = color
        self.sistema_operativo = sistema_operativo

    # Métodos.
    def llamar(self, numero):
        print(f"\nLlamando al número {numero}...")
        
        with open(r"Archivos\punto1.txt","a") as archivo:
            archivo.write(f"Llamando al número {numero}..." + "\n")

    def enviar_mensaje(self, numero, mensaje):
        print(f"Enviando mensaje al número {numero}: {mensaje}")
        
        with open(r"Archivos\punto1.txt","a") as archivo:
            archivo.write(f"Enviando mensaje al número {numero}: {mensaje}" + "\n")

    def mostrarDatos(self):
        print(f"Marca del celular: {self.marca}, Modelo del celular: {self.modelo}, Color del celular: {self.color}, Sistema Operativo: {self.sistema_operativo}.")
        
        with open(r"Archivos\punto1.txt","a") as archivo:
            archivo.write(f"Marca del celular: {self.marca}, Modelo del celular: {self.modelo}, Color del celular: {self.color}, Sistema Operativo: {self.sistema_operativo}." + "\n\n")

# Entidad Asignatura.
class Asignatura:
    # Atributos.
    def __init__(self, nombre, codigo, creditos, intensidad_horaria):
        self.nombre = nombre
        self.codigo = codigo
        self.creditos = creditos
        self.intensidad_horaria = intensidad_horaria

    # Métodos.
    def estudiar(self):
        print(f"\nEstudiando la asignatura {self.nombre}...")
        
        with open(r"Archivos\punto1.txt","a") as archivo:
            archivo.write(f"Estudiando la asignatura {self.nombre}..." + "\n")

    def presentar_examen(self):
        print(f"Presentando examen de la asignatura {self.nombre}...")
        
        with open(r"Archivos\punto1.txt","a") as archivo:
            archivo.write(f"Presentando examen de la asignatura {self.nombre}..." + "\n")

    def mostrarDatos(self):
        print(f"Nombre de la asignatura: {self.nombre}, Código de la asignatura: {self.codigo}, Cantidad de créditos: {self.creditos}, Intensidad horaria: {self.intensidad_horaria} horas.")
        
        with open(r"Archivos\punto1.txt","a") as archivo:
            archivo.write(f"Nombre de la asignatura: {self.nombre}, Código de la asignatura: {self.codigo}, Cantidad de créditos: {self.creditos}, Intensidad horaria: {self.intensidad_horaria} horas." + "\n\n")

# Entidad Ejercito.
class Ejercito:
    # Atributos.
    def __init__(self, nombre, division, cantidad_soldados, armamento):
        self.nombre = nombre
        self.division = division
        self.cantidad_soldados = cantidad_soldados
        self.armamento = armamento

    # Métodos.
    def atacar(self):
        print(f"\nEl ejército {self.nombre} ha atacado.")
        
        with open(r"Archivos\punto1.txt","a") as archivo:
            archivo.write(f"El ejército {self.nombre} ha atacado." + "\n")

    def defender(self):
        print(f"El ejército {self.nombre} se ha defendido.")
        
        with open(r"Archivos\punto1.txt","a") as archivo:
            archivo.write(f"El ejército {self.nombre} se ha defendido." + "\n")

    def mostrarDatos(self):
        print(f"Nombre del ejercito: {self.nombre}, Tipo de divisiones: {self.division}, Cantidad de soldados: {self.cantidad_soldados}, Armamento de los soldados: {self.armamento}.")
        
        with open(r"Archivos\punto1.txt","a") as archivo:
            archivo.write(f"Nombre del ejercito: {self.nombre}, Tipo de divisiones: {self.division}, Cantidad de soldados: {self.cantidad_soldados}, Armamento de los soldados: {self.armamento}." + "\n\n")

# Entidad Silla.
class Silla:
    # Atributos.
    def __init__(self, marca, modelo, material, color):
        self.marca = marca
        self.modelo = modelo
        self.material = material
        self.color = color

    # Métodos.
    def sentarse(self):
        print(f"\nSentándose en la silla {self.marca} {self.modelo}...")
        
        with open(r"Archivos\punto1.txt","a") as archivo:
            archivo.write(f"Sentándose en la silla {self.marca} {self.modelo}..." + "\n")

    def recostarse(self):
        print(f"Recostándose en la silla {self.marca} {self.modelo}...")
        
        with open(r"Archivos\punto1.txt","a") as archivo:
            archivo.write(f"Recostándose en la silla {self.marca} {self.modelo}..." + "\n")

    def mostrarDatos(self):
        print(f"Marca de la silla: {self.marca}, Modelo de la silla: {self.modelo}, Material de la silla: {self.material}, Color de la silla: {self.color}.")
        
        with open(r"Archivos\punto1.txt","a") as archivo:
            archivo.write(f"Marca de la silla: {self.marca}, Modelo de la silla: {self.modelo}, Material de la silla: {self.material}, Color de la silla: {self.color}." + "\n\n")

# Entidad Audífonos.
class Audifonos:
    # Atributos.
    def __init__(self, marca, modelo, color, tipo_conexion):
        self.marca = marca
        self.modelo = modelo
        self.color = color
        self.tipo_conexion = tipo_conexion

    # Métodos.
    def escuchar_musica(self):
        print(f"\nEscuchando música con los audífonos {self.marca} {self.modelo}...")
        
        with open(r"Archivos\punto1.txt","a") as archivo:
            archivo.write(f"Escuchando música con los audífonos {self.marca} {self.modelo}..." + "\n")

    def contestar_llamada(self):
        print(f"Contestando llamada con los audífonos {self.marca} {self.modelo}...")
        
        with open(r"Archivos\punto1.txt","a") as archivo:
            archivo.write(f"Contestando llamada con los audífonos {self.marca} {self.modelo}..." + "\n")

    def mostrarDatos(self):
        print(f"Marca de audífonos: {self.marca}, Modelo de los audífonos: {self.modelo}, Color de los audífonos: {self.color}, Tipo de conexión: {self.tipo_conexion}.")
        
        with open(r"Archivos\punto1.txt","a") as archivo:
            archivo.write(f"Marca de audífonos: {self.marca}, Modelo de los audífonos: {self.modelo}, Color de los audífonos: {self.color}, Tipo de conexión: {self.tipo_conexion}." + "\n\n")

menu()