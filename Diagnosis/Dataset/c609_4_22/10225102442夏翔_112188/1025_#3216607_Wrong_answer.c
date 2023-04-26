#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int num;
    long long score;
    int win;
    int false;
}TEAM;
int cmp1(const void *a, const void *b){
    TEAM x1=*(TEAM*)a, x2=*(TEAM*)b;
    if(x1.score!=x2.score) return x2.score-x1.score;
    else if(x1.win!=x2.win) return x2.win-x1.win;
    else if(x1.false!=x2.false) return x1.false-x2.false;
    return x1.num-x2.num;
}
int main(){
    long long n ,m;
    scanf("%lld %lld", &n, &m);
    TEAM *teams;
    int a, b, c;
    while(n!=0 || m!=0){
        teams = (TEAM*)calloc(n, sizeof(TEAM));
        for(int i=0; i<n; i++) teams[i].num = i+1;
        for(long long i=0; i<m; i++){
            scanf("%d %d %d", &a, &b, &c);
            if(c==1){
                teams[a-1].win++;
                teams[a-1].score += 3;
                teams[b-1].false--;
                teams[b-1].score--;
            }else if(c==-1){
                teams[b-1].win++;
                teams[b-1].score += 3;
                teams[a-1].false--;
                teams[a-1].score--;
            }else{
                teams[a-1].score++;
                teams[b-1].score++;
            }
        }
        qsort(teams,n,sizeof(teams[0]),cmp1);
        for(int i=0; i<n-1; i++) 
            printf("%d ",teams[i].num);
        printf("%d\n",teams[n-1].num);
        free(teams);
        scanf("%d %d", &n, &m);
    }
    return 0;
}