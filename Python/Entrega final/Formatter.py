import re


def codigodeprueba():
    print("hola, estoy probando git")

def separadorEspacios():
    '''
    separadorEspacios

    -----------

    Almacena en una variable llamada separador un espacio en blanco " " 
    que se multiplica segun la cantidad de espacio entre caracteres dado
     
    '''
    separador = " " * cantEspacios
    return separador

def separadorSaltosLineas():
    '''
    separadorSaltosLineas
    ---------
    Almacena en una variable llamada separador un salto de linea, se multiplica por 
    la cantidad de saltos de linea que se requiera 
    
    '''
    separador = "\n" * cantSaltosLineas
    return separador

def separadorTabs(espacio):
    '''
    separadorTabs
    ---------
    espacio: int 
    ---------
    Almacena en una variable llamada separador un tab, se multiplica por
    la cantidad de tabs que se requiera y por espacio, que indicara cuantos 
    tabs debe existir para que la sintaxis sea correcta
    '''
    separador = "\t" * (cantTab*espacio)
    return separador

def procesarDatos(archivo):
    '''
    procesarDatos
    --------
    archivo: archivo de texto
    --------
    Ordena todas las secuencias de letras y caracteres especiales en una lista, primero se 
    toman todos los strings individuales y se almacenan en datos, luego en datosLimpios se 
    ordenan los strings separando los simbolos especiales mediante una expresion regular. Si el string 
    no posee algun simbolo especial se agrega a datosLimpios, caso opuesto se divide en nueva_lista para 
    ser agregados a datosLimpios. 
    La funcion devuelve la lista de datosLimpios
    '''
    datos = []
    for linea in archivo:
        datos.extend(caracterBlanco.findall(linea))

    datosLimpios = []  
    for cadena in datos:
        if re.search(caracterEspecial , cadena):      #ve si la cadena de la lista tiene algun simbolo especial
            nueva_lista = []
            temp = ""
            for i in cadena:             
                if re.match(letra_Palabra, i):  # Verifica si el elemento es una letra
                    temp += i 
                else:
                    if temp:  # Si hay un carácter almacenado en la variable temporal
                        nueva_lista.append(temp)  # Agrega el carácter unido a la nueva lista
                        temp = "" 
                    nueva_lista.append(i)  
            if temp:
                nueva_lista.append(temp)
            for elemento in nueva_lista:
                datosLimpios.append(elemento)
        else :                              #la cadena no tiene ningun simbolo especial
            datosLimpios.append(cadena)
    datosLimpios.append('')
    return datosLimpios


def listaOperaciones(listaTemp,numero):
        '''
        listaOperaciones
        -------
        listaTemp: lista de strings
        numero: int
        -------
        agrega a una nueva lista algunos elementos de la lista completa de strings(listaTemp) que luego se usa
        para comprobar con oper_bin() si estan bien escritas. Si num es igual a 1, indica que se quiere revisar 
        la condicion de un "if" o un "while" , si num es 2 se revisara los elementos de una igualdad.
        Luego de realizar oper_bin(), si retorna True devuelve la lista completa haciendo un slide de los elementos
        que se consultaron, si retorna False indica que ocurrio un error y devolvera una lista vacia
        '''
        nueva_lista = []
        contador = 0
        simbolo = ""
        if numero == 1:
            simbolo = simbolos[5]
        elif numero == 2:
            simbolo = simbolos[1]

        for i, elemento in enumerate(listaTemp):
            if elemento == simbolo:
                if i == len(listaTemp) - 2:
                    break
                break
            contador += 1
            
        nueva_lista = listaTemp[:contador + 1]
        booleano = oper_bin(nueva_lista,numero)
        if booleano == False:
            lista_vacia = [""]
            return lista_vacia
        del(nueva_lista)
        return listaTemp[contador + 1:]
    


def oper_bin(listaTemp, num):
    '''
    oper_bin
    -------
    listaTemp: lista de string
    num : int
    -------

    Verifica si la operacion binaria esta correcta y la escribe en el archivo formateado.txt.
    se recorre la listaTemp que contiene una secuencia de un condicional u operacion binaria,
    dependiendo si el parametro num es igual a 1 o 2 respectivamente.
    La funcion returna True si la operacion esta bien escrita, caso contario retorna False

    '''
    flag = True
    while len(listaTemp) > 0:
        if re.search(enteroRe , listaTemp[0]):   #entero
            entero = re.search(enteroRe, listaTemp[0])
            formateado.write(entero.group() + separadorEspacios())   
            listaTemp.pop(0)

        elif re.search(boolRe, listaTemp[0]):        #bool
            booleano = re.search(boolRe, listaTemp[0])
            formateado.write(booleano.group() + separadorEspacios())
            listaTemp.pop(0)
        
        elif re.search(simbolos[0], listaTemp[0]) and re.search(simbolos[0],listaTemp[2]):   #string 
            palabra = re.search(stringRe , listaTemp[1])
            formateado.write("#"+ palabra.group() + "#" + separadorEspacios())
            listaTemp = listaTemp[3:]

        elif re.search(variableRe,listaTemp[0]):          #variable
            variable = re.search(variableRe, listaTemp[0])
            formateado.write(variable.group()+ separadorEspacios())
            listaTemp.pop(0)

        elif num == 1 and re.search(operando, listaTemp[0]):
            simbolo = re.search(operandoIfWhile , listaTemp[0])
            if listaTemp[1] == "=":
                formateado.write("==" + separadorEspacios())
                listaTemp = listaTemp[2:]
            else:
                if simbolo == None:
                    listaTemp.clear()
                    flag = False
                    break
                formateado.write(simbolo.group() + separadorEspacios())
                listaTemp.pop(0)

        elif num == 2 and re.search(operando, listaTemp[0]):
            simbolo = re.search(operando, listaTemp[0])
            if listaTemp[1] == "=":
                formateado.write("==" + separadorEspacios())
                listaTemp = listaTemp[2:]
            else: 
                if simbolo == None: 
                    listaTemp.clear()
                    flag = False
                    break 
                formateado.write(simbolo.group() + separadorEspacios())
                listaTemp.pop(0)

        elif re.search(simbolos[1], listaTemp[0]):
            signo = re.search(simbolos[1], listaTemp[0])
            listaTemp.pop(0)
            if len(listaTemp) > 0 and listaTemp[0] == simbolos[3]:
                pila.pop(0)
                formateado.write(signo.group() + separadorSaltosLineas())
                listaTemp.clear()
            else:
                formateado.write(signo.group() + separadorSaltosLineas() )
                listaTemp.clear()
            break
        
        elif listaTemp[0] == simbolos[5]:
            formateado.write(")" + separadorEspacios())
            listaTemp.pop(0)

        else:
            listaTemp.clear()
            break
    
    return flag

#######################################################

simbolos = ["#" ,";",  "{" ,"}" , "(" , ")" , "()"]

caracterEspecial = re.compile(r"\W+")
caracterBlanco = re.compile(r"\S+")
digito = re.compile(r"\d")
letra_Palabra = re.compile(r"^[a-zA-Z0-9]+$")
enteroRe = re.compile(r"[1-9]+[0-9]*")
boolRe = re.compile(r"true|false")
stringRe = re.compile(r"^[A-Za-z0-9]+$")
variableRe = re.compile(r"[a-zA-Z]+[a-zA-Z0-9]*")
operando = re.compile(r"[+\-/*<==]")
operandoIfWhile = re.compile(r"[<|==]")

puntoComa = re.compile(r";")
hashtag = re.compile(r"#")
abreLlave = re.compile(r"{")
cierraLlave = re.compile(r"}")

returnRe = re.compile(r'return')
declaracion = re.compile(r"int|str|bool")
ifRe = re.compile(r"if")
elseRe = re.compile(r"else")
whileRe = re.compile(r"while")

######################################################

config = open("config.txt", "r")
linea  = config.readline()

numeros = re.findall(r'\d+', linea)

cantEspacios = int(numeros[0])
cantSaltosLineas = int(numeros[1])
cantTab = int(numeros[2])

codigo = open("codigo.txt" , "r")
formateado = open("formateado.txt" , "w")

lista = procesarDatos(codigo)
pila = []
k = 0


while len(lista) > 0:
    if lista[0] == 'int' and lista[1] == 'main' and lista[2] == '(' and lista[3] == ')' and lista[4] == '{' :
        temporal = '' 
        for elemento in lista[0:5]:
            temporal += elemento + separadorEspacios()
        formateado.write(separadorTabs(k) + temporal + separadorSaltosLineas() )
        k+=1
        lista = lista[5:]
    
    elif re.search(returnRe,lista[0]) and len(pila) == 0:
        formateado.write(separadorTabs(k) + 'return' + separadorEspacios())
        match = re.search(r"0",lista[1])
        if match:
            formateado.write( match.group() + separadorEspacios())
            if len(lista)  > 2 and lista[2] == ";":
                formateado.write(";" + separadorSaltosLineas())
                lista = lista[3:]
                if len(lista) > 0 and lista[0] == "}":
                    formateado.write("}")
                    lista.pop(0)
                else:
                    lista.clear()
            else:
                lista.clear()
        else:
            lista.clear()


    elif re.search(declaracion,lista[0]):
        match = re.search(declaracion,lista[0])
        formateado.write(separadorTabs(k) + match.group()+ separadorEspacios())
        variable = re.search(variableRe,lista[1])
        if variable:
            formateado.write(variable.group()+ separadorEspacios())
        else:
            lista.clear()
            break

        if lista[2] == ";" and lista[3] == "}":  
            formateado.write(";" + separadorSaltosLineas()) 
        elif lista[2] == ";":
            formateado.write(";" + separadorSaltosLineas() ) 
        else:
            lista.clear()
        lista = lista[3:]

    elif re.search(ifRe, lista[0]):
        pila.append("if")
        match = re.search(ifRe,lista[0])
        formateado.write(separadorTabs(k) + match.group() + separadorEspacios())
        if lista[1] == "(":   ##separa la lista
            formateado.write("(" + separadorEspacios())
            lista = lista[2:]
            lista = listaOperaciones(lista, 1)
            if lista[0] == "{" : 
                k+=1
                formateado.write("{" + separadorSaltosLineas())
                lista.pop(0)
            else:
                lista.clear()
                break
        else:
            lista.clear()
        
    elif re.search(elseRe , lista[0]) :
        pila.append("else")
        match = re.search(elseRe , lista[0])
        formateado.write(match.group() + separadorEspacios())
        if lista[1] == "{":
            k+=1
            formateado.write("{" + separadorSaltosLineas()  )
            lista = lista[2:]
        else:
            lista.clear()

    elif re.search(whileRe, lista[0]): 
        pila.append("while")
        match = re.search(whileRe,lista[0])
        formateado.write(separadorTabs(k) + match.group() + separadorEspacios())
        if lista[1] == "(":   ##separa la lista
            formateado.write("(" + separadorEspacios())
            lista = lista[2:]
            lista = listaOperaciones(lista, 1)
            if lista[0] == "{" : 
                k+=1
                formateado.write("{" + separadorSaltosLineas() )
                lista.pop(0)
            else:
                lista.clear()
        else:
            lista.clear()

    elif re.search(variableRe, lista[0]):
        variable = re.search(variableRe , lista[0])
        formateado.write(separadorTabs(k) + variable.group()+ separadorEspacios())
        if lista[1] == "=":   ##separa la lista
            formateado.write("=" + separadorEspacios())
            lista = lista[2:]
            lista = listaOperaciones(lista,2)
        
    elif re.search(r"}" , lista[0]):
        signo = re.search(r"}" , lista[0])
        if re.search(elseRe , lista[1]):
            k-=1
            formateado.write(separadorTabs((k)) + signo.group() + separadorEspacios())
        else:
            k-=1
            formateado.write(separadorTabs((k)) + signo.group() + separadorSaltosLineas())
        lista.pop(0)
        pila.pop(0)
        
    elif re.search(r"{" , lista[0]):
        signo = re.search(r"{" , lista[0])
        k+=1
        formateado.write((separadorTabs(k))+ signo.group() + separadorSaltosLineas() )
        lista.pop(0)

    else:
        lista.clear()

     
config.close()
codigo.close()
formateado.close()


