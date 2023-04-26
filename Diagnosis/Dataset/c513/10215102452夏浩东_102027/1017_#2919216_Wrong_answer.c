#include <stdio.h>
int main()
{
    char s[51];
    long long int res=0;
    long long int mul=1;
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='I'){
        	if(s[i+1]=='V'||s[i+1]=='X') res-=1*mul;
            else res+= 1*mul;
		}
        else if(s[i]=='V') res+=5*mul;
    	else if(s[i]=='X'){
    		if(s[i+1]=='L' || s[i+1]=='C') res-=10*mul;
            else res+=mul*10;
		}
        else if (s[i]=='L') res+=50*mul;
        else if(s[i]=='C'){
        	if(s[i+1]=='D' || s[i+1]=='M') res-=100*mul;
            else res+=100*mul;
		}
    	else if(s[i]=='D') res+=500*mul;
    	else if(s[i]=='M') res+=1000*mul;
        else if(s[i]=='(') mul*=1000;
        else if(s[i]==')') mul/=1000;
    }
    printf("%lld",res);
    return 0;
}