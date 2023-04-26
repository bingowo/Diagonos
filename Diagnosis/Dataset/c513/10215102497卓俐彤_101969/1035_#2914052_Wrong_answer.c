#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct column{
    long long int R;
    long long int H;
    long long int S;
    long long int sumS;
};

int compar1(const void*a,const void*b){
    struct column d1,d2;
    d1=*((struct column*)a);
    d2=*((struct column*)b);
    if(d2.sumS>d1.sumS)return 1;
    else return -1;
}

int compar2(const void*a,const void*b){
    long long int d1,d2;
    d1=*((long long int*)a);
    d2=*((long long int*)b);
    if(d2>d1)return 1;
    else return -1;
}


int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    struct column columns[n];
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&columns[i].R,&columns[i].H);
        columns[i].S=2*columns[i].R*columns[i].H;
        columns[i].sumS=columns[i].S+columns[i].R*columns[i].R;
    }
    qsort(columns,n,sizeof(columns[0]),compar1);
    long long int maxS=columns[0].sumS;
    long long int s[n];
    int k=0;
    for(int i=1;i<n;i++)s[k++]=columns[i].S;
    qsort(s,k,sizeof(s[0]),compar2);
    for(int i=0;i<m-1;i++)maxS+=s[i];
    printf("%lld\n",maxS);
    return 0;
}
