#include<stdio.h>
#include<string.h>
int main()
{
    int x,len,e,y=0;
    double s;
    scanf("%d",&x);
    for(int i=0;i<x;i++)
    {
        e=1;
        char m[100];
        s=1;
        scanf("%s",&m);
        len=strlen(m);
        for(int i=2;i<len;i++)
        {
            e=e*8;
            y=(m[i]-'0');
            s=s+y/e;
        }
        printf("%lf\n",s);
    }
    
}