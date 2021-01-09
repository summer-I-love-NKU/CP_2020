# Simple C Complier created by Shen Zhe, 2021.1

#*********************************** AST ***********************************
#        Node Type         Node Info                   Children
#0 |  @0   prog                                     children: @0 -> [ @1 @4 ]  
#1 |  @1   stmt         stmt_type: decl var         children: @1 -> [ @2 ]  
#1 |  @2   type              type: int              children: @2 -> [ @3 ]  
#1 |  @3   var           var_name: help             
#0 |  @4   func                                     children: @4 -> [ @5 ]  
#14|  @5   block                                    children: @5 -> [ @6 @9 @13 @16 ]  
#14|  @6   stmt         stmt_type: decl var         children: @6 -> [ @7 ]  
#14|  @7   type              type: int              children: @7 -> [ @8 ]  
#14|  @8   var           var_name: a                
#15|  @9   stmt         stmt_type: assign           children: @9 -> [ @10 @11 ]  
#15|  @10  var           var_name: a                
#15|  @11  expr         expr_type: 0-               children: @11 -> [ @12 ]  
#15|  @12  const       const_type: int              const_value: 2    
#16|  @13  stmt         stmt_type: decl var         children: @13 -> [ @14 ]  
#16|  @14  type              type: int              children: @14 -> [ @15 ]  
#16|  @15  var           var_name: b                
#17|  @16  stmt         stmt_type: assign           children: @16 -> [ @17 @18 ]  
#17|  @17  var           var_name: b                
#17|  @18  stmt         stmt_type: assign           children: @18 -> [ @19 @20 ]  
#17|  @19  var           var_name: a                
#17|  @20  const       const_type: int              const_value: 99    


#*********************************** ASM CODE ***********************************
# Simple C Complier created by Shen Zhe, 2021.1
	.file  "test.c"
.section	.rodata

.data
	.align 4
	.type	help, @object
	.size	help, 4
help:
	.long	0

	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	0

	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	0



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


	movl	$-2, %eax
	movl	%eax, a
	movl	$99, a
	movl	a, %eax
	movl	%eax, b

	movl	$0, %eax
	movl	-4(%ebp), %ecx
	leave
	leal	-4(%ecx), %esp
	ret
.LFE0:
	.size	main, .-main

.ident		"Simple_C_Complier_ShenZhe: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
.section	.note.GNU-stack,"",@progbits
