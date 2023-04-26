#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
const  char t[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};
char s[101];
void read(char s[],int a[])
{   int i=0;
    char c;
    while(s[i])
    {
        c=s[i];
        for(int j=i*8+7;j>=i*8;j--)
             {
                 a[j]=c%2;
                 c=c/2;
             }
        i++;
    }
}

int main()
{
    int n,l,cnt,cnt1;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {   int a[810]={0},b[150]={0};
        gets(s);
        read(s,a);
        l=strlen(s);
        cnt=l*8;
        while(cnt%6!=0)
            cnt++;
        cnt1=cnt/6;
        for(int j=0;j<cnt1;j++)
        {
            for(int q=j*6;q<j*6+6;q++)
                b[j]=b[j]*2+a[q];
        }
        printf("case #%d:\n",i);
        if(cnt1<4)
        {
            for(int j=0;j<cnt1;j++)
                printf("%c",t[b[j]]);
            while(cnt1<4)
            {
                printf("=");
                cnt1++;
            }
            printf("\n");
        }
        else
        {
            for(int j=0;j<cnt1;j++)
                printf("%c",t[b[j]]);
            while(cnt1%4!=0)
            {
                printf("=");
                cnt1++;
            }
            printf("\n");
        }

    }
    return 0;
}
