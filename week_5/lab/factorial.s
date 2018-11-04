.data
n: 		.word 7

.text
main:
		la t0, n
		lw a0, 0(t0)
		jal ra, factorial

		addi a1, a0, 0
		addi a0, x0, 1
		ecall		# Print Result

		addi a0, x0, 10
		ecall		# Exit

factorial:	beq  a0, x0, r1
		addi t0, x0, 1
		beq  a0, t0, r1

            	addi t1, x0, 2

loop:		mul  t0, t1, t0

		beq  t1, a0, exit
            	addi t1, t1, 1
            	j loop

exit:		add a0, t0, x0
		ret

r1:		addi a0, x0, 1
		ret