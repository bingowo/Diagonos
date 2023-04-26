#include<stdio.h>
#include<math.h>
int length(long long int a,long long int b)
{
    int c=1;
    if(a>=0)
    {
        while(a>=b)
        {
            a=a/b;
            c=c+1;
        }
    }
    else
    {
        a=a*(-1);
        c=2;
        while(a>b)
        {
            a=a/b;
            c=c+1;
        }
        
    }
        return c;
}
int main()
{
    int number=0;
    scanf("%d",&number);
    char s[number][100];
    long long int f[number][2];
    for(int i=0;i<number;i++)
    {
        scanf("%lld%lld",&f[i][1],&f[i][2]);
        long long int a=abs(f[i][1]);
        long long int b=f[i][2];
        int c=length(f[i][1],b);
        long long int e[c];
        for(int j=0;j<c;j++)
        {
            e[j]=a%b;
            a=a/b;
        }
        if(f[i][1]>=0)
        {
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
        else
        {
        	s[i][0]='-';
            for(int k=0;k<c-1;k++)
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
        
    }
    for(int i=0;i<number;i++)
    {
        int l=length(f[i][1],f[i][2]);
        if(length(f[i][1],f[i][2])==1)
        {
            printf("%c\n",s[i][0]);
        }
        else
        {
            printf("%s\n",s[i]);
        }
    }
    return 0;
}