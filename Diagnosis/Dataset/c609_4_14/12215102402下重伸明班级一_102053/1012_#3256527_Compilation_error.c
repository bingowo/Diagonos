#include<stdio.h>
#include<string.h>
int main()
{
    int x,len,e,y=0;
    scanf("%d",&x);
    for(int i=0;i<x;i++)
    {
        e=1;
        char m[100];
        double s=1;
        scanf("%s",&m);
        len=strlen(m);
        for(int i=2;i<len;i++)
        {
            y=y*8+m[i];
            e=e*8;
        }
        s=(s/e)*y;
    }
    printf("%lf",s);
}