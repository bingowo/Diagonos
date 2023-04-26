#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void solve(char*p,int len)
{
    int i,d=0;char arr[100];double f=0,temp;
    for(;len!=1;len--)
    {
        i=0;
        f=p[len-1]-'0';
        do
        {
            if(i<d){temp=f*10+arr[i]-'0';}
            else {temp=f*10;}
            arr[i]=temp/8+'0';
            f=temp%8;
            i++;
        }while(f!=0||i<d);
        d=i;
    }
    arr[d]='\0';
    printf("%s",arr);
}

int main()
{
    int T,i,j=0,len;char s[52];
    scanf("%d",&T);
    while(scanf("%s",s)!=EOF)
    {
        printf("case #%d:\n0.",j++);
        len=strlen(s);
        solve(s,len);
    }
}