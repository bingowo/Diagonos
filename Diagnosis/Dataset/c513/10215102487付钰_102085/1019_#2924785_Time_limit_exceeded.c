#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int jifen;
    int win;
    int lose;
    int all;
    int bianhao;
}stu;

int cmp(const void *a,const void *b)
{
    stu *pa=(stu *)a;
    stu *pb=(stu *)b;
    if(pa->jifen!=pb->jifen){
        return pa->jifen > pa->jifen ? -1:1;
    }
    else if(pa->win != pb ->win){
        return pa->win > pb->win? -1:1;
    }
    else if(pa->lose != pb->lose){
        return pa->lose > pa->lose? 1:-1;    }
    else{
        return pa->bianhao - pb->bianhao;
    }

}
int main()
{
    int m,n,a,b,c;

    scanf("%d %d",&n,&m);
    while(!(m==0&n==0)){
    stu x[n];
    for(int k=0;k<n;k++){
        x[k].jifen=0;
        x[k].win=0;
        x[k].lose=0;
        x[k].all=0;
    }
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&a,&b,&c);
        x[a].bianhao=a;
        x[b].bianhao=b;
        if(c==1){
            x[a].jifen++;
            x[b].jifen++;
        }
        if(c==-1){
            x[a].lose++;
            x[a].jifen--;
            x[b].win++;
            x[b].jifen+=3;
        }
    }
    qsort(x,n,sizeof(x[0]),cmp);
    int g;
    for(g=0;g<n-1;g++){
        printf("%d ",x[g].bianhao);
    }
    printf("%d\n",x[g].bianhao);
    }
    return 0;
}
