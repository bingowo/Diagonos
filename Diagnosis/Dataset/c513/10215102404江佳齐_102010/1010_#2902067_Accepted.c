#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse(char s[])
{
    int temp,i,j;
    for(i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        temp=s[i];s[i]=s[j];s[j]=temp;
    }
}

int main()
{
    char s[510];char n[2000]="0001";int len;
    scanf("%s",s);
    len=strlen(s);
    char B[11];int M=0;
    while(len)
    {
        B[M]=(len%2)+'0';
        len=len/2;
        M+=1;
    }
    while(M<10)
    {
        B[M]='0';
        M++;
    }
    B[10]='\0';
    reverse(B);
    strcat(n,B);
    len=strlen(s);
    if(len%3==0)
    {
        for(int i=0;i<len;i+=3)
        {
            int a=(s[i]-'0')*100+(s[i+1]-'0')*10+(s[i+2]-'0');
            char A[11];int m=0;
            while(a)
            {
                A[m]=(a%2)+'0';
                a=a/2;
                m+=1;
            }
            while(m<10)
            {
                A[m]='0';
                m++;
            }
            A[10]='\0';
            reverse(A);
            strcat(n,A);
        }
    }
    else if(len%3==1)
    {
        for(int i=0;i<len-1;i+=3)
        {
            int a=(s[i]-'0')*100+(s[i+1]-'0')*10+(s[i+2]-'0');
            char A[11];int m=0;
            while(a)
            {
                A[m]=(a%2)+'0';
                a=a/2;
                m+=1;
            }
            while(m<10)
            {
                A[m]='0';
                m++;
            }
            A[10]='\0';
            reverse(A);
            strcat(n,A);
        }
        int b=s[len-1]-'0';
        char A[5];int m=0;
        while(b)
        {
            A[m]=b%2+'0';
            b=b/2;
            m+=1;
        }
        while(m<4)
        {
            A[m]='0';
            m++;
        }
        A[4]='\0';
        reverse(A);
        strcat(n,A);
    }
    else if(len%3==2)
    {
        for(int i=0;i<len-2;i+=3)
        {
            int a=(s[i]-'0')*100+(s[i+1]-'0')*10+(s[i+2]-'0');

            char A[11];int m=0;
            while(a)
            {
                A[m]=a%2+'0';
                a=a/2;
                m+=1;
            }
            while(m<10)
            {
                A[m]='0';
                m++;
            }
            A[10]='\0';
            reverse(A);
            strcat(n,A);
        }
        int b=(s[len-2]-'0')*10+(s[len-1]-'0');
        char A[7];int m=0;
        while(b)
        {
            A[m]=b%2+'0';
            b=b/2;
            m+=1;
        }
        while(m<7)
        {
            A[m]='0';
            m++;
        }
        A[7]='\0';
        reverse(A);
        strcat(n,A);
    }
    n[strlen(n)]='\0';
    printf("%s",n);
    return 0;
}
