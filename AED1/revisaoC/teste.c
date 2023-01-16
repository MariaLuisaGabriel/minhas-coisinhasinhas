#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int raiz (float a, float b, float c, float *x1, float *x2){
    printf("aa");
    float raiz[2]; 
    float Delta;

    Delta = (b * b) - (4 * (a * c));
    
    
    if (Delta < 0){
        return 0;
    }

    
    if (Delta == 0){
        raiz[0] = (-b + sqrt(Delta)) / (2 * a); 
        
        *x1 = raiz[0]; 
        
        printf("Unica raiz da equacao: %f\n", *x1);
        
        return 1; 
    }
    
    if (Delta > 0){
        raiz[0] = ((-1)*b + sqrt(Delta)) / (2 * a); 
        raiz[1] = ((-1)*b - sqrt(Delta)) / (2 * a); 

        *x1 = raiz[0]; 
        *x2 = raiz[1];
        
        printf ("Raizes da equacao:\nx1: %f\nx2: %f\n", *x1, *x2);

        return 2; 
    } 
}

int main (){
  
   float a, b, c, r; 
   float *x1, *x2; 
   x1 = (float *)malloc(sizeof(float));
   x2 = (float *)malloc(sizeof(float));

    printf("Digite um valor A:\n");
    scanf("%f", &a); 
    printf("Digite um valor B:\n");
    scanf("%f", &b); 
    printf("Digite um valor C:\n"); 
    scanf("%f", &c); 

    r = raiz (a, b, c, x1, x2); 


    if (r == 0) {
        printf("O resultado dessa equacao nao possui raizes reais\n"); 
    }
    if (r == 1) {
        printf("O resultado dessa equacao tem uma unica raiz real\n");
    }
    if (r == 2) {
        printf("O resultado dessa equacao tem duas raizes reais\n");
    }
    
    
system("pause");
return 0;
}