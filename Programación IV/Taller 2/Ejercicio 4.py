'''
Diseñe las siguientes entidades con al menos 5 atributos y al
menos dos métodos:
a. Libro
b. Casa
c. Película
d. Bodega
e. Lámpara
f. Modem
g. Router
h. Maletín
i. Paciente Oncológico
j. Gato
'''
# Hecho por: Steven Grisales López - 1034289634
from io import *

def menu():
    while True:
          
        opcion = int(input('''
            Menú de opciones.
                1. Libro
                2. Casa
                3. Película
                4. Bodega
                5. Lámpara
                6. Modem
                7. Router
                8. Maletín
                9. Paciente Oncológico
                10. Gato
                0. Salir
            Ingrese una opción: '''))
        
        match opcion:
            
            case 1:
                archivo = open(r"punto4.txt", "a")  # Esta con relative path (Cambiar si no funciona).
                libro = Libro()
                libro.cambiarAutor()
                libro.añadirPaginas()
                libro.mostrarDatos()
                archivo.close()
            
            case 2:
                archivo = open(r"punto4.txt", "a")  # Esta con relative path (Cambiar si no funciona).
                casa = Casa()
                casa.comprarCasa()
                casa.construirPisos()
                casa.mostrarDatos()
                archivo.close()
                
            case 3:
                archivo = open(r"punto4.txt", "a")  # Esta con relative path (Cambiar si no funciona).
                pelicula = Pelicula()
                pelicula.cambiarDuracion()
                pelicula.sueño()
                pelicula.mostrarDatos()
                archivo.close()
                
            case 4:
                archivo = open(r"punto4.txt", "a")  # Esta con relative path (Cambiar si no funciona).
                bodega = Bodega()
                bodega.añadirProducto()
                bodega.verificarProductos()
                bodega.mostrarDatos()
                archivo.close()
                
            case 5:
                archivo = open(r"punto4.txt", "a")  # Esta con relative path (Cambiar si no funciona).
                lampara = Lampara()
                lampara.cambiarColor()
                lampara.prenderLampara()
                lampara.mostrarDatos()
                archivo.close()
                
            case 6:
                archivo = open(r"punto4.txt", "a")  # Esta con relative path (Cambiar si no funciona).
                modem = Modem()
                modem.cambiarProveedor()
                modem.verificarVelocidad()
                modem.mostrarDatos()
                archivo.close()
                
            case 7:
                archivo = open(r"punto4.txt", "a")  # Esta con relative path (Cambiar si no funciona).
                router = Router()
                router.subirFrecuencia()
                router.cambiarProveedor()
                router.mostrarDatos()
                archivo.close()
                
            case 8:
                archivo = open(r"punto4.txt", "a")  # Esta con relative path (Cambiar si no funciona).
                maletin = Maletin()
                maletin.agregarBolsillo()
                maletin.verificarEstado()
                maletin.mostrarDatos()
                archivo.close()
                
            case 9:
                archivo = open(r"punto4.txt", "a")  # Esta con relative path (Cambiar si no funciona).
                paciente = PacienteOncologico()
                paciente.cambiarEtapa()
                paciente.cambiarCancer()
                paciente.mostrarDatos()
                archivo.close()
                
            case 10:
                archivo = open(r"punto4.txt", "a")  # Esta con relative path (Cambiar si no funciona).
                gato = Gato()
                gato.cambiarPeso()
                gato.llamarGato()
                gato.mostrarDatos()
                archivo.close()
                
            case 0:
                print("\n   Saliendo del programa...")
                exit()
                
            case _:
                print("\nOpción inválida. Por favor, seleccione una opción válida.")

archivo = open(r"punto4.txt", "a")  # Esta con relative path (Cambiar si no funciona).

class Libro:
    titulo = "Don Quijote de la Mancha"
    autor = "Miguel de Cervantes Saavedra"
    año = 2004
    editorial = "Círculo de Lectores, Galaxia Gutenberg"
    paginas = 400
    
    def mostrarDatos(self):
        print(f"Título del libro: {self.titulo}, Autor del libro: {self.autor}, Año de publicación: {self.año}, Editorial: {self.editorial}, Cantidad de páginas: {self.paginas}.")
        archivo.write(f"Libro: {self.titulo}, {self.autor}, {self.año}, {self.editorial}, {self.paginas}\n")
        
    def cambiarAutor(self):
        nuevoAutor = str(input("\nIngrese el nuevo autor: "))
        self.autor = nuevoAutor
        archivo.write(f"\nSe ha cambiado el autor del libro a {nuevoAutor}.\n")
        
    def añadirPaginas(self):
        nuevasPaginas = int(input("Ingrese la cantidad de páginas que desea añadir: "))
        self.paginas += nuevasPaginas # Añadir las paginas al libro actual.
        archivo.write(f"Se han añadido {nuevasPaginas} paginas al libro.\n")
        
    
class Casa:
    habitaciones = 5
    tam_construccion = 280 # m^2
    pisos = 2
    direccion = "Calle 10 # 20-30"
    precio = 1000000
    
    def mostrarDatos(self):
        print(f"Cantidad de habitaciones: {self.habitaciones}, Tamaño de la construccion: {self.tam_construccion}, Cantidad de pisos: {self.pisos}, Direccion: {self.direccion}, Precio: {self.precio}.")
        archivo.write(f"Casa: {self.habitaciones}, {self.tam_construccion}, {self.pisos}, {self.direccion}, {self.precio}\n")
        
    def comprarCasa(self):
        presupuesto = int(input("\nIngrese el presupuesto con el que cuenta: "))
        if presupuesto >= self.precio: # Verificar si el presupuesto es suficiente para comprar la casa
            print("La casa ha sido comprada.")
            archivo.write(f"\nLa casa ha sido comprada.\n")
        else:
            print("El presupuesto no es suficiente para comprar la casa.")
            archivo.write(f"\nEl presupuesto no es suficiente para comprar la casa.\n")
        
    def construirPisos(self):
        nuevosPisos = int(input("Ingrese la cantidad de pisos que desea añadir: "))
        self.pisos += nuevosPisos # Añadir los pisos a la casa actual.
        self.tam_construccion = self.tam_construccion * self.pisos # Aumentar el tamaño de la construccion.
        archivo.write(f"Se han añadido {nuevosPisos} pisos a la casa y se ha modificado el tamaño de la construccion a: {self.tam_construccion}.\n")
        
    
class Pelicula:
    titulo = "El señor de los anillos"
    director = "Peter Jackson"
    año = 2001
    genero = "Ficcion de Aventuras"
    duracion = 178 # En minutos
    
    def mostrarDatos(self):
        print(f"Título de la pelicula: {self.titulo}, Director de la película: {self.director}, Año de publicación: {self.año}, Genero de la pelicula: {self.genero}, Duracion de la pelicula: {self.duracion}.")
        archivo.write(f"Pelicula: {self.titulo}, {self.director}, {self.año}, {self.genero}, {self.duracion}\n")
        
    def cambiarDuracion(self):
        nuevaDuracion = int(input("\nIngrese la duracion de la pelicula: "))
        self.duracion = nuevaDuracion # Cambiar la duracion de la pelicula.
        archivo.write(f"\nSe ha cambiado la duracion de la pelicula a {nuevaDuracion}.\n")
  
    def sueño(self):
        if self.duracion > 180: # Verificar si la pelicula es muy larga.
            print("La pelicula es muy larga, te quedarás dormido.")
            archivo.write(f"La pelicula dura {self.duracion}, te quedarás dormido.\n")
        else:
            print("No te queda tiempo para dormir, la pelicula es corta.")
            archivo.write(f"La pelicula dura {self.duracion}, no te quedarás dormido.\n")
    
    
class Bodega:
    nombre = "Mesa tra'"
    ubicacion = "Calle 16 Av. 30 de Agosto"
    estado = "Abierto"
    productos = ["Arroz", "Frijoles", "Aceite", "Azucar", "Sal"]
    cantidad = len(productos)
    
    def mostrarDatos(self):
        print(f"Nombre de la Bodega: {self.nombre}, Ubicacion de la Bodega: {self.ubicacion}, Estado de la Bodega: {self.estado}, Productos: {self.productos}, Cantidad de productos: {self.productos}.")
        archivo.write(f"Bodega: {self.nombre}, {self.ubicacion}, {self.estado}, {self.productos}, {self.cantidad}\n")
                    
    def añadirProducto(self):
        if self.estado == "Cerrado": # Verificar si la bodega esta cerrada.
            print("\nLa bodega se encuentra cerrada, no se pueden añadir productos.")
            archivo.write(f"La bodega se encuentra cerrada, no se pueden añadir productos.\n")
        else:
            nuevoProd = str(input("\nIngrese el producto que desea añadir: "))
            self.productos.append(nuevoProd)
            self.cantidad += 1 # Aumentar la cantidad de productos.
            archivo.write(f"\nSe ha añadido el producto {nuevoProd} a la bodega y ha aumentado la cantidad de productos.\n")
        
    def verificarProductos(self):
        producto = str(input("Ingrese el producto que desea buscar: "))
        if producto in self.productos: # Verificar si el producto se encuentra en la bodega.
            print("El producto si se encuentra disponible.")
            archivo.write(f"El producto {producto} si se encuentra disponible.\n")
        else:
            print("El producto no se encuentra disponible.")
            archivo.write(f"El producto {producto} no se encuentra disponible.\n")
      
class Lampara:
    material = "Vidrio"
    color = "Blanco"
    tipo = "De techo"
    precio = 50000 # COP
    estado = "Apagada"
    
    def mostrarDatos(self):
        print(f"Material de la lampara: {self.material}, Color de la lampara: {self.color}, Tipo de lampara: {self.tipo}, Precio de la lampara: {self.precio}, Estado de la lampara: {self.estado}.")
        archivo.write(f"Lampara: {self.material}, {self.color}, {self.tipo}, {self.precio}, {self.estado}\n")
    
    def cambiarColor(self):
        nuevoColor = str(input("\nIngrese el nuevo color de la lampara: "))
        self.color = nuevoColor # Cambiar el color de la lampara.
        archivo.write(f"\nSe ha cambiado el color de la lampara a {nuevoColor}.\n")
        
    def prenderLampara(self):
        if self.estado == "Apagada": # Verificar si la lampara esta apagada.
            print("La lampara ha sido prendida.")
            self.estado = "Prendida"
            archivo.write(f"La lampara ha sido prendida.\n")
        else:
            print("La lampara ya se encuentra prendida.")
            archivo.write(f"La lampara ya se encuentra prendida.\n")
          
class Modem:
    proveedor = "Claro"
    velocidad_transferencia = 300 #Mbps
    Seguridad_red = "WPA2" 
    conexion = "Ethernet"
    estado = "Activo"
    
    def mostrarDatos(self):
        print(f"Proveedor del modem: {self.proveedor}, Velocidad de transferencia: {self.velocidad_transferencia}, Seguridad de la red: {self.Seguridad_red}, Tipo de conexion: {self.conexion}, Estado del modem: {self.estado}.")
        archivo.write(f"Modem: {self.proveedor}, {self.velocidad_transferencia}, {self.Seguridad_red}, {self.conexion}, {self.estado}\n")
        
    def cambiarProveedor(self):
        nuevoProveedor = str(input("\nIngrese el nuevo proveedor: "))
        self.proveedor = nuevoProveedor # Cambiar el proveedor del modem.
        archivo.write(f"\nSe ha cambiado el proveedor del modem a {nuevoProveedor}.\n")
    
    def verificarVelocidad(self):
        if self.conexion == "Ethernet": # Verificar si la conexion es Ethernet.
            print(f"La velocidad de transferencia es de {self.velocidad_transferencia} Mbps.")
            archivo.write(f"La velocidad de transferencia es de {self.velocidad_transferencia} Mbps.\n")
        else:
            print("La velocidad de transferencia es inferior a la establecida, cambie la conexion a Ethernet para obtener una velocidad optima.")
            archivo.write(f"La velocidad de transferencia es inferior a la establecida, cambie la conexion a Ethernet para obtener una velocidad optima.\n")
            
class Router:
    proovedor = "Tigo UNE"
    MAC = "D7-A7-0F-E7-04-13"
    velocidad_transferencia = 100 # Mbps 1GB = 1000Mbp
    frecuencia = 2.4 # GHz
    estado = "Activo"
    
    def mostrarDatos(self):
        print(f"Proveedor del router: {self.proovedor}, MAC del router: {self.MAC}, Velocidad de transferencia: {self.velocidad_transferencia}, Frecuencia del router: {self.frecuencia}, Estado del router: {self.estado}.")
        archivo.write(f"Router: {self.proovedor}, {self.MAC}, {self.velocidad_transferencia}, {self.frecuencia}, {self.estado}\n")   
        
    def subirFrecuencia(self):
        opcion = str(input("\nDesea cambiar la frecuencia del router a 5GHz (Si/No): "))
        
        if (opcion == "Si"): # Verificar si el usuario desea cambiar la frecuencia.
            nuevaFrecuencia = 5
            self.frecuencia = nuevaFrecuencia
            print(f"Se ha cambiado la frecuencia a {nuevaFrecuencia} GHz.")
            self.velocidad_transferencia = 1000 # Cambiar la velocidad de transferencia a 1000 Mbps.
            archivo.write(f"\nSe ha cambiado la frecuencia a {nuevaFrecuencia} GHz y la velocidad de transferencia a 1000 Mbps.\n")
        else:
            print("La frecuencia no ha sido cambiada.")
            archivo.write(f"\nLa frecuencia no ha sido cambiada\n.")
            
    def cambiarProveedor(self):
        nuevoProveedor = str(input("Ingrese el nuevo proveedor: "))
        self.proovedor = nuevoProveedor # Cambiar el proveedor del router.
        archivo.write(f"Se ha cambiado el proveedor del router a {self.proovedor}.\n")
    
class Maletin:
    material = "Cuero"
    color = "Negro"
    tamaño = "Mediano"
    bolsillos = 2
    estado = "Perfecto"

    def mostrarDatos(self):
        print(f"Material del maletín: {self.material}, Color del maletín: {self.color}, Tamaño del maletín: {self.tamaño}, Cantidad de bolsillos: {self.bolsillos}, Estado del maletín: {self.estado}.")
        archivo.write(f"Maletin: {self.material}, {self.color}, {self.tamaño}, {self.bolsillos}, {self.estado}\n")
        
    def agregarBolsillo(self):
        cantidad = int(input("\nIngrese la cantidad de bolsillos que desea agregar: "))
        self.bolsillos += cantidad #  Agregar bolsillos al maletín.
        archivo.write(f"\nLos bolsillos aumentaron a {self.bolsillos}.\n")
        
    def verificarEstado(self):
        condicion = str(input("Ingrese el estado del maletin(Perfecto/Desgastado): "))
            
        if condicion != "Perfecto" and condicion != "Desgastado": # Comprobamos las posibles respuestas
            print("Error, por favor ingrese una respuesta valida.")
            
        elif condicion == "Perfecto": # Verificar si el maletin esta en perfecto estado.
            print("El maletin se encuentra en perfecto estado.")
            archivo.write(f"El maletin se encuentra en perfecto estado.\n")
                
        else:
            self.bolsillos = self.bolsillos / 2 # Reducir la cantidad de bolsillos a la mitad.
            print(f"El maletin pierde la mitad de los bolsillos: {self.bolsillos}.")
            archivo.write(f"El maletin pierde la mitad de los bolsillos: {self.bolsillos}.\n")
    
class PacienteOncologico:
    nombre = "Rodrigo"
    edad = 52
    tipo_cancer = "Cancer de prostata"
    estado_paciente = "Estable"
    etapa_cancer = 1
    
    def mostrarDatos(self):
        print(f"Nombre del paciente: {self.nombre}, Edad del paciente: {self.edad}, Tipo de cancer: {self.tipo_cancer}, Estado del paciente: {self.estado_paciente}, Etapa del cancer: {self.etapa_cancer}.")
        archivo.write(f"Paciente Oncologico: {self.nombre}, {self.edad}, {self.tipo_cancer}, {self.estado_paciente}, {self.etapa_cancer}\n")
        
    def cambiarEtapa(self):
        nuevaEtapa = int(input("\nIngrese la nueva etapa del cancer: "))
        self.etapa_cancer = nuevaEtapa # Cambiar la etapa del cancer.
        
        if self.etapa_cancer > 3: # Verificar si el paciente se encuentra en estado critico.
            print("El paciente se encuentra en estado critico.")
            self.estado_paciente = "Critico"
            archivo.write(f"\nEl paciente se encuentra en estado critico.\n")
        else:
            print(f"El paciente se encuentra en la etapa {self.etapa_cancer} del cancer.")
            self.estado_paciente = "Estable"
            archivo.write(f"\nEl paciente se encuentra en la etapa {self.etapa_cancer} del cancer.\n")
            
    def cambiarCancer(self):
        nuevoCancer = str(input("Ingrese el nuevo tipo de cancer: "))
        self.tipo_cancer = nuevoCancer
        archivo.write(f"El paciente ahora tiene {nuevoCancer}.\n")
    
class Gato:
    nombre = "Yoru"
    edad = 5
    color = "Naranja con Blanco"
    raza = "Persa"
    peso = 4.5

    def mostrarDatos(self):
        print(f"Nombre del gato: {self.nombre}, Edad del gato: {self.edad}, Color del gato: {self.color}, Raza del gato: {self.raza}, Peso del gato: {self.peso}.")
        archivo.write(f"Gato: {self.nombre}, {self.edad}, {self.color}, {self.raza}, {self.peso}\n")
        
    def cambiarPeso(self):
        nuevoPeso = int(input("\nIngrese el nuevo peso del gato: "))
        self.peso = nuevoPeso
        
        if self.peso > 5: # Verificar si el gato se encuentra obeso.
            print("El gato se encuentra obeso, pongalo a dieta")
            archivo.write(f"\nEl gato se encuentra obeso, pongalo a dieta.\n")
        else:
            print("El gato se encuentra en un peso saludable")
            archivo.write(f"\nEl gato se encuentra en un peso saludable.\n")
            
    def llamarGato(self):
        print(f"{self.nombre} ha venido a ti")
        archivo.write(f"{self.nombre} ha venido a ti.\n")

menu()