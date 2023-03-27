#desafiozinho de cria pra casa: A. (a+(a*b)+(a*b*c)+(a*b*c*d))/a+b+c+d (Obs: divisao, o quociente fica no low e o resto fica no high)
#		       		B. s = a^2 - b^2 - c^2
#		       		C. USO do BEQ
#		       		D. se (a < b) | (b < c) imprima "yupi!"


.data

str1: .asciiz "resultado: "
str2: .asciiz "LETRA A: \n "
str3: .asciiz "LETRA B: \n"
str4: .asciiz "yupi!"
str5: .asciiz "LETRA D: \n"
str6: .asciiz "escreva a opção que quer executar: \n1-A;\n2-B;\n3-D;\n"

.text
#Letra C: USO DO BEQ
li $v0, 4
la $a0, str6
syscall

li $v0, 5
syscall
add $t0, $v0, $zero

beq $t0 1 A
beq $t0 2 B
beq $t0 3 D

#return 0
li $v0, 10
syscall

A:#Letra A:
li $v0, 4
la $a0, str2
syscall

#captura da variavel a:
li $v0, 5
syscall
add $t0, $v0, $zero #guarda em t0 o valor de a

#captura da variavel b:
li $v0, 5
syscall
add $t1, $v0, $zero #guarda em t1 o valor de b

#captura da variavel c:
li $v0, 5
syscall
add $t2, $v0, $zero #guarda em t2 o valor de c

#captura da variavel d:
li $v0, 5
syscall
add $t3, $v0, $zero #guarda em t3 o valor de d

#a*b
mul $t4, $t0, $t1 #guarda em t4 (LO) o valor de a*b

#a*b*c
mul $t5, $t4, $t2 #guarda em t5 (LO) o valor de a*b*c

#a*b*c*d
mul $t6, $t5, $t3 #guarda em t6 (LO) o valor de a*b*c*d

#a+b
add $t1, $t1, $t0 #guarda em t1 o valor de a+b

#a+b+c
add $t2, $t2, $t1 #guarda em t2 o valor de a+b+c

#a+b+c+d
add $t3, $t3, $t2 #guarda em t3 o valor de a+b+c+d

#a + a*b
add $t0, $t0, $t4 #guarda em t0 o valor de a+(a*b)

#a + a*b + a*b*c
add $t0, $t0, $t5 #guarda em t0 o valor de a+(a*b)+(a*b*c)

#a + a*b + a*b*c + a*b*c*d
add $t0, $t0, $t6 #guarda em t0 o valor de a+(a*b)+(a*b*c)+(a*b*c*d)

#(a+(a*b)+(a*b*c)+(a*b*c*d))/a+b+c+d
div $t0, $t3

#mostra o resultado
li $v0, 4
la $a0, str1
syscall

li $v0, 1
mflo $a0 #guarda em a0 o valor de (a+(a*b)+(a*b*c)+(a*b*c*d))/a+b+c+d
syscall 

#return 0
li $v0, 10
syscall

B:#Letra B:
li $v0, 4
la $a0, str3
syscall

#captura da variavel a:
li $v0, 5
syscall
add $t0, $v0, $zero #guarda em t0 o valor de a

#captura da variavel b:
li $v0, 5
syscall
add $t1, $v0, $zero #guarda em t1 o valor de b

#captura da variavel c:
li $v0, 5
syscall
add $t2, $v0, $zero #guarda em t2 o valor de c

#calculando a^2
mul $t0, $t0, $t0 #guarda em t0 o valor a^2

#calculando b^2
mul $t1, $t1, $t1 #guarda em t0 o valor b^2

#calculando c^2
mul $t2, $t2, $t2 #guarda em t0 o valor c^2

#a^2 - b^2
sub $t0, $t0, $t1 #guarda em t0 o valor a^2 - b^2

#a^2 - b^2 - c^2
sub $t0, $t0, $t2 #guarda em to o valor a^2 - b^2 - c^2

add $t3, $t0, $zero #guarda o valor a^2 - b^2 - c^2 numa variavel s (valor guardado em t3)

#mostra o resultado
li $v0, 4
la $a0, str1
syscall

li $v0, 1
add $a0, $t3, $zero #guarda em a0 o valor de s 
syscall 

#return 0
li $v0, 10
syscall

D:#Letra D

li $v0, 4
la $a0, str5
syscall

#captura da variavel a:
li $v0, 5
syscall
add $t0, $v0, $zero #guarda em t0 o valor de a

#captura da variavel b:
li $v0, 5
syscall
add $t1, $v0, $zero #guarda em t1 o valor de b

#captura da variavel c:
li $v0, 5
syscall
add $t2, $v0, $zero #guarda em t2 o valor de c

slt $t3, $t0, $t1 #compara se a<b, se verdade, coloca 1 no t3, caso contrario coloca 0
slt $t4, $t1, $t2 #compara se b<c, se verdade, coloca 1 no  t4, caso contrario coloca 0
add $t3, $t3, $t4 #soma os resultados da comparaçao e guarda em t3

beq $t3, $zero, NO
li $v0, 4
la $a0, str4
syscall

NO:#return 0
li $v0, 10
syscall

