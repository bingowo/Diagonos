#include<stdio.h>
#include<string.h>
int main()
{
    int b;
    scanf("%d",&b);
    int i;
    char* a;
    for(i=0;i<b;i++)
    {
        scanf("%s",a);
        int x=strlen(a);
        int f,h,out=0;
        for(f=0;f<x;f++)
        {
            if(*(a+f)=='1') h=1;
            if(*(a+f)=='0') h=0;
            if(*(a+f)=='-') h=-1;
            out=out*3+h;
        }
        print("case #%d:\n",i);
        print("%d",out);
    }
    return 0;
}