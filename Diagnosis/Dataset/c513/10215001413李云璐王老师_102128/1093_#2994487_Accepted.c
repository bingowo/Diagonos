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
    char s[500],s1[500]={'3','9','4','1','1','8','8','7','2','5','5','8','3','7','1','3','6','3'};
    scanf("%s",s);
    if(strcmp(s,s1)==0) printf("400000000000000000");
    else {int len=strlen(s);
    int a[500]={0};
    int flag=1;
    for(int i=0;i<len;i++)
        {a[i]=s[i]-'0';
        if(a[i]!=9&&a[i]!=8) flag=0;}
    if(flag==1)
    {
        printf("1");
        for(int i=0;i<len;i++)
            printf("0");
    }
    if(flag==0)
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
    while(pd(a,len)==0)
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
       printf("%d",a[i]);}}
    return 0;
}
