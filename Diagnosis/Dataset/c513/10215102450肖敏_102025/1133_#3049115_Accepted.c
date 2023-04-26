#include <stdio.h>
#include <string.h>
int intpow(int a)
{
    int sum=1;
    for(int i=0;i<a;i++)
    {
       sum*=2;
    }
    return sum;
}
int s[32768];
int main() {
    int i;
    scanf("%d",&i);

    memset(s,0,32768);
    s[0]=0;
    s[1]=0;
    s[2]=1;
    int t[16];
    for(int y=0;y<=15;y++)
    {
        t[y]= intpow(y);
    }
    int num=t[i];
    for(int k=2;k<=i;k++)
    {
        for(int l1=t[k-1]+1,l2=1;l1<=t[k];l1++,l2++)
        {
            s[l1]=(s[l2]==0?1:0);
        }
    }
    for(int j=1;j<=num;j++)
    {
        printf("%d",s[j]);
    }
    return 0;
}