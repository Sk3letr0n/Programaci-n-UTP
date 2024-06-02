'''
3. Se plantea desarrollar un programa que permita la gestión comercial del
Banco P&O,
cuya superclase Sucursal debe llevar los atributos código, nombre,
dirección, teléfono y los métodos crear () y eliminar (); así como las
subclases Empleados, Cliente, Cuenta y Tarjeta con sus correspondientes
encapsulamientos, atributos y métodos.
Crear el código de las clases implementando una relación de herencia
desde la superclase Sucursal hasta las subclases Empleados, Cliente y
Cuenta y una relación de herencia desde Cuenta hacía Tarjeta.
Por último, cree un objeto de cada clase y pruebe los métodos.
'''
# Hecho por: Steven Grisales López y Luis Felipe Garzón Bonilla.
from Sucursal import Sucursal
from Cliente import Cliente
from Empleado import Empleado
from Cuenta import Cuenta, Tarjeta

# Crear objetos de cada clase
sucursal1 = Sucursal("S001", "Sucursal Principal", "123 Calle Principal", "123-456-7890")
empleado1 = Empleado("E001", "Juan Perez", "456 Calle Secundaria", "987-654-3210", "12345", 5000)
cliente1 = Cliente("C001", "Maria Lopez", "789 Avenida Terciaria", "567-890-1234", "67890")
cuenta1 = Cuenta("CU001", "Cuenta de Ahorros", "101 Calle Ahorrativa", "222-333-4444", "98765", 1000)
tarjeta1 = Tarjeta("CU001", "Cuenta de Ahorros", "101 Calle Ahorrativa", "222-333-4444", "98765", 1000, "1234-5678-9012-3456", "Débito")

# Probar los métodos
print("Información de la sucursal:")
print(f"Código: {sucursal1.get_codigo()}")  # Utiliza el getter get_codigo()
print(f"Nombre: {sucursal1.get_nombre()}")
print(f"Dirección: {sucursal1.get_direccion()}")
print(f"Teléfono: {sucursal1.get_telefono()}")
sucursal1.crear()

print("\nInformación del empleado:")
print(f"Código: {empleado1.get_codigo()}")  # Utiliza el getter get_codigo()
print(f"Nombre: {empleado1.get_nombre()}")
print(f"Dirección: {empleado1.get_direccion()}")
print(f"Teléfono: {empleado1.get_telefono()}")
print(f"ID de Empleado: {empleado1.get_empleado_id()}")
print(f"Salario Mensual: ${empleado1.get_salario()}")
print(f"Salario Anual: ${empleado1.calcular_salario_anual()}")

print("\nInformación del cliente:")
print(f"Código: {cliente1.get_codigo()}")
print(f"Nombre: {cliente1.get_nombre()}")
print(f"Dirección: {cliente1.get_direccion()}")
print(f"Teléfono: {cliente1.get_telefono()}")
print(f"ID de Cliente: {cliente1.get_cliente_id()}")
cliente1.solicitar_tarjeta()

print("\nInformación de la cuenta:")
print(f"Código: {cuenta1.get_codigo()}")
print(f"Nombre: {cuenta1.get_nombre()}")
print(f"Dirección: {cuenta1.get_direccion()}")
print(f"Teléfono: {cuenta1.get_telefono()}")
print(f"Número de Cuenta: {cuenta1.get_cuenta_id()}")
print(f"Saldo Inicial: ${cuenta1.consultar_saldo()}")
cuenta1.depositar(500)
print(f"Saldo después del depósito: ${cuenta1.consultar_saldo()}")
cuenta1.retirar(200)
print(f"Saldo después del retiro: ${cuenta1.consultar_saldo()}")

print("\nInformación de la tarjeta:")
print(f"Código: {tarjeta1.get_codigo()}")
print(f"Nombre: {tarjeta1.get_nombre()}")
print(f"Dirección: {tarjeta1.get_direccion()}")
print(f"Teléfono: {tarjeta1.get_telefono()}")
print(f"Número de Cuenta Asociada: {tarjeta1.get_cuenta_id()}")
print(f"Saldo en la Tarjeta: ${tarjeta1.consultar_saldo()}")
print(f"Número de Tarjeta: {tarjeta1.get_numero_tarjeta()}")
print(f"Tipo de Tarjeta: {tarjeta1.get_tipo()}")


with open("Punto 3\informacion.txt", "a") as archivo:
    archivo.write("\nInformacion de la sucursal:\n")
    archivo.write(f"Codigo: {sucursal1.get_codigo()}\n")
    archivo.write(f"Nombre: {sucursal1.get_nombre()}\n")
    archivo.write(f"Direccion: {sucursal1.get_direccion()}\n")
    archivo.write(f"Telefono: {sucursal1.get_telefono()}\n")
    archivo.write("\n")

    archivo.write("Informacion del empleado:\n")
    archivo.write(f"Codigo: {empleado1.get_codigo()}\n")
    archivo.write(f"Nombre: {empleado1.get_nombre()}\n")
    archivo.write(f"Direccion: {empleado1.get_direccion()}\n")
    archivo.write(f"Telefono: {empleado1.get_telefono()}\n")
    archivo.write(f"ID de Empleado: {empleado1.get_empleado_id()}\n")
    archivo.write(f"Salario Mensual: ${empleado1.get_salario()}\n")
    archivo.write(f"Salario Anual: ${empleado1.calcular_salario_anual()}\n")
    archivo.write("\n")

    archivo.write("Informacion del cliente:\n")
    archivo.write(f"Codigo: {cliente1.get_codigo()}\n")
    archivo.write(f"Nombre: {cliente1.get_nombre()}\n")
    archivo.write(f"Direccion: {cliente1.get_direccion()}\n")
    archivo.write(f"Telefono: {cliente1.get_telefono()}\n")
    archivo.write(f"ID de Cliente: {cliente1.get_cliente_id()}\n")
    archivo.write("\n")

    archivo.write("Informacion de la cuenta:\n")
    archivo.write(f"Codigo: {cuenta1.get_codigo()}\n")
    archivo.write(f"Nombre: {cuenta1.get_nombre()}\n")
    archivo.write(f"Direccion: {cuenta1.get_direccion()}\n")
    archivo.write(f"Telefono: {cuenta1.get_telefono()}\n")
    archivo.write(f"Numero de Cuenta: {cuenta1.get_cuenta_id()}\n")
    archivo.write(f"Saldo Inicial: ${cuenta1.consultar_saldo()}\n")
    archivo.write("\n")

    archivo.write("Informacion de la tarjeta:\n")
    archivo.write(f"Codigo: {tarjeta1.get_codigo()}\n")
    archivo.write(f"Nombre: {tarjeta1.get_nombre()}\n")
    archivo.write(f"Direccion: {tarjeta1.get_direccion()}\n")
    archivo.write(f"Telefono: {tarjeta1.get_telefono()}\n")
    archivo.write(f"Numero de Cuenta Asociada: {tarjeta1.get_cuenta_id()}\n")
    archivo.write(f"Saldo en la Tarjeta: ${tarjeta1.consultar_saldo()}\n")
    archivo.write(f"Numero de Tarjeta: {tarjeta1.get_numero_tarjeta()}\n")
    archivo.write(f"Tipo de Tarjeta: {tarjeta1.get_tipo()}\n")
    
    
    archivo.close()
    
    opcion = input("Desea eliminar la sucursal? (S/N): ")
    if opcion == "S":
        Sucursal.eliminar_sucursal("S001")
        print("La sucursal se ha eliminado")
    else:
        print("La sucursal no se ha eliminado")