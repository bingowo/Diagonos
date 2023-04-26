#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define IN 0
#define MOV 1
#define ADD 2
#define SUB 3
#define MUL 4
#define DIV 5
#define OUT 6
int cmd_num(char s[])
{
	int cmd = 0;
	if(strcmp(s, "IN") == 0){
	cmd = IN;
	}else if(strcmp(s, "MOV") == 0){
	cmd = MOV;
	}else if(strcmp(s, "ADD") == 0){
	cmd = ADD;
	}else if(strcmp(s, "SUB") == 0){
	cmd = SUB;
	}else if(strcmp(s, "MUL") == 0){
	cmd = MUL;
	}else if(strcmp(s, "DIV") == 0){
	cmd = DIV;
	}else if(strcmp(s, "OUT") == 0){
	cmd = OUT;
	}
	return cmd;
}
int main()
{
	char cmd[5],R[10];
	int r[4]={0};
	while(scanf("%s %s",cmd,R)!=EOF){
		int n = cmd_num(cmd);		
		switch(n){
			case IN:
				r[R[0]-'A'] = atoi(R+3);break;
			case MOV:
				r[R[0]-'A'] = r[R[3]-'A'];break;
			case ADD:
				r[R[0]-'A'] += r[R[3]-'A'];break;
			case SUB:
				r[R[0]-'A'] -= r[R[3]-'A'];break;
			case MUL:
				r[R[0]-'A'] *= r[R[3]-'A'];break;
			case DIV:
				r[R[0]-'A'] /= r[R[3]-'A'];break;
			case OUT:
				printf("%d",r[R[0]-'A']);break;
		}
		
	}
	return 0;
}