#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    char number[12];
    int score;
};

int cmp(const void*a,const void*b){
struct student a1,b1;
a1=*((struct student *)a);
b1=*((struct student *)b);
return a1.score<b1.score;
}

int main(){
int T;
scanf("%d",&T);
for(int i=0;i<T;i++){

    int N,M,G;
    scanf("%d%d%d",&N,&M,&G);
    struct student p[N];
    int fz[M];
    for(int j=1;j<M+1;j++){
        scanf("%d",&fz[j]);
    }
    int S,sum=0;
    int r=0;
    for(int j=0;j<N;j++){
        scanf("%s",p[j].number);
        scanf("%d",&S);
        for(int k=0;k<S;k++){
            int a;
            scanf("%d",&a);
            sum=sum+fz[a];
        }
        if(sum>G)r=r+1;
        p[j].score=sum;

    }
    qsort(p,N,sizeof(p[0]),cmp);
    printf("case #%d:\n",i);
    printf("%d\n",r);
    for(int x=0;x<N;x++){
        if(p[x].score>G){
        printf("%s %d",p[x].number,p[x].score);
        }
    }
}
return 0;
}
