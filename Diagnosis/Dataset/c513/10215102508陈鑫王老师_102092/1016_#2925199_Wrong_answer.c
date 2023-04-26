#include<stdio.h>
#include<stdlib.h>
int mod(int n,int k)
{
    if(n%k<0)
    return n-(n/k+1)*k;
    else return n%k;
}
int main()
{
    int n,r;
    scanf("%d%d",&n,&r);
    char a[21]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'},ret[10000];
    int i=0;
    while(n)
    {
        int c=mod(n,r);
        ret[i++]=a[c];
        if(n%r<0)n=n/r+1;
        else n=n/r;
    }
    for(int j=i-1;j>=0;j--)
    {
        printf("%c",ret[j]);
    }
    return 0;
}
