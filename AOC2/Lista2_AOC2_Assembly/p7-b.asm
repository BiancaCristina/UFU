# Alternativa b) da questao 7)

.data
	M1: .asciiz "Digite um valor a = "
	M2: .asciiz "\nDigite um valor b = "
	Q:  .asciiz"\n\n\n"
	F1: .asciiz "Eh maior"
	F2: .asciiz "Nao eh maior"
.text
	# Pede para que o usuario digite um valor para a
	li $v0, 4
	la $a0, M1
	syscall
	
	# Le o inteiro
	li $v0, 5
	syscall 
	
	# Armazena o valor lido em $t4
	move $t4, $v0
	
	# Pede para que o usuario digite um valor para b
	li $v0, 4
	la $a0, M2
	syscall
	
	# Le o inteiro
	li $v0, 5
	syscall
	
	# Armazena o valor lido em $t5
	move $t5, $v0
	
	maior:
		sgt $t0,$t4,$t5          # Se $t4 > $t5 entao $t0=1, do contrario $t0=0
		bne $t0,$zero,verdadeiro # Se $t0 != 0 entao eh maior e pula pra label verdadeiro
		li $v0, 4
		la $a0, F2
		syscall
		
		li $v0, 10 # Encerra o programa
		syscall
		
	verdadeiro:
		li $v0, 4
		la $a0, F1
		syscall
		
		li $v0, 10 # Encerra o programa
		syscall