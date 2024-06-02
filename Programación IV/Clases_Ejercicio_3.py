class Sucursal:
    def __init__(self, codigo, nombre, direccion, telefono):
        self.__codigo = codigo
        self.__nombre = nombre
        self.__direccion = direccion
        self.__telefono = telefono

    def Get_Codigo_Sucursal(self):
        return self.__codigo
    
    def Get_Nombre_Sucursal(self):
        return self.__nombre
    
    def Get_Direccion_Sucursal(self):
        return self.__direccion
    
    def Get_Telefono_Sucursal(self):
        return self.__telefono
    
    
    def Set_Sucursal(self):
        self.__codigo = input("Ingrese el codigo de la sucursal: ")
        self.__nombre = input("Ingrese el nombre de la sucursal: ")
        self.__direccion = input("Ingrese la direccion de la sucursal: ")
        self.__telefono = input("Ingrese el telefono de la sucursal: ")  
        
        with open("Sucursales.txt", "a") as file:
            file.write("-------------------\n")
            file.write(f"Codigo: {self.Get_Codigo_Sucursal()}\n")
            file.write(f"Nombre: {self.Get_Nombre_Sucursal()}\n")
            file.write(f"Direccion: {self.Get_Direccion_Sucursal()}\n")
            file.write(f"Telefono: {self.Get_Telefono_Sucursal()}\n")
            file.write("-------------------")  
        
    def Escoger_Sucursal(self):
        Buscar = input("Ingrese el codigo de la sucursal: ")
        Encontrada = False
        with open("Sucursales.txt", "r") as file:
            for linea in file:
                if "Codigo" in linea:
                    codigo = linea.split(":")[1].strip()
                elif "Nombre" in linea:
                    nombre = linea.split(":")[1].strip()
                elif "Direccion" in linea:
                    direccion = linea.split(":")[1].strip()
                elif "Telefono" in linea:
                    telefono = linea.split(":")[1].strip()
                    if codigo == Buscar:
                        print(f"Sucursal encontrada:\n Codigo: {codigo}, Nombre: {nombre}, Dirección: {direccion}, Teléfono: {telefono}")
                        Encontrada = True
            if not Encontrada:
                print("Sucursal no encontrada.")  
            
        self.__codigo = codigo
        self.__nombre = nombre
        self.__direccion = direccion
        self.__telefono = telefono
    
    def Crear_Escoger(self):
        while True:
            print("Ingrese '1' para Crear una nueva Sucursal")
            print("Ingrese '2' para Escoger una Sucursal existente")
            opcion = int(input())
            
            if opcion == 1:          
                self.Set_Sucursal()
                break
                
            elif opcion == 2:
                self.Escoger_Sucursal() 
                break              
            
            else:
                print("Opcion no valida\n\n")  
                
def Eliminar_Sucursal(codigo):
    with open("Sucursales.txt", "r") as file:
        lines = file.readlines()
        file.seek(0)
    with open("Sucursales.txt", "w") as file:
        encontrar = False
        contar = 0
        for line in lines:
            if f"Codigo: {codigo}" in line:
                contar = 6
                encontrar = True

            if contar > 0:
                contar -= 1
            if contar == 0:
                file.write(line)
        
        if encontrar:
            print("Se eliminó la sucursal")
        else:
            print("No se encontró la sucursal")                                     

class Empleado(Sucursal):
    def __init__(self, codigo, nombre, direccion, telefono, id_empleado, cargo):
        super().__init__(codigo, nombre, direccion, telefono)
        self.__id_empleado = id_empleado
        self.__cargo = cargo
        
    def Get_ID_Empleado(self):
        return self.__id_empleado
    
    def Get_Cargo_Empleado(self):
        return self.__cargo
    
    def Set_Empleado(self):
        super().Crear_Escoger()
        self.__id_empleado = input("Ingrese la ID del empleado: ")
        self.__cargo = input("Ingrese el cargo del empleado: ")
        
        with open("Empleado.txt", "a") as file:
            file.write("-------------------\n")
            file.write(f"Codigo: {self.Get_Codigo_Sucursal()}\n")
            file.write(f"Nombre: {self.Get_Nombre_Sucursal()}\n")
            file.write(f"Direccion: {self.Get_Direccion_Sucursal()}\n")
            file.write(f"Telefono: {self.Get_Telefono_Sucursal()}\n")
            file.write(f"ID: {self.Get_ID_Empleado()}\n")
            file.write(f"Cargo: {self.Get_Cargo_Empleado()}\n")
            file.write("-------------------")  

class Cliente(Sucursal):
    def __init__(self, codigo, nombre, direccion, telefono, id_cliente):
        super().__init__(codigo, nombre, direccion, telefono)
        self.__id_cliente = id_cliente
        
    def Get_ID_Cliente(self):
        return self.__id_cliente

    def Set_Cliente(self):
        super().Crear_Escoger()
        self.__id_cliente = input("Ingrese la ID del cliente: ")
        
        with open("Cliente.txt", "a") as file:
            file.write("-------------------\n")
            file.write(f"Codigo: {self.Get_Codigo_Sucursal()}\n")
            file.write(f"Nombre: {self.Get_Nombre_Sucursal()}\n")
            file.write(f"Direccion: {self.Get_Direccion_Sucursal()}\n")
            file.write(f"Telefono: {self.Get_Telefono_Sucursal()}\n")
            file.write(f"ID: {self.Get_ID_Cliente()}\n")
            file.write("-------------------") 

class Cuenta(Sucursal):
    def __init__(self, codigo, nombre, direccion, telefono, numero_cuenta, saldo):
        super().__init__(codigo, nombre, direccion, telefono)
        self.__numero_cuenta = numero_cuenta
        self.__saldo = saldo
        
    def Get_NumeroCuenta_Cuenta(self):
        return self.__numero_cuenta
    
    def Get_Saldo_Cuenta(self):
        return self.__saldo   
    
    def Set_Cuenta(self):
        super().Crear_Escoger() 
        
        isCuenta = True
        
        if self.Get_NumeroCuenta_Cuenta() != "":
            isCuenta = False 
            
        self.__numero_cuenta = input("Ingrese el nunero de cuenta: ")
        self.__saldo = input("Ingrese el saldo de la cuenta: ")
        
        if isCuenta:
            with open("Cuenta.txt", "a") as file:
                file.write("-------------------\n")
                file.write(f"Codigo: {self.Get_Codigo_Sucursal()}\n")
                file.write(f"Nombre: {self.Get_Nombre_Sucursal()}\n")
                file.write(f"Direccion: {self.Get_Direccion_Sucursal()}\n")
                file.write(f"Telefono: {self.Get_Telefono_Sucursal()}\n")
                file.write(f"Numero de Cuenta: {self.Get_NumeroCuenta_Cuenta()}\n")
                file.write(f"Saldo: {self.Get_Saldo_Cuenta()}\n")
                file.write("-------------------") 

class Tarjeta(Cuenta):
    def __init__(self, codigo, nombre, direccion, telefono, numero_cuenta, saldo, numero_tarjeta):
        super().__init__(codigo, nombre, direccion, telefono, numero_cuenta, saldo)
        self.__numero_tarjeta = numero_tarjeta
        
    def Get_NumeroTarjeta_Tarjeta(self):
        return self.__numero_tarjeta
    
    def Set_Tarjeta(self):
        super().Set_Cuenta()
        self.__numero_tarjeta = input("Ingrese el numero de la tarjeta: ")
        
        with open("Tarjeta.txt", "a") as file:
            file.write("-------------------\n")
            file.write(f"Codigo: {self.Get_Codigo_Sucursal()}\n")
            file.write(f"Nombre: {self.Get_Nombre_Sucursal()}\n")
            file.write(f"Direccion: {self.Get_Direccion_Sucursal()}\n")
            file.write(f"Telefono: {self.Get_Telefono_Sucursal()}\n")
            file.write(f"Numero de Cuenta: {self.Get_NumeroCuenta_Cuenta()}\n")
            file.write(f"Saldo: {self.Get_Saldo_Cuenta()}\n")
            file.write(f"Numero de Tarjeta: {self.Get_NumeroTarjeta_Tarjeta()}\n")
            file.write("-------------------") 
     
     
     
     
        

        
        




