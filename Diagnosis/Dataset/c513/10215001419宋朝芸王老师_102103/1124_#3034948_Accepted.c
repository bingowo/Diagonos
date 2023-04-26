#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000

int GCD(int m,int n)
{
    int temp;
    if(m<n) temp=m,m=n,n=temp;     //m中放较大数
    if(m%n==0) return n;
    temp=n,n=m%n,m=temp;
    return(GCD(m,n));
}

int cmp(const void *a, const void *b){  //asc
    return *(int*)a - *(int*)b;
}

int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){

        int num[N] = {0};
        int cnt = 0;
        int index[1001] = {0};
        int n;
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            int temp;
            scanf("%d",&temp);
            index[temp]++;

            if(index[temp] == 1) num[cnt++] = temp;
        }

        //if(cnt == 1){printf("case #%d:\n0\n",R);continue;}

        qsort(num,cnt,sizeof(num[0]),cmp);

        int res = 0;
        for(int i = 0; i < cnt; i++){
            for(int j = 0; j < i; j++){

                int max = num[i], min = num[j];
                if(GCD(max,min) == 1) res++;
            }
        }

        printf("case #%d:\n%d\n",R,res);
    }
    return 0;
}
