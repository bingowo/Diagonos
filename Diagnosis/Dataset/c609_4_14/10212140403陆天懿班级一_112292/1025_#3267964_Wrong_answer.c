#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define N 11
int a[N],b[N],c[N],r[N];
int n,m;
int ta,tb,tc;

void Init(){
    for(int i=1;i<=n;i++)
        r[i]=i;
}

int Cmp(const int* pa, const int* pb){
    if(a[*pa]!=a[*pb]) return a[*pb]-a[*pa];
    if(b[*pa]!=b[*pb]) return b[*pb]-b[*pa];
    if(c[*pa]!=c[*pb]) return c[*pa]-c[*pb];
    return *pa-*pb;
}

void Print(){
    printf("%d",r[1]);
    for(int i=2;i<=n;i++)
        printf(" %d",r[i]);
    printf("\n");
}

int main(){
    for(scanf("%d%d",&n,&m);n*m;scanf("%d%d",&n,&m)){
        Init();
        while(m--){
            scanf("%d%d%d",&ta,&tb,&tc);
            if(tc==-1){
                ta=ta^tb;tb=ta^tb;ta=ta^tb;
            }
            if(tc){
                a[ta]+=3,a[tb]-=1;
                b[ta]+=1,c[tb]+=1;
            }
            else{
                a[ta]+=1,a[tb]+=1;
            }
        }
        qsort(r+1,n,sizeof(r[0]),Cmp);
        Print();
    }

    return 0;
}
