#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char xuehao[12];
    int zongshu;
    int tihao[12];
    int score;

}stu;
int cmp(const void *a,const void *b)
{
    stu *p1=(stu*)a;
    stu *p2=(stu*)b;
    if(p1->score != p2->score){
        return p2->score - p1->score;
    }
    else return strcmp(p2->xuehao,p1->xuehao);
}

int main()
{
    int t,n,m,g,j,k,y;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int sum=0;
        printf("case #%d:\n",i);
        scanf("%d %d %d",&n,&m,&g);
        stu a[n];
        int M[m];
        for(int l=0;l<n;l++){
                for(int u=0;u<12;u++){
                    a[l].tihao[u]=0;
                }
            }

        for(int j=0;j<m;j++){
            scanf("%d",&M[j]);
        }

        for(j=0;j<n;j++){
            a[j].score=0;
            scanf("%s %d",a[j].xuehao,&a[j].zongshu);



            for(k=0;k<a[j].zongshu;k++){
                scanf("%d",&a[j].tihao[k]);

                a[j].score+=M[a[j].tihao[k]-1];
            }
            if(a[j].score>=g) sum++;
        }
        printf("%d\n",sum);
        qsort(a,n,sizeof(a[0]),cmp);
        for(y=0;y<n;y++){
            if(a[y].score>=g){
                    printf("%s %d\n",a[y].xuehao,a[y].score);
                }

        }
    }
    }
