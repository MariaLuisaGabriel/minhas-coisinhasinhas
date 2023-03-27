#basico1.asm

#DESC: le dois valores do teclado e calcula a sua media

.data
	str1: .asciiz "escreva o primeiro inteiro: "
	str2: .asciiz "escreva o segundo inteiro: "
	str4: .asciiz "eh impar"
	str5: .asciiz "eh par"

.text
	addi $v0, $zero, 4 #le string = 4
	la $a0, str1
	syscall
	
	#le o primeiro inteiro
	addi $v0, $zero, 5 #le inteiro = 5
	syscall
	add $s0, $zero, $v0
	
	addi $s7, $zero, 1
	and $s7, $s7, $s0 #AND da algebra booleana (como s7 é 1, ele vai fazer com que o AND guarde so o bit menos significativo, se em s0 ele for 1)
	# 10010101 && 00000001 = 00000001 (impar)
	# 10101010 && 00000001 = 00000000 (par)
	#em vez de and, podia usar andi $s7, $s7, 1
	
	beq $s7, $zero, PAR #compara os dados em s7 e zero, se for 0, ele pula para o endereço guardado em PAR
	#beq = branch if equal
	#imprime que eh impar (fzr isso embaixo o torna um else - so vai aí se oq ta em beq for falso)
	addi $v0, $zero, 4
	la $a0, str4
	syscall
	
	j SAI #jump para o endereço em SAI
	
    PAR:#imprime que eh par
	addi $v0, $zero, 4
	la $a0, str5
	syscall
	
    SAI:#return 0
	addi $v0, $zero, 10
	syscall


# 	OPERADORES LOGICOS:
#só há and, or, nor e xor
# estrutura dos comandos: 
# and $destino, $operando1, $operando2

#OBS: como conseguir ~x? nor de x = ~x, pois ~(x+x) = ~x  :D

#	OPERADORES LOGICOS COM CONSTANTES: (lembrando que ele analisa a constante como binário)
#só há andi, ori, nori e xori
# estrutura dos comandos:
# and $destino, $operando1, cte
