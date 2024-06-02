from Sucursal import Sucursal

class Cliente(Sucursal):
    def __init__(self, codigo, nombre, direccion, telefono, cliente_id):
        super().__init__(codigo, nombre, direccion, telefono)
        self.__cliente_id = cliente_id

    # Getter
    def get_cliente_id(self):
        return self.__cliente_id

    def solicitar_tarjeta(self):
        print("Solicitud de tarjeta realizada")