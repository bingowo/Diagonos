#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    char number[12];
    int n;
};

int cmp(const void *a,const void *b)
{
    struct student x,y;
    x = *((struct student *)a);
    y = *((struct student *)b);
    if(x.n != y.n){
        return y.n - x.n;
    }
    else return strcmp(x.number,y.number);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        int N,M,G;
        scanf("%d%d%d",&N,&M,&G);
        int table[10];
        for(int i=0;i<M;i++){
            scanf("%d",&table[i]);
        }
        struct student stu[500];
        for(int i=0;i<N;i++){
            stu[i].n=0;
            scanf("%s",stu[i].number);
            int num=0;
            scanf("%d",&num);
            for(int j=0;j<num;j++){
                int x;
                scanf("%d",&x);
                stu[i].n += table[x-1];
            }
        }
        int count=0;
        for(int i=0;i<N;i++){
            if(stu[i].n>=G)count++;
        }
        qsort(stu,N,sizeof(stu[0]),cmp);
        printf("%d\n",count);
        for(int i=0;i<count;i++){
            printf("%s %d\n",stu[i].number,stu[i].n);
        }
    }
    return 0;
}
