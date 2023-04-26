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
    long long int f[number][2];
    for(int i=0;i<number;i++)
    {
        scanf("%lld%lld",&f[i][1],&f[i][2]);
        long long int a=f[i][1];
        long long int b=f[i][2];
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
                long long int deep=e[k]-10;
                s[i][c-k-1]=17+deep+'0';
            }
        }
        
    }
    for(int i=0;i<number;i++)
    {
        for(int j=0;j<length(f[i][1],f[i][2])-1;j++)
        {
            printf("%c",s[i][j]);
        }
        printf("%c\n",s[i][length(f[i][1],f[i][2])]);
    }
    return 0;
    
    
}