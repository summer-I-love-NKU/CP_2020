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
	.local	_ZL1a
	.comm	_ZL1a,4,4
	.local	_ZL1b
	.comm	_ZL1b,4,4
	.local	_ZL1c
	.comm	_ZL1c,4,4
	.local	_ZL1d
	.comm	_ZL1d,4,4
	.local	_ZL1e
	.comm	_ZL1e,4,4
	.section	.rodata
.LC0:
	.string	"%d %d %d %d %d"
.LC1:
	.string	"%d %d %d %d %d\n"
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
	pushl	%esi
	pushl	%ebx
	pushl	%ecx
	subl	$12, %esp
	subl	$8, %esp
	pushl	$_ZL1e
	pushl	$_ZL1d
	pushl	$_ZL1c
	pushl	$_ZL1b
	pushl	$_ZL1a
	pushl	$.LC0
	call	scanf


	addl	$32, %esp
	movl	_ZL1e, %esi
	movl	_ZL1d, %ebx
	movl	_ZL1c, %ecx
	movl	_ZL1b, %edx
	movl	_ZL1a, %eax
	subl	$8, %esp


	pushl	_ZL1e
	pushl	_ZL1d
	pushl	_ZL1c
	pushl	_ZL1b
	pushl	_ZL1a
	pushl	$.LC1
	call	printf
	addl	$32, %esp
	movl	$0, %eax
	leal	-12(%ebp), %esp
	popl	%ecx
	popl	%ebx
	popl	%esi
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
