# Resolutor de Sudoku desde muy fácil hasta muy difícil.
# Realizado por Grupo 7 conformado por: Luis Felipe Garzón Bonilla, Santiago Aristizabal Sepúlveda y Steven Grisales López.

import copy # Librería para copiar objetos.

class CSP:
    def __init__(self): 
        self.Vars = {} # Diccionario que contiene las variables del problema.
        self.Constraints={'Dif':[], 'SameDomain2': [], 'SameDomain3': [], 'NotRepeated': []} # Diccionario que contiene las restricciones del problema.
        self.checkReductions = False # Variable que nos indica si se realizó alguna eliminación en el dominio de las variables.
        
    # Dominios de las variables.
    def Vars_Doms(self): 
        rows = set(range(1, 10)) # Filas.
        cols = ['A','B','C','D','E','F','G','H','I'] # Columnas.
        for c in cols:
            for r in rows:
                self.Vars[f"{c}{r}"] = rows.copy() #
                
    # Se asigna el valor a la variable.
    def setValueInVars(self,Name,Value): 
        self.Vars[Name] = {Value}  
        
    # Se inicializa el tablero.
    def initBoard(self,nameFile):
        file = open(nameFile, "r")
        ListSudoku = "ABCDEFGHI" #
        for r in range(1, 10): # Se recorre el tablero.
            for c in ListSudoku:
                cur = int(file.readline()) # Se lee el valor del archivo.
                if(cur < 10): # Si el valor es menor a 10, se asigna a la variable.
                    self.setValueInVars(f"{c}{r}",cur) 
                    
    # Restricciones de las filas.                
    def rowConstraints(self, consKey):
        colsIndex = "ABCDEFGHI"
        for i in range(1, 10):
            l = [] # Lista que contiene las variables de la fila.
            for j in colsIndex:
                l.append(str(j) + str(i)) # Se agrega la variable a la lista.
            self.Constraints[consKey].append(l) # Se agrega la lista a la restricción.
                
    # Restricciones de las columnas.
    def colConstraints(self, consKey):
        colsIndex = "ABCDEFGHI"
        for i in colsIndex:
            l = [] # Lista que contiene las variables de la columna.
            for j in range(1, 10): 
                l.append(str(i) + str(j)) # Se agrega la variable a la lista.
            self.Constraints[consKey].append(l) # Se agrega la lista a la restricción.
            
    # Restricciones de las ventanas.
    def windowConstraints(self, consKey, startRange, endRange):
        triplets = ["ABC", "DEF", "GHI"] # Se definen las tripletas. 
        for t in triplets: 
            l = [] # Lista que contiene las variables de la ventana.
            for c in t:  
                for i in range(startRange, endRange): # Se recorre la ventana.
                    l.append(str(c) + str(i)) # Se agrega la variable a la lista.
            self.Constraints[consKey].append(l) # Se agrega la lista a la restricción.
        
    # Se agregan las restricciones al diccionario de restricciones.           
    def constraintStructures(self, consKey):
        self.Constraints[consKey] = [] # Se inicializa la restricción.
        self.rowConstraints(consKey)
        self.colConstraints(consKey)
        # Se definen los rangos de las ventanas.
        startRange = [1, 4, 7] 
        endRange = [4, 7, 10] 
        for index in range(3): 
            self.windowConstraints(consKey, int(startRange[index]), int(endRange[index])) 
            
    # Restricciones de diferencias.    
    def dif(self, list_, index):
        for var in list_:
            if (self.numElement(var) == 1): # Si el dominio de la variable es 1, se elimina el elemento de las demás variables.
                element = self.Vars[var] 
                self.deleteElementInVar(var, list_, element.copy())
                self.deleteVarInConstraint('Dif', var, index) # Se elimina la variable de la restricción.
    
    # Restricciones de dominios iguales de 2.
    def SameDomain2(self):    
        for constraint in self.Constraints['SameDomain2']: 
            for var_1 in constraint:
                if(self.numElement(var_1) == 2): # Si el dominio de la variable es 2, se verifica si hay dominios iguales.
                    for var_2 in constraint:
                        if var_1 == var_2: # Si la variable es la misma, se pasa.
                            pass
                        else:
                            if(self.Vars[var_1] == self.Vars[var_2]): # Si los dominios son iguales, se eliminan los elementos de las demás variables.
                                lista_valores = list(self.Vars[var_1]) # Se obtienen los valores del dominio.
                                val_1 = lista_valores[0] # Se obtiene el primer valor.
                                val_2 = lista_valores[1] # Se obtiene el segundo valor.
                                
                                for valForDelete in constraint: 
                                    if((valForDelete == var_1) or (valForDelete == var_2)): # Si la variable a eliminar es la misma, se pasa.
                                        pass
                                    else:
                                        lenBefore = len(self.Vars[valForDelete]) # Se obtiene el tamaño del dominio antes de eliminar los elementos.
                                        # Se eliminan los elementos del dominio.
                                        self.Vars[valForDelete].discard(val_1)
                                        self.Vars[valForDelete].discard(val_2)  
                                        lenAfter = len(self.Vars[valForDelete]) # Se obtiene el tamaño del dominio después de eliminar los elementos.
                                        if(lenBefore > lenAfter): # Si el tamaño del dominio disminuyó, se actualiza la variable checkReductions.                                       
                                            self.checkReductions = True

    # Restricciones de dominios iguales de 3.
    def SameDomain3(self):
        for constraint  in self.Constraints['SameDomain3']:
            for var_1 in constraint:
                if(self.numElement(var_1) == 3): # Si  el dominio de la variable es 3, se verifica si hay dominios iguales.
                    for var_2 in constraint:
                        if var_1 == var_2: # Si la variable es la misma, se pasa
                            pass
                        else:
                            if(self.Vars[var_1] == self.Vars[var_2]): # Si los dominios son iguales, se eliminan los elementos de las demás variables.
                                for var_3 in constraint:
                                    if(var_3 == var_1 or var_3 == var_2): 
                                        pass
                                    else:
                                        if(self.Vars[var_3] == self.Vars[var_1]): 
                                            lista = list(self.Vars[var_1]) # Se obtienen los valores del dominio.
                                            val_1 = lista[0]
                                            val_2 = lista[1]
                                            val_3 = lista[2]
                                         
                                            for valForDelete in constraint: # Se eliminan los elementos del dominio.
                                                if(valForDelete == var_1 or valForDelete == var_2 or valForDelete == var_3):
                                                    pass # Si la variable a eliminar es la misma, se pasa.
                                                else:
                                                    lenBefore = len(self.Vars[valForDelete]) # Se obtiene el tamaño del dominio antes de eliminar los elementos.
                                                    self.Vars[valForDelete].discard(val_1) 
                                                    self.Vars[valForDelete].discard(val_2)
                                                    self.Vars[valForDelete].discard(val_3)
                                                    lenAfter = len(self.Vars[valForDelete])
                                                    if(lenBefore > lenAfter): # Si el tamaño del dominio disminuyó, se actualiza la variable checkReductions.         
                                                            self.checkReductions = True # Se actualiza la variable checkReductions.
    
    # Restricciones de no repetidos.
    def NotRepeated(self): 
        for constraint in self.Constraints['NotRepeated']: # Se recorren las restricciones.
            all_values = set() 
            for var in constraint:
                all_values.update(self.Vars[var]) # Se obtienen los valores de los dominios de las variables.
            for value in all_values:
                count = 0
                for var in constraint: # Se verifica si el valor se encuentra en los dominios de las variables.
                    if value in self.Vars[var]: # Si el valor se encuentra en el dominio de la variable, se aumenta el contador.
                        count += 1  
                        var_unic = var # Se guarda la variable en la que se encuentra el valor.
                if ((count == 1) and not (self.numElement(var_unic) == 1)):   
                    self.Vars[var_unic] = {value} # Si el valor se encuentra en un solo dominio, se actualiza el dominio de la variable.
                    self.checkReductions = True
                    
    # Se elimina el elemento del dominio de la variable.
    def deleteElementInVar(self, var, list_, element):
        integer_element = int(element.pop()) # Se obtiene el elemento del dominio.
        for c in list_:
            if (c == var): # Si la variable es la misma, se pasa
                pass
            else:
                self.Vars[c].discard(integer_element) # Se elimina el elemento del dominio.
                self.checkReductions = True # Se actualiza la variable checkReductions.

    # Se elimina la variable de la restricción.      
    def deleteVarInConstraint(self, constKey, var, i):
        lista = self.Constraints[constKey][i] # Se obtiene la restricción.
        lista.remove(var) # Se elimina la variable de la restricción.   
    
    # Se obtiene el número de elementos del dominio de la variable.
    def numElement(self, clave):
        return len(self.Vars[clave]) # Se retorna el número de elementos del dominio de la variable.
    
    # Se recorren las restricciones.
    def loopThroughConstraint(self): # Se recorren las restricciones.
        self.checkReductions = False # Se inicializa la variable checkReductions.
        for index in range(len(self.Constraints['Dif'])): # Se recorren las restricciones de diferencia.
            self.dif(self.Constraints['Dif'][index], index) 
            # Se verifica si el sudoku es consistente.
        self.SameDomain2() 
        self.SameDomain3()
        self.NotRepeated()
        return self.checkReductions
    
    # Se verifica si el sudoku está resuelto.
    def is_solved(self):
        colsIndex = "ABCDEFGHI" # Columnas.
        for c in colsIndex: # Se recorren las columnas.
            for i in range(1, 10):
                if not(len(self.Vars[str(c) + str(i)]) == 1): # Se verifica si el dominio de la variable es 1.
                    return False
        return True

    # Se verifica si el sudoku es consistente.
    def localConsistent(self): # Se verifica si el sudoku es consistente.
        colsIndex = "ABCDEFGHI"
        for c in colsIndex: # Se recorren las columnas.
            for i in range(1,10):
                if (len(self.Vars[str(c) + str(i)]) == 0): # Se verifica si el dominio de la variable es 0.
                    return False
        return True
        
    # Se copia el objeto.
    def copy(self):
        return copy.deepcopy(self) 
    
    # Se realiza el backtracking.
    def backTracking(self, sudoku):
        colsIndex = "ABCDEFGHI" # Columnas.
        break_outer_loop = False # Variable que nos indica si se realizó alguna eliminación en el dominio de las variables.
        for c in colsIndex:
            for i in range(1,10):
                if (len(self.Vars[str(c) + str(i)]) == 2): # Se verifica si el dominio de la variable es 2.  
                    lista = list(self.Vars[str(c) + str(i)]) # Se obtienen los valores del dominio.
                    element = lista[0] # Se obtiene el primer valor.
                    self.Vars[str(c) + str(i)].discard(element) # Se elimina el primer valor del dominio.
                    break_outer_loop = True
                    break
            if break_outer_loop: # Se verifica si se realizó alguna eliminación en el dominio de las variables. 
                break
            
        if(break_outer_loop): # Se verifica si se realizó alguna eliminación en el dominio de las variables.
            while(self.loopThroughConstraint()): # Se recorren las restricciones.
                pass
            if (self.localConsistent() == False): # Se verifica si el sudoku es consistente.
                sudoku.Vars[str(c) + str(i)] = {element} # Se actualiza la variable.
                return False
            else: 
                return True
                
sudoku = CSP()
sudoku.Vars_Doms()
sudoku.initBoard("Tablero3.txt") # Se inicializa el tablero.
# Se agregan las restricciones.
sudoku.constraintStructures('Dif') 
sudoku.constraintStructures('SameDomain2') 
sudoku.constraintStructures('SameDomain3')
sudoku.constraintStructures('NotRepeated')

# Se resuelve el sudoku.
while(sudoku.is_solved() == False):
    # Se recorren las restricciones.
    while(sudoku.loopThroughConstraint()):
        pass
    # Se verifica si el sudoku está resuelto.
    if sudoku.is_solved() == False:
        test = sudoku.copy() # Se copia el objeto.
        if(test.backTracking(sudoku) == False): # Se realiza el backtracking en la copia.
            pass
        else:
            sudoku = test # Se actualiza el sudoku.

print("SUDOKU RESUELTO")
print("______________________")
print(sudoku.Vars)        