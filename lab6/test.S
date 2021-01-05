	.file	"test.cpp"
	.globl	help_me
	.bss
	.align 4
	.type	help_me, @object
	.size	help_me, 4
help_me:
	.zero	4
	.section	.rodata
.LC0:
	.string	"test:%d %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$20, %esp
	movl	$-100020, -24(%ebp)
	movl	$-3, -20(%ebp)
	movl	-24(%ebp), %eax
	cltd
	idivl	-20(%ebp)
	movl	%eax, -16(%ebp)
	movl	-24(%ebp), %eax
	cltd
	idivl	-20(%ebp)
	movl	%edx, -12(%ebp)
	subl	$4, %esp
	pushl	-12(%ebp)
	pushl	-16(%ebp)
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	movl	$0, %eax
	movl	-4(%ebp), %ecx
	leave
	leal	-4(%ecx), %esp
	ret
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
