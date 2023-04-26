#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int s[510];int n[2000];int d[4]={0,0,0,1};int len;
    scanf("%s",s);
    len=strlen(s);
    strcat(n,d);
    int B[10]={};int M=9;
    while(len)
    {
        B[M]=len%2;
        len=len/2;
        M-=1;
    }
    strcat(n,B);
    if(len%3==0)
    {
        for(int i=0;i<len;i+=3)
        {
            int a=s[i]*100+s[i+1]*10+s[i+2];
            int A[10]={};int m=9;
            while(a)
            {
                A[m]=a%2;
                a=a/2;
                m-=1;
            }
            strcat(n,A);
        }
    }
    else if(len%3==1)
    {
        for(int i=0;i<len-1;i+=3)
        {
            int a=s[i]*100+s[i+1]*10+s[i+2];
            int A[10]={};int m=9;
            while(a)
            {
                A[m]=a%2;
                a=a/2;
                m-=1;
            }
            strcat(n,A);
        }
        int b=s[len-1];
        int A[4]={};int m=3;
            while(b)
            {
                A[m]=b%2;
                b=b/2;
                m-=1;
            }
            strcat(n,A);
    }
    else if(len%3==2)
    {
        for(int i=0;i<len-2;i+=3)
        {
            int a=s[i]*100+s[i+1]*10+s[i+2];
            int A[10]={};int m=9;
            while(a)
            {
                A[m]=a%2;
                a=a/2;
                m-=1;
            }
            strcat(n,A);
        }
        int b=s[len-2]*10+s[len-1];
        int A[7]={};int m=6;
            while(b)
            {
                A[m]=b%2;
                b=b/2;
                m-=1;
            }
            strcat(n,A);
    }
    for(int i=0;i<strlen(n);i++) printf("%d",n[i]);
    return 0;
}
