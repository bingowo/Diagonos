#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Êý¾Ý²Ù¿ØÖ¸Áî
#define IN 0
#define OUT 1
#define MOV 2
#define XCHG 3

//ÔËËãÖ¸Áî 
#define ADD 4
#define SUB 5
#define MUL 6
#define DIV 7
#define MOD 8
#define AND 9
#define OR 10
#define XOR 11

int ReadOrder(char s[])
{
	int ret = 0;
	if(strcmp(s, "ADD") == 0){
		ret = ADD;
	}else if(strcmp(s, "SUB") == 0){
		ret = SUB;
	}else if(strcmp(s, "MUL") == 0){
		ret = MUL;
	}else if(strcmp(s, "DIV") == 0){
		ret = DIV;
	}else if(strcmp(s, "MOD") == 0){
		ret = MOD;
	}else if(strcmp(s, "AND") == 0){
		ret = AND;
	}else if(strcmp(s, "OR") == 0){
		ret = OR;
	}else if(strcmp(s, "XOR") == 0){
		ret = XOR;
	}else if(strcmp(s, "IN") == 0){
		ret = IN;
	}else if(strcmp(s, "OUT") == 0){
		ret = OUT;
	}else if(strcmp(s, "MOV") == 0){
		ret = MOV;
	}else if(strcmp(s, "XCHG") == 0){
		ret = XCHG;
	}
	
	return ret;
}

int ReadReg(char s[])
{
	return s[0] - 'A';
}

int main(void)
{
	int x[26] = {0};
	char order[100], reg[100];
	while(scanf("%s %s", order, reg) != EOF){
		int o = ReadOrder(order), r1, r2, r3;
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
			case OUT:
				r1 = ReadReg(reg);
				printf("%d\n", x[r1]);
				break;
			case XCHG:
				r1 = ReadReg(reg);
				r2 = ReadReg(reg + 3);								
				int temp;
				temp = x[r1];
				x[r1] = x[r2];
				x[r2] = x[r1];
			case ADD:
				if(strlen(reg) == 5){
					r1 = ReadReg(reg);
					r2 = ReadReg(reg + 3);
					x[r1] = x[r1] + x[r2];					
				}else{
					r1 = ReadReg(reg);
					r2 = ReadReg(reg + 3);
					r3 = ReadReg(reg + 6);
					x[r1] = x[r2] + x[r3];						
				}
				break;
			case SUB:
				if(strlen(reg) == 5){
					r1 = ReadReg(reg);
					r2 = ReadReg(reg + 3);
					x[r1] = x[r1] - x[r2];					
				}else{
					r1 = ReadReg(reg);
					r2 = ReadReg(reg + 3);
					r3 = ReadReg(reg + 6);
					x[r1] = x[r2] - x[r3];						
				}
				break;
			case MUL:
				if(strlen(reg) == 5){
					r1 = ReadReg(reg);
					r2 = ReadReg(reg + 3);
					x[r1] = x[r1] * x[r2];					
				}else{
					r1 = ReadReg(reg);
					r2 = ReadReg(reg + 3);
					r3 = ReadReg(reg + 6);
					x[r1] = x[r2] * x[r3];						
				}
				break;
			case DIV:
				if(strlen(reg) == 5){
					r1 = ReadReg(reg);
					r2 = ReadReg(reg + 3);
					x[r1] = x[r1] / x[r2];					
				}else{
					r1 = ReadReg(reg);
					r2 = ReadReg(reg + 3);
					r3 = ReadReg(reg + 6);
					x[r1] = x[r2] / x[r3];						
				}
				break;
			case MOD:
				if(strlen(reg) == 5){
					r1 = ReadReg(reg);
					r2 = ReadReg(reg + 3);
					x[r1] = x[r1] % x[r2];					
				}else{
					r1 = ReadReg(reg);
					r2 = ReadReg(reg + 3);
					r3 = ReadReg(reg + 6);
					x[r1] = x[r2] % x[r3];						
				}
				break;
			case AND:
				if(strlen(reg) == 5){
					r1 = ReadReg(reg);
					r2 = ReadReg(reg + 3);
					x[r1] = x[r1] & x[r2];					
				}else{
					r1 = ReadReg(reg);
					r2 = ReadReg(reg + 3);
					r3 = ReadReg(reg + 6);
					x[r1] = x[r2] & x[r3];						
				}
				break;
			case OR:
				if(strlen(reg) == 5){
					r1 = ReadReg(reg);
					r2 = ReadReg(reg + 3);
					x[r1] = x[r1] | x[r2];					
				}else{
					r1 = ReadReg(reg);
					r2 = ReadReg(reg + 3);
					r3 = ReadReg(reg + 6);
					x[r1] = x[r2] | x[r3];						
				}
				break;
			case XOR:
				if(strlen(reg) == 5){
					r1 = ReadReg(reg);
					r2 = ReadReg(reg + 3);
					x[r1] = x[r1] ^ x[r2];					
				}else{
					r1 = ReadReg(reg);
					r2 = ReadReg(reg + 3);
					r3 = ReadReg(reg + 6);
					x[r1] = x[r2] ^ x[r3];						
				}
				break;
		}
	}
	
	return 0;
}