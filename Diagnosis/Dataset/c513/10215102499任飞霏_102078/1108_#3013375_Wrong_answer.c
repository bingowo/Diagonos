#include <stdio.h>
#include <stdlib.h>

void solve(int n,int m)
{
    int table[101]={0};
    int t=n/m,j=0;
    table[n%m]=j++;
    printf("%d.",t);
    n%=m;
    while(n%m!=0){
        n*=10;
        printf("%d",n/m);
        n%=m;
        if(table[n]){
            printf("\n%d-%d\n",table[n]+1,j);
            return;
        }
        else{
            table[n]=j++;
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n,m;
        scanf("%d%d",&n,&m);
        printf("case #%d:\n",t);
        solve(n,m);
    }
    return 0;
}
