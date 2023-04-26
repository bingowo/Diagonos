#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int name;
    int score;
    int win;
    int lose;
} TEAM;

int cmp(const void* p3,const void* p4)
{
    TEAM* p1=(TEAM* )p3;
    TEAM* p2=(TEAM* )p4;
    if((p1->score)<(p2->score)) return 1;
    else if ((p1->score)>(p2->score)) return -1;
    else{
        if((p1->win)<(p2->win)) return 1;
        else if((p1->win)>(p2->win)) return -1;
        else {
            if((p1->lose)>(p2->lose)) return 1;
            else if((p1->lose)<(p2->lose)) return -1;
            else{
                if((p1->name)>(p2->name)) return 1;
                else return -1;
            }
        }
    }
}

int main()
{
    int m=0,n=0,team1=0,team2=0,result=0,num=0;
    TEAM* p=(TEAM *)malloc(10*sizeof(TEAM));
    while(scanf("%d %d",&n,&m)){
        if (m==0&&n==0) break;
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&team1,&team2,&result);
            if(num==0){
                (p+num)->name=team1;
                (p+num)->score=0;
                (p+num)->win=0;
                (p+num)->lose=0;
                num++;
                (p+num)->name=team2;
                (p+num)->score=0;
                (p+num)->win=0;
                (p+num)->lose=0;
                num++;
            }
            else{
                int j=0;
                for(;j<num;j++){
                    if (((p+j)->name)==team1) break;
                }
                if(j==num) {
                    (p+num)->name=team1;
                    (p+num)->score=0;
                    (p+num)->win=0;
                    (p+num)->lose=0;
                    num++;
                }
                j=0;
                for(;j<num;j++){
                    if (((p+j)->name)==team2) break;
                }
                if(j==num) {
                    (p+num)->name=team2;
                    (p+num)->score=0;
                    (p+num)->win=0;
                    (p+num)->lose=0;
                    num++;
                }
            }
            for(int k=0;k<num;k++){
                if(((p+k)->name)==team1) {
                    if(result==1) {
                        (p+k)->win++;
                        (p+k)->score+=3;
                    }
                    else if(result==0) (p+k)->score++;
                    else {
                        (p+k)->lose++;
                        (p+k)->score--;
                    }
                }
                else if(((p+k)->name)==team2) {
                    if(result==1) {
                        (p+k)->lose++;
                        (p+k)->score--;
                    }
                    else if(result==0) (p+k)->score++;
                    else {
                        (p+k)->win++;
                        (p+k)->score+=3;
                    }
                }
            }
        }
        qsort(p,num,sizeof(TEAM),cmp);
        for(int w=0;w<num;w++) printf("%d ",(p+w)->name);
        printf("\n");
    }
    free(p);
    return 0;
}
