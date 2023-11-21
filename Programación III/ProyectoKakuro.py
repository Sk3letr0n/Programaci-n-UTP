# Resolutor de Kakuro.
# Realizado por Grupo 7 conformado por: Luis Felipe Garzón Bonilla, Santiago Aristizabal Sepúlveda y Steven Grisales López.

import copy
class CSP:
    def __init__(self):
        self.Vars = {}
        self.equivalencies = {}
        self.Constraints = {'Dif' : [], 'OnlySum' : [], 'BaseValues2Vars' : [],  'OnlyValor' : []}
        self.checkReductions = False
        self.combina = []
        
    def assignEquivalencies(self):
         self.equivalencies = { 
                                '3' : [['B5', 'B6'], ['B8', 'B9'], ['E8', 'E9'], ['G6', 'G7'], ['E2', 'F2'], ['C4', 'D4'], ['E9', 'F9']],
                                '4' : [['E5', 'E6'], ['F2', 'F3'], ['I5', 'I6'], ['H5', 'I5'], ['C7', 'D7'], ['G7', 'H7'], ['B9', 'C9']],
                                '5' : [['F8', 'F9']],
                                '6' : [['B6', 'C6']],
                                '8' : [['F5', 'F6']],
                                '10': [['D4', 'D5'], ['E2', 'E3'], ['G3', 'G4']],
                                '11': [['D7', 'D8'], ['G4', 'H4']],
                                '12': [['H2', 'I2']],
                                '13': [['I2', 'I3']],
                                '15': [['E6', 'F6', 'G6', 'H6', 'I6']],
                                '19': [['B5', 'C5', 'D5', 'E5', 'F5']],
                                '22': [['C4', 'C5', 'C6', 'C7', 'C8', 'C9'], ['H2', 'H3', 'H4', 'H5', 'H6', 'H7'], ['B8', 'C8', 'D8', 'E8', 'F8']],
                                '25': [['E3', 'F3', 'G3', 'H3', 'I3']]}
                
    def createDif(self):
        for key in self.equivalencies:
            for constraint in self.equivalencies[key]:
                    self.Constraints['Dif'].append(constraint)
                    
    def createOnlySumThatSatisface(self):
        self.Constraints['OnlySum'] = self.equivalencies.copy()
        self.Constraints['OnlyValor'] = self.equivalencies.copy()
        
    def createBaseValues2Vars(self):
        self.equivalencies = dict(sorted(self.equivalencies.items(), key=lambda x: int(x[0]), reverse=True))
        self.Constraints['BaseValues2Vars'] = self.equivalencies.copy()
                
    def constraintStructures(self):
        self.createDif() 
        self.createOnlySumThatSatisface()  
        self.createBaseValues2Vars() 
                    
    def assignDomainsInVars(self):
        cols = "ABCDEFGHI"
        for c in cols:
            for index in range(1, 10):
                break_outer_loop = False
                for constraint in self.Constraints['Dif']:
                    for var in constraint:
                        if(str(c)+str(index) == var):
                            self.Vars[str(c)+str(index)] = set(range(1,10))
                            break_outer_loop = True
                            break
                    if break_outer_loop:
                        break
                    
    def baseValues2Variables(self):
        for key in self.Constraints['BaseValues2Vars']:
            equi = int(key)
            for i in range(len(self.Constraints['BaseValues2Vars'][key])):
                var = self.Constraints['BaseValues2Vars'][key][i][0]
                domainVar = set()
                
                if(len(self.Constraints['BaseValues2Vars'][key][i]) == 2 and (not len(self.Vars[var]) == 1)):
                    var2 = self.Constraints['BaseValues2Vars'][key][i][1]
                    for num1 in self.Vars[var]:
                        for num2 in self.Vars[var2]:
                            if(num1 == num2):
                                pass
                            else:
                                if((num1 + num2) == equi):
                                    domainVar.add(num1)
                                    domainVar.add(num2)
                                    
                    self.Vars[var] = domainVar
                    self.Vars[var2] = domainVar
  
    def OnlySumThatSatisface(self):
        for key in self.Constraints['OnlySum']:
            equi = int(key)
            for i in range(len(self.Constraints['OnlySum'][key])):
                if(len(self.Constraints['OnlySum'][key][i]) == 2):
                    var1 = self.Constraints['OnlySum'][key][i][0]
                    var2 = self.Constraints['OnlySum'][key][i][1]
                    
                    if not (self.numElement(var1) == 1 and self.numElement(var2) == 1):
                        domain1 = self.Vars[var1]
                        domain2 = self.Vars[var2]
                        if not (domain1 == domain2):
                            notValid = False
                            cont = 0
                            for value1 in domain1:
                                for value2 in domain2:
                                    if (value1+value2 == equi):
                                        cont = cont+1
                                        value1_ = value1
                                        value2_ = value2
                                        
                                        if(cont == 2):
                                            notValid = True
                                
                            if notValid == True or cont == 0:
                                pass
                            else:
                                lenBefore1 = len(self.Vars[var1])
                                lenBefore2 = len(self.Vars[var2])
                                self.Vars[var1] = {value1_}
                                self.Vars[var2] = {value2_}
                                lenAfter1 = len(self.Vars[var1])
                                lenAfter2 = len(self.Vars[var2])
                                if(lenBefore1 > lenAfter1 or (lenBefore2 > lenAfter2)) : 
                                    self.checkReductions = True
            
    def onlyValor(self):
        for key in self.Constraints['OnlyValor']:
            for constraint in self.Constraints['OnlyValor'][key]:
                cont = 0
                sum = 0
                for var in constraint:
                    if(self.numElement(var) == 1):
                        onlyElement =list(self.Vars[var])
                        onlyElement = onlyElement[0]
                        sum = onlyElement+sum
                    else:
                        var1 = var
                        cont = cont+1
                if(cont == 1):
                    key = int(key)
                    value = key-sum
                    lenBefore = len(self.Vars[var1])
                    self.Vars[var1] = {value}
                    lenAfter = len(self.Vars[var1])
                    if(lenBefore > lenAfter): 
                        self.checkReductions = True
             
    def dif(self, list_):
        for var in list_:
            if (self.numElement(var) == 1):
                element = self.Vars[var]  
                self.deleteElementInVar(var, list_, element.copy())
        
    def numElement(self, clave):
        return len(self.Vars[clave])
    
    def deleteElementInVar(self, var, list_, element):
        integer_element = int(element.pop())
        for c in list_:
            if (c == var):
                pass
            else:
                lenBefore = len(self.Vars[c])
                copia=self.Vars[c].copy()
                copia.discard(integer_element) 
                self.Vars[c]= copia
                lenAfter = len(self.Vars[c])
                if(lenBefore > lenAfter):                                      
                    self.checkReductions = True
                    
    
    def loopThroughConstraint(self):
        self.checkReductions = False
        for index in range(len(self.Constraints['Dif'])):
            self.dif(self.Constraints['Dif'][index])
        self.OnlySumThatSatisface()
        self.onlyValor()
        return self.checkReductions
    
    def copy(self):
        return copy.deepcopy(self)
    
    def busqueda(self, myKakuro):
        sirve = True
        for key in self.Constraints['OnlyValor']:
            for constraint in self.Constraints['OnlyValor'][key]:
                key = int(key)
                cont = 0
                sum = 0
                for var in constraint:
                    if not(len(self.Vars[var]) == 1):
                        cont = cont+1
                        if cont == 1:
                            var1 = var
                        if cont == 2:
                            var2= var
                        if cont == 3:
                            var3= var
                        
                    else:
                        list0 = list(self.Vars[var])
                        sum = sum+list0[0]
                if(cont == 3):
                    list1 = list(self.Vars[var1])
                    list2 = list(self.Vars[var2])
                    list3 = list(self.Vars[var3])
                    key = key-sum
                    
                    for num1 in list1:
                        for num2 in list2:
                            for num3 in list3:
                                        
                                if(num1+num2+num3 == key):
                                    l=[num1,num2,num3]
                                   
                                    for combinacion in myKakuro.combina:
                                        if(l == combinacion):
                                            sirve = False
                                            
                                    if(sirve == True):
                                        self.Vars[var1] = {num1}
                                        self.Vars[var2] = {num2}
                                        self.Vars[var3] = {num3}
                                
                                        self.loopThroughConstraint()
                                        
                                        if (self.verificardif() == False):
                                            myKakuro.combina.append(l)
                                            self = myKakuro.copy()
                                        else:
                                            return(self)

    def localConsistent(self):
        for var in self.Vars:
                if (len(self.Vars[var]) == 0):
                    return False
        return True
    
    def is_solved(self):
        for var in self.Vars:
                if not(len(self.Vars[var]) == 1):
                    return False
        return True
                                         
    def verificardif(self):
        for contraint in self.Constraints['Dif']:
            for var1 in contraint:
                for var2 in contraint:
                    if(var1 == var2):
                        pass
                    else:
                        if(self.Vars[var1] == self.Vars[var2]):
                            return False            
        return True            
                
myKakuro = CSP()
myKakuro.assignEquivalencies()
myKakuro.constraintStructures()
myKakuro.assignDomainsInVars()
myKakuro.baseValues2Variables()

while(myKakuro.is_solved() == False):
  
    while(myKakuro.loopThroughConstraint()):
        pass
    myKakuro.baseValues2Variables()
    while(myKakuro.loopThroughConstraint()):
        pass
  
    if(myKakuro.is_solved() == False):
        test = myKakuro.copy()
        myKakuro = test.busqueda(myKakuro)
        
print(myKakuro.Vars)








    
#print(myKakuro.Constraints)


