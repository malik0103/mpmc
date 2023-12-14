#include<stdio.h>
#include<string.h>
void main(){
    char macros[20][10], label[20], opcode[20], operand[20];
    int i, j, n, m = 0;
    FILE *Fp1, *Fp[10];

    Fp1 = fopen("input.txt", "r");
    fscanf(Fp1, "%s%s%s", label, opcode, operand);
    while (strcmp(opcode, "END") != 0){
        if(!strcmp(opcode, "MACRO")){
            Fp[m] = fopen(operand, "w");
            m++;
            fscanf(Fp1, "%s%s%s", label, opcode, operand);
            while(strcmp(opcode, "MEND") != 0){
                fprintf(Fp[m-1], "%s\t%s\t%s\n", label, opcode, operand);
                fscanf(Fp1, "%s%s%s", label, opcode, operand);
            }
        }
        fscanf(Fp1, "%s%s%s", label, opcode, operand);
    }
}