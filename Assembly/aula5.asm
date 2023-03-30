#ESTRUTURAS DE REPETIÇÃO

#1) beq (branch if equal)
#sintaxe: beq rs, rt, label
#semantica: se rs == rt, jump to label
#ex: beq $s0, $zero, SAI

#2) j (jump)
#sintaxe: j label
#semantica: PC <- label (program counter recebe o endereço de memoria da etiqueta (label) )
#ex: j SAI
#obs: PC =  program counter (guarda a proxima posição de memoria a se executar no programa)

#3) slt (set if less than)
#sintaxe: slt rd, rs, rt
#semantica: se rs < rt entao rd <- 1, senão, rd <- 0

#4) bne (branch if not equal)
#sintaxe: bne rs, rt, label
#semantica: se rs != rt, jump to label

#INSTRUÇÕES DE CONTROLE DE FLUXO

.data
str1: .asciiz "eh menor que 10"
str2: .asciiz "eh maior ou igual a 10"

.text

#if(<expressao logica>)
#{ ... } -> executa if true (!=0)
#pula if false (==0)

# if (num<10)
# printf("eh menor que 10");
# else
# printf("eh >= 10")

li $v0, 5
syscall
move $t0, $v0 # mover o valor de v0 para t0

#expressao logica
slti $t1, $t0, 10 # set if less immediate (pra poder comparar com inteiros!!)
# t1 = 0 se t0>=10
# t1 = 1 se t0<10
#/expressao logica

beq $t1, $zero, ELSE #t1 é o resultado da expressao logica, caso $t1 seja 0 (FALSE), então vc pula para ELSE
#corpo do if
li $v0, 4
la $a0, str1
syscall
j SAI #pular o else, pois ja executou o if
#/corpo do if

ELSE:
#corpo do else
li $v0, 4
la $a0, str2
syscall
#/corpo do else

SAI: # é como se pulasse os argumentos do if
#obs: o endereço de SAI vai ser 55, pois a proxima instruçao valida aparece na linha 55
#return 0
li $v0, 10
syscall