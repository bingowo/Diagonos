#include <stdio.h>
#include <stdlib.h>

struct team{
int score;
int victory;
int failure;
int bh;
};

int cmp(const void*x,const void*y){
struct team x1,y1;
x1=*((struct team *)x);
y1=*((struct team *)y);
if(x1.score!=y1.score){
    return x1.score>y1.score;
}
else{
    if(x1.victory!=y1.victory){
        return x1.victory>y1.victory;
    }
    else{
        if(x1.failure!=y1.failure){
          return x1.failure<y1.failure;
        }
        else return x1.bh<y1.bh;
    }
}
}

int main()
{   int n,m;
scanf("%d%d",&n,&m);
if(m==0&&n!=0){
    printf("1\n");
    scanf("%d%d",&n,&m);
}
    while(1){
    struct team p[n+1];
    for(int k=0;k<n;k++){
        p[k].score=0;
        p[k].victory=0;
        p[k].failure=0;
        p[k].bh=k+1;
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(c==1){
            p[a-1].score=p[a-1].score+3;
            p[a-1].victory=p[a-1].victory+1;
            p[a-1].failure=p[a-1].failure;
            p[a-1].bh=a;
            p[b-1].score=p[b-1].score-1;
            p[b-1].victory=p[b-1].victory;
            p[b-1].failure=p[b-1].failure+1;
            p[b-1].bh=b;
        }
        if(c==-1){
            p[b-1].score=p[b-1].score+3;
            p[b-1].victory=p[b-1].victory+1;
            p[b-1].failure=p[b-1].failure;
            p[b-1].bh=b;
            p[a-1].score=p[a-1].score-1;
            p[a-1].victory=p[a-1].victory;
            p[a-1].failure=p[a-1].failure+1;
            p[a-1].bh=a;
        }
        if(c==0){
            p[a-1].score=p[a-1].score+1;
            p[a-1].victory=p[a-1].victory;
            p[a-1].failure=p[a-1].failure;
            p[a-1].bh=a;
            p[b-1].score=p[b-1].score+1;
            p[b-1].victory=p[b-1].victory;
            p[b-1].failure=p[b-1].failure;
            p[b-1].bh=b;
        }
    }
    qsort(p,n,sizeof(p[0]),cmp);
    for(int j=n-1;j>=0;j--){
        printf("%d ",p[j].bh);
    }
    //printf("\n");
    if(m==0&&n==0)break;
    else {
        scanf("%d%d",&n,&m);
        printf("\n");
    }
    return 0;
}
