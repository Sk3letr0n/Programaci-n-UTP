
class Animal:
    def __init__(self,nombre,peso):
        self.nombre=nombre
        self.peso=peso
    def metodo(self):
        return f"nombre:{self.nombre} peso:{self.peso}"