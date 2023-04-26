#include<string.h>
#include<stdio.h>

int main()
{
    int A,B,i,j;
    int temp=0;
    int num;
    char s[100];char t[100];
    scanf("%d%s%d",&A,s,&B);
    int len=strlen(s);
    for(i=0;i<len;i++)
    {
        temp=temp*A;
        if(s[i]>='0'&&s[i]<='9') temp=temp+s[i];
        if(s[i]>='a'&&s[i]<='z') temp=temp+s[i]-'a'+10;
        if(s[i]>='A'&&s[i]<='Z') temp+temp+s[i]-'A'+10;
    }
    for(j=0;temp>0;j++)
    {
       num=temp%B;
       if(num>=0&&num<=9) t[j]=num;
       else t[j]=num-10+'A';
       temp=temp/B;
    }
    for(j--;j>=0;j--)
    {
        printf("%c",t[j]);
    }
    return 0;
}
