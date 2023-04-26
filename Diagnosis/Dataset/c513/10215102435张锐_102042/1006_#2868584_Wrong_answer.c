#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long unsigned power(int base,int n)
{
    int i;
    long long int p;
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
        long long unsigned sum;
        for(int j=0;j<num;j++)
        {
            if(s[j]=='-') sum+=(-1)*power(3,num-1-j);
            else if(s[j]=='0') ;
            else if(s[j]==1) sum+=power(3,num-1-j);
        }
        printf("case #%d\n%llu\n",i,sum);
    }
    return 0;
}
