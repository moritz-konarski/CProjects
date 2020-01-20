	.file	"bitmask.c"
	.text
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"Please enter one number!"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, %eax
	movq	%rsi, -32(%rbp)
	movb	%al, -20(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	cmpb	$2, -20(%rbp)
	jne	.L2
	movl	$0, -12(%rbp)
	movq	-32(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	leaq	-12(%rbp), %rdx
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_sscanf@PLT
	movw	$1, -16(%rbp)
	movw	$31, -14(%rbp)
	jmp	.L3
.L7:
	movl	-12(%rbp), %edx
	movswl	-14(%rbp), %eax
	movl	%eax, %ecx
	shrl	%cl, %edx
	movl	%edx, %eax
	andl	$1, %eax
	testl	%eax, %eax
	je	.L4
	movl	$49, %edi
	call	putchar@PLT
	jmp	.L5
.L4:
	movl	$48, %edi
	call	putchar@PLT
.L5:
	movzwl	-16(%rbp), %eax
	leal	1(%rax), %edx
	movw	%dx, -16(%rbp)
	andl	$3, %eax
	testw	%ax, %ax
	jne	.L6
	movl	$32, %edi
	call	putchar@PLT
.L6:
	movzwl	-14(%rbp), %eax
	subl	$1, %eax
	movw	%ax, -14(%rbp)
.L3:
	cmpw	$0, -14(%rbp)
	jns	.L7
	movl	$10, %edi
	call	putchar@PLT
	jmp	.L8
.L2:
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
.L8:
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L10
	call	__stack_chk_fail@PLT
.L10:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 9.1.0"
	.section	.note.GNU-stack,"",@progbits
