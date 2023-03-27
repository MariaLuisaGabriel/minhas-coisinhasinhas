#DESC: z = a+2b^2+3c3+4d^4,onde a,b,c,d sao lidos do teclado

.data
  
.text
    #le a
    li $v0, 5 #li = load immediate
    syscall
    add $s0, $zero, $v0
    
    #le b
    li $v0, 5 #li = load immediate
    syscall
    add $s1, $zero, $v0
    
    #le c
    li $v0, 5 #li = load immediate
    syscall
    add $s2, $zero, $v0
    
    #le d
    li $v0, 5 #li = load immediate
    syscall
    add $s3, $zero, $v0

    #operaçoes de b
    mult $s1, $s1 #multiplicando b com b, o dado é guardado em high/low (no caso ta no low, pq n vamo bota numero mt grande)
    mflo $t1 #move from low pra um registrador temporario
    sll  $t1, $t1, 1 #move os bits que representam b em uma casa para a esquerda (isso equivale a multiplicar por 2)
    #em t1 está 2b²
    
    #operaçoes de c
    mult $s2, $s2 #c^2
    mflo $t2 
    mult $s2, $t2 #c^3
    mflo $t2
    li $t7,3
    mult $t2, $t7
    mflo $t2 #3c^3
    #em t2 está 3c³
    
    #operaçoes em d
    mult $s3, $s3 #d^2
    mflo $t3
    mult $t3, $t3 #d^4
    mflo $t3
    sll $t3, $t3, 2 #4d^4
    #em t3 está 4d^4
    
    #operaçao com a,b,c,d
    add $t0, $s0, $t1 #a+2b^2
    add $t0, $t0, $t2 #a+2b^2+3c^3
    add $t0, $t0, $t3 #a+2b^2+3c^3+4d^4
    
    #escrever o resultado
    li $v0, 1 #print integer = 1
    add $a0, $zero, $t0 #pode trocar por move $a0, $t0
    syscall 
    
    #return 0
    li $v0, 10 #equivale a addi $v0, $zero, 10
    syscall 