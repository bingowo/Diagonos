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
#define XCHG 7
#define AND 8
#define OR 9
#define XOR 10
#define MOD 11
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
	}else if(strcmp(s, "XCHG") == 0){
	cmd = XCHG;
	}else if(strcmp(s, "AND") == 0){
	cmd = AND;
	}else if(strcmp(s, "OR") == 0){
	cmd = OR;
	}else if(strcmp(s, "XOR") == 0){
	cmd = XOR;
	}else if(strcmp(s, "MOD") == 0){
	cmd = MOD;
	}
	return cmd;
}
int main()
{
	char cmd[5],R[10];
	int r[26]={0};
	int t;
	while(scanf("%s %s",cmd,R)!=EOF){
		int n = cmd_num(cmd);
		int len = strlen(R)	;	
		switch(n){
			case IN:
				r[R[0]-'A'] = atoi(R+3);break;
			case MOV:
				r[R[0]-'A'] = r[R[3]-'A'];break;
			case ADD:
				if(len>5)
					r[R[0]-'A'] = r[R[3]-'A'] + r[R[6]-'A'];
				else
					r[R[0]-'A'] += r[R[3]-'A'];break;
			case SUB:
				if(len>5)
					r[R[0]-'A'] = r[R[3]-'A'] - r[R[6]-'A'];
				else
					r[R[0]-'A'] -= r[R[3]-'A'];break;
			case MUL:
				if(len>5)
					r[R[0]-'A'] = r[R[3]-'A'] * r[R[6]-'A'];
				else
					r[R[0]-'A'] *= r[R[3]-'A'];break;
			case DIV:
				if(len>5)
					r[R[0]-'A'] = r[R[3]-'A'] / r[R[6]-'A'];
				else
					r[R[0]-'A'] /= r[R[3]-'A'];break;
			case OUT:
				printf("%d\n",r[R[0]-'A']);break;
			case XCHG:
				t = r[R[0]-'A'];
				r[R[0]-'A'] = r[R[3]-'A'];
				r[R[3]-'A'] = t;
			case MOD:
				if(len>5)
					r[R[0]-'A'] = r[R[3]-'A'] % r[R[6]-'A'];
				else
					r[R[0]-'A'] = r[R[0]-'A']%r[R[3]-'A'];break;
			case AND:
				if(len>5)
					r[R[0]-'A'] = r[R[3]-'A'] & r[R[6]-'A'];
				else
					r[R[0]-'A'] = r[R[0]-'A'] & r[R[3]-'A'];break;
			case OR:
				if(len>5)
					r[R[0]-'A'] = r[R[3]-'A'] | r[R[6]-'A'];
				else
					r[R[0]-'A'] = r[R[0]-'A'] | r[R[3]-'A'];break;
			case XOR:
				if(len>5)
					r[R[0]-'A'] = r[R[3]-'A'] ^ r[R[6]-'A'];
				else
					r[R[0]-'A'] = r[R[0]-'A'] ^ r[R[3]-'A'];break;
		}
		
	}
	return 0;
}