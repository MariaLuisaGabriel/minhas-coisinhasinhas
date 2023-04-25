.include "macros.asm"
.data
	arr: .space 4000 #array com 1000 posições para inteiros
	key: .space 4
	str: .asciiz "\n"
	str1: .asciiz ","
.text
#1º: gerar numeros aleatorios:
	la $s7, arr
	addi $t3, $0, 900
	addi $s5, $0, 6
	addi $s0, $0, 1 #contador
	addi $s1, $0, 10 #primeiro elemento do vetor
	sw $s1, 0($s7)
FOR:    slti $t1, $s0, 1000 #o loop começa preenchendo a partir da posicao 1
	beq $t1, 0, SAI
	sll $t2, $s0, 2 #multiplica o contador por 4 (aritmetica de vetores)
	add $t2, $t2, $s7
	#rand() => Xn+1 = (aXn+c)mod m, onde a = contador ,c = contador.6 e m = 110
	mul $t1, $s1, $s0 
	mul $t6, $s0, $s5
	add $t1, $t1, $t6
	div $t1, $t3
	mfhi $s1
	#/rand()
	sw $s1, 0($t2)
	addi $s0, $s0, 1
	j FOR	
SAI:
	printArr($s7,str1)
#void insertionSort(int *v, int n)
#{
#    int i, key, j;
	addi $s0, $0, 1 #i=1
	la $s2, key
#    for (i = 1; i < n; i++)
FOR2:	slti $t1, $s0, 1000
	beq $t1, 0, SAI2
#    {
	sll $t2, $s0, 2 #multiplica por 4 de acordo com o contador
	add $t2, $t2, $s7 #aritmética de vetores
#       key = v[i];
	lw $s2, 0($t2) #v[i]
#       j = i - 1;
	addi $s1, $s0, -1 
	
#       while (j >= 0 && v[j] > key)
WHILE:  
	sll $t2,$s1,2 #multiplica por 4 de acordo com o contador
	add $t2,$t2,$s7 #aritmética de vetores
	lw $s3, 0($t2) #v[j]
	
	slti $t0, $s1, 0 #j>=0 -> t0 = 0
	slt $t1, $s2, $s3 #v[j]>key -> t1 = 1
	sub $t1, $t0, $t1
	bne $t1, -1, SAI3 #continuar o while -> t0 - t1 = -1
#       {
	
	addi $s4, $s1, 1
	sll $t2, $s4, 2 #multiplica por 4 de acordo com o contador
	add $t2, $t2, $s7 #aritmética de vetores (posicao do j+1)
#           v[j + 1] = v[j];
	sw $s3, 0($t2)
#           j = j - 1;
	addi $s1, $s1, -1
#       }
	j WHILE
SAI3:
	addi $s4, $s1, 1
	sll $t2, $s4, 2 #multiplica por 4 de acordo com o contador
	add $t2, $t2, $s7 #aritmética de vetores (posicao do j+1)
#       v[j + 1] = key;
	sw $s2, 0($t2)
#   }
	addi $s0, $s0, 1
	j FOR2
#}
SAI2:
	printStr(str)
	printArr($s7,str1)
	return0
