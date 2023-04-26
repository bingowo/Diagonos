#include <stdio.h>
#include <string.h>
void mul(int* L,int num)
{
    int left=0;
    for(int i=399;i>=0;i--)
    {
        int temp = L[i]*num+left;
        L[i] = temp%10;
        left = temp/10;
    }
}
int main()
{
    char s[1001];
    scanf("%s",s);
    int len = strlen(s);
    int L[400];
    for(int i=0;i<399;i++) L[i]=0;
    L[399]=1;
    if(len!=1 && s[0]!=s[1]) mul(L,2);
    for(int i=1;i<len-1;i++)
	{
		if(s[i]!=s[i-1] && s[i]!=s[i+1] && s[i-1]!=s[i+1] ) mul(L,3);
		else if(s[i]==s[i-1] && s[i]==s[i+1]) continue;
		else mul(L,2);
	}
    if(len>=2 && s[len-1]!=s[len-2]) mul(L,2);	
    int zero=0;
    for(zero=0;L[zero]==0;zero++) continue;
    if(len!=1) for(int i=zero;i<400;i++) printf("%d",L[i]);
    else printf("1");
}