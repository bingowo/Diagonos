#include<stdio.h>

void solve(int x)
{
    int a,b;
    scanf("%d %d",&a,&b);
    int s[100]={0};
    s[0]=1;
    int i,k,flag=0;
    for(i=0;i<b;++i)
    {
        for(k=0;k<100;k++)
        {
            s[k]=s[k]*a;
        }
        for(k=0;k<100;++k)
        { 
            s[k]=s[k]+flag;
            flag=0;
            if(s[k]>=10)
            {
                flag=s[k]/10;
                s[k]=s[k]%10;
            }
            else
            {
                flag=0;
            }
        }
    }
    
    for(i=99;s[i]==0;--i);
        printf("case #%d:\n",x);
    for(;i>=0;--i)printf("%d",s[i]);
        printf("\n");
}

int main()
{
    int T,i;
    scanf("%d",&T);
    getchar();
    for(i=0;i<T;++i)
    {
        solve(i);
    }
}