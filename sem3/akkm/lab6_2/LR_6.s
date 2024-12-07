	AREA MyCode, CODE, ReadOnly
    ENTRY
    EXPORT MyProg

MyProg
    ; Підготовка до транспонування
    LDR r2, =8           ; Кількість стовпців у вхідній матриці (n=8)
    LDR r3, =6           ; Кількість рядків у вхідній матриці (m=6)
    LDR r7, =4           ; Розмір елемента (4 байти)
    LDR r4, =0           ; Лічильник рядків

TRANSPOSE
    LDR r0, =inputMatrix      ; Початкова адреса вхідної матриці
    LDR r1, =transposedMatrix ; Початкова адреса транспонованої матриці
    MOV r5, #0                ; Індекс стовпця

COLUMN_LOOP
    MOV r4, #0                ; Індекс рядка
ROW_LOOP
    ; Вхідна матриця: адреса елемента [r4, r5]
    MUL r6, r4, r2            ; r6 = рядок * n
    ADD r6, r5                ; r6 = рядок * n + стовпець
    MUL r6, r6, r7            ; r6 = адреса елемента у вхідній матриці
    ADD r6, r0, r6            ; r0 = адреса елемента у вхідній матриці

    ; Транспонована матриця: адреса елемента [r5, r4]
    MUL r8, r5, r3            ; r8 = стовпець * m
    ADD r8, r4                ; r8 = стовпець * m + рядок
    MUL r8, r8, r7            ; r8 = адреса елемента у транспонованій матриці
    ADD r8, r1, r8            ; r1 = адреса елемента у транспонованій матриці

    LDR r9, [r6]              ; Завантажити елемент з вхідної матриці
    STR r9, [r8]              ; Записати елемент у транспоновану матрицю

    ADD r4, r4, #1            ; Наступний рядок
    CMP r4, r3
    BNE ROW_LOOP

    ADD r5, r5, #1            ; Наступний стовпець
    CMP r5, r2
    BNE COLUMN_LOOP

; Обчислення скалярного добутку 4-го і 5-го рядків
    LDR r0, =inputMatrix
    ADD r0, #4 * 8 * 3		  ; Зсув до 4-го рядка
    LDR r1, =inputMatrix
    ADD r1, #4 * 8 * 4        ; Зсув до 5-го рядка
    LDR r2, = 8               ; Кількість елементів у рядку
    LDR r3, =0                ; Ініціалізація скалярного добутку

SCALAR_LOOP
	LDR r4, [r0], #4          ; Завантажити елемент з 4-го рядка
    LDR r5, [r1], #4          ; Завантажити елемент з 5-го рядка
    MUL r6, r4, r5            ; Множення елементів
    ADD r3, r3, r6            ; Додавання до скалярного добутку
    SUB r2, #1
    CMP r2, #0
    BNE SCALAR_LOOP

    LDR r7, =scalarMul
    STR r3, [r7]              ; Зберегти скалярний добуток

; Підрахунок кількості та суми елементів 2-го стовпця, що відповідають умовам
    LDR r0, =inputMatrix
    ADD r0, #4                ; Зсув до 2-го стовпця
    LDR r1, =6                ; Кількість елементів у стовпці
    LDR r3, =0                ; Лічильник елементів, що відповідають умовам
    LDR r4, =0                ; Сума елементів, що відповідають умовам

COND
    LDR r2, [r0], #4 * 8      ; Завантажити елемент з 2-го стовпця
    CMP r2, #-34
    BLT TRUE
    CMP r2, #62
    BLE FALSE
TRUE
    ADD r3, #1                ; Збільшити лічильник відповідних елементів
    ADD r4, r2                ; Додати елемент до суми
FALSE
    SUB r1, #1
    CMP r1, #0
    BNE COND

    LDR r5, =amountOfElems
    LDR r6, =sumOfElems
    STR r3, [r5]              ; Зберегти кількість елементів
    STR r4, [r6]              ; Зберегти суму елементів

Stop B Stop

    ALIGN
    AREA MyData, Data, ReadOnly
    EXPORT inputMatrix
inputMatrix DCD -93, -64, 73, 50, -37, 28, -47, -99
            DCD 30, -21, -1, 61, -17, -62, 67, -45
            DCD -30, 93, 56, -15, -94, -48, -89, -34
            DCD -44, 54, -2, -86, 59, -15, -50, 91
            DCD -84, 43, -87, 94, 62, 28, 85, -88
            DCD 60, -71, 43, -93, -8, -64, 46, -87

    AREA MyData1, Data, ReadWrite
    EXPORT transposedMatrix
    EXPORT scalarMul
    EXPORT sumOfElems
    EXPORT amountOfElems

transposedMatrix SPACE 4 * 6 * 8      ; 6*8 елементів
scalarMul       SPACE 4           ; Скалярний добуток
sumOfElems      SPACE 4           ; Сума елементів
amountOfElems   SPACE 4           ; Кількість елементів

    END
