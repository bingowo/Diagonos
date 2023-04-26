#include<stdio.h>
long long a[51];
int main()
{
    int t;
    int step=0;
    scanf("%d",&t);
    a[1]=1;
    a[2]=2;
    a[3]=4;
    a[4]=8;
    for(int m=5;m<51;m++){
        a[m]=a[m-1]+a[m-2]+a[m-3]+a[m-4];
        int n;
        while(scanf("%d",&n)!=EOF){
            printf("case #%d:\n",step);
            step++;
        }
    }
    return 0;
}