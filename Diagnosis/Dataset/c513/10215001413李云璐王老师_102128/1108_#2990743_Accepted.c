#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

void solve(int n,int m)
{
    int yu[10000]={0};
    int t;
    t=n/m;
    int j=1;
    yu[n%m]=j++;
    n=n%m;
    printf("%d.",t);
    while(n%m!=0)
    {
       n*=10;
       printf("%d",n/m);
       n%=m;
       if(yu[n]!=0) {printf("\n");printf("%d-%d",yu[n],j-1);return;}
       else yu[n]=j++;
     }

}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        printf("case #%d:\n",i);
        solve(n,m);printf("\n");
    }
    return 0;
}
