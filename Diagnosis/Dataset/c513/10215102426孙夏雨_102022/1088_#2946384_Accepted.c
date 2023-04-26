#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int m=0,n=0;
        scanf("%d %d",&m,&n);
        n=(n>(m/2))? m-n:n;
        printf("case #%d:\n",t);
        if(n==0) printf("1\n");
        else{
            long long int fenzi=1,fenmu=1,ans=0;
            for(int i=n,j=m;i>0;i--,j--) {
                fenmu*=i;
                fenzi*=j;
                if(fenzi%fenmu==0) {
                    fenzi/=fenmu;
                    fenmu=1;
                }
            }
            ans=fenzi/fenmu;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
