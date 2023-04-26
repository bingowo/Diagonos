#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dot[1000][2];
void trans(int j,double x,double y){
dot[j][0]=sqrt(x*x+y*y);
dot[j][1]=atan(y/x);
if(dot[j][1]<0)dot[j][1]=dot[j][1]+3.141592;
}

int cmp(const void* a,const void* b){
double** a1=(double**)a;
double** b1=(double**)b;
if(a1[0]==b1[0]){
    return a1[1]<b1[1];
}
else return a1[0]>b1[0];
}

int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N;
        scanf("%d",&N);
        for(int j=0;j<N;j++){
            double x,y;
            scanf("%lf%lf",&x,&y);
            trans(j,x,y);
        }
        qsort(dot,N,sizeof(dot[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++){
            printf("(%f,%f)\n",dot[j][0],dot[j][1]);
        }
    }
    return 0;

}
