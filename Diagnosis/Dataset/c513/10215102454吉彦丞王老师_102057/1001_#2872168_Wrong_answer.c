#include<stdio.h>
int length(long long int a,long long int b)
{
    int c=1;
    while(a>b)
    {
        a=a/b;
        c=c+1;
    }
    return c;
}
int main()
{
    int number;
    scanf("%d",&number);
    char s[number][100];
    int a[number][100];
    for(int i=0;i<number;i++)
    {
        long long int a;
        long long int b;
        scanf("%lld%d",&a,&b);
        int c=length(a,b);
        long long int e[c];
        for(int j=0;j<c;j++)
        {
            e[j]=a%b;
            a=a/b;
        }
        for(int k=0;k<c;k++)
        {
            if(e[k]<10)
            {
                s[i][c-k-1]=e[k]+'0';
            }
            else
            {
                int deep=e[k]-10;
                s[i][c-k-1]=17+deep+'0';
            }
        }
        
    }
    for(int i=0;i<number;i++)
    {
        for(int j=0;j<99;j++)
        {
            printf("%c",s[i][j]);
        }
        printf("%c",s[i][99]);
    }
    return 0;
    
    
}