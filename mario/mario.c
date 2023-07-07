#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int s = 0;
    int b = 0;
    int a;
    do
    {
        a = get_int ("Digite a altura da piramide que deseja(aceitavel entre 1 e 8)");
    }
    while ( a < 1 || a > 8 );
        for (int i = 0; i < a; i++)
            {
                for (int j = 0; j < a; j++)
                {
                        printf(" ");
                }
            printf("\n");
            }

}