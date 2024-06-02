import os
import time
import struct
import tkinter as tk
from tkinter import messagebox, simpledialog

class Cliente:
    def __init__(self, nombreApellido, telefono, documento):
        self.nombreApellido = nombreApellido
        self.telefono = telefono
        self.documento = documento

class Venta:
    def __init__(self, marca, precio, fechaVenta, nombreCliente):
        self.marca = marca
        self.precio = precio
        self.fechaVenta = fechaVenta
        self.nombreCliente = nombreCliente

def SOATExpirado(fechaVenta):
    ahora = time.time()
    diferencia = ahora - fechaVenta
    unAnio = 365 * 24 * 60 * 60
    return diferencia > unAnio

def crear_archivo_clientes():
    if not os.path.exists("clientes.txt"):
        with open("clientes.txt", "wb") as archivo:
            nombreApellido = "Juan Perez".ljust(40, '\x00')
            telefono = "123456789".ljust(15, '\x00')
            documento = 12345678
            archivo.write(struct.pack('40s 15s i', nombreApellido.encode('utf-8'), telefono.encode('utf-8'), documento))

def crear_archivo_marcas():
    if not os.path.exists("Marcas.txt"):
        marcas = [
            "Toyota 500000",
            "Nissan 450000",
            "Chevrolet 480000",
            "Ford 470000"
        ]
        with open("Marcas.txt", "w") as archivo:
            for marca in marcas:
                archivo.write(marca + "\n")

def crear_archivo_ventas():
    if not os.path.exists("Ventas.txt"):
        ventas = [
            f"Marca: Toyota Precio: 500000 Fecha: {int(time.time())} Cliente: Juan Perez"
        ]
        with open("Ventas.txt", "w") as archivo:
            for venta in ventas:
                archivo.write(venta + "\n")

def ingresarCliente():
    nombreApellido = simpledialog.askstring("Ingreso de Cliente", "Ingrese Nombre y Apellido:")
    telefono = simpledialog.askstring("Ingreso de Cliente", "Ingrese Numero de telefono:")
    documento = simpledialog.askinteger("Ingreso de Cliente", "Ingrese Documento:")
    
    if nombreApellido and telefono and documento:
        try:
            with open("clientes.txt", "ab") as archivo:
                cliente = Cliente(nombreApellido, telefono, documento)
                archivo.write(struct.pack('40s 15s i', cliente.nombreApellido.encode('utf-8'), cliente.telefono.encode('utf-8'), cliente.documento))
            messagebox.showinfo("Ingreso de Cliente", "Cliente ingresado exitosamente.")
        except Exception as e:
            messagebox.showerror("Error", f"Error al abrir el archivo: {e}")

def mostrarClientes():
    try:
        with open("clientes.txt", "rb") as archivo:
            clientes_info = ""
            while True:
                datos = archivo.read(struct.calcsize('40s 15s i'))
                if not datos:
                    break
                nombreApellido, telefono, documento = struct.unpack('40s 15s i', datos)
                nombreApellido = nombreApellido.decode('utf-8').strip('\x00')
                telefono = telefono.decode('utf-8').strip('\x00')
                clientes_info += f"Nombre y Apellido: {nombreApellido}\nNumero de telefono: {telefono}\nDocumento: {documento}\n\n"
            if clientes_info:
                messagebox.showinfo("Clientes Registrados", clientes_info)
            else:
                messagebox.showinfo("Clientes Registrados", "No hay clientes registrados.")
    except Exception as e:
        messagebox.showerror("Error", f"Error al abrir el archivo: {e}")

def verificarSOAT():
    nombreCliente = simpledialog.askstring("Verificación de SOAT", "Ingrese Nombre y Apellido del cliente:")
    if nombreCliente:
        encontrado = False
        try:
            with open("Ventas.txt", "r") as ventasFile:
                for linea in ventasFile:
                    datos = linea.split()
                    marca = datos[1]
                    precio = int(datos[3])
                    fechaVenta = int(datos[5])
                    nombre = ' '.join(datos[7:])
                    if nombre == nombreCliente:
                        encontrado = True
                        if SOATExpirado(fechaVenta):
                            messagebox.showinfo("Verificación de SOAT", f"El SOAT del cliente {nombreCliente} ha expirado.")
                        else:
                            messagebox.showinfo("Verificación de SOAT", f"El SOAT del cliente {nombreCliente} no ha expirado.")
                        break
                if not encontrado:
                    messagebox.showinfo("Verificación de SOAT", f"No se encontró un SOAT para el cliente {nombreCliente}.")
        except Exception as e:
            messagebox.showerror("Error", f"No se puede abrir el archivo de ventas: {e}")

def venderSOAT():
    try:
        with open("Marcas.txt", "r") as marcasFile:
            marcas = []
            precios = []
            for line in marcasFile:
                datos = line.split()
                marcas.append(datos[0])
                precios.append(int(datos[1]))

            marca_seleccionada = simpledialog.askinteger("Venta de SOAT", f"Seleccione una marca:\n" + '\n'.join([f"{idx+1}. {marcas[idx]} - Precio: {precios[idx]}" for idx in range(len(marcas))]))

            if marca_seleccionada is None:
                messagebox.showinfo("Venta de SOAT", "Operación cancelada por el usuario.")
                return
            
            if not (1 <= marca_seleccionada <= len(marcas)):
                messagebox.showerror("Error", "Selección inválida. Por favor, seleccione un número válido.")
                return
            
            seleccionMarca = marcas[marca_seleccionada - 1]
            seleccionPrecio = precios[marca_seleccionada - 1]

            confirmacion = messagebox.askyesno("Confirmación", f"Ha seleccionado la marca: {seleccionMarca}\nPrecio del SOAT: {seleccionPrecio}\nDesea comprar este SOAT?")
            
            if confirmacion:
                ahora = time.time()
                nombreCliente = simpledialog.askstring("Venta de SOAT", "Ingrese Nombre y Apellido del cliente:")

                if not nombreCliente:
                    messagebox.showinfo("Venta de SOAT", "Operación cancelada por el usuario.")
                    return

                clienteEncontrado = False
                with open("clientes.txt", "rb") as clientesFile:
                    while True:
                        datos = clientesFile.read(struct.calcsize('40s 15s i'))
                        if not datos:
                            break
                        nombreApellido, _, _ = struct.unpack('40s 15s i', datos)
                        if nombreApellido.decode('utf-8').strip('\x00') == nombreCliente:
                            clienteEncontrado = True
                            break

                if clienteEncontrado:
                    soatVencido = True
                    with open("Ventas.txt", "r") as ventasFile:
                        for linea in ventasFile:
                            datos = linea.split()
                            marca = datos[1]
                            precio = int(datos[3])
                            fechaVenta = int(datos[5])
                            nombre = ' '.join(datos[7:])
                            if nombre == nombreCliente:
                                if not SOATExpirado(fechaVenta):
                                    soatVencido = False
                                    break

                    if soatVencido:
                        with open("Ventas.txt", "a") as ventasFile:
                            ventasFile.write(f"Marca: {seleccionMarca} Precio: {seleccionPrecio} Fecha: {int(ahora)} Cliente: {nombreCliente}\n")
                        messagebox.showinfo("Venta de SOAT", "El nuevo SOAT ha sido registrado exitosamente.")
                    else:
                        messagebox.showinfo("Venta de SOAT", "El cliente ya tiene un SOAT vigente.")
                else:
                    messagebox.showinfo("Venta de SOAT", "El cliente no existe.")
            else:
                messagebox.showinfo("Venta de SOAT", "Compra cancelada.")
    except Exception as e:
        messagebox.showerror("Error", f"No se puede abrir el archivo de marcas: {e}")

def cantidadSOATsVendidos():
    soatsVendidos = 0
    try:
        with open("Ventas.txt", "r") as ventasFile:
            for linea in ventasFile:
                soatsVendidos += 1
        messagebox.showinfo("Cantidad de SOATs vendidos", f"Cantidad de SOATs vendidos: {soatsVendidos}")
    except Exception as e:
        messagebox.showerror("Error", f"No se puede abrir el archivo de ventas: {e}")

def mostrarSOATsVendidos():
    try:
        with open("Ventas.txt", "r") as ventasFile:
            soats_info = ""
            for linea in ventasFile:
                datos = linea.split()
                marca = datos[1]
                precio = int(datos[3])
                fechaVenta = time.ctime(int(datos[5]))
                nombreCliente = ' '.join(datos[7:])
                soats_info += f"Marca: {marca}\nPrecio: {precio}\nFecha: {fechaVenta}\nCliente: {nombreCliente}\n\n"
            if soats_info:
                messagebox.showinfo("SOATs Vendidos", soats_info)
            else:
                messagebox.showinfo("SOATs Vendidos", "No hay SOATs vendidos.")
    except Exception as e:
        messagebox.showerror("Error", f"No se puede abrir el archivo de ventas: {e}")

def main():
    crear_archivo_clientes()
    crear_archivo_marcas()
    crear_archivo_ventas()

    root = tk.Tk()
    root.title("Sistema de Gestión de SOATs")

    frame = tk.Frame(root)
    frame.pack(padx=10, pady=10)

    btn_ingresar_cliente = tk.Button(frame, text="Ingresar Cliente", command=ingresarCliente)
    btn_ingresar_cliente.pack(pady=5)

    btn_mostrar_clientes = tk.Button(frame, text="Mostrar Clientes", command=mostrarClientes)
    btn_mostrar_clientes.pack(pady=5)

    btn_vender_soat = tk.Button(frame, text="Vender SOAT", command=venderSOAT)
    btn_vender_soat.pack(pady=5)

    btn_verificar_soat = tk.Button(frame, text="Verificar SOAT Vencido", command=verificarSOAT)
    btn_verificar_soat.pack(pady=5)

    btn_cantidad_soats_vendidos = tk.Button(frame, text="Cantidad de SOATs Vendidos", command=cantidadSOATsVendidos)
    btn_cantidad_soats_vendidos.pack(pady=5)

    btn_mostrar_soats_vendidos = tk.Button(frame, text="Mostrar SOATs Vendidos", command=mostrarSOATsVendidos)
    btn_mostrar_soats_vendidos.pack(pady=5)

    root.mainloop()

if __name__ == "__main__":
    main()