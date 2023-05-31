#funcoes
#macros pop e push salvas na macros.asm

.include "macros.asm"
.data
	str1: .asciiz "digite dois numeros inteiros: \n"
	str2: .asciiz "o menor eh: "
.text
	printStr(str1)
	readInt($s0)
	readInt($s1)
	# (1) set argumentos: normalmente guardados em registradores reservados: a0, a1, a2, a3
	add $a0, $0, $s0
	add $a1, $0, $s1
	jal MIN # (2) chama a funcao, jal = jump and link (salta e salva o endereço de retorno (linha em que está) no $ra)
	add $s2, $v0, 0 # (7) retira de v0 o valor do retorno, pq ele é usado pra syscalls tb
	printStr(str2)
	printInt($s2)
	
	return0


#funcao MIN
MIN:	# (3) salva contexto
	sw $ra, 0($sp) #salvar na memória o endereço de retorno de fluxo, necessário pq ele é mt importante pro processo do código
	# 0: primeira posicao em relacao a sp
	sw $a0, -4($sp) #salvar na memória o endereço do primeiro argumento, necessário pq ele é mt importante pro processo do código
	# -4: segunda posicao em relacao a sp (ver em Obs) 
	sw $a1, -8($sp) #salvar na memória o endereço do segundo argumento, necessário pq ele é mt importante pro processo do código
	# -8: terceira posicao em relacao a sp (ver em Obs)
	addi $sp, $sp, -12 #(botar sp ja na proxima posicao, pra caso fosse necessario salvar mais algo)
	
	#Obs:valor do endereço de sp é o valor maximo para 32 bits, então para gerar array com ele, deve fazer movimento decrescente
	#(execução de procedimentos na memória em pilha tb usa do sp decrescente)
	
	#array final: [ra][a0][a1]
	#              0   1   2, onde a posicao 0 tem o endereço de maior valor
	#codigo da funcao
	slt $t0, $a0, $a1 # s0 tem o valor de retorno se t0 é 1 (s0<s1)
	beq $t0, $0, MAIOR
	add $t0, $0, $a0
	j PULA #p/ saltar de volta pra onde ta o jal ($ra salvou isso)
	
MAIOR:	add $t0, $0, $a1 # s0 guarda o valor de retorno, onde t0 é 0 (s0>=s1)

PULA:
	# (4) set retornos (guardados em v0 e/ou v1)
	add $v0, $0, $t0
	
	# (5) restaurar o contexto
	addi $sp, $sp, 12 #retorna sp pra seu valor original
	lw $ra, 0($sp) #o endereço de sp (0)
	lw $a0, -4($sp) #o endereço de sp + 4 bytes pra tras (1)
	lw $a1, -8($sp) #o endereço de sp + 8 bytes pra tras (2)
	
	# (6) retornar ao fluxo
	jr $ra #p/ saltar de volta pra onde ta o jal ($ra salvou isso) => jr (jump com endereço num registrador)