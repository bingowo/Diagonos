#include<stdio.h>
#include<string.h>
long long func1(char c)
{
	long long ret;
	switch(c){
		case 'I':	ret = 1;	break;
		case 'V':	ret = 5;	break;
		case 'X':	ret = 10;	break;
		case 'L':	ret = 50;	break;
		case 'C':	ret = 100;	break;
		case 'D':	ret = 500;	break;
		case 'M':	ret = 1000;	break;
	}
	
	return ret;
}
int main(){
    char s[100];
    scanf("%s",&s);
    long long sum=0;
    int length=strlen(s);
    int i;
    long long n=1;
    for(i=strlen(s)-1;i>=0;i--){
    	if(s[i]==')'){
    		n=n*1000;
		}
		else if(s[i]=='(') n=n/1000;
		else if(s[i]!='('&&s[i]!=')'){
			/*if((s[i+1]=='('&&func1(s[i]>sum))||(s[i+1]==')'&&func1(s[i]>sum))) sum=sum+func1(s[i])*n;
			else if((s[i+1]=='('&&func1(s[i]<sum))||(s[i+1]==')'&&func1(s[i]<sum))) sum=sum-func1(s[i])*n;*/
			if(s[i+1]=='\0'&&s[i]!='('&&s[i]!=')') sum=sum+func1(s[i])*n;
			else if(s[i+1]==s[i]) sum=sum+func1(s[i])*n;
			else{
				if(sum>func1(s[i])) sum=sum-func1(s[i])*n;
				else sum=sum+func1(s[i])*n;
			}
		}
	}
	if(sum<0) sum=-sum;
	printf("%lld",sum);
} 