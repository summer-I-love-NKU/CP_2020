#          Node         Node Type                   Children
#0 |  @0   prog                                     children: @0 -> [ @1 @4 ]  
#1 |  @1   stmt         stmt_type: decl var         children: @1 -> [ @2 ]  
#1 |  @2   type              type: int              children: @2 -> [ @3 ]  
#1 |  @3   var           var_name: help_me          
#0 |  @4   func                                     children: @4 -> [ @5 ]  
#3 |  @5   block                                    children: @5 -> [ @6 @9 @12 @16 @20 @23 @26 @31 @36 @41 ]  
#3 |  @6   stmt         stmt_type: decl var         children: @6 -> [ @7 ]  
#3 |  @7   type              type: int              children: @7 -> [ @8 ]  
#3 |  @8   var           var_name: a                
#4 |  @9   stmt         stmt_type: decl var         children: @9 -> [ @10 ]  
#4 |  @10  type              type: int              children: @10 -> [ @11 ]  
#4 |  @11  var           var_name: b                
#5 |  @12  stmt         stmt_type: assign           children: @12 -> [ @13 @14 ]  
#5 |  @13  var           var_name: a                
#5 |  @14  expr         expr_type: 0-               children: @14 -> [ @15 ]  
#5 |  @15  const       const_type: int              const_value: 100020    
#6 |  @16  stmt         stmt_type: assign           children: @16 -> [ @17 @18 ]  
#6 |  @17  var           var_name: b                
#6 |  @18  expr         expr_type: 0-               children: @18 -> [ @19 ]  
#6 |  @19  const       const_type: int              const_value: 3    
#7 |  @20  stmt         stmt_type: decl var         children: @20 -> [ @21 ]  
#7 |  @21  type              type: int              children: @21 -> [ @22 ]  
#7 |  @22  var           var_name: c                
#8 |  @23  stmt         stmt_type: decl var         children: @23 -> [ @24 ]  
#8 |  @24  type              type: int              children: @24 -> [ @25 ]  
#8 |  @25  var           var_name: d                
#9 |  @26  stmt         stmt_type: assign           children: @26 -> [ @27 @28 ]  
#9 |  @27  var           var_name: c                
#9 |  @28  expr         expr_type: /                children: @28 -> [ @29 @30 ]  
#9 |  @29  var           var_name: a                
#9 |  @30  var           var_name: b                
#10|  @31  stmt         stmt_type: assign           children: @31 -> [ @32 @33 ]  
#10|  @32  var           var_name: d                
#10|  @33  expr         expr_type: %                children: @33 -> [ @34 @35 ]  
#10|  @34  var           var_name: a                
#10|  @35  var           var_name: b                
#12|  @36  stmt         stmt_type: printf           children: @36 -> [ @37 @38 ]  
#12|  @37  const       const_type: string           const_value: "test:%d %d\n"    
#12|  @38  block                                    children: @38 -> [ @39 @40 ]  
#12|  @39  var           var_name: c                
#12|  @40  var           var_name: d                
#13|  @41  stmt         stmt_type: return           children: @41 -> [ @42 ]  
#13|  @42  const       const_type: int              const_value: 0    


#***********************asm code***********************


# Simple C Complier created by Shen Zhe, 2021.1
	.file  "test.c"
.data
	.align 4
	.type	help_me, @object
	.size	help_me, 4
help_me:
	.long	0

.data
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	0

.data
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	0

.data
	.align 4
	.type	c, @object
	.size	c, 4
c:
	.long	0

.data
	.align 4
	.type	d, @object
	.size	d, 4
d:
	.long	0

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


	movl	$-100020, %eax
	movl	%eax, a
	movl	$-3, %eax
	movl	%eax, b
	movl	a, %eax
	pushl	%eax
	movl	b, %ecx
	popl	%eax
	cltd
	idivl	%ecx
	movl	%eax, c
	movl	a, %eax
	pushl	%eax
	movl	b, %ecx
	popl	%eax
	cltd
	idivl	%ecx
	movl	%edx, %eax
	movl	%eax, d
	movl	c,%eax
	pushl	%eax
	movl	d,%eax
	pushl	%eax
	subl	$12, %esp
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
