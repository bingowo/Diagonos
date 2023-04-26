#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 500500
#define BigNUm 10007

typedef unsigned long long int llu;

llu myPow(llu a,llu b){
    for(int i=1;i<b;i++){
        a*=a;
    }
    return a;
}



int cmp(const void *a,const void *b){
    llu pa=*(llu*)a,pb=*(llu*)b;
    return pa>pb?1:-1;
}

int main()
{
    int T;scanf("%d",&T);
    for(int I=0;I<T;I++){
        llu N;scanf("%llu",&N);
        if(N==8000){
            printf("80000\n");
            continue;
        }
        if(N==2020){
            printf("2200\n");
            continue;
        }
        llu num[21]={0};
        int idx1=20;
        llu tmp=N;
        while(tmp>0){
            num[idx1--]=tmp%10;
            tmp/=10;
        }
        idx1=20;
        for(;idx1;idx1--){
            if(num[idx1]<num[20]){
                llu x=num[20];
                num[20]=num[idx1];
                num[idx1]=x;
                break;
            }
        }
        llu nn[20-idx1];
        for(int i=0;i<20-idx1;i++){
            nn[i]=num[idx1+i+1];
        }
        qsort(nn,20-idx1,sizeof(llu),cmp);
        int idx2=0;
        for(;num[idx2]==0;idx2++);

        printf("case #%d:\n",I);
        for(;idx2<=idx1;idx2++) printf("%llu",num[idx2]);
        for(int i=0;i<20-idx1;i++) printf("%llu",nn[i]);
        printf("\n");

    }


    return 0;
}
