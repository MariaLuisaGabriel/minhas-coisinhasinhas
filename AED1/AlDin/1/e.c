#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int CPF;
    char EC[20];
    char **fi;
    int filhos;
}cli;
int T=0;
void inserir(cli *l,int y);
void remover(cli *b);
void mostrar1(cli *f);
void mostrar2(cli *o);
int main()
{
    cli *c;
    char C[1];
    int n;
    int i;
    printf("escreva quantos clientes ira colocar na lista: ");
    scanf("%d",&n);
    setbuf(stdin,0);
    c = (cli *)malloc(n*sizeof(cli));
    if(c==NULL)
    {
        printf("ERRO! memoria nao alocada.");

    }
    while(1)
    {
        printf("\nMENU:\n=====\n");
        setbuf(stdin,0);
        printf("opcoes de comando:\nI:inserir cliente;\nM:mostrar todos os dados dos clientes inscritos;\nR:remover cliente;\nC:mostrar CPF dos clientes inseridos;\nX:sair do MENU;\n->");
        scanf("%s",C);
        if((strcmp(C,"I")==0)||(strcmp(C,"i")==0))
        { 
            inserir(c,n);
        }
        else if((strcmp(C,"R")==0)||(strcmp(C,"r")==0))
        {
            remover(c);
        }
        else if((strcmp(C,"C")==0)||(strcmp(C,"c")==0))
        {
            mostrar1(c);  
        }
        else if((strcmp(C,"M")==0)||(strcmp(C,"m")==0))
        {
            mostrar2(c);
        }
        else if((strcmp(C,"X")==0)||(strcmp(C,"x")==0))
        {
            break;
        }
        else
            printf("\nesse comando nao esta na lista de comandos!\n");
    }
    return 0;
}
void inserir(cli *l,int y)
{
    int m;
    if(T==y)
    {
        printf("lista de clientes cheia! remova um cliente para adicionar outro.");
    }
    else
    {
        printf("insira o CPF do cliente: ");
        scanf("%d",&l[T].CPF);
        setbuf(stdin,0);
        printf("insira o estado civil do cliente: ");
        scanf("%[^\n]s",l[T].EC);
        printf("esse cliente possui filhos? se sim, quantos? se nao, escreva 0. ");
        scanf("%d",&m);
        l[T].filhos=m;
        if(m==0);
        else
        {
            l[T].fi=(char **)malloc(m*sizeof(char*));
                for(int j=0;j<m;j++)
                    l[T].fi[j]=(char *)malloc(20*sizeof(char));
            for(int a=0;a<m;a++)
            {
                setbuf(stdin,0);
                printf("\nescreva o nome do filho %d: ",a+1);
                scanf("%[^\n]s",l[T].fi[a]);
            }
        }
        printf("insercao bem-sucedida!");
        T++;
    }
}
void remover(cli *b)
{
    int p;
    if(T==0)
    {
        printf("nao ha clientes na lista para remover!");
    }
    else
    {   
        printf("qual a posicao do cliente que deseja remover? ");
        scanf("%d",&p);
        for(int a=(p-1);a<T;a++)
        {
            *(b+a)=*(b+a+1);
        }
        puts("remocao bem-sucedida!");
        T--;
    }
}
void mostrar1(cli *f)
{
    for(int i=0;i<T;i++)
        printf("cliente %d: %d\n",i+1,(f+i)->CPF);
}
void mostrar2(cli *o)
{
    if(T==0)
    {
        puts("nao ha clientes a se mostrar!");
    }
    else
    {
        for(int i=0;i<T;i++)
        {
            printf("\ncliente %d:\n-CPF: %d\n-estado civil: %s\n",i+1,(o+i)->CPF,(o+i)->EC);
            if((o[i].filhos)!=0)
            {
                printf("filhos do cliente %d:",i+1);
                for(int u=0;u<(o[i].filhos);u++)
                    printf("\nfilho %d: %s",u+1,(o+i)->fi[u]);
            }
        } 
    }
}