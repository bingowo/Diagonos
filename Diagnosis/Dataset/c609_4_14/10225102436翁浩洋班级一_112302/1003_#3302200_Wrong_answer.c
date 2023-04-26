#include <stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<=T;cas++)
    {
        long long int n;int m=0;int i=0;
        int a[100]={0};
        scanf("%d",&n);
        do{
            m=n%2333;
            n=n/2333;
            a[i]=m;
            i++;
        }while(n!=0);
        for(;i--;i>=0)printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}