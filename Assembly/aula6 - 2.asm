#calcular a média de 10 inteiros

.data
	str1: .asciiz "a media eh: "
	str2: .asciiz "digite um numero"
.text

	add $s0, $0, $0 #i=0
	add $s1, $0, $0 #media = 0
FOR1:
 	slti $t0, $s0, 10 #i<10
	beq $t0, $0, SAI1 
	addi $s0, $s0, 1 # i++
	#corpo do for
	li $v0, 4
	la $a0, str2
	syscall
	
	li $v0, 5
	syscall
	add $s1, $s1, $v0 # media = media + nº capturado
	#/corpo do for
	j FOR1
SAI1:
	div $s1, $s0 #media/10, onde s0 = 10 (i = 10 no final da contagem)
	li $v0, 4
	la $a0, str1
	syscall
	
	li $v0, 1 #mostra o valor da media
	mflo $a0
	syscall
	
	#return 0
	li $v0, 10
	syscall