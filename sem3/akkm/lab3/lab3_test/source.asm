; ������� ������� ��������, ��� �������� ���� �������� ������
.586P
; ������ ������ ���'��
.MODEL FLAT, STDCALL
;------------------------------------------------
; ������� �����
_DATA SEGMENT
Num1 DD 17, 3, -51, 242, -113	; ���������� ������ �����, ����� � ���� ����� ������� �����
N DD 5							; ʳ������ �������� � ����� Num1
Sum DD 0						; ���� �������� ������ Num1
_DATA ENDS
; ������� ����
_TEXT SEGMENT
START:
	lea EBX, Num1				; ����������� � BX ������ ������� �������� ������ Num1
	mov ECX, N					; ����������� � CX ������� �������� � ����� Num1
	mov EAX, 0					; � AX ���� ���� �������� ������ Num1
M1: add EAX, [EBX]				; ������ �� AX �������� ������� ������ Num1
	add EBX, 4					; ������� ������ ���������� �������� ������ Num1
	loop M1						; ���������� CX � ���� CX �� ������� ����, �� �� �1
	mov Sum, EAX				; ���� ����������. �������� ��������� ���� � ������ Sum
	RET							; �����
_TEXT ENDS
END START