.586P
.MODEL FLAT, STDCALL
;-----------------------
_DATA SEGMENT
row			DD 6
col			DD 7
shift		DD 0			; offset in bytes during continuing iteration
matrix		DD -47, 89, -12, 35, 78, 62, -3
			DD 16, -95, 74, -22, 50, -69, 81
			DD -56, 39, 87, 5, 41, 93, -18
			DD 67, -30, 82, -9, 25, -73, 58
			DD -84, 11, -60, -96, -33, 44, -7
			DD 29, -26, 76, -15, 44, -31, 20
matrixT	DD 42 DUP (0)
scal		DD 0
count		DD 0
sum			DD 0
_DATA ENDS

_TEXT SEGMENT
START:
	lea ESI, matrix
	lea EDI, matrixT
	mov EBX, row

TRANSPOSITION_FIRST_LOOP:
	mov ECX, col

	TRANSPOSITION_SECOND_LOOP:
		mov EAX, [ESI]
		mov [EDI], EAX
		add ESI, 4
		add EDI, 24
		loop TRANSPOSITION_SECOND_LOOP

	lea EDI, matrixT
	add shift, 4
	add EDI, shift
	dec EBX
	jnz TRANSPOSITION_FIRST_LOOP

lea EBX, matrix
add EBX, 12				; set EBX to the 1 element of 4th column
mov ECX, row			; loop counter = row

SCALAR:
	mov EAX, [EBX + 4]	; set EAX to 5th column
	imul EAX, [EBX]
	add scal, EAX
	add EBX, 28			; set EBX to the next row 4th column (7*4)
	loop SCALAR

lea EBX, matrix
add EBX, 140			; set EBX to the 6th row (5*7*4)
mov ECX, col			; loop counter = col

CONDITION:
	mov EAX, [EBX]
	cmp EAX, -26
	jle TRUE
	cmp EAX, 44
	jle FALSE

TRUE:
	inc count
	add sum, EAX

FALSE:
	add EBX, 4			; next element
	loop CONDITION
	RET
END START
_TEXT ENDS
