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

#push (salvar contexto de TODOS os registradores)
.macro PUSH()
	sw $at, 0($sp)
	sw $a0, -4($sp)
	sw $a1, -8($sp)
	sw $a2, -12($sp)
	sw $a3, -16($sp)
	sw $t0, -20($sp)
	sw $t1, -24($sp)
	sw $t2, -28($sp)
	sw $t3, -32($sp)
	sw $t4, -36($sp)
	sw $t5, -40($sp)
	sw $t6, -44($sp)
	sw $t7, -48($sp)
	addi $sp, $sp, -52 #prepara o sp pra outro salvamento
.end_macro 

#pop (pegar tudo que é guardado e botar de volta nos registradores)
.macro POP()
	addi $sp, $sp, 52 #volta o sp pra posicao original dele
	lw $at, 0($sp)
	lw $a0, -4($sp)
	lw $a1, -8($sp)
	lw $a2, -12($sp)
	lw $a3, -16($sp)
	lw $t0, -20($sp)
	lw $t1, -24($sp)
	lw $t2, -28($sp)
	lw $t3, -32($sp)
	lw $t4, -36($sp)
	lw $t5, -40($sp)
	lw $t6, -44($sp)
	lw $t7, -48($sp)
.end_macro
