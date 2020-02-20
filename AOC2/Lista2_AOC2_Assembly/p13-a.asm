.data

.text
	begin:
		addi $t0, $zero,0       # Faz $t0 = 0 (variavel i)
		addi $t1, $zero,-1      # Faz $t1 = -1 (variavel j)
		addi $t4, $zero, 10     # Faz $t4 = 10 (variavel temporaria pra controlar o loop)
		
	loop:
		slt $t2, $t0, $t4       # Caso $t0 < 10 entao $t2=1, do contrario $t2=0
		beq $t2, $zero, finish  # Caso $t2=0 vai pra finish (porque $10 < 10)
		andi $t2, $t0, 1        # Faz $t0&1, se for par $t2=0, do contrario $t2=1
		beq $t2, 1, soma        # Caso seja impar, pula pra soma
		addi $t0,$t0,1          # Incrementa o $t0 (variavel i)
		j loop
 	soma:
 		add $t1, $t1, $t0       # Faz $t1 = $t1 + $t0 (j+= i)
 		addi $t0,$t0,1          # Incrementa o $t0 (variavel i)
 		j loop
 		
	finish:		
		li $v0, 10
		syscall