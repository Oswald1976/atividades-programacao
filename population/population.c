#include <stdio.h>


int popatua, popfutu, qtdmort, qtdnasc, qtdatua, qtdanos;


int main(void)
{
    do
    {
        printf("Digite a Quantidade Atual   ");
        scanf("%i", &popatua);
    }while(popatua < 9);

    do
    {
        printf("Digite a Quantidade futural ");
        scanf("%i", &popfutu);
    }while(popfutu <= popatua );

    while (popatua <= popfutu)
    {
        qtdmort = popatua / 4;
        qtdnasc = popatua / 3;

        qtdatua = qtdnasc - qtdmort;

        popatua = popatua + qtdatua ;
        qtdanos++;
    }
    printf("%i", qtdanos);
}