#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct{
     int a;
     int b;
}num;

int cmp(const void*p1,const void*p2){
    int m=(*(num*)p1).b;
    int n=(*(num*)p2).b;
    if(m!=n){
        return n-m;
    }else{
        return (*(num*)p1).a-(*(num*)p2).a;}

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
            scanf("%d",&goal[j].a);
            int c=goal[j].a;
            int x=1,y=0;            /*x表示二进制数后来不断左移，挨个进行位与，存储个数1*/
            for(int k=0;k<64;k++){
                if(c&x){
                    y++;}
               x= x<<1;
            }
            goal[j].b=y;
        }
        qsort(goal,N,sizeof(num),cmp);
        printf("case #%d;\n",i);
        for(int j=0;j<N;j++){
            printf("%d ",goal[j].a);
        }
        printf("\n");
    }
    return 0;
}
