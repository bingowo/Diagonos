#include <stdlib.h>
#include <stdlib.h>
typedef struct
{
    int bianhao;
    int win;
    int lose;
    int score;
}stu;

int cmp(const void *a,const void *b)
{
    stu *pa=(stu *)a;
    stu *pb=(stu *)b;
    if(pa->score!=pb->score){
        return pa->score > pb->score ? -1: 1;
    }
    else if(pa->win != pb ->win){
        return pa->win > pb->win? -1:1;
    }
    else if(pa->lose != pb->lose){
        return pa->lose > pb->lose?1:-1;}
    else{
        return pa->bianhao - pb->bianhao;
    }

}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    stu a[n];
    while(m&&n){
    for(int i=0;i<m;i++){

        int x,y,c;
        for(int k=0;k<n;k++){
        a[k].score=0;
        a[k].win=0;
        a[k].lose=0;
        a[k].bianhao=k+1;
    }

        scanf("%d %d %d",&x,&y,&c);

        if(c==1){
            a[x-1].win++;
            a[y-1].lose++;
            a[x-1].score+=3;
            a[y-1].score-=1;
        }
        if(c==0){
            a[x-1].score+=1;
            a[y-1].score+=1;
        }
        if(c==-1){
            a[y-1].win++;
            a[x-1].lose++;
            a[y-1].score+=3;
            a[x-1].score-=1;
        }
    }
        qsort(a,n,sizeof(a[0]),cmp);
        for(int j=0;j<n;j++)
        {
            printf("%d%c",a[j].bianhao, j == n - 1?'\n':' ');
        }
        scanf("%d %d",&n,&m);

}
}
