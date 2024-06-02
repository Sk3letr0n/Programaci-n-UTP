'''
Diseñe un programa que reciba un numero entero de 4 cifras, diga si el
primer número es múltiplo del cuarto número y debe mostrar la suma del
segundo número y el tercero (no requiere implementar el paradigma
orientado a objetos), este punto se debe hacer usando operaciones
aritméticas para descomponer el numero de 4 cifras.
'''
# Hecho por: Steven Grisales López (1034289634) y Luis Felipe Garzón Bonilla (1089931169)

numero = int(input("Ingrese un número de 4 cifras: "))

# Verificar si el número ingresado es de 4 cifras
if numero < 1000 or numero > 9999:
    print("El número ingresado no es de 4 cifras, intente nuevamente")

else:
    # Descomponer el número
    primer_numero = numero % 10 
    segundo_numero = (numero // 10) % 10
    tercer_numero = (numero // 100) % 10
    cuarto_numero = (numero // 1000) % 10 

    print(f"El primer número es: {primer_numero}")
    print(f"El segundo número es: {segundo_numero}")
    print(f"El tercer número es: {tercer_numero}")
    print(f"El cuarto número es: {cuarto_numero}")

    # Verificar si el primer número es múltiplo del cuarto número
    if primer_numero != 0 and primer_numero % cuarto_numero == 0:
        print(f"El primer número es múltiplo del cuarto número")
    else:
        print(f"El primer número no es múltiplo del cuarto número")

    print(f"La suma de el segundo y tercer numero es: {segundo_numero + tercer_numero}")