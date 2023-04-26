#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

#define LEN 1000000
#define BigNUm 10007

typedef unsigned long long int llu;

typedef struct{
    llu R;
    llu H;
    llu sideS;
    llu topS;
}CD;

int cmp(const void *a,const void *b){
    CD pa=*(CD*)a,pb=*(CD*)b;
    return pa.sideS>pb.sideS?-1:1;
}

int main()
{
    int n,m;scanf("%d%d",&n,&m);
    CD cds[1000]={0};
    for(int i=0;i<n;i++){
        scanf("%llu%llu",&cds[i].R,&cds[i].H);
        cds[i].sideS=2*cds[i].H*cds[i].R;
        cds[i].topS=cds[i].R*cds[i].R;
    }

    qsort(cds,n,sizeof(CD),cmp);

    llu totalS=0,tmpS=0;
    for(int j=0;j<n;j++){
        tmpS=cds[j].sideS+cds[j].topS;
        int cnt=1;
        for(int k=0;cnt<m;k++){
            if(k!=j){
                tmpS+=cds[k].sideS;
                cnt++;
            }
        }
        if(tmpS>totalS) totalS=tmpS;
    }


    printf("%llu",totalS);

    return 0;
}
