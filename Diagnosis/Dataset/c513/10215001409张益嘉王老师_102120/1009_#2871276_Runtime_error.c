#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int n[20],i,N;
    gets(n);
    N=atoi(n);
    for(i=0;i<n;i++)
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
