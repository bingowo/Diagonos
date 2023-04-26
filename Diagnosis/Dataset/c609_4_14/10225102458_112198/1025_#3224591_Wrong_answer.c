#include <stdio.h>
#include <stdlib.h>
typedef struct {int score;int sort;int fail;int tru;}match;
int cmp(const void* a,const void *b)
{
    match aa=*(match*) a;
    match bb=*(match*) b;
    if(aa.score==bb.score){
        if(aa.tru==bb.tru){
                if(aa.fail==bb.fail)return aa.sort-bb.sort;
                else return aa.fail-bb.fail;
        }
        else return bb.tru-aa.tru;
        }
    else return bb.score-aa.score;

}
int main()
{
    int n,m,a,b,c;
    scanf("%d%d",&n,&m);
    while((n|| m)==1){
        match com[n];
        for(int i=0;i<n;i++){
            com[i].score=0;
            com[i].sort=i+1;
            com[i].fail=0;
            com[i].tru=0;
        }
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            if(c==1){com[a-1].score+=4;com[b-1].score-=1;com[b-1].fail++;com[a-1].tru++;}
            else if(c==-1){com[b-1].score+=4;com[a-1].score-=1;com[a-1].fail++;com[b-1].tru++;}
            else {com[b-1].score+=1;com[a-1].score+=1;}
        }
        qsort(com,n,sizeof(com[0]),cmp);
        for(int i=0;i<n;i++){
            printf("%d",com[i].sort);
            i==n-1?printf("\n"):printf(" ");
        }
        scanf("%d%d",&n,&m);
    }
    return 0;
}
