#include<stdio.h>
#include<string.h>

void main(){
    char macros[20][10], label[20], opcode[20], operand[20];
    int i, j, n, m = 0;
    FILE *Fp1, *Fp[10], *Fp2;
    Fp1 = fopen("input.txt", "r");
    Fp2 = fopen("macro_out.txt", "w");
    fscanf(Fp1, "%s%s%s", label, opcode, operand);
    while(strcmp(opcode, "END") != 0){
        if(!strcmp(opcode, "CALL")){
            Fp[m] = fopen(operand, "r");
            m++;
            fscanf(Fp[m-1], "%s%s%s", label, opcode, operand);
            while(!feof(Fp[m-1])){
                fprintf(Fp2, "%s\t%s\t%s\n", label, opcode, operand);
                fscanf(Fp[m-1], "%s%s%s", label, opcode, operand);
            }
        }else{
            fprintf(Fp2, "%s\t%s\t%s\n", label, opcode, operand);
        }
        fscanf(Fp1, "%s%s%s", label, opcode, operand);
    }
    fprintf(Fp2, "%s\t%s\t%s\n", label, opcode, operand);
}