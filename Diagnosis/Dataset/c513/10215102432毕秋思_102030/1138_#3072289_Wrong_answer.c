#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int a,b;
    char n[100],ans[100];
    scanf("%d%s",&a,&n);
    long long t=0;
    int len=strlen(n);
    for(int i=0;i<len;i++)
    {
        if(n[i]>='a'&&n[i]<='f')
        {
            n[i]-=87;
        }
        else if(n[i]>='A'&&n[i]<='F')
        {
            n[i]-=55;
        }
        else
        {
            n[i]-='0';
        }
        t=t*a+n[i];
    }
    printf("%lld",t);
    return 0;
}
