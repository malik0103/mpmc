        DATA SEGMENT 
        MSG1 DB "HELLO WORLD$"
        DATA ENDS
ASSUME CS:CODE; DS:DATA
        CODE SEGMENT
START:
        MOV AX, DATA 
        MOV DS, AX
        MOV DX, OFFSET MSG1
        MOV AH, 09H
        INT 21H
        MOV AH, 4CH
        MOV AL, 00H
        INT 21H
        CODE ENDS
        END START