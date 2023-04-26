#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 150

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[N],a[N];
        int num=0,len;
        while(scanf("%s",s))
        {
            len=strlen(s[N])-1;
            for(:len!=1;--len)
            {
                int digit=s[len]-'0',j=0,temp;
                do{
                    if(j<num)
                    temp=digit*10+a[j]-'0';
                    else
                    temp=digit*10;
                    a[j++]=temp/8+'0';
                    digit=temp%8;
                }while(digit!=0||j<num);
                num=j;
            }
            a[num]='\0'
        }
    }
    return 0;
}