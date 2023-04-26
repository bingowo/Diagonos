#include<stdio.h>
int main()
{
    char s[]="0123456789ABCDEFGHIJ";
    char f[34];
    int a,d,i=0;
    scanf("%d %d",&a,&d);
        while(a!=0)
        {
            if(a%d<0)
            {f[i]=s[-d+a%d];
            a=a/d+1;}
            else {f[i]=s[a%d];
            a=a/d;}
            i++;
        }
        i--;
        for(;i>-1;i--) printf("%c",f[i]);
    return 0;
}