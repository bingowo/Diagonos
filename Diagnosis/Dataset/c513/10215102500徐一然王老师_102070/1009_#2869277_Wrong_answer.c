#include<stdio.h>

int main()
{
    int count,num=0,num1=0;
    scanf("%d",&count);
    getchar();
    char s[100];
    char copy;
    char *p=s;
    while(count--)
    {
        gets(s);
        while(*p)
        {
            copy=*p;
            while(copy)
            {
             if(copy%2==1)
             {
                 num1=num1+1;
             }
             copy=copy/2;
            }
            num=num+8;
            p++;
        }
        p=s;
        while(num1%2==0&&num%2==0)
        {
            num1=num1/2;
            num=num/2;
        }
        while(num%num1==0&&num1!=1)
        {
            num1=1;
            num=num/num1;
        }
        printf("%d/%d\n",num1,num);
        num1=0;
        num=0;
    }
}
