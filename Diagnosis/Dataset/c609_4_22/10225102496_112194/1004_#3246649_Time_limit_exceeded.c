#include<stdlib.h>
#include<stdio.h>

int main()
{
    int A,B,i,j;
    int temp=0;
    int num;
    char s[32];char t[100];
    scanf("%d%s%d",&A,s,&B);
    for(i=0;s[i];i++)
    {
        temp=temp*A;
        if(s[i]>='0'&&s[i]<='9') temp=temp+s[i];
        if(s[i]>='a'&&s[1]<='z') temp=temp+s[i]-'a'+10;
        if(s[i]>='A'&&s[1]<='Z') temp+temp+s[i]-'A'+10;
    }
    for(j=0;temp>0;j++)
    {
       num=temp%B;
       if(num>=0&&num<=9) t[j]=num+'0';
       else t[j]=num-10+'A';
       num=num/10;
    }
    for(j--;j>=0;j--)
    {
        printf("%c",t[j]);
    }
    return 0;
}
