#include<stdio.h>
#include<string.h>
int main()
{
    int a;
    scanf("%d",&a);
    int i;
    char* a;
    for(i=0;i<a;i++)
    {
        scanf("%s",a);
        int x=strlen(a);
        int f,h,out=0;
        for(f=0;f<x;f++)
        {
            if(char*(a+f)=='1') h=1;
            if(char*(a+f)=='0') h=0;
            if(char*(a+f)=='-') h=-1;
            out=out*3+h;
        }
        print("case #%d:\n",i);
        print("%d",out)
    }
    return 0;
}