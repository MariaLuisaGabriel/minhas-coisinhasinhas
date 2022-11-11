#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char nome[50];
    int id;
}aluno;
int main()
{
    aluno *v;
    int q;
    int m=0,j=0;
    printf("escreva a quantidade de alunos que se deve ter na lista: ");
    scanf("%d",&q);
    v = (aluno *)malloc(q*sizeof(aluno));
    for(int i=0;i<q;i++)
    {
        printf("escreva o nome do %dº aluno: ",i+1);
        scanf("%s",(v+i)->nome);
        printf("escreva a idade do %dº aluno: ",i+1);
        scanf("%d",&(v+i)->id);
        if((v+i)->id>m)
        {
            m=(v+i)->id;
            j++;
        }
    }
    printf("\n\no aluno mais velho é o %s.",(v+j-1)->nome);
    return 0;
}