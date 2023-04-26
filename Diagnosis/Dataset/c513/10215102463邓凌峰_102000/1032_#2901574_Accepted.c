#include <stdio.h>
#include <stdlib.h>

typedef long long int lli;

typedef struct
{
    lli nums[50];
}Num;

int cmp(const void *a,const void *b)
{
    Num pa=*(Num*)a,pb=*(Num*)b;
    int order=0;
    while(1){
        if(pa.nums[order]==-1 && pb.nums[order]==-1) break;
        if(pa.nums[order]!=pb.nums[order]){
            return pa.nums[order]>pb.nums[order]?-1:1;
        }
        else order++;
    }
}


int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N;scanf("%d",&N);
        Num lines[N];
        //初始化数组里面的数值为-1
        for(int j=0;j<N;j++){
            for(int k=0;k<50;k++){
                lines[j].nums[k]=-1;
            }
        }

        for(int j=0;j<N;j++){
            lli mid;scanf("%lld",&mid);
            for(int k=0;mid!=-1;k++){
                lines[j].nums[k]=mid;
                scanf("%lld",&mid);
            }
        }
        qsort(lines,N,sizeof(Num),cmp);
        for(int j=0;j<N;j++){
            for(int k=0;k<50;k++){
                if(lines[j].nums[k]!=-1) printf("%lld ",lines[j].nums[k]);
            }
            printf("\n");
        }


    }

	return 0;
}
