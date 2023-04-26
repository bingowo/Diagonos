#include <stdio.h>
#include <stdlib.h>
#include<math.h>
typedef struct
{
    long long k;
}shuzu;
shuzu p[100];
long long jisuan(int n,int m)
{
    int i=0;
    if(n<m){if(p[n].k==0)p[n].k=pow(2,n);}
    else if(n==m){if(p[n].k==0)p[n].k=pow(2,n)-1;}
    else{for(i=1;i<=m;i++){if(p[n-i].k==0)p[n-i].k=jisuan(n-i,m);p[n].k=p[n].k+p[n-i].k;}}
    return p[n].k;


}
int main()
{
    int n=0,m=0;
    while(1)
    {   scanf("%d %d",&n,&m);
        if(n==-1 && m==-1)break;
        int i=0;
        for(i=0;i<100;i++)p[i].k=0;
        long long sum=0;
        sum=pow(2,n)-jisuan(n,m);
        printf("%lld\n",sum);

    }
    return 0;
}
