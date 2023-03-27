#BIOS: Sistema Binário de Entrada e Saída -> código que é usado pela CPU assim que o sistema é energizado (1ª instrução a ser feita qdo é ligado);
#a BIOS é um código que possui várias funções, como a de verificação de funcionamento do sistema como um todo, servir de boot loader (carregar o sitema operacional)
 
.data

str1: .asciiz " Hello World!" #variável que usa ASCII

.text
#teste para entrada de dados

li $v0, 5 #5 = leitura de dados, o dado capturado vai pro v0 (especificação em help)
syscall
add $a0, $v0, $zero #passar o dado pro a0, a partir do v0 (resultado da leitura vai pro v0)

#teste de impressão de inteiros na tela
#uso de $v0 =  uso de serviços, mais detalhes em help [syscalls] (MARS), cada numero serve pra algo, assim como 10 serve para return 0;

addi $v0, $0, 1 #1 = impressao de inteiros, guardados em v0 (especificação em help)
#addi $a0, $0, 42 -> guardar 42 em a0 para ser printado na tela, antes de ser escrito o teste para entrada de dados :)
syscall #assim que escreve syscall, o sistema é verificado, e ele ve que em v0 esta o 1, entao ele pega a info em a0 e escreve ela na tela;

#teste de impressão de strings na tela

addi $v0, $0, 4 #4 =  impressao de string (imprime oq está em a0)
la $a0, str1 #load address
syscall

addi $v0, $zero, 10 #return 0
syscall

#add = operação entre 2 argumentos
#addi = atribuição, se usado com $0, do dado relevante no registrador de destino (add immediate value - serve pra conseguir pôr dado imediato na conta, tipo 1,2,3.. etc);
