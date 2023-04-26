#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct x_y{
    double p;
    double angle;
}a[1000];

int cmp(const void *a,const void *b){
    struct x_y *a1 = (struct x_y*)a;
    struct x_y *b1 = (struct x_y*)b;
    if(a1->angle == b1->angle){
        return a1->p > b1->p?-1:1;
    }else{
        return a1->angle > b1->angle?1:-1;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    int n;
    double x,y;
    for(int i = 0;i < T;i++){
        scanf("%d",&n);
        for(int i = 0;i < n;i++){
            scanf("%lf%lf",&x,&y);
            a[i].p = sqrt(x * x + y * y);
            a[i].angle = atan2(y,x);
            if(a[i].angle < 0)a[i].angle += 2 * acos(-1);
        }
        qsort(a,n,sizeof(struct x_y),cmp);
        printf("case #%d:\n",i);
        for(int j = 0;j < n;j++){
            printf("(%.4lf,%.4lf)\n",a[j].p,a[j].angle);
        }
    }

    return 0;
}
