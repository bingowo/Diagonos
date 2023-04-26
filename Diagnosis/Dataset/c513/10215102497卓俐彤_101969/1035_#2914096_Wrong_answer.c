#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct column{
    long long int R;
    long long int H;
    long long int S;
    long long int s;
};

int compar1(const void*a,const void*b){
    struct column d1,d2;
    d1=*((struct column*)a);
    d2=*((struct column*)b);
    if(d2.S>d1.S)return 1;
    else return -1;
}

int compar2(const void*a,const void*b){
    struct column d1,d2;
    d1=*((struct column*)a);
    d2=*((struct column*)b);
    if(d2.R>d1.R)return 1;
    else return -1;
}


int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    struct column columns[n+1];
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&columns[i].R,&columns[i].H);
        columns[i].S=2*columns[i].R*columns[i].H;
        columns[i].s=columns[i].R*columns[i].R;
    }
    qsort(columns,n,sizeof(columns[0]),compar1);
    long long int maxS=0;
    for(int i=0;i<m;i++)maxS+=columns[i].S;
    qsort(columns,m,sizeof(columns[0]),compar2);
    printf("%lld\n",maxS+columns[0].s);
    return 0;
}
