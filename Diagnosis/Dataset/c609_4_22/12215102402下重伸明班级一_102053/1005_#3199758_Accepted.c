#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[100];
        scanf("%s", s);
        int len= strlen(s);
        int n=1,sum=0;
        for(int j=len-1;j>=0;j--)
        {
            if(s[j]=='-')
            {
                sum=sum-n;
            }
            if(s[j]=='0')
            {
                sum=sum+0;
            }
            if(s[j]=='1')
            {
                sum=sum+n;
            }
            n=n*3;
        }
        printf("case #%d:\n",i);
        printf("%d\n",sum);
    }
    
    
}