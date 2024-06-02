'''
1. Crear un programa para una Clínica Nutricional que contenga:
Una clase principal llamada Persona con los siguientes atributos: nombre,
edad, RUT, sexo (H hombre, M mujer), peso y altura. No se quiere acceder
directamente a ellos. Piense qué modificador de acceso (encapsulamiento)
es el más adecuado, también su tipo. Además, crear las siguientes clases
derivadas:
La clase Paciente tendrá como atributos fechaPrimeraConsulta,
medicoTratante (de tipo Médico); otra clase llamada Medico que herede de
Persona y tenga como atributo adicional precioConsulta y especialidad.
Cada una de las clases debe tener su respectivo constructor.
Los métodos que se implementarán en la clase Paciente son:
calcularIMC(): calculará si la persona está en su peso ideal (peso en kg/
(altura^2 en m)),
devuelve un -1 si está por debajo de su peso ideal, un 0 si está en su peso
ideal y un 1 si tiene sobrepeso.
esMayorDeEdad (): indica si es mayor de edad, devuelve un booleano.
comprobarSexo(sexo): comprueba que el sexo introducido es correcto. Si
no es correcto, será H.
Por último, vamos a crear un objeto donde pidamos información por teclado
y luego podamos saber si el paciente está en su peso ideal, tiene sobre
peso o está por debajo de su peso.
'''
# Hecho por: Steven Grisales López y Luis Felipe Garzón Bonilla.
import os
from Medico import Medico
from Paciente import Paciente

os.system("cls")

# Solicitare informacion del medico por teclado.
print("Bienvenido doctor/doctora por favor digite los siguientes datos.")
medico = Medico("", 0, "", "", 0.0, 0.0, 0, "")
medico.set_nombre()
medico.set_edad()
medico.set_rut()
medico.set_sexo()
medico.set_peso()
medico.set_altura()
medico.set_especialidad()
medico.set_precio_consulta()


# Solicitar información del paciente por teclado.
print("\nBienvenido señor/señora por favor digite los siguientes datos.")
paciente = Paciente("", 0, "", "", 0.0, 0.0, "", medico)
paciente.set_nombre()
paciente.set_edad()
paciente.set_rut()
paciente.set_sexo()
paciente.set_peso()
paciente.set_altura()
paciente.set_fecha_primera_consulta()


# Calcular y mostrar el estado del paciente.
estado = paciente.calcularIMC()
if estado == -1:
    print("\n- El paciente está por debajo de su peso ideal.")
elif estado == 0:
    print("\n- El paciente está en su peso ideal.")
else:
    print("\n- El paciente tiene sobrepeso.")

# Mostrar si el paciente es mayor de edad.
mayorEdad = paciente.esMayorDeEdad()
if paciente.get_edad == False:
    print("\n- El paciente registrado es menor de edad.")
else:
    print("\n- El paciente registrado es mayor de edad.")

print("\n- Sexo registrado del paciente es:", paciente.comprobarSexo(paciente.get_sexo()))


# Guardar en un archivo.
with open('Punto 1\datos_clinica.txt', 'a') as file:
    file.write(f"\nPaciente: {paciente.get_nombre()}\n")
    file.write(f"Edad: {paciente.get_edad()}\n")
    file.write(f"RUT: {paciente.get_rut()}\n")
    file.write(f"Sexo: {paciente.comprobarSexo(paciente.get_sexo())}\n")
    file.write(f"Peso: {paciente.get_peso()}\n")
    file.write(f"Altura: {paciente.get_altura()}\n")
    file.write(f"Fecha Primera Consulta: {paciente.get_fecha_primera_consulta()}\n")
    file.write(f"Medico Tratante: {paciente.get_medico_tratante().get_nombre()}\n")
    file.write(f"Especialidad Medico: {paciente.get_medico_tratante().get_especialidad()}\n")
    file.write(f"Precio Consulta: {paciente.get_medico_tratante().get_precio_consulta()}\n")

print("\nDatos guardados exitosamente, saliendo del programa...")