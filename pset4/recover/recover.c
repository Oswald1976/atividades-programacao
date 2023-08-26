#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
 if (argc < 2) // Check for invalid usage
    {
        printf("O que vai ser recuperado ?!?!?!?!\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if(file == NULL)
    {
        printf("Não foi possivel abrir %s !!!\n", argv[1]);
        return 1;
    }

 // Ler os primeiros 3 bytes
    BYTE bytes[3];
    fread(bytes, sizeof(BYTE), 3, file);
    // Verificar os três primeiros bytes
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
    {
        int adest = 000;
        

        FILE *destination = fopen(argv[2], "w");
        if (destination == NULL)
        {
            fclose(source);
            printf("Não foi possível criar %s.\n", argv[2]);
            return 1;
        }
        else
        {
            // Copiar um byte de cada vez do arquivo origem(source) para o arquivo destino(destination)
            BYTE buffer;
            while(fread(&buffer, sizeof(BYTE), 1, file))
            {
                fwrite(&buffer, sizeof(BYTE), 1, destination);
            }

     // Fechar os arquivos
     fclose(source);
     fclose(destination);
     return 0;
        }
    }
    else
    {
       printf("Não\n");
    }
    // Fechar o arquivo
    fclose(file);


}