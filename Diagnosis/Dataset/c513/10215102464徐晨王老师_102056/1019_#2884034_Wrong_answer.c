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
    return y1.score-x1.score;
}
/*else{
    if(x1.victory!=y1.victory){
        return y1.victory-x1.victory;
    }
    else{
        if(x1.failure!=y1.failure){
          return x1.failure-y1.failure;
        }
        else return x1.bh-y1.bh;
    }
}*/
}

int main()
{   int n,m;
scanf("%d%d",&n,&m);
if(m==0&&n!=0){
    printf("1\n");
    scanf("%d%d",&n,&m);
}
    while(n!=0&&m!=0){
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
            p[a].score=p[a].score+3;
            p[a].victory=p[a].victory+1;
            p[a].failure=p[a].failure;
            p[a].bh=a+1;
            p[b].score=p[b].score-1;
            p[b].victory=p[b].victory;
            p[b].failure=p[b].failure+1;
            p[b].bh=b+1;
        }
        if(c==-1){
            p[b].score=p[b].score+3;
            p[b].victory=p[b].victory+1;
            p[b].failure=p[b].failure;
            p[b].bh=b+1;
            p[a].score=p[a].score-1;
            p[a].victory=p[a].victory;
            p[a].failure=p[a].failure+1;
            p[a].bh=a+1;
        }
        if(c==0){
            p[a].score=p[a].score+1;
            p[a].victory=p[a].victory;
            p[a].failure=p[a].failure;
            p[a].bh=a+1;
            p[b].score=p[b].score+1;
            p[b].victory=p[b].victory;
            p[b].failure=p[b].failure;
            p[b].bh=b+1;
        }
    }
    qsort(p,n,sizeof(p[0]),cmp);
    for(int j=0;j<n;j++){
        printf("%d",p[j].bh);
    }
    printf("\n");
    scanf("%d%d",&n,&m);
    }
    return 0;
}
