#comentario ehehe
#primeira aula de Assembly!!
#15/03/23

#apresenta��o da estrutura m�nima de um programa de asm
#run: f3 (assemble)

.data #declarando vari�veis
    x: .word 42 #declara uma palavra(32 bits) x com o valor 42
    y: .word 12 #declara uma palavra(32 bits) y com o valor 12
    z: .word 2 #declara uma palavra(32 bits) z com o valor 2
    w: .space 4 #declara uma variavel w com 4 bytes de espa�o
    f: .float 3.123 #declara uma variavel float f com valor 3.123

.text #comandos Assembly de opera��o
#jeitinho maroto de guardar/transferir rapidamente informa�oes num registrador: addi rd,ri,cte (rd = registrador de destino, ri = registrador inicial($zero),cte = constante)
#inicializando vari�veis: ($0 = $zero)

    addi $s0, $0, 42
    addi $s1, $0, 12
    addi $s2, $0, 2
    
#opera�oes:
    
    add $t0, $s0, $s1
    sub $s3, $t0, $s2
    
# "return 0":
   
    addi $v0, $0, 10
    syscall     

#nao precisa compilar! somente rodar.
