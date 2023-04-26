#include <stdio.h>
#include <stdlib.h>

struct data{
    long long int x;
    int number;
};

int cmp(const void *a,const void *b){
    struct data d1,d2;
    d1=*((struct data *)a);
    d2=*((struct data *)b);
    if(d2.number!=d1.number)
        return d2.number-d1.number;
    else{
        if(d1.x>d2.x) return 1;
        else return -1;
    }
}

int main()
{
    struct data p[10000];
    int t,n;
    scanf("%d",&t);
    for(int k=0;k<t;k++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%ll",&p[i].x);
            int d=1;
            p[i].number=0;
            for(int j=0;j<64;j++){
                if(p[i].x&d) p[i].number++;
                d=d<<1;
            }
        }
        qsort(p,n,sizeof(p[0]),cmp);
        printf("case #%d:\n",k);
        int m;
        for(m=0;m<n;m++){
            printf("%ll",p[m].x);
        }
    }
    return 0;
}
