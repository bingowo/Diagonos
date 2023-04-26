#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    char a[100007], l;
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
}ss;
char s[107];
int main()
{
   	int t; scanf("%d",&t);
	while(t--){
		ss.l = 0;
		scanf("%s",s);
		int len = strlen(s);
		bool ans = 1;
		for(int i = 0; i < len; i++){
			if(ss.empty()){
				ss.push(s[i]);
				continue;
			}
			if(s[i]=='{' || s[i] == '(' || s[i] == '['){
				if(s[i] == '{'){
					if(ss.top()!='('){
						ans = 0;
						break;	
					}else{
						ss.push(s[i]);
					}
				}else if(s[i] == '['){
					if(ss.top()!='{'){
						ans = 0;
						break;
					}else{
						ss.push(s[i]);
					}
				}else{
					if(ss.top()!='['){
						ans = 0;
						break;
					}else{
						ss.push(s[i]);
					}
				}
			}else{
				char topc = ss.top();
				if(s[i] == '}'){
					if(topc != '{'){
						ans = 0;
						break;
					}else{
						ss.pop();
					}
				}else if(s[i] == ')'){
					if(topc != '('){
						ans = 0;
						break;
					}else{
						ss.pop();
					}
				}else{
					if(topc != '['){
						ans = 0;
						break;
					}else{
						ss.pop();
					}
				}
			}
		}
		if(ans&&ss.empty()){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	} 
	return 0;
}