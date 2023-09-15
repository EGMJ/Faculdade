"""
# escreva um programa que imprime de 1 a 500 com multiplos de 5

def imprimeMult(i):
    if i <= 500:
        print(f"{i}")
        i += 5
        imprimeMult(i)
        print(f"{i}")

imprimeMult(10)

def soma100(i,soma):
    if(i <= 100):
        soma = soma + i
        i = i + 1
        soma = soma100(i,soma)
    return soma

print(f"\n O valos da soma dos 100 números: {soma100(1,0)}")

def calcPares(num,soma):
    if num <= 200:
        if num % 2 == 1:
            num = num + 1
        # soma= soma + num
        # num = num + 2
        soma = calcPares(num+2,soma+num)
    return soma


print(f"\n O valos da soma dos 100 números: {calcPares(25,0)}")

# Faça um programa que calcule a multiplicação de dois numeros através de somas sucessivas.

def multi(num, x, soma):
    if x > 0:
        # soma = num + soma
        soma = multi(num,x-1,soma+num)
    return soma

print(f"\n A Multiplicação dos números: {multi(4, 10, 0)}")

# escreva um programa que possui entrada 10 numeros e imprimer a metade de cada um deles

def metade10(i):
    if i < 10:
        num = float(input("Digite o numero: "))
        print(f"\n A Divisão dos números: {float(num/2)}")
        metade10(i + 1)
metade10(0)

# crie um programa que o usuario diga qual a tabuada deseja imprimir
def tabuada(i,num):
    if i <= 10:
        print(f"{i} X {num} = {i * num}")
        tabuada(i + 1,num)

num = int(input("Qual é a tabuada que vc quer? "))
tabuada(0,num)

# escreva um programa que some todos os numeros de 1 a 500 qua sao multiplos de 5 ou 3
def somaMult(i, soma):
    if i <= 500:
        if i % 3 == 0 or i % 5 == 0:
            soma = somaMult(i+1, soma + i)
        else:
            soma = somaMult(i+1, soma)
    return soma

print(f"\n A soma dos multiplos de 5 e 3 é: {somaMult(1,0)}")
"""
# escreva um programa que dado um numero ele diz se é primo ou nao

def verificaPrimo(num, i, primo):
    if i < num and primo:
        if num % i == 0:
            return False
        primo = verificaPrimo(num, i+1, primo)
    return primo
num = int(input("Insira o numero: ")) 
print(f"O numero {num} é primo? {verificaPrimo(num, 2, True)}")        

