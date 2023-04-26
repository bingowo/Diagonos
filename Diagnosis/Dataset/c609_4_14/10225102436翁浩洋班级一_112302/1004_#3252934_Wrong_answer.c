#include <stdio.h>
#include <string.h>
int main()
{
    int A,B;//A进制到B进制
    char n[32];
    scanf("%d %s %d",&A,n,&B);
    //char table[]="0123456789abcdef";
    int M=0;int q=1;int temp=0;int cout=0;
    for(int i=strlen(n)-1;i>=0;i--)
    {
        if(n[i]>='0' &&n[i]<='9')
            temp=n[i]-'0';
        else if(n[i]>='A' &&n[i]<='Z')
            temp =n[i]-'A'+10;
        else if(n[i]>='a' &&n[i]<='z')
            temp =n[i]-'a'+10;
        else break;
        M+=temp*q;//计算对应十进制数
        q*=A;//A的k次方
    }

    while(M)
    {
        temp=M%B;
        M/=B;
        if(temp>=10)
            n[cout]=temp-10+'A';
        else
            n[cout]=temp+'0';
        cout++;
    }
    for(int i=cout-1;i>=0;i--)
         printf("%c",n[i]);
    return 0;
}
