#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
typedef struct{
    double jiaodu;
    double changdu;
    double x;
    double y;

}stu;

int cmp(const void *a,const void *b){
    stu *p1=(stu*)a;
    stu *p2=(stu*)b;
    if(p1->changdu>p2->changdu) return -1;
    else if(p1->changdu < p2->changdu) return 1;
    else if(p1->jiaodu < p2->jiaodu ) return 1;
    else return -1;


}
int main()
{
    int t;
    stu a[1000];
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        printf("case #%d:\n",i);
        int n;
        for(int j=0;j<n;j++){
            scanf("%lf %lf",&a[j].x,&a[j].y);
            a[j].changdu=sqrt(pow(a[j].x,2)+pow(a[j].y,2));
            if(a[j].x>0&&a[j].y>0)
            a[j].jiaodu=atan(a[j].y/a[j].x);
            if(a[j].x>0&&a[j].y<0)
            a[j].jiaodu=2*PI-atan(a[j].y/a[j].x);
            if(a[j].x<0&&a[j].y>0)
            a[j].jiaodu=0.5*PI+atan(a[j].y/a[j].x);
            if(a[j].x<0&&a[j].y<0)
            a[j].jiaodu=PI+atan(a[j].y/a[j].x);
        }

        qsort(a,n,sizeof(a[0]),cmp);
        for(int k=0;k<n;k++){
            printf("(%.4lf,%.4lf)\n",a[k].changdu,a[k].jiaodu);
        }

    }
}
