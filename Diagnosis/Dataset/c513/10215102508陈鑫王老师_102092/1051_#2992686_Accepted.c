#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char bate64[65]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int ans[804]={0};
        char s[101];
        scanf("%s",s);
        int x,len=strlen(s);
        int a=len%3;
        if(a==0) x=0;
        else if(a==1) x=4;
        else x=2;
        int Len=len*8+x;
        for(int j=0,k=7;j<len;j++,k=7+j*8)
        {
            int b=s[j];
            while(b)
            {
               ans[k]=b%2;
               b=b/2;
               k--;
            }
        }
        char ret[1000];
        int index=0;
        for(int j=0;j<Len;j+=6)
        {
            int n=0;
            int k=j,time=1;
            while(time<7)
            {
                n=n*2+ans[k];
                time++;
                k++;
            }
            ret[index++]=bate64[n];

        }
        int l=Len/6;
        if(l%4!=0)
        {
            int v=4-l%4;
            for(int j=0;j<v;j++)
            {
                ret[index++]='=';
            }
        }
        ret[index]='\0';
        printf("case #%d:\n%s\n",i,ret);
    }
    return 0;
}
