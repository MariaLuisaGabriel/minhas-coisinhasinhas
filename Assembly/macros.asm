#criação e uso de macros
#macros: arquivos que possuem certos grupos de operações interessantes a outro código, de outro arquivo
#return 0
.macro return0
      li $v0, 10
      syscall
.end_macro 

#print int
.macro printInt(%int) #o %int é um argumento pra macro, precisa do % pra mostrar que é argumento
      li $v0, 1
      add $a0, $0, %int #argumento recebido
      syscall
.end_macro 
#read int
.macro readInt(%reg)
     li $v0, 5
     syscall
     add %reg, $0, $v0 #retorna, por reg, o valor lido
.end_macro 
#print string
.macro printStr(%str)
     li $v0, 4
     la $a0, %str
     syscall
.end_macro 
#read string
.macro readStr(%buff, %len)
     li $v0, 8
     la $a0, %buff #posiçao a se armazenar o dado lido
     add $a1, $0, %len #quantidade de caracteres que tem que ler
     syscall
.end_macro 

#print array
.macro printArr(%int,%buff)
	add $s1, $0, $0
FOR2:	slt $t0, $s1, $s0
	beq $t0, $0, SAI3
	#corpo do for
	sll $t2, $s1, 2
	add $t2, $t2, $s7
	lw $t3, 0($t2)
	printInt($t3)
	printStr(%buff)
	#/corpo do for
	addi $s1, $s1, 1
	j FOR2
SAI3:
.end_macro