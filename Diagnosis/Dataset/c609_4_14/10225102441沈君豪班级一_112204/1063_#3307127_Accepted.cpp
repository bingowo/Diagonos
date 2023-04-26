#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int aa[51];

long long int f(int a)
{
    if(aa[a]){
        return aa[a];
    }
    if(a==4){
        return 8;
    }else if(a==3){
        return 4;
    }else if(a==2){
        return 2;
    }else if(a==1){
        return 1;
    }else{
        return aa[a]=(f(a-1)+f(a-2)+f(a-3)+f(a-4));
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    int m;
    memset(aa,0,sizeof(int)*51);
    for(int i=0;i<T;i++){
        scanf("%d",&m);
        long long int n=f(m);
        printf("case #%d:\n%lld\n",i,n);
    }
    return 0;
}
