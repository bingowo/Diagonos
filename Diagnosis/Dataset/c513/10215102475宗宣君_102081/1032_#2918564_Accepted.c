#include <stdio.h>
#include <stdlib.h>
typedef struct{
int A[50];
int B;
}RES;
int cmp(const void*a,const void*b)
{
    RES *C,*D;int i;
    C = (RES *)a;D = (RES *)b;
    for(i = 0;(*C).A[i]!=-1&&(*D).A[i]!=-1;i++)
    {
        if((*C).A[i]<(*D).A[i]) return 1;
        else if((*C).A[i]>(*D).A[i]) return -1;
    }
    if((*C).A[i]==-1) return 1;
    else return -1;
}
int main()
{
    int T,i,j,k,p;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        int N;
        scanf("%d\n",&N);
        RES S[N];
        for(k = 0;k<N;k++)
        {
            j = 0;
        do{
            scanf("%d",&S[k].A[j]);
            j++;
        }while(S[k].A[j-1]!=-1);
        S[k].B = j;
        }
        qsort(S,N,sizeof(RES),cmp);
        for(j = 0;j<N;j++)
        {
            for(p = 0;p<S[j].B-1;p++)
                printf("%d ",S[j].A[p]);
            printf("\n");
        }

    }
    return 0;
}
