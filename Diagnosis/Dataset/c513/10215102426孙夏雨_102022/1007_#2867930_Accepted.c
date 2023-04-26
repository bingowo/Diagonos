#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        int max=1,d=1,last=1&n;
        n=n>>1;
        while(n>0){
            if((1&n)!=last) {
                d++;
                if(max<d) max=d;
            }
            else d=1;
            last=1&n;
            n=n>>1;
        }
        printf("case #%d:\n",i);
        printf("%d\n",max);
    }
    return 0;
}
