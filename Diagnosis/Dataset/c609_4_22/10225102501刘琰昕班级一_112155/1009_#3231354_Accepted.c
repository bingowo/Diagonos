#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//辗转相除法求最大公约数
void change(int a,int b,int *max)
{
    while(b)
    {
        int t=b;
        b=a%b;
        a=t;
    }
    *max=a;
} 

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char s[120]={0};char *p=s;
        getchar();
        scanf("%[^\n]",s);
        int num1=0,num=0,max=0;
        while(*p)
        {
            char c=*p;
            while(c)
            {
                c&=c-1;
                num1++;
            }
            p++;
        }
        num=strlen(s)*8;
        change(num1,num,&max);
        printf("%d/%d\n",num1/max,num/max);
    }
}
