#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[55],a[155];
        printf("case #%d:\n",i);
        scanf("%s",s);
            int num=0,len;
            len=strlen(s)-1;
            for(;len!=1;--len)
            {
                int digit=s[len]-'0',j=0,temp;
                do{
                    temp=digit*10;
                    a[j++]=temp/8+'0';
                    digit=temp%8;
                }while(digit!=0);
                num=j;
            }
            a[num]='\0';
            printf("0.%s\n",a);
    }
    return 0;
}