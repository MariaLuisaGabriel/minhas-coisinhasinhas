# COMO MEXER COM STRINGS/ARRAYS
# load word: lw receptor, posicao(doador de dados) (olha 32 bits)
# semanticamente: receptor recebe o dado na posicao inicial do doador de dados + posicao

# store word: sw doador de dados, posicao(receptor)
# semanticamente: receptor recebe, em certa posicao (relativo a sua posicao zero), os dados do doador

# load byte: lb receptor, doador(posicao)

# store byte: sb doador, receptor(posicao)
#A = 65, a = 97 ( A = a - 32 )
.include "macros.asm"
.data
	str1: .asciiz "escreva o tamanho da string: "
	str2: .asciiz "\nescreva uma palavra: "
	str3: .asciiz "\n\n\n"
	str: .asciiz
.text
	printStr(str1)
	readInt($s0)
	printStr(str2)
	readStr(str, $s0)
	
	li $t5, 122 #auxiliar
	li $t0, 0 #contador
WHILE:  slt $t1 , $t0, $s0 #compara se o contador é menor que a posicao final da string
	bne $t1, 1, SAI #se for maior ou igual, sai do loop
	lb $t1, str($t0) #t1 recebe um byte de str
	slti $t2, $t1, 97
	beq $t2, 1, JUMP #salta quando é verdade que t1<97
	slt $t2, $t5, $t1
	beq $t2, 1, JUMP #salta quando é verdade que 122<t1
	beq $t1, '\0', SAI
	addi $t1, $t1, -32 # muda ele para upperCase
	sb $t1, str($t0) #devolve o valor atualizado pra string

JUMP:   addi $t0, $t0, 1
	j WHILE
SAI:
	printStr(str3)
	printStr(str)
	return0
