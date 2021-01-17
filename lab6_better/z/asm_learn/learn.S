.file	"test.c"

#随处放即可


.section	.rodata
.LC0:
	.string	"%d\n"
.LC1:
	.string	"wwwwww\n"
#*************************************************************************
.text
	.globl	main
	.type	main, @function
main:
.LFB0:
													#leal	4(%esp), %ecx
													#andl	$-16, %esp
													#pushl	-4(%ecx)
#ia32中程序中用了ebx、esi、edi时，结束时必须还原（程序开始时也必须保存）
#因为这三个是被调用者负责保存的寄存器；

#而eax、edx、ecx则不必还原，因为这三个是调用者保存的寄存器
#所以优先使用eax、edx、ecx可减少程序开始和结束时的开销



	pushl	%ebp
	movl	%esp, %ebp
									#pushl	%ecx		#保存和恢复%ecx寄存器

									#subl	$4, %esp
	movl	a, %edx
	movl	b, %eax
	addl	%eax, %edx
	movl	c, %eax
	addl	%edx, %eax
	movl	%eax, d


	movl	$30, e



	movl	d, %eax
				#subl	$8, %esp
	pushl	%eax
	pushl	$.LC0
	call	printf
											#addl	$16, %esp#???????????????????????
	
	
	movl	e, %eax
				#subl	$8, %esp
	pushl	%eax
	pushl	$.LC0
	call	printf
												#addl	$16, %esp#?????????????????
	movl	$2021, %eax
				#subl	$8, %esp
	pushl	%eax
	pushl	$.LC0
	call	printf



				#subl	$4, %esp
	pushl	$.LC1
	call	printf

													#movl	$0, %eax
													#movl	-4(%ebp), %ecx
	leave
									#leal	-4(%ecx), %esp#保存和恢复%ecx寄存器
	ret


.LFE0:
	.size	main, .-main






.data

	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	1


	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	4



	.align 4
	.type	c, @object
	.size	c, 4
c:
	.long	6


	.local	d
	.comm	d,4  #,4
	.local	e
	.comm	e,4  #,4


	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits


















	.file	"test.c"
.bss
	.comm	a,4

.data
	.align 4#-----------------?32
	.type	b, @object
	.size	b, 4
b:
    .long	199
    
    .align 4
	.type	c, @object
	.size	c, 4
c:
	.long	499

	.section	.rodata
.LC0:
	.string	"%d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	
	pushl	%ebp
	movl	%esp, %ebp
	subl    $8, %esp
    movl $123456,a
	movl    a,%eax
    pushl   %eax
	pushl	$.LC0
	call	printf
	
	leave
	ret
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
