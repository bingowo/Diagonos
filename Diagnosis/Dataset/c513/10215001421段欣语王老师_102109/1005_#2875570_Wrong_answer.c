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
        int num=0,len;
        printf("case #%d:\n",i);
        while(scanf("%s",s)!=EOF)
        {
            len=strlen(s)-1;
            for(;len!=1;--len)
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
            a[num]='\0';
            printf("%s\n",a);
        }
    }
    return 0;
}