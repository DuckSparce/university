; Програма LR_11.s
; Оголосити кодову секцію MyCode
		AREA MyCode, CODE, ReadOnly
; Оголосити точку входу в програму додатка
		ENTRY
; Оголосити точку входу глобальної змінної
		EXPORT MyProg
MyProg
; Операції додавання / віднімання слів
; Виконати попарне додавання / віднімання
; 32-розрядних слів з масиву Array_W.
; Зберегти суми в пам'яті за адресою Sum_W
; Зберегти різниці в пам'яті за адресою Sub_W
; ініціалізація покажчиків
		LDR r0, = Array_W
		LDR r4, = Sum_W
		LDR r5, = Sub_W
; Перша сума і перша різниця
		LDR r1, [r0], #4 ; r0 = r0+4
		LDR r2, [r0], #4 ; r0 = r0+4
		ADDS r3, r1, r2
		STR r3, [r4], #4 ; r4 = r4+4
		SUBS r3, r1, r2
		STR r3, [r5], #4 ; r5 = r5+4
; Друга сума і друга різниця
		LDR r1, [r0], #4 ; r0 = r0+4
		LDR r2, [r0]
		ADDS r3, r1, r2
		STR r3, [r4]
		SUBS r3, r1, r2
		STR r3, [r5]
Stop B Stop
		ALIGN
; Оголосити секцію даних в пам'яті
		AREA MyData, Data, ReadOnly
		EXPORT Array_W
Array_W DCD 9, 4, 3, 5
; Оголосити секцію даних в оперативній пам'яті
		AREA MyData1, Data, ReadWrite
		EXPORT Sum_W
		EXPORT Sub_W
; Зарезервувати в ОЗУ місце для розміщення
; результів додавання і віднімання слів
Sum_W SPACE 4 * 2
Sub_W SPACE 4 * 2
; Кінець ассемблерного тексту
		END
