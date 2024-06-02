''' Menú de opciones de los 6 puntos del taller 3 '''

# Hecho por Steven Grisales López - 1034289634
from io import * 
import math

def menu():
    while True:
          
        opcion = int(input('''
            Menú de opciones.
                1. Punto 1.
                2. Punto 2.
                3. Punto 3.
                4. Punto 4.
                5. Punto 5.
                6. Punto 6.	
                0. Salir.
            Ingrese una opción: '''))
        
        match opcion:
            
            case 1:
                ''' 1. Diseñe las siguientes entidades con al menos 4 atributos y al menos dos métodos:
                a. Avión
                b. Celular
                c. Asignatura
                d. Ejercito
                e. Silla
                f. Audífonos '''

                def menu_punto1():
                    while True:
                        
                        opcion = int(input('''
                            Menú de opciones.
                                1. Avión.
                                2. Celular.
                                3. Asignatura.
                                4. Ejercito.
                                5. Silla.
                                6. Audífonos.
                                0. Salir
                            Ingrese una opción: '''))
                        
                        match opcion:
                            
                            case 1:
                                avion = Avion("Airbus", 319, 156, "Blanco con Azul")
                                avion.despegar()
                                avion.aterrizar()
                                avion.mostrarDatos()
                            
                            case 2:
                                celular = Celular("Xiaomi", "Redmi 12", "Blanco", "Android")
                                celular.llamar(3052456442)
                                celular.enviar_mensaje(3116086466, "Hola que tal soy colosal")
                                celular.mostrarDatos()
                                
                            case 3:
                                asignatura = Asignatura("Programación", "IS553", 3, 4)
                                asignatura.estudiar()
                                asignatura.presentar_examen()
                                asignatura.mostrarDatos()
                                
                            case 4:
                                ejercito = Ejercito("ELN", "Infanteria", 20, "AK47")
                                ejercito.atacar()
                                ejercito.defender()
                                ejercito.mostrarDatos()
                                
                            case 5:
                                silla = Silla("Tailus", "GamerPRO", "Plástico", "Negra")
                                silla.sentarse()
                                silla.recostarse()
                                silla.mostrarDatos()
                                
                            case 6:
                                audifonos = Audifonos("Apple", "X-Max", "Blancos", "Bluetooth")
                                audifonos.escuchar_musica()
                                audifonos.contestar_llamada()
                                audifonos.mostrarDatos()

                                
                            case 0:
                                print("\n   Saliendo de la opción...")
                                return()
                                
                            case _:
                                print("\nOpción inválida. Por favor, seleccione una opción válida.")

                # Entidad Avión.
                class Avion:
                    # Atributos.
                    def __init__(self, marca, modelo, capacidad, color):
                        self.marca = marca
                        self.modelo = modelo
                        self.capacidad = capacidad
                        self.color = color

                    # Métodos.
                    def despegar(self):
                        print(f"\nEl avión {self.marca} {self.modelo} ha despegado.")
                        
                        with open(r"Archivos\punto1.txt","w") as archivo:
                            archivo.write(f"El avión {self.marca} {self.modelo} ha despegado." + "\n")

                    def aterrizar(self):
                        print(f"El avión {self.marca} {self.modelo} ha aterrizado.")
                        
                        with open(r"Archivos\punto1.txt","a") as archivo:
                            archivo.write(f"El avión {self.marca} {self.modelo} ha aterrizado." + "\n")

                    def mostrarDatos(self):
                        print(f"Marca del avión: {self.marca}, Modelo del avión: {self.modelo}, Capacidad de pasajeros: {self.capacidad}, Color del avión: {self.color}.")
                        
                        with open(r"Archivos\punto1.txt","a") as archivo:
                            archivo.write(f"Marca del avión: {self.marca}, Modelo del avión: {self.modelo}, Capacidad de pasajeros: {self.capacidad}, Color del avión: {self.color}." + "\n\n")

                # Entidad Celular.
                class Celular:
                    # Atributos.
                    def __init__(self, marca, modelo, color, sistema_operativo):
                        self.marca = marca
                        self.modelo = modelo
                        self.color = color
                        self.sistema_operativo = sistema_operativo

                    # Métodos.
                    def llamar(self, numero):
                        print(f"\nLlamando al número {numero}...")
                        
                        with open(r"Archivos\punto1.txt","a") as archivo:
                            archivo.write(f"Llamando al número {numero}..." + "\n")

                    def enviar_mensaje(self, numero, mensaje):
                        print(f"Enviando mensaje al número {numero}: {mensaje}")
                        
                        with open(r"Archivos\punto1.txt","a") as archivo:
                            archivo.write(f"Enviando mensaje al número {numero}: {mensaje}" + "\n")

                    def mostrarDatos(self):
                        print(f"Marca del celular: {self.marca}, Modelo del celular: {self.modelo}, Color del celular: {self.color}, Sistema Operativo: {self.sistema_operativo}.")
                        
                        with open(r"Archivos\punto1.txt","a") as archivo:
                            archivo.write(f"Marca del celular: {self.marca}, Modelo del celular: {self.modelo}, Color del celular: {self.color}, Sistema Operativo: {self.sistema_operativo}." + "\n\n")

                # Entidad Asignatura.
                class Asignatura:
                    # Atributos.
                    def __init__(self, nombre, codigo, creditos, intensidad_horaria):
                        self.nombre = nombre
                        self.codigo = codigo
                        self.creditos = creditos
                        self.intensidad_horaria = intensidad_horaria

                    # Métodos.
                    def estudiar(self):
                        print(f"\nEstudiando la asignatura {self.nombre}...")
                        
                        with open(r"Archivos\punto1.txt","a") as archivo:
                            archivo.write(f"Estudiando la asignatura {self.nombre}..." + "\n")

                    def presentar_examen(self):
                        print(f"Presentando examen de la asignatura {self.nombre}...")
                        
                        with open(r"Archivos\punto1.txt","a") as archivo:
                            archivo.write(f"Presentando examen de la asignatura {self.nombre}..." + "\n")

                    def mostrarDatos(self):
                        print(f"Nombre de la asignatura: {self.nombre}, Código de la asignatura: {self.codigo}, Cantidad de créditos: {self.creditos}, Intensidad horaria: {self.intensidad_horaria} horas.")
                        
                        with open(r"Archivos\punto1.txt","a") as archivo:
                            archivo.write(f"Nombre de la asignatura: {self.nombre}, Código de la asignatura: {self.codigo}, Cantidad de créditos: {self.creditos}, Intensidad horaria: {self.intensidad_horaria} horas." + "\n\n")

                # Entidad Ejercito.
                class Ejercito:
                    # Atributos.
                    def __init__(self, nombre, division, cantidad_soldados, armamento):
                        self.nombre = nombre
                        self.division = division
                        self.cantidad_soldados = cantidad_soldados
                        self.armamento = armamento

                    # Métodos.
                    def atacar(self):
                        print(f"\nEl ejército {self.nombre} ha atacado.")
                        
                        with open(r"Archivos\punto1.txt","a") as archivo:
                            archivo.write(f"El ejército {self.nombre} ha atacado." + "\n")

                    def defender(self):
                        print(f"El ejército {self.nombre} se ha defendido.")
                        
                        with open(r"Archivos\punto1.txt","a") as archivo:
                            archivo.write(f"El ejército {self.nombre} se ha defendido." + "\n")

                    def mostrarDatos(self):
                        print(f"Nombre del ejercito: {self.nombre}, Tipo de divisiones: {self.division}, Cantidad de soldados: {self.cantidad_soldados}, Armamento de los soldados: {self.armamento}.")
                        
                        with open(r"Archivos\punto1.txt","a") as archivo:
                            archivo.write(f"Nombre del ejercito: {self.nombre}, Tipo de divisiones: {self.division}, Cantidad de soldados: {self.cantidad_soldados}, Armamento de los soldados: {self.armamento}." + "\n\n")

                # Entidad Silla.
                class Silla:
                    # Atributos.
                    def __init__(self, marca, modelo, material, color):
                        self.marca = marca
                        self.modelo = modelo
                        self.material = material
                        self.color = color

                    # Métodos.
                    def sentarse(self):
                        print(f"\nSentándose en la silla {self.marca} {self.modelo}...")
                        
                        with open(r"Archivos\punto1.txt","a") as archivo:
                            archivo.write(f"Sentándose en la silla {self.marca} {self.modelo}..." + "\n")

                    def recostarse(self):
                        print(f"Recostándose en la silla {self.marca} {self.modelo}...")
                        
                        with open(r"Archivos\punto1.txt","a") as archivo:
                            archivo.write(f"Recostándose en la silla {self.marca} {self.modelo}..." + "\n")

                    def mostrarDatos(self):
                        print(f"Marca de la silla: {self.marca}, Modelo de la silla: {self.modelo}, Material de la silla: {self.material}, Color de la silla: {self.color}.")
                        
                        with open(r"Archivos\punto1.txt","a") as archivo:
                            archivo.write(f"Marca de la silla: {self.marca}, Modelo de la silla: {self.modelo}, Material de la silla: {self.material}, Color de la silla: {self.color}." + "\n\n")

                # Entidad Audífonos.
                class Audifonos:
                    # Atributos.
                    def __init__(self, marca, modelo, color, tipo_conexion):
                        self.marca = marca
                        self.modelo = modelo
                        self.color = color
                        self.tipo_conexion = tipo_conexion

                    # Métodos.
                    def escuchar_musica(self):
                        print(f"\nEscuchando música con los audífonos {self.marca} {self.modelo}...")
                        
                        with open(r"Archivos\punto1.txt","a") as archivo:
                            archivo.write(f"Escuchando música con los audífonos {self.marca} {self.modelo}..." + "\n")

                    def contestar_llamada(self):
                        print(f"Contestando llamada con los audífonos {self.marca} {self.modelo}...")
                        
                        with open(r"Archivos\punto1.txt","a") as archivo:
                            archivo.write(f"Contestando llamada con los audífonos {self.marca} {self.modelo}..." + "\n")

                    def mostrarDatos(self):
                        print(f"Marca de audífonos: {self.marca}, Modelo de los audífonos: {self.modelo}, Color de los audífonos: {self.color}, Tipo de conexión: {self.tipo_conexion}.")
                        
                        with open(r"Archivos\punto1.txt","a") as archivo:
                            archivo.write(f"Marca de audífonos: {self.marca}, Modelo de los audífonos: {self.modelo}, Color de los audífonos: {self.color}, Tipo de conexión: {self.tipo_conexion}." + "\n\n")

                menu_punto1()
            
            case 2:
                ''' 2. Diseñar una clase para crear un objeto rectángulo con sus respectivos atributos, un método que dibuje el rectángulo con “*”
                y otro método que realice alguna fórmula con los datos del rectángulo. '''

                class Rectangulo:
                    # Atributos.
                    def __init__(self, base, altura):
                        self.base = base
                        self.altura = altura

                    # Métodos.
                    def dibujar(self):
                        self.altura = int(input("\nIngrese la altura: "))
                        self.base = int(input("Ingrese la base: "))

                        with open(r"Archivos\punto2.txt","a") as archivo:
                            archivo.write(f"\nLa altura es {self.altura}, y la base es: {self.base}" + "\n")

                        for _ in range(self.altura):
                            print("*" * self.base)

                            with open(r"Archivos\punto2.txt","a") as archivo:
                                archivo.write("*" * self.base + "\n")

                    def calcular_formulas(self):
                        print(f"El perímetro del rectángulo es: {2 * (self.base + self.altura)}")
                        print(f"El área del rectángulo es: {self.base * self.altura}")

                        with open(r"Archivos\punto2.txt","a") as archivo:
                            archivo.write(f"El perímetro del rectángulo es {2 * (self.base + self.altura)}." + "\n" + f"El área del rectángulo es {self.base * self.altura}." + "\n")

                # Prueba de la clase.
                rectangulo = Rectangulo(0, 0)
                rectangulo.dibujar()
                rectangulo.calcular_formulas()

                
            case 3:
                ''' 3. Diseñar una clase para crear un objeto empleado con al menos 5 atributos y los siguientes métodos:
                    a. Calcular lo que se gana al mes teniendo en cuenta el número de horas que trabaja, el valor de cada hora.
                    b. Calcular el tiempo de antigüedad y cuanto le falta para pensionarse teniendo en cuenta que las mujeres se pensionan antes que los hombres.
                    c. Calcular cuánto paga por salud y pensión al mes el empleado teniendo en cuenta que es 4% de salud y 4% de pensión y al año cuanto abona en pensión.
                    d. Se deben guardar todos los datos de los empleados en un archivo. '''

                class Empleado:
                    # Atributos.
                    def __init__(self, nombre, edad, sexo, horas_trabajadas, valor_hora, años_empresa):
                        self.nombre = nombre
                        self.edad = edad
                        self.sexo = sexo
                        self.horas_trabajadas = horas_trabajadas
                        self.valor_hora = valor_hora # 8458 pesos
                        self.años_empresa = años_empresa

                    # Métodos.
                    
                    # a) Método para calcular el salario mensual.
                    def salario_mensual(self):
                        salario_mensual = self.horas_trabajadas * self.valor_hora
                        print(f"El salario mensual de {self.nombre} es: {salario_mensual} pesos.")
                        
                        with open(r"Archivos\punto3.txt", "a") as file:
                            file.write(f"\nEl salario mensual de {self.nombre} es: {salario_mensual} pesos.")

                    # b) Método para calcular el tiempo de antigüedad y el tiempo que falta para pensionarse.
                    def tiempo_pension(self):
                        if self.sexo == "Mujer" or self.sexo== "mujer":
                            
                            if self.años_empresa >= 25:
                                
                                if self.edad >= 57:
                                    
                                    print(f"{self.nombre} ya esta pensionada.")
                                    with open(r"Archivos\punto3.txt", "a") as archivo:
                                        archivo.write(f"\n{self.nombre} ya esta pensionada.")
                                else:
                                    
                                    print(f"A {self.nombre} le faltan {57 - self.edad} para pensionarse.")
                                    with open(r"Archivos\punto3.txt", "a") as archivo:
                                        archivo.write(f"\nA {self.nombre} le faltan {57 - self.edad} para pensionarse.")
                            else:
                                
                                print(f"A {self.nombre} le faltan {25 - self.años_empresa} para cumplir el tiempo de antiguedad.")
                                with open(r"Archivos\punto3.txt", "a") as archivo:
                                    archivo.write(f"\nA {self.nombre} le faltan {25 - self.años_empresa} para cumplir el tiempo de antiguedad.")
                                    
                        elif self.sexo == "Hombre" or self.sexo == "hombre":
                            
                            if self.años_empresa >= 25:
                                
                                if self.edad >= 62:
                                    
                                    print(f"{self.nombre} ya esta pensionado.")
                                    with open(r"Archivos\punto3.txt", "a") as archivo:
                                        archivo.write(f"\n{self.nombre} ya esta pensionado.")
                                else:
                                    
                                    print(f"A {self.nombre} le faltan {62 - self.edad} para pensionarse.")
                                    with open(r"Archivos\punto3.txt", "a") as archivo:
                                        archivo.write(f"\nA {self.nombre} le faltan {62 - self.edad} para pensionarse.")
                            else:
                                
                                print(f"A {self.nombre} le faltan {25 - self.años_empresa} para cumplir el tiempo de antiguedad.")
                                with open(r"Archivos\punto3.txt", "a") as archivo:
                                    archivo.write(f"\nA {self.nombre} le faltan {25 - self.años_empresa} para cumplir el tiempo de antiguedad.")
                                    
                        else: 
                            print("Error, el genero ingresado no es valido.")
                            with open(r"Archivos\punto3.txt", "a") as archivo:
                                archivo.write("\nError, el genero ingresado no es valido.")

                    # c) Método para calcular el valor de la salud y la pensión.
                    def salud_pension(self):
                        salud = self.horas_trabajadas * self.valor_hora * 0.04
                        pension = self.horas_trabajadas * self.valor_hora * 0.04
                        
                        print(f"El empleado paga en salud ${salud} y en pension ${pension}, por lo tanto, al año paga en pension ${pension * 12}.\n")
                        
                        with open(r"Archivos\punto3.txt", "a") as archivo:
                            archivo.write(f"\nEl empleado paga en salud ${salud} y en pension ${pension}, por lo tanto, al año paga en pension ${pension * 12}.\n")
                    

                    # d) Método para guardar los datos de los empleados en un archivo.
                    def guardar_datos_Usuario(self):
                        nombre = input("Ingrese el nombre del empleado: ")
                        self.nombre = nombre
                        
                        edad = int(input("Ingrese la edad del empleado: "))
                        self.edad = edad
                        
                        sexo = input("Ingrese el genero del empleado: ")
                        self.sexo = sexo
                        
                        valor_hora = int(input("Ingrese el valor de las horas: "))
                        self.valor_hora = valor_hora
                        
                        horas_trabajadas = int(input("Ingrese las horas totales trabajadas: "))
                        self.horas_trabajadas = horas_trabajadas
                        
                        años_empresa = int(input("Ingrese la antiguedad del empleado: "))
                        self.años_empresa = años_empresa

                        print(f"\n---------------------------------------------------------------------------\nNombre: {self.nombre}.\nEdad: {self.edad}.\nGenero: {self.sexo}.\nValor de horas: ${self.valor_hora}.\nHoras trabajadas: {self.horas_trabajadas}.\nAntiguedad: {self.años_empresa} años.\n---------------------------------------------------------------------------")
                        with open(r"Archivos\punto3.txt", "a") as archivo:
                            archivo.write(f"\n---------------------------------------------------------------------------\nNombre: {self.nombre}.\nEdad: {self.edad}.\nGenero: {self.sexo}.\nValor de horas: ${self.valor_hora}.\nHoras trabajadas: {self.horas_trabajadas}.\nAntiguedad: {self.años_empresa} años.\n---------------------------------------------------------------------------")

                Trabajador = Empleado("", 0, "", 0, 0, 0)
                Trabajador.guardar_datos_Usuario()
                Trabajador.salario_mensual()
                Trabajador.tiempo_pension()
                Trabajador.salud_pension()

                
            case 4:
                ''' 4. Diseñar una clase para un objeto calculadora científica con sus respectivos atributos y al menos 12 métodos. '''
                def menu_punto4():
                    while True:
                        opcion = int(input('''\nBienvenido a la calculadora científica.
                            1. Mostrar Datos.
                            2. Sumar. 
                            3. Restar. 
                            4. Multiplicar. 
                            5. Dividir. 
                            6. Potencia. 
                            7. Raíz cuadrada. 
                            8. Raíz cúbica. 
                            9. Logaritmo. 
                            10. Seno.
                            11. Coseno. 
                            12. Tangente. 
                            13. Factorial. 
                            0. Salir. 
                            Ingrese una opción: '''))
                    
                        Calculadora = CalculadoraCientifica("Casio", 50000, "Negra", "Programable", "fx-82MS", 4, "LED", "100GB", 25, "2 años", "Se rasgó", 12)

                        match opcion:
                            case 1:
                                Calculadora.mostrarDatos()
                                
                                
                            case 2:
                                a = int(input("\nIngrese el primer número: "))
                                b = int(input("Ingrese el segundo número: "))
                                print(f"El resultado de la suma es: {Calculadora.sumar(a, b)}" + "\n")
                                
                                with open(r"Archivos\punto4.txt","a") as archivo:
                                    archivo.write(f"El resultado de la suma es: {Calculadora.sumar(a, b)}" + "\n")

                            case 3:
                                a = int(input("\nIngrese el primer número: "))
                                b = int(input("Ingrese el segundo número: "))
                                print(f"El resultado es: {Calculadora.restar(a, b)}" + "\n")
                                
                                with open(r"Archivos\punto4.txt","a") as archivo:
                                    archivo.write(f"El resultado de la resta es: {Calculadora.restar(a, b)}" + "\n")

                            case 4:
                                a = int(input("\nIngrese el primer número: "))
                                b = int(input("Ingrese el segundo número: "))
                                print(f"El resultado es: {Calculadora.multiplicar(a, b)}" + "\n")
                                
                                with open(r"Archivos\punto4.txt","a") as archivo:
                                    archivo.write(f"El resultado de la multiplicación es: {Calculadora.multiplicar(a, b)}" + "\n")

                            case 5:
                                a = int(input("\nIngrese el primer número: "))
                                b = int(input("Ingrese el segundo número: "))
                                print(f"El resultado es: {Calculadora.dividir(a, b)}" + "\n")
                                
                                with open(r"Archivos\punto4.txt","a") as archivo:
                                    archivo.write(f"El resultado de la división es: {Calculadora.dividir(a, b)}" + "\n")

                            case 6:
                                a = int(input("\nIngrese el primer número: "))
                                b = int(input("Ingrese el segundo número: "))
                                print(f"El resultado es: {Calculadora.potencia(a, b)}" + "\n")
                                
                                with open(r"Archivos\punto4.txt","a") as archivo:
                                    archivo.write(f"El resultado de la potencia es: {Calculadora.potencia(a, b)}" + "\n")

                            case 7:
                                a = int(input("\nIngrese el número: "))
                                print(f"El resultado es: {Calculadora.raiz_cuadrada(a)}" + "\n")
                                
                                with open(r"Archivos\punto4.txt","a") as archivo:
                                    archivo.write(f"El resultado de la raíz cuadrada es: {Calculadora.raiz_cuadrada(a)}" + "\n")

                            case 8:
                                a = int(input("\nIngrese el número: "))
                                print(f"El resultado es: {Calculadora.raiz_cubica(a)}" + "\n")
                                
                                with open(r"Archivos\punto4.txt","a") as archivo:
                                    archivo.write(f"El resultado de la raíz cúbica es: {Calculadora.raiz_cubica(a)}" + "\n")

                            case 9:
                                a = int(input("\nIngrese el número: "))
                                print(f"El resultado es: {Calculadora.logaritmo(a)}" + "\n")
                                
                                with open(r"Archivos\punto4.txt","a") as archivo:
                                    archivo.write(f"El resultado del logaritmo es: {Calculadora.logaritmo(a)}" + "\n")

                            case 10:
                                a = int(input("\nIngrese el número: "))
                                print(f"El resultado es: {Calculadora.seno(a)}" + "\n")
                                
                                with open(r"Archivos\punto4.txt","a") as archivo:
                                    archivo.write(f"El resultado del seno es: {Calculadora.seno(a)}" + "\n")

                            case 11:
                                a = int(input("\nIngrese el número: "))
                                print(f"El resultado es: {Calculadora.coseno(a)}" + "\n")
                                
                                with open(r"Archivos\punto4.txt","a") as archivo:
                                    archivo.write(f"El resultado del coseno es: {Calculadora.coseno(a)}" + "\n")

                            case 12:
                                a = int(input("\nIngrese el número: "))
                                print(f"El resultado es: {Calculadora.tangente(a)}" + "\n")
                                
                                with open(r"Archivos\punto4.txt","a") as archivo:
                                    archivo.write(f"El resultado de la tangente es: {Calculadora.tangente(a)}" + "\n")

                            case 13:
                                a = int(input("\nIngrese el número: "))
                                print(f"El resultado es: {Calculadora.factorial(a)}" + "\n")
                                
                                with open(r"Archivos\punto4.txt","a") as archivo:
                                    archivo.write(f"El resultado del factorial es: {Calculadora.factorial(a)}" + "\n")
                            
                            case 0:
                                print("\n   Saliendo de la opción...")
                                return()
                                
                            case _:
                                print("\nOpción inválida. Por favor, seleccione una opción válida.")
                
                class CalculadoraCientifica:

                    def __init__(self, marca, precio, color, tipo, modelo, baterias, pantalla, memoria, teclas, garantia, manual, funciones):
                        self.marca = marca
                        self.precio = precio
                        self.color = color
                        self.tipo = tipo 
                        self.modelo = modelo
                        self.baterias = baterias
                        self.pantalla = pantalla
                        self.memoria = memoria
                        self.teclas = teclas
                        self.garantia = garantia
                        self.manual = manual
                        self.funciones = funciones

                    def mostrarDatos(self):
                        print(f"\nMarca: {self.marca}, Precio: {self.precio}, Color: {self.color}, Tipo: {self.tipo}, Modelo: {self.modelo}, Baterias: {self.baterias}, Pantalla: {self.pantalla}, Memoria: {self.memoria}, Teclas: {self.teclas}, Garantia: {self.garantia}, Manual: {self.garantia}, Funciones: {self.funciones}." + "\n")
                        
                        with open(r"Archivos\punto4.txt","a") as archivo:
                            archivo.write(f"Marca: {self.marca}, Precio: {self.precio}, Color: {self.color}, Tipo: {self.tipo}, Modelo: {self.modelo}, Baterias: {self.baterias}, Pantalla: {self.pantalla}, Memoria: {self.memoria}, Teclas: {self.teclas}, Garantia: {self.garantia}, Manual: {self.garantia}, Funciones: {self.funciones}." + "\n")

                    def sumar(self, a, b):
                        return a + b

                    def restar(self, a, b):
                        return a - b

                    def multiplicar(self, a, b):
                        return a * b

                    def dividir(self, a, b):
                        return a / b

                    def potencia(self, a, b):
                        return a ** b

                    def raiz_cuadrada(self, a):
                        return a ** 0.5

                    def raiz_cubica(self, a):
                        return a ** (1/3)

                    def logaritmo(self, a):
                        return math.log(a)

                    def seno(self, a):
                        return math.sin(a)

                    def coseno(self, a):
                        return math.cos(a)

                    def tangente(self, a):
                        return math.tan(a)

                    def factorial(self, a):
                        return math.factorial(a)
                        
                menu_punto4()
                
            case 5:
                ''' 5. Para la siguiente lista:
                    Lista=[1,1991, “taller”,200,3,”programación”,700, “utp”, “POO”]
                    Implemente uno o varios métodos para hacer:
                         La lista inicial debe quedar guardada en un archivo
                         A partir de la lista inicial se debe guardar en un archivo una lista con los números enteros y en otro archivo guardar la lista con las cadenas.
                         En un ultimo archivo vamos a guardar una lista donde se reemplacen los números impares con la palabra: “reemplazo”
                         Al final debe crear un método donde se imprima solo la mitad de la lista. '''

                class Lista():
                    # Atributos.
                    def __init__(self, lista):
                        self.lista = lista

                    # Métodos.
                    def guardar_lista_inicial(self):
                        with open(r"Archivos\Inicial_punto5.txt","w") as archivo:
                            archivo.write(f"\nLa lista inicial es: {self.lista}." + "\n")
                            
                        print(f"La lista inicial es: {self.lista}.")

                    def guardar_enteros(self):
                        lista_enteros = [] 
                        
                        for i in range(len(self.lista)):
                            if (type(self.lista[i]) == int): # Si el elemento es un número entero.
                                lista_enteros.append(self.lista[i]) # Se agrega el elemento a la lista de enteros.
                    
                        with open(r"Archivos\Enteros_punto5.txt","w") as archivo:
                            archivo.write(f"La lista de solo enteros es: {lista_enteros}." + "\n")
                            
                        print(f"La lista de solo enteros es: {lista_enteros}.")

                    def guardar_cadenas(self):
                        lista_cadenas = []

                        for i in range(len(self.lista)):
                            if (type(self.lista[i]) == str): # Si el elemento es una cadena.
                                lista_cadenas.append(self.lista[i]) # Se agrega el elemento a la lista de cadenas.

                        with open(r"Archivos\Cadenas_punto5.txt","w") as archivo:
                            archivo.write(f"La lista de solo cadenas es: {lista_cadenas}." + "\n")
                            
                        print(f"La lista de solo cadenas es: {lista_cadenas}.")

                    def impares_reemplazo(self):
                        for i in range(len(self.lista)): # Se recorre la lista.
                            # Si el elemento es un número impar, se reemplaza por "reemplazo".
                            if (type(self.lista[i]) == int and self.lista[i] % 2 != 0): 
                                self.lista[i] = "reemplazo"
                        
                        with open(r"Archivos\Impares_punto5.txt","w") as archivo: 
                            archivo.write(f"La lista con impares reemplazados es: {self.lista}." + "\n")
                            
                        print(f"La lista con impares reemplazados es: {self.lista}.")

                    def mitad_lista(self):
                        mitad = len(self.lista) // 2 # // Obtiene la división entera redondeando hacia abajo.
                        print(f"La mitad de la lista es: {self.lista[:mitad]}") # :mitad imprime desde el inicio hasta la mitad de la lista.

                lista = [1, 1991, "taller", 200, 3, "programación", 700, "utp", "POO"]
                Punto5 = Lista(lista)
                Punto5.guardar_lista_inicial()
                Punto5.guardar_enteros()
                Punto5.guardar_cadenas()
                Punto5.impares_reemplazo()       

                
            case 6:
                ''' 6. Realice un ejemplo de cada método de archivos visto en clase. '''

                class Metodos_Archivos:
                    def __init__(self, nombre, edad, genero):
                        self.nombre = nombre
                        self.edad = edad
                        self.genero = genero
                        
                    # Método With para abrir un archivo
                    def metodo_with(self):
                        with open(r"Archivos\punto6.txt", "w") as archivo:
                            archivo.write(f"Nombre: {self.nombre}\nEdad: {self.edad}\nGenero: {self.genero}\n")
                        
                        print("Método With: ")
                        
                        with open(r"Archivos\punto6.txt", "r") as archivo:
                            print(archivo.read())
                            
                    # Método Seek para mover el puntero de lectura/escritura
                    def metodo_seek(self):
                        print("Método Seek: ")
                        
                        with open(r"Archivos\punto6.txt", "r") as archivo:
                            archivo.seek(7)  # Mover el puntero a la posición 7
                            print(archivo.read())
                    
                    # Método Tell para obtener la posición actual del puntero
                    def metodo_tell(self):
                        print("Método Tell:")
                        
                        with open(r"Archivos\punto6.txt", "r") as archivo:
                            archivo.read()  # Leer los primeros 4 caracteres
                            print(f"La cantidad de caracteres en el archivo es: {archivo.tell()}\n")  # Mostrar la nueva posición del puntero
                    
                    # Método Readline para leer una línea a la vez
                    def metodo_readline(self):
                        print("Método Readline: ")
                        
                        with open(r"Archivos\punto6.txt", "r") as archivo:
                            print(archivo.readline())  # Leer la primera línea

                    # Método Readlines para leer todas las líneas en una lista
                    def metodo_readlines(self):
                        print("Método Readlines: ")
                        
                        with open(r"Archivos\punto6.txt", "r") as archivo:
                            for linea in archivo.readlines():
                                print(linea)

                    # Método Writelines para escribir una lista de líneas en un archivo
                    def metodo_writelines(self):
                        Lista = ["Cancion \n", "sobre \n", "piratas"]
                        
                        print("Método Writelines: ")
                        with open (r"Archivos\punto6.txt", "r+") as archivo: 
                            archivo.read()  
                                            
                            final_del_archivo = archivo.tell()   
                            archivo.writelines(Lista)   
                            archivo.seek(final_del_archivo)   
                            contenido_editado = archivo.read()
                            print (contenido_editado)           

                Metodos = Metodos_Archivos("Juan", 25, "Masculinos")
                Metodos.metodo_with()
                Metodos.metodo_seek()
                Metodos.metodo_tell()
                Metodos.metodo_readline()
                Metodos.metodo_readlines()
                Metodos.metodo_writelines()
                
            case 0:
                print("\n   Saliendo del programa...")
                exit()
                
            case _:
                print("\nOpción inválida. Por favor, seleccione una opción válida.")
                
menu()