	.file	"test.cpp"
	.globl	help_me
	.bss
	.align 4
	.type	help_me, @object
	.size	help_me, 4
help_me:
	.zero	4
	.globl	help
	.align 4
	.type	help, @object
	.size	help, 4
help:
	.zero	4
	.globl	a
	.data
	.align 4
	.type	a, @object
	.size	a, 20
a:
	.long	1
	.long	2
	.long	3
	.zero	8
	.section	.rodata
.LC0:
	.string	"%d"
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
	subl	$4, %esp
	movl	a+8, %eax
	subl	$8, %esp
	pushl	%eax
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
