#include <stdio.h>
#include <stdlib.h>

void solve(int n,int m)
{
    int table[101]={0};
    int t=n/m,j=1;
    n%=m;
    table[n]=j++;
    printf("%d.",t);
    
    while(n%m!=0){
        n*=10;
        printf("%d",n/m);
        n%=m;
        if(table[n]){
            printf("\n%d-%d",table[n],j-1);
            break;
        }
        else{
            table[n]=j++;
        }
    }
    printf("\n");
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
