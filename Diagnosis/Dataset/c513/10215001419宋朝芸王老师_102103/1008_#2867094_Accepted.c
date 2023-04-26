#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    for(scanf("%d",&T);T>0;T--){

        int a,b,same,temp,res;
        scanf("%d %d",&a,&b);
        same=a^b;
        temp=1;
        res=0;

        for(int i=0;i<32;i++){
            if((same&temp)!=0) res++;
            temp=temp<<1;
        }
        printf("%d\n",res);
    }
    return 0;
}
