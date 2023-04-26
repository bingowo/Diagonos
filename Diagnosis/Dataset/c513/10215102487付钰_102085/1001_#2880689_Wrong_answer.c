#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
void conversion(int d,int k)//10-k
{
    int n=abs(d);
    if(n!=d) printf("-");
    char out[1000];
    int i=0;
    while(n>0)
    {
        out[i++]=n%k;
        n=n/k;
    }
    for(int j=i-1;j>=0;j--)
    {
        if(out[j]>=10) printf("%c",(char)(out[j]+'A'-10));
        else printf("%d",(char)(out[j]+'0'));
    }
}

int main()
{
    int t,i,n,r,x;
    scanf("%d",&t);
    for(i=0;i<t-1;i++)
    {
        scanf("%d %d",&n,&r);
        conversion(n,r);
        printf("\n");
    }
    if(i==t-1)
    {
        scanf("%d %d",&n,&r);
        conversion(n,r);
    }
}
