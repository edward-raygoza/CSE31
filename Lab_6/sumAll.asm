.data
	messageEnter: .asciiz "\nPlease enter a number(Enter 0 to end): "
	posnum: .asciiz "\nSum of positive numbers is: "
	negnum: .asciiz "\nSum of negative numbers is: "
	
	
.text
	#li of negative and positive numbers entered
	li $s0,0 
	li $s1,0
loop:
	li $v0,4
	la $a0, messageEnter
	syscall
	
	li $v0,5
	syscall
	move $t0,$v0
	
	beqz $t0,done
	
	bltz $t0, negativen
	add $s0,$s0,$t0
	j skip
negativen:
	add $s1,$s1,$t0
skip:
	j loop
done:
	li $v0,4
	la $a0,posnum
	syscall
	move $a0,$s0
	li $v0,1
	syscall
	
	li $v0,4
	la $a0,negnum
	syscall
	move $a0,$s1
	li $v0,1
	syscall
	