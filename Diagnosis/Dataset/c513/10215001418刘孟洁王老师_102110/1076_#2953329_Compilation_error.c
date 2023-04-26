#include <stdio.h>
using namespace std;
char s[107];
int main()
{
   	int t; scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		stack<char> ss;
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