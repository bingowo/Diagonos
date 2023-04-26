#include<stdio.h>
#include<stdlib.h>
int cmp(const void* _a,const void* _b)
{
    int* a = (int*)_a ; int* b= (int*)_b ;
    if(score_count[*a]!=score_count[*b]) {
        return score_count[*b] - score_count[*a] ? 1 : -1 ;}
    if(wins_count[*a]!=wins_count[*b]) {
        return wins_count[*b] - wins_count[*a] ? 1 : -1 ;}
    if(lose_count[*a]!=lose_count[*b]) {
        return lose_count[*a] - lose_count[*b] ? 1 : -1 ;}
    return *a - *b ? 1 : -1 ;
}

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m) && n!=0){
        extern score_count[n+1]; extern wins_count[n+1];
        extern lose_count[n+1]; int a,b,c;
        for(int h=1;h!=n+1;h++) {
            score_count[h] = 0 ;
            wins_count[h] = 0 ;
            lose_count[h] = 0 ;
        }
        for(int i=0;i!=m;i++){
            scanf("%d %d %d",&a,&b,&c);
            if(c==1) {
                wins_count[a]+=1;lose_count[b]+=1;
                score_count[a]+=3;score_count[b]-=1;}
            else if(c==-1) {
                wins_count[b]+=1;lose_count[a]+=1;
                score_count[a]-=1;score_count[b]+=3;}
            else {
                score_count[a]+=1;score_count[b]+=1;}
            int ranking[n];
            for(int j=0;j!=n;j++) ranking[j]=j+1;
            qsort(ranking,n,sizeof(ranking[0]),cmp);
            for(int k=0;k!=n;k++) printf("%d",ranking[k]);
        }
    }
}