#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a,b;
    char n[100];
    scanf("%d %s %d",&a,n,&b);
    //先将a进制的非负整数n转换为十进制
    int m=0,r=1;
    for(int i=strlen(n)-1;i>=0;i--)
    {
        if(n[i]>='A' && n[i]<='F') m+=(n[i]-'A'+10)*r;
        else if(n[i]>='a' && n[i]<='f') m+=(n[i]-'a'+10)*r;
        else m+=(n[i]-'0')*r;
        r*=a;
    }
    //将十进制数转换为b进制
    if(m==0) printf("0\n");
    int s[100];
    int cnt=0;
    while(m!=0)
    {
        s[cnt]=m%b;
        m/=b;
        cnt++;
    }
    for(int i=cnt-1;i>=0;i--)
    {
        if(s[i]>=10)
        {
            int j=s[i];
            printf("%c",j-10+'A');
        }
        else printf("%d",s[i]);
    }
    printf("\n");
    return 0;
}
