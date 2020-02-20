# Alternativa c) da questao 7)

.data
	M1: .asciiz "Digite o valor a = "
	M2: .asciiz "\nDigite o valor b = "
	Q: .asciiz "\n\n\n"
	F1: .asciiz "Eh maior"
	F2: .asciiz "Eh menor"
	F3: .asciiz "Eh igual"
	
.text
	# Pede que o usuario digite o valor de a
	li $v0, 4
	la $a0, M1
	syscall
	
	# Le o inteiro digitado
	li $v0, 5
	syscall
	
	# Armazena o inteiro digitado em 0x12345678
	move $t0, $v0
	
	inicio:
		addi $t3, $zero, 0         # Faz com que $t3 = 0 
		
	verificaIgualdade:
		add $t3, $t3, 0x12345678   # Faz $t2 = 0x12345678
		sub $t3, $t3, $t0          # Faz $t2 = 0x12345678 - $t0
		
		sgt $t1, $t3, $zero        # Caso $t3 > 0 entao $t1=1, do contrario $t1=0
		bnez $t1, ehMenor          # Se $t1!=0 entao $t0 < 0x12345678
		
		addi $t2, $zero, 0         # Faz com que $t2 = 0 
		
		li $v0, 10                 # Encerra o programa
		syscall 
   		
	ehMenor:
		# Printa a mensagem dizendo que eh menor
		li $v0,4                   
		la $a0, F2
		syscall
		
		li $v0, 10                 # Encerra o programa
		syscall
		
		

	
	
	