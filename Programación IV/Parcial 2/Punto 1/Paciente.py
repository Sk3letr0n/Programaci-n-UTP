from Persona import Persona

class Paciente(Persona):
    def __init__(self, nombre, edad, RUT, sexo, peso, altura, fechaPrimeraConsulta, medicoTratante):
        super().__init__(nombre, edad, RUT, sexo, peso, altura)
        self.__fechaPrimeraConsulta = fechaPrimeraConsulta
        self.__medicoTratante = medicoTratante
        
    def get_fecha_primera_consulta(self):
        return self.__fechaPrimeraConsulta
    
    def set_fecha_primera_consulta(self):
        self.__fechaPrimeraConsulta = input("Fecha primera consulta: ")
        
        
    def get_medico_tratante(self):
        return self.__medicoTratante
    
    def set_medico_tratante(self, medicoTratante):
        self.__medicoTratante = medicoTratante
    
    
    def calcularIMC(self):
        altura_metros = self._Persona__altura / 100 # Convertir la altura a metros
        imc = self._Persona__peso / (altura_metros ** 2) # Calcular el IMC
        
        # Por debajo del peso
        if imc < 18.5:
            return -1 
        # Peso ideal
        elif 18.5 <= imc < 24.9:
            return 0
        # Sobrepeso
        else:
            return 1
    
    
    def esMayorDeEdad(self):
        return self._Persona__edad >= 18 # Devolver True si es mayor de edad, False si es menor de edad.
 

    def comprobarSexo(self, sexo):
        if sexo.upper() == 'H' or sexo.upper() == 'M': # Comprobar si el sexo es correcto
            return sexo.upper() # Devolver el sexo en mayúsculas.
        else:
            sexo = "H"
            return 'H' # Si el sexo no es correcto, devolver H por defecto.