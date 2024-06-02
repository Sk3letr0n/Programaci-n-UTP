class usuario:
    def __init__(self,nombre,edad,direccion):
        self.nombre=nombre
        self.edad=edad
        self.direccion=direccion
    def mostrardatos(self):
        return f"nombre: {self.nombre} edad: {self.edad} direccion: {self.direccion}"


class estudiante(usuario):
    def __init__(self,curso):
        super().__init__(nombre,edad,direccion)
        self.curso=curso
    def mostrardatos(self):
        dato=super().mostrardatos()
        return f"{dato} curso:{self.curso}"

class profesor(estudiante):
    def __init__(self):
        super().__init__()

pepito= estudiante("pepito",45,"utp","programacion")
print(pepito.mostrardatos())
    
    