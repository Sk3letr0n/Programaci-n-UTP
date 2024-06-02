class Animal:
    def __init__(self, nombre, edad, especie, habitat, alimentacion):
        self.__nombre = nombre
        self.__edad = edad
        self.__especie = especie
        self.__habitat = habitat
        self.__alimentacion = alimentacion

    def set_nombre(self, nombre):
        self.__nombre = nombre

    def get_nombre(self):
        return self.__nombre

    def comer(self):
        print(f"{self.__nombre} está comiendo {self.__alimentacion}.")

    def dormir(self):
        print(f"{self.__nombre} está durmiendo.")
