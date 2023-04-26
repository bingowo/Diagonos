#include<stdio.h>
#include<stdlib.h>

int main(){
    struct group{
        int num,win,fall,score;
    }
    int n,m;
    scanf("%d %d",&n,&m);
    while(n!=0&&m!=0){
        struct *p[n+1];
        for(int i=0;i<=n;i++){
            p->win=0;p->fall=0;p->score=0;p->num=i;
        }
        int a,b,c;
        while(m--){
            scanf("%d %d %d",&a,&b,&c);
            if(c==1){
                (p+a)->win++;(p+b)->fall++;
                (p+a)->score+=3;(p+b)->score--;
            }
            if(c==-1){
                (p+b)->win++;(p+a)->fall++;
                (p+b)->score+=3;(p+a)->score--;
            }
            if(c==0){
                (p+a)->score++;(p+b)->score++;
            }
        }
        scanf("%d %d",&n,&m);
}