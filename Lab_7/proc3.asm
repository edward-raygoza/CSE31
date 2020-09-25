	.data
	.text
	
MAIN:
	addi $s0, $zero, 5# s0 = 5
	addi $s1, $zero, 10# s1 = 10
	
	addi $a0, $zero, 5
	addi $a1, $zero, 10
	
	jal SUM
	
	add $s1, $s0, $1
	add $s1, $s1, $v0
	
	add $a0, $s1, $zero
	li $v0, 1
	syscall
	li $v0, 10
	syscall
	
	

SUM:
	# prologue
	addi $sp, $sp, -20
	sw $a0, 0($sp)
	sw $a1, 4($sp)
	sw $s0, 8($sp)
	sw $s1, 12($sp)
	sw $ra, 16($sp)
	
	# body
	# call sub with args 10+1 and 5+1
	# sub(11, 6), need a0 = 11, and a1 = 6
	addi $t0, $a0, 1
	addi $t1, $a1, 1
	add $a0, $t0, $zero
	add $a1, $t1, $zero
	jal SUB
	add $s0, $v0, $zero # p = sum(n+1, m+1)
	
	# get q = sum(m-1, n-1)
	lw $t0, 0($sp)
	lw $t1, 4($sp)
	addi $a0, $t0, -1
	addi $a1, $t1, -1
	jal SUB
	add $s1, $v0, $zero
	
	# return p + q, or s0 + s1
	add $v0, $s0, $s1
	
	# epilogue
	lw $a0, 0($sp)
	lw $a1, 4($sp)
	lw $s0, 8($sp)
	lw $s1, 12($sp)
	lw $ra, 16($sp)
	addi $sp, $sp, 20
	
	jr $ra

SUB:
	sub $v0, $a1, $a0
	jr $ra