#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()

{
    int t,n,a,b;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        n=0;
        scanf("%d%d",&a,&b);
        while(a>0||b>0){
            if((a&1)!=(b&1)) n++;
            a=a>>1;
            b=b>>1;
        }
        printf("%d\n",n);
    }
    return 0;
}
