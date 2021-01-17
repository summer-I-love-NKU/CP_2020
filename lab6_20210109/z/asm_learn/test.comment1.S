   1              		.file	"test.c"
   2              		.text
   3              	.Ltext0:
   4              		.section	.rodata
   5              	.LC0:
   6 0000 74657374 		.string	"test!!!"
   6      21212100 
   7              		.text
   8              		.globl	main
  10              	main:
  11              	.LFB0:
  12              		.file 1 "test.c"
   1:test.c        **** #include<stdio.h>
   2:test.c        **** int main(){
  13              		.loc 1 2 0
  14              		.cfi_startproc
  15 0000 8D4C2404 		leal	4(%esp), %ecx
  16              		.cfi_def_cfa 1, 0
  17 0004 83E4F0   		andl	$-16, %esp
  18 0007 FF71FC   		pushl	-4(%ecx)
  19 000a 55       		pushl	%ebp
  20              		.cfi_escape 0x10,0x5,0x2,0x75,0
  21 000b 89E5     		movl	%esp, %ebp
  22 000d 51       		pushl	%ecx
  23              		.cfi_escape 0xf,0x3,0x75,0x7c,0x6
  24 000e 83EC04   		subl	$4, %esp
   3:test.c        ****     printf("test!!!\n");
  25              		.loc 1 3 0
  26 0011 83EC0C   		subl	$12, %esp
  27 0014 68000000 		pushl	$.LC0
  27      00
  28 0019 E8FCFFFF 		call	puts
  28      FF
  29 001e 83C410   		addl	$16, %esp
   4:test.c        ****     return 0;
  30              		.loc 1 4 0
  31 0021 B8000000 		movl	$0, %eax
  31      00
   5:test.c        **** }...
  32              		.loc 1 5 0
  33 0026 8B4DFC   		movl	-4(%ebp), %ecx
  34              		.cfi_def_cfa 1, 0
  35 0029 C9       		leave
  36              		.cfi_restore 5
  37 002a 8D61FC   		leal	-4(%ecx), %esp
  38              		.cfi_def_cfa 4, 4
  39 002d C3       		ret
  40              		.cfi_endproc
  41              	.LFE0:
  43              	.Letext0:
