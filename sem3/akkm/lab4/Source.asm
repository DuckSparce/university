include Irvine32.inc

.686
.model flat,c
.stack

.data

zeroBytes byte 0dh, 0ah  ; New line symbols (CR LF)

firstText   byte    " Kachur  Artem   Myroslavovych    11-12-2005     Mukachevo      Zakarpatska       PZ-21A  ", 00
firstLen    DD 90
secondText  byte    120 DUP (?)
secondLen   DD 120
thirdText   byte    90 DUP (?)
thirdLen    DD 90

lastName    byte    21 DUP (?)
firstName   byte    21 DUP (?)
patronymic  byte    21 DUP (?)
birth       byte    21 DUP (?)
city        byte    21 DUP (?)
region      byte    21 DUP (?)
sgroup      byte    21 DUP (?)

lastNameLen     DD 0
firstNameLen    DD 0 
patronymicLen   DD 0
birthLen        DD 0
cityLen         DD 0
regionLen       DD 0
sgroupLen       DD 0

begin       DD 0     ; Initial position in the text
spacesNum   DD 0
ACount      DD 0     ; Count of 'A' symbols

filename    BYTE "Kachur.txt", 00
fileHandle  DD ?
byteCount   DD ?
toAppend    byte "KDM - 100, Basics of Programming - 98"
toAppendLen DD $ - toAppend

.code

; Procedure to count the number of spaces in a string
spaceLen proc start:dword 
    lea edi, firstText        ; Load the addres of first text to edi
    add edi, start            ; Add the offset to the start position
    mov esi, edi              ; Copy the addres to esi
    mov eax, ' '              ; Find the space symbol
    mov ecx, firstLen         ; Load firstLen to ecx
    cld                       ; Clear the direction flag
    repe scasb                ; Find the space
    dec edi                   ; Get back on 1 sym
    sub edi, esi              ; Calculate the difference (length)
    mov eax, edi              ; Save it to eax
    add ebx, eax              ; Add it to ebx
    mov begin, ebx            ; Save the initial position
    ret
spaceLen endp

; Procedure to count field length (up to space)
fieldLen proc start:dword
    lea edi, firstText        ; Load the addres of first text to edi
    add edi, start            ; Add the offset to the start position
    mov esi, edi              ; Copy the addres to esi
    mov eax, ' '              ; Find the space symbol
    mov ecx, firstLen         ; Load firstLen to ecx
    cld                       ; Clear the direction flag
    repne scasb               ; Up to first symbol
    dec edi                   ; Get back on 1 sym
    sub edi, esi              ; Calculate the difference (length)
    mov eax, edi              ; Save it to eax
    mov ebx, eax              ; Save it to ebx
    add ebx, start            ; Add ofset to the initial position
    ret
fieldLen endp

main proc

mov ebx, 0                  ; Init ebx

; Copy fields and its lengths
invoke spaceLen, ebx        ; Call spaceLen procedure
add spacesNum, eax          ; Add number of spaces
invoke fieldLen, ebx        ; Call fieldLen procedure
mov lastNameLen, eax        ; Save field length

mov ecx, lastNameLen        ; Load field length to ecx
lea esi, firstText          ; Load the address of first text to esi
add esi, begin              ; Add offset
lea edi, lastName           ; Load buffer address to edi
rep movsb                   ; Copy bytes to buffer

invoke spaceLen, ebx        ; Count spaces for firstName
add spacesNum, eax
invoke fieldLen, ebx
mov firstNameLen, eax

mov ecx, firstNameLen
lea esi, firstText
add esi, begin
lea edi, firstName
rep movsb

invoke spaceLen, ebx        ; Count spaces for patronymic
add spacesNum, eax
invoke fieldLen, ebx
mov patronymicLen, eax

mov ecx, patronymicLen
lea esi, firstText
add esi, begin
lea edi, patronymic
rep movsb

invoke spaceLen, ebx        ; Count spaces for birth date
add spacesNum, eax
invoke fieldLen, ebx
mov birthLen, eax

mov ecx, birthLen
lea esi, firstText
add esi, begin
lea edi, birth
rep movsb

invoke spaceLen, ebx        ; Count spaces for city
add spacesNum, eax
invoke fieldLen, ebx
mov cityLen, eax

mov ecx, cityLen
lea esi, firstText
add esi, begin
lea edi, city
rep movsb

invoke spaceLen, ebx        ; Count spaces for region
add spacesNum, eax
invoke fieldLen, ebx
mov regionLen, eax

mov ecx, regionLen
lea esi, firstText
add esi, begin
lea edi, region
rep movsb

invoke spaceLen, ebx        ; Count spaces for group
add spacesNum, eax
invoke fieldLen, ebx
mov sgroupLen, eax

mov ecx, sgroupLen
lea esi, firstText
add esi, begin
lea edi, sgroup
rep movsb

invoke spaceLen, ebx        ; Count spaces at the end
add spacesNum, eax

; Copy the field to the second line
lea edi, secondText
mov eax, ' '

mov ecx, 7              ; Copy group
rep stosb
lea esi, sgroup
mov ecx, sgroupLen
rep movsb

mov ecx, 2              ; Copy first name
rep stosb
lea esi, firstName
mov ecx, firstNameLen
rep movsb

mov ecx, 6              ; Copy region
rep stosb
lea esi, region
mov ecx, regionLen
rep movsb

mov ecx, 3              ; Copy patronymic
rep stosb
lea esi, patronymic
mov ecx, patronymicLen
rep movsb

mov ecx, 1              ; Copy last name
rep stosb
lea esi, lastName
mov ecx, lastNameLen
rep movsb

mov ecx, 5              ; Copy city
rep stosb
lea esi, city
mov ecx, cityLen
rep movsb

mov ecx, 4              ; Copy birth date
rep stosb
lea esi, birth
mov ecx, birthLen
rep movsb

mov ecx, 3              ; Copy spaces at the end to the second string
rep stosb

lea esi, zeroBytes      ; Copy 00 to the end
mov ecx, 2
rep movsb

lea edx, secondText     ; Output second text
call WriteString

; Open the file for write
invoke CreateFile, ADDR filename, GENERIC_WRITE, DO_NOT_SHARE, NULL, 
        CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0
mov fileHandle, eax

; Write first and second text to file, close the handle
invoke WriteFile, fileHandle, ADDR secondText, secondLen, ADDR byteCount, 0
invoke WriteFile, fileHandle, ADDR firstText, firstLen, ADDR byteCount, 0
invoke CloseHandle, fileHandle

; Open file for write and read
invoke CreateFile, ADDR filename, GENERIC_READ or GENERIC_WRITE, DO_NOT_SHARE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0
mov fileHandle, eax

; Set file pointer 
invoke SetFilePointer, fileHandle, secondLen, 0, FILE_BEGIN
; Read the text
invoke ReadFile, fileHandle, ADDR thirdText, firstLen, ADDR byteCount, 0

lea esi, thirdText
mov ecx, thirdLen

count:
    lodsb
    cmp eax, 'A'
    jnz pass_increment
    inc ACount
    pass_increment:
    loop count

; Write info about disciplines to the end of file
invoke SetFilePointer, fileHandle, 0, 0, FILE_END
invoke WriteFile, fileHandle, ADDR toAppend, toAppendLen, ADDR byteCount, 0
invoke CloseHandle, fileHandle

invoke ExitProcess, 0

ret
main ENDP
end main
