	.data
#part 2
n:	.word 25
#part 3
str1:	.asciiz "Less\n"
str2:	.asciiz "Less than or equal to\n"
str3:	.asciiz "Greater than\n"
str4: 	.asciiz "Greater than or equal to\n"

	.text	
	
	la $t0, n
	lw $s0, 0($t0)
	
	#part 4
	li $v0, 5
	syscall
	move $t0, $v0
	
	#part 5
	li $t1, 0
	slt $t1, $t0, $s0
	bne $t1, $0, LESS
	beq $t1, $s0, GEQ
	j GEQ
	
	#slt $t1, $t0, $t0
	#bne $t1, $zero, GREAT
	#beq $t1, $t0, LEQ
	#j finish 
LESS:	li $v0, 4
	la $a0, str1
	syscall
	j finish
	
GEQ:	li $v0,4
	la $a0, str4
	syscall
	j finish

GREAT:	li $v0,4
	la $a0, str3
	syscall
	j finish
	
LEQ:	li $v0, 4
	la $a0, str2
	syscall
	
	j finish
	
finish:	li $v0, 10
	syscall
