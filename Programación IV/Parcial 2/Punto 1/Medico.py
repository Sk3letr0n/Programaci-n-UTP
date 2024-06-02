from Persona import Persona

class Medico(Persona):
    def __init__(self, nombre, edad, RUT, sexo, peso, altura, precioConsulta, especialidad):
        super().__init__(nombre, edad, RUT, sexo, peso, altura)
        self.__precioConsulta = precioConsulta
        self.__especialidad = especialidad
        
    def get_precio_consulta(self):
        return self.__precioConsulta
    
    def set_precio_consulta(self):
        self.__precioConsulta = float(input("Precio de la consulta: "))

    def get_especialidad(self):
        return self.__especialidad
    
    def set_especialidad(self):
        self.__especialidad = input("Especialidad del medico: ")