.text
void_delay:
	addi $a0, $zero, 3  # int ms, men hur ger jag den inget v�rde?? a0 = 100 // ms
	addi $s0, $zero, 0 # int i		s0 = 0; //i 
	addi $s1, $zero, 5 # random v�rde       s1 = 5; //j 
     loop1:
     	slt $t1, $zero, $a0 # kontrollera om ms > 0   if (0 < a0) // a<ms  
     	beq $t1, $zero, done # �r den < 0 avsluta     if (t1 == 0 ) // g� to done 
     	nop
     	add $a0, $a0, -1 # minska ms med 1 	      a0 = a0 -1 // ms - 1 
     	addi $s0, $zero, 0 # reseta s0 s� du kan loopa igen  s0  = 0; // i  
     loop2:
    	slt $t2, $s0, $s1 # kontrollera om i < random v�rde	s0 < s1 // i  < j;  
     	beq $t2, $zero, loop1 # �r den < forts�tt loop annars hoppa till loop1 // t2 = 0 // g� to loop1 
     	nop
    	add $s0, $s0, 1 # plussa i med 1
    	j loop2
    	nop
     done:
     	j done
    	nop     