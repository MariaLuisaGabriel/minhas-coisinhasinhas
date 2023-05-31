#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD.h"

int main()
{
    FILE *f;
    char palavra[50], estrofe[1000], nome[50], autor[50];
    pal *fila, *buscaBin, *arvBin, *arvAVL_pal, *arvAVL_freq;
    int disp[16], j, k = 0, tam = 1;
    for(int i = 0; i<16; i++)
    {
        disp[i]=1;
    }
    //menu dos arquivos disponíveis para acesso:
    while(1)
    {
        printf("MENU\n====\nqual dos arquivos disponiveis quer baixar?");
        j=1;
        for(int i = 1; i<=16; i++)
        {
            switch(i)
            {
                case 1:
                    if(disp[i]==1) printf("\n%d - Lança Perfume, Rita Lee",j); j++;
                    break;
                case 2:
                    if(disp[i]==1) printf("\n%d - Ovelha Negra, Rita Lee",j); j++;
                    break;
                case 3:
                    if(disp[i]==1) printf("\n%d - Brasil, Cazuza",j); j++;
                    break;
                case 4:
                    if(disp[i]==1) printf("\n%d - Todo o Amor Que Houver Nessa Vida, Cazuza",j); j++;
                    break;
                case 5:
                    if(disp[i]==1) printf("\n%d - Lança Perfume, Rita Lee",j); j++;
                    break;
                case 6:
                    if(disp[i]==1) printf("\n%d - Lança Perfume, Rita Lee",j); j++;
                    break;
                case 7:
                    if(disp[i]==1) printf("\n%d - Lança Perfume, Rita Lee",j); j++;
                    break;
                case 8:
                    if(disp[i]==1) printf("\n%d - Lança Perfume, Rita Lee",j); j++;
                    break;
                case 9:
                    if(disp[i]==1) printf("\n%d - Lança Perfume, Rita Lee",j); j++;
                    break;
                case 10:
                    if(disp[i]==1) printf("\n%d - Lança Perfume, Rita Lee",j); j++;
                    break;
                case 11:
                    if(disp[i]==1) printf("\n%d - Lança Perfume, Rita Lee",j); j++;
                    break;
                case 12:
                    if(disp[i]==1) printf("\n%d - Lança Perfume, Rita Lee",j); j++;
                    break;
                case 13:
                    if(disp[i]==1) printf("\n%d - Lança Perfume, Rita Lee",j); j++;
                    break;
                case 14:
                    if(disp[i]==1) printf("\n%d - Lança Perfume, Rita Lee",j); j++;
                    break;
                case 15:
                    if(disp[i]==1) printf("\n%d - Lança Perfume, Rita Lee",j); j++;
                    break;
                case 16:
                    if(disp[i]==1) printf("\n%d - Lança Perfume, Rita Lee",j); j++;
                    break;
            }
        }
        if(j==1) printf("todas as letras ja foram baixadas.");
        else
        {
            printf("\ndigite 0 se quiser sair;\n->");
            scanf("%d",&j);
        }
        if(j==0) {break;}
        f = fopen("1.txt","r");
        /*switch(j)
        {
            case 1:
                printf("a");
                f = fopen("1.txt","r");   
                break;
            case 2:
                f = fopen("2.txt","r");
                break;
            case 3:
                f = fopen("3.txt","r");
                break;
            case 4:
                f = fopen("4.txt","r");
                break;
            case 5:
                f = fopen("5.txt","r");
                break;
            case 6:
                f = fopen("6.txt","r");
                break;
            case 7:
                f = fopen("7.txt","r");
                break;
            case 8:
                f = fopen("8.txt","r");
                break;
            case 9:
                f = fopen("9.txt","r");
                break;
            case 10:
                f = fopen("10.txt","r");
                break;
            case 11:
                f = fopen("11.txt","r");
                break;
            case 12:
                f = fopen("12.txt","r");
                break;
            case 13:
                f = fopen("13.txt","r");
                break;
            case 14:
                f = fopen("14.txt","r");
                break;
            case 15:
                f = fopen("15.txt","r");
                break;
            case 16:
                f = fopen("16.txt","r");
                break;
        }*/
        j=0;
        //montar a fila de palavras
        while(!feof(f))
        {
            if(k!=1)
            {
                fscanf(f,"%[^\n]\n %[^\n]\n\n %[^\n]\n\n",nome,autor,estrofe);
                k=1;
            }
            else
            {
                fscanf(f,"%[^\n]\n\n",estrofe);
            }

            espacos();//gera vetor com todas as posições de espaços ou / da estrofe
            for(int i=0;i<strlen(estrofe);i++)
            {
                if(estrofe[i]=='\n')
                {
                    estrofe[i] = '/';
                }
                else
                {    
                    extrai();//tira uma palavra por vez do intervalo entre um espaço e outro
                    printf("%s",palavra);
                    if(strlen(palavra)>3)
                    {
                        insereFila(fila,palavra,estrofe,nome,autor);
                    }
                }
            }
        }
        fclose(f);
        /*while(fila!=NULL)
        {
            insereBuscaBin(buscaBin,&tam,POPFila(fila));
            insereArvAVL_freq();
            insereArvAVL_pal();
            insereArvBin();
        }

        printf("\n\nfazer pesquisa de palavras nas letras de musica(0) ou continuar baixando(1)?")
        scanf("%d",&j);
        if(j==0)
        {
            //funcoes de pesquisa em cada funçao, precisa ainda dizer o tempo de custo das pesquisas
            //ver isso ^ no arquivo do teams

            //print de informaçoes do dado procurado
        }*/
    }
    mostraFila(fila);
    return 0;
}