#include <stdio.h>
#include <string.h>
void add(int* L,int k,int num)
{
    int left=num;
    for(int i=k;i>=0;k--)
    {
        int temp = L[k]+left;
        L[k] = temp%10;
        left = temp/10;
        if(left==0) break;
    }
    return;
}
int func(int* L,int len)
{
    int count=0;
    int res=len-1;
    for(int i=len-1;i>=0;i--)
    {
        if(L[i]==9 && count==0){
            add(L,i,1);
            res=i;
            count=1;
        }
        else if(L[i]==9 && count==1){
            add(L,i,1);
        }
    }
    return res;
}
int main()
{
    char s[101];
    scanf("%s",s);
    int L[100];
    for(int i=0;i<100;i++) L[i]=0;
    int k=99,len=(int)strlen(s);
    for(int i=len-1;i>=0;i--)
    {
        L[k--]=s[i]-'0';
    }
    add(L,99,1);
    int res = func(L,100);
    int sum = 0;
    for(int i=0;i<=res;i++) sum+=L[i];
    for(int i=res+1;i<99;i++) L[i]=0;
    if(len!=1){
		if(sum%9==0) L[99]=1;
		else L[99]=0;
	}
    int zero=0;
    for(int i=0;L[i]==0;i++) zero++;
    for(int i=zero;i<100;i++) printf("%d",L[i]);
    return 0;
}

