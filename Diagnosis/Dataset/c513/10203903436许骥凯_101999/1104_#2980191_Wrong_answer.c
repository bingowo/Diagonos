#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int VarMI[128];



int trans(const char *temp, char *var){
    int arg;
    var[0] = temp[0], var[1] = temp[1], var[2] = 0;
    char t[100]; strcpy(t, temp + 3);
    arg = atoi(t);
    return arg;
}
void trans2(const char *temp,  char *var1, char *var2){var1[0] = temp[0], var1[1] = temp[1], var1[2] = 0; var2[0] = temp[3], var2[1] = temp[4], var2[2] = 0;}
void trans3(const char *temp, char *var1, char *var2, char *var3){
    var1[0] = temp[0], var1[1] = temp[1], var1[2] = 0; 
    var2[0] = temp[3], var2[1] = temp[4], var2[2] = 0;
    var3[0] = temp[6], var3[1] = temp[7], var3[2] = 0;
}

void IN(const char *var, int arg){VarMI[var[0]] = arg;}
void MOV(const char *var1, const char *var2){VarMI[var1[0]] = VarMI[var2[0]];}
void XCHG(const char *var1, const char *var2){int temp = VarMI[var1[0]];VarMI[var1[0]] = VarMI[var2[0]];VarMI[var2[0]] = temp;}

void ADD(const char *var1, const char *var2){VarMI[var1[0]] += VarMI[var2[0]];}
void ADD2(const char *var1, const char *var2, const char *var3){VarMI[var1[0]] = VarMI[var2[0]] + VarMI[var3[0]];}

void SUB(const char *var1, const char *var2){VarMI[var1[0]] -= VarMI[var2[0]];}
void SUB2(const char *var1, const char *var2, const char *var3){VarMI[var1[0]] = VarMI[var2[0]] - VarMI[var3[0]];}

void MUL(const char *var1, const char *var2){VarMI[var1[0]] *= VarMI[var2[0]];}
void MUL2(const char *var1, const char *var2, const char *var3){VarMI[var1[0]] = VarMI[var2[0]] * VarMI[var3[0]];}

// void DIV(const char *var1, const char *var2){VarMI[var1[0]] /= VarMI[var2[0]];}
// void DIV2(const char *var1, const char *var2, const char *var3){VarMI[var1[0]] = VarMI[var2[0]] / VarMI[var3[0]];}

void MOD(const char *var1, const char *var2){VarMI[var1[0]] %= VarMI[var2[0]];}
void MOD2(const char *var1, const char *var2, const char *var3){VarMI[var1[0]] = VarMI[var2[0]] % VarMI[var3[0]];}

void AND(const char *var1, const char *var2){VarMI[var1[0]] *= VarMI[var2[0]];}
void AND2(const char *var1, const char *var2, const char *var3){VarMI[var1[0]] = VarMI[var2[0]] * VarMI[var3[0]];}

void OR(const char *var1, const char *var2){VarMI[var1[0]] |= VarMI[var2[0]];}
void OR2(const char *var1, const char *var2, const char *var3){VarMI[var1[0]] = VarMI[var2[0]] | VarMI[var3[0]];}

void XOR(const char *var1, const char *var2){VarMI[var1[0]] ^= VarMI[var2[0]];}
void XOR2(const char *var1, const char *var2, const char *var3){VarMI[var1[0]] = VarMI[var2[0]] ^ VarMI[var3[0]];}

int main(){ 
    char op[50];
    while(~scanf("%s", op)){
        char temp[50]; scanf("%s", temp);
        if (!strcmp(op, "IN")){char var[5]; int arg; arg = trans(temp, var); IN(var, arg);}
        else if (!strcmp(op, "OUT")){printf("%d\n", VarMI[temp[0]]);}
        else if (!strcmp(op, "MOV")){char var1[5], var2[5];trans2(temp, var1, var2);MOV(var1, var2);}
        else if (!strcmp(op, "XCHG")){char var1[5], var2[5];trans2(temp, var1, var2);XCHG(var1, var2);}

        else{            
            char var1[5], var2[5], var3[5] = {0};
            if (strlen(temp) == 8) trans3(temp, var1, var2, var3);
            else if (strlen(temp) == 5) trans2(temp, var1, var2);
            
            if (!strcmp(op, "ADD"))
                (!strlen(var3))? ADD(var1, var2): ADD2(var1, var2, var3);
            else if (!strcmp(op, "SUB"))
                (!strlen(var3))? SUB(var1, var2): SUB2(var1, var2, var3);
            else if (!strcmp(op, "MUL"))
                (!strlen(var3))? MUL(var1, var2): MUL2(var1, var2, var3);
            // else if (!strcmp(op, "DIV"))
            //     (!strlen(var3))? DIV(var1, var2): DIV2(var1, var2, var3);
            else if (!strcmp(op, "MOD"))
                (!strlen(var3))? MOD(var1, var2): MOD2(var1, var2, var3);
            else if (!strcmp(op, "AND"))
                (!strlen(var3))? AND(var1, var2): AND2(var1, var2, var3);
            else if (!strcmp(op, "OR"))
                (!strlen(var3))? OR(var1, var2): OR2(var1, var2, var3);
            else if (!strcmp(op, "XOR")) 
                (!strlen(var3))? XOR(var1, var2): XOR2(var1, var2, var3);
        }
    }
    return 0;
}