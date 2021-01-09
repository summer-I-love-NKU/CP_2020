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
	.align 32
	.type	a, @object
	.size	a, 40
a:
	.zero	40
	.section	.rodata
.LC0:
	.string	"%d\n"
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
	movl	$0, -12(%ebp)
.L3:
	cmpl	$9, -12(%ebp)
	jg	.L2
	movl	-12(%ebp), %eax
	leal	1(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, a(,%eax,4)
	movl	-12(%ebp), %eax
	movl	a(,%eax,4), %eax
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	addl	$1, -12(%ebp)
	jmp	.L3
.L2:
	movl	$0, %eax
	movl	-4(%ebp), %ecx
	leave
	leal	-4(%ecx), %esp
	ret
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
