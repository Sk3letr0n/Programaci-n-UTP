// Para ejecutar los ejercicios colocar el nombre de su respectiva función ;)

// Punto 1
let mult = 1;
let contador = 0;

do {
    let nume = parseInt(prompt("Ingrese un número: "));

    if(isNaN(nume)){
        console.log("No es un número válido.");
        continue;
    }

    mult *= nume;
    contador += 1;

} while(contador < 2);

console.log("El resultado de la multiplicación es: " + mult);

// Punto 2
let num1

do {
    num1 = parseInt(prompt("Ingrese un númerito: "));

    if(isNaN(num1)){
        console.log("No es un númerito válido.");
        continue;
    }

    break
        
} while(true);

let esPar = num1 % 2 === 0;
console.log(esPar ? 'Es par' : 'Es impar');

// Punto 3
function par_o_impar() {
    let num;
    do{
        num = parseInt(prompt("Ingrese un númerito: "));

        if(isNaN(num)){
            console.log("No es un númerito válido.");
            continue;
        }

        break
        
    } while(true);

    return num % 2 == 0 ? 'Es par' : 'Es impar';
}

// Punto 4
function multiimpar() {
    let num2;
    let mult = 1;
    let lista = [];

    do{
        num2 = parseInt(prompt("Ingrese un númerote: "));

        if(isNaN(num2)){
            console.log("No es un númerote válido.");
            continue;
        }

        if(num != -1){

            lista.push(num2);

            if(lista.length % 2 != 0){
                mult *= num2;
            }
            continue;
        }

    } while(num2 != -1);

    if(lista.length != 0){
        lista.push(mult)
    }
    
    return lista;
    
}