#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2) {
        printf("Usage: ./substituion key\n");
        return 1;
    }
    string valor = argv[1];
    for (int i = 0, n = strlen(valor); i < n; i++) {
        if (! isalpha(valor[i])) {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    for (int i = 0, n = strlen(valor); i < n; i++) {
        if (valor[i] == valor[i+1]) {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    if (strlen(argv[1]) != 26) {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string text = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++) {
        if (isupper(text[i])) {
            int cripto = (text[i]) - 'A';
            printf("%c", toupper(valor[cripto]));
        }
        if (islower(text[i])) {
            int cripto = (text[i]) - 'a';
            printf("%c", tolower(valor[cripto]));
        }
        if (! isalpha(text[i])) {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}