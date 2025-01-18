# Hangman Game (Jogo da Forca) 
# Programação Orientada a Objetos

# Import
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
        

# Board (tabuleiro)
board = ['''

>>>>>>>>>>Hangman<<<<<<<<<<

+---+
|   |
    |
    |
    |
    |
=========''', '''

+---+
|   |
O   |
    |
    |
    |
=========''', '''

+---+
|   |
O   |
|   |
    |
    |
=========''', '''

 +---+
 |   |
 O   |
/|   |
     |
     |
=========''', '''

 +---+
 |   |
 O   |
/|\  |
     |
     |
=========''', '''

 +---+
 |   |
 O   |
/|\  |
/    |
     |
=========''', '''

 +---+
 |   |
 O   |
/|\  |
/ \  |
     |
=========''']




# Classe
class Hangman:

	# Método Construtor
    def __init__(self, palavra):
        self.palavra = palavra
        self.letras_erradas = []
        self.letras_escolhidas = []

        
	# Método para adivinhar a letra
    def guess(self, letra):
        
        if letra in self.palavra and letra not in self.letras_escolhidas:
            self.letras_escolhidas.append(letra)
        
        elif letra not in self.palavra and letra not in self.letras_erradas:
            self.letras_erradas.append(letra)
        
        else: 
            return False
        
        return True
    
    
	# Método para verificar se o jogo terminou
    def hangman_over(self):
        return self.hangman_won() or (len(self.letras_erradas) == 6)

	# Método para verificar se o jogador venceu
    def hangman_won(self):
        
        if '_' not in self.hide_palavra():
            return True
        return False
        

	# Método para não mostrar a letra no board
    def hide_palavra(self):
        rtn = ''
        for letra in self.palavra:
            if letra not in self.letras_escolhidas:
                rtn += '_'
            else:
                rtn += letra
        return rtn    

	# Método para checar o status do game e imprimir o board na tela
    def print_game_status(self):
        
        # Desenha a forca
        print (board[len(self.letras_erradas)])
        
        
        print ('\nPalavra: ' + self.hide_palavra())
        
        print ('\nLetras Erradas: ',)
        
        for letra in self.letras_erradas:
            print (letra,)
         
        print()
        
        print('Letras Corretas : ',)
        
        for letra in self. letras_escolhidas:
            print (letra,)
            
        print()
        
    
# Método para selecionar uma palavra randomicamente em um banco de palavras
def rand_palavra():
    # Lista de palavras para o jogo
    palavras = ['banana', 'abacate', 'uva', 'morango', 'laranja']
    
    # Escolhe randomicamente uma palavra
    palavra = random.choice(palavras)
    
    return palavra
    
    
    
    
#Método Main - Execução do Programa
def main():
        
          
    # Cria um objeto e escolhe uma palavra randomicamente
    game = Hangman(rand_palavra())
        
    # Enquanto o jogo não tiver terminado, print do status, solicita uma letra e faz a leitura do caracter
    while not game.hangman_over():
    
        limpa_tela()
        
        # Status do game
        game.print_game_status()
        
        # Recebe uma letra do terminal
        user_input = input('\nDigite uma letra : ')
        
        # Verifica se a letra digitada faz parte da palavra secreta
        game.guess(user_input)
        
    limpa_tela()
    # Printa o esttus do jogo depois do loop
    game.print_game_status()
    
    # De acordo com o resultado do jogo, imprime a mensagem na tela para o usuario
    if game.hangman_won():
        print('\nParabéns !!! Você Venceu !!!')
    else:
        print('\nQue Pena !!! Você perdeu !!!')
        print('\nA Palavra era ' + game.palavra)
        
# Executa o programa
if __name__ == "__main__":
    main()
