#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a2i(char x[])
{
    int l=strlen(x),r=0,i;
    for(i=l-1;i>=0;i--)
    {
        r+=(x[i]-'0')*pow(10,l-i-1);
    }
    return r;
}

int yueshu(int a,int b)
{
    if(a==b) return a;
    else if(a>b) return yueshu(b,a);
    else
    {
        if((b%a)==0) return a;
        else return yueshu(b%a,a);
    }
}

int main()
{
    char n[20];
    int i,N;
    gets(n);
    N=a2i(n);
    for(i=0;i<N;i++)
    {
        char ch[125];
        gets(ch);

        int len=strlen(ch),j,k,co=0,mu,yue;
        for(j=0;j<len;j++)
        {
            for(k=0;k<8;k++)
            {
                if((ch[j]&1)==1) co++;
                ch[j]=ch[j]>>1;

            }
        }
        mu=8*len;
        //printf("len=%d\n",len);
        //printf("mu=%d\n",mu);
        //printf("co=%d\n",co);
        yue=yueshu(co,mu);
        if(yue!=1)
        {
            mu=mu/yue;
            co=co/yue;
        }
        printf("%d/%d\n",co,mu);

    }
    return 0;
}
