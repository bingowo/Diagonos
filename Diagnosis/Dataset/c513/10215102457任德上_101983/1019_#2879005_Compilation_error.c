#include<stdio.h>
#include<stdlib.h>
struct team{
    int num;
    int score;
};
int cmp(void *a,void *b){
    struct team m,n;
    m=*((struct team*)a);
    n=*((struct team*)b);
    return n.score-m.score;
}
int main(){
    int m,n,a,b,c;
    scanf("%d%d",&n,&m);
    while(m!=0&&n!=0){
        struct team k[n];
        for(int i=0;i<n;i++)k[i].num=i+1,k[i].score=0;
        while(m-->0){
            scanf("%d%d%d",&a,&b,&c);
            if(c==1){k[a-1].score+=3,k[b-1].score-=1;}
            else if(c==-1){k[a-1].score-=1,k[b-1].score+=3;}
            else {k[a-1].score+=1,k[b-1].score+=1;}
            qsort(k,n,sizeof(struct team),cmp);
        }
        for(int i=0;i<n-1;i++)printf("%d ",k[i].num);
        printf("%d\n",k[i].num);
        scanf("%d%d",&n,&m);
    }
    return 0;
    }

