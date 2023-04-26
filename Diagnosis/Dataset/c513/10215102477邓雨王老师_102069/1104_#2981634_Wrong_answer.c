#include<stdio.h>
#include<string.h>
#include<stdlib.h>   //因为要用到atoi（把字符串转换为 
//数据操控指令
#define IN 0
#define OUT 1
#define MOV 2
#define XCHG 3
//运算指令
#define ADD 4
#define SUB 5
#define MUL 6
#define DIV 7
#define MOD 8
#define AND 9
#define OR 10
#define XOR 11
int readorder(char s[]){            //用来读取指令类型 
int ret = 0;
if(strcmp(s, "ADD") == 0){ret = ADD;}
else if(strcmp(s, "SUB") == 0){ret = SUB;}
else if(strcmp(s, "MUL") == 0){ret = MUL;}
else if(strcmp(s, "DIV") == 0){ret = DIV;}
else if(strcmp(s, "MOD") == 0){ret = MOD;}
else if(strcmp(s, "AND") == 0){ret = AND;}
else if(strcmp(s, "OR") == 0){ret = OR;}
else if(strcmp(s, "XOR") == 0){ret = XOR;}
else if(strcmp(s, "IN") == 0){ret = IN;}
else if(strcmp(s, "OUT") == 0){ret = OUT;}
else if(strcmp(s, "MOV") == 0){ret = MOV;}
else if(strcmp(s, "XCHG") == 0){ret = XCHG;}
return ret;
}
int readreg(char s[]){return s[0] - 'A';}
int main(){
	char order[5],reg[20];
	int x[26]={0};
	while(scanf("%s %s",&order,&reg)!=EOF){
		int order1=readorder(order),y1,y2,y3; //order1表明了操控指令的类型，y1,y2,y3代表了三个可能的参数（因为运算指令中最多只有三个参数）
		switch(order1){
			case IN:
				y1=readreg(reg);
				x[y1]=atoi(reg+3);
				break;
			case OUT:
				y1=readreg(reg);
				printf("%d\n",x[y1]);
				break;
			case MOV:
				y1=readreg(reg);
				y2=readreg(reg+3);
				x[y1]=x[y2];
				break;
			case XCHG:
				y1=readreg(reg);
				y2=readreg(reg+3);
				int temp;
				temp=x[y2];
				x[y2]=x[y1];
				x[y1]=temp;
				break;
			case ADD:
				if(strlen(reg)==5){  //只有两个参数的情况 
					y1=readreg(reg);
					y2=readreg(reg);
					x[y1]+=x[y2];
				}
				else{
					y1=readreg(reg); //有三个参数的情况 
					y2=readreg(reg+3);
					y3=readreg(reg+6);
					x[y1]=x[y2]+x[y3]; 
				}
				break;
			case SUB:
				if(strlen(reg)==5){  //只有两个参数的情况 
					y1=readreg(reg);
					y2=readreg(reg);
					x[y1]-=x[y2];
				}
				else{
					y1=readreg(reg); //有三个参数的情况 
					y2=readreg(reg+3);
					y3=readreg(reg+6);
					x[y1]=x[y2]-x[y3]; 
				}
				break;
			case MUL:
				if(strlen(reg)==5){  //只有两个参数的情况 
					y1=readreg(reg);
					y2=readreg(reg);
					x[y1]*=x[y2];
				}
				else{
					y1=readreg(reg); //有三个参数的情况 
					y2=readreg(reg+3);
					y3=readreg(reg+6);
					x[y1]=x[y2]*x[y3]; 
				}
				break;
			case DIV:
				if(strlen(reg)==5){  //只有两个参数的情况 
					y1=readreg(reg);
					y2=readreg(reg);
					x[y1]/=x[y2];
				}
				else{
					y1=readreg(reg); //有三个参数的情况 
					y2=readreg(reg+3);
					y3=readreg(reg+6);
					x[y1]=x[y2]/x[y3]; 
				}
				break;
			case MOD:
				if(strlen(reg)==5){  //只有两个参数的情况 
					y1=readreg(reg);
					y2=readreg(reg);
					x[y1]=x[y1]%x[y2];
				}
				else{
					y1=readreg(reg); //有三个参数的情况 
					y2=readreg(reg+3);
					y3=readreg(reg+6);
					x[y1]=x[y2]%x[y3]; 
				}
				break;
			case AND:
				if(strlen(reg)==5){  //只有两个参数的情况 
					y1=readreg(reg);
					y2=readreg(reg);
					x[y1]=x[y1]&x[y2];
				}
				else{
					y1=readreg(reg); //有三个参数的情况 
					y2=readreg(reg+3);
					y3=readreg(reg+6);
					x[y1]=x[y2]&x[y3]; 
				}
				break;
			case OR:
				if(strlen(reg)==5){  //只有两个参数的情况 
					y1=readreg(reg);
					y2=readreg(reg);
					x[y1]=x[y1]|x[y2];
				}
				else{
					y1=readreg(reg); //有三个参数的情况 
					y2=readreg(reg+3);
					y3=readreg(reg+6);
					x[y1]=x[y2]|x[y3]; 
				}
				break;
			case XOR:
				if(strlen(reg)==5){  //只有两个参数的情况 
					y1=readreg(reg);
					y2=readreg(reg);
					x[y1]=x[y1]^x[y2];
				}
				else{
					y1=readreg(reg); //有三个参数的情况 
					y2=readreg(reg+3);
					y3=readreg(reg+6);
					x[y1]=x[y2]^x[y3]; 
				}
				break;
		} 
	}
	return 0;
} 