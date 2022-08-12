/*
Apresentar o conteúdo de uma matriz M LxC.
L e C, assim como os dados da matriz são passados via arquivo .txt.
há o uso das funçoes carregaMat(preencher a matriz com numeros do arquivo), apresntaMat(apresenta os dados da matriz preenchida), apresentaDS(apresentar a diagonal secundaria da matriz) e apresentaDP(apresentar a diagonal principal da matriz).
"Este programa é de minha/nossa autoria. Durante a prova, não conversei/conversamos com qualquer pessoa nem copiei/copiamos ou adaptei/adaptamos esta solução."
por
Maria Luisa Gabriel Domingues, 12121BCC010 
Geraldo Rodrigues de Melo Neto, 12121BCC008
2022
*/

#include <stdio.h>
#define MAXL 10
#define MAXC 10
int carregaMat(int l,int c,int mat[MAXL][MAXC],FILE *f);
void apresentaMat(int l,int c,int mat[MAXL][MAXC]);
void apresentaDP(int l,int c,int mat[MAXL][MAXC]);
void apresentaDS(int l,int c,int mat[MAXL][MAXC]);
int
main(int argc,char *argv[])
{
    FILE *f = NULL;
    int mat[MAXL][MAXC];//matriz a ser preenchida
	int L;//numero de linhas
    int C;//numero de colunas
    if(argc<2)
    {
        fprintf(stderr,"ERRO:faltam argumentos.\n");
        return -2;
    } 
    f = fopen(argv[1],"r");
    if(f == NULL)//exibir erro à abertura do arquivo, caso ocorra
    {
        fprintf(stderr,"ERRO:arquivo nao pode ser aberto\n");
        return -1;
    }
    fscanf(f,"%d %d", &L, &C);
    if(carregaMat(L,C,mat,f)==0)
    {
        fprintf(stderr,"o conteúdo do arquivo não foi suficiente para preencher M.\n");
        return 2;
    }
    printf("\n");
    apresentaMat(L,C,mat);
    printf("\n");
    apresentaDP(L,C,mat);
    printf("\n");
    apresentaDS(L,C,mat);
    printf("\n");
    fclose(f);
    return 0;
}
/*
preenchimento de M com os números contidos no arquivo .txt
recebe os argumentos L,C,a matriz mat e o arquivo f
retorna 0 a funçao main quando não há dados suficientes para preenchimento
retorna 1 a funçao main quando há dados suficientes para preenchimento
*/
int carregaMat(int l,int c,int mat[MAXL][MAXC],FILE *f)
{
    int i;//contador
    int j;//contador
    for(i=0;i<l;i++)
    {
        for(j=0;j<c;j++)
        {
            fscanf(f,"%d",&mat[i][j]);
            if(mat[i][j]=='\0')
                return 0;
        }

    }
    return 1;
}
/*
apresentação de M
recebe L,C e a matriz mat
*/
void apresentaMat(int l,int c,int mat[MAXL][MAXC])
{
    int i;//contador
    int j;//contador
    printf("Matriz\n-------\n");
    for(i=0;i<l;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%02d ",mat[i][j]);
        }
        printf("\n");
    }
}
/*
apresenta a diagonal principal da matriz mat
recebe L,C, e a matriz mat
*/
void apresentaDP(int l,int c,int mat[MAXL][MAXC])
{
    int i;//contador
    int j;//contador
    printf("\ndiagonal principal:\n");
    for(i=0;i<l;i++)
    {
        for(j=0;j<c;j++)
        {
            if(i==j)
                printf("%02d ",mat[i][j]);
            else
                printf("  ");
        }
        printf("\n");
    }
}
/*
apresenta a diagonal secundaria da matriz mat
recebe L,C, e a matriz mat
*/
void apresentaDS(int l,int c,int mat[MAXL][MAXC])
{
    int i;//contador
    int j;//contador
    printf("\ndiagonal secundaria:\n");
    for(i=0;i<l;i++)
    {
        for(j=c;j>=0;j--)
        {
            if((i+j)==(l-1))
                printf("%02d ",mat[i][j]);
            else
                printf("  ");
        }
        printf("\n");
    }
}