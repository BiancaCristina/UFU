# Alternativa a) da questao 7)

.data
	M1: .asciiz "Digite um valor a = "
	M2: .asciiz "\nDigite um valor b = "
	Q:  .asciiz"\n\n\n"
	F1: .asciiz "Nao eh menor nem igual"
	F2: .asciiz "Eh menor ou igual"
.text
	# Pede para que o usuario digite um valor para a
	li $v0, 4
	la $a0, M1
	syscall
	
	# Le o inteiro
	li $v0, 5
	syscall 
	
	# Armazena o valor lido em $t3
	move $t3, $v0
	
	# Pede para que o usuario digite um valor para b
	li $v0, 4
	la $a0, M2
	syscall
	
	# Le o inteiro
	li $v0, 5
	syscall
	
	# Armazena o valor lido em $t5
	move $t5, $v0
	
	menor:
		sgt $t0, $t3, $t5 # Se $t3 > $t5 entao $t0 = 1, do contrario $t0=0
		bne $t0, $zero, falso # Caso $t0=0, nao eh menor nem igual
		li $v0, 4
		la $a0, F2
		syscall
		
		li $v0, 10 # Encerra o programa
		syscall
		
	falso:
		li $v0, 4
		la $a0, F1
		syscall
		
		li $v0, 10 # Encerra o programa
		syscall
