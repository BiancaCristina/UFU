	.data
word1:	.word 0x01 0x02 0x03 0x04 0x05 0x06 0x07 0x00	# Palavra inicial
word2:	.word 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00	# Palavra pra guardar a copia

	.globl main
	.text

main:
	la $a0, word1 			# Guarda a palavra inicial em $a0
	la $a1, word2			# Guarda a copia da palavra inicial em $a1
	li $v0, 0			# Inicia o contador de palavras copiadas com 0 (contador = $v0)
loop: 
	lw $v1, ($a0) 			# Faz $v1 = word1[0]
	beq $v1, $zero, fim		# Caso chegue ao final da palavra inicial, sai do loop
	sw $v1, ($a1)			# Faz word2[0] = $v1 = word1[0]
	addi $a0, $a0, 4		# Acrescenta 4 bytes na word1 (palavra inicial)
	addi $a1, $a1, 4		# Acrescenta 4 bytes na word2 (copia)
	addi $v0, $v0, 1		# Faz contador++
	j loop				# Volta pro loop
	
fim:	
	li $v0, 10			# Encerra o programa
	syscall
	