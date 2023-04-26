#include<stdio.h>
#include<string.h>
int main()
{
    int T,cnt=0;
    scanf("%d",&T);
    while(T--){
        printf("case #%d:\n",cnt++);
        char octal[52],decimal[156];
        scanf("%s\n",octal);
        int len=strlen(octal),j=0;
        for(int i=2;i<len;i--){
            int num=octal[i]-'0',r=0;//s2i，定义商、余数
            decimal[j++]=(num+r)/8+'0';//十进制小数位
            r=num%8*10;
        }
        decimal[j]='\0';
        printf("%s",decimal);
    }
    return 0;
}
