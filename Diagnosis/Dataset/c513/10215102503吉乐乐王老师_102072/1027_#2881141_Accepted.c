#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
    double x,y;
    double p,sita;
}point;
int cmp(const void *a,const void *b){
    point x=*(point*)a;
    point y=*(point*)b;
    if(x.sita!=y.sita) return x.sita>y.sita?1:-1;
    return x.p<y.p?1:-1;
}
int main(){
    int t;scanf("%d",&t);getchar();
    int idx=0;
    while(t--){
        int n;scanf("%d",&n);getchar();
        point *pro=(point*)malloc(sizeof(point)*n);
        for(int i=0;i<n;i++){
            scanf("%lf %lf",&pro[i].x,&pro[i].y);
            pro[i].p=sqrt(pro[i].x*pro[i].x+pro[i].y*pro[i].y);
            pro[i].sita=atan2(pro[i].y,pro[i].x);
            if(pro[i].sita<0)pro[i].sita+=2*3.14159265;
        }
        qsort(pro,n,sizeof(pro[0]),cmp);
        printf("case #%d:\n",idx++);
        for(int i=0;i<n;i++){
            printf("(%.4lf,%.4lf)\n",pro[i].p,pro[i].sita);
        }
    }
}

