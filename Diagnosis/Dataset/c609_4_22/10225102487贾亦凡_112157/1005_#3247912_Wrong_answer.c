#include<stdio.h>
#include<string.h>
#include<math.h>

void f(int len,char a[],int b[])//len将是字符串长度//函数把字符串转为数字
{
    int k=0,n;
    for(int j=len-1;j>=0;j--)
    {
        if (a[j]=='-')
        n=-1;
        else if(a[j]=='0')
        n=0;
        else
        n=1;
        b[k]=n;
        k++;
    }
}
int main()
{
    int t;
    char s[50];
    int len;
    int x[100];
    scanf("%d",&t);
    int sum;
    for(int i=0;i<t;i++)
    {
        scanf("%s",s);
        len=strlen(s);
        f(len,s,x);
        sum=0;
        for(int l=0;l<len;l++)
        sum+=x[l]*(int)pow(3,l);
        
        printf("case #%d:\n",i);
        printf("%d",sum);
    }
    return 0;
}
