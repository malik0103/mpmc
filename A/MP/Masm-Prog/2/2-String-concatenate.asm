        DATA SEGMENT 
        MSG1 DB "HELLO$"
        MSG2 DB "WORLD$"
        DATA ENDS
ASSUME CS:CODE; DS:DATA
        CODE SEGMENT
START:  
        MOV AX, DATA 
        MOV DS, AX
        MOV DX, OFFSET MSG1
        MOV AH, 09H
        INT 21H
        MOV DX OFFSET MSG2
        MOV AH, 09H
        INT 21H
        CODE ENDS
        END START