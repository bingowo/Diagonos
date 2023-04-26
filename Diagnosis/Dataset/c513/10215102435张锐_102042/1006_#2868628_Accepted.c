#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned power(int base,int n)
{
    int i;
    int p;
    p=1;
    for(i=1;i<=n;i++)
        p=p*base;
    return p;
}
int main()
{
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        char s[100];
        scanf("%s",&s);
        int num=strlen(s);
        unsigned sum=0;
        for(int j=0;j<num;j++)
        {
            if(s[j]=='-') sum+=(-1)*power(3,num-1-j);
            else if(s[j]=='0') ;
            else if(s[j]=='1') sum+=power(3,num-1-j);
        }
        printf("case #%d:\n%u\n",i,sum);
    }
    return 0;
}
