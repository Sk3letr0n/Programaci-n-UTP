from Sucursal import Sucursal

class Empleado(Sucursal):
    def __init__(self, codigo, nombre, direccion, telefono, empleado_id, salario):
        super().__init__(codigo, nombre, direccion, telefono)
        self.__empleado_id = empleado_id
        self.__salario = salario

    # Getters
    def get_empleado_id(self):
        return self.__empleado_id

    def get_salario(self):
        return self.__salario

    # Setter
    def set_salario(self, salario):
        if salario >= 0:
            self.__salario = salario

    def calcular_salario_anual(self):
        return self.__salario * 12
    
    