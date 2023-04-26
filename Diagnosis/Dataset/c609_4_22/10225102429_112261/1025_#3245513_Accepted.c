#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int poi,win,lose,num;
}team;
int cmp(const void* a, const void* b){
    int pa = (*(team*)a).poi,pb = (*(team*)b).poi;
    int wa = (*(team*)a).win,wb = (*(team*)b).win;
    int la = (*(team*)a).lose,lb = (*(team*)b).lose;
    int na = (*(team*)a).num,nb = (*(team*)b).num;
    if(pa!=pb) return pb-pa;
    else{
        if(wa!=wb) return wb-wa;
        else{
            if(la!=lb) return la-lb;
            return na-nb;
        }
    }
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)&&n){
        team a[n];
        for(int i = 0; i<n; i++){
            a[i].num = i+1;
            a[i].poi = 0;
            a[i].win = 0;
            a[i].lose = 0;
        }
        for(int i = 0; i<m; i++){
            int ta,tb,res; scanf("%d%d%d",&ta,&tb,&res);
            ta--,tb--;
            if(res) {
                if(res==-1) {
                    int t;
                    t = ta;
                    ta = tb;
                    tb = t;
                }
                a[ta].poi+=3;
                a[ta].win++;
                a[tb].poi-=1;
                a[tb].lose++;
            }
            else{
                a[ta].poi+=1;
                a[tb].poi+=1;
            }
        }
        qsort(a,n,sizeof(team),cmp);
        for(int i = 0; i<n; i++){
            printf("%d%c",a[i].num,i==n-1?'\n':' ');
        }
    }
    return 0;
}