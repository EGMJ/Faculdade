import time



name = "Edson"

print(name)

name = 12.5
print(name)
name += 1
print(name)

num = int(input("insira o numero"))

def fatorial(n):
    if(n == 0):
        return 1
    return n*fatorial(n-1)

# print(f'O numero fatorial é: {fatorial(num)}')
# print(f'O numero fatorial '+str(num) + 'é: ',fatorial(num))



def fatorialNR(n):
    x = 1
    for i in range(2,n+1):
        x = x * i
    return x  

# print(f'O numero fatorial é: {fatorialNR(num)}')

def fibonnaci(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    if n > 1:
        return fibonnaci(n-1) + fibonnaci(n-2)

def fibonnaciNR(n):
    if n == 0:
        return 0
    if n == 1: 
        return 1
    F1 = 0
    F2 = 1

    for i in range(2,n+1):
        F = F1 + F2
        F1 = F2
        F2 = F
    return F

inicioR = time.time()
print("Fibonnaci recursivo")
fimR = time.time()
inicioNR = time.time()
print(f'O numero de fibonnaci é: {fibonnaci(num)}')
fimNR = time.time()

print("Fibonnaci não recursivo")
print(f'O numero de fibonnaci é: {fibonnaciNR(num)}')

print("\n\n O tempo da Fibonnaci recursivo é de: ",(fimNR-inicioNR),"segundos")
print("\n\n O tempo da Fibonnaci recursivo é de: ",(fimR-inicioR),"segundos")