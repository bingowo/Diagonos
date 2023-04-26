#include<stdio.h>
int main()
{
    char s[]="0123456789ABCDEFGHIJKLMN";
    int a,d;
    scanf("%d %d",&a,&d);
        while(a!=0)
        {
            if(a%d<0)
            {printf("%c\n",s[-d+a%d]);
            a=a/d+1;}
            else printf("%c\n",s[a%d]);
            a=a/d;
        }
    return 0;
}