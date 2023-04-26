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
    long long int d1,d2;
    d1=*((long long int*)a);
    d2=*((long long int*)b);
    if(d2>d1)return 1;
    else return -1;
}


int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    struct column columns[n+1];
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&columns[i].R,&columns[i].H);
        columns[i].s=2*columns[i].R*columns[i].H;
        columns[i].S=columns[i].R*columns[i].R+columns[i].s;
    }
    qsort(columns,n,sizeof(columns[0]),compar1);
    long long int maxS=0,sn=0;
    long long int s0=columns[0].S-columns[0].s;
    for(int i=0;i<n-m+1;i++){
        sn=columns[i].S;
        long long int s[n][2];
        int k=0;
        for(int j=0;j<n;j++){
            if(j==i)continue;
            s[k][0]=columns[j].s;
            if(columns[j].R>columns[0].R)s[k++][1]=columns[j].S-columns[j].s;
            else s[k++][1]=0;
        }
        s[k][0]='\0';
        qsort(s,k,sizeof(s[0]),compar2);
        for(int j=0;j<m-1;j++){
            sn+=s[j][0];
            if(s[j][1]>s0){
                sn=sn-s0+s[j][1];
                s0=s[j][1];
            }
        }
        if(sn>maxS)maxS=sn;
    }
    
    printf("%lld\n",maxS);
    return 0;
}
