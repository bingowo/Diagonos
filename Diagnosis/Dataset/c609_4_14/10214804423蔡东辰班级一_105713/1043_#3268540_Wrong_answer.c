#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	int T, state = 0;
	int ls[100] = {0};
	scanf("%d", &T);
	char c;
	char check[128] = {0};
	check['}'] = '{';
	check[')'] = '(';
	check[']'] = '[';
	char s[101] = {0};
	while(T--){
		int cnt = -1;
		int start = 0;
		char s[101] = {0};
		scanf("%s", s);
		for(int i = 0; c = s[i]; i++){
			//ls用于记录上一次的状态。
			switch(state){
				case 0:// 初始状态,只接受左括号，匹配后回到0
					ls[++cnt] = state;
					if(c == '{'){state = 1; break;} 
					else if(c == '['){state = 2; break;}
					else if(c == '('){state = 3; break;}
					else if(check[c] == s[start]){
						start = i+1;
						break;
					}
					else {state = 4; break;}//No;
				case 1://意味着外层是一个{，只接受[ 和 }
					if(c == '}') {state = ls[cnt--]; break;}
					else if(c == '[') {ls[++cnt] = state; state = 2; break;}
					else {state = 4; break;}//No
				case 2://意味着外层是一个[，只接受( 和 ]
					if(c == ']') {state = ls[cnt--]; break;}
					else if(c == '(') {ls[++cnt] = state; state = 3; break;}
					else {state = 4; break;}					
				case 3://意味着外层是一个(, 只接受{和)
					if(c == ')') {state = ls[cnt--]; break;}
					else if(c == '{') {ls[++cnt] =  state; state = 1; break;}
					else {state = 4; break;}
				case 4:
					break;
			}
		}
		if(state == 4){
			printf("No\n");
		}
		if(state == 0){
			printf("Yes\n");
		}
	}
	return 0;
}