//sort\1024.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//#define LOCAL
#define TRUE 1
#define FALSE 0
struct stu{
    long long number;
    int score;
};
typedef struct stu student;
student slist[550];
int Marr[12];

int stucmp(student*x,student*y)
{
    if(x->score==y->score){
        return x->number>y->number?1:-1;
    }else{
        return x->score>y->score?-1:1;
    }
}
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int T;
    scanf("%d",&T);
    for(int iT=0;iT<T;++iT){
        printf("case #%d:\n",iT);
        int N,M,G;
        scanf("%d %d %d",&N,&M,&G);
        memset(slist,0,(N+1)*sizeof(student));
        for(int iM=1;iM<=M;++iM){
            scanf("%d",&Marr[iM]);
        }
        int temtotal;
        for(int iN=0;iN<N;++iN){
            temtotal=0;
            scanf("%lld",&slist[iN].number);
            int S;
            scanf("%d",&S);
            int tem;
            for(int iS=0;iS<S;++iS){
                scanf("%d",&tem);
                temtotal+=Marr[tem];
            }
            slist[iN].score=temtotal;
        }
        qsort(slist,N,sizeof(slist[0]),stucmp);
        int Nend=0;
        while(Nend<N&&slist[Nend].score>=G)++Nend;
        printf("%d\n",Nend);
        for(int iN=0;iN<Nend;++iN){
            printf("%lld %d\n",slist[iN].number,slist[iN].score);
        }
    }
}
