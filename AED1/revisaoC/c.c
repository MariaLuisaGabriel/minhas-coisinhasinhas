/*
Faça um programa que receba três notas de um aluno, calcule e mostre a média aritmética. Considerando que, se o aluno tirar média entre 0 e 3, ele está REPROVADO, se ele tirar entre 3 e 7, ele está de EXAME FINAL, e se ele tirar entre 7 e 10, ele está APROVADO, calcule, para alunos de EXAME FINAL, qual deverá ser a nota tirada neste exame, para que o aluno seja aprovado, considerando que a média entre a nota do exame e a média ao longo do semestre deve ser 6,0.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char notas[3][6];
    char ef[6];
    float n1=0,n2=0,n3=0,m,EF;
    int i,j,a,b;
    printf("escreva as tres notas que tirou esse semestre, no seguinte modelo:\n||n1 n2 n3\n**EM NOTAÇAO COM 2 casas decimais!\n->");
    scanf("%s %s %s",notas[0],notas[1],notas[2]);
    printf("%d\n",isdigit(notas[0][0]));
    for(i=0;i<2;i++)
    {  
        for(j=0;j<5;j++)
        {
            if(strlen(notas[i])>5)
            {
                printf("ERRO: escreva uma nota compativel com as da escola e com o modelo!");
                return -1;
            }
            if(isdigit(notas[i][j])==0)
            {
                if(notas[i][j]=='.');
                else
                {
                    printf("ERRO1: escreva NUMEROS positivos, somente!");
                    return -2;
                }
            }
        }
    }
    for(a=0;a<2;a++)
    {
        for(b=0;b<5;b++)
        {
            if(notas[a][b]==',')
                notas[a][b]='.';
        }
    }
    n1=atof(notas[0]);
    if(n1>10)
    {
        printf("ERRO: escreva uma nota compativel com as da escola!");
        return -3;
    }
    n2=atof(notas[1]);
    if(n2>10)
    {
        printf("ERRO: escreva uma nota compativel com as da escola!");
        return -4;
    }
    n3=atof(notas[2]);
    if(n3>10)
    {
        printf("ERRO: escreva uma nota compativel com as da escola!");
        return -5;
    }
    m=(n1+n2+n3)/3;
    if(3>=m>=0)
    {
        puts("parabens! voce esta REPROVADO.");
    }
    else if(m<=7)
    {
        puts("parabens! voce fara EXAME FINAL.");
        puts("escreva a nota que tirou no EXAME FINAL:");
        printf("->");
        scanf("%s",ef);
        for(i=0;i<5;i++)
        {
            if(strlen(ef)>5)
            {
                printf("ERRO: escreva uma nota compativel com as da escola e com o modelo!");
                return -6;
            }
            if((isdigit(ef[i])==0)&&(ef[i]!=',')&&(ef[i]!='.'))
            {
                printf("ERRO2: escreva NUMEROS positivos, somente!");
                return -7;
            }
        }
        EF=atof(ef);
        if(EF>=10)
        {
            printf("ERRO: escreva uma nota compativel com as da escola!");
            return -8;
        }
        m=(m+EF)/2;
        if(m>=6)
        {
            puts("parabens! voce esta APROVADO.");
        }
        else
        {
            puts("parabens! voce esta REPROVADO.");
        }
    }
    else if(m<=10)
    {
        puts("parabens! voce esta APROVADO.");
    }
    return 0;
}