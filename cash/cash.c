#include <stdio.h>

float cent;
int m25 = 0, m10 = 0, m5 = 0, m1 = 0, totalm = 0;


int main(void)
{
    do
    {

        printf("Digite o Valor do troco em moedas (aceitavel entre 0,01 e 0,99 e substitua a , por . )");
        scanf("%float", &cent);
    }
    while ((int) cent >= 1);
        while (cent >= 0.25 )
            {
                m25= m25 + 1 ;
                cent = cent - 0.25;
            }
        while ( cent >= 0.10 )
            {
                m10= m10 + 1 ;
                cent=cent - 0.10;
            }
        while ( cent >= 0.05 )
            {
                m5= m5 + 1 ;
                cent=cent - 0.05;
            }
         while ( cent > 0.00 )
            {
                m1= m1 + 1 ;
                cent=cent - 0.01;
            }
        totalm = m25+m10+m5+m1;
        printf("Quantidade de moedas de 0,25 ... : %i\n", m25 );
        printf("Quantidade de moedas de 0,10 ... : %i\n", m10 );
        printf("Quantidade de moedas de 0,05 ... : %i\n", m5 );
        printf("Quantidade de moedas de 0,01 ... : %i\n", m1 );
        printf("Quantidade de total de moedas .. : %i\n", totalm );

}
