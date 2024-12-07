.model small
.stack 100h

startColumn = 22
startRow = 1

.data

lastName DB "Kachur", 00
lastNameLen DW $-lastName-1
firstName DB "Artem", 00
firstNameLen DW $-firstName-1
patronym DB "Myroslavovych", 00
patronymLen DW $-patronym-1

color DB 00000001b

.code

main PROC
    ; set up DS for DOS
    mov AX, @data
    mov DS, AX

    ; clear screen
    mov AH, 00h
    mov AL, 2h
    int 10h

    ; first page
    mov AH, 05h
    mov AL, 01h
    int 10h
    
    mov AX, 0B900h
    mov ES, AX
    mov DL, color

    mov BX, 80*2*startRow+2*startColumn
    lea SI, lastName
    mov CX, lastNameLen
    
    LAST_NAME_LOOP:
        mov AL, [SI]
        mov ES:[BX], AL   ; output char
        inc BX                 

        mov ES:[BX], DL   ; output color
        inc BX
        
        inc SI            ; next char
        add DL, 13         ; next color
        loop LAST_NAME_LOOP

    add BX, 80*2*2+2*3
    lea SI, firstName
    mov CX, firstNameLen
    
    FIRST_NAME_LOOP:
        mov AL, [SI]
        mov ES:[BX], AL   ; output char
        inc BX                 

        mov ES:[BX], DL   ; output color
        inc BX
        
        inc SI             ; next char
        add DL, 13         ; next color
        loop FIRST_NAME_LOOP

    add BX, 80*2*4+2*5
    lea SI, patronym
    mov CX, patronymLen
    
    PATRONYM_LOOP:
        mov AL, [SI]
        mov ES:[BX], AL   ; output char
        inc BX

        mov ES:[BX], DL   ; output color
        inc BX
        
        inc SI            ; next char
        add DL, 13       ; next color
        loop PATRONYM_LOOP

    ; waiting for press key
    mov AH, 10h
    int 16h
    
    ; return control to DOS
    mov AH, 4ch
    int 21h
    ret

main ENDP
END main
