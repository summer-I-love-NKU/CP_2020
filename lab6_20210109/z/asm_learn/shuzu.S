	.file	"test.c"

.bss
	.comm	bss_test,4
	.comm	a,48

	.globl	b

.data
	.align 32
	.type	b, @object
	.size	b, 40
b:
    .long	1
    .long	2
    .long	3
    .long	4
    #.zero	24


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
	movl	$100, bss_test
	movl	$23223, a+4
	movl	$112345, b
	movl	b+36, %eax
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
