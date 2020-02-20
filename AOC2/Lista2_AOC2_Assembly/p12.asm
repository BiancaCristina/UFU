.data 
	M1: .asciiz "\nDigite um valor inteiro positivo para n = "
	T0: .asciiz "\n$t0 = "
	T1: .asciiz "\n$t1 = "
.text
	li $v0, 4                      # Printa string
	la $a0, M1                     # Printa M1
	syscall
	
	li $v0, 5                      # Le o inteiro n e o armazena em $v0
	syscall
	
	move $a0, $v0                  # Move o que ta em $v0 para $a0
	
	begin: 
		addi $t0, $zero, 0     # Faz com que o conteudo de $t0 = 0 + 0 = 0
		addi $t1, $zero, 1     # Faz com que o conteudo de $t1 = 0 + 1 = 1
		 
	loop:  
		slt $t2, $a0, $t1      # Se $a0 < $t1 entao $t2 = 1, caso contrario $t2 = 0
		bne $t2, $zero, finish # Se $t2 for diferente de 0, vai pra finish 
		add $t0, $t0, $t1      # Faz $t0 = $t0 + $t1
		addi $t1, $t1, 2       # Faz $t1 = $t1 + 2 
		j loop                 # Volta pro inicio do loop 
	
	finish: 
		add $v0, $t0, $zero    # Faz $v0 = $t0 + 0 
		
		# Logo, a explicacao sucinta para o que esse programa calcula eh que:
		# Enquanto o valor armazenado em $a0 for menor que o conteudo de $t1, ocorrera o seguinte:
			# $t0 sera sempre somado a ele mesmo + $t1
			# $t1 sera acrescido em 2 unidades
			