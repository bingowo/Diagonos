#include <stdlib.h>
#include <string.h>
typedef struct
{
    int no;
    int win;
    int fail;
    int point;
} team;
int cmp(const void* a,const void* b)
{
    team t1,t2;
    t1=*(team*)a;t2=*(team*)b;
    if(t1.point-t2.point==0){
        if(t1.win-t2.win==0){
            if(t1.fail-t2.fail==0){
                return(t1.no-t2.no);
            }
            else return(t1.fail-t2.fail);
        }
        else return(t2.win-t1.win);
    }
    else return(t1.point-t2.point);
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)&&n!=0&&m!=0){
        team *t;
        t=(team*)malloc(n*sizeof(team));
        for(int i=0;i<n;i++){
            t[i].no=i+1;
            t[i].win=0;t[i].fail=0;t[i].point=0;
        }
        for(int i=0;i<m;i++){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if(c==1){
                t[a-1].point=t[a-1].point+3;t[a-1].win++;
                t[b-1].point=t[b-1].point-1;t[b-1].fail++;
            }
            else if(c==-1){
                t[a-1].point=t[a-1].point-1;t[a-1].fail++;
                t[b-1].point=t[b-1].point+3;t[b-1].win++;
            }
            else{
                t[a-1].point++;
                t[b-1].point++;
            }
        }
        qsort(t,n,sizeof(t[0]),cmp);
        for(int i=0;i<n;i++)printf("%d ",t[i].no);
        printf("\n");
    }
    return 0;
}
