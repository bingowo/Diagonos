#include <stdio.h>
#include <stdlib.h>
struct data{
    int score;
    int vict;
    int deft;
    int num;

};
int cmp(const void *a,const void *b){
    struct data d1,d2;
    d1=*((struct data *)a);
    d2=*((struct data *)b);
    if(d2.score!=d1.score){
        return d2.score-d1.score;
    }
    else{
        if(d2.vict!=d1.vict){
            return d2.vict-d1.vict;
        }
        else{
            if(d2.deft!=d1.deft){
                return d1.deft-d2.deft;
            }
            else
            {
                if(d1.num>d2.num)
                    return 1;
                else return -1;
            }

        }
    }


}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        struct data p[n];
        if(n==0&&m==0) break;
        for(int i = 1; i <=n; i++) {
			p[i].num=i;
			p[i].deft=0;
			p[i].score=0;
			p[i].vict=0;
		}
        for(int i=0;i<m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(c==1){
                p[a].score+=3;
                p[b].score-=1;
                p[a].vict++;
                p[b].deft++;
            }
            if(c==-1){
                p[b].score+=3;
                p[a].score-=1;
                p[b].vict++;
                p[a].deft++;
            }
            if(c==0){
                p[a].score++;
                p[b].score++;
            }
        }
        qsort(p,n+1,sizeof(p[1]),cmp);
        for(int j=1;j<=n;j++)printf("%d ",p[j].num);printf("\n");

    }
    return 0;
}
