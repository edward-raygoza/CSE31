	.data
	
prompt: .asciiz  "Please enter an integer"
	
	.text
	
MAIN:	addi $sp, $sp, -4
	#prompts the user to enter input
	li $v0, 4
	la $a0, prompt
	syscall
	#gets number entered
	li $v0, 5
	syscall
	#stores the result in a0
	move $a0, $v0
	addi $v0, $zero, 0
	
	#recursion
	jal recursion
	
	#return value
	sw $v0, 0($sp)
	lw $a0, 0($sp)
	
	li $v0,1
	syscall
	
	j end
	
recursion:	
	#Pushing stack frame for local storage
	addi $sp, $sp, -12	
	#stores retrun address in stack frame
	sw $ra, 8($sp)
	
	#checking if m is eqal to 10
	addi $t0, $zero, 10
	bne $t0, $a0, not_ten
	
	addi $v0, $v0,2
	j end_recursion
	
not_ten:
	#checking if m is eqal to 11
	addi $t0, $zero, 11
	bne $t0, $a0, not_eleven
	addi $v0, $v0,1
	
	j end_recursion
	
not_eleven:
	sw $a0, 4($sp)
	#m+2
	addi $a0, $a0, 2
	#recursion m+2 and load the first return val
	jal recursion
	lw $a0, 4($sp)
	
	#recursion m+1 
	addi $a0,$a0,1
	jal recursion
	
	#loading 1st value
	lw $a0, 4($sp)
	add $v0, $v0, $a0
	
	j end_recursion
	
end_recursion:
	#returns value retrieved of program to main
	lw $ra, 8($sp)
	#pop stack frame and return address
	addi $sp, $sp, 12
	jr $ra
	
end:
	#pop stack frame
	addi $sp, $sp 4
	li $v0, 10
	syscall
	