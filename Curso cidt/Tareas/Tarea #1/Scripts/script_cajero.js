// Punto 5 - Cajero
// Para ejecutar el cajero para que no se ejecute nada más iniciar la página escribir en consola cajero(); ;) o si no borrar de una vez el comentario al final.

let saldo = 1000;

function cajero(){

    console.log("Ingresando al cajero...");
    console.log("-- Menú del cajero --\n1. Depositar.\n2. Retirar.\n3. Consultar.\n4. Salir del Cajero.");

    op = parseInt(prompt("Ingrese una opción: "));
    switch(op){
        case 1:
            Depositar();
            break;
         case 2:
            Retirar();
            break;
        case 3:
            Consultar();
            break;
        case 4:
            Salir();
            break;
        default:
            console.log('Opción no válida');
            cajero();
    }
}

function Depositar() {
    let valor = parseInt(prompt("Ingrese el valor a depositar: "));
    if (!isNaN(valor) && valor > 0) {
        saldo += valor;
    } else {
        console.log("El valor ingresado no es válido.");
        Depositar();
    }
    Preguntar();
}

function Retirar() {
    let valor = parseInt(prompt("Ingrese el valor a retirar: "));
    if (!isNaN(valor) && valor > 0) {
        if (valor <= saldo) {
            saldo -= valor;
        } else {
            console.log("No es posible hacer el retiro por fondos insuficientes.");
            Retirar();
        }
    } else {
        console.log("El valor ingresado no es válido.");
        Retirar();
    }
    Preguntar();
}



function Consultar(){
    console.log("Su saldo actual es: " + saldo);
    Preguntar();
}

function Preguntar() {
    let opcion = parseInt(prompt("¿Desea realizar otra operación? (0 = No, 1 = Sí)"));
    if (opcion == 1) {
        cajero();
    } else if (opcion == 0) {
        Salir();
    }
}

function Salir(){
    console.log("Saliendo de la aplicación...");
}

// cajero();