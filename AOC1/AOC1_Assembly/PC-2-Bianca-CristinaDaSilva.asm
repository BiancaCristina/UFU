#Nome: Bianca Cristina da Silva 
#Matricula: 11711BCC023
.data
	P1: .asciiz "Considerando um polinomio de 2 grau (ax2+bx+c), digite os valores para a,b e c.\n"
	A: .asciiz "a: "
	B: .asciiz "b: "
	C: .asciiz "c: "
	S1: .asciiz "Delta = "

.text
	#Printa o P1 (inicia o programa)
	li $v0,4
	la $a0,P1
	syscall
	
	#Pede pro usuario digitar um valor para a e armazena em t0
	li $v0,4
	la $a0,A
	syscall
	
	li $v0,5
	syscall
	
	move $t0,$v0
	
	#Pede pro usuario digitar um valor para b e armazena em t1
	li $v0,4
	la $a0,B
	syscall
	
	li $v0,5
	syscall
	
	move $t1,$v0
	
	#Pede pro usuario digitar um valor para c e armazena em t2
	li $v0,4
	la $a0,C
	syscall
	
	li $v0,5
	syscall
	
	move $t2,$v0
	
	.globl calculadora_delta
	
	calculadora_delta:
		jal calcula_delta  #Funcao que calcula valor do delta
		la $t6, 0($v0)     #Armazena o valor do delta em t6
		jal imprime_delta  #Funcao que imprime valor do delta
		j encerra_programa #Funcao que calcula o delta
	
	calcula_delta:
		mul $t3,$t1,$t1 #Calculando b^2
		mul $t4,$t0,$t2 #Calculando a*c
		mul $t4,$t4,4   #Calculando 4*a*c
		sub $t5,$t3,$t4 #Calculando b^2 - 4*a*c (delta)
		jr $ra          #Volta para a linha onde foi chamado
		
	imprime_delta:
		#Printa a mensagem de saída
		li $v0,4
		la $a0,S1
		syscall
	
		#Printa o valor do delta acoplado à mensagem de saída
		li $v0,1
		move $a0,$t5
		syscall
		
		jr $ra #Volta para a linha onde foi chamado
	
	encerra_programa:
		li $v0, 10 #Encerra o programa
		syscall	 