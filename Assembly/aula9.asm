#bubbleSort em assembly

.include "macros.asm"
.data
	n: .space 4 #(4 bytes -> 1 posiçao de int)
	temp: .space 4 #(4 bytes -> 1 posiçao de int)
	arr: .space 400 #(400 bytes -> 100 posiçoes de int)
	str1: .asciiz "escreva n: "
	str2: .asciiz "\nescreva um numero: "
	str3: .asciiz "\narray ordenado:"
.text
	printStr(str1)
	readInt($s0)
	#salva o numero lido em n (memória de n)
	la $t0, n #cria ponteiro para n
	sw $s0, 0($t0) #salva o inteiro em s0 na posicao 0 de t0
	
	#loop para guardar dados do array
	la $s7, arr #ponteiro para o array, fica com o endereço da posição 0 do array
	addi $s1, $0, 0 # i = 0
FOR:    slt $t7, $s1, $s0  # testar i < n (n está no s0 e no t0 nesse momento)
	beq $t7, $0, SAI 
	#corpo do for
	printStr(str2)
	readInt($s2)
	sll $t3, $s1, 2 #é pra multiplicar o i por 4 (já que precisa disso pq o array é de inteiros)
	add $t3, $t3, $s7 #t3 recebe o endereço do s7 + t3, ou seja, é aritmética de vetores
	sw $s2, 0($t3)
	#em vez de oq tá nas linhas 24 e 25, vc podia so colocar: addi $s7, $s7, 4 ; onde s7 guarda o endereço da primeira posicao do array
	#/corpo do for
	addi $s1, $s1, 1 # i++
	j FOR
SAI:

	#BubbleSort
	# **s0 ainda tem o valor de n
	addi $s1, $0, 0 #i = 0
	move $t3, $0
	addi $t0, $s0, -1 # t0 = n-1
BUBBLE: slt $t7, $s1, $t0 #i<(n-1)
	beq $t7, $0, SAI1
	#corpo do bubblesort
	#for (int j = 0; j <n-i-1; j++)
		add $s2, $0, $0 #j = 0
FOR1:   	sub $t2, $s0, $s1
		addi $t2, $t2, -1
		slt $t3, $s2, $t2
		beq $t3, $0, SAI2
		#corpo do for
		sll $t4, $s2, 2
		add $t4, $t4, $s7 #guarda em t4 a posição 0 do array + algum multiplo de 4, pra acessar posicoes adiante no array
		lw $t5, 0($t4) #posicao definida com o j 
		lw $t6, 4($t4) #próxima posição, em relação ao t4 (posicao definida com o j+1)
		slt $t7, $t6, $t5 #if (arr[j]>arr[j+1])
		beq $t7, $0, SF1 #sai se afirmar 0 (false) para arr[j+1]<arr[j]
			#corpo do if
			#temp = arr[j]
			la $at, temp
			sw $t5, 0($at)
			#arr[j] = arr[j+1]
			sw $t6, 0($t4)
			#arr[j+1] = temp
			sw $t5, 4($t4)
			#/corpo do if
SF1:
		#/corpo do for
		addi $s2, $s2, 1 #j++
		j FOR1
SAI2:
	#/corpo do bubblesort
	addi $s1, $s1, 1
	j BUBBLE
SAI1:
	#escrever o array ordenado
	printStr(str3)
	#for (int i = 0; i<n; i++)
		add $s1, $0, $0
FOR2:		slt $t0, $s1, $s0
		beq $t0, $0, SAI3
		#corpo do for
		sll $t2, $s1, 2
		add $t2, $t2, $s7
		lw $t3, 0($t2)
		printInt($t3)
		#/corpo do for
		addi $s1, $s1, 1
		j FOR2
SAI3:
	return0