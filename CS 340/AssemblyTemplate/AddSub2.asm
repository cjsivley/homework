TITLE Add and Subtract, Version 2         (AddSub2.asm)

; Codey Sivley
; CS340 Dr Rimes
; Equation Assignment

INCLUDE Irvine32.inc

.data
varA     dword  20
varB     dword  12
varC     dword  36
varD     dword  52
tmp1     dword  ?
cons     dword  9
res1     dword  ?
res2     dword  ?

.code
main PROC
		;Equation 1: (a+b)*3+(d-c)*2+9
	mov eax,varA
	add eax,varB
		;don't know how to multiply, so I'll just add a few times
	mov ebx,eax
	add eax,ebx
	add eax,ebx
		;halfway done, move to temp
	mov tmp1,eax
		;right half of problem
	mov eax, varD
	sub eax, varC
		;multiply
	mov ebx, eax
	add eax, ebx
		;add them up
	add eax, tmp1
	add eax, cons
	mov res1, eax ;I suppose it would be good to move it back to memory

		;Equation 2: (a-b)*3+(d+c)*2-9
	mov ebx, varA
	sub ebx, varB
		;multiply
	mov ecx, ebx
	add ebx, ecx
	add ebx, ecx
		;move to temp
	mov tmp1, ebx
		;right half again
	mov ebx, varD
	add ebx, varC
	mov ecx, ebx
		;multiply
	add ebx, ecx
		;sub nine and add the first half
	sub ebx, cons
	add ebx, tmp1
	mov res2, ebx

	call	DumpRegs			; display the registers

	exit
main ENDP
END main