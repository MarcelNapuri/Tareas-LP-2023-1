import re
'''
int main() {
str var; int var2;

if(#pepe# == true){
    str loquesea;
}
else{ loquesea = #punto# + #com#; }

bool var3; while(1 < 2) {
var2 = 12312 + #asdasd#; var3 = 1 - 2;if (sdasd == 3) { while( 4 < 5){bool frue ; }}else{int var1;}
}return 0;}

'''
texto = "Hola    mundo!     Cómo estás?"
palabras = re.split(r"\s+", texto)
print(palabras)

simbolos = ["#" ,";",  "{" ,"}" , "(" , ")" , "()"]

caracterEspecial = re.compile(r"\W+")
caracterBlanco = re.compile(r"\s+")
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

'''
lista1 = ['int', 'main', '(', ')', '{', 'str', 'var', ';', 'int', 'var2', ';', 'if', '(', '#', 'pepe', '#', '=', '=', 'true', ')', '{', 'str', 'loquesea', ';', 'while', '(', '1', '<', '2', ')', '{', 'int', 'estoEsDePrueba', ';', '}', '}', 'else', '{', 'loquesea', '=', '#', 'punto', '#', '+', '#', 'com', '#', ';', '}', 'bool', 'var3', ';', 'while', '(', '1', '<', '2', ')', '{', 'var2', '=', '12312', '+', '#', 'asdasd', '#', ';', 'var3', '=', '1', '-', '2', ';', 'if', '(', 'sdasd', '=', '=', '3', ')', '{', 'while', '(', '4', '<', '5', ')', '{', 'bool', 'frue', ';', '}', '}', 'else', '{', 'int', 'var1', ';', '}', '}', 'return', '0', ';', '}', '']
lista2 = ['int', 'main', '(', ')', '{', 'str', 'var', ';', 'int', 'var2', ';', 'if', '(', '#', 'pepe', '#', '=', '=', 'true', ')', '{', 'str', 'loquesea', ';', 'while', '(', '1', '<', '2', ')', '{', 'int', 'estoEsDePrueba', ';', '}', '}', 'else', '{', 'loquesea', '=', '#', 'punto', '#', '+', '#', 'com', '#', ';', '}', 'bool', 'var3', ';', 'while', '(', '1', '<', '2', ')', '{', 'var2', '=', '12312', '+', '#', 'asdasd', '#', ';', 'var3', '=', '1', '-', '2', ';', 'if', '(', 'sdasd', '=', '=', '3', ')', '{', 'while', '(', '4', '<', '5', ')', '{', 'bool', 'frue', ';', '}', '}', 'else', '{', 'int', 'var1', ';', '}', '}', 'return', '0', ';', '}', '']

if lista1 == lista2:
    print("Las listas son iguales")
else:
    print("Las listas son diferentes")
    '''