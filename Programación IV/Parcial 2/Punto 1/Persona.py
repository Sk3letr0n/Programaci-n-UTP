class Persona():
    def __init__(self, nombre, edad, RUT, sexo, peso, altura):
        self.__nombre = nombre
        self.__edad = edad
        self.__RUT = RUT
        self.__sexo = sexo
        self.__peso = peso
        self.__altura = altura
        
    def get_nombre(self):
        return self.__nombre
    
    def set_nombre(self):
        self.__nombre = input("Nombre: ")
        

    def get_edad(self):
        return self.__edad
    
    def set_edad(self):
        self.__edad = int(input("Edad: "))
        

    def get_rut(self):
        return self.__RUT
    
    def set_rut(self):
        self.__RUT = input("RUT: ")
        

    def get_sexo(self):
        return self.__sexo
    
    def set_sexo(self):
        self.__sexo = input("Sexo (H hombre, M mujer): ")
        

    def get_peso(self):
        return self.__peso
    
    def set_peso(self):
        self.__peso = float(input("Peso (kg): "))
        

    def get_altura(self):
        return self.__altura
    
    def set_altura(self):
        self.__altura = float(input("Altura: "))