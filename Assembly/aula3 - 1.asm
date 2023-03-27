#basico1.asm

#DESC: le dois valores do teclado e calcula a sua media

.data
	str1: .asciiz "escreva o primeiro inteiro: "
	str2: .asciiz "escreva o segundo inteiro: "
	str3: .asciiz "a media inteira eh: "

.text
	addi $v0, $zero, 4
	la $a0, str1
	syscall
	
	#le o primeiro inteiro
	addi $v0, $zero, 5
	syscall
	add $s0, $zero, $v0
	
	addi $v0, $zero, 4
	la $a0, str2
	syscall
	
	#le o segundo inteiro
	addi $v0, $zero, 5
	syscall
	add $s1, $zero, $v0
	
	#calcula a media
	add $s2, $s1, $s0 #S0 + S1
	srl $s2, $s2, 1 #mover todos os elementos uma casa para a direita, para dividir por 2 (custa menos que a divisao)
	#como ocorre isso?
	#ex: 8/2 = 4, pois: 1000 (8), >>1 (move 1 casa pra direita) = 0100 (4)
	#JÁ SE MOVER PRA ESQUERDA: vc multiplica por 2
	#ex: 5x2=10, pois: 0101 (5), <<1 (move 1 casa pra esquerda) = 1010 (10)
	
	addi $v0, $zero, 4
	la $a0, str3
	syscall
	
	#imprime o resultado
	addi $v0, $zero, 1
	add $a0, $zero, $s2
	syscall
	
	addi $v0, $zero, 10
	syscall