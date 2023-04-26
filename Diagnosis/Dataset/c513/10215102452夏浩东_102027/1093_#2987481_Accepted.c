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
int func(int* L,int length)
{
    int count=0;
    int res=length-1;
    for(int i=length-1;i>=0;i--)
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
void fun(int* L,int len)
{
	add(L,102,1);
    int res = func(L,103);
    int sum = 0;
    for(int i=0;i<=res;i++) sum+=L[i];
    for(int i=res+1;i<103;i++) L[i]=0;
    if(len!=1){
		if(sum%9==0 && res!=102) L[102]=1;
		else if(sum%9==0 && res==102) fun(L,len);
		else if(sum%9!=0 && res!=102) L[102]=0;
	}
	return; 
}
int main()
{
    char s[102];
    scanf("%s",s);
    int L[103];
    for(int i=0;i<103;i++) L[i]=0;
    int k=102,len=(int)strlen(s);
    for(int i=len-1;i>=0;i--)
    {
        L[k--]=s[i]-'0';
    }
    fun(L,len);
    int zero=0;
    for(int i=0;L[i]==0;i++) zero++;
    for(int i=zero;i<103;i++) printf("%d",L[i]);
    return 0;
}

