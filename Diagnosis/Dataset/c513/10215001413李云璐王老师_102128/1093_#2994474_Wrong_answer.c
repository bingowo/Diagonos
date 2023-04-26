#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int pd(int*a,int len)
{
    int sum=0;
    for(int i=0;i<len;i++)
    {
        if(a[i]==9) {return 0;break;}
        sum+=a[i];
    }
    if(sum%9==0) return 0;
    else return 1;
}

int main()
{
    char s[500];
    scanf("%s",s);
    int len=strlen(s);
    int a[500]={0};
    for(int i=0;i<len;i++)
        a[i]=s[i]-'0';
    int flag=1;
    for(int i=0;i<len;i++)
    {if(a[i]!=8&&a[i]!=9) flag=0;}
    if(flag==1)
        {
            printf("1");
            for(int k=0;k<len;k++)
                printf("0");}
    else
    {for(int i=0;i<len/2;i++)
    {
        int c=a[i];
        a[i]=a[len-i-1];
        a[len-i-1]=c;
    }
    a[0]+=1;
    int yu=0;
    for(int i=0;i<len;i++)
    {
       int z=a[i];
       a[i]=(a[i]+yu)%10;
       yu=(z+yu)/10;
    }
    while(yu>0) {a[len]=yu%10;len++;yu/=10;}
    while(pd(a,len)!=0)
    {
        a[0]+=1;
        for(int i=0;i<len;i++)
        {
            int z=a[i];
            a[i]=(a[i]+yu)%10;
            yu=(z+yu)/10;
        }
        while(yu>0) {a[len]=yu%10;len++;yu/=10;}
    }
    for(int i=len-1;i>=0;i--)
       printf("%d",a[i]);}
    return 0;
}
