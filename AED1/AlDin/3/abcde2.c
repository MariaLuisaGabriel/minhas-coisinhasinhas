#include <stdio.h>
#include <stdlib.h>
void mm(float *med, int *mai, int *v, int m);
int troca(char c, int t, char *d);
void inverte(int t, int *v);
void prod(int t, int *v, int m);
void* maloc(int t,int zu,void *k);
int a;
char b;
int main()
{
    float l,e;
    int *v,me,ma,m,c;
    char *p,j;
    void *f;
    while(1)
    {
    printf("\n");
    puts("funcoes do programa: ");
    puts("*escreva o numero da opcao que deseja usar!*");
    puts("0- sair.");
    puts("1- apresentar a media e o maior valor de um vetor.");
    puts("2- trocar um certo caractere por * numa palavra.");
    puts("3- inverter um vetor escrito.");
    puts("4- produto de vetor por escalar.");
    puts("5- alocar dinamicamente um vetor, preenchendo-o com um certo valor.");
    printf("->");
    scanf("%d",&c);
    fflush(stdin);
    if(c==0)
    {
        break;
    }
    if(c==1)
    {
        printf("escreva quantos numeros se deseja colocar: ");
        scanf("%d",&m);
        fflush(stdin);
        v = (int *)malloc(m*sizeof(int));
        for(int i=0;i<m;i++)
        {
            printf("\nescreva o valor do %dº numero: ",i+1);
            scanf("%d",&v[i]);
        }
        mm(&e,&ma,v,m);
        puts("vetor escrito: ");
        for(int i=0;i<m;i++)
        {
            printf("%d ",v[i]);
        }
        printf("\n");
        printf("a media dos valores escritos eh: %f\no maior valor eh: %d",e,ma);
    }
    if(c==2)
    {
        printf("\nescreva o tamanho máximo da palavra que deseja escrever: ");
        scanf("%d",&m);
        p = (char *)malloc(m*sizeof(char));
        printf("\nescreva uma palavra qualquer: ");
        scanf(" %[^\n]s",p);
        printf("\nescreva um caractere que queira substituir por * : ");
        scanf(" %c",&j);
        me = troca(j,m,p);
        printf("\npalavra com %c oculto: %s",j,p);
        printf("\nforam feitas %d substituiçoes.",me);
    }
    if(c==3)
    {
        printf("\nescreva o tamanho do vetor a se inserir os numeros: ");
        scanf("%d",&m);
        v = (int *)malloc(m*sizeof(int));
        for(int i=0;i<m;i++)
        {
            printf("\nescreva o valor do %dº numero: ",i+1);
            scanf("%d",&v[i]);
        }
        puts("vetor escrito:");
        for(int i=0;i<m;i++)
        {
            printf("%d ",v[i]);
        }
        printf("\n");
        inverte(m,v);
        puts("vetor invertido:");
        for(int i=0;i<m;i++)
        {
            printf("%d ",v[i]);
        }
    }
    if(c==4)
    {
        printf("escreva quantos numeros se deseja colocar: ");
        scanf("%d",&m);
        fflush(stdin);
        v = (int *)malloc(m*sizeof(int));
        for(int i=0;i<m;i++)
        {
            printf("\nescreva o valor do %dº numero: ",i+1);
            scanf("%d",&v[i]);
        }
        printf("\nescreva um numero inteiro para multiplicar o vetor: ");
        scanf("%d",&me);
        puts("vetor antes do produto: ");
        for(int i=0;i<m;i++)
        {
            printf("%d ",v[i]);
        }
        prod(m,v,me);
        puts("vetor após o produto: ");
        for(int i=0;i<m;i++)
        {
            printf("%d ",v[i]);
        }
    }
    if(c==5)
    {
        printf("escreva o tamanho do vetor: ");
        scanf("%d",&m);
        printf("prefere escrever um valor do tipo :\n-0:letra;\n-1:numero inteiro;\n-2:numero fracionario.\n->");
        scanf("%d",&ma);
        if(ma==0)
        {
            printf("escreva a letra que se quer que preencha esse vetor: ");
            scanf(" %c",&j);
            f = maloc(m,ma,&j);
            puts("vetor de letras:");
            for(int i=0;i<m;i++)
            {
                printf("%c ",*(char *)(f+i));
            }
        }
        if(ma==1)
        {
            printf("escreva o valor que se quer que preencha esse vetor: ");
            scanf("%d",&c);
            f = maloc(m,ma,&c);
            puts("vetor de numeros:");
            for(int i=0;i<m;i++)
            {
                printf("%d ",*(int *)(f + i*sizeof(int)));
            }
        }
        if(ma==2)
        {
            printf("escreva o valor fracionário que se quer que preencha esse vetor: ");
            scanf("%f",&l);
            f = maloc(m,ma,&l);
            puts("vetor de numeros fracionarios:");
            for(int i=0;i<m;i++)
            {
                printf("%.2f ",*(float *)(f + i*sizeof(float)));
            }
        }
    }
    }
    return 0;
}
void mm(float *med, int *mai, int *v,int m)
{
    int i;
    *mai = 0;
    *med = 0.0;
    for(i=0;i<m;i++)
    {
        *med += *(v+i);
        if(*(v+i)>*mai)
        {
            *mai=*(v+i);
        } 
    }
    *med = *med/m;
}
int troca(char c, int t, char *d)
{
    int j=0;
    for(int i=0;i<t;i++)
    {
        if(d[i]==c)
        {
            d[i]='*';
            j++;
        }
    }
    return(j);
}
void inverte(int t, int *v)
{
    int d[t];
    for(int i=0;i<t;i++)
    {
        d[i]=v[i];
    }
    int j = t-1;
    for(int i=0;i<t;i++)
    {
        v[i]=d[j];
        j--;
    }
}
void prod(int t, int *v, int m)
{
    for(int i=0;i<t;i++)
    {
        v[i] = v[i]*m;
    }
}
void* maloc(int t, int zu, void *k)
{
    void *d;
    switch (zu)
    {
        case 0://caracter
        {
            d = (char *)malloc(t*sizeof(char));
            for(int i=0;i<t;i++)
            {
                *(char *)(d+i)=*(char *)k;
            }
            break;
        }
        case 1://inteiro
        {
            d = (int *)malloc(t*sizeof(int));
            for(int i=0;i<t;i++)
            {
                *(int *)(d+i*sizeof(int))=*(int *)k;
            }
            break;
        }
        case 2://fracionário
        {
            d = (float *)malloc(t*sizeof(float));
            for(int i=0;i<t;i++)
            {
                *(float *)(d+i*sizeof(float))=*(float *)k;
            }
            break;
        }
    }
    return d;
}
