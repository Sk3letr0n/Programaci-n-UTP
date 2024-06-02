from Sucursal import Sucursal

class Cuenta(Sucursal):
    def __init__(self, codigo, nombre, direccion, telefono, cuenta_id, saldo):
        super().__init__(codigo, nombre, direccion, telefono)
        self.__cuenta_id = cuenta_id
        self.__saldo = saldo

    # Getters
    def get_cuenta_id(self):
        return self.__cuenta_id

    def get_saldo(self):
        return self.__saldo

    def depositar(self, monto):
        self.__saldo += monto

    def retirar(self, monto):
        if monto <= self._saldo:
            self.__saldo -= monto
        else:
            print("Saldo insuficiente")

    def consultar_saldo(self):
        return self.__saldo

class Tarjeta(Cuenta):
    def __init__(self, codigo, nombre, direccion, telefono, cuenta_id, saldo, numero_tarjeta, tipo):
        super().__init__(codigo, nombre, direccion, telefono, cuenta_id, saldo)
        self.__numero_tarjeta = numero_tarjeta
        self.__tipo = tipo

    # Getters
    def get_numero_tarjeta(self):
        return self.__numero_tarjeta

    def get_tipo(self):
        return self.__tipo
