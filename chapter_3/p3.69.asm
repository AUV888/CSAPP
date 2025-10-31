# prototype:
# void test(long i, b_struct *bp)
test:
	mov 0x120(%rsi), %ecx           # last = bp +288
	add (%rsi), %ecx                # first
	lea (%rdi, %rdi, 4), %rax       # rax stores 5*i
	lea (%rsi, %rax, 8), %rax       # rax stores ap, where ap = bp + 40*i
	mov 0x8(%rax), %rdx             # rdx stores ap->idx, where ap->idx = *(ap+8) NOTE: ap has not +8(+first+align) yet!
	movslq %ecx, %rcx               # sign extension of ecx
	mov %rcx, 0x10(%rax, %rdx, 8)   # *(ap + 8 + 8 + 8*rdx) =n
	retq
