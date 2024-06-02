class Sucursal:
    def __init__(self, codigo, nombre, direccion, telefono):
        self.__codigo = codigo
        self.__nombre = nombre
        self.__direccion = direccion
        self.__telefono = telefono

    def crear(self):
        print("Sucursal creada")

    def eliminar_sucursal(codigo_sucursal):
        with open("informacion.txt", "r+") as archivo:
            lineas = archivo.readlines()
            archivo.seek(0) # Posiciona el puntero al inicio del archivo

            eliminar = False
            eliminar_linea_anterior = False
            lineas_a_eliminar = 0 # Contador de líneas a eliminar

            for linea in lineas: # Recorre las líneas del archivo
                if not eliminar: # Si no se está eliminando la sucursal
                    
                    if f"Codigo: {codigo_sucursal}" in linea: 
                        eliminar = True
                        if eliminar_linea_anterior: 
                            lineas_a_eliminar += 2  # Borra la línea que contiene el código y la línea anterior
                        else:
                            lineas_a_eliminar += 1  # Solo borra la línea que contiene el código
                    else:
                        eliminar_linea_anterior = False
                        
                elif lineas_a_eliminar <= 37:  # Borra las 36 líneas siguientes
                    lineas_a_eliminar += 1 # Incrementa el contador de líneas a eliminar
                    
                else:
                    eliminar = False  # Detén la eliminación después de las 36 líneas

                if not eliminar:
                    archivo.write(linea) # Escribe la línea en el archivo

            archivo.truncate() # Trunca el archivo para eliminar las líneas que no se han escrito

    # Getters
    def get_codigo(self):
        return self.__codigo

    def get_nombre(self):
        return self.__nombre

    def get_direccion(self):
        return self.__direccion

    def get_telefono(self):
        return self.__telefono