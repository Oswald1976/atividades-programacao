#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
 if (argc < 2) // Check for invalid usage
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }
}