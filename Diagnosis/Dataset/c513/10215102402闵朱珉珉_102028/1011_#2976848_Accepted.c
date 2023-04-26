#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char s[100000],t[100000];
    scanf("%s",s);
    int len=strlen(s);
    int q=0,k=0;
    for(int i=2;i<len;i++)
    {
        int temp,p=1;
        if(s[i]>='A')temp=s[i]-'A'+10;
        else temp=s[i]-'0';
        for (int j=3;j>=0;j--)
        {
            if (temp & (p<<j)) t[k++]='1';
            else t[k++]='0';
        }
    }
    long long q_r=0,q_i=0,a,b;
    for(int i=0;i<k;i++)
    {
        int r=t[i]-'0';
        a=-(q_r+q_i)+r;
        b=q_r-q_i;
        q_r=a;
        q_i=b;
    }
    if(q_i==0)
        printf("%lld",a);
    else
    {
        if(q_r!=0)
        {
            printf("%lld",q_r);
            if(q_i>0)printf("+");
        }
        if (q_i==1) printf("i");
        else if (q_i==-1) printf("-i");
        else printf("%lldi\n",q_i);

    }

}
