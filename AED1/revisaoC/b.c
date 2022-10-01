/*
Escreva um programa que recebe um operador aritmético e dois operandos e calcule a operação indicada. As
operações possíveis são soma(+), subtração(-), multiplicação(*) e divisão(/).
*/
#include <stdio.h>
void soma(float p,float s);
float subt(float P,float S);
void prod(float a, float b);
float divs(float bat, float ata);
int main()
{
    float po,so;
    char op;
    printf("escreva uma operacao com dois operandos que envolva uma das 4 operacoes:\n|-+: soma\n|-: subtracao\n|*: produto\n|/:divisao\n ");
    scanf("%f %c %f",&po,&op,&so);
    switch (op)
    {
        case '+':
            soma(po,so);
            break;
        case '-':
            printf("resultado: %.1f",subt(po,so));
            break;
        case '*':
            prod(po,so);
            break;
        case '/':
            printf("resultado: %.4f",divs(po,so));
            break;
        default:
            printf("escreva um dos quatro operandos do MENU somente!");
    }
    return 0;
}
void soma(float p,float s)
{
    printf("resultado: %.1f",p+s);
}
float subt(float P, float S)
{
    return(P-S);
}
void prod(float a, float b)
{
    printf("resultado: %f",a*b);
}
float divs(float bat, float ata)
{
    return(bat/ata);
}