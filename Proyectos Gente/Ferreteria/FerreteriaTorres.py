import pandas as pd
import tkinter as tk
from tkinter import messagebox
from datetime import datetime
from PIL import ImageTk, Image
import os

# Path de la carpeta de facturas para usarla más adelante (contiene todas las facturas).
facturas_dir = 'facturas'
if not os.path.exists(facturas_dir):
    os.makedirs(facturas_dir)

# leer la hoja de excel que contiene los datos de los productos
archivo_excel = 'productosJT.xlsx'
df = pd.read_excel(archivo_excel, sheet_name='Hoja1')

# crear listas para cada una de las columnas
codigos = df['Codigo'].values.tolist()
productos = df['Producto'].values.tolist()
precio = df['Precio'].values.tolist()
disponibles = df['Disponibles'].values.tolist()

# Saldo inicial para pago con tarjeta
saldo_tarjeta = 1000000

def guardar_datos_excel(df, archivo):
    try:
        df.to_excel(archivo, index=False, sheet_name='Hoja1')
    except PermissionError:
        messagebox.showerror(message="Permiso denegado: No se puede guardar el archivo. Verifique si está abierto en otro programa.", title="Error")
    except Exception as e:
        messagebox.showerror(message=f"Error al guardar el archivo: {e}", title="Error")

def cuenta():
    T = q1.get()
    if T == '':
        messagebox.showinfo(message="Hola de nuevo", title="Titulo")

def confirmar_salida():
    if messagebox.askyesno("Salir", "¿Desea salir?"):
        DF.destroy()

def bienvenida():
    t = q1.get()
    e = q3.get()
    
    if t == 'admin' and e == '12345':
        q2.set('Bienvenido')
        
        messagebox.showinfo(message="Inicio de sesión exitosamente", title="Éxito")
        
        DF.withdraw()
        
        abrir_ventana_menu()
        
    else:
        q2.set('Ingreso Fallido')
        q1.set('')
        q3.set('')
            
        a = int(c.get())
        c.set(str(a + 1))
        print(a)
        if a == 3:
            DF.destroy()

from PIL import ImageTk, Image

def abrir_ventana_menu():
    global ventana_secundaria
    ventana_secundaria = tk.Toplevel()
    
    ventana_secundaria.title('Menú')
    ventana_secundaria.iconphoto(True, tk.PhotoImage(file="construyefacil16.png"))
    
    ventana_secundaria.config(width=600, height=400) 

    # Cargar la imagen y colocarla en el menú
    img = Image.open("construyefacil.png")
    img = img.resize((200, 100))
    img = ImageTk.PhotoImage(img)
    
    img_label = tk.Label(ventana_secundaria, image=img)
    img_label.image = img  # Necesario para evitar que la imagen sea eliminada por el recolector de basura
    img_label.place(relx=0.5, rely=0.2, anchor=tk.CENTER)
    
    boton_buscar = tk.Button(ventana_secundaria, 
                             text='Buscar',
                             command=abrir_ventana_buscar,
                             width=20)
    boton_buscar.place(relx=0.5, rely=0.4, anchor=tk.CENTER)
    
    boton_comprar = tk.Button(ventana_secundaria, 
                              text='Comprar',
                              command=abrir_ventana_comprar,
                              width=20)
    boton_comprar.place(relx=0.5, rely=0.5, anchor=tk.CENTER)
    
    boton_registrar_actualizar = tk.Button(ventana_secundaria, 
                                           text='Registrar/Actualizar',
                                           command=abrir_ventana_registrar_actualizar,
                                           width=20)
    boton_registrar_actualizar.place(relx=0.5, rely=0.6, anchor=tk.CENTER)
    
    boton_cerrar = tk.Button(ventana_secundaria, 
                             text='Salir',
                             command=confirmar_salida,
                             width=20)
    boton_cerrar.place(relx=0.5, rely=0.7, anchor=tk.CENTER)
    
    ventana_secundaria.resizable(0, 0)
    ventana_secundaria.configure(background='light blue')
        
def volver_al_menu(ventana_actual):
    ventana_actual.destroy()
    ventana_secundaria.deiconify()

def abrir_ventana_buscar():
    ventana_secundaria.withdraw()
    
    ventana_buscar = tk.Toplevel()
    ventana_buscar.title('Buscar Producto')
    ventana_buscar.geometry('400x300')
    ventana_buscar.iconphoto(True, tk.PhotoImage(file="construyefacil16.png"))
    ventana_buscar.configure(background='light blue')
    
    tk.Label(ventana_buscar, text='Código del producto').pack(pady=10)
    codigo_entry = tk.Entry(ventana_buscar)
    codigo_entry.pack(pady=10)
    
    def buscar_producto():
        codigo = int(codigo_entry.get())
        if codigo in codigos:
            index = codigos.index(codigo)
            messagebox.showinfo(
                message=f"Producto: {productos[index]}\nPrecio: {precio[index]}\nDisponibles: {disponibles[index]}",
                title="Buscar Producto"
            )
        else:
            messagebox.showerror(message="Producto no encontrado", title="Error")
    
    tk.Button(ventana_buscar, text='Buscar', command=buscar_producto).pack(pady=10)
    tk.Button(ventana_buscar, text='Volver', command=lambda: volver_al_menu(ventana_buscar)).pack(pady=10)

def abrir_ventana_comprar():
    ventana_secundaria.withdraw()
    
    ventana_comprar = tk.Toplevel()
    ventana_comprar.title('Comprar Producto')
    ventana_comprar.geometry('400x350')
    ventana_comprar.iconphoto(True, tk.PhotoImage(file="construyefacil16.png"))
    ventana_comprar.configure(background='light blue')
    
    tk.Label(ventana_comprar, text='Código del producto').pack(pady=10)
    codigo_entry = tk.Entry(ventana_comprar)
    codigo_entry.pack(pady=10)
    
    tk.Label(ventana_comprar, text='Cantidad').pack(pady=10)
    cantidad_entry = tk.Entry(ventana_comprar)
    cantidad_entry.pack(pady=10)
    
    def comprar_producto():
        try:
            codigo = int(codigo_entry.get())
            cantidad = int(cantidad_entry.get())
            
            if codigo in codigos:
                index = codigos.index(codigo)
                if disponibles[index] >= cantidad:
                    total = precio[index] * cantidad
                    disponibles[index] -= cantidad
                    
                    def pedir_metodo_pago():
                        messagebox.showinfo(message=f"El total a pagar es {total} pesos", title="Total a Pagar")
                        
                        ventana_comprar.withdraw()
                        
                        ventana_metodo_pago = tk.Toplevel()
                        ventana_metodo_pago.title('Método de Pago')
                        ventana_metodo_pago.geometry('400x300')
                        
                        tk.Label(ventana_metodo_pago, text='Seleccione el método de pago').pack(pady=10)
                        
                        def seleccionar_metodo_pago(metodo):
                            ventana_metodo_pago.withdraw()
                            
                            if metodo == 'Efectivo':
                                ventana_pago_efectivo = tk.Toplevel()
                                ventana_pago_efectivo.title('Pago en Efectivo')
                                ventana_pago_efectivo.geometry('400x300')
                                
                                tk.Label(ventana_pago_efectivo, text='Ingrese la cantidad pagada').pack(pady=10)
                                pago_entry = tk.Entry(ventana_pago_efectivo)
                                pago_entry.pack(pady=10)
                                
                                def procesar_pago_efectivo():
                                    pago = float(pago_entry.get())
                                    if pago < total:
                                        messagebox.showerror(message="Dinero insuficiente, por favor pagar lo necesario", title="Error")
                                    else:
                                        cambio = pago - total
                                        messagebox.showinfo(message=f"Cambio: {cambio:.2f} pesos", title="Pago en Efectivo")
                                        finalizar_compra(codigo, productos[index], total, metodo, pago, cambio)
                                        ventana_pago_efectivo.destroy()
                                
                                tk.Button(ventana_pago_efectivo, text='Pagar', command=procesar_pago_efectivo).pack(pady=10)
                            
                            elif metodo == 'Tarjeta':
                                messagebox.showinfo(message="Su pago fue realizado con tarjeta.", title="Pago con Tarjeta")
                                finalizar_compra(codigo, productos[index], total, metodo, total, 0)
                        
                        tk.Button(ventana_metodo_pago, text='Efectivo', command=lambda: seleccionar_metodo_pago('Efectivo')).pack(pady=10)
                        tk.Button(ventana_metodo_pago, text='Tarjeta', command=lambda: seleccionar_metodo_pago('Tarjeta')).pack(pady=10)
                    
                    pedir_metodo_pago()
                else:
                    messagebox.showerror(message="No hay suficientes productos disponibles", title="Error")
            else:
                messagebox.showerror(message="Producto no encontrado", title="Error")
        except ValueError:
            messagebox.showerror(message="Por favor ingrese valores válidos", title="Error")
    
    tk.Button(ventana_comprar, text='Comprar', command=comprar_producto).pack(pady=10)
    tk.Button(ventana_comprar, text='Volver', command=lambda: volver_al_menu(ventana_comprar)).pack(pady=10)

def finalizar_compra(codigo, producto, total, metodo, pago, cambio):
    facturas_dir = 'facturas'
    if not os.path.exists(facturas_dir):
        os.makedirs(facturas_dir)
    
    num_facturas = len(os.listdir(facturas_dir))
    factura_filename = f'factura-{num_facturas + 1}.txt'
    
    with open(os.path.join(facturas_dir, factura_filename), 'w') as archivo_txt:
        linel = """
        
        SUPERMERCADO CONSTRUYE FACIL
             NIT. 69696969
        REGIMEN SIMPLE TRIBUTACION
            RESPONSABLE DE IVA
             CIUDAD NIGHTCITY
         CRA 8A- DEBAJO DEL PUENTE
          TELEFONO: 312 6969696
          
        ---------------------------"""
        
        archivo_txt.write(linel)
        archivo_txt.write('\n codigo  producto  precio c/u')
        archivo_txt.write('\n {:<10}{:<10} {:<10}'.format(str(codigo), producto, str(total)))
        
        archivo_txt.write('\n' + '' .center(34, '-'))
        archivo_txt.write('\n total a pagar: ' +'{:>8}'  .format(str(total)))
        iva  = total * 0.20
        subtotal = total - iva  
        
        archivo_txt.write('\n subtotal: '+'{:>16}'  .format(str(subtotal)))    
        archivo_txt.write('\n IVA: '+'{:>17}'  .format(str(round(iva))))
        
        archivo_txt.write('\n' + '' .center(34, '-')+'\n')
        archivo_txt.write('Metodo de pago: '+ metodo + '\n')
        archivo_txt.write('Total pagado: {}\n'.format(pago))
        archivo_txt.write('Cambio: ' + str(cambio) + ' pesos\n')
        archivo_txt.write('' .center(34, '-')+'\n')
        
        fecha_actual = datetime.now()
        archivo_txt.write('Fecha y hora:{:02d}/{:02d}/{:04d} {:02d}:{:02d}:{:02d}\n'
                          .format(fecha_actual.day,
                            fecha_actual.month, 
                            fecha_actual.year, 
                            fecha_actual.hour,
                            fecha_actual.minute, 
                            fecha_actual.second))
        
        archivo_txt.write('-' * 30 + '\n')
        archivo_txt.write('\n' + 'Muchas gracias por su compra, feliz día' .center(32,'-' ))
    
    # Guardar los datos actualizados en el archivo Excel
    df_actualizado = pd.DataFrame({
        'Codigo': codigos,
        'Producto': productos,
        'Precio': precio,
        'Disponibles': disponibles
    })
    guardar_datos_excel(df_actualizado, archivo_excel)
    
    messagebox.showinfo(message="Compra realizada correctamente", title="Compra Producto")
    ventana_secundaria.deiconify()

def abrir_ventana_registrar_actualizar():
    ventana_secundaria.withdraw()
    
    ventana_registrar_actualizar = tk.Toplevel()
    ventana_registrar_actualizar.title('Registrar/Actualizar Producto')
    ventana_registrar_actualizar.geometry('400x300')
    ventana_registrar_actualizar.iconphoto(True, tk.PhotoImage(file="construyefacil16.png"))
    ventana_registrar_actualizar.configure(background='light blue')
    
    tk.Button(ventana_registrar_actualizar, text='Registrar', command=registrar_producto).pack(pady=10)
    tk.Button(ventana_registrar_actualizar, text='Actualizar', command=actualizar_producto).pack(pady=10)
    tk.Button(ventana_registrar_actualizar, text='Volver', command=lambda: volver_al_menu(ventana_registrar_actualizar)).pack(pady=10)

def registrar_producto():
    ventana_registrar = tk.Toplevel()
    ventana_registrar.title('Registrar Producto')
    ventana_registrar.geometry('300x250')
    ventana_registrar.configure(background='light blue')
    
    tk.Label(ventana_registrar, text='Producto').pack(pady=5)
    producto_entry = tk.Entry(ventana_registrar)
    producto_entry.pack(pady=5)
    
    tk.Label(ventana_registrar, text='Precio').pack(pady=5)
    precio_entry = tk.Entry(ventana_registrar)
    precio_entry.pack(pady=5)
    
    tk.Label(ventana_registrar, text='Disponibles').pack(pady=5)
    disponibles_entry = tk.Entry(ventana_registrar)
    disponibles_entry.pack(pady=5)
    
    def guardar_producto():
        nuevo_producto = producto_entry.get()
        nuevo_precio = float(precio_entry.get())
        nueva_disponibilidad = int(disponibles_entry.get())
        nuevo_codigo = max(codigos) + 1
        
        codigos.append(nuevo_codigo)
        productos.append(nuevo_producto)
        precio.append(nuevo_precio)
        disponibles.append(nueva_disponibilidad)
        
        # Guardar los datos en el archivo Excel
        df_nuevo = pd.DataFrame({
            'Codigo': codigos,
            'Producto': productos,
            'Precio': precio,
            'Disponibles': disponibles
        })
        
        guardar_datos_excel(df_nuevo, archivo_excel)
        messagebox.showinfo(message="Datos guardados exitosamente", title="Éxito")
        ventana_registrar.destroy()
    
    tk.Button(ventana_registrar, text='Guardar', command=guardar_producto).pack(pady=20)

def actualizar_producto():
    ventana_actualizar = tk.Toplevel()
    ventana_actualizar.title('Actualizar Producto')
    ventana_actualizar.geometry('300x200')
    ventana_actualizar.configure(background='light blue')
    
    tk.Label(ventana_actualizar, text='Código del producto').pack(pady=5)
    codigo_entry = tk.Entry(ventana_actualizar)
    codigo_entry.pack(pady=5)
    
    tk.Label(ventana_actualizar, text='Nueva cantidad disponible').pack(pady=5)
    cantidad_entry = tk.Entry(ventana_actualizar)
    cantidad_entry.pack(pady=5)
    
    def guardar_actualizacion():
        codigo = int(codigo_entry.get())
        nueva_cantidad = int(cantidad_entry.get())
        
        if codigo in codigos:
            index = codigos.index(codigo)
            disponibles[index] = nueva_cantidad
            
            # Guardar los datos en el archivo Excel
            df_nuevo = pd.DataFrame({
                'Codigo': codigos,
                'Producto': productos,
                'Precio': precio,
                'Disponibles': disponibles
            })
            
            guardar_datos_excel(df_nuevo, archivo_excel)
            messagebox.showinfo(message="Datos guardados exitosamente", title="Éxito")
            ventana_actualizar.destroy()
        else:
            messagebox.showerror(message="Código de producto no encontrado", title="Error")
    
    tk.Button(ventana_actualizar, text='Guardar', command=guardar_actualizacion).pack(pady=20)

# En la ventana principal
DF = tk.Tk()
DF.title('Login')
DF.iconphoto(True, tk.PhotoImage(file="construyefacil16.png"))
DF.config(width=600, height=400)
DF.configure(background='light blue')

q1 = tk.StringVar()
q2 = tk.StringVar()
q3 = tk.StringVar()
c = tk.StringVar(DF, '1')

L1 = tk.Label(DF, text='Nombre de Usuario', bg="White", fg="Black", width=20, height=2).place(x=80, y=50)
E1 = tk.Entry(DF, textvariable=q1).place(x=250, y=50)

L2 = tk.Label(DF, text='', textvariable=q2, bg="White", fg="Black", width=12, height=1).place(x=250, y=150)

L3 = tk.Label(DF, text='Contraseña', bg="White", fg="Black", width=20, height=2).place(x=80, y=100)
E2 = tk.Entry(DF, textvariable=q3, show='*').place(x=250, y=100)

B1 = tk.Button(DF, text='Entrar', command=bienvenida, width=10).place(x=250, y=200)
B2 = tk.Button(DF, text='Cerrar', command=confirmar_salida, width=10).place(x=250, y=250)

DF.mainloop()
