typedef struct aluno{
    int mat;
    char nome[81];
    char turma;
    char email[41];
}Aluno
#define N 127
typedef Aluno* Hash[N]; // vetor de ponteiros para a                          // estrutura alunoint hash(int mat){   // função hashingreturn (mat%N);}