; this macro prints a char in AL and advances
; the current cursor position:
PUTC    MACRO   char
        PUSH    AX
        MOV     AL, char
        MOV     AH, 0Eh
        INT     10h     
        POP     AX
ENDM


; this macro prints a string that is given as a parameter, example:
; PRINT 'hello world!'
; new line is NOT added.
PRINT   MACRO   sdat
LOCAL   s_dcl, skip_dcl

PUSH    AX      ; store registers...
PUSH    DX      ;

JMP     skip_dcl        ; skip declaration.
        s_dcl DB sdat, '$'

skip_dcl:
	LEA dx, s_dcl
	MOV AH, 09h
	INT 21h

POP     DX      ; re-store registers...
POP     AX      ;
ENDM

; this macro prints an array of values that is given as a parameter, example:
; PRINT 03h, 34h, 02h
; new line is NOT added.
PRINTLAB   MACRO   sdat

PUSH    AX      ; store registers...
PUSH    DX      ;

	LEA dx, sdat
	MOV AH, 09h
	INT 21h

POP     DX      ; re-store registers...
POP     AX      ;
ENDM


; turns off the cursor:
CURSOROFF       MACRO
        PUSH    AX
        PUSH    CX
        MOV     AH, 1
        MOV     CH, 28h
        MOV     CL, 09h
        INT     10h
        POP     CX
        POP     AX
ENDM



; turns on the cursor:
CURSORON        MACRO
        PUSH    AX
        PUSH    CX
        MOV     AH, 1
        MOV     CH, 08h
        MOV     CL, 09h
        INT     10h
        POP     CX
        POP     AX
ENDM

; sets current cursor
; position:
GOTOXY  MACRO   col, row
        PUSH    AX
        PUSH    BX
        PUSH    DX
        MOV     AH, 02h
        MOV     DH, row
        MOV     DL, col
        MOV     BH, 0
        INT     10h
        POP     DX
        POP     BX
        POP     AX
ENDM

		