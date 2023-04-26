#include <stdio.h>
#include <stdlib.h>
int cmp(void* a,void* b){
    long long int m,n;
    m=*(long long int*)a,n=*(long long int*)b;
    if(num(m)!=num(n)) return num(n)-num(m);
    else if(m<n) return-1;
    else return 1;
}

int num(int x){
    int sum=0;
    if(x>=0){
        while(x){
            sum+=x%2;
            x=x/2;
        }
    }
    else {
        sum=64-num(-x-1);
    }
    return sum;
}

int main()
{
    int t,i,j;
    scanf("%d",&t);
    long long int a[t],b[t][10000];
    for(i=0;i<t;i++){
        scanf("%lld",&a[i]);
        for(j=0;j<a[i];j++) scanf("%lld",&b[i][j]);
    }
    for(i=0;i<t;i++){
        qsort(b[i],a[i],sizeof(b[i][0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<a[i];j++) printf("%lld ",b[i][j]);
        printf("\n");
    }
    return 0;
}
