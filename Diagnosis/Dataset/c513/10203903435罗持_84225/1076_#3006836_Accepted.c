#include <stdio.h>
#include <string.h>
int T;
int main(void)
{
	scanf("%d",&T);
	while(T--){
		char s[111] = {0};
		char st[111] = {0};
		int top = 0;
		scanf("%s",s);
		int n = strlen(s);
		int flag = 1;
		for(int i=0;i<n;i++){
			//printf("%d %d\n",i,flag);
			if(top==0){
				st[++top] = s[i];
				continue;
			}
			switch (s[i]){
				case '(':
					if(st[top]=='[') st[++top] = '(';
					else flag = 0;
					break;
				case ')':
					if(st[top]=='(') top--;
					else flag = 0;
					break;
				case '[':
					if(st[top]=='{') st[++top] = '[';
					else flag = 0;
					break;
				case ']':
					if(st[top]=='[') top--;
					else flag = 0;
					break;
				case '{':
					if(st[top]=='(') st[++top] = '{';
					else flag = 0;
					break;
				case '}':
					if(st[top]=='{') top--;
					else flag = 0;
					break;
			}
		}
		if(flag && top==0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}