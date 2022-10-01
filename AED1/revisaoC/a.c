/*
Faça um programa que receba o ano de nascimento de uma pessoa e o ano atual, calcule e mostre a idade desta
pessoa, e quantos anos essa pessoa terá em 2030.
*/
#include <stdio.h>
int main()
{
    int n,a;
    puts("escreva seu ano de nascimento:");
    scanf("%d",&n);
    puts("escreva o ano atual:");
    scanf("%d",&a);
    if(a<n)
    {
        fprintf(stderr,"\noxe kkkkkkj\n");
        return -1;
    }
    if((a-n)==1)
        printf("sua idade atual é %d ano, e voce tera %d anos em 2030.",a-n,2030-n);
    else
        printf("sua idade atual é %d anos, e voce tera %d anos em 2030.",a-n,2030-n);
    return 0;
}