from Animal import Animal
from SerVivo import SerVivo

class Mamifero(Animal, SerVivo):
    def __init__(self, nombre, edad, especie, habitat, alimentacion, pelaje, reproduccion):
        Animal.__init__(self, nombre, edad, especie, habitat, alimentacion)
        SerVivo.__init__(self, nombre, edad, reproduccion, "Vivíparo")
        self.__pelaje = pelaje

    def set_pelaje(self, pelaje):
        self.__pelaje = pelaje

    def get_pelaje(self):
        return self.__pelaje

    def amamantar(self):
        print(f"{self.get_nombre()} está amamantando a sus crías.")

class Ave(Animal, SerVivo):
    def __init__(self, nombre, edad, especie, habitat, alimentacion, color_plumaje, reproduccion):
        Animal.__init__(self, nombre, edad, especie, habitat, alimentacion)
        SerVivo.__init__(self, nombre, edad, reproduccion, "Ovíparo")
        self.__color_plumaje = color_plumaje

    def set_color_plumaje(self, color_plumaje):
        self.__color_plumaje = color_plumaje

    def get_color_plumaje(self):
        return self.__color_plumaje

    def volar(self):
        print(f"{self.get_nombre()} está volando.")

class Pez(Animal, SerVivo):
    def __init__(self, nombre, edad, especie, habitat, alimentacion, tipo_agua, reproduccion):
        Animal.__init__(self, nombre, edad, especie, habitat, alimentacion)
        SerVivo.__init__(self, nombre, edad, reproduccion, "Ovíparo")
        self.__tipo_agua = tipo_agua

    def set_tipo_agua(self, tipo_agua):
        self.__tipo_agua = tipo_agua

    def get_tipo_agua(self):
        return self.__tipo_agua

    def nadar(self):
        print(f"{self.get_nombre()} está nadando en agua {self.__tipo_agua}.")

class Reptil(Animal, SerVivo):
    def __init__(self, nombre, edad, especie, habitat, alimentacion, temperatura_cuerpo, reproduccion):
        Animal.__init__(self, nombre, edad, especie, habitat, alimentacion)
        SerVivo.__init__(self, nombre, edad, reproduccion, "Ovíparo")
        self.__temperatura_cuerpo = temperatura_cuerpo

    def set_temperatura_cuerpo(self, temperatura_cuerpo):
        self.__temperatura_cuerpo = temperatura_cuerpo

    def get_temperatura_cuerpo(self):
        return self.__temperatura_cuerpo

    def tomar_sol(self):
        print(f"{self.get_nombre()} está tomando el sol para regular su temperatura.")

class Anfibio(Animal, SerVivo):
    def __init__(self, nombre, edad, especie, habitat, alimentacion, tipo_piel, reproduccion):
        Animal.__init__(self, nombre, edad, especie, habitat, alimentacion)
        SerVivo.__init__(self, nombre, edad, reproduccion, "Ovovivíparo")
        self.__tipo_piel = tipo_piel

    def set_tipo_piel(self, tipo_piel):
        self.__tipo_piel = tipo_piel

    def get_tipo_piel(self):
        return self.__tipo_piel

    def saltar(self):
        print(f"{self.get_nombre()} está saltando.")
