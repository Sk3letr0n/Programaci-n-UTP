'''
Diseñar una clase para crear un objeto empleado con al menos 5
atributos y los siguientes métodos:
    a. Calcular lo que se gana al mes teniendo en cuenta el
    número de horas que trabaja, el valor de cada hora.
    b. Calcular el tiempo de antigüedad y cuanto le falta para
    pensionarse teniendo en cuenta que las mujeres se
    pensionan antes que los hombres.
    c. Calcular cuánto paga por salud y pensión al mes el
    empleado teniendo en cuenta que es 4% de salud y 4% de
    pensión y al año cuanto abona en pensión.
    d. Se deben guardar todos los datos de los empleados en un
    archivo.
'''
# Hecho por Steven Grisales López - 1034289634
from io import *

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