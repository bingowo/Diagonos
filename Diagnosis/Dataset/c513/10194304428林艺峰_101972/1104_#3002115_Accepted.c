#include<string.h>
#include<stdlib.h>
#include<stdio.h>
int reg[256];
char str[110], command[110], line[110];
char *op[] = {"IN", "OUT", "MOV", "XCHG", "ADD", "SUB", "MUL", "DIV", "MOD", "AND", "OR", "XOR"};
int main(){
	int count, temp, o;
	while(gets(line)){
		int l = strlen(line), pos, i;
		for(i = 0; i < l; ++i){
			if(line[i] == ' '){
				pos = i;
				line[i] = 0;
				break;
			}
		}
		strcpy(command, line);
		strcpy(str, line + pos + 1);
		for(i = 0; i < 12; ++i){
			if(!strcmp(command, op[i]))	o = i;
		}
		switch(o){
		case 0:
			reg[str[0]] = atoi(str+3);
		break;
		
		case 1:
			printf("%d\n", reg[str[0]]);
		break;
		
		case 2:
			reg[str[0]] = reg[str[3]];
		break;
		
		case 3:
			temp = reg[str[0]];
			reg[str[0]] = reg[str[3]];
			reg[str[3]] = temp;
		break;
		
		case 4:
			count = (str[5] == ',') ? 3 : 2;
			if(count == 2){
				reg[str[0]] = reg[str[0]] + reg[str[3]];
			}
			else{
				reg[str[0]] = reg[str[3]] + reg[str[6]];
			}
		break;
		
		case 5:
			count = (str[5] == ',') ? 3 : 2;
			if(count == 2){
				reg[str[0]] = reg[str[0]] - reg[str[3]];
			}
			else{
				reg[str[0]] = reg[str[3]] - reg[str[6]];
			}
		break;
		
		case 6:
			count = (str[5] == ',') ? 3 : 2;
			if(count == 2){
				reg[str[0]] = reg[str[0]] * reg[str[3]];
			}
			else{
				reg[str[0]] = reg[str[3]] * reg[str[6]];
			}
		break;
		
		case 7:
			count = (str[5] == ',') ? 3 : 2;
			if(count == 2){
				reg[str[0]] = reg[str[0]] / reg[str[3]];
			}
			else{
				reg[str[0]] = reg[str[3]] / reg[str[6]];
			}
		break;
		
		case 8:
			count = (str[5] == ',') ? 3 : 2;
			if(count == 2){
				reg[str[0]] = reg[str[0]] % reg[str[3]];
			}
			else{
				reg[str[0]] = reg[str[3]] % reg[str[6]];
			}
		break;
		
		case 9:
			count = (str[5] == ',') ? 3 : 2;
			if(count == 2){
				reg[str[0]] = reg[str[0]] & reg[str[3]];
			}
			else{
				reg[str[0]] = reg[str[3]] & reg[str[6]];
			}
		break;
		
		case 10:
			count = (str[5] == ',') ? 3 : 2;
			if(count == 2){
				reg[str[0]] = reg[str[0]] | reg[str[3]];
			}
			else{
				reg[str[0]] = reg[str[3]] | reg[str[6]];
			}
		break;
		
		case 11:
			count = (str[5] == ',') ? 3 : 2;
			if(count == 2){
				reg[str[0]] = reg[str[0]] ^ reg[str[3]];
			}
			else{
				reg[str[0]] = reg[str[3]] ^ reg[str[6]];
			}
		break;
		}
	}
	return 0;
}