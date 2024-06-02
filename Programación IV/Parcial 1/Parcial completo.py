# Anderson Adarve Valencia - Santiago Aristizabal Sepulveda

class CifradoCesar:
    def _init_(self, desplazamiento):
        self.desplazamiento = desplazamiento

    def cifrar(self, texto_plano):
        texto_cifrado = ""
        for caracter in texto_plano:
            if caracter.isalpha():
                if caracter.islower():
                    texto_cifrado += chr((ord(caracter) - 97 + self.desplazamiento) % 26 + 97)
                elif caracter.isupper():
                    texto_cifrado += chr((ord(caracter) - 65 + self.desplazamiento) % 26 + 65)
            else:
                texto_cifrado += caracter
        return texto_cifrado

    def descifrar(self, texto_cifrado):
        texto_descifrado = ""
        for caracter in texto_cifrado:
            if caracter.isalpha():
                if caracter.islower():
                    texto_descifrado += chr((ord(caracter) - 97 - self.desplazamiento) % 26 + 97)
                elif caracter.isupper():
                    texto_descifrado += chr((ord(caracter) - 65 - self.desplazamiento) % 26 + 65)
            else:
                texto_descifrado += caracter
        return texto_descifrado

# Entidad Usuario.
class Usuario:

    # Atributos.
    def _init_(self, nombre, celular, id, direccion):
        self.nombre = nombre
        self.celular = celular
        self.id = id
        self.direccion = direccion

# Entidad Producto.
class Producto:

    # Atributos.
    def _init_(self, nombre, cantidad):
        self.nombre = nombre
        self.cantidad = cantidad


class Gestor_usuarios:
    def _init_(self, archivo):
        self.archivo = archivo
        self.usuarios = self.cargar_usuarios()
        
    def cargar_usuarios(self):
        lista_usuarios = []
        try:
            with open(self.archivo, 'r') as f:
                for linea in f:
                    nombre, celular, id, direccion = linea.strip().split(',')
                    usuario = Usuario(nombre, celular, id, direccion)
                    lista_usuarios.append(usuario)

        except FileNotFoundError:
            print("\nEl archivo de usuarios no existe. Creando una lista vacía.\n")
        return lista_usuarios

    def crear_usuario(self, nombre, celular, id, direccion):

        for usuario in self.usuarios:
            if usuario.id == id:
                print("\nYa existe un usuario con este ID...\n")
                return()
        
        usuario = Usuario(nombre, celular, id, direccion)
        self.usuarios.append(usuario)

        with open(r"usuarios.txt", "a") as archivo:
            archivo.write(f"{usuario.nombre},{usuario.celular},{usuario.id},{usuario.direccion}\n")

    def consultar_usuarios(self):
        print("\nUsuarios en el sistema: \n")
        for usuario in self.usuarios:
            print(f"Nombre: {usuario.nombre} - Cel: {usuario.celular} - C.C.: {usuario.id} - Dir: {usuario.direccion}\n")

    def editar(self, id, atributo):
        print(f"\nEditando usuario con C.C. {id}...")
    
        for usuario in self.usuarios:
            if usuario.id == id:
                match atributo:
                    case 1:
                        nombre = str(input("\nIngrese el nuevo nombre: "))
                        usuario.nombre = nombre
                        self.guardar_usuarios()
                        break

                    case 2:
                        celular = str(input("\nIngrese el nuevo celular: "))
                        usuario.celular = celular
                        self.guardar_usuarios()
                        break
                     
                    case 3:
                        direccion = str(input("\nIngrese la nueva direccion: "))
                        usuario.direccion = direccion
                        self.guardar_usuarios()
                        break

                    case _:
                        print("\nIngrese una opcion valida.\n")
        else:
            print(f"\nNo se encontro al ususario con C.C. {id}\n")

    def guardar_usuarios(self):
        with open(self.archivo, 'w') as f:
            for usuario in self.usuarios:
                f.write(f"{usuario.nombre},{usuario.celular},{usuario.id},{usuario.direccion}\n")

    def borrar_usuario(self, id):
        print(f"\nBorrando usuario con C.C. {id}...")

        for usuario in self.usuarios:
            if usuario.id == id:
                self.usuarios.remove(usuario)
                self.guardar_usuarios()
                print("\nUsuario borrado exitosamente.")      
                break
        else:
            print(f"\nNo se encontro al ususario con C.C. {id}\n")
    

class Inventario:
    def _init_(self, archivo):
        self.archivo = archivo
        self.productos = self.cargar_productos()

    def cargar_productos(self):
        lista_productos = []
        try:
            with open(self.archivo, 'r') as f:
                for linea in f:
                    nombre, cantidad = linea.strip().split(',')
                    producto = Producto(nombre, cantidad)
                    lista_productos.append(producto)

        except FileNotFoundError:
            print("\nEl archivo de inventario no existe. Creando una lista vacía.\n")
        return lista_productos
    
    def consultar_productos(self):
        print("\nProductos en el inventario: \n")
        for producto in self.productos:
            print(f"Nombre: {producto.nombre} - Cantidad: {producto.cantidad}\n")

    def agregar(self, name, quantity):

        for producto in self.productos:
            if producto.nombre.lower() == name.lower():
                # Si el producto ya existe, incrementar la cantidad en 1
                producto.cantidad += quantity
                self.guardar_productos()
                print("\nCantidad de producto incrementada satisfactoriamente...\n")
                return()
        else:
            producto = Producto(name, quantity)

            self.productos.append(producto)

            with open(self.archivo, "a") as archivo:
                archivo.write(f"{producto.nombre},{producto.cantidad}\n")
            
            print("\nProducto agregado satisfactoriamente...\n")               

    def buscar(self, name):
        print(f"\nBuscando {name}...")
    
        for producto in self.productos:
            if producto.nombre == name:
                print(f"\nProducto encontrado -> Producto: {producto.nombre} - Cantidad: {producto.cantidad}\n")
        else:
            print(f"\nEl producto {name} no se ha encontrado en el inventario...\n")
            

    def ordenar(self):
        
        if not self.productos:
            print("\nNo hay productos en el inventario...\n")
            return()
    
        self.productos.sort(key=lambda producto: producto.nombre)

        with open(self.archivo, 'w') as f:
            for producto in self.productos:
                f.write(f"{producto.nombre},{producto.cantidad}\n")
            
        print("\nProductos organizados satisfactoriamente...\n")


    def guardar_productos(self):
        with open(self.archivo, 'w') as f:
            for producto in self.productos:
                f.write(f"{producto.nombre},{producto.cantidad}\n")

    def borrar_producto(self, name):
        print(f"\nBorrando {name}...")

        for producto in self.productos:
            if producto.nombre.lower() == name.lower():
                self.productos.remove(producto)
                self.guardar_productos()
                print("\nProducto borrado exitosamente...\n")      
                break
        else:
            print(f"\nNo se encontro {name}...\n")

def analizar_numero(numero):
    # Descomponer el número en sus dígitos
    primero = numero // 1000
    segundo = (numero // 100) % 10
    tercero = (numero // 10) % 10
    cuarto = numero % 10
    
    # Verificar si el primer número es múltiplo del cuarto número
    es_multiplo = primero % cuarto == 0
    
    # Calcular la suma del segundo y el tercer número
    suma_segundo_tercero = segundo + tercero
    
    # Imprimir los resultados
    print(f"\nEl primer número es múltiplo del cuarto número: {es_multiplo}\n")
    print(f"\nLa suma del segundo y tercer número es: {suma_segundo_tercero}\n")
    

def menu_punto_2():
    gestor = Gestor_usuarios("usuarios.txt")

    while True: 
        opcion = int(input('''
            Menú de opciones:
                           
                1. Crear usuario
                2. Consultar usuarios inscritos
                3. Editar al menos dos atributos del usuario
                4. Borrar usuario
                0. Salir
                           
            Por favor elija una opcion: '''))
        
        match opcion:
            
            case 1:
                nombre = str(input("\nIngrese el nombre: "))
                celular = str(input("\nIngrese el celular: "))
                id = str(input("\nIngrese su cedula: "))
                direccion = str(input("\nIngrese la direccion: "))

                gestor.crear_usuario(nombre, celular, id, direccion)
            
            case 2:
                gestor.consultar_usuarios()
                
            case 3:
                gestor.consultar_usuarios()
                
                id = str(input("\nIngrese la C.C. del usuario que desea editar: "))

                print("\nSeleccione el atributo que desea editar: ")

                atributo = int(input('''
                        1. Nombre
                        2. Celular
                        3. Direccion
                        0. Salir
                                     
                    Por favor elija un atributo: '''))
                
                gestor.editar(id, atributo)


            case 4:
                gestor.consultar_usuarios()
                
                borrar_id = str(input("\nIngrese la C.C. del usuario que desea borrar: "))

                gestor.borrar_usuario(borrar_id)
                
            case 0:
                print("\nSaliendo...")
                return()
                
            case _:
                print("\nOpción incorrecta. Por favor, ingrese una opción válida.\n")


def menu_punto_3():

    inventario = Inventario("inventario.txt")

    while menu: 
        opcion = int(input('''
            Menú de opciones:
                           
                1. Ingresar producto al inventario
                2. Buscar un producto en el inventario
                3. Borrar un producto 
                4. Ordenar los productos en el inventario
                5. Consultar productos en el inventario
                0. Salida
                           
            Por favor elija una opcion: '''))
        
        match opcion:

            case 1:
                name = str(input("\nNombre del producto: "))
                cantidad = int(input("\nCantidad del producto: "))
                inventario.agregar(name, cantidad)

            case 2:
                name = str(input("\nNombre del producto: "))
                inventario.buscar(name)

            case 3: 
                name = str(input("\nIngrese el nombre del producto que desea borrar del inventario: "))
                inventario.borrar_producto(name)

            case 4:          
                inventario.ordenar()

            case 5:
                inventario.consultar_productos()

            case 0:
                print("\nSaliendo...\n")
                return()
            
            case _:
                print("\nOpción incorrecta. Por favor, ingrese una opción válida.\n")

def menu():
    while True:
          
        opcion = int(input('''
            Menú de opciones:
                           
                1. Punto 1.
                2. Punto 2.
                3. Punto 3.
                4. Punto 4.
                5. Punto 5.	
                0. Salir.
                           
            Ingrese una opción: '''))
        
        match opcion:
            
            case 1:
                #  1. Haciendo uso de los comentarios defina los siguientes conceptos:
                    # a. Clase
                    # b. Objeto
                    # c. Self
                    # d. Constructor
                    # e. Programación orientada objetos
                    # f. Método
                    # g. Instancia
                
                    # a. Clase: En Python, una clase es como un plano o una plantilla que define la estructura y el comportamiento de los objetos,una clase es un diseño para crear objetos con características y funciones específicas.

                    # b. Objeto: Un objeto es una instancia de una clase. En Python, cuando se crea un objeto, se esta creando una instancia de esa clase. Por ejemplo, si se tiene una clase llamada “carro”, un objeto sería un automóvil específico creado a partir de esa clase.

                    # c. Self: En Python, "self.0" se refiere a la instancia actual de la clase. Se utiliza dentro de los métodos de la clase para acceder a los atributos y métodos de esa instancia en particular. Es una convención para referirse al objeto mismo dentro de su propia definición.

                    # d. Constructor: El constructor en Python es un método especial llamado "init()" que se llama automáticamente cuando se crea una nueva instancia de la clase. Se utiliza para inicializar los atributos del objeto y realizar cualquier otra configuración necesaria antes de que el objeto esté listo para su uso.

                    # e. Programación orientada a objetos: Es un paradigma de programación que se basa en el concepto de "objetos", que son instancias de clases que contienen atributos y métodos.

                    # f. Método: En Python, un método es una función definida dentro de una clase que opera en instancias de esa clase. Los métodos representan comportamientos asociados con los objetos y pueden acceder y modificar los atributos del objeto.

                    # g. Instancia: Una instancia es un objeto específico creado a partir de una clase. Cada instancia tiene sus propios valores de atributos. 
                
                print("\n1. Definicion de Conceptos\n")
                      
                print("a. Clase: En Python, una clase es como un plano o una plantilla que define la estructura y el comportamiento de los objetos,una clase es un diseño para crear objetos con características y funciones específicas.\n")

                print("b. Objeto: Un objeto es una instancia de una clase. En Python, cuando se crea un objeto, se esta creando una instancia de esa clase. Por ejemplo, si se tiene una clase llamada “carro”, un objeto sería un automóvil específico creado a partir de esa clase.\n")

                print("c. Self: En Python, 'self' se refiere a la instancia actual de la clase. Se utiliza dentro de los métodos de la clase para acceder a los atributos y métodos de esa instancia en particular. Es una convención para referirse al objeto mismo dentro de su propia definición.\n")

                print("d. Constructor: El constructor en Python es un método especial llamado 'init()' que se llama automáticamente cuando se crea una nueva instancia de la clase. Se utiliza para inicializar los atributos del objeto y realizar cualquier otra configuración necesaria antes de que el objeto esté listo para su uso.\n")

                print("e. Programación orientada a objetos: Es un paradigma de programación que se basa en el concepto de 'objetos', que son instancias de clases que contienen atributos y métodos.\n")

                print("f. Método: En Python, un método es una función definida dentro de una clase que opera en instancias de esa clase. Los métodos representan comportamientos asociados con los objetos y pueden acceder y modificar los atributos del objeto.\n")

                print("g. Instancia: Una instancia es un objeto específico creado a partir de una clase. Cada instancia tiene sus propios valores de atributos.\n") 


            case 2:
                # 2. Realice un programa para gestionar la información de usuarios como son:
                    # a. Crear usuario
                    # b. Consultar usuarios inscritos
                    # c. Editar al menos dos atributos del usuario
                    # d. Borrar usuario
                    # Para este punto deben implementar el paradigma orientado a objetos, el
                    # tema de constructores y archivos.
                
                print("\n2. Gestionar la información de usuarios: \n")

                menu_punto_2()

                
            case 3:
                # 3. Realizar un programa con el paradigma orientado a objetos y archivos para
                #     gestionar un inventario sencillo donde tendremos el nombre del producto y
                #     la cantidad del producto, el sistema de realizar las siguientes acciones:
                #     a. Ingresar elementos al inventario
                #     b. Buscar un elemento especifico en el inventario
                #     c. Borrar un elemento en especifico
                #     d. Ordenar los elementos en el inventario
                
                print("\n3. Gestionar la información de usuarios: \n")

                menu_punto_3()                

            case 4: 
                # 4. Diseñe un programa que reciba un numero entero de 4 cifras, diga si el
                # primer número es múltiplo del cuarto número y debe mostrar la suma del
                # segundo número y el tercero (no requiere implementar el paradigma
                # orientado a objetos), este punto se debe hacer usando operaciones
                # aritméticas para descomponer el numero de 4 cifras.
                # Pedir al usuario que ingrese un número de 4 cifras

                numero = int(input("\nIngrese un número entero de 4 cifras: "))

                # Verificar si el número tiene exactamente 4 cifras
                if 1000 <= numero <= 9999:
                    analizar_numero(numero)
                else:
                    print("\nEl número ingresado no tiene 4 cifras...\n")

            case 5:
                # 5. Implementar el algoritmo de cifrado cesar haciendo uso de POO, archivos y listas.

                desplazamiento = int(input("Ingrese el valor del desplazamiento para el cifrado César: "))
                cifrador = CifradoCesar(desplazamiento)

                # cifrado
                texto_plano = input("Ingrese el texto a cifrar: ")
                texto_cifrado = cifrador.cifrar(texto_plano)
                print("Texto cifrado:", texto_cifrado)

                # descifrado
                texto_descifrado = cifrador.descifrar(texto_cifrado)
                print("Texto descifrado:", texto_descifrado)

                # texto cifrado en un archivo
                nombre_archivo = "texto_cifrado.txt"
                with open(nombre_archivo, "w") as archivo:
                    archivo.write(texto_cifrado)

                # Leer texto cifrado desde el archivo y descifrarlo
                with open(nombre_archivo, "r") as archivo:
                    texto_cifrado_archivo = archivo.read()
                texto_descifrado_archivo = cifrador.descifrar(texto_cifrado_archivo)
                print("Texto descifrado desde el archivo:", texto_descifrado_archivo)

            case 0: 
                return()
            

menu()