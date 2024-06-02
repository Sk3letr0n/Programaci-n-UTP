class estudiante:
    
    nombre = ""
    edad = 0
    
    def mostrarDatos(self):
        print(f"nombre: {self.nombre} edad: {self.edad}")
        
    def cambioNombre(self):
        nuevoNombre = str(input("Ingrese el nuevo nombre: "))
        self.nombre = nuevoNombre
        
    def cambioEdad(self):
        nuevaEdad = int(input("Ingrese la nueva edad: "))
        self.edad = nuevaEdad
        
pepito = estudiante()

pepito.cambioNombre()
pepito.cambioEdad()
pepito.mostrarDatos()
