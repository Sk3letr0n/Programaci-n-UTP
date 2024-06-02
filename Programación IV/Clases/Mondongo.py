class Estudiante:
    def __init__(self, nombre, edad, programa, universidad = "utp"):
        self.nombre = nombre
        self.edad = edad
        self.programa = programa
        self.universidad = universidad

    def mostrarDatos(self):
        print(f"Nombre: {self.nombre} - Edad: {self.edad} - Programa: {self.programa} - Universidad: {self.universidad}")

    def modificarDato(self, dato):

        opcion = int(input('''Ingrese una opcion:
                              1. Modificar Nombre
                              2. Modificar Edad
                              3. Modificar Programa  
                              4. Modficar Universidad
                              5. Salir
                              Opcion: '''))
        match opcion:
            case 1:
                self.nombre = dato
                pass 
            case 2:
                self.edad = dato
                pass 
            case 3:
                self.programa = dato
                pass 
            case 4:
                self.universidad = dato
                pass 
        
Ejemplo1 = Estudiante("Tulio", 56, "Ingeniria en Sistemas")
Ejemplo1.mostrarDatos()
Ejemplo1.modificarDato(dato="penedol")
Ejemplo1.mostrarDatos()