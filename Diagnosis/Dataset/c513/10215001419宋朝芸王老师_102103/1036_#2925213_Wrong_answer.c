#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    long long int x,y;
}POINTS;

int cmp(const void *a, const void *b){
    long long int ax = ((POINTS*)a)->x, ay = ((POINTS*)a)->y,
            bx = ((POINTS*)b)->x, by = ((POINTS*)b)->y;
    if(abs(ax)+abs(ay) > abs(bx)+abs(by)) return -1;
    if(abs(ax)+abs(ay) < abs(bx)+abs(by)) return 1;
    if(ax > bx) return 1;
    if(ax < bx) return -1;
    if(ay > by) return 1;
    if(ay < by) return -1;
    return 0;
}

int cal_step(POINTS *in, int a, int b){

    long long int manhatten = abs(in[a].x - in[b].x) + abs(in[a].y - in[b].y);
    if(manhatten /2 == 0)
        return 0;

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

    for(int i = 0; i < n; i++){
        scanf("%lld%lld",&in[i].x,&in[i].y);
    }

    qsort(in,n,sizeof(POINTS),cmp);

    printf("%lld\n",abs(in[0].x - in[1].x)
                + abs(in[0].y - in[1].y));

    long long int steps = 0;
    for(int i = 0; i+1 < n; i++){
        if(cal_step(in,i,i+1) == 0){
            printf("0\n");
            return 0;
        }
        steps += cal_step(in,i,i+1);
    }

    printf("%d\n",steps);

    return 0;
}
