#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
 if (argc < 2) // Check for invalid usage
    {
        printf("O que vai ser recuperado ?!?!?!?!\n");
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    

}