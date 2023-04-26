#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    long long int x,y;
    unsigned long long int man;
}POINTS;

unsigned long long uabs(long long int a, long long int b){
    if(a > b) return (unsigned long long)(a-b);
    else return (unsigned long long)(b-a);
}

int cmp(const void *a, const void *b){
    POINTS *pa = (POINTS*)a, *pb = (POINTS*)b;
    if(pa->man > pb->man) return -1;
    if(pa->man < pb->man) return 1;
    if(pa->x > pb->x) return 1;
    if(pa->x < pb->x) return -1;
    if(pa->y > pb->y) return 1;
    if(pa->y < pb->y) return -1;
    return 0;
}


int cal_step(POINTS *in, int a, int b){

    unsigned long long int manhatten = uabs(in[a].x,in[b].x) + uabs(in[a].y,in[b].y);
    if(manhatten % 2 == 0)
        return -1;

    if(manhatten == 1) return 1;
    /***try alg***/
    int i = 0;
    while(pow(2,i) < manhatten) i++;
    return i;

}

int main()
{
    int n;
    scanf("%d",&n);

    POINTS *in = (POINTS*)malloc(n*sizeof(POINTS));

    /***input***/
    for(int i = 0; i < n; i++){
        scanf("%lld%lld",&in[i].x,&in[i].y);
        in[i].man = uabs(in[i].x,0) + uabs(in[i].y,0);
    }

    /***sort_by_manhatten***/
    qsort(in,n,sizeof(POINTS),cmp);

    /***print***/
    printf("%llu\n",uabs(in[0].x,in[1].x) + uabs(in[0].y,in[1].y));

    /***cal_steps***/
    long long int steps = 0;
    for(int i = 0; i+1 < n; i++){

        if(in[i].x == in[i+1].x && in[i].y == in[i+1].y)
            continue;

        if(cal_step(in,i,i+1) == -1){
            printf("%lld\n",steps);
            return 0;
        }

        steps += cal_step(in,i,i+1);
    }

    printf("%lld\n",steps);

    return 0;
}
