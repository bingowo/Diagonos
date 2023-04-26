#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stack[120];int sp=0;
char s[120];
int main()
{	
	int pro;scanf("%d",&pro);getchar();
	while(pro--){
		fgets(s,120,stdin);
		int i=0;int tag=0;
		while(s[i]!='\n' && tag!=-1){
			char c=s[i];
			if(c=='(' || c=='[' || c=='{')stack[sp++]=c;
			else{
				switch(c){
					case(')'):{
						if(stack[sp-1]=='('){
							sp--;
							if(!(sp==0 || stack[sp-1]=='['))tag=-1;
						}
						else tag=-1;
						break;
					}
					case(']'):{
						if(stack[sp-1]=='['){
							sp--;
							if(!(sp==0 || stack[sp-1]=='{'))tag=-1;
						}
						else tag=-1;
						break;
					}
					case('}'):{
						if(stack[sp-1]=='{'){
							sp--;
							if(!(sp==0 || stack[sp-1]=='('))tag=-1;
						}
						else tag=-1;
						break;
					}
				}
			}
			i++;
		}
		if(tag==-1 || sp!=0)printf("No\n");
		else printf("Yes\n");
		sp=0;
	}
	return 0;
}