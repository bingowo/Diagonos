#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    char* number;
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
    int m;
    for(int j=1;j<M+1;j++){
        scanf("%d",&m);
        fz[j]=m;
    }
    char s[12];
    int S,sum=0;
    int k=0;
    for(int j=0;j<N;j++){
        scanf("%s",s);
        scanf("%d",&S);
        for(int k=9;k<S;k++){
            int a;
            scanf("%d",&a);
            sum=sum+fz[a];
        }
        if(sum>=G){
            p[k].score=sum;
            p[k].number=s;
            k=k+1;
        }

    }
    printf("%d\ncase #%d:\n",k,i);
    qsort(p,k,sizeof(p[0]),cmp);
    for(int x=0;x<k+1;x++){
        printf("%s %d",p[x].number,p[x].score);
    }
}
return 0;
}
