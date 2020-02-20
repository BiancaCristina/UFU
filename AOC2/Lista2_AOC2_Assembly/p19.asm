	.data
M1:	.asciiz "Digite um valor n = "
F1:	.asciiz "\nSomatorio = "
	.globl main
	.text
	
main:
	li $v0, 4			# Printa string
	la $a0, M1			# Printa a string M1
	syscall
	
	li $v0, 5			# Le inteiro
	syscall
	
	move $s0, $v0 			# $s0 = $v0 = n
	
	xor $t0, $t0, $t0 		# Faz $t0 = 0 (variavel i)
	xor $s1, $s1, $s1		# Faz $s1 = 0 (variavel pra guardar a soma)
	
	jal somatorio			# Chama a funcao pra calcular o somatorio
	la $t6, 0($v0)			#
	j encerra
	
somatorio:
	beq $s0, $zero, fimSomatorio	# Se n==0, entao sai do loop
	add $s1, $s1, $s0		# Faz $s1 = $s1 + $s0 (soma += n)
	addi $s0, $s0, -1		# Faz $s0 = $s0 - 1 (n--)
	j somatorio			# Volta pro loop
	
fimSomatorio:	
	jr $ra				# Volta pra linha que o chamou (main)
	
encerra:
	li $v0, 4			# Printa string
	la $a0, F1			# Printa a string F1
	syscall
	
	li $v0, 1			# Printa inteiro
	la $a0, ($s1)			# Printa o valor final do somatorio
	syscall
	
	li $v0, 10			# Encerra o programa
	syscall
