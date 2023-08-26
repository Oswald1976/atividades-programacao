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
    typedef uint8_t buffer[512];
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


 // Ler os primeiros 3 bytes
    BYTE bytes[3];
    fread(bytes, sizeof(BYTE), 3, file);
    // Verificar os três primeiros bytes
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
    {
        int adest = 000;
        const char *nomeArquivo = "%s.jpg", adest;
        FILE *arquivo;
        arquivo = fopen(nomeArquivo, "w");
        if (arquivo != NULL)
        {
            printf("O arquivo existe.\n");
            fclose(arquivo);
        }
        else
        {
            printf("O arquivo não existe.\n");
        }

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