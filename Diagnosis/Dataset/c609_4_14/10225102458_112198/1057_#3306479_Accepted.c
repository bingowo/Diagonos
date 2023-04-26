#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int a[1000];
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        memset(a,0,sizeof(a));
        a[0]=1;
        scanf("%d",&m);
        for(int i=2;i<=m;i++){
            for(int j=0;j<1000;j++){
                a[j]*=i;
            }
            for(int i=0;i<1000;i++){
                a[i+1]+=a[i]/10;
                a[i]%=10;
            }
        }
        int cnt=0;
        while(a[cnt]==0){cnt++;}

        printf("case #%d:\n%d",i,cnt);

    printf("\n");}
    return 0;
}
