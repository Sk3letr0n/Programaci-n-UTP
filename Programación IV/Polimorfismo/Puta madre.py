# Ejercicio

class Usuario():
    def __init__(self, nombre, cedula, edad):
        self.nombre = nombre
        self.cedula = cedula
        self.edad = edad
        
    def mostrar_datos(self):
        print(f"Nombre: {self.nombre}, Cedula: {self.cedula}, Edad: {self.edad}")
        
class Medico(Usuario):
    def __init__(self, salario, experiencia, universidad):
        self.salario = salario
        self.experiencia = experiencia
        self.universidad = universidad
        
        super().__init__(self.nombre, self.cedula, self.edad) 
        
    def calcular_salario(self):
        pass
    
    def contrato(self):
        pass

class Especialista(Medico):
    def __init__(self, especialidad, residencia):
        self.especialidad = especialidad
        self.residencia = residencia
        
        super().__init__(self.salario, self.experiencia, self.universidad)
        
    def calcular_salario(self):
        return super().calcular_salario()
    
    def contrato(self):
        return super().contrato()


class Enfermera(Usuario):
    def __init__(self, salario, experiencia, universidad):
        self.salario = salario
        self.experiencia = experiencia
        self.universidad = universidad
        
        super().__init__(self.nombre, self.cedula, self.edad) 
    
    def calcular_salario(self):
        pass
    
    def tipo_contrato(self):
        pass
    
class Auxiliar(Enfermera):
    def __init__(self):
        super().__init__(self.salario, self.cedula, self.edad)
        
    def calcular_salario(self):
        return super().calcular_salario()
    
    def tipo_contrato(self):
        return super().tipo_contrato()

    