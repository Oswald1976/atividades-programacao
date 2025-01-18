# Projeto 1 - Desenvolvimento do jogo da forca - Versão 1

import random
from os import system, name

#função para limpar a tela a cada execução
def limpa_tela():
    
    # Windows
    if name == 'nt':
        _ = system('cls')
     
     # Linux ou Mac
    else:
        _ = system('clear')
        
def game():

    limpa_tela()
    print("\nBem-Vindos ao jogo da forca!")
    print("Adivinhe a palavra abaixo:\n")
    
    # Lista de palavras para o jogo
    palavras = ['banana', 'abacate', 'uva', 'morango', 'laranja']
    
    # Escolhe randomicamente uma palavra
    palavra = random.choice(palavras)
    
    # tracos = len(palavra)
    # List comprehension
    letras_descobertas = ['_' for letra in palavra]
    
    # Lista para as letras erradas
    letras_erradas = []
    
    
    # Número de chances
    chances = 6
    
    while chances > 0:
    
        print(" ".join(letras_descobertas))
        print("\nChances restantes :", chances)
        print("letras erradas:"," ".join(letras_erradas))
    
        # tentativa
        tentativa = input("\nDigite uma letra: ").lower()
    
        # Condicional
        if tentativa in palavra:
            index = 0
            for letra in palavra:
                if tentativa == letra:
                    letras_descobertas[index] = letra
                index += 1
        else:
            chances -= 1
            letras_erradas.append(tentativa)
        
        # Condicional quando o jogador ganha
        if "_" not in letras_descobertas:
            print("\n VocÊ venceu, a palava era:", palavra)
            break
            
    # Condicional quando o jogador perde
    if "_" in letras_descobertas:
        print("\nVocê perdeu, a palavra era:", palavra)
        
# Bloco main
if __name__=="__main__":
    game()
    print("\nParabéns. Você fez seu primeiro programa em Python com a DSA. \n")

    
    