
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
long long int rti(char s[])
{
    int a[150];long long int n=1,res=0,form=0,temp=0;
    a['I']=1;
    a['V']=5;
    a['X']=10;
    a['L']=50;
    a['C']=100;
    a['D']=500;
    a['M']=1000;
    while(*s)
    {
        if (*s=='(')
                n=n*1000;
        else if(*s==')')
            n=n/1000;
        else
        {
         temp=a[*s]*n;
         if (temp>form)
         {
             res=res+temp-form-form;
         }
         else
            res=res+temp;
        }
        form=temp;
        *s++;
    }
    return res;
}
int main()
{
    int n;
    char s[50];
    scanf("%s",s);
    printf("%lld",rti(s));
    return 0;
}