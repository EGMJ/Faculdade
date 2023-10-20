
# metodo construtor
class NodoArvore():
    def __init__(self, chave = None, esquerda = None, direita = None, altura = None):
        self.chave = chave
        self.esquerda = esquerda
        self.direita = direita
        self.altura = altura

    def __repr__(self):
        return '%s <- %s -> %s' % (self.esquerda and self.esquerda.chave, self.chave, self.direita and self.direita.chave)


def inserir_ordenado(raiz, no):
    # iniserir um no na raiz
    if raiz == None:
        raiz = no
    
    # o no deve ser inserido na subarvore direita
    elif raiz.chave < no.chave:
        if raiz.direita == None:
            raiz.direita = no
        else:
            inserir_ordenado(raiz.direita, no)

    # o no deve ser inserido na subarvore esquerda
    else:
        if raiz.esquerda == None:
            raiz.esquerda = no
        else:
            inserir_ordenado(raiz.esquerda, no) 

def em_ordem(raiz):
    if not raiz:
        return
    
    em_ordem(raiz.esquerda)

    print(raiz.chave,", ",end="")

    em_ordem(raiz.direita)

def em_ordemAltura(raiz):
    if not raiz:
        return
    
    em_ordemAltura(raiz.esquerda)
    print(raiz.altura,", ",end="")
    em_ordemAltura(raiz.direita)

def calc_altura(raiz):
    if not raiz:
        return
    calc_altura(raiz.esquerda)
    calc_altura(raiz.direita)

    # chegamos no nó folha
    if not raiz.esquerda and not raiz.direita:
        raiz.altura = 0

    if raiz.esquerda and not raiz.direita:
        raiz.altura = raiz.esquerda.altura + 1

    if not raiz.esquerda and raiz.direita:
        raiz.altura = raiz.direita.altura + 1

    if raiz.esquerda and raiz.direita:
        if raiz.esquerda.altura >= raiz.direita.altura:
            raiz.altura = raiz.esquerda.altura + 1
        else:
            raiz.altura = raiz.direita.altura + 1     


def calc_fator_balanciamento(raiz, fator = None):
    if not raiz:
        return
    calc_fator_balanciamento(raiz.esquerda, fator)
    calc_fator_balanciamento(raiz.direita, fator)
    
    # chegamos no nó folha
    if not raiz.esquerda. and not raiz.direita:
        fator = 0

    if raiz.esquerda and not raiz.direita:
        fator = raiz.esquerda.altura - (-1)

    if not raiz.esquerda and raiz.direita:
        fator = (-1) - raiz.direita.altura

    if raiz.esquerda and raiz.direita:
        fator = raiz.esquerda.altura - raiz.direita.altura

raiz = NodoArvore(35)
valores = [20,41,11,27,40,56,21,74]

for key in valores:
    nodo = NodoArvore(key)
    inserir_ordenado(raiz,nodo)

calc_altura(raiz)
print("\n")
em_ordemAltura(raiz)
print("\n")