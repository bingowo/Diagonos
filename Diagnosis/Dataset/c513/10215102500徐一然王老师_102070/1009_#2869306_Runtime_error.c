#include<stdio.h>


int GCD(int a,int b)
{
    int temp;
    if(a<b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    while(b!=0)
    {
        temp=a%b;
        a=b;b=temp;
    }
    return a;
}

int main()
{
    int count,A,num=0,num1=0;
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
        A=GCD(num,num1);
        printf("%d/%d\n",num1/A,num/A);
        num1=0;
        num=0;
    }
}
