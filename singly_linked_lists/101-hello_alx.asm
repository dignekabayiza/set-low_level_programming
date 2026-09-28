	global	main
	extern	printf

	section	.text
main:
	push	rbp
	mov	rdi, format
	xor	eax, eax
	call	printf
	pop	rbp
	xor	eax, eax
	ret

	section	.data
format:
	db	"Hello, Frontier", 10, 0
