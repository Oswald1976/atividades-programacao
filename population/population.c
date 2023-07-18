#include <stdio.h>


int popatua, popfutu, qtdmort, qtdnasc, qtdatua, qtdanos;


int main(void)
{
    do
    {
        printf("Digite a Quantidade Atual");
        scanf("%d", popatua);
    }while(popatua < 9);

    do
    {
        printf("Digite a Quantidade futural");
        scanf("%d", popfuru);
    }while(popfutu <= popatua );

    do while (popatua <= popfutu)
    {
        qtdmort = popatua / 4;
        qtdnasc = popatua / 3;

        qtdatua = qtdnasc - qtdmort;

        popatua = popatua + qtdatua ;
        qtdanos++;
    }
    printf("%i\n", qdtanos);
}