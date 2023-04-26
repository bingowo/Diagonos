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
    unsigned T,num;
    scanf("%u",&T);
    for(int iT=0;iT<T;++iT){
        printf("case #%d:\n",iT);
        scanf("%u",&num);
        if(num==0){printf("0\n");break;}//remove the sit of zero
        int pos=8*sizeof(int)-1;
        while((num>>pos)==0)--pos;//find the first 1
        int before=1,biggest=1,temlen=1;
        --pos;
        while(pos>=0){
            if(before^((num>>pos)&1)){
                ++temlen;
            }else{//calc and update
                if(temlen>biggest)biggest=temlen;
                temlen=1;
            }
            before=(num>>pos)&1;
            --pos;
        }
        if(temlen>biggest)biggest=temlen;

        printf("%d\n",biggest);

    }
    return 0;
}
