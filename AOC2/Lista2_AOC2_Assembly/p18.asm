	.data
QUEBRA: .asciiz "\n\n"
M1:	.asciiz "Digite um valor para a = "
M2:	.asciiz "\nDigite um valor para b = "
F1: 	.asciiz "\nNovo valor de a = "
F2:	.asciiz "\nNovo valor de b = "

	.globl main
	.text
	
main:
	li $v0, 4		# Pede pro usuario digitar um valor para a
	la $a0, M1     		# Imprime a mensagem M1
	syscall			# Systemcall	
	
	li $v0, 5		# Le o inteiro digitado	
	syscall			# Systemcall	
	
	move $t0, $v0		# Faz $t0 = $v0 = a
	
	li $v0, 4		# Pede pro usuario digitar um valor para b
	la $a0, M2		# Imprime a mensagem M2
	syscall			# Systemcall
	
	li $v0, 5		# Le o inteiro digitado
	syscall			# Systemcall
	
	la $a0, ($t0)		# $a0 = &$t0 = &a
	la $a1, ($v0)		# $a1 = &$v0 = &b
	
swap:
	# Faz a troca de valores de a e b
	addi $sp, $sp, -8	# Cria pilha com 8 bytes (2 posicoes)
	sw $a0, 0($sp)		# Posicao 1 da pilha = a
	sw $a1, 4($sp)		# Posicao 2 da pilha = b
	lw $a0, 4($sp)		# &a0 = 4($sp) = b
	lw $a1, 0($sp)		# &a1 = 0($sp) = a
	
	move $t0, $a0		# $t0 = $a0 (para fins de impressao)
	move $t1, $a1		# $t1 = $a1 (para fins de impressao)
	
	li $v0, 4		# Printa uma string
	la $a0, QUEBRA		# Printa a string QUEBRA	
	syscall
	
	li $v0, 4		# Printa string
	la $a0, F1		# Printa a string F1
	syscall
	
	li $v0, 1		# Printa inteiro
	la $a0, ($t0)		# Printa o valor de a
	syscall
	
	li $v0, 4		# Printa string
	la $a0, F2		# Printa a string F2
	syscall
	
	li $v0, 1		# Printa inteiro
	la $a0, ($t1)		# Printa o valor de b
	syscall
	
	li $v0, 10		# Encerra o programa
	syscall
			
	
	