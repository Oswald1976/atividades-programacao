from cs50 import get_int
# solicita a altura da piramide (tem que ser de 1 a 8)
altura = get_int ("Altura (1 a 8) ?")
if altura < 1 or altura > 8:
    print("Numero Invalido")
if altura > 1 and altura < 8:
    for i in range(altura - (altura - 1)):
        print(" ", end="")
    for j in range(altura):
        print("#", end="")