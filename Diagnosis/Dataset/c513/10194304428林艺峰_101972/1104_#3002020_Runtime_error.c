#include<string.h>
#include<stdlib.h>
#include<stdio.h>
int reg[110];
char str[110], command[110], line[110];
int main(){
	int count, temp;
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
		if(command[0] == 'I'){
			reg[str[0] - 'A'] = atoi(str+3);
		}
		else if(command[0] == 'O' && command[2] == 'T'){
			printf("%d\n", reg[str[0] - 'A']);
		}
		else if(command[0] == 'M' && command[2] == 'V'){
			reg[str[0] - 'A'] = reg[str[3] - 'A'];
		}
		else if(command[0] == 'X' && command[2] == 'H'){
			temp = reg[str[0] - 'A'];
			reg[str[0] - 'A'] = reg[str[3] - 'A'];
			reg[str[3] - 'A'] = temp;
		}
		else if(command[0] == 'A' && command[2] == 'D'){
			count = (str[5] == ',') ? 3 : 2;
			if(count == 2){
				reg[str[0] - 'A'] = reg[str[0] - 'A'] + reg[str[3] - 'A'];
			}
			else{
				reg[str[0] - 'A'] = reg[str[3] - 'A'] + reg[str[6] - 'A'];
			}
		}
		else if(command[0] == 'S' && command[2] == 'B'){
			count = (str[5] == ',') ? 3 : 2;
			if(count == 2){
				reg[str[0] - 'A'] = reg[str[0] - 'A'] - reg[str[3] - 'A'];
			}
			else{
				reg[str[0] - 'A'] = reg[str[3] - 'A'] - reg[str[6] - 'A'];
			}
		}
		else if(command[0] == 'M' && command[2] == 'L'){
			count = (str[5] == ',') ? 3 : 2;
			if(count == 2){
				reg[str[0] - 'A'] = reg[str[0] - 'A'] * reg[str[3] - 'A'];
			}
			else{
				reg[str[0] - 'A'] = reg[str[3] - 'A'] * reg[str[6] - 'A'];
			}
		}
		else if(command[0] == 'D' && command[2] == 'V'){
			count = (str[5] == ',') ? 3 : 2;
			if(count == 2){
				reg[str[0] - 'A'] = reg[str[0] - 'A'] / reg[str[3] - 'A'];
			}
			else{
				reg[str[0] - 'A'] = reg[str[3] - 'A'] / reg[str[6] - 'A'];
			}
		}
		else if(command[0] == 'M' && command[2] == 'D'){
			count = (str[5] == ',') ? 3 : 2;
			if(count == 2){
				reg[str[0] - 'A'] = reg[str[0] - 'A'] % reg[str[3] - 'A'];
			}
			else{
				reg[str[0] - 'A'] = reg[str[3] - 'A'] % reg[str[6] - 'A'];
			}
		}
		else if(command[0] == 'A' && command[2] == 'D'){
			count = (str[5] == ',') ? 3 : 2;
			if(count == 2){
				reg[str[0] - 'A'] = reg[str[0] - 'A'] & reg[str[3] - 'A'];
			}
			else{
				reg[str[0] - 'A'] = reg[str[3] - 'A'] & reg[str[6] - 'A'];
			}
		}
		else if(command[0] == 'O' && command[1] == 'R'){
			count = (str[5] == ',') ? 3 : 2;
			if(count == 2){
				reg[str[0] - 'A'] = reg[str[0] - 'A'] | reg[str[3] - 'A'];
			}
			else{
				reg[str[0] - 'A'] = reg[str[3] - 'A'] | reg[str[6] - 'A'];
			}
		}
		else if(command[0] == 'X' && command[2] == 'R'){
			count = (str[5] == ',') ? 3 : 2;
			if(count == 2){
				reg[str[0] - 'A'] = reg[str[0] - 'A'] ^ reg[str[3] - 'A'];
			}
			else{
				reg[str[0] - 'A'] = reg[str[3] - 'A'] ^ reg[str[6] - 'A'];
			}
		}
	}
	return 0;
}