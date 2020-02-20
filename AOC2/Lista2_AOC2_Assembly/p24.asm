	.data
QUEBRA:	.asciiz "\n"
M1:	.asciiz "Digite um valor para n = "
F1:	.asciiz "\nFib(n) = "
	
	.globl main
	.text
	
main:
	li $v0, 4			# Printa string
	la $a0, M1			# Printa a string M1
	syscall
	
	li $v0, 5			# Le o inteiro digitado para n
	syscall
	
	move $s0, $v0			# Armazena n em $s0
	
	jal calcula_fib 		# Chama a funcao que calcula o fibonacci
	la $t6, 0($v0)			# Salva o retorno
	j encerra			# Chama a funcao que encerra o programa
	
###################### CALCULANDO O FIB(n) ######################
calcula_fib:
	# Essa funcao calcula o fibinonacci
	addi $t0, $t0, 1		# Faz $t0 = 1 (variavel i)
	addi $t1, $t1, 1		# Faz $t1 = 1 (variavel j)
	addi $s1, $s1, 1		# Faz $s0 = 1 (variavel fib)
	
	beq $s0, $zero, casobase1	# Se n == 0, vai pra casobase1
	beq $s0, 1, casobase2		# Se n == 1, vai pra casobase2
	
	addi $s0, $s0, -2		# Faz $s0 = $s0 - 2 (n -= 2)
	
	j loop1				# Vai pro loop1
loop1:
	beq $s0, $zero, fimLoop1	# Quando n == 0, vai pro fimLoop1 
	
	add $s1, $t0, $t1		# Faz $s0 = $t0 + $t1 (fib = i + j)
	add $t1, $t0, $zero		# Faz $t1 = $t0 (j = i)
	add $t0, $s1, $zero		# Faz $t0 = $s0 (i = fib)
	
	addi $s0, $s0, -1		# n--
	
	j loop1
	
casobase1:
	# Label para quando n==0
	addi $s1, $s1, 0		# Se n==0, fib==0
	j fimLoop1			# Pula pro label fimLoop
	
casobase2:
	# Label para quando n==1
	addi $s1, $s1, 1		# Se n==1, fib=1
	j fimLoop1			# Pula pro label fimLoop
	
fimLoop1:
	# Esse label faz voltar pra main
	jr $ra
	
###################### ENCERRANDO O PROGRAMA ######################
encerra:
	li $v0, 4			# Printa string
	la $a0, F1			# Printa a string F1
	syscall
	
	li $v0, 1			# Printa inteiro
	la $a0, ($s1)			# Printa o valor de fib(n)
	syscall 
	
	li $v0, 10			# Encerra o programa
	syscall