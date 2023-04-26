#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k,n;
    scanf("%d%d",&k,&n);
    int table[100]={0,1};
    for(int i=2;i<=n;i++){
        int j=0;
        while(j<=k&&i-j>=0){
            table[i]+=table[i-j];
            j++;
        }
    }
    printf("%d",table[n-1]);
    return 0;
}
