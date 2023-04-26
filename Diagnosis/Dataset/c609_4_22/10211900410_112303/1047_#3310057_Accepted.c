#include<stdio.h>
#include<stdlib.h>
#define N 95
void mul(int *re,int n)
{
    int i,carry=0;
    for(i=0;i<N;i++){
        int t=re[i]*n+carry;
        re[i]=t%10;
        carry=t/10;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int a,n;
        int re[95]={1};
        scanf("%d %d",&a,&n);
        for(int j=0;j<n;j++){
            mul(re,a);
        }
        printf("case #%d:\n",i);
        int flag=0;
        for(int j=N-1;j>=0;j--){
            if(flag==0&&re[j]==0) continue;
            if(flag==1) printf("%d",re[j]);
            if(flag==0&&re[j]!=0){
                flag=1;
                printf("%d",re[j]);
            }
        }
        printf("\n");
    }
    return 0;
}