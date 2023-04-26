#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GCD(int m,int n)
/* 找最大公约数m<n*/
{
    for(int i=0;i<m;i++)
    {
        int x=m-i;
        if((m%x==0)&&(n%x==0)) return x;
    }
}
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        char s[200];
        gets(s);
        int len=strlen(s);
        int num=0,size=len*8;
        for(int j=0;j<len;j++)
        {
            int k=0;
            while(k<8)
            {
                if((s[j]>>k)&1==1) num++;
                k++;
            }
        }
        int x=GCD(num,size);
        printf("%d/%d\n",num/x,size/x);
    }
    return 0;
}
