	.arch msp430g2553
	.data
	.align 2
	 
Jt:
	.word zero
	.word one
	.word two
	.word three
	.word four
	.word five
	.word six
	.word seven
	.word eight
	.word nine
	.word ten
	.word eleven
	.word twelve
	.word thirteen
	.word fourteen
	.word fifteen
	.word exit

	.extern toggle_red()
	.extern toggle_green()
	.extern buzzer_set_period()
	.text
	.align 2
	.global route3
	.word route3
route3:
	
	mov R12, R13
	add R13,R13
	
	mov Jt(R13),R0

zero:
	call #toggle_green
	jmp exit
one:
	call #toggle_red
	mov #1000, R12
	call #buzzer_set_period
	jmp exit
two:
	jmp exit
three:
	call #toggle_green
	call #toggle_red
	mov #5000, R12
	call #buzzer_set_period
	jmp exit
four:
	call #toggle_red
	jmp exit
five:
	jmp exit
six:
	call #toggle_green	
	jmp exit
seven:
	call #toggle_red
	jmp exit
eight:
	jmp exit
nine:
	call #toggle_green
	call #toggle_red
	jmp exit
ten:
	call #toggle_red
	jmp exit
eleven:
	mov #4000, R12
	call #buzzer_set_period
	jmp exit
twelve:
	jmp exit
thirteen:
	call #toggle_green
	jmp exit
fourteen:
	jmp exit
fifteen:
	call #toggle_red
	mov #0, R12
	call #buzzer_set_period
exit:
	ret
	
