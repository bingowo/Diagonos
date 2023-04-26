#include <stdio.h>
#include <string.h>
int stack[110];
int sp = 0;
void push(int c){ stack[sp++] = c;}   //pop和push需要自己定义
int pop(void){ return stack[--sp];}
int isEmpty(void){ return sp == 0;}  //当栈为空时，返回1，否则返回0  用来判断栈是否为空 
int top(void){ return stack[sp - 1];}
void clear(void)                     //用来清空栈 
{
	memset(stack, 0, sizeof(stack));
	sp = 0;
}

int main(void)
{
	int t;
	scanf("%d", &t);
	char c=getchar();
	int i;
	for(i = 0 ; i < t; i ++){
		int isPerfect = 1; 
		while((c = getchar()) != '\n'){
			if(c == '(' || c == '[' || c == '{'){
				if(c == '(' &&!isEmpty()){           //看前面的那个括号是不是符合要求，就BREAK了！ 
					if(top() != '['){
						isPerfect = 0;
					}
				}else if(c == '[' && !isEmpty()){
					if(top() != '{'){
						isPerfect = 0;
					}
				}else if(c == '{' && !isEmpty()){
					if(top() != '('){
						isPerfect = 0;
					}
				}
				push(c);
			}else{
				if(c == ')' && top() == '('){
					pop();
				}else if(c == ']' && top() == '['){
					pop();
				}else if(c == '}' && top() == '{'){
					pop();
				}else{
					push(c);
				}
			}
		}
		if(!isEmpty()){
			isPerfect = 0;
			clear();
		}
		if(isPerfect){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}