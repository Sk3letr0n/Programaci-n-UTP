class SerVivo:
    def __init__(self, nombre, edad, reproduccion, crecimiento):
        self.__nombre = nombre
        self.__edad = edad
        self.__reproduccion = reproduccion
        self.__crecimiento = crecimiento

    def set_reproduccion(self, reproduccion):
        self.__reproduccion = reproduccion

    def get_reproduccion(self):
        return self.__reproduccion

    def reproducirse(self):
        print(f"{self.__nombre} se está reproduciendo de manera {self.__reproduccion}.")
