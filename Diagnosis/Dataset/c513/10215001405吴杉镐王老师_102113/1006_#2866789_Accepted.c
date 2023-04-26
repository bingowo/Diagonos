#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int x;
    scanf("%d",&x);
    int y=0;
    while(y<x)
    {
        printf("case #%d:\n",y);
        y++;
        char s[100]={'\0'};
        scanf("%s",s);
        unsigned long l=strlen(s);
        int sum=0;
        for(int i=0;i<l;i++)
        {
            if(s[i]=='-') sum=sum-pow(3,l-i-1);
            else if(s[i]=='1') sum=sum+pow(3,l-i-1);
            else ;
        }
        printf("%d\n",sum);
    }
}