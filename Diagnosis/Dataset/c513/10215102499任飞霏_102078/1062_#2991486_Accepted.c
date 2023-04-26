#include <stdio.h>
#include <stdlib.h>

long long table[51]={0};

long long int step(int n)
{
    if(n<=0)return 0;
    else if(table[n]!=0)return table[n];
    else{
        table[n]=step(n-1)+step(n-2)+step(n-3)+step(n-4);
        return table[n];
    }
}


int main()
{
    int T;
    scanf("%d",&T);
    table[1]=1;
    table[2]=2;
    table[3]=4;
    table[4]=8;
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        int n;
        scanf("%d",&n);
        printf("%lld\n",step(n));

    }
    return 0;
}
