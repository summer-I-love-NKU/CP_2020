# Simple C Complier created by Shen Zhe, 2021.1

#*********************************** AST ***********************************
#        Node Type         Node Info                   Children
#0 |  @0   prog                                     children: @0 -> [ @1 @4 @14 ]  
#1 |  @1   stmt         stmt_type: decl var         children: @1 -> [ @2 ]  
#1 |  @2   type              type: int              children: @2 -> [ @3 ]  
#1 |  @3   var           var_name: help             
#2 |  @4   stmt         stmt_type: decl array       children: @4 -> [ @5 ]  
#2 |  @5   type              type: int              children: @5 -> [ @6 ]  
#2 |  @6   array       array_name: a0               children: @6 -> [ @7 @8 ]  
#2 |  @7   const       const_type: int              const_value: 5    
#2 |  @8   stmt         stmt_type: block            children: @8 -> [ @9 @10 @11 @12 @13 ]  
#2 |  @9   const       const_type: int              const_value: 1    
#2 |  @10  const       const_type: int              const_value: 2    
#2 |  @11  const       const_type: int              const_value: 3    
#2 |  @12  const       const_type: int              const_value: 0    
#2 |  @13  const       const_type: int              const_value: 0    
#0 |  @14  func                                     children: @14 -> [ @15 ]  
#4 |  @15  block                                    children: @15 -> [ @16 @20 @24 ]  
#4 |  @16  stmt         stmt_type: decl var         children: @16 -> [ @17 ]  
#4 |  @17  type              type: int              children: @17 -> [ @18 ]  
#4 |  @18  var           var_name: a                children: @18 -> [ @19 ]  
#4 |  @19  const       const_type: int              const_value: 1    
#5 |  @20  stmt         stmt_type: printf           children: @20 -> [ @21 @22 ]  
#5 |  @21  const       const_type: string           const_value: "%d"    
#5 |  @22  block                                    children: @22 -> [ @23 ]  
#5 |  @23  array       array_name: a0               
#6 |  @24  stmt         stmt_type: return           children: @24 -> [ @25 ]  
#6 |  @25  const       const_type: int              const_value: 0    


#*********************************** ASM CODE ***********************************
# Simple C Complier created by Shen Zhe, 2021.1
	.file  "test.c"
.section	.rodata
.LC0:
	.string	"%d"

.data
	.align 4
	.type	help, @object
	.size	help, 4
help:
	.long	0

	.align 4
	.type	a0, @object
	.size	a0, 20
a0:
	.long	1
	.long	2
	.long	3
	.long	0
	.long	0
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	1


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


	movl	a0+8,%eax
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

.ident		"Simple_C_Complier_ShenZhe: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
.section	.note.GNU-stack,"",@progbits
