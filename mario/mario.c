#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int a = get_int ("Digite a altura da piramide que deseja(aceitavel entre 1 e 8)");
    for (int i = 0; i < a; i++)
    {
       for (int j = 0; j < a; j++)
       {
            do
            {
            printf("#");
            }
            while( j <= a );
       }
    printf("\n");
    }
}