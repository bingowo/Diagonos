#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{int T,a,b,n;
scanf("%d",&T);
for(int i=0;i<T;i++){
    n=0;
    scanf("%d%d",&a,&b);
    do{if((a&1)!=(b&1))n++;
        a=a>>1;b=b>>1;
    }while(a!=0||b!=0);
    printf("%d\n",n);
};
    return 0;
}
