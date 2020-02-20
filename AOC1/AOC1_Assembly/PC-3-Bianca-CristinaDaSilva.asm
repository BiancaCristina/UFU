#Nome: Bianca Cristina da Silva
#Matricula: 11711BCC023

.data
	MI: .asciiz "Devemos calcular o fatorial de n =  "     #M1 = mensagem inicial
	MF: .asciiz "\nO fatorial de n! eh = "                 #MF = mensagem final
.text
	#Exibe MI
	li $v0, 4
	la $a0, MI
	syscall 
	
	li $v0,5 #Armazena o valor de n em $v0
	syscall
	
	move $t0,$v0 #Guarda o valor de n em t0
	
	.globl main
	
	main:
		li $t1, 1         #t1 = valor inicial do fatorial = 1
		addi $sp,$sp,-4   #Inicia a pilha
		sw $t0,0($sp)     #Salva o valor de n na primeira posicao da pilha
		
		
	calcula_fatorial:
		#Inicia um laco while
		ble $t0, 1, saida  #Realiza o while enquanto n <= 1
		mul $t1,$t1,$t0    #Multiplica o fatorial pelo n atual
		addi $t0,$t0,-1    #Decrementa o n (o qual esta em t0)
		j calcula_fatorial #Volta pro inicio do while
				
	saida:
		#Exibe MF
		li $v0, 4
		la $a0, MF
		syscall
		
		#Exibe o valor do fatorial acoplado à mensagem de saida
		li $v0, 1
		move $a0, $t1
		syscall
		
		#Encerra o programa
		addi $sp, $sp,4 #Libera espaco alocado pra pilha
		li $v0, 10
		syscall
	
		
		
