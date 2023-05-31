#fazer funcao fatorial

.include "macros.asm"

.data
	str1: .asciiz "\nescreva um numero: "
	str2: .asciiz "\nresultado: "
	
.text

	printStr(str1)
	readInt($s0)
	printStr(str2)
	
	add $a0, $0, $s0
	addi $a1, $0, 2
	add $a2, $0, 1
	jal FAT
	add $s1, $0 $v0
	printInt($s1)
	return0
	
FAT:
	PUSH()
LOOP:   sle $t0, $a1, $a0
	beq $t0, 0, SAI
	mul $a2, $a2, $a1
	addi $a1, $a1, 1
	j LOOP
SAI:
	add $v0, $0, $a2
	POP()
	jr $ra