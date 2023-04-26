#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
double poland(void); 
int main(){
	int T;
	scanf("%d",&T);
	for(int i = 0;i < T;i++){
		printf("case #%d:\n",i);
		printf("%.6lf\n",poland());
	}
	return 0;
}
double poland(void){
	char a[10];
	double stack[101];
	char state[101];
	int cnt = 0;
	int num = 0;
	double operand_a,operand_b;
	int flag = 1; 
	while(flag && scanf("%s",a) == 1){
		//printf("%s\n",a);
		switch(a[0]){
			case'+':
				state[num++] = '+';
				break;
			case'-':
				state[num++] = '-';
				break;
			case'*':
				state[num++] = '*';
				break;
			case'/':
				state[num++] = '/';
				break;
			default:
				operand_a = atof(a);
				if(state[num-1] == '1'){                       //标记数字 
					num--;     
					operand_b = stack[--cnt];
					switch(state[--num]){                                 
						case'+':
							stack[cnt++] = operand_b + operand_a;
							state[num++] = '1';                            //仍标记为数字 
							break;
						case'-':
							stack[cnt++] = operand_b - operand_a;
							state[num++] = '1';
							break;
						case'*':
							stack[cnt++] = operand_b * operand_a;
							state[num++] = '1';
							break;
						case'/':
							stack[cnt++] = operand_b / operand_a;
							state[num++] = '1';
							break;
					}
				}
				else{
					stack[cnt++] = operand_a;
					state[num++] = '1';
				}
				break;
		}
		char c;
		if((c = getchar()) == '\n')       //c为空格或换行符 
			flag = 0;
	}
	return stack[0];
}	
