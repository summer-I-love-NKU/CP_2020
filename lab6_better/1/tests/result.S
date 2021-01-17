# Simple C Complier created by Shen Zhe, 2021.1

#*********************************** AST ***********************************
#        Node Type         Node Info                   Children
#0 |  @0   prog                                     children: @0 -> [ @1 @4 @8 ]  
#1 |  @1   stmt         stmt_type: decl var         children: @1 -> [ @2 ]  
#1 |  @2   type              type: int              children: @2 -> [ @3 ]  
#1 |  @3   var           var_name: help             
#2 |  @4   stmt         stmt_type: decl array       children: @4 -> [ @5 ]  
#2 |  @5   type              type: int              children: @5 -> [ @6 ]  
#2 |  @6   array       array_name: a                children: @6 -> [ @7 ]  
#2 |  @7   const       const_type: int              const_value: 10    
#0 |  @8   func                                     children: @8 -> [ @9 ]  
#4 |  @9   block                                    children: @9 -> [ @10 @14 @18 ]  
#4 |  @10  stmt         stmt_type: decl var         children: @10 -> [ @11 ]  
#4 |  @11  type              type: int              children: @11 -> [ @12 ]  
#4 |  @12  var           var_name: b                children: @12 -> [ @13 ]  
#4 |  @13  const       const_type: int              const_value: -1    
#6 |  @14  stmt         stmt_type: printf           children: @14 -> [ @15 @16 ]  
#6 |  @15  const       const_type: string           const_value: "%d\n"    
#6 |  @16  block                                    children: @16 -> [ @17 ]  
#6 |  @17  var           var_name: b                
#7 |  @18  stmt         stmt_type: return           children: @18 -> [ @19 ]  
#7 |  @19  const       const_type: int              const_value: 0    


#*********************************** ASM CODE ***********************************
# Simple C Complier created by Shen Zhe, 2021.1
	.file  "test.c"
.section	.rodata
.LC0:
	.string	"%d\n"

.data
	.align 4
	.type	help, @object
	.size	help, 4
help:
	.long	0

	.align 4
	.type	a, @object
	.size	a, 40
a:
	.zero	40
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	-1


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


	movl	b,%eax
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
