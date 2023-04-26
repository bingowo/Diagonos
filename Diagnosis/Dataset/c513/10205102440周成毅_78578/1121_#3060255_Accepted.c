#include <stdio.h>

int p[100];
int n;

int istrue(int num,int co){
    if(num-p[co]==0 || num+p[co]==0)
        return 1;
    else if(co==n-1)
        return 0;
    else
        return istrue(num-p[co],co+1)+ istrue(num+p[co],co+1)+ istrue(num,co+1);
}

int main() {
    int m,sum=0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        p[i] = m;
        sum+=m;
    }
    for(int i=1;i<=sum;i++) {
        if (istrue(i,0))
            printf("1");
        else
            printf("0");
    }
    printf("\n");
    return 0;
}
