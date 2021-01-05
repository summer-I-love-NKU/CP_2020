# Simple C Complier created by Shen Zhe, 2021.1

#*********************************** AST ***********************************
#        Node Type         Node Info                   Children
#0 |  @0   prog                                     children: @0 -> [ @1 @4 ]  
#1 |  @1   stmt         stmt_type: decl var         children: @1 -> [ @2 ]  
#1 |  @2   type              type: int              children: @2 -> [ @3 ]  
#1 |  @3   var           var_name: help             
#0 |  @4   func                                     children: @4 -> [ @5 ]  
#3 |  @5   block                                    children: @5 -> [ @6 ]  
#3 |  @6   stmt         stmt_type: decl array       children: @6 -> [ @7 ]  
#3 |  @7   type              type: int              children: @7 -> [ @8 @10 ]  
#3 |  @8   array       array_name: a                children: @8 -> [ @9 ]  
#3 |  @9   const       const_type: int              const_value: 5    
#3 |  @10  stmt         stmt_type: block            children: @10 -> [ @11 @12 @13 @14 @15 ]  
#3 |  @11  const       const_type: int              const_value: 1    
#3 |  @12  const       const_type: int              const_value: 2    
#3 |  @13  const       const_type: int              const_value: 3    
#3 |  @14  const       const_type: int              const_value: 4    
#3 |  @15  const       const_type: int              const_value: 5    


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


decl array
error!!

	movl	$0, %eax
	movl	-4(%ebp), %ecx
	leave
	leal	-4(%ecx), %esp
	ret
.LFE0:
	.size	main, .-main

.ident		"Simple_C_Complier_ShenZhe: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
.section	.note.GNU-stack,"",@progbits
