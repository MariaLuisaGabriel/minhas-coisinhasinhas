#BIOS: Sistema Bin�rio de Entrada e Sa�da -> c�digo que � usado pela CPU assim que o sistema � energizado (1� instru��o a ser feita qdo � ligado);
#a BIOS � um c�digo que possui v�rias fun��es, como a de verifica��o de funcionamento do sistema como um todo, servir de boot loader (carregar o sitema operacional)
 
.data

str1: .asciiz " Hello World!" #vari�vel que usa ASCII

.text
#teste para entrada de dados

li $v0, 5 #5 = leitura de dados, o dado capturado vai pro v0 (especifica��o em help)
syscall
add $a0, $v0, $zero #passar o dado pro a0, a partir do v0 (resultado da leitura vai pro v0)

#teste de impress�o de inteiros na tela
#uso de $v0 =  uso de servi�os, mais detalhes em help [syscalls] (MARS), cada numero serve pra algo, assim como 10 serve para return 0;

addi $v0, $0, 1 #1 = impressao de inteiros, guardados em v0 (especifica��o em help)
#addi $a0, $0, 42 -> guardar 42 em a0 para ser printado na tela, antes de ser escrito o teste para entrada de dados :)
syscall #assim que escreve syscall, o sistema � verificado, e ele ve que em v0 esta o 1, entao ele pega a info em a0 e escreve ela na tela;

#teste de impress�o de strings na tela

addi $v0, $0, 4 #4 =  impressao de string (imprime oq est� em a0)
la $a0, str1 #load address
syscall

addi $v0, $zero, 10 #return 0
syscall

#add = opera��o entre 2 argumentos
#addi = atribui��o, se usado com $0, do dado relevante no registrador de destino (add immediate value - serve pra conseguir p�r dado imediato na conta, tipo 1,2,3.. etc);
