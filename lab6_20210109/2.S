	.file	"test.c"
	.comm	a,1,1

			subl	$4, %esp-----start:?????????????
				movb	$1, a
				movzbl	a, %eax
				addl	$2, %eax
				movb	%al, a
        subl	$12, %esp-----------printf arg1:12 16  printf\scanf,arg1,2: 8 16
        pushl	$.LC0
        call	printf
        addl	$16, %esp
            movb	$49, a
            movzbl	a, %eax
            movsbl	%al, %eax
            subl	$8, %esp
            pushl	%eax
            pushl	$.LC1
            call	printf
            addl	$16, %esp





char a;
int b=1;
int main(){}

.comm	a,1,1

	.globl	b
	.data
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	1