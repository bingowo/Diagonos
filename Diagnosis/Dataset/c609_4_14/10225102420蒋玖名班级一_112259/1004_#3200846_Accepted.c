#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
int f(int a,char n[])
{
    int len=strlen(n);
    int sum=0;
    for(int i=0;i<len;i++)
    {
        if(isdigit(n[i]))
            sum=sum*a+n[i]-'0';
        else{
            if(n[i]>='a')
                sum=sum*a+n[i]-'a'+10;
            else
                sum=sum*a+n[i]-'A'+10;
        }
    }
    return sum;
}
void change(int a,char n[],int b)
{
    int lenn=strlen(n);
    if(n[0]=='0'&&lenn==1)
    {
        printf("0\n");
        return;
    }
    int tn;
    tn=f(a,n);
    if(b!=10)
    {
        char str[100];
        int len=0;
        while(tn)
        {
            if(tn%b<10)
                str[len++]=tn%b+'0';
            else{
                str[len++]=tn%b+'A'-10;
            }
            tn/=b;
        }
        for(int i=len-1;i>=0;i--)
            printf("%c",str[i]);
        printf("\n");
        return ;
    }
    else{
        printf("%d\n",tn);
        return;
    }
}
int main()
{
    int A,B;
    char str[100];
    scanf("%d %s %d",&A,str,&B);
    if(A!=B)
        change(A,str,B);
    else{
        for(int i=0;i<strlen(str);i++)
            printf("%c",str[i]);
    printf("\n");
    }
    return 0;
}
