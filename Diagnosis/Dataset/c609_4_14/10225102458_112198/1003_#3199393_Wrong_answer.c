#include <stdlib.h>

int main()
{
    int n,m1,cnt=0;
    long long int m;
    scanf("%d",&n);
    long long int *mn[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&m);
        m1=m;
        do{
            cnt++;
        }while(m/=2333);
        mn[i]=(long long int *)malloc(sizeof(long long int)*(cnt+1));
        mn[i][0]=cnt;
        for(int j=cnt;j>0;j--){mn[i][j]=m1%2333;m1/=2333;}
        cnt=0;
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=mn[i][0];j++){printf("%lld",mn[i][j]);
        if(j!=mn[i][0])printf(" ");}
        printf("\n");


    }
    return 0;
}
