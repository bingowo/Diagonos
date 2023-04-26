#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define IN 0
#define MOV 1
#define ADD 2
#define SUB 3
#define MUL 4
#define DIV 5
#define OUT 6
int ReadOrder(char s[])
{
int ret = 0;
if(strcmp(s, "IN") == 0){
ret = IN;
}else if(strcmp(s, "MOV") == 0){
ret = MOV;
}else if(strcmp(s, "ADD") == 0){
ret = ADD;
}else if(strcmp(s, "SUB") == 0){
ret = SUB;
}else if(strcmp(s, "MUL") == 0){
ret = MUL;
}else if(strcmp(s, "DIV") == 0){
ret = DIV;
}else if(strcmp(s, "OUT") == 0){
ret = OUT;
}
return ret;
}
int ReadReg(char s[]){ return s[0] - 'A';}
int main(void) {
int x[4] = {0};
char order[4], reg[100];
while(scanf("%s %s", order, reg) != EOF){
int o = ReadOrder(order), r1, r2;
switch(o){
case IN:
r1 = ReadReg(reg);
x[r1] = atoi(reg + 3);
break;
case MOV:
r1 = ReadReg(reg);
r2 = ReadReg(reg + 3);
x[r1] = x[r2];
break;
case ADD:
r1 = ReadReg(reg);
r2 = ReadReg(reg + 3);
x[r1] = x[r1] + x[r2];
break;
case SUB:
r1 = ReadReg(reg);
r2 = ReadReg(reg + 3);
x[r1] = x[r1] - x[r2];
break;
case MUL:
r1 = ReadReg(reg);
r2 = ReadReg(reg + 3);
x[r1] = x[r1] * x[r2];
break;
case DIV:
r1 = ReadReg(reg);
r2 = ReadReg(reg + 3);
x[r1] = x[r1] / x[r2];
break;
case OUT:
r1 = ReadReg(reg);
printf("%d\n", x[r1]);
break; } }
return 0; }