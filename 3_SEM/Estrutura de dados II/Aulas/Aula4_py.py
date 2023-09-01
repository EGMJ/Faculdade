name = "Edson"

print(name)

name = 12.5
print(name)
name += 1
print(name)


def fatorial(n):
    if(n == 0):
        return 1
    return n*fatorial(n-1)


num = int(input("insira o numero"))
# print(f'O numero fatorial é: {fatorial(num)}')
# print(f'O numero fatorial '+str(num) + 'é: ',fatorial(num))


def fatorialNR(n):
    x = 1
    for i in range(2,n+1):
        x = x * i
    return x  

# print(f'O numero fatorial é: {fatorialNR(num)}')

def 