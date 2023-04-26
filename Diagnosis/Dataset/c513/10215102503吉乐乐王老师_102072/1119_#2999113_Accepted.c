#include<stdlib.h>
#include<stdio.h>
int main(){
    long int dis;
    scanf("%ld",&dis);getchar();
    int n;
    scanf("%d",&n);getchar();
    double maxt=-1;
    for(int i=0;i<n;i++){
        long int k,v,tdis;
        scanf("%ld %ld",&k,&v);
        tdis=dis-k;
        double t=(tdis*1.0)/v;
        maxt=t>maxt?t:maxt;
    }
    double ret=(dis*1.0)/maxt;
    printf("%.6lf",ret);
}