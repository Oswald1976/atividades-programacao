// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44; // Numero de bites do cabeçalho do arquivo wav
uint8_t header[HEADER_SIZE];
int16_t buffer[2];

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }
    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    float factor = atof(argv[3]);
    int som = 0;


    fread(header, 1, sizeof(header), input); // le os primeiros 44 bites do cabeçalho
    fwrite(header, 1, sizeof(header), output); // grava os primeiros 44 bites do cabeçalho
    // TODO: Copy header from input file to output file

 while ((som = fread(buffer, 1, sizeof(buffer), input)) > 0)
    {
        som = (int16_t)(som * factor);

            fwrite(buffer, 1, som, output);

    }
    // TODO: Read samples from input file and write updated data to output file

    // Close files
    fclose(input);
    fclose(output);
    return 0;
}
