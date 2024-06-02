class PersonalUniversitario():
    def __init__(self, Nombre, Apellido, Codigo, AñodeInicio, Materias, Telefono):
        self.Nombre = Nombre
        self.Apellido = Apellido
        self.Codigo = Codigo
        self.AñodeInicio = AñodeInicio
        self.Materias = Materias
        self.Telefono = Telefono

    def CrearPersonal(self):
        self.Nombre = input("Ingrese el Nombre: ")
        self.Apellido = input("Ingrese el Apellido: ")
        self.Codigo = input("Ingrese el Codigo: ")
        self.AñodeInicio = int(input("Ingrese el año de inicio: "))
        self.Materias = input("Ingrese las materias : ")
        self.Telefono = input("Ingrese el Telefono: ")

    def Antiguedad(self):
        Antiguedad = 2024 - self.AñodeInicio
        return(Antiguedad)

class Profesor(PersonalUniversitario):
    def __init__(self, Nombre, Apellido, Codigo, AñodeInicio, Materias, Telefono, Valor, Horas):
        super().__init__(Nombre, Apellido, Codigo, AñodeInicio, Materias, Telefono)
        self.Valor = Valor
        self.Horas = Horas

    def SueldoMensualProfesor(self):
        sueldo = self.Valor * self.Horas
        return(sueldo)

    def Dictar(self):
        return(self.Materias)     
            
    def CrearProfesor(self):
        super().CrearPersonal()
        self.Valor = int(input("Ingrese el pago por hora del profesor: "))
        self.Horas = int(input("Ingrese las horas mensuales que trabaja: "))
        
        with open("Ejercicio 1 - Datos_Personal.txt", "a") as file:
            file.write(f'''---Datos del Usuario:  --- 
                Ocupación: Profesor
                Nombre: {self.Nombre}
                Apellido: {self.Apellido}
                Codigo: {self.Codigo}
                Año de inicio: {self.AñodeInicio}
                Materias: {self.Materias}
                Telefono: {self.Telefono}
                Valor: {self.Valor}
                Horas: {self.Horas}\n''')         

class Alumno(PersonalUniversitario):
    def __init__(self, Nombre, Apellido, Codigo, AñodeInicio, Materias, Telefono, Facultad, NumeroMaterias):
        super().__init__(Nombre, Apellido, Codigo, AñodeInicio, Materias, Telefono)
        self.Facultad = Facultad
        self.NumeroMaterias = NumeroMaterias
        
    def CrearAlumno(self):
        Guardar = True
        if self.NumeroMaterias == -1:
            Guardar = False
        super().CrearPersonal()
        self.Facultad = input("Ingrese la facultad del estudiante: ")
        self.NumeroMaterias = int(input("Ingrese el numero de materias que ve el estudiante: "))

        if Guardar:
            with open("Ejercicio 1 - Datos_Personal.txt", "a") as file:
                file.write(f'''---Datos del Usuario:  --- 
                    Ocupación: Alumno
                    Nombre: {self.Nombre}
                    Apellido: {self.Apellido}
                    Codigo: {self.Codigo}
                    Año de inicio: {self.AñodeInicio}
                    Materias: {self.Materias}
                    Telefono: {self.Telefono}
                    Facultad: {self.Facultad}
                    Numero de materias: {self.NumeroMaterias}\n''')      

class ProfesorAyudante(Profesor, Alumno):
    def __init__(self, Nombre, Apellido, Codigo, AñodeInicio, Materias, Telefono, Valor, Horas, Facultad, NumeroMaterias):
        Alumno.__init__(self, Nombre, Apellido, Codigo, AñodeInicio, Materias, Telefono, Facultad, NumeroMaterias)       
        self.Valor = Valor
        self.Horas = Horas

        #self.Facultad = Facultad
        #self.NumeroMaterias = NumeroMaterias
        
    def CrearProfesorAyudante(self):
        Alumno.CrearAlumno(self)
        self.Valor = int(input("Ingrese el valor de las horas: "))
        self.Horas = int(input("Ingrese el numero de horas: "))

        with open("Ejercicio 1 - Datos_Personal.txt", "a") as file:
            file.write(f'''---Datos del Usuario:  --- 
                Ocupación: Ayudante
                Nombre: {self.Nombre}
                Apellido: {self.Apellido}
                Codigo: {self.Codigo}
                Año de inicio: {self.AñodeInicio}
                Materias: {self.Materias}
                Telefono: {self.Telefono}
                Valor: {self.Valor}
                Facultad: {self.Facultad}
                Horas: {self.Horas}
                Numero de materias: {self.NumeroMaterias}\n''')
             
EjemploProfesor1 = Profesor("", "", "", 0, "", "", 0, 0) 
EjemploProfesor1.CrearProfesor()
print(f"La antiguedad del profesor es de: {EjemploProfesor1.Antiguedad()} años")
print(f"Las materias que dicta el profesor son: {EjemploProfesor1.Dictar()}")
print(f"El sueldo del profesor es de: {EjemploProfesor1.SueldoMensualProfesor()}$")

EjemploAyudante = ProfesorAyudante("", "", "", 0, "", "", 0, 0, "", -1)
EjemploAyudante.CrearProfesorAyudante()

EjemploAlumno = Alumno("", "", "", 0, "", "", "", 0)
EjemploAlumno.CrearAlumno()