.model small
.stack 100h

xVal = 13
yVal = 6
horizontalLen = 221
verticalLen = 137

.data
    saveMode BYTE ?

.code

drawVertical PROC
mov CX, verticalLen
inc CX

vertical:
    mov BYTE PTR ES:[DI], BL
    add DI, 320
    loop vertical

ret
drawVertical ENDP

drawHorizontal PROC
mov CX, horizontalLen
inc CX

horizontal:
    mov BYTE PTR ES:[DI], BL
    inc DI
    loop horizontal

ret
drawHorizontal ENDP

main PROC
    ; Set video mode
    mov AX, @data
    mov DX, AX
    mov AH, 0Fh
    int 10h
    mov saveMode, AL

    ; Set new videomode
    mov AH, 0
    mov Al, 13h
    int 10h

    ; Set videobuffer segment address
    mov AX, 0A000h
    mov ES, AX

    ; OUTER LINES
    ; Set outer lines color in palette
    mov DX, 3C8h
    mov AL, 1
    out DX, AL
    mov DX, 3C9h
    mov AL, 63              ; Red
    out DX, AL
    mov AL, 0               ; Green
    out DX, AL
    mov AL, 0               ; Blue
    out DX, AL

    ; TOP line start coordinates (top-left)
    mov AX, 320
    mov BX, yVal
    mul BX
    add AX, xVal
    mov DI, AX
    
    mov BL, 1               ; set color to use
    call drawHorizontal

    ; LEFT line start coordinates (top-left)
    mov AX, 320
    mov BX, yVal
    mul BX
    add AX, xVal
    mov DI, AX

    mov BL, 1
    call drawVertical

    ; BOTTOM line start coordinates (bottom-left)
    mov BX, 320
    mov AX, yVal
    add AX, verticalLen
    mul BX
    add AX, xVal
    mov DI, AX

    mov BL, 1
    call drawHorizontal

    ; RIGHT line start coordinates (top-right)
    mov AX, 320
    mov BX, yVal
    mul BX
    add AX, xVal
    add AX, horizontalLen
    mov DI, AX

    mov BL, 1
    call drawVertical

    ; INNER LINES
    ; Set inner lines color in palette
    mov DX, 3C8h
    mov AL, 2
    out DX, AL
    mov DX, 3C9h
    mov AL, 0               ; Red
    out DX, AL
    mov AL, 0               ; Green
    out DX, AL
    mov AL, 63               ; Blue
    out DX, AL

    ; Setting up start coordinates (top-left)
    mov AX, 320
    mov BX, yVal
    mul BX
    add AX, xVal
    mov DI, AX
    
nextHorizontal:
    mov AX, verticalLen
    mov BX, 5
    div BX
    mov BX, 320
    mul BX
    add DI, AX

    mov BL, 2
    call drawHorizontal
    
    sub DI, horizontalLen        ; return back to needed column
    dec DI

    ; cmp with (yVal+verticalLen)*320+xVal
    mov AX, verticalLen
    add AX, yVal
    mov BX, 320
    mul BX
    add AX, xVal

    cmp DI, AX
    jg nextHorizontal

    ; Setting up start coordinates (top-left)
    mov AX, 320
    mov BX, yVal
    mul BX
    add AX, xVal
    mov DI, AX

nextVertical:
    mov AX, horizontalLen
    mov BX, 6
    div BX
    add DI, AX

    mov BL, 2
    call drawVertical

    mov AX, verticalLen
    inc AX
    mov BX, 320
    mul BX
    sub DI, AX         ; return back to needed row

    ; cmp with yVal*320+horizontalLen-horizontalLen/6
    mov AX, yVal
    mov BX, 320
    mul BX
    add AX, horizontalLen
    sub AX, 30

    cmp DI, AX
    jl nextVertical

    ; DRAWN RECTANGLE
    ; Set color palette for rectangle to draw
    mov DX, 3C8h
    mov AL, 3
    out DX, AL
    mov DX, 3C9h
    mov AL, 0               ; Red
    out DX, AL
    mov AL, 63              ; Green
    out DX, AL
    mov AL, 0               ; Blue
    out DX, AL

    ; Setting up start coordinates
    mov DI, (yVal+verticalLen/5+1)*320+horizontalLen/6*4+xVal+1
    mov BX, 26

outerLoop:
    mov CX, 35

    innerLoop:
        mov BYTE PTR ES:[DI], 3
        inc DI
        loop innerLoop

    sub DI, 35
    add DI, 320

    dec BX
    jnz outerLoop


    mov AH, 10h  ; Чекаємо натиснення клавіші
    int 16h
    mov AH, 0    ; Відновимо старий відеорежим
    mov AL, saveMode
    int 10h

    ; Завершення програми
    mov AH, 4ch
    int 21h
    ret

main endp
end main
