#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
    FILE *F1, *F2, *F3, *F4;
    char s[100], lab[30], opcode[30], opa[30], opcode1[30], opa1[30];
    int locctr, x = 0;
    F1 = fopen("input.txt", "r");
    F2 = fopen("opcode.txt", "r");
    F3 = fopen("out.txt", "w");
    F4 = fopen("sym.txt", "w");
    while (fscanf(F1, "%s%s%s", lab, opcode, opa) != EOF){
        if(strcmp(lab, "**") == 0){
            if(strcmp(opcode, "START") == 0){
                fprintf(F3, "%s %s %s", lab, opcode, opa);
                locctr = atoi(opa);
            }else{
                rewind(F2);
                x = 0;
                while(fscanf(F2, "%s%s", opcode1, opa1) != EOF){
                    if(strcmp(opcode, opcode1) == 0){
                        x = 1;
                    }
                }
                if(x == 1){
                    fprintf(F3, "\n%d %s %s %s", locctr, lab, opcode, opa);
                    locctr += 3;
                }
            }
        }else{
            if(strcmp(opcode, "RESW") == 0){
                fprintf(F3, "\n%d %s %s %s", locctr, lab, opcode, opa);
                fprintf(F4, "\n%d %s", locctr, lab);
                locctr += 3 * atoi(opa);
            }else if(strcmp(opcode, "WORD") == 0){
                fprintf(F3, "\n%d %s %s %s", locctr, lab, opcode, opa);
                fprintf(F4, "\n%d %s", locctr, lab);
                locctr += 3;
            }else if(strcmp(opcode, "BYTE") == 0){
                fprintf(F3, "\n%d %s %s %s", locctr, lab, opcode, opa);
                fprintf(F4, "\n%d %s", locctr, lab);
                locctr += 1;
            }else if(strcmp(opcode, "RESB") == 0){
                fprintf(F3, "\n%d %s %s %s", locctr, lab, opcode, opa);
                fprintf(F4, "\n%d %s", locctr, lab);
                locctr += 1;
            }else{
                fprintf(F3, "\n%d %s %s %s", locctr, lab, opcode, opa);
                fprintf(F4, "\n%d %s", locctr, lab);
                locctr += atoi(opa);
            }
        }
    }
}