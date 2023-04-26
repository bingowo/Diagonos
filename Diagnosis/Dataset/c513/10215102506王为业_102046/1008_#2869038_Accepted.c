#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//#define LOCAL

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    unsigned T,x,y;
    scanf("%u",&T);
    for(int iT=0;iT<T;++iT){
        scanf("%u %u",&x,&y);
        int diff=0;
        for(int i=0;i<8*sizeof(unsigned);++i){
            if((x&1)^(y&1))++diff;
            x>>=1;y>>=1;
        }
        printf("%d\n",diff);
    }
    return 0;
}
