#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

void main()
{
    int i,o;
    arvBin *a;
    printf("\nnumero de nos: ");
    scanf("%d",&o);
    for(int j = 0;j<o; j++)
    {
        i = rand()%100;
        if(i==-1){break;}
        if(j==0)
        {
            a = criaArv(i);
        }
        else
        {
            insereNo(a,i,1);
        }
    }
    mostraArv(a);
    puts("\n");
    mostraArvAlin(a);
    int res;
    contTAM(a,0,&res);
    printf("\ntamanho da arvore: %d",res);
    printf("\nmaior valor da arvore: %d",maior(a));

    arvBin *k;
    printf("\nescreva um valor pra ser achado: ");
    scanf("%d",&i);
    k = buscaArv(a,i);
    if(k!=NULL) {printf("\nvalor %d existe na arvore.",i);}
    else {printf("\nvalor %d nao existe na arvore.",i);}

    printf("\n\nescreva o valor que quer remover: ");
    scanf("%d",&i);
    printf("\ndeseja remover substituindo pelo menor(1), ou pelo maior(2)?");
    scanf("%d",&o);
    a = removeNo(a,i,o);
    printf("\narvore com no retirado:\n");
    percursos(a,1);
    printf("\n");
    printf("\nmaior: %d, menor: %d\n",getmaior(a),getmenor(a));
    mostraArvAlin(a);
    mostraArv(a);
}