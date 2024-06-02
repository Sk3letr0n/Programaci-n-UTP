'''
a. Para cada clase debe diseñar al menos 6 atributos.
b. Para las clases profesor debe realizar un método en donde se pueda
calcular el sueldo mensual dependiendo de las horas que trabaja y del
tipo de profesor que sea
c. Debe de crear un método para calcular la antigüedad de todas las
entidades en el diseño.
d. Dependiendo de cada tipo de profesor debe diseñar al menos tres
materias acordes con el rango de cada uno y se deben visualizar en
pantalla por medio de un método.
e. Guarde la información que crea necesaria en un archivo para este
programa.
'''

from datetime import datetime #Se importa la librería datetime para trabajar con fechas

def Menu():
    while True:
        print("1. Crear un usuario.")
        print("2. Mostrar personal.")
        print("3. Calcular el sueldo mensual de un docente.")
        print("4. Calcular antiguedad de un usuario.")
        print("5. Consultar las materias que dicta un docente")
        print("6. Salir.")
        opcion = int(input("Ingrese una opción: "))
        
        match opcion:
            case 1:
                print("1. Crear un profesor.")
                print("2. Crear un alumno.")
                print("3. Crear un profesor ayudante.")
                print("4. Regresar al menú.")
                opcion = int(input("Ingrese una opción: "))
                match opcion:
                    case 1:
                        personal=Profesor("","",0, "", "", "") 
                        personal.CrearUsuario("Profesor")
                    case 2:
                        personal=Alumno("","",0, "", "", "")
                        personal.CrearUsuario("Alumno")
                    case 3:
                        personal=ProfesorAyudante("","",0, "", "", "")
                        personal.CrearUsuario("Profesor Ayudante")
                        print("Volviendo al menú...")
                        pause = input("Presione enter para continuar")
                        Menu()
                    case 4:
                        print("Volviendo al menú...")
                        pause = input("Presione enter para continuar")
                        Menu()    
                    case _:
                        print("Opción no válida, regresando al menú...")
                        pause = input("Presione enter para continuar")
                        Menu()
            case 2:
                Personal=PersonalUniversitario("","",0, "", "", "")
                Personal.Mostrar()
                print("Volviendo al menú...")
                pause = input("Presione enter para continuar")
            case 3:
                personal=Profesor("","",0, "", "", "")
                personal.SueldoMensual()
                print("Volviendo al menú...")
                pause = input("Presione enter para continuar")
                Menu()

            case 4:
                print("Ingrese la fecha en la que se unió a la institución: ")
                año=int(input("Ingrese el año: "))
                mes=int(input("Ingrese el mes: "))
                dia=int(input("Ingrese el día: "))
                fecha_ingresada = datetime(año, mes, dia).date()
                
                personal=PersonalUniversitario("","",0, "", "", "")
                personal.Antiguedad(fecha_ingresada)
                Menu()

            case 5:
                personal=Profesor("","",0, "", "", "")
                personal.Materias()
                print("Volviendo al menú...")
                pause = input("Presione enter para continuar")
                Menu()
            case 6:
                print("Gracias por usar el programa.")
                exit()
            case _:
                print("Opción no válida.")
                print("Volviendo al menú...")
                pause = input("Presione enter para continuar")
                Menu()

    

class PersonalUniversitario():
    def __init__(self, cargo, nombre, edad, documento, telefono, correo):
            self.cargo= cargo
            self.nombre= nombre
            self.edad= edad
            self.documento= documento
            self.telefono= telefono
            self.correo= correo
    
    def CrearUsuario(self, cargo):
        nombre=input("Ingrese el nombre: ")
        edad=int(input("Ingrese la edad: "))
        documento=input("Ingrese el documento: ")
        telefono=input("Ingrese el telefono: ")
        correo=input("Ingrese el correo: ")
        personal=PersonalUniversitario(cargo, nombre, edad, documento, telefono, correo)

        if cargo=="Profesor" or cargo=="profesor":
            personal=Profesor(cargo, nombre, edad, documento, telefono, correo)
        elif cargo=="Alumno" or cargo=="alumno":
            personal=Alumno(cargo, nombre, edad, documento, telefono, correo)
        elif cargo=="Profesor Ayudante" or cargo=="profesor ayudante":
            personal=ProfesorAyudante(cargo, nombre, edad, documento, telefono, correo)
        

        with open("PersonalU.txt", "a") as archivo: #Se guarda la información del vehículo en un archivo
            archivo.write(f"Cargo: {personal.cargo}, Nombre {personal.nombre}, Edad: {personal.edad}, Documento: {personal.documento}, Telefono: {personal.telefono}, Correo: {personal.correo}" + "\n")

    def Antiguedad(self, fecha):
        fecha_actual = datetime.now().date() #Se obtiene la fecha actual del sistema
        diferencia = fecha_actual - fecha #Se calcula la diferencia entre la fecha actual y la fecha de ingreso
        print(f"El tiempo de antiguedad es de : {diferencia.days} días.")
    
    
    def Mostrar(self):
        print("Personal registrado: ")
        with open("PersonalU.txt", "r") as archivo: #Se guarda la información del vehículo en un archivo
            print(archivo.read())


class Profesor(PersonalUniversitario):
    def __init__(self, cargo, nombre, edad, documento, telefono, correo):
         super().__init__(cargo, nombre, edad, documento, telefono, correo)

    def SueldoMensual(self):
        Horas=int(input("Ingrese el numero de horas que trabaja al día: "))
        Cargo=input("Ingrese el tipo de profesor que es: ")

        if Cargo =="Catedratico" or Cargo=="catedratico":
            print(f"Su sueldo mensual es de: {(Horas*10000)*30}") #Se calcula el sueldo mensual multiplicando las horas trabajadas por el valor de la hora y por los días del mes
        elif Cargo == "Planta" or Cargo=="planta":
             print(f"Su sueldo mensual es de: {(Horas*15000)*30}")
        elif Cargo=="Suplente" or Cargo=="suplente":
             print(f"Su sueldo mensual es de: {(Horas*20000)*30}")
    
    def Materias(self):
        Cargo=input("Ingrese el tipo de profesor que es: ")

        if  Cargo =="Transitivo" or Cargo=="transitivo":
            print("Las materias que dicta este profesor son: Teoría de Sistemas, Programación 2, Desarrollo del Pensamiento Lógico")
        elif Cargo == "Planta" or Cargo=="planta":
            print("Las materias que dicta este profesor son: Inteligencia Artificial, Desarrollo de Software, Comunicaciones")
        elif Cargo=="Catedratico" or Cargo=="catedratico":
             print("Las materias que dicta este profesor son: Introducción a la Informatica, Logica, Programación")
         
    

class Alumno(PersonalUniversitario):
    def __init__(self, cargo, nombre, edad, documento, telefono, correo):
         super().__init__(cargo, nombre, edad, documento, telefono, correo) #Se llama al constructor de la clase padre

class ProfesorAyudante(Profesor,Alumno):
    def __init__(self, cargo, nombre, edad, documento, telefono, correo):
        Profesor.__init__(self, cargo, nombre, edad, documento, telefono, correo) #Se llama al constructor de la clase padre
        Alumno.__init__(self, cargo, nombre, edad, documento, telefono, correo)
    
Menu()


