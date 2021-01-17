run: w
w:
	gcc -m32 -S test.cpp -o test.S
	# gcc -m32 -c -g -Wa,-adlhn test.c > test.c1.S
	# gcc -m32 -S -fverbose-asm test.c -o test.c2.S
	sed -i '/^	.cfi_/d' test.S
	gcc -m32 test.S -o test
	./test
h:
	sudo sh -c 'echo 1 > /proc/sys/vm/drop_caches'
	sync
	sync
	sync
s:
	gcc -m32 1.S -o 1.out
	./1.out