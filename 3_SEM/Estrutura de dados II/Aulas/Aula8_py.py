
# metodo construtor
class NodoArvore():
    def __init__(self, chave = None, esquerda = None, direita = None):
        self.chave = chave
        self.esquerda = esquerda
        self.direita = direita

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



raiz = NodoArvore(35)
valores = [20,41,11,27,40,56,21,74]

for key in valores:
    nodo = NodoArvore(key)
    inserir_ordenado(raiz,nodo)

