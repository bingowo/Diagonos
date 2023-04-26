#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 1000
#define BigNUm 10007

int main()
{

    int T;scanf("%d",&T);
    for(int I=0;I<T;I++){
        int a,b,k,n,m;
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        
        int ans=1;
        for(int i=0;i<n;i++){
            ans=(ans*(k-i)/(i+1))%BigNUm;
        }
        for(int i=1;i<=n;i++){
            ans=(ans*a)%BigNUm;
        }
        for(int i=1;i<=m;i++){
            ans=(ans*b)%BigNUm;
        }
        
        
        printf("case #%d:\n",I);
        printf("%d\n",ans);
    }

    return 0;
}





