/*


"Este programa é de minha/nossa autoria. Durante a prova, não conversei/conversamos com qualquer pessoa nem copiei/copiamos ou adaptei/adaptamos esta solução."
por
Maria Luisa Gabriel Domingues, 12121BCC010 
Geraldo Rodrigues de Melo Neto, 12121BCC008
2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int isRealNum(char n[]);
int
main(int argc, char *argv[])
{
    float n=0;//numero recebido
    if(argv[1]=="\0")
    {
        fprintf(stderr,"ERRO:nao apresentou o numero a ser processado.\n");
        return -2;
    }    
    if(isRealNum(argv[1])==0)
    {
        fprintf(stderr,"ERRO:deve-se apresentar um número real.\n");
        return -3;
    }
    n=atof(argv[1]);
    printf("%.2f",n*2);
    return 0;
}
/*
verificar se n é um numero real
retorna 0 se o numero nao for real
retorna 1 se o numero for real
*/
int isRealNum(char n[])
{
    int i;
    i=((n[0]=='+'||'-') ? 1 : 0);
    for(;n[i]!='\0';i++)
    {
        if(n[i]==',')
        {
            return 0;
        }    
        if(n[i]=='.');
        else if (isdigit(n[i])==0)
        {
            return 0;
        }
    }
}