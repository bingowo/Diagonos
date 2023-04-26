#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=1,m=1;
    while(n!)
    scanf("%d%d",&n,&m);
    int a[11]={0};
    int gn1 = 0;
    int gn2 = 0;
    int c = 0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&gn1,&gn2,&c);
        if(c==1){
            a[gn1]+=3;
            a[gn2]-=1;
        }
        if(c==-1){
            a[gn2]+=3;
            a[gn1]-=1;
        }
        if(c==0){
            a[gn2]+=1;
            a[gn1]+=1;
        }
    }
    return 0;
}
