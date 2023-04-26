#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
char s[105];
int max(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}
int main()
{
    int n,i,len=0,f=-1,maxn=0;
    scanf("%s",s);
    i=0;
    while(s[i])
    {
        if(s[i]>='1'&&s[i]<='9')
        {
            len++;i++;
            while(s[i]>='0'&&s[i]<='9'&&s[i])
            {len++;i++;}
            maxn=max(maxn,len);
            len=0;
        }
        else
            i++;
    }
    printf("%d",maxn);
    return 0;
}
