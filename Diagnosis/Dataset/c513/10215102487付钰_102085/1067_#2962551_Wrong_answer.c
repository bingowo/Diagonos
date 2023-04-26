#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int a[74]= {0,1,1,2,4,7,13,24,44,81,149};
int main()
{
    int t,n,out;
    scanf("%d",&t);
    //int a[74];
    //memset(a,0,sizeof(int)*74);
    //a[74]= {0,1,1,2,4,7,13,24,44,81,149};
    for(int i=0;i<t;i++){
        printf("case #%d:\n",i);
        scanf("%d",&n);
        if(n==0) out=0;
        else if(a[n]!=0) out =a[n];
        else out=a[n-1]+a[n-2]+a[n-3];
        printf("%d",out);
        if(i!=t-1) printf("\n");
    }
}
