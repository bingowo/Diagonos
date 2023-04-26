#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int a[74]= {0,1,1,2,4,7,13,24,44,81,149};
int Cnt(int  n){
    if(a[n]){
        return a[n];
    }
    if(n==0) return 0;
    int ret=Cnt(n-3)+ Cnt(n-2)+ Cnt(n-1);
    a[n] = ret;
    return ret;

}
int main()
{
    int t,n;
    scanf("%d",&t);
    //int a[74];
    //memset(a,0,sizeof(int)*74);
    //a[74]= {0,1,1,2,4,7,13,24,44,81,149};
    for(int i=0;i<t;i++){
        printf("case #%d:\n",i);
        scanf("%d",&n);
        printf("%d",Cnt(n));
        if(i!=t-1) printf("\n");
    }
}
