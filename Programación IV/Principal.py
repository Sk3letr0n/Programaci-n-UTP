from Clases_Ejercicio_3 import * 

def Menu_Principal():
    print("\n\n---------------------")
    print("1. Crear Sucursal")
    print("2. Eliminar Sucursal")
    print("3. Crear Empleados")
    print("4. Crear Clientes")
    print("5. Crear Cuentas")
    print("6. Crear Tarjetas")
    print("7. Salir")
    print("---------------------\n\n")

while True:
    Menu_Principal()
    opcion = input("Ingrese su opción: ")

    if opcion == "1":
        sucursal = Sucursal("", "", "", "")
        sucursal.Set_Sucursal()
    elif opcion == "2":
        Eliminar = input("Ingrese el codigo de la sucursal que desea eliminar: ")
        Eliminar_Sucursal(Eliminar) 
    elif opcion == "3":
        empleado = Empleado("", "", "", "", "", "")
        empleado.Set_Empleado()

    elif opcion == "4":
        cliente = Cliente("", "", "", "", "")
        cliente.Set_Cliente()

    elif opcion == "5":
        cuenta = Cuenta("", "", "", "", "", "")
        cuenta.Set_Cuenta()

    elif opcion == "6":
        tarjeta = Tarjeta("", "", "", "", "x", "", "")
        tarjeta.Set_Tarjeta()

    elif opcion == "7":
        print("El programa cerró")
        break
    else:
        print("Opción no válida")