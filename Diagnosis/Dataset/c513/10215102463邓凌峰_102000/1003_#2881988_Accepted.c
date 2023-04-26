#include <stdio.h>
#include <stdlib.h>

int ones(long long x)
{
    int count=0;
    long long mid=1;
    for(int i=0;i<64;i++){
        if((x&mid)==1){count++;}
        x=x>>1;
    }
    return count;
}

int cmp(const void *a,const void *b)
{
    long long aa=*(long long *)a,bb=*(long long *)b;
    int aaa=ones(aa),bbb=ones(bb);
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
        for(int k=0;k<t;k++){printf("%lld ",mid[k]);}
        printf("\n");
    }


    return 0;
}