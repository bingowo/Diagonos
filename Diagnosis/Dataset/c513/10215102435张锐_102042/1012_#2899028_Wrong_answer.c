#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s[50];
    scanf("%s",s);
    int len=strlen(s);int i=0;long long int a=0,b=0;int bo=1;
    if(s[len-1]!='i')
    {
        if(s[0]=='-') {bo=-1;i++;}
        for(;isdigit(s[i])&&i<len;i++) {a=a*10+(s[i]-'0');}
        a=a*bo;
    }
    else
    {
        if(s[0]=='-') {bo=-1;i++;}
        for(;isdigit(s[i])&&i<len;i++) {a=a*10+(s[i]-'0');}
        a=a*bo;bo=1;
        if(s[i]=='i') {b=a;a=0;}
        else
        {
            if(s[i]=='-') {bo=-1;}
            i++;
            if(s[i]=='i') b=1;
            for(;isdigit(s[i])&&i<len;i++) {b=b*10+(s[i]-'0');}
            b=b*bo;
        }
    }
    long long int qr=a,qi=b;
    int answer[100]={0};int j=0,r=0;
    for(;qr!=0||qi!=0;j++)
    {
        r=abs((qr+qi)%2);answer[j]=r;
        qr=(b-a+r)/2;qi=(-a-b+r)/2;a=qr;b=qi;
    }
    for(int k=j-1;k>=0;k--)
    {
        printf("%d",answer[k]);
    }
    if(j==0) printf("0");
    return 0;
}
