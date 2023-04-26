#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct{
     long long int a;
     int b;
}num;

int cmp(const void*p1,const void*p2){
    int m=(*(num*)p1).b;
    int n=(*(num*)p2).b;
    if(m!=n){
        return n-m;
    }else{
        if((*(num*)p1).a>(*(num*)p2).a)
            return 1;
        else
            return -1;
        }

}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N;
        scanf("%d",&N);
        num* goal=(num*)malloc(sizeof(num*)*N);
        for(int j=0;j<N;j++){
            scanf("%lld",&goal[j].a);
            long long int c=goal[j].a;
            int y=0;                                   /*x表示二进制数后来不断左移，挨个进行位与，存储个数1*/
            while(c){
                c = c>>1;
                y++;
            }
            goal[j].b=y;
        }
        qsort(goal,N,sizeof(num),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++){
            printf("%lld ",goal[j].a);
        }
        printf("\n");
        free(goal);
    }
    return 0;
}
