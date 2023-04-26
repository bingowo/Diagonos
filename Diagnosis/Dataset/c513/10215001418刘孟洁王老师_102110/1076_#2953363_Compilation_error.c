#include <stdio.h>
#include<stdlib.h>
#include<string.h>
char a[100007];
int l;
void push(char x){
    a[++l] = x;
}
char top(){
    return a[l];
}
void pop(){
    l--;
}
int empty(){
    return l > 0 ? 0 : 1;
}
char s[107];
int main()
{
   	int t; scanf("%d",&t);
	while(t--){
		l = 0;
		scanf("%s",s);
		int len = strlen(s);
		bool ans = 1;
		for(int i = 0; i < len; i++){
			if(empty()){
				push(s[i]);
				continue;
			}
			if(s[i]=='{' || s[i] == '(' || s[i] == '['){
				if(s[i] == '{'){
					if(top()!='('){
						ans = 0;
						break;	
					}else{
						push(s[i]);
					}
				}else if(s[i] == '['){
					if(top()!='{'){
						ans = 0;
						break;
					}else{
						push(s[i]);
					}
				}else{
					if(top()!='['){
						ans = 0;
						break;
					}else{
						push(s[i]);
					}
				}
			}else{
				char topc = top();
				if(s[i] == '}'){
					if(topc != '{'){
						ans = 0;
						break;
					}else{
						pop();
					}
				}else if(s[i] == ')'){
					if(topc != '('){
						ans = 0;
						break;
					}else{
						pop();
					}
				}else{
					if(topc != '['){
						ans = 0;
						break;
					}else{
						pop();
					}
				}
			}
		}
		if(ans&&empty()){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	} 
	return 0;
}