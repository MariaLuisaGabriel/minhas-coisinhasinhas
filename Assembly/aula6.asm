#ESTRUTURAS DE REPETIÇÃO

.data


.text
#dowhile
	add $s0, $0, $0

	#corpo do dowhile
dw1: 	
	addi $s0, $s0, 1 #tipo um i++	
	#\corpo do dowhile
	#exp logica
	slti $t0, $s0, 10 #(set if less than immediate) condiçao i<10 TRUE = 1, FALSE = 0
	#\exp logica
	bne $t0, $0, dw1 #vai continuar o while se 1 != 0 (se a condição não se encontra FALSE), ou seja, se i<10, quando der 0 == 0 (i>=10), o programa executa a partir da linha 19

#while
	add $s0, $0, $0
	
	#exp logica
wh1:	slti $t0, $s0, 10 #if i<10
	beq $t0, $0, SAI1 # if (FALSE) jump SAI1
	#\exp logica
	#corpo do while
	addi $s0, $s0, 1 # i++
	li $v0, 1 #print integer
	add $a0, $s0, $0
	syscall
	
	#\corpo do while
	j wh1 #refaz o loop do while
SAI1:

#for
	add $s0, $0, $0 #i=0
FOR1:
 	slti $t0, $s0, 10 #i<10
	beq $t0, $0, SAI2 
	addi $s0, $s0, 1 # i++
	#corpo do for
	li $v0, 1
	add $a0, $s0, $0
	syscall
	#/corpo do for
	j FOR1
SAI2:
	#return 0
	li $v0, 10
	syscall