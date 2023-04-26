#include <stdio.h>
#include <stdlib.h>
void conversion(int x,int k)
{
    int n=abs(x);
    char out[1000];
    int i=0;
    while(n>0)
    {
        out[i++]=n%k;
        n/=k;
    }
    for(int j=i-1;j>=0;j--)
    {
        if(out[j]<10)
        {
            printf("%c",(char)('0'+out[j]));
        }
        else{
            printf("%c",(char)('A'+out[j]-10));
        }
    }
}
int main()
{
    int t,i,n,r,x;
    scanf("%d",&t);
    for(i=0;i<=t;i++)
    {
        scanf("%d %d",&n,&r);
        conversion(n,r);
        printf("\n");
    }
}
