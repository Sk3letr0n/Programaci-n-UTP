'''
1. Para el siguiente grafico diseñe un algoritmo implementando herencia
múltiple:

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
# Hecho por: Steven Grisales López - 1034289634
import os

script_path = os.path.dirname(os.path.abspath(__file__)) # Ruta del archivo actual.

class PersonalUniversitario:
        def __init__(self, nombre, apellido, año_ingreso):
            self.nombre = nombre
            self.apellido = apellido
            self.año_ingreso = año_ingreso

        def calcular_antiguedad(self):
            return 2023 - self.año_ingreso

class Profesor(PersonalUniversitario):
        def __init__(self, nombre, apellido, año_ingreso, horas_trabajadas, tipo_profesor):
            super().__init__(nombre, apellido, año_ingreso)
            self.horas_trabajadas = horas_trabajadas
            self.tipo_profesor = tipo_profesor

        def calcular_sueldo(self):
            if self.tipo_profesor == "Tiempo Completo":
                sueldo = self.horas_trabajadas * 40  # Suponiendo 40 USD por hora
            else:
                sueldo = self.horas_trabajadas * 20  # Suponiendo 20 USD por hora
            return sueldo

        def listar_materias(self):
            if self.tipo_profesor == "Tiempo Completo":
                materias = ["Matemáticas", "Física", "Química"]
            else:
                materias = ["Inglés", "Historia", "Literatura"]
            return materias

class Alumno(PersonalUniversitario):
        def __init__(self, nombre, apellido, año_ingreso, carrera, promedio, creditos_aprobados, creditos_totales):
            super().__init__(nombre, apellido, año_ingreso)
            self.carrera = carrera
            self.promedio = promedio
            self.creditos_aprobados = creditos_aprobados
            self.creditos_totales = creditos_totales

class ProfesorAyudante(Profesor):
        def __init__(self, nombre, apellido, año_ingreso, horas_trabajadas, tipo_profesor, carrera, tareas_asignadas):
            super().__init__(nombre, apellido, año_ingreso, horas_trabajadas, tipo_profesor)
            self.carrera = carrera
            self.tareas_asignadas = tareas_asignadas

        def listar_materias(self):
            if self.tipo_profesor == "Medio Tiempo":
                materias = ["Psicología Básica", "Psicología Clínica", "Psicología Social"]
            else:
                materias = ["Psicología Experimental", "Psicología del Desarrollo", "Psicología Cognitiva"]
            return materias

# Crear objetos de las clases
profesor = Profesor("Ricardo", "Moreno", 2005, 160, "Tiempo Completo")
alumno = Alumno("Steven", "Grisales", 2022, "Ingeniería Informática", 4.0, 90, 120)
profesor_ayudante = ProfesorAyudante("Ana", "Martínez", 2018, 80, "Medio Tiempo", "Psicología", "Corrección de exámenes")

# Calcular antigüedad y sueldo
print(f"Antigüedad del profesor: {profesor.calcular_antiguedad()} años")
print(f"Sueldo del profesor: ${profesor.calcular_sueldo()}")

# Mostrar materias
print("Materias del profesor:")
for materia in profesor.listar_materias():
    print(materia)

# Calcular antigüedad del alumno
print(f"Antigüedad del alumno: {alumno.calcular_antiguedad()} años")

# Mostrar información del profesor ayudante
print(f"Tareas asignadas al profesor ayudante: {profesor_ayudante.tareas_asignadas}")


file_path = os.path.join(script_path, "informacion_universidad.txt")
# Guardar información en un archivo
with open(file_path, "w") as archivo:
    archivo.write(f"Nombre del profesor: {profesor.nombre}\n")
    archivo.write(f"Antigüedad del profesor: {profesor.calcular_antiguedad()} años\n")
    archivo.write(f"Sueldo del profesor: ${profesor.calcular_sueldo()}\n")
    archivo.write(f"Materias del profesor: {', '.join(profesor.listar_materias())}\n")
    archivo.write(f"Nombre del alumno: {alumno.nombre}\n")
    archivo.write(f"Antigüedad del alumno: {alumno.calcular_antiguedad()} años\n")
    archivo.write(f"Carrera del alumno: {alumno.carrera}\n")
    archivo.write(f"Promedio del alumno: {alumno.promedio}\n")
    archivo.write(f"Créditos aprobados por el alumno: {alumno.creditos_aprobados}\n")
    archivo.write(f"Créditos totales del alumno: {alumno.creditos_totales}\n")
    archivo.write(f"Nombre del profesor ayudante: {profesor_ayudante.nombre}\n")
    archivo.write(f"Tareas asignadas al profesor ayudante: {profesor_ayudante.tareas_asignadas}\n")