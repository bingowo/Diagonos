#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    char d[51],dten[154];
    int T;
    scanf("%d",&T);
    int temp;
    for(int i=0;i<T;++i)
    {
        scanf("%s",d);
        int num=0;
        int len=strlen(d)-1;
        for(;len!=1;--len)
        {
            int j=0;
            int digit=d[len]-'0';
            do{
                if(j<num) temp=digit*10+dten[j]-'0';
                else temp=digit*10;
                dten[j++]=(temp/8)+'0';
                digit=temp%8;
            }while(digit!=0||j<num);
            num=j;
        }
        printf("case #%d:\n",i);
        printf("0.%s\n",dten);
    }
    return 0;
}
