#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
char s[1005];
char a[2005];
int main()
{
    scanf("%s",s);
    int i=0,b1=1002,b2=1002;
    while(s[i])
    {
        if (s[i]>='a'&&s[i]<='z')
            s[i]=s[i]-32;
        if(i==0)
        {
            a[1002]=s[i];
        }
        else
        {
            if(s[i]>=a[b1])
                a[--b1]=s[i];
            else
                a[++b2]=s[i];
        }
        i++;

    }
    printf("%s",a+b1);
    return 0;
}
