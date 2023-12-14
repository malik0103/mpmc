        DATA SEGMENT 
        STRING1 DB 99H, 12H, 56H, 45H, 36H
        DATA ENDS
ASSUME CS:CODE; DS:DATA
        CODE SEGMENT
START:
        MOV AX, DATA 
        MOV DS, AX
        MOV CH, 04H
UP2:    MOV CL, 04H
        LEA SI, STRING1
UP1:    MOV AL, [SI]
        MOV BL, [SI+1]
        CMP AL, BL
        JNC DOWN
        MOV DL, [SI+1]
        XCHG [SI], DL
        MOV [SI+1], DL
DOWN:   INC SI
        DEC CL
        JNZ UP1
        DEC CH
        JNZ UP2
        INT 3
        CODE ENDS
        END START