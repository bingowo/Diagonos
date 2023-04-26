#include <stdio.h>
#include <stdlib.h>

typedef struct team{
    int point;
    int num;
    int win;
    int lose;
}Team;

int cmp(const void*a,const void*b){
    Team *t1=(Team*)a;
    Team *t2=(Team*)b;
    if(t1->point==t2->point){
        if(t1->win==t2->win){
            if(t1->lose==t2->lose){
                return (t1->num-t2->num);
            }
            return (t1->lose-t2->lose);
        }
        return (t2->win-t1->win);
    }
    return (t2->point-t1->point);
}
int main()
{
    int n,m,i,j,k;
    scanf("%d%d",&n,&m);
    while(n!=0 || m!=0){
        int a,b,c;
        Team T[11];
        for(i=0;i<=10;i++){
            T[i].num=i;
            T[i].point=0;
            T[i].win=0;
            T[i].lose=0;
        }
        for(j=0;j<m;j++){
            scanf("%d%d%d",&a,&b,&c);
            if(c==1){
                T[a].point+=3;
                T[b].point--;
                T[a].win++;
                T[b].lose++;
            }
            if(c==-1){
                T[b].point+=3;
                T[a].point--;
                T[b].win++;
                T[a].lose++;
            }
            if(c==0){
                T[a].point++;
                T[b].point++;
            }
        }
        qsort(T+1,n,sizeof(Team),cmp);

        for(k=1;k<n;k++)
            printf("%d ",T[k].num);
        printf("%d\n",T[k].num);
        scanf("%d%d",&n,&m);
    }
    return 0;
}
