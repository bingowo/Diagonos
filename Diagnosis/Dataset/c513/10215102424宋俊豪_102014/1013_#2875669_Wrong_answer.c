#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int main()
{   int a[100];char s[50];
    a['2']=-1;
    a['0']=0;
    a['1']=1;
    scanf("%s",s);
    long long int num1,num2,num3,i=0;
    num3=1;num1=0;num2=0;
    if (strlen(s)==1)
    {
        printf("%d",a[s[i]]);
    }
    else {
    while(s[i]!='.'&&s[i]!='\0')
    {
        num1=num1*3+a[s[i]];
        i++;
    }
    i++;
    for(i;i<strlen(s);i++)
    {
        num2=num2*3+a[s[i]];
        num3=num3*3;
    }

num1=num1+num2/num3;
num2=num2-num2/num3;
if (num1>0&&num2<0)
{
    num1--;
    num2+=num3;
}
else if (num1<0&&num2>0)
{
    num1++;
    num2=num3-num2;
}
else if (num1<0&&num2<0)
    num2=-num2;
  if (num1!=0)
  printf("%d ",num1);
  if (num2!=0)
    printf("%d ",num2);
    if (num3!=1)
    printf("%d",num3);
    }
    return 0;
}

