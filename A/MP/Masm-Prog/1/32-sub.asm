        DATA SEGMENT
        LIST DD 12121212H, 12121212H;
        N3 DW ?
        N4 DW ?
        DATA ENDS
        CODE SEGMENT
ASSUME CS:CODE; DS:DATA
START:  MOV AX, DATA 
        MOV DS, AX
        XOR AX, AX
        MOV CL, AL
        MOV AX, [SI]
        SUB AX, [SI+4]
        MOV BX, AX
        MOV N3, BX
        MOV AX, [SI+2]
        SUB AX, [SI+6]
        MOV DX, AX
        MOV N4, DX
        JNC STOP
        INC CL
STOP:   MOV AX, 4CH
        INT 21H
        CODE ENDS
        END START