#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    char octal[55],decimal[155];
    int T,i=0,temp;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%s",&octal);
        int num=0,len=strlen(octal)-1;
        for(;len!=1;--len)
        {
            int digit=octal[len]-'0',j=0;
            do{
                if(j<num) temp=digit*10+decimal[j]-'0';
                else temp=digit*10;
                decimal[j++]=temp/8+'0';
                digit=temp%8;
            }while(digit!=0||j<num);
            num=j;
        }
        decimal[num]='\0';
        printf("case #%d:\n",i);
        printf("%s\n",decimal);
    }
    return 0;
}
