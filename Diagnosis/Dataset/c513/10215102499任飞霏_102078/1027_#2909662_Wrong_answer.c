#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ji{
    double x;
    double y;
    double tan;
    double r;
    double th;
};

int cmp(const void* a,const void* b);

int main()
{
    struct ji s[1010];
    int T;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        int n;
        scanf("%d",&n);
        for(int j = 0;j < n;j++){
            scanf("%lf%lf",&s[j].x,&s[j].y);
            s[j].tan = s[j].y/s[j].x;
            s[j].r = sqrt(s[j].y*s[j].y + s[j].x*s[j].x);
            s[j].th = atan2(s[j].y,s[j].x);
            if(s[j].y<0)s[j].th += 3.1415926;
        }
        qsort(s,n,sizeof(struct ji),cmp);
        printf("case #%d:\n",i);
        for(int k = 0;k < n;k++){
            printf("(%.4lf,%.4lf)\n",s[k].r,s[k].th);
        }

    }
    return 0;
}

int cmp(const void* a,const void* b)
{
    struct ji m = *((struct ji*)a);
    struct ji n = *((struct ji*)b);
    if(m.th != n.th){
        if(m.th>n.th)return 1;
        else
            return -1;
    }
    else{
        if(m.r>n.r)return -1;
        else if(m.r<n.r)return 1;
    }
}
