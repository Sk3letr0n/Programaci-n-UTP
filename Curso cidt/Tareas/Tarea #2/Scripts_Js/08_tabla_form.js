// Hecho por Steven Grisales López
/****************************************************************************/
// RECONFIGURACIÓN DE LA CUADRÍCULA DE LA PÁGINA

// Se obtiene el grid del main
var grid_main = document.getElementById("grid_main");

// Se definen las áreas de la cuadrícula para cada tamaño de pantalla
var areasDesktop = '"S1 S1 S1 S1" "S1 S1 S1 S1"';
var areasTablet = '"S1 S1" "S1 S1"';
var areasSmartphone = '"S1 S1"';

// Se crean los @media screen queries
var media_screen_Tablet = window.matchMedia("(max-width: 900px) and (min-width: 551px)");
var media_screen_Smartphone = window.matchMedia("(max-width: 550px)");

// Se crea la función para actualizar las áreas de la cuadrícula
function actualizarGridAreas() {
  if (media_screen_Smartphone.matches) {
    // Si la pantalla es de tamaño smartphone
    grid_main.style.gridTemplateAreas = areasSmartphone;
  } else if (media_screen_Tablet.matches) {
    // Si la pantalla es de tamaño tablet
    grid_main.style.gridTemplateAreas = areasTablet;
  } else {
    // Si la pantalla es de tamaño desktop
    grid_main.style.gridTemplateAreas = areasDesktop;
  }
}

// Se actualizan las áreas de la cuadrícula cuando la página se carga
actualizarGridAreas();

// Se actualizan las áreas de la cuadrícula cuando el tamaño de la ventana cambia
window.addEventListener("resize", actualizarGridAreas);

// CREACIÓN, APERTURA Y CONFIGURACIÓN DE LA BD
var database = window.indexedDB.open("BD_Nutrition", 1);

database.onerror = function(event) {
  console.log("No se pudo abrir la base de datos", event);
};

database.onupgradeneeded = function(event) {
  var db = event.target.result;

  var objectStore = db.createObjectStore("daticos", { keyPath: "indice", autoIncrement : true });

  objectStore.createIndex("alimento", "alimento", { unique: true });
};

database.onsuccess = function(event) {
  console.log("Base de datos abierta exitosamente");

  var db = event.target.result;
  var trans = db.transaction("daticos", "readonly");
  var store = trans.objectStore("daticos");

  var solicitud = store.getAll();

  solicitud.onsuccess = function(event) { 
    var data = event.target.result;

    if(data.length != 0){
      var tabla = document.getElementById("tabla");
      var tbody = document.createElement("tbody");
      
      data.forEach((element) => {
        var tr = document.createElement("tr");

        var elementoIndice = tr.appendChild(crearCelda(element.indice));
        elementoIndice.style.display = "none";
        tr.appendChild(crearCelda(element.alimento));
        tr.appendChild(crearCelda(element.calorias));
        tr.appendChild(crearCelda(element.grasas));
        tr.appendChild(crearCelda(element.proteina));
        tr.appendChild(crearCelda(element.carbohidratos));

        var td = document.createElement("td");
        var span = document.createElement("span");
        var text = document.createTextNode("Editar");
        span.appendChild(text);
        span.className = "editar";
        span.setAttribute("onclick", "transformarEnEditable(this)");
        td.appendChild(span);
        tr.appendChild(td);
        tbody.appendChild(tr);
      });

      tabla.appendChild(tbody);
    } else {
      console.log("Lo lamentamos! Aún no existen registros en nuestra Base de Datos");
    }
  };

  solicitud.onerror = function(event){
    console.log("No se pudo obtener los datos", event);
  };
};

function crearCelda(textContent){
  var td = document.createElement("td");
  var span = document.createElement("span");
  var text = document.createTextNode(textContent);
  span.appendChild(text);
  td.appendChild(span);
  return td;
}

/****************************************************************************/
// EDICIÓN DE TABLAS

// Boton Editar
var editando = false;

function transformarEnEditable(nodo) { //El nodo recibido es SPAN
    
  if (editando == false) {
    var nodoTd = nodo.parentNode; //Nodo Td: Celda
    var nodoTr = nodoTd.parentNode; //Nodo Tr: Fila
    var nodosEnTr = nodoTr.getElementsByTagName('td');

    // Se guarda el contenido de cada celda de la fila seleccionada
    var indice = nodosEnTr[0].textContent;
    var alimento = nodosEnTr[1].textContent; 
    var calorias = nodosEnTr[2].textContent;
    var grasas = nodosEnTr[3].textContent;
    var proteina = nodosEnTr[4].textContent;
    var carbohidratos = nodosEnTr[5].textContent; 

    // Creación del input
     var nuevoCodigoHtml = '<td hidden><input type="text" id="indice" readonly value="' + indice +  '" </td>' +
    '<td><input type="text" id="alimento" value="' + alimento + '" size="10"></td>' +
    '<td><input type="text" id="calorias" value="' + calorias + '" size="5"></td>' +
    '<td><input type="text" id="grasas" value="' + grasas + '" size="5"></td>' +
    '<td><input type="text" id="proteina" value="' + proteina + '" size="5"></td>' +
    '<td><input type="text" id="carbohidratos" value="' + carbohidratos + '" size="5"></td>' + 
    '<td>En edición</td>'; 

    nodoTr.innerHTML = nuevoCodigoHtml;

    var nodoBotonesForm = document.getElementById('botonesform');

    if (indice != "" && indice != undefined) {
      nodoBotonesForm.innerHTML +=
        '<td>' +
          '<form id = "form_botones" method="get" onsubmit="UpdateData(' + indice +')" onreset="anular()">' +
          '<input class="boton" type = "submit" value="Actualizar">' +
          '<input class="boton" type="button" onclick="DeleteData(' + indice + ')" value="Eliminar">' +
          '<input class="boton" type="reset" value="Cancelar"> </form>' + "</td>";
    } else {
      nodoBotonesForm.innerHTML +=
        '<td>' +
        '<form id = "form_botones" method="get" onsubmit="CreateData()" onreset="anular()">' +
        '<input class="boton" type = "submit" value="Aceptar">' +
        '<input class="boton" type="reset" value="Cancelar"> </form>' +
        "</td>";
    }
        
    editando = "true";
  } else {
    alert ('Solo se puede editar una línea. Recargue la página para poder editar otra');
  }
}

function anular() {
  window.location.reload(); // Refresca la ventana
} 

// CRUD
var data;
var resultado = [];
var buscar_listar;

// Crear Datos
function CreateData() {
  var indice = document.getElementById("indice").value;
  var alimento = document.getElementById("alimento").value;
  var calorias = document.getElementById("calorias").value;
  var grasas = document.getElementById("grasas").value;
  var proteina = document.getElementById("proteina").value;
  var carbohidratos = document.getElementById("carbohidratos").value;

  if(indice != ""){ 
    var daticos = {
    "alimento": alimento,
    "calorias": calorias,
    "grasas": grasas,
    "proteina": proteina,
    "carbohidratos": carbohidratos,
    "indice": parseInt(indice)
  };

  var band = true;

  } else { 
    var daticos = {
      "alimento": alimento,
      "calorias": calorias,
      "grasas": grasas,
      "proteina": proteina,
      "carbohidratos": carbohidratos
    };
  }

  var db = database.result;
  var trans = db.transaction("daticos", "readwrite");
  var store = trans.objectStore("daticos");
  store.add(daticos);

  trans.oncomplete = function() {
    alert("Datos guardados exitosamente"); 
    window.location.reload();
  };

  trans.onerror = function(event) {
    if(band == true){
      alert(`Ese registro ya existe en la Base de Datos`);
      band = false;
    } else {
      console.log(`Error al guardar los datos: ${event}`);
    }
  };

  document.getElementById("indice").value = "";
  document.getElementById("alimento").value = "";
  document.getElementById("calorias").value = "";
  document.getElementById("grasas").value = "";
  document.getElementById("proteina").value = "";
  document.getElementById("carbohidratos").value = "";
}


// Actualizar Datos
function UpdateData(){
  var confirmacion = confirm("¿Estás seguro de modificar el registro?");
  if (confirmacion) {
    var indice = document.getElementById("indice").value;
    var alimento = document.getElementById("alimento").value;
    var calorias = document.getElementById("calorias").value;
    var grasas = document.getElementById("grasas").value;
    var proteina = document.getElementById("proteina").value;
    var carbohidratos = document.getElementById("carbohidratos").value;

    if(indice != ""){
      var daticos = {            
        "alimento": alimento,
        "calorias": calorias,
        "grasas": grasas,
        "proteina": proteina,
        "carbohidratos": carbohidratos,
        "indice": parseInt(indice)
      };

      var db = database.result;
      var trans = db.transaction("daticos", "readwrite");
      var store = trans.objectStore("daticos");

      store.put(daticos);

      trans.oncomplete = function() {
        alert("Datos actualizados exitosamente");
        window.location.reload();
      };

      trans.onerror = function(event) {
        console.log("Error al actualizar los datos:", event);
      };

      document.getElementById("indice").value = "";
      document.getElementById("alimento").value = "";
      document.getElementById("calorias").value = "";
      document.getElementById("grasas").value = "";
      document.getElementById("proteina").value = "";
      document.getElementById("carbohidratos").value = "";
    } else {
      alert('No hay Datos que editar');
    }
  } else{
  }
}

// Eliminar Datos
function DeleteData(indice){
  var confirmacion = confirm("¿Estás seguro de eliminar el registro?");

  if(confirmacion){

      var db = database.result
      var trans = db.transaction("daticos", "readwrite");
      var store = trans.objectStore("daticos");
      store.delete(parseInt(indice));

      trans.oncomplete = function() {
        alert("Registro eliminado correctamente");
        anular();
      }

      trans.onerror = function(event){
        console.log("Error al eliminar el registro:", event);
      }

    } else {
      alert("Debe buscar el registro antes de eliminarlo");
    }
  }
