#include<stdio.h>
int length(long long int a,int b)
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
    int a[number][100];
    for(int i=0;i<number;i++)
    {
        long long int a;
        int b;
        scanf("%lld%d",&a,&b);
        int c=length(a,b);
        char s[c];
        if(c==1)
        {
            
        }
        
    }
    
    
}