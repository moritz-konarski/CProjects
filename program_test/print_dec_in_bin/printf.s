	.file	"printf.c"
	.text
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"%08x"
.LC2:
	.string	"0000 "
.LC3:
	.string	"0001 "
.LC4:
	.string	"0010 "
.LC5:
	.string	"0011 "
.LC6:
	.string	"0100 "
.LC7:
	.string	"0101 "
.LC8:
	.string	"0110 "
.LC9:
	.string	"0111 "
.LC10:
	.string	"1000 "
.LC11:
	.string	"1001 "
.LC12:
	.string	"1010 "
.LC13:
	.string	"1011 "
.LC14:
	.string	"1100 "
.LC15:
	.string	"1101 "
.LC16:
	.string	"1110 "
.LC17:
	.string	"1111 "
.LC18:
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
	subq	$64, %rsp
	movl	%edi, %eax
	movq	%rsi, -64(%rbp)
	movb	%al, -52(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	cmpb	$2, -52(%rbp)
	jne	.L2
	leaq	-20(%rbp), %rax
	movq	%rax, -32(%rbp)
	movl	$0, -36(%rbp)
	movq	-64(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	leaq	-36(%rbp), %rdx
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_sscanf@PLT
	movl	-36(%rbp), %edx
	leaq	-20(%rbp), %rax
	leaq	.LC1(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	sprintf@PLT
	jmp	.L3
.L22:
	movq	-32(%rbp), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$54, %eax
	ja	.L4
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L6(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L6(%rip), %rdx
	addq	%rdx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L6:
	.long	.L21-.L6
	.long	.L20-.L6
	.long	.L19-.L6
	.long	.L18-.L6
	.long	.L17-.L6
	.long	.L16-.L6
	.long	.L15-.L6
	.long	.L14-.L6
	.long	.L13-.L6
	.long	.L12-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L4-.L6
	.long	.L11-.L6
	.long	.L10-.L6
	.long	.L9-.L6
	.long	.L8-.L6
	.long	.L7-.L6
	.long	.L5-.L6
	.text
.L21:
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L20:
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L19:
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L18:
	leaq	.LC5(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L17:
	leaq	.LC6(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L16:
	leaq	.LC7(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L15:
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L14:
	leaq	.LC9(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L13:
	leaq	.LC10(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L12:
	leaq	.LC11(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L11:
	leaq	.LC12(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L10:
	leaq	.LC13(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L9:
	leaq	.LC14(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L8:
	leaq	.LC15(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L7:
	leaq	.LC16(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L5:
	leaq	.LC17(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
.L4:
	addq	$1, -32(%rbp)
.L3:
	movq	-32(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L22
	movl	$10, %edi
	call	putchar@PLT
	jmp	.L23
.L2:
	leaq	.LC18(%rip), %rdi
	call	puts@PLT
.L23:
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L25
	call	__stack_chk_fail@PLT
.L25:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 9.1.0"
	.section	.note.GNU-stack,"",@progbits
