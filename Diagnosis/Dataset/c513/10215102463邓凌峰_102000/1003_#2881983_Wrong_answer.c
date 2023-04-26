#include <stdio.h>
#include <stdlib.h>


int cmp(const void *a,const void *b)
{
    long long aa=*(long long *)a,bb=*(long long *)b;
    int aaa=0,bbb=0;
    for(int i=0;i<64;i++){
        if((aa&1)==1)aaa++;
        aa=aa>>1;
    }
    for(int i=0;i<64;i++){
        if((bb&1)==1)bbb++;
        bb=bb>>1;
    }
    aa=*(long long *)a,bb=*(long long *)b;
    if(aaa!=bbb){
            return (aaa>bbb)?-1:1;
    }
    else{
        return (aa>bb)?1:-1;
    }

}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int t;
        scanf("%d",&t);
        long long mid[t];
        for(int j=0;j<t;j++){scanf("%lld",&mid[j]);}
        qsort(mid,t,sizeof(long long),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<t;k++){printf("%d ",mid[k]);}
        printf("\n");
    }


    return 0;
}
