#include <stdio.h>
int main()
{
    int A,B;//A进制到B进制
    char n[32];
    scanf("%d %s %d",&A,n,&B);
    //char table[]="0123456789abcdef";
    int M=0;int q=0;int temp=0;int cout=0;int f=0;
    for(int i=strlen(a)-1;i>=0;i--)
    {
        if(a[i]>='0' &&a[i]<='9')
            temp=a[i]-'0';
        else if(a[i]>='A' &&a[i]<='Z')
            temp =a[i]-'A'+10;
        else if(a[i]>='a' &&a[i]<='z')
            temp =a[i]-'a'+10;
        else break;
        M+=temp*q;//计算对应十进制数
        q*=A;//A的k次方
    }

    while(M)
    {
        temp=M%B;
        M/=B;
        if(temp>=10)
            a[cout]=temp-10+'A';
        else
            a[cout]=temp+'0';
        cout++;
    }
    for(int i=cout-1;i>=0;i--)
         printf("%c",a[i]);
    return 0;
}
