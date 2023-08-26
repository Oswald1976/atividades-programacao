#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//errado
// fread(buffer, 512, 1, filer);

// certo
// fread(buffer, 1, 512, filer);

// 1 = tamanho em byte;
// 512 = n de bytes a serem lidos de uma so vez;

int main(int argc, char *argv[])
{
    if (argc < 2) // Check for invalid usage
    {
        printf("O que vai ser recuperado ?!?!?!?!\n");
        return 1;
    }
    uint8_t buffer[512];
    int imagem , i = 0, gravando = 0;
    char img[10] = "000.jpg";

    FILE *file = fopen(argv[1], "r");
    FILE *image = NULL; //INICIALIZA O PONTEIRO VAZIO;
    if(file == NULL)  // Verifica se o arquivo foi aberto
    {
        printf("Não foi possivel abrir %s !!!\n", argv[1]);
        return 1;
    }

    //a função fread retorna o valor do bloco lido (512) retornando 0 quando chega ao fim do arquivo.
    while ((imagem = fread(buffer, 1, sizeof(buffer), file)) > 0)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (gravando == 1)
            {
                fclose(image);
            }
            sprintf(img, "%03i.jpg", i);
            image = fopen(img, "wb");
            i++;
            gravando = 1;
        }

        if (gravando == 1)
        {
            fwrite(buffer, 1, imagem, image);
        }
    }

    fclose(image);
    fclose(file);

    return 0;
}


