        DATA SEGMENT
        N1 DW 1731H
        N2 DW 9212H
        N3 DW ?
        DATA ENDS
        CODE SEGMENT
ASSUME CS:CODE; DS:DATA
START:  MOV AX, DATA 
        MOV DS, AX
        XOR AX, AX
        MOV BX, AX
        MOV AX, N1
        ADD AX, N2
        MOV N3, AX
        JNC STOP
        INC BX
STOP:   MOV CX, AX
        MOV AX, 4CH
        INT 21H
        CODE ENDS
        END START