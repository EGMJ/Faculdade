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
"""

def calcPares(num,soma):
    if num <= 200:
        if num % 2 == 1:
            num = num + 1
        # soma= soma + num
        # num = num + 2
        soma = calcPares(num+2,soma+num)
    return soma


print(f"\n O valos da soma dos 100 números: {calcPares(25,0)}")
