.data 
	M1: .asciiz "Valor de a = "
	M2: .asciiz "\nValor de b = "
	Q: .asciiz "\n\n\n"
.text
	# Printa a mensagem M1
	li $v0, 4  
	la $a0, M1
	syscall
	
	# Salva o valor lido em $s0
	li $v0, 5
	syscall
	
	move $s0, $v0
	
	# Printa a mensagem M2
	li $v0, 4
	la $a0, M2
	syscall
	
	# Salva o valor lido em $s2
	li $v0, 5
	syscall
	
	move $s2, $v0
	
	begin:
	
	here:
		seq $t0, $s0, $s2  # Se $s0 == $s3 entao $t0 = 1, do contrario $t0 = 0
		bne $t0, 1, finish # Se $t1 != 1, vai pra finish
		add $s0, $s0, $s0  # Soma $s0 com ele mesmo e salva em $s0
		j finish           # Vai pra finish
	
	finish: 	
		# Printa o valor de s0 e s2
		li $v0, 4
		la $a0, Q
		syscall
	
		li $v0, 4
		la $a0, M1
		syscall 
	
		li $v0, 1
		move $a0, $s0
		syscall
	
		li $v0, 4
		la $a0, M2
		syscall
	
		li $v0, 1
		move $a0, $s2
		syscall
	
	
	
	
	
