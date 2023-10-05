# Representação de arvore

# Arvore simples - grau 2

# Representando um nó

# metodo construtor
class NodoArvore():
    def __init__(self, chave = None, esquerda = None, direita = None):
        self.chave = chave
        self.esquerda = esquerda
        self.direita = direita

    def __repr__(self):
        return '%s <- %s -> %s' % (self.esquerda and self.esquerda.chave, self.chave, self.direita and self.direita.chave)

def em_ordem(raiz):
    if not raiz:
        return
    
    em_ordem(raiz.esquerda)

    print(raiz.chave,", ",end="")

    em_ordem(raiz.direita)

raiz = NodoArvore(3)

raiz.esquerda = NodoArvore(1)
raiz.direita = NodoArvore(8)

raiz.direita.direita = NodoArvore(10)
raiz.direita.esquerda = NodoArvore(6)

raiz.esquerda.esquerda = NodoArvore(-3)
raiz.esquerda.direita = NodoArvore(2)


# print(raiz)
# print(raiz.esquerda)
# print(raiz.direita)


em_ordem(raiz)