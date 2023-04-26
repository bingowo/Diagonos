#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Number{
    long long int inner;
    int highest;
};

int cmp(const void *d1, const void *d2){
    struct Number a,b;
    a=*((struct Number*)d1);
    b=*((struct Number*)d2);
    if(a.highest>b.highest) return -1;
    else if(a.highest<b.highest) return 1;
    else {
            if(a.inner<b.inner) return -1;
            else return 1;
    }
}

int the_highest(long long int inner){
    while((inner/10)!=0){
        inner/=10;
    }
    return (int)abs(inner) ;
}

int main(){
    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int n; scanf("%d",&n);
        struct Number number[n];
        for(int i=0;i<n;i++){
            scanf("%lld",&number[i].inner);//long long int µÄÕ¼Î»·ûÊÇ%lld
            number[i].highest=the_highest(number[i].inner);
            //printf("The number is %lld, and its highest is %d\n",number[i].inner,number[i].highest);
        }
        qsort(number,n,sizeof(number[0]),cmp);
        printf("case #%d:\n",cas);
        for(int i=0;i<n;i++){
            printf("%lld ", number[i].inner);
        }
        printf("\n");
    }
    return 0;
}
