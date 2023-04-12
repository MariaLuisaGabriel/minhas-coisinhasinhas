# uso de aula7 como arquivo de macros, e aqui como main

.include "aula7.asm"

.data
	buff: .space 128 #separando 128 bytes em buff
	str1: .asciiz "\n"

.text
    # :)
    # uso das macros
    # printStr(str1)
    readStr(buff, 11)
    printStr(str1)
    printStr(buff)
    readInt($t0)
    printInt($t0)
   
    return0
