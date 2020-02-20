	.data
QUEBRA:	.asciiz "\n"
F1:	.asciiz "Quantidade de impares = "
array:	.word 0:100
size: 	.word 100

	.globl main
	.text

main:
	# Funcao principal
	la $a0, array		# $a0 = endereco do array
	lw $t0, size($zero)	# $t0 = size
	xor $t1, $t1, $t1	# $t1 = 0 (variavel i)
	addi $t2, $t2, 1	# $t2 = 1 (variavel que vai povoar o array)
	xor $t3, $t3, $t3	# #t3 = 0 (variavel que vai contar bytes de 4 em 4)
	xor $t7, $t7, $t7	# $t7 = 0 (variavel que vai guardar a quantidade de impares)
	jal povoaArray		# Chama a funcao que vai preencher o array
	la $t6, 0($v0)		# Salva retorno
	jal verificaImpares	# Chama a funcao que vai contar quantos valores impares tem no array
	la $t9, 0($v0)		# Salva retorno
	j encerra		# Chama a funcao que vai encerrar o programa

###################### PREENCHENDO O ARRAY ######################
povoaArray:
	# Essa funcao povoa o array com valores sequenciais 1,2,3,4...
	beq $t0, $t1, fimLoop1	# Caso $t1 == size, sai do loop
	sw $t2, array($t3)	# Faz array($t3) = $t2
	addi $t3, $t3, 4	# Incrementa $t3 em 4 unidades 
	addi $t1, $t1, 1	# Faz i++
	addi $t2, $t2, 1	# Faz $t2++
	j povoaArray
	
fimLoop1:
	# Volta pra main
	jr $ra
##############################################################################################################

###################### CONTANDO OS VALORES IMPARES ######################
verificaImpares: 
	# Essa funcao vai contar a quantidade de impares no array
	xor $t1, $t1, $t1	# $t1 = 0 (variavel i)
	xor $t3, $t3, $t3	# #t3 = 0 (variavel que vai contar bytes de 4 em 4)
	j loop2
	
loop2:
	# Esse loop verifica quais valores do vetor sao impares e faz o devido tratamento
	beq $t0, $t1, fimLoop2 	# Caso $t1 == size, sai do loop
	
	lw $t4, array($t3)	# $t4 = array($t3)
	
	andi $t5, $t4, 1	# Faz $t4&1, se for par $t5=0, se for impar $t5=1
	beq $t5, 1, ehImpar	# Caso seja impar, pula pro label ehImpar
	
	addi $t3, $t3, 4	# Incrementa $t3 em 4 unidades (contador de bytes)
	addi $t1, $t1, 1	# i++
	
	j loop2			# Volta pro loop2
	
ehImpar:
	# Essa funcao incrementa a quantidade de impares
	addi $t7, $t7, 1	# Faz $t7++ (contador de impares)
	addi $t3, $t3, 4	# Incrementa $t3 em 4 unidades (contador de bytes)
	addi $t1, $t1, 1	# i++
	j loop2			# Volta pro loop2

fimLoop2:
	# Volta pro main
	jr $ra
########################################################################################

###################### FIM DO PROGRAMA ###################### 		
encerra:
	# Essa funcao vai imprimir o contador de impares e finalizar o programa
	li $v0, 4		# Printa string
	la $a0, F1		# Printa a string F1
	syscall
	
	li $v0, 1		# Printa inteiro
	la $a0, ($t7)		# Printa o contador de impares
	syscall
	
	li $v0, 10		# Encerra o programa
	syscall