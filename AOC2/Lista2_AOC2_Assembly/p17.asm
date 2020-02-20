	.data
QUEBRA: .asciiz "\n"
M1:     .asciiz "Digite um valor para c = "
A: 	.word 0:100
B:	.word 0:100
n:	.word 100

	.globl main
	.text
	
main:
	xor $t0, $t0, $t0 # $t0 = 0 (variavel i = 0)
	lw $t2, n($zero)  # $t2 = n 
	xor $t3, $t3, $t3 # $t3 = 0 (variavel que vai mudando de 4 em 4 bytes)
	addi $t1, $t1, 1  # $t1 = 1
		
	# Pede pro usuario digitar um valor para c e salva
	li $v0, 4
	la $a0, M1      # Printa a mensagem
	syscall
	
	li $v0, 5       # Le inteiro c
	syscall 
	
	move $s0, $v0   # $s0 = $v0 = c
	addi $s0, $s0, 10 # c = 10
	
	la $a0, A         # $a0 = endereco do vetor A
	la $a1, B         # $a1 = endereco do vetor B
povoaB:
	# Povoar todas as posicoes do vetor B com 1
	beq $t0, $t2, fimB # Se i == n, entao sai do povoaB
	
	sw  $t1, B($t3)    # A($t3) = $t1 = 1
	
	addi $t3, $t3, 4   # Incrementa o $t3 em 4 unidades 
	addi $t0, $t0, 1   # i++
	j povoaB           # Volta pro loop

fimB:
	# Reseta os temporarios e pula pro povoaA
	xor $t0, $t0, $t0 # $t0 = 0 (variavel i)
	xor $t3, $t3, $t3 # $t3 = 0 (variavel pra contar de 4 em 4 bytes)
	xor $t4, $t4, $t4 # $t4 = 0 (variavel temporaria pra salvar os valores)
	j povoaA
povoaA:
	# Fazer A[i] = B[i] + c
	beq $t0, $t2, fimA    # Se i==n, entao sai do povoaA
	
	lw $t4, B($t3)        # $t4 = B($t3)
	
	add $t4, $t4, $s0     # $t4 = B($t3) + c
	
	sw $t4, A($t3)        # A($t3) = $t4 = B[i] + c
	
	addi $t3, $t3, 4      # Incrementa o $t3 em 4 unidades (contagem de 4 em 4 bytes)
	addi $t0, $t0, 1      # i++
	j povoaA              # Volta pro loop
	
fimA:
	# Reseta os temporarios 
	xor $t0, $t0, $t0 # $t0 = 0 
	xor $t3, $t3, $t3 # $t3 = 0
	xor $t4, $t4, $t4 # $t4 = 0
	j imprimeA

imprimeA:
	move $t3, $a0             # $t3 = endereco do vetor A 
	j loopA                   # pula pra loopA
	
loopA: 
	beq $t0, $t2, finaliza    # Se i==n, entao finaliza
	
	li $v0, 1                 # Printa inteiro
	lw $a0, 0($t3)            # Carrega em $a0 o inteiro armazenado em 0($t3)
	syscall
	
	li $v0, 4                 # Printa string
	la $a0, QUEBRA		  # Printa \n
	syscall
	
	addi $t3, $t3, 4	  # Incrementa #t3 em 4 unidades (contador de 4 em 4 bytes)
	addi $t0, $t0, 1	  # i++
	j loopA			  # Volta pro loop
	
finaliza:
	li $v0,10 		  # Encerra o programa
	syscall

	
	
	
	
	
	

	
	
