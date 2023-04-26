#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{int T,n,k=1,t=-1,l=1;
scanf("%d",&T);
for(int i=0;i<T;i++){
    k=1;t=-1,l=1;
    scanf("%d",&n);
    do{
        if(t==-1){t=n&1;}
        else if((n&1)!=t){k++;t=n&1;}
        else{t=n&1;k=1;};
        if(k>l)l=k;
        n=n>>1;
    }while(n);
    printf("case #%d:\n%d\n",i,l);
};
    return 0;
}
