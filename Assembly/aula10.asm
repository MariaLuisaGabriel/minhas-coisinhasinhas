#la é uma pseudoinstrucao
#é necessário usar 2 instrucoes para fazer um la, pois o la meche com hexadecimal junto com bits
#la divide em lui e ori
#o lui pega as 4 primeiras casas hexadecimais e guarda nos primeiros 16 bits do registrador de destino
#o ori faz um or desse registrador com as ultimas 4 casas do endereço, guardando no final o endereço inteiro no registrador de destino
#ex: str: 0x11020783
#la $a0, str
#-> lui $at, 0x1102 (at = 11 02 00 00)
#-> ori $a0, $at, 0x0783 (11 02 00 00)
#/////////////////////(or 00 00 07 83)
#X or 0 = X |------->(a0= 11 02 07 83)
#final: a0 = 11 02 07 83

#pseudoinstrucoes notaveis: 
#la a0, address -> lui at, 4 primeiras casas address + ori a0, at, 4 ultimas casas address 
#beq s0, cte, label -> guarda cte num registrador + beq normal c 2 registradores e um label
#not s0, s1 -> nor s0, s1, s1 (not(x+x) = not x)

#Obs cada instrução é reconhecível pelo processador de acordo com um dos seguintes formatos:
#R-type:{OpCode (6 bits)} { rs (5 bits)} { rt (5 bits)} { rd (5 bits)} {shamt(5bit)}{funct(5 bits) } (usado normalmente para funcoes aritmeticas)
#////// 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0 (bits)
#I-type:{OpCode (6 bits)} { rs (5 bits)} { rt (5 bits)} {   address constantes(16 bits)     } (usado normalmente pra funcoes que envolvem immediate)
#////// 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0 (bits)
#J-type:{OpCode (6 bits)} {		  target address(26 bits)        		    } (usado para jump)
#////// 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0 (bits)
# o programa vai guardar essas instrucoes no modo hexadecimal (famosa linguagem de máquina), pegando de 4 em 4 bits registrados no modo R,I ou J.

#OpCode: bits do tipo de operacao
#rs: registrador de entrada 1
#rt: registrador de entrada 2
#rd: registrador de destino
#shamt: shift ammount (serve pro sll e slr (mover bits pra um lado ou pro outro))
#funct: bits da funcao

#obs: func $rd, $rs, $rt -> guardar nos bits: rs, rt, rd (nessa ordem)
#ex: add $t3, $t3, $s7 -> 000000 01011 10111 01011 00000 10000 
#			  opc    rs    rt    rd    shmt  funct
#(t3 = 11, s7 = 23) em hexa: 0000 0001 0111 0111 0101 1000 0010 0000 = 0 1 7 7 5 8 2 0 (0x01775820) //CODIGO DE MAQUINA//

#ex2: sll $t3, $s1, 2 -> 000000 00000 10001 01011 00010 000000 (o rt foi preferido pelo sll, o rs nao foi usado pq so tem um registrador de entrada, e aquele 2 vai pro shamt)
#em hexa: 0000 0000 0001 0001 0101 1000 1000 0000 = 0 0 1 1 5 8 8 0 (0x00115880) //CODIGO DE MAQUINA//

.include "macros.asm"
.data

.text
	return0