class User:
    
    def __init__(self,nombre,edad):
        self.__nombre=nombre
        self.__edad=edad
    def get_nombre(self):
        return self.__nombre
    def set_nombre(self,nombre):
        self.__nombre=nombre
        
class medico(User):
    pass      
        
        
pepito=User("pepito",100)
cesar=medico("cesar",100)


print(pepito.get_nombre())
pepito.set_nombre("otro nombre")
print(pepito.get_nombre())