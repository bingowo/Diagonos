#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data{
    char id[100];
    int score;

};
int cmp(const void *a,const void *b){
    struct data d1,d2;
    d1=*((struct data *)a);
    d2=*((struct data *)b);
    if(d2.score!=d1.score){
        return d2.score-d1.score;
    }
    else{
        return strcmp(d1.id,d2.id);
    }

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=0;cas<t;cas++){
        struct data p[1000];
        int n,m,g;
        scanf("%d%d%d",&n,&m,&g);
        int points[11];
        for(int i=1;i<=m;i++){
            scanf("%d",&points[i]);
        }
        for(int j=0;j<n;j++){
            int s;
             p[j].score=0;
            scanf("%s%d",p[j].id,&s);
            for(int k=0;k<s;k++){
                int fen;
                scanf("%d",&fen);
                p[j].score+=points[fen];
            }

        }
        qsort(p,n,sizeof(p[0]),cmp);
        int z=0;
        while(p[z].score>=g){
            z++;
        }
        printf("case #%d:\n%d\n",cas,z);
        for(int q=0;q<z;q++){
            printf("%s %d\n",p[q].id,p[q].score);
        }
    }

    return 0;
}
